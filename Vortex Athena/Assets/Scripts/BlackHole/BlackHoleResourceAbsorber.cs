using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Events;

/// <summary>
/// Componente dedicado a la absorción de recursos por el agujero negro.
/// Se agrega al mismo GameObject que contiene el BlackHole.
/// </summary>
[RequireComponent(typeof(BlackHole))]
public class BlackHoleResourceAbsorber : MonoBehaviour
{
    #region Inspector Properties

    [Header("⚙️ Configuración de Absorción")]
    [Space(10)]

    [Tooltip("Radio dentro del cual los recursos son absorbidos instantáneamente")]
    [SerializeField, Range(0.5f, 5f)]
    private float instantAbsorptionRadius = 1.5f;

    [Tooltip("¿Usar el radio del núcleo del BlackHole como radio de absorción?")]
    [SerializeField]
    private bool useCoreRadiusForAbsorption = true;

    [Tooltip("Tiempo de retraso antes de absorber un recurso (para efectos)")]
    [SerializeField, Range(0f, 2f)]
    private float absorptionDelay = 0.1f;

    [Tooltip("Máximo de recursos que pueden ser absorbidos por frame")]
    [SerializeField, Range(1, 10)]
    private int maxAbsorptionsPerFrame = 3;

    [Header("🎯 Filtros")]
    [Space(10)]

    [Tooltip("Tags de objetos que pueden ser absorbidos")]
    [SerializeField]
    private string[] absorbableTags = { "Resource", "Collectible" };

    [Tooltip("Capas que pueden contener recursos absorbibles")]
    [SerializeField]
    private LayerMask absorbableLayers = -1;

    [Header("🎮 Eventos")]
    [Space(10)]

    [Tooltip("Evento cuando un recurso es absorbido")]
    public UnityEvent<GameObject> onResourceAbsorbed = new UnityEvent<GameObject>();

    [Tooltip("Evento con información del tipo de recurso absorbido")]
    public UnityEvent<CollectibleResource> onCollectibleAbsorbed = new UnityEvent<CollectibleResource>();

    [Header("📊 Estadísticas")]
    [Space(10)]

    [SerializeField, ReadOnly]
    private int totalResourcesAbsorbed = 0;

    [SerializeField, ReadOnly]
    private int resourcesInRange = 0;

    [Header("📊 Debug")]
    [Space(10)]

    [Tooltip("Mostrar información de debug")]
    [SerializeField]
    private bool debugMode = false;

    [Tooltip("Color del gizmo del radio de absorción")]
    [SerializeField]
    private Color absorptionGizmoColor = new Color(1f, 0.3f, 0.3f, 0.4f);

    #endregion

    #region Private Variables

    private BlackHole blackHole;
    private CircleCollider2D absorptionTrigger;
    private float currentAbsorptionRadius;

    // Listas para gestión de recursos
    private readonly HashSet<GameObject> resourcesBeingAbsorbed = new HashSet<GameObject>();
    private readonly Queue<GameObject> absorptionQueue = new Queue<GameObject>();
    private readonly Dictionary<GameObject, float> absorptionTimers = new Dictionary<GameObject, float>();

    // Cache para optimización
    private Collider2D[] overlapResults = new Collider2D[50];
    private float lastCheckTime = 0f;
    private const float CHECK_INTERVAL = 0.1f; // Revisar cada 100ms

    #endregion

    #region Properties

    /// <summary>
    /// Radio actual de absorción
    /// </summary>
    public float AbsorptionRadius => currentAbsorptionRadius;

    /// <summary>
    /// Total de recursos absorbidos
    /// </summary>
    public int TotalResourcesAbsorbed => totalResourcesAbsorbed;

    /// <summary>
    /// Recursos actualmente en rango
    /// </summary>
    public int ResourcesInRange => resourcesInRange;

    #endregion

    #region Unity Lifecycle

    private void Awake()
    {
        InitializeComponents();
    }

    private void Start()
    {
        SetupAbsorptionTrigger();
    }

    private void Update()
    {
        if (blackHole == null || !blackHole.IsActive)
            return;

        // Procesar cola de absorción
        ProcessAbsorptionQueue();

        // Revisar recursos periódicamente
        if (Time.time - lastCheckTime >= CHECK_INTERVAL)
        {
            CheckForResources();
            lastCheckTime = Time.time;
        }
    }

    private void OnValidate()
    {
        // Actualizar radio si está usando el del núcleo
        if (Application.isPlaying && blackHole != null)
        {
            UpdateAbsorptionRadius();
        }
    }

    #endregion

    #region Initialization

    /// <summary>
    /// Inicializa los componentes necesarios
    /// </summary>
    private void InitializeComponents()
    {
        // Obtener referencia al BlackHole
        blackHole = GetComponent<BlackHole>();
        if (blackHole == null)
        {
            Debug.LogError($"[BlackHoleResourceAbsorber] No se encontró componente BlackHole en '{name}'");
            enabled = false;
            return;
        }

        UpdateAbsorptionRadius();
    }

    /// <summary>
    /// Configura el trigger de absorción
    /// </summary>
    private void SetupAbsorptionTrigger()
    {
        // Buscar o crear collider trigger
        CircleCollider2D[] colliders = GetComponents<CircleCollider2D>();
        foreach (var col in colliders)
        {
            if (col.isTrigger && col != blackHole.GetComponent<CircleCollider2D>())
            {
                absorptionTrigger = col;
                break;
            }
        }

        if (absorptionTrigger == null)
        {
            absorptionTrigger = gameObject.AddComponent<CircleCollider2D>();
            absorptionTrigger.isTrigger = true;
        }

        absorptionTrigger.radius = currentAbsorptionRadius;
    }

    /// <summary>
    /// Actualiza el radio de absorción
    /// </summary>
    private void UpdateAbsorptionRadius()
    {
        if (blackHole == null) return;

        currentAbsorptionRadius = useCoreRadiusForAbsorption ?
            blackHole.CoreRadius : instantAbsorptionRadius;

        if (absorptionTrigger != null)
        {
            absorptionTrigger.radius = currentAbsorptionRadius;
        }
    }

    #endregion

    #region Resource Detection

    /// <summary>
    /// Revisa y procesa recursos en el área de absorción
    /// </summary>
    private void CheckForResources()
    {
        // Usar OverlapCircleNonAlloc para mejor performance
        int numFound = Physics2D.OverlapCircleNonAlloc(
            transform.position,
            currentAbsorptionRadius,
            overlapResults,
            absorbableLayers
        );

        resourcesInRange = 0;

        for (int i = 0; i < numFound && i < overlapResults.Length; i++)
        {
            Collider2D col = overlapResults[i];
            if (col == null) continue;

            GameObject obj = col.gameObject;

            // Verificar si ya está siendo procesado
            if (resourcesBeingAbsorbed.Contains(obj))
                continue;

            // Verificar tags si están configurados
            if (absorbableTags.Length > 0 && !HasValidTag(obj))
                continue;

            resourcesInRange++;

            // Intentar absorber el recurso
            TryAbsorbResource(obj);
        }
    }

    /// <summary>
    /// Verifica si un objeto tiene un tag válido para absorción
    /// </summary>
    private bool HasValidTag(GameObject obj)
    {
        foreach (string tag in absorbableTags)
        {
            if (obj.CompareTag(tag))
                return true;
        }
        return false;
    }

    #endregion

    #region Absorption Logic

    /// <summary>
    /// Intenta absorber un recurso
    /// </summary>
    private void TryAbsorbResource(GameObject resource)
    {
        if (resource == null || resourcesBeingAbsorbed.Contains(resource))
            return;

        // Marcar como en proceso de absorción
        resourcesBeingAbsorbed.Add(resource);

        // Si hay delay, agregarlo a la cola
        if (absorptionDelay > 0)
        {
            absorptionTimers[resource] = absorptionDelay;
            absorptionQueue.Enqueue(resource);
        }
        else
        {
            // Absorber inmediatamente
            AbsorbResource(resource);
        }
    }

    /// <summary>
    /// Procesa la cola de absorción con delays
    /// </summary>
    private void ProcessAbsorptionQueue()
    {
        if (absorptionQueue.Count == 0)
            return;

        int absorptionsThisFrame = 0;
        List<GameObject> toRemove = new List<GameObject>();

        // CORRECCIÓN: Crear una copia de las claves para iterar
        // Esto evita el error de modificación durante la iteración
        List<GameObject> timerKeys = new List<GameObject>(absorptionTimers.Keys);

        // Actualizar timers usando la copia de las claves
        foreach (var resource in timerKeys)
        {
            // Verificar que el recurso todavía existe en el diccionario
            if (!absorptionTimers.ContainsKey(resource))
                continue;

            absorptionTimers[resource] -= Time.deltaTime;

            if (absorptionTimers[resource] <= 0)
            {
                toRemove.Add(resource);
            }
        }

        // Procesar recursos listos
        foreach (var resource in toRemove)
        {
            if (absorptionsThisFrame >= maxAbsorptionsPerFrame)
                break;

            absorptionTimers.Remove(resource);

            if (resource != null)
            {
                AbsorbResource(resource);
                absorptionsThisFrame++;
            }
            else
            {
                // El recurso fue destruido mientras esperaba
                resourcesBeingAbsorbed.Remove(resource);
            }
        }

        // Limpiar cola
        while (absorptionQueue.Count > 0 && !absorptionQueue.Peek())
        {
            absorptionQueue.Dequeue();
        }
    }

    /// <summary>
    /// Absorbe un recurso definitivamente
    /// </summary>
    private void AbsorbResource(GameObject resource)
    {
        if (resource == null)
        {
            resourcesBeingAbsorbed.Remove(resource);
            return;
        }

        // Verificar si es un CollectibleResource
        CollectibleResource collectible = resource.GetComponent<CollectibleResource>();
        if (collectible != null)
        {
            // Notificar al recurso que fue absorbido
            collectible.AbsorbedByBlackHole();

            // Invocar evento específico
            onCollectibleAbsorbed?.Invoke(collectible);
        }

        // Invocar evento general
        onResourceAbsorbed?.Invoke(resource);

        // Actualizar estadísticas
        totalResourcesAbsorbed++;

        if (debugMode)
        {
            Debug.Log($"[BlackHoleResourceAbsorber] Recurso '{resource.name}' absorbido. " +
                     $"Total: {totalResourcesAbsorbed}");
        }

        // Limpiar de las listas
        resourcesBeingAbsorbed.Remove(resource);

        // Desactivar o destruir el objeto
        // Nota: El CollectibleResource debería manejar su propia destrucción/desactivación
        if (collectible == null)
        {
            // Si no es un CollectibleResource, desactivarlo
            resource.SetActive(false);
        }
    }

    /// <summary>
    /// Verifica si una posición está dentro del radio de absorción
    /// </summary>
    /// <param name="position">Posición a verificar</param>
    /// <returns>True si está dentro del radio de absorción</returns>
    public bool IsWithinAbsorptionRadius(Vector3 position)
    {
        return Vector3.Distance(transform.position, position) <= currentAbsorptionRadius;
    }
    #endregion

    #region Trigger Events

    private void OnTriggerEnter2D(Collider2D other)
    {
        // Verificación rápida de capas
        if (((1 << other.gameObject.layer) & absorbableLayers) == 0)
            return;

        TryAbsorbResource(other.gameObject);
    }

    private void OnTriggerStay2D(Collider2D other)
    {
        // Verificación adicional para objetos que entran mientras el agujero está inactivo
        if (blackHole.IsActive && !resourcesBeingAbsorbed.Contains(other.gameObject))
        {
            OnTriggerEnter2D(other);
        }
    }

    #endregion

    #region Utility Methods

    /// <summary>
    /// Resetea las estadísticas del absorbedor
    /// </summary>
    public void ResetStatistics()
    {
        totalResourcesAbsorbed = 0;
        resourcesInRange = 0;
        resourcesBeingAbsorbed.Clear();
        absorptionQueue.Clear();
        absorptionTimers.Clear();
    }

    /// <summary>
    /// Verifica si un objeto está siendo absorbido
    /// </summary>
    public bool IsAbsorbingResource(GameObject resource)
    {
        return resourcesBeingAbsorbed.Contains(resource);
    }

    /// <summary>
    /// Obtiene información de debug
    /// </summary>
    public string GetDebugInfo()
    {
        return $"Resource Absorber '{name}'\n" +
               $"Absorption Radius: {currentAbsorptionRadius:F2}\n" +
               $"Resources in Range: {resourcesInRange}\n" +
               $"Being Absorbed: {resourcesBeingAbsorbed.Count}\n" +
               $"In Queue: {absorptionQueue.Count}\n" +
               $"Total Absorbed: {totalResourcesAbsorbed}";
    }

    #endregion

    #region Gizmos

    private void OnDrawGizmosSelected()
    {
        // Actualizar radio si es necesario
        if (blackHole == null)
        {
            blackHole = GetComponent<BlackHole>();
        }

        if (blackHole != null && useCoreRadiusForAbsorption)
        {
            currentAbsorptionRadius = blackHole.CoreRadius;
        }
        else
        {
            currentAbsorptionRadius = instantAbsorptionRadius;
        }

        // Dibujar radio de absorción
        Gizmos.color = absorptionGizmoColor;
        Gizmos.DrawSphere(transform.position, currentAbsorptionRadius);

        // Dibujar líneas a recursos siendo absorbidos
        if (Application.isPlaying)
        {
            Gizmos.color = Color.red;
            foreach (var resource in resourcesBeingAbsorbed)
            {
                if (resource != null)
                {
                    Gizmos.DrawLine(transform.position, resource.transform.position);
                    Gizmos.DrawWireCube(resource.transform.position, Vector3.one * 0.5f);
                }
            }
        }
    }

    #endregion

    #region Custom Attributes

    /// <summary>
    /// Atributo para mostrar campos como solo lectura en el inspector
    /// </summary>
    public class ReadOnlyAttribute : PropertyAttribute { }

    #endregion
}