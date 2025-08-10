using UnityEngine;
using GameSystems; // Para acceder a UnifiedDeathManager y FuelManager

public class CombatSystem : MonoBehaviour
{
    [HideInInspector] public ShipController shipController { get; private set; }
    [HideInInspector] public UnifiedDeathManager deathManager { get; private set; } // CAMBIADO
    [HideInInspector] public FuelManager fuelManager { get; private set; } // CAMBIADO

    [Tooltip("valor de la fuerza del empujo contra el mapa o otras naves")]
    public float PushMagnitude;

    [Range(0, 100)]
    [Tooltip("valor del slow contra otras naves")]
    public float SlowMagnitude = 35;

    [Tooltip("Daño recibido al chocar")]
    public float CollideDamageValue;

    public bool IsInvencible { get; set; }
    public Collider2D[] CollidersToIgnore;

    public ShieldController Shield;

    private void OnEnable()
    {
        shipController = GetComponent<ShipController>();

        // Buscar el nuevo UnifiedDeathManager
        deathManager = GetComponent<UnifiedDeathManager>();
        if (deathManager == null)
            deathManager = GetComponentInParent<UnifiedDeathManager>();

        // Buscar el nuevo FuelManager
        fuelManager = GetComponent<FuelManager>();
        if (fuelManager == null)
            fuelManager = GetComponentInParent<FuelManager>();
    }

    public void Kill()
    {
        if (IsInvencible) return;

        // Usar el nuevo sistema de muerte unificado
        deathManager?.TriggerDeath(UnifiedDeathManager.DeathType.PlayerCollision);
    }

    /// <summary>
    /// Maneja colisiones con otros jugadores (muerte por detrás)
    /// </summary>
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (IsInvencible) return;

        // Verificar si es otro jugador
        if (collision.gameObject.CompareTag("Player"))
        {
            // Calcular el ángulo del impacto
            Vector2 impactDirection = collision.contacts[0].normal;
            float angle = Vector2.Angle(-transform.up, impactDirection);

            // Si el impacto es por detrás (menos de 45 grados)
            if (angle < 45f)
            {
                Kill();
            }
            else
            {
                // Aplicar empuje si no muere
                var otherShip = collision.gameObject.GetComponent<ShipController>();
                if (otherShip != null && shipController != null)
                {
                    // Empujar a la otra nave
                    Vector2 pushDirection = (collision.transform.position - transform.position).normalized;
                    otherShip.PushShip(pushDirection, PushMagnitude);

                    // Ralentizar a la otra nave
                    otherShip.SlowShip(SlowMagnitude, 1f);
                }
            }
        }
    }
}