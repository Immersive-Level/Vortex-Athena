using UnityEngine;
using GameSystems; // Para acceder a los nuevos sistemas

public enum ColliderType
{
    Front,
    Back
}

public class ShipCollider : MonoBehaviour
{
    [Header("Tipo de Collider")]
    public ColliderType type;

    [Header("Efecto de Colisión")]
    public GameObject collisionEffectPrefab;  // Prefab de animación de colisión

    [SerializeField] private CombatSystem combatSystem;
    private UnifiedDeathManager deathManager; // NUEVO: Referencia al death manager
    private FuelManager fuelManager; // NUEVO: Referencia al fuel manager

    private void OnEnable()
    {
        // Obtener CombatSystem del padre
        //combatSystem = transform.parent.GetComponent<CombatSystem>();
        if (combatSystem == null)
        {
            Debug.LogError("[ShipCollider] CombatSystem no encontrado en el padre");
        }

        // NUEVO: Obtener referencias a los nuevos sistemas
        // Primero intentar obtener del CombatSystem
        if (combatSystem != null)
        {
            deathManager = combatSystem.deathManager;
            fuelManager = combatSystem.fuelManager;
        }

        // Si no se encontraron, buscar en el padre
        if (deathManager == null)
        {
            deathManager = transform.parent.GetComponent<UnifiedDeathManager>();
            if (deathManager == null)
                deathManager = transform.parent.GetComponentInChildren<UnifiedDeathManager>();
        }

        if (fuelManager == null)
        {
            fuelManager = transform.parent.GetComponent<FuelManager>();
            if (fuelManager == null)
                fuelManager = transform.parent.GetComponentInChildren<FuelManager>();
        }

        // Validar que se encontraron los componentes necesarios
        if (deathManager == null)
            Debug.LogWarning("[ShipCollider] UnifiedDeathManager no encontrado");

        if (fuelManager == null)
            Debug.LogWarning("[ShipCollider] FuelManager no encontrado");
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        // Ignorar recursos
        if (collision.gameObject.CompareTag("Resource")) return;

        // Recorremos los colliders que queremos ignorar
        if (combatSystem != null && combatSystem.CollidersToIgnore != null)
        {
            foreach (Collider2D ignoreCollider in combatSystem.CollidersToIgnore)
            {
                // Si el collider actual es igual al collider de la colisión, retornamos sin hacer nada
                if (ignoreCollider == collision.collider)
                {
                    return;
                }
            }
        }

        // Verificar si es colisión con otra nave
        bool isShipCollision = collision.gameObject.CompareTag("Nave") || collision.gameObject.CompareTag("Player");

        if (isShipCollision)
        {
            // Punto de contacto de la colisión
            ContactPoint2D contact = collision.GetContact(0);

            // Instanciar el prefab de animación en el punto de impacto
            if (collisionEffectPrefab != null)
            {
                GameObject effect = Instantiate(
                    collisionEffectPrefab,
                    contact.point,
                    Quaternion.identity
                );

                // Destruir el efecto después de unos segundos
                Destroy(effect, 2f);
            }

            Debug.Log($"[ShipCollider] Colisión con {collision.gameObject.name} - Tipo: {type}");

            // Si es colisión trasera y no somos invencibles, morir
            if (type == ColliderType.Back && combatSystem != null && !combatSystem.IsInvencible)
            {
                // Dar punto al atacante
                PlayerScoreSystem otherScore = collision.gameObject.GetComponent<PlayerScoreSystem>();
                if (otherScore == null)
                {
                    // Buscar en el padre o hijos
                    otherScore = collision.gameObject.GetComponentInParent<PlayerScoreSystem>();
                    if (otherScore == null)
                        otherScore = collision.gameObject.GetComponentInChildren<PlayerScoreSystem>();
                }

                otherScore?.AddScore(inKills: 1); // Le añade una kill al oponente

                // ACTUALIZADO: Usar el nuevo sistema de muerte
                if (deathManager != null)
                {
                    deathManager.TriggerDeath(UnifiedDeathManager.DeathType.PlayerCollision);
                }
                else if (combatSystem != null)
                {
                    // Fallback al método Kill del CombatSystem
                    combatSystem.Kill();
                }

                return; // No aplicar más efectos si morimos
            }
        }

        // Aplicar efectos de colisión (slow y daño de combustible)
        ApplyCollisionEffects(collision);
    }

    /// <summary>
    /// Aplica los efectos de colisión (ralentización y pérdida de combustible)
    /// </summary>
    private void ApplyCollisionEffects(Collision2D collision)
    {
        // Aplicar ralentización
        if (combatSystem != null && combatSystem.shipController != null)
        {
            // Empujón opcional (comentado en el código original)
            // Vector2 forceDirection = (collision.transform.position - transform.position).normalized;
            // combatSystem.shipController.PushShip(forceDirection, combatSystem.PushMagnitude);

            // Ralentización
            combatSystem.shipController.SlowShip(combatSystem.SlowMagnitude);
        }

        // ACTUALIZADO: Quitar combustible usando el nuevo FuelManager
        if (fuelManager != null && combatSystem != null)
        {
            // Usar el método SetFuel para reducir combustible
            float currentFuel = fuelManager.CurrentFuel;
            float newFuel = Mathf.Max(0, currentFuel - combatSystem.CollideDamageValue);
            fuelManager.SetFuel(newFuel);

            Debug.Log($"[ShipCollider] Daño por colisión: -{combatSystem.CollideDamageValue} combustible");
        }
    }

    /// <summary>
    /// Método de utilidad para verificar si el ship está muerto
    /// </summary>
    private bool IsShipDead()
    {
        if (deathManager != null)
            return deathManager.IsDead;
        return false;
    }

    private void OnDrawGizmosSelected()
    {
        // Dibujar el tipo de collider para debug
        Gizmos.color = type == ColliderType.Back ? Color.red : Color.green;

        Collider2D col = GetComponent<Collider2D>();
        if (col != null)
        {
            Bounds bounds = col.bounds;
            Gizmos.DrawWireCube(bounds.center, bounds.size);
        }
    }
}