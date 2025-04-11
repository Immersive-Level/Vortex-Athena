using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Sistema de generación de recursos alrededor del agujero negro
/// Maneja el object pooling y la generación de recursos
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
    [Tooltip("Referencia al agujero negro")]
    public BlackHole blackHole;

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

    // Diccionarios para almacenar los pools de cada tipo de recurso
    private Dictionary<ResourceType, Queue<GameObject>> resourcePools = new Dictionary<ResourceType, Queue<GameObject>>();

    // Lista de recursos activos
    private List<GameObject> activeResources = new List<GameObject>();

    // Contador de tiempo para la generación
    private float spawnTimer;

    // Referencia al BlackHoleAttractionManager
    private BlackHoleAttractionManager attractionManager;

    private void Awake()
    {
        // Crear el contenedor si no existe
        if (poolContainer == null)
        {
            GameObject container = new GameObject("ResourcePoolContainer");
            poolContainer = container.transform;
            poolContainer.SetParent(transform);
        }
    }

    private void Start()
    {
        // Buscar el agujero negro si no está asignado
        if (blackHole == null)
        {
            blackHole = FindObjectOfType<BlackHole>();

            if (blackHole == null)
            {
                Debug.LogWarning("ResourceSpawner: No se encontró un BlackHole en la escena.");
                enabled = false;
                return;
            }
        }

        // Obtener referencia al BlackHoleAttractionManager
        attractionManager = BlackHoleAttractionManager.Instance;
        if (attractionManager == null)
        {
            Debug.LogWarning("ResourceSpawner: No se encontró BlackHoleAttractionManager. La atracción gravitacional podría no funcionar correctamente.");
        }

        // Inicializar los pools
        InitializePools();

        // Inicializar timer
        spawnTimer = spawnInterval;
    }

    private void Update()
    {
        // Limpiar recursos nulos de la lista
        activeResources.RemoveAll(r => r == null);

        // Generar recursos si es tiempo y hay espacio
        spawnTimer -= Time.deltaTime;
        if (spawnTimer <= 0 && activeResources.Count < maxActiveResources)
        {
            SpawnResource();
            spawnTimer = spawnInterval;
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
            Queue<GameObject> pool = new Queue<GameObject>();

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
    /// </summary>
    private GameObject CreateResourceObject(ResourceInfo info)
    {
        GameObject obj = Instantiate(info.prefab, poolContainer);

        // Configurar el componente CollectibleResource
        CollectibleResource resource = obj.GetComponent<CollectibleResource>();
        if (resource == null)
        {
            resource = obj.AddComponent<CollectibleResource>();
        }
        resource.resourceType = info.resourceType;

        // Asegurarse de que tenga Rigidbody2D
        Rigidbody2D rb = obj.GetComponent<Rigidbody2D>();
        if (rb == null)
        {
            rb = obj.AddComponent<Rigidbody2D>();
            rb.gravityScale = 0; // No afectado por gravedad
            rb.linearDamping = 0.5f;      // Algo de resistencia
        }

        // Asegurarse de que tenga Collider2D
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

        return obj;
    }

    /// <summary>
    /// Obtiene un recurso aleatorio del pool basado en las probabilidades
    /// </summary>
    public GameObject GetRandomResource()
    {
        // Lista para probabilidades ponderadas
        List<ResourceInfo> weightedList = new List<ResourceInfo>();

        foreach (var resourceInfo in resourceInfoList)
        {
            if (resourceInfo.resourceType == null) continue;

            // Añadir basado en probabilidad (convertir a porcentaje)
            int weight = Mathf.RoundToInt(resourceInfo.spawnProbability * 100);
            for (int i = 0; i < weight; i++)
            {
                weightedList.Add(resourceInfo);
            }
        }

        if (weightedList.Count == 0)
            return null;

        // Seleccionar uno aleatorio
        int randomIndex = Random.Range(0, weightedList.Count);
        ResourceInfo selectedInfo = weightedList[randomIndex];

        return GetResourceFromPool(selectedInfo.resourceType);
    }

    /// <summary>
    /// Obtiene un recurso del pool, o crea uno nuevo si es necesario
    /// </summary>
    private GameObject GetResourceFromPool(ResourceType resourceType)
    {
        if (resourceType == null || !resourcePools.ContainsKey(resourceType))
            return null;

        Queue<GameObject> pool = resourcePools[resourceType];

        // Si no hay objetos disponibles, crear uno nuevo
        if (pool.Count == 0)
        {
            ResourceInfo info = resourceInfoList.Find(r => r.resourceType == resourceType);
            if (info != null)
            {
                return CreateResourceObject(info);
            }
            return null;
        }

        // Obtener objeto del pool
        GameObject obj = pool.Dequeue();
        obj.SetActive(true);

        // Registrar con el BlackHoleAttractionManager
        if (attractionManager != null)
        {
            AffectedByBlackHole affected = obj.GetComponent<AffectedByBlackHole>();
            if (affected != null)
            {
                attractionManager.RegisterAffectableObject(affected);
            }
        }

        return obj;
    }

    /// <summary>
    /// Devuelve un recurso al pool para su reutilización
    /// </summary>
    public void ReturnToPool(GameObject obj)
    {
        if (obj == null) return;

        // Desactivar y devolver al pool
        obj.SetActive(false);
        obj.transform.SetParent(poolContainer);

        // Desregistrar del BlackHoleAttractionManager
        if (attractionManager != null)
        {
            AffectedByBlackHole affected = obj.GetComponent<AffectedByBlackHole>();
            if (affected != null)
            {
                attractionManager.UnregisterAffectableObject(affected);
            }
        }

        // Obtener el tipo de recurso
        CollectibleResource resource = obj.GetComponent<CollectibleResource>();
        if (resource == null || resource.resourceType == null)
        {
            Destroy(obj); // Si no tiene el componente necesario, destruirlo
            return;
        }

        // Añadir a la cola correspondiente
        if (!resourcePools.ContainsKey(resource.resourceType))
        {
            resourcePools[resource.resourceType] = new Queue<GameObject>();
        }

        resourcePools[resource.resourceType].Enqueue(obj);

        // Remover de la lista de activos
        activeResources.Remove(obj);
    }

    /// <summary>
    /// Genera un recurso en una posición aleatoria alrededor del agujero negro
    /// </summary>
    private void SpawnResource()
    {
        if (blackHole == null) return;

        // Obtener posición del agujero negro
        Vector3 blackHolePosition = blackHole.transform.position;

        // Generar posición aleatoria alrededor del agujero negro
        Vector2 randomDirection = Random.insideUnitCircle.normalized;
        float randomDistance = Random.Range(minSpawnRadius, maxSpawnRadius);
        Vector3 spawnPosition = blackHolePosition + new Vector3(randomDirection.x, randomDirection.y, 0) * randomDistance;

        // Verificar si hay obstáculos
        bool isValidPosition = !Physics2D.OverlapCircle(spawnPosition, 1f, obstacleLayer);

        if (isValidPosition)
        {
            // Obtener recurso aleatorio
            GameObject resource = GetRandomResource();

            if (resource != null)
            {
                // Configurar posición y rotación
                resource.transform.position = spawnPosition;
                resource.transform.rotation = Quaternion.Euler(0, 0, Random.Range(0, 360));

                // Añadir a la lista de activos
                activeResources.Add(resource);

                // Dar velocidad inicial aleatoria
                Rigidbody2D rb = resource.GetComponent<Rigidbody2D>();
                if (rb != null)
                {
                    Vector2 randomVelocity = Random.insideUnitCircle.normalized * Random.Range(1f, 3f);
                    rb.linearVelocity = randomVelocity;
                }

                AffectedByBlackHole affectedByBlackHole = resource.GetComponent<AffectedByBlackHole>();
                if (affectedByBlackHole != null)
                {
                    affectedByBlackHole.canBeAffected = true;
                }
            }
        }
    }

    // Visualizar radios de spawn en el editor
    private void OnDrawGizmosSelected()
    {
        if (blackHole == null) return;

        Vector3 center = blackHole.transform.position;

        // Radio mínimo
        Gizmos.color = new Color(0.2f, 0.8f, 0.2f, 0.3f);
        Gizmos.DrawWireSphere(center, minSpawnRadius);

        // Radio máximo
        Gizmos.color = new Color(0.8f, 0.2f, 0.2f, 0.3f);
        Gizmos.DrawWireSphere(center, maxSpawnRadius);
    }
}
