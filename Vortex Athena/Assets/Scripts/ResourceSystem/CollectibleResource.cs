using UnityEngine;

/// <summary>
/// Componente que representa un recurso recolectable en el juego
/// ACTUALIZADO: Compatible con el nuevo sistema BlackHoleCore
/// </summary>
public class CollectibleResource : MonoBehaviour
{
    [Tooltip("Tipo de recurso que representa este objeto")]
    public ResourceType resourceType;

    [Tooltip("¿Debe rotarse aleatoriamente para efecto visual?")]
    public bool randomRotation = true;

    [Tooltip("Velocidad de rotación")]
    public float rotationSpeed = 30f;

    // Referencias a componentes
    private SpriteRenderer spriteRenderer;
    private Collider2D resourceCollider;
    private ResourceSpawner spawner;

    // ACTUALIZADO: Referencia al nuevo sistema
    private BlackHoleCore blackHoleCore;

    // Estado del recurso - público para que el ResourceSpawner pueda verificarlo directamente
    [HideInInspector] public bool isCollected = false;

    // Variables para efectos visuales
    private Vector3 rotationAxis;
    private Vector3 originalScale;
    private float activationTime;

    private void Awake()
    {
        // Obtener referencias a componentes
        spriteRenderer = GetComponent<SpriteRenderer>();
        resourceCollider = GetComponent<Collider2D>();

        // Ejes de rotación fijos para mejorar rendimiento
        rotationAxis = Vector3.forward;

        // Guardar escala original para efectos de pulso
        originalScale = transform.localScale;
    }

    private void OnEnable()
    {
        // Registrar tiempo de activación
        activationTime = Time.time;

        // Referencia global al spawner (singleton)
        spawner = ResourceSpawner.Instance;

        // ACTUALIZADO: Buscar el nuevo BlackHoleCore
        if (blackHoleCore == null)
        {
            blackHoleCore = FindAnyObjectByType<BlackHoleCore>();
        }

        // Configurar visual
        if (spriteRenderer != null && resourceType != null)
        {
            spriteRenderer.sprite = resourceType.sprite;
            spriteRenderer.color = resourceType.resourceColor;
        }

        // Configurar rotación
        if (randomRotation)
        {
            rotationSpeed = Random.Range(20f, 50f) * (Random.value > 0.5f ? 1f : -1f);
        }

        // Asegurar estado inicial correcto
        isCollected = false;

        // Asegurar collider activo
        if (resourceCollider != null)
        {
            resourceCollider.enabled = true;
        }
    }

    private void Update()
    {
        if (isCollected) return;

        // Verificar tiempo de seguridad (30 segundos)
        if (Time.time > activationTime + 30f && gameObject.activeInHierarchy)
        {
            // Desactivar si ha estado activo demasiado tiempo
            ReturnToPool();
            return;
        }

        // Rotación constante para efecto visual
        if (randomRotation)
        {
            transform.Rotate(rotationAxis, rotationSpeed * Time.deltaTime);
        }

        // ACTUALIZADO: Verificación simplificada usando BlackHoleCore
        // El CollectibleResourceAdapter se encarga de la lógica de gravedad
        // Solo verificamos si estamos muy cerca del centro por seguridad
        if (blackHoleCore != null && blackHoleCore.IsActive)
        {
            float distance = Vector2.Distance(transform.position, blackHoleCore.Position);
            if (distance <= blackHoleCore.EventHorizonRadius * 0.5f) // Muy cerca del centro
            {
                AbsorbedByBlackHole();
            }
        }
    }

    /// <summary>
    /// Se llama cuando este objeto es absorbido por el agujero negro
    /// ACTUALIZADO: Simplificado para trabajar con el nuevo sistema
    /// </summary>
    public void AbsorbedByBlackHole()
    {
        // Evitar múltiples recolecciones
        if (isCollected) return;
        isCollected = true;

        // Desactivar collider
        if (resourceCollider != null)
        {
            resourceCollider.enabled = false;
        }

        // Distribuir puntos a jugadores si es de tipo Points
        if (resourceType != null && resourceType.effect == ResourceType.ResourceEffect.Points)
        {
            PlayerScoreSystem[] playerScoreSystems = FindObjectsByType<PlayerScoreSystem>(FindObjectsSortMode.None);
            if (playerScoreSystems.Length > 0)
            {
                int pointsPerPlayer = Mathf.RoundToInt(resourceType.effectAmount / playerScoreSystems.Length);
                foreach (var scoreSystem in playerScoreSystems)
                {
                    scoreSystem.AddScore(pointsPerPlayer);
                }
            }
        }

        // Reproducir efectos
        PlayEffects();

        // Devolver al pool después de un breve retraso para efectos
        Invoke("ReturnToPool", 0.1f);
    }

    /// <summary>
    /// Se llama cuando este objeto es recolectado por el jugador
    /// </summary>
    public void CollectedByPlayer()
    {
        if (isCollected) return;
        isCollected = true;

        // Desactivar collider
        if (resourceCollider != null)
        {
            resourceCollider.enabled = false;
        }

        // Reproducir efectos
        PlayEffects();

        // Devolver al pool después de un breve retraso para efectos
        Invoke("ReturnToPool", 0.1f);
    }

    /// <summary>
    /// NUEVO: Método para ser llamado por el CollectibleResourceAdapter
    /// cuando el recurso es consumido por el agujero negro a través del nuevo sistema
    /// </summary>
    public void OnConsumedByGravitySystem()
    {
        AbsorbedByBlackHole();
    }

    /// <summary>
    /// Reproduce efectos visuales y sonoros
    /// </summary>
    private void PlayEffects()
    {
        if (resourceType == null) return;

        // Sonido
        if (resourceType.collectSound != null)
        {
            AudioSource.PlayClipAtPoint(resourceType.collectSound, transform.position);
        }

        // Efecto visual
        if (resourceType.collectEffect != null)
        {
            Instantiate(resourceType.collectEffect, transform.position, Quaternion.identity);
        }
    }

    /// <summary>
    /// Devuelve este objeto al pool de recursos
    /// </summary>
    private void ReturnToPool()
    {
        // Cancelar cualquier invocación pendiente
        CancelInvoke();

        // Usar el singleton para devolver al pool
        if (spawner != null)
        {
            spawner.ReturnToPool(gameObject);
        }
        else if (ResourceSpawner.Instance != null)
        {
            ResourceSpawner.Instance.ReturnToPool(gameObject);
        }
        else
        {
            // Si no hay spawner, simplemente destruir
            Destroy(gameObject);
        }
    }

    /// <summary>
    /// NUEVO: Método público para verificar distancia al agujero negro
    /// Útil para sistemas externos que necesiten esta información
    /// </summary>
    public float GetDistanceToBlackHole()
    {
        if (blackHoleCore == null) return float.MaxValue;
        return Vector2.Distance(transform.position, blackHoleCore.Position);
    }

    /// <summary>
    /// NUEVO: Método público para verificar si está en zona de peligro
    /// </summary>
    public bool IsInDangerZone()
    {
        if (blackHoleCore == null) return false;
        return GetDistanceToBlackHole() <= blackHoleCore.EventHorizonRadius * 1.5f;
    }
}