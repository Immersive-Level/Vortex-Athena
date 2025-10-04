using UnityEngine;
using GameSystems; // Para acceder a FuelManager y UnifiedDeathManager
using UnityEngine.Events; // <-- NUEVO: para exponer eventos de audio

/// <summary>
/// Componente que permite al jugador recolectar recursos
/// Actualizado para trabajar con el nuevo FuelManager
/// </summary>
public class ResourceCollector : MonoBehaviour
{
    [Tooltip("ID del jugador para identificación")]
    public int playerID = 1;

    [Tooltip("Referencia al sistema de puntuación")]
    public PlayerScoreSystem scoreSystem;

    [Tooltip("Referencia al sistema de combustible")]
    public FuelManager fuelManager; // CAMBIADO: Fuel_System -> FuelManager

    // --------- NUEVO: Integración con estado de muerte ----------
    [Header("Estado del jugador (opcional)")]
    [Tooltip("Si se asigna, puedes bloquear la recolección cuando la nave esté muerta.")]
    [SerializeField] private UnifiedDeathManager deathManager;
    [Tooltip("Si está activo, NO se recolectará ni se dispararán SFX cuando la nave esté muerta.")]
    [SerializeField] private bool bloquearSiMuerto = true;

    [Header("Efectos visuales")]
    [Tooltip("Efecto general de recolección (fallback si no hay específico)")]
    public GameObject collectEffect;

    [Tooltip("Efecto de recolección para GASOLINA")]
    public GameObject collectEffectFuel;

    [Tooltip("Efecto de recolección para PUNTOS/FRAGMENTOS")]
    public GameObject collectEffectPoints;

    [Tooltip("Radio para detectar recursos")]
    public float collectionRadius = 0.8f;

    [Tooltip("Capa de recursos recolectables")]
    public LayerMask resourceLayer;

    [Tooltip("Usar verificación adicional con OverlapCircle")]
    public bool useCircleCheck = true;

    [Tooltip("Intervalo para verificación adicional")]
    public float checkInterval = 0.2f;

    // --------- NUEVO: SFX por tipo de recolección ----------
    [Header("SFX (UnityEvents)")]
    [Tooltip("Se invoca al recolectar cualquier recurso (aparte del específico).")]
    public UnityEvent onSfxCollectAny;
    [Tooltip("Se invoca al recolectar GASOLINA.")]
    public UnityEvent onSfxCollectFuel;
    [Tooltip("Se invoca al recolectar PUNTOS/FRAGMENTOS.")]
    public UnityEvent onSfxCollectPoints;

    // Control de tiempo para verificación adicional
    private float lastCheckTime;

    // Buffer para resultados de OverlapCircle para evitar creación de arrays
    private Collider2D[] colliderBuffer = new Collider2D[10];

    private void Start()
    {
        // Auto-referencias si no están asignadas
        if (scoreSystem == null)
        {
            scoreSystem = GetComponent<PlayerScoreSystem>();
        }

        if (fuelManager == null)
        {
            fuelManager = GetComponent<FuelManager>();
            if (fuelManager == null)
                fuelManager = GetComponentInParent<FuelManager>();
        }

        // NUEVO: intentar auto-asignar manejador de muerte
        if (deathManager == null)
        {
            deathManager = GetComponent<UnifiedDeathManager>();
            if (deathManager == null)
                deathManager = GetComponentInParent<UnifiedDeathManager>();
            if (deathManager == null)
                deathManager = GetComponentInChildren<UnifiedDeathManager>();
        }
    }

    private void Update()
    {
        // Si está muerto y bloqueamos recolección, salir
        if (bloquearSiMuerto && deathManager != null && deathManager.IsDead)
            return;

        // Verificación adicional con OverlapCircle si está habilitada
        if (useCircleCheck && Time.time > lastCheckTime + checkInterval)
        {
            CheckNearbyResources();
            lastCheckTime = Time.time;
        }
    }

    /// <summary>
    /// Verifica recursos cercanos usando OverlapCircle
    /// </summary>
    private void CheckNearbyResources()
    {
        int count = Physics2D.OverlapCircleNonAlloc(transform.position, collectionRadius, colliderBuffer, resourceLayer);

        for (int i = 0; i < count; i++)
        {
            Collider2D collider = colliderBuffer[i];
            if (collider == null) continue;

            CollectibleResource resource = collider.GetComponent<CollectibleResource>();
            if (resource != null && !resource.isCollected)
            {
                // Si está muerto y bloqueamos recolección, saltar
                if (bloquearSiMuerto && deathManager != null && deathManager.IsDead)
                    continue;

                // Procesar lógica (puntaje/combustible)
                ProcessResource(resource);

                // Efecto visual (según tipo)
                PlayCollectFX(resource, collider.transform.position);

                // NUEVO: SFX (según tipo y genérico)
                PlayCollectSFX(resource);
            }
        }
    }

    /// <summary>
    /// Procesa la recolección según el tipo de recurso
    /// </summary>
    private void ProcessResource(CollectibleResource resource)
    {
        if (resource == null || resource.resourceType == null) return;

        switch (resource.resourceType.effect)
        {
            case ResourceType.ResourceEffect.Fuel:
                if (fuelManager != null)
                {
                    fuelManager.AddFuel(resource.resourceType.effectAmount);
                }
                break;

            case ResourceType.ResourceEffect.Points:
                if (scoreSystem != null)
                {
                    scoreSystem.AddScore(inScore: Mathf.RoundToInt(resource.resourceType.effectAmount));
                }
                break;
        }

        // Marcar como recolectado
        resource.CollectedByPlayer();
    }

    /// <summary>
    /// Detección por colisión
    /// </summary>
    private void OnTriggerEnter2D(Collider2D other)
    {
        // Si está muerto y bloqueamos recolección, salir
        if (bloquearSiMuerto && deathManager != null && deathManager.IsDead)
            return;

        CollectibleResource resource = other.GetComponent<CollectibleResource>();
        if (resource != null && !resource.isCollected)
        {
            ProcessResource(resource);

            // Efecto visual (según tipo)
            PlayCollectFX(resource, other.transform.position);

            // NUEVO: SFX (según tipo y genérico)
            PlayCollectSFX(resource);
        }
    }

    /// <summary>
    /// Instancia el efecto visual adecuado según el tipo de recurso.
    /// Si no hay efecto específico asignado, usa el general (collectEffect).
    /// </summary>
    private void PlayCollectFX(CollectibleResource resource, Vector3 position)
    {
        if (resource == null || resource.resourceType == null) return;

        GameObject fxToSpawn = null;

        switch (resource.resourceType.effect)
        {
            case ResourceType.ResourceEffect.Fuel:
                fxToSpawn = collectEffectFuel != null ? collectEffectFuel : collectEffect;
                break;

            case ResourceType.ResourceEffect.Points:
                fxToSpawn = collectEffectPoints != null ? collectEffectPoints : collectEffect;
                break;

            default:
                fxToSpawn = collectEffect;
                break;
        }

        if (fxToSpawn != null)
        {
            Instantiate(fxToSpawn, position, Quaternion.identity);
        }
    }

    // --------- NUEVO: disparo de SFX según el tipo ----------
    private void PlayCollectSFX(CollectibleResource resource)
    {
        if (resource == null || resource.resourceType == null) return;

        // Primero el específico por tipo
        switch (resource.resourceType.effect)
        {
            case ResourceType.ResourceEffect.Fuel:
                onSfxCollectFuel?.Invoke();
                break;

            case ResourceType.ResourceEffect.Points:
                onSfxCollectPoints?.Invoke();
                break;
        }

        // Luego el genérico "cualquier recolección"
        onSfxCollectAny?.Invoke();
    }

    // Visualizar radio de recolección
    private void OnDrawGizmosSelected()
    {
        Gizmos.color = new Color(0.2f, 0.8f, 0.2f, 0.3f);
        Gizmos.DrawSphere(transform.position, collectionRadius);
    }
}

