using UnityEngine;
using System.Collections;
using GameSystems; // Para acceder a FuelManager y UnifiedDeathManager
using UnityEngine.Events; // Para exponer eventos de audio

/// <summary>
/// Componente que permite al jugador recolectar recursos
/// Sistema híbrido: VFX hijo para combustible, VFX instanciado para fragmentos
/// </summary>
public class ResourceCollector : MonoBehaviour
{
    [Tooltip("ID del jugador para identificación")]
    public int playerID = 1;

    [Tooltip("Referencia al sistema de puntuación")]
    public PlayerScoreSystem scoreSystem;

    [Tooltip("Referencia al sistema de combustible")]
    public FuelManager fuelManager;

    // --------- Integración con estado de muerte ----------
    [Header("Estado del jugador (opcional)")]
    [Tooltip("Si se asigna, puedes bloquear la recolección cuando la nave esté muerta.")]
    [SerializeField] private UnifiedDeathManager deathManager;
    [Tooltip("Si está activo, NO se recolectará ni se dispararán SFX cuando la nave esté muerta.")]
    [SerializeField] private bool bloquearSiMuerto = true;

    // --------- VFX para COMBUSTIBLE (GameObject hijo - activar/desactivar) ----------
    [Header("VFX Combustible (GameObject hijo)")]
    [Tooltip("VFX de recolección de GASOLINA (hijo de la nave, se activa/desactiva)")]
    public GameObject collectVFXFuel;

    [Tooltip("Duración del VFX de combustible antes de desactivarse (segundos)")]
    [Range(0.1f, 5f)]
    public float vfxFuelDuration = 1f;

    // --------- VFX para FRAGMENTOS (Prefab - Instantiate) ----------
    [Header("VFX Fragmentos (Prefab instantiado)")]
    [Tooltip("Prefab de VFX para PUNTOS/FRAGMENTOS (se instancia en posición del recurso)")]
    public GameObject collectEffectPoints;

    [Tooltip("VFX general de recolección (fallback, se instancia)")]
    public GameObject collectEffect;

    // --------- Detección de recursos ----------
    [Header("Detección de Recursos")]
    [Tooltip("Radio para detectar recursos")]
    public float collectionRadius = 0.8f;

    [Tooltip("Capa de recursos recolectables")]
    public LayerMask resourceLayer;

    [Tooltip("Usar verificación adicional con OverlapCircle")]
    public bool useCircleCheck = true;

    [Tooltip("Intervalo para verificación adicional")]
    public float checkInterval = 0.2f;

    // --------- SFX por tipo de recolección ----------
    [Header("SFX (UnityEvents)")]
    [Tooltip("Se invoca al recolectar cualquier recurso (aparte del específico).")]
    public UnityEvent onSfxCollectAny;
    [Tooltip("Se invoca al recolectar GASOLINA.")]
    public UnityEvent onSfxCollectFuel;
    [Tooltip("Se invoca al recolectar PUNTOS/FRAGMENTOS.")]
    public UnityEvent onSfxCollectPoints;

    // Variables privadas
    private float lastCheckTime;
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

        // Intentar auto-asignar manejador de muerte
        if (deathManager == null)
        {
            deathManager = GetComponent<UnifiedDeathManager>();
            if (deathManager == null)
                deathManager = GetComponentInParent<UnifiedDeathManager>();
            if (deathManager == null)
                deathManager = GetComponentInChildren<UnifiedDeathManager>();
        }

        // Inicializar VFX de combustible (hijo)
        InitializeFuelVFX();
    }

    /// <summary>
    /// Inicializa el VFX de combustible asegurándose de que esté desactivado
    /// </summary>
    private void InitializeFuelVFX()
    {
        if (collectVFXFuel != null)
            collectVFXFuel.SetActive(false);
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

                // Activar efecto visual correspondiente
                PlayCollectVFX(resource, collider.transform.position);

                // Disparar SFX según el tipo
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

            // Activar efecto visual correspondiente
            PlayCollectVFX(resource, other.transform.position);

            // Disparar SFX según el tipo
            PlayCollectSFX(resource);
        }
    }

    /// <summary>
    /// Sistema híbrido de VFX:
    /// - FUEL: Activa VFX hijo de la nave (optimizado, sin instantiate)
    /// - POINTS: Instancia VFX en la posición del recurso (visual claro de dónde estaba)
    /// </summary>
    private void PlayCollectVFX(CollectibleResource resource, Vector3 position)
    {
        if (resource == null || resource.resourceType == null) return;

        switch (resource.resourceType.effect)
        {
            case ResourceType.ResourceEffect.Fuel:
                // Sistema optimizado: activar VFX hijo
                ActivateFuelVFX();
                break;

            case ResourceType.ResourceEffect.Points:
                // Sistema original: instanciar en posición del fragmento
                InstantiatePointsVFX(position);
                break;

            default:
                // Fallback: instanciar efecto general
                if (collectEffect != null)
                {
                    Instantiate(collectEffect, position, Quaternion.identity);
                }
                break;
        }
    }

    /// <summary>
    /// Activa el VFX de combustible (hijo de la nave)
    /// Se desactivará automáticamente después de vfxFuelDuration segundos
    /// </summary>
    private void ActivateFuelVFX()
    {
        if (collectVFXFuel != null)
        {
            // Reiniciar el VFX (desactivar y activar para reiniciar particle systems)
            collectVFXFuel.SetActive(false);
            collectVFXFuel.SetActive(true);

            // Programar desactivación automática
            StartCoroutine(DeactivateVFXAfterDelay(collectVFXFuel, vfxFuelDuration));
        }
    }

    /// <summary>
    /// Instancia el VFX de fragmentos/puntos en la posición del recurso
    /// </summary>
    private void InstantiatePointsVFX(Vector3 position)
    {
        GameObject vfxPrefab = collectEffectPoints != null ? collectEffectPoints : collectEffect;

        if (vfxPrefab != null)
        {
            Instantiate(vfxPrefab, position, Quaternion.identity);
        }
    }

    /// <summary>
    /// Coroutine que desactiva un VFX después de un tiempo determinado
    /// </summary>
    private IEnumerator DeactivateVFXAfterDelay(GameObject vfx, float delay)
    {
        yield return new WaitForSeconds(delay);

        if (vfx != null)
        {
            vfx.SetActive(false);
        }
    }

    /// <summary>
    /// Dispara los eventos de SFX según el tipo de recurso
    /// </summary>
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

    // Visualizar radio de recolección en el editor
    private void OnDrawGizmosSelected()
    {
        Gizmos.color = new Color(0.2f, 0.8f, 0.2f, 0.3f);
        Gizmos.DrawSphere(transform.position, collectionRadius);
    }
}