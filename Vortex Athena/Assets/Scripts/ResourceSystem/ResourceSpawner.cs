using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Sistema de generación de recursos alrededor del agujero negro
/// Maneja el object pooling y la generación de recursos
/// MODIFICADO: Compatible con el nuevo sistema BlackHoleCore
/// </summary>
public class ResourceSpawner : MonoBehaviour
{
    [System.Serializable]
    public class ResourceInfo
    {
        public ResourceType resourceType;
        public GameObject prefab;
        [Range(0f, 1f)]
        public float spawnProbability = 0.5f;
        public int initialPoolSize = 10;
    }

    [Header("Configuración de Recursos")]
    [Tooltip("Lista de tipos de recursos y sus prefabs")]
    public List<ResourceInfo> resourceInfoList = new List<ResourceInfo>();

    [Header("Configuración de Spawning")]
    [Tooltip("Referencia al agujero negro - NUEVO SISTEMA")]
    public BlackHoleCore blackHoleCore; // MODIFICADO: Cambiado de BlackHole a BlackHoleCore

    [Tooltip("Radio mínimo de generación (desde el agujero negro)")]
    public float minSpawnRadius = 3f;

    [Tooltip("Radio máximo de generación (desde el agujero negro)")]
    public float maxSpawnRadius = 5f;

    [Tooltip("Tiempo entre generación de recursos (segundos)")]
    public float spawnInterval = 2f;

    [Tooltip("Cantidad máxima de recursos activos")]
    public int maxActiveResources = 50;

    [Tooltip("Capa para verificar obstáculos")]
    public LayerMask obstacleLayer;

    [Header("Object Pooling")]
    [Tooltip("Contenedor para los objetos inactivos del pool")]
    public Transform poolContainer;

    [Header("Seguridad")]
    [Tooltip("Intervalo para verificar recursos problemáticos (segundos)")]
    public float cleanupInterval = 15f;

    [Header("NUEVO: Configuración del Sistema de Gravedad")]
    [Tooltip("Prefab del adaptador que conecta recursos con el sistema de gravedad")]
    public GameObject gravityAdapterPrefab;

    [Tooltip("Añadir automáticamente adaptador de gravedad a recursos sin él")]
    public bool autoAddGravityAdapter = true;

    // Diccionarios para almacenar los pools y recursos activos 
    private Dictionary<ResourceType, Queue<GameObject>> resourcePools = new Dictionary<ResourceType, Queue<GameObject>>();
    private HashSet<GameObject> activeResources = new HashSet<GameObject>();

    // Singleton
    private static ResourceSpawner _instance;
    public static ResourceSpawner Instance { get { return _instance; } }

    // Variables para ponderación de recursos
    private List<ResourceInfo> weightedResourceList;
    private int totalWeight;

    // MODIFICADO: Referencia al sistema de atracción actualizada
    // private BlackHoleAttractionManager attractionManager; // REMOVIDO - ya no se usa

    // Para la generación de recursos
    private float spawnTimer;
    private Vector3 tempSpawnPosition;

    private void Awake()
    {
        // Configurar singleton
        if (_instance != null && _instance != this)
        {
            Destroy(gameObject);
            return;
        }
        _instance = this;

        // Crear el contenedor si no existe
        if (poolContainer == null)
        {
            GameObject container = new GameObject("ResourcePoolContainer");
            poolContainer = container.transform;
            poolContainer.SetParent(transform);
        }

        // Precalcular lista ponderada de recursos
        PrecalculateWeightedResources();
    }

    private void Start()
    {
        // MODIFICADO: Buscar el nuevo BlackHoleCore
        if (blackHoleCore == null)
        {
            blackHoleCore = FindAnyObjectByType<BlackHoleCore>();
            if (blackHoleCore == null)
            {
                Debug.LogWarning("ResourceSpawner: No se encontró un BlackHoleCore en la escena.");
                enabled = false;
                return;
            }
        }

        // MODIFICADO: Ya no necesitamos BlackHoleAttractionManager
        // attractionManager = BlackHoleAttractionManager.Instance;

        // Inicializar los pools
        InitializePools();

        // Inicializar timer
        spawnTimer = spawnInterval;

        // Iniciar limpieza periódica
        InvokeRepeating("CheckAndCleanupResources", cleanupInterval, cleanupInterval);

        // NUEVO: Suscribirse a eventos del agujero negro
        BlackHoleEvents.ObjectConsumed += OnResourceConsumedByBlackHole;
    }

    private void OnDestroy()
    {
        // NUEVO: Desuscribirse de eventos
        BlackHoleEvents.ObjectConsumed -= OnResourceConsumedByBlackHole;

        // Limpiar timer al destruir
        CancelInvoke();
    }

    // NUEVO: Método para manejar cuando un recurso es consumido por el agujero negro
    private void OnResourceConsumedByBlackHole(IGravityAffected gravityAffected)
    {
        // Verificar si el objeto consumido es un recurso nuestro
        if (gravityAffected?.Transform != null)
        {
            GameObject obj = gravityAffected.Transform.gameObject;
            CollectibleResource resource = obj.GetComponent<CollectibleResource>();

            if (resource != null && activeResources.Contains(obj))
            {
                // Marcar como recolectado y devolver al pool
                resource.isCollected = true;
                ReturnToPool(obj);
            }
        }
    }

    private void Update()
    {
        // Generar recursos si es tiempo y hay espacio
        spawnTimer -= Time.deltaTime;
        if (spawnTimer <= 0 && activeResources.Count < maxActiveResources)
        {
            SpawnResource();
            spawnTimer = spawnInterval;
        }
    }

    /// <summary>
    /// Precalcula lista ponderada de recursos para eficiencia en GetRandomResource
    /// </summary>
    private void PrecalculateWeightedResources()
    {
        weightedResourceList = new List<ResourceInfo>();
        totalWeight = 0;

        foreach (var info in resourceInfoList)
        {
            if (info.resourceType == null || info.prefab == null) continue;

            int weight = Mathf.RoundToInt(info.spawnProbability * 100);
            totalWeight += weight;

            // Agregar referencia al info actual al weightedResourceList
            for (int i = 0; i < weight; i++)
            {
                weightedResourceList.Add(info);
            }
        }
    }

    /// <summary>
    /// Inicializa todos los pools de recursos
    /// </summary>
    private void InitializePools()
    {
        foreach (var resourceInfo in resourceInfoList)
        {
            if (resourceInfo.resourceType == null || resourceInfo.prefab == null)
                continue;

            // Crear una cola para este tipo de recurso
            Queue<GameObject> pool = new Queue<GameObject>(resourceInfo.initialPoolSize);

            // Crear los objetos iniciales
            for (int i = 0; i < resourceInfo.initialPoolSize; i++)
            {
                GameObject obj = CreateResourceObject(resourceInfo);
                obj.SetActive(false);
                pool.Enqueue(obj);
            }

            // Guardar el pool
            resourcePools[resourceInfo.resourceType] = pool;
        }
    }

    /// <summary>
    /// Crea un objeto recurso con los componentes necesarios
    /// MODIFICADO: Ahora incluye el adaptador de gravedad
    /// </summary>
    private GameObject CreateResourceObject(ResourceInfo info)
    {
        GameObject obj = Instantiate(info.prefab, poolContainer);

        // Configurar componentes solo si no existen
        ConfigureCollectibleResource(obj, info.resourceType);
        ConfigureRigidbody(obj);
        ConfigureCollider(obj);

        // NUEVO: Configurar adaptador de gravedad
        ConfigureGravityAdapter(obj);

        return obj;
    }

    /// <summary>
    /// NUEVO: Configura el adaptador de gravedad para conectar con BlackHoleCore
    /// </summary>
    private void ConfigureGravityAdapter(GameObject obj)
    {
        // Verificar si ya tiene un componente de gravedad
        if (obj.GetComponent<IGravityAffected>() != null)
            return;

        if (autoAddGravityAdapter)
        {
            // Añadir el adaptador específico para recursos
            CollectibleResourceAdapter adapter = obj.GetComponent<CollectibleResourceAdapter>();
            if (adapter == null)
            {
                adapter = obj.AddComponent<CollectibleResourceAdapter>();
            }
        }
    }

    /// <summary>
    /// Configura el componente CollectibleResource
    /// </summary>
    private void ConfigureCollectibleResource(GameObject obj, ResourceType resourceType)
    {
        CollectibleResource resource = obj.GetComponent<CollectibleResource>();
        if (resource == null)
        {
            resource = obj.AddComponent<CollectibleResource>();
        }
        resource.resourceType = resourceType;

        // Garantizar que cada prefab posea el script ResourceLifetime
        if (obj.GetComponent<ResourceLifetime>() == null)
            obj.AddComponent<ResourceLifetime>();
    }

    /// <summary>
    /// Configura el Rigidbody2D si no existe
    /// </summary>
    private void ConfigureRigidbody(GameObject obj)
    {
        Rigidbody2D rb = obj.GetComponent<Rigidbody2D>();
        if (rb == null)
        {
            rb = obj.AddComponent<Rigidbody2D>();
            rb.gravityScale = 0; // IMPORTANTE: Desactivar gravedad de Unity, usamos la del agujero negro
            rb.linearDamping = 0.5f;
        }
    }

    /// <summary>
    /// Configura el Collider2D si no existe
    /// </summary>
    private void ConfigureCollider(GameObject obj)
    {
        Collider2D collider = obj.GetComponent<Collider2D>();
        if (collider == null)
        {
            CircleCollider2D circleCollider = obj.AddComponent<CircleCollider2D>();
            circleCollider.isTrigger = true;
            circleCollider.radius = 0.5f;
        }
        else
        {
            collider.isTrigger = true;
        }
    }

    /// <summary>
    /// Obtiene un recurso aleatorio basado en las probabilidades precalculadas
    /// </summary>
    public GameObject GetRandomResource()
    {
        if (weightedResourceList.Count == 0) return null;

        // Seleccionar recursos directo de la lista precalculada
        int randomIndex = Random.Range(0, weightedResourceList.Count);
        ResourceInfo selectedInfo = weightedResourceList[randomIndex];

        return GetResourceFromPool(selectedInfo.resourceType);
    }

    /// <summary>
    /// Obtiene un recurso del pool o crea uno nuevo
    /// MODIFICADO: Actualizado para el nuevo sistema de gravedad
    /// </summary>
    private GameObject GetResourceFromPool(ResourceType resourceType)
    {
        if (resourceType == null || !resourcePools.ContainsKey(resourceType))
            return null;

        Queue<GameObject> pool = resourcePools[resourceType];
        GameObject obj = null;

        // Obtener del pool o crear nuevo
        if (pool.Count == 0)
        {
            ResourceInfo info = resourceInfoList.Find(r => r.resourceType == resourceType);
            if (info != null)
            {
                obj = CreateResourceObject(info);
            }
        }
        else
        {
            obj = pool.Dequeue();

            // Si el objeto es nulo (raro pero posible), crear uno nuevo
            if (obj == null)
            {
                ResourceInfo info = resourceInfoList.Find(r => r.resourceType == resourceType);
                if (info != null)
                {
                    obj = CreateResourceObject(info);
                }
                else
                {
                    return null;
                }
            }
        }

        // Activar y registrar
        if (obj != null)
        {
            // Activar el objeto (esto disparará OnEnable en CollectibleResource)
            obj.SetActive(true);

            // MODIFICADO: El registro con el sistema de gravedad es automático
            // cuando el objeto entra en el trigger del BlackHoleCore
            // Ya no necesitamos registrar manualmente con BlackHoleAttractionManager

            // Agregar a activos
            activeResources.Add(obj);
        }

        return obj;
    }

    /// <summary>
    /// Devuelve un recurso al pool
    /// MODIFICADO: Actualizado para el nuevo sistema
    /// </summary>
    public void ReturnToPool(GameObject obj)
    {
        if (obj == null) return;

        // Evitar procesamiento redundante
        if (!obj.activeInHierarchy) return;

        // Remover de recursos activos
        activeResources.Remove(obj);

        // MODIFICADO: Ya no necesitamos desregistrar manualmente del sistema de atracción
        // El BlackHoleCore maneja esto automáticamente cuando el objeto se desactiva

        // Obtener tipo de recurso
        CollectibleResource resource = obj.GetComponent<CollectibleResource>();
        if (resource == null || resource.resourceType == null)
        {
            Destroy(obj);
            return;
        }

        ResourceType resourceType = resource.resourceType;

        // Resetear estado del recurso
        resource.isCollected = false;

        // Desactivar y mover al contenedor
        obj.SetActive(false);
        obj.transform.SetParent(poolContainer);

        // Resetear física
        Rigidbody2D rb = obj.GetComponent<Rigidbody2D>();
        if (rb != null)
        {
            rb.linearVelocity = Vector2.zero;
            rb.angularVelocity = 0f;
        }

        // Añadir al pool correspondiente
        if (!resourcePools.ContainsKey(resourceType))
        {
            resourcePools[resourceType] = new Queue<GameObject>();
        }

        resourcePools[resourceType].Enqueue(obj);
    }

    /// <summary>
    /// Genera un recurso en posición aleatoria
    /// MODIFICADO: Usa BlackHoleCore en lugar de BlackHole
    /// </summary>
    private void SpawnResource()
    {
        if (blackHoleCore == null) return;

        // Generar posición aleatoria
        Vector2 randomDirection = Random.insideUnitCircle.normalized;
        float randomDistance = Random.Range(minSpawnRadius, maxSpawnRadius);
        tempSpawnPosition = blackHoleCore.transform.position + new Vector3(randomDirection.x, randomDirection.y, 0) * randomDistance;

        // Verificar obstáculos
        if (Physics2D.OverlapCircle(tempSpawnPosition, 1f, obstacleLayer)) return;

        // NUEVO: Verificar que no esté muy cerca del horizonte de eventos
        float distanceToCenter = Vector2.Distance(tempSpawnPosition, blackHoleCore.Position);
        if (distanceToCenter <= blackHoleCore.EventHorizonRadius * 1.5f) return;

        // Obtener recurso y configurarlo
        GameObject resource = GetRandomResource();
        if (resource != null)
        {
            // Configurar posición y rotación
            resource.transform.position = tempSpawnPosition;
            resource.transform.rotation = Quaternion.Euler(0, 0, Random.Range(0, 360));

            // Dar velocidad inicial
            Rigidbody2D rb = resource.GetComponent<Rigidbody2D>();
            if (rb != null)
            {
                rb.linearVelocity = Random.insideUnitCircle.normalized * Random.Range(1f, 2f);
            }
        }
    }

    /// <summary>
    /// Verifica y limpia recursos problemáticos
    /// </summary>
    private void CheckAndCleanupResources()
    {
        // Usar una lista temporal para evitar modificar la colección durante iteración
        List<GameObject> problematicResources = new List<GameObject>();

        foreach (GameObject resource in activeResources)
        {
            if (resource == null) continue;

            // Verificar si debe limpiarse (colliders desactivados o marcado como recolectado)
            bool shouldCleanup = false;

            // Verificar CollectibleResource
            CollectibleResource collectible = resource.GetComponent<CollectibleResource>();
            if (collectible != null && collectible.isCollected)
            {
                shouldCleanup = true;
            }
            else
            {
                // Verificar si todos los colliders están desactivados
                Collider2D[] colliders = resource.GetComponents<Collider2D>();
                if (colliders.Length > 0)
                {
                    bool allDisabled = true;
                    foreach (var collider in colliders)
                    {
                        if (collider != null && collider.enabled)
                        {
                            allDisabled = false;
                            break;
                        }
                    }

                    if (allDisabled)
                    {
                        shouldCleanup = true;
                    }
                }
            }

            // Agregar a la lista de problemáticos si es necesario
            if (shouldCleanup)
            {
                problematicResources.Add(resource);
            }
        }

        // Limpiar los recursos problemáticos
        int cleanedCount = 0;
        foreach (GameObject resource in problematicResources)
        {
            try
            {
                ReturnToPool(resource);
                cleanedCount++;
            }
            catch (System.Exception)
            {
                // En caso de error, desactivar a la fuerza
                if (resource != null)
                {
                    resource.SetActive(false);
                    activeResources.Remove(resource);
                }
            }
        }

        if (cleanedCount > 0)
        {
            Debug.Log($"ResourceSpawner: Se limpiaron {cleanedCount} recursos problemáticos.");
        }
    }

    // NUEVO: Métodos públicos para configuración dinámica del agujero negro
    public void SetBlackHoleReference(BlackHoleCore newBlackHole)
    {
        blackHoleCore = newBlackHole;
    }

    public void AdjustSpawnRadiusBasedOnBlackHole()
    {
        if (blackHoleCore == null) return;

        // Ajustar radios basándose en la intensidad del agujero negro
        float intensity = blackHoleCore.CurrentIntensity;
        float baseMin = 3f;
        float baseMax = 5f;

        minSpawnRadius = baseMin + (intensity - 1f) * 2f;
        maxSpawnRadius = baseMax + (intensity - 1f) * 3f;

        // Asegurar que el mínimo no sea menor que el horizonte de eventos
        minSpawnRadius = Mathf.Max(minSpawnRadius, blackHoleCore.EventHorizonRadius * 2f);
    }

    // Visualizar radios de spawn en el editor
    // MODIFICADO: Usa BlackHoleCore
    private void OnDrawGizmosSelected()
    {
        if (blackHoleCore == null) return;

        Vector3 center = blackHoleCore.transform.position;

        // Radio mínimo
        Gizmos.color = new Color(0.2f, 0.8f, 0.2f, 0.3f);
        Gizmos.DrawWireSphere(center, minSpawnRadius);

        // Radio máximo
        Gizmos.color = new Color(0.8f, 0.2f, 0.2f, 0.3f);
        Gizmos.DrawWireSphere(center, maxSpawnRadius);

        // NUEVO: Mostrar zona de peligro (horizonte de eventos)
        Gizmos.color = new Color(1f, 0f, 0f, 0.8f);
        Gizmos.DrawWireSphere(center, blackHoleCore.EventHorizonRadius);
    }
}