using UnityEngine;

/// <summary>
/// Componente que representa un recurso recolectable en el juego
/// </summary>
public class CollectibleResource : MonoBehaviour
{
    [Tooltip("Tipo de recurso que representa este objeto")]
    public ResourceType resourceType;

    [Tooltip("¿Debe rotarse aleatoriamente para efecto visual?")]
    public bool randomRotation = true;

    [Tooltip("Velocidad de rotación")]
    public float rotationSpeed = 30f;

    [Tooltip("Efecto visual cuando está cerca del agujero negro")]
    public bool pulseWhenClose = true;

    [Tooltip("Velocidad del pulso")]
    public float pulseSpeed = 2f;

    // Referencias a componentes
    private SpriteRenderer spriteRenderer;
    private Collider2D resourceCollider;
    private AffectedByBlackHole affectedByBlackHole;
    private ResourceSpawner spawner;
    private Transform blackHoleTransform;

    // Estado del recurso - público para que el ResourceSpawner pueda verificarlo directamente
    [HideInInspector] public bool isCollected = false;

    // Variables para efectos visuales
    private Vector3 rotationAxis;
    private float pulseTimer;
    private Vector3 originalScale;
    private float activationTime;

    private void Awake()
    {
        // Obtener referencias a componentes
        spriteRenderer = GetComponent<SpriteRenderer>();
        resourceCollider = GetComponent<Collider2D>();
        affectedByBlackHole = GetComponent<AffectedByBlackHole>();

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

        // Solo buscar el agujero negro una vez al activarse
        if (blackHoleTransform == null)
        {
            BlackHole blackHole = FindAnyObjectByType<BlackHole>();
            if (blackHole != null)
            {
                blackHoleTransform = blackHole.transform;
            }
        }

        // Suscribirse a eventos
        if (affectedByBlackHole != null)
        {
            affectedByBlackHole.onEnterEventHorizon += OnEnterEventHorizon;
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

    private void OnDisable()
    {
        // Desuscribirse de eventos al desactivar
        if (affectedByBlackHole != null)
        {
            affectedByBlackHole.onEnterEventHorizon -= OnEnterEventHorizon;
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

        //// Efecto de pulso cuando está cerca del agujero negro
        //if (pulseWhenClose && affectedByBlackHole != null && affectedByBlackHole.isWithinEventHorizon)
        //{
        //    pulseTimer += Time.deltaTime * pulseSpeed;
        //    float pulseFactor = 1f + Mathf.Sin(pulseTimer) * 0.2f;
        //    transform.localScale = originalScale * pulseFactor;
        //}
        //else if (transform.localScale != originalScale)
        //{
        //    // Restaurar escala original gradualmente
        //    transform.localScale = Vector3.Lerp(transform.localScale, originalScale, Time.deltaTime * 5f);
        //}

        // Verificar si está dentro del radio de absorción del agujero negro
        if (blackHoleTransform != null)
        {
            BlackHoleResourceAbsorber absorber = blackHoleTransform.GetComponent<BlackHoleResourceAbsorber>();
            if (absorber != null && absorber.IsWithinAbsorptionRadius(transform.position))
            {
                AbsorbedByBlackHole();
            }
        }
    }

    /// <summary>
    /// Se llama cuando el recurso entra en el horizonte de eventos del agujero negro
    /// </summary>
    private void OnEnterEventHorizon()
    {
        if (isCollected) return;

        // Aumentar brillo del color
        if (spriteRenderer != null && resourceType != null)
        {
            spriteRenderer.color = new Color(
                resourceType.resourceColor.r * 1.5f,
                resourceType.resourceColor.g * 1.5f,
                resourceType.resourceColor.b * 1.5f,
                resourceType.resourceColor.a
            );
        }
    }

    /// <summary>
    /// Se llama cuando este objeto es absorbido por el agujero negro
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
}