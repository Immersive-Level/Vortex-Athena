using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Sistema de generación de recursos optimizado para BlackHoleCore
/// Object pooling eficiente sin overhead de debug
/// </summary>
public class ResourceSpawner : MonoBehaviour
{
    [System.Serializable]
    public class ResourceInfo
    {
        public ResourceType resourceType;
        public GameObject prefab;
        [Range(0f, 1f)] public float spawnProbability = 0.5f;
        public int initialPoolSize = 10;
    }

    [Header("Configuración de Recursos")]
    public List<ResourceInfo> resourceInfoList = new List<ResourceInfo>();

    [Header("Sistema BlackHole")]
    [SerializeField] private BlackHoleCore blackHoleCore;
    [SerializeField] private bool autoFindBlackHole = true;
    [SerializeField] private bool autoAddGravityAdapter = true;

    [Header("Spawning")]
    [SerializeField] private float minSpawnRadius = 3f;
    [SerializeField] private float maxSpawnRadius = 5f;
    [SerializeField] private float spawnInterval = 2f;
    [SerializeField] private int maxActiveResources = 50;
    [SerializeField] private LayerMask obstacleLayer;

    [Header("Pooling")]
    [SerializeField] private Transform poolContainer;
    [SerializeField] private float cleanupInterval = 15f;

    private Dictionary<ResourceType, Queue<GameObject>> resourcePools = new Dictionary<ResourceType, Queue<GameObject>>();
    private HashSet<GameObject> activeResources = new HashSet<GameObject>();
    private List<ResourceInfo> weightedResourceList;
    private float spawnTimer;

    private static ResourceSpawner _instance;
    public static ResourceSpawner Instance => _instance;

    private void Awake()
    {
        if (_instance != null && _instance != this)
        {
            Destroy(gameObject);
            return;
        }
        _instance = this;

        if (poolContainer == null)
        {
            GameObject container = new GameObject("ResourcePoolContainer");
            poolContainer = container.transform;
            poolContainer.SetParent(transform);
        }

        PrecalculateWeightedResources();
    }

    private void Start()
    {
        if (autoFindBlackHole && blackHoleCore == null)
        {
            blackHoleCore = FindAnyObjectByType<BlackHoleCore>();
            if (blackHoleCore == null)
            {
                Debug.LogError("ResourceSpawner: BlackHoleCore not found!", this);
                enabled = false;
                return;
            }
        }

        InitializePools();
        spawnTimer = spawnInterval;
        InvokeRepeating(nameof(CheckAndCleanupResources), cleanupInterval, cleanupInterval);
        BlackHoleEvents.ObjectConsumed += OnResourceConsumedByBlackHole;
    }

    private void OnDestroy()
    {
        BlackHoleEvents.ObjectConsumed -= OnResourceConsumedByBlackHole;
        CancelInvoke();
    }

    private void OnResourceConsumedByBlackHole(IGravityAffected gravityAffected)
    {
        if (gravityAffected?.Transform != null)
        {
            GameObject obj = gravityAffected.Transform.gameObject;
            CollectibleResource resource = obj.GetComponent<CollectibleResource>();

            if (resource != null && activeResources.Contains(obj))
            {
                resource.isCollected = true;
                ReturnToPool(obj);
            }
        }
    }

    private void Update()
    {
        spawnTimer -= Time.deltaTime;
        if (spawnTimer <= 0 && activeResources.Count < maxActiveResources)
        {
            SpawnResource();
            spawnTimer = spawnInterval;
        }
    }

    private void PrecalculateWeightedResources()
    {
        weightedResourceList = new List<ResourceInfo>();

        foreach (var info in resourceInfoList)
        {
            if (info.resourceType == null || info.prefab == null) continue;

            int weight = Mathf.RoundToInt(info.spawnProbability * 100);
            for (int i = 0; i < weight; i++)
            {
                weightedResourceList.Add(info);
            }
        }
    }

    private void InitializePools()
    {
        foreach (var resourceInfo in resourceInfoList)
        {
            if (resourceInfo.resourceType == null || resourceInfo.prefab == null) continue;

            Queue<GameObject> pool = new Queue<GameObject>(resourceInfo.initialPoolSize);

            for (int i = 0; i < resourceInfo.initialPoolSize; i++)
            {
                GameObject obj = CreateResourceObject(resourceInfo);
                obj.SetActive(false);
                pool.Enqueue(obj);
            }

            resourcePools[resourceInfo.resourceType] = pool;
        }
    }

    private GameObject CreateResourceObject(ResourceInfo info)
    {
        GameObject obj = Instantiate(info.prefab, poolContainer);

        ConfigureCollectibleResource(obj, info.resourceType);
        ConfigureRigidbody(obj);
        ConfigureCollider(obj);
        ConfigureGravityAdapter(obj);

        return obj;
    }

    private void ConfigureGravityAdapter(GameObject obj)
    {
        if (obj.GetComponent<IGravityAffected>() != null) return;

        if (autoAddGravityAdapter)
        {
            CollectibleResourceAdapter adapter = obj.GetComponent<CollectibleResourceAdapter>();
            if (adapter == null)
            {
                obj.AddComponent<CollectibleResourceAdapter>();
            }
        }
    }

    private void ConfigureCollectibleResource(GameObject obj, ResourceType resourceType)
    {
        CollectibleResource resource = obj.GetComponent<CollectibleResource>();
        if (resource == null)
        {
            resource = obj.AddComponent<CollectibleResource>();
        }
        resource.resourceType = resourceType;

        if (obj.GetComponent<ResourceLifetime>() == null)
            obj.AddComponent<ResourceLifetime>();
    }

    private void ConfigureRigidbody(GameObject obj)
    {
        Rigidbody2D rb = obj.GetComponent<Rigidbody2D>();
        if (rb == null)
        {
            rb = obj.AddComponent<Rigidbody2D>();
            rb.gravityScale = 0;
            rb.linearDamping = 0.5f;
        }
    }

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

    public GameObject GetRandomResource()
    {
        if (weightedResourceList.Count == 0) return null;

        int randomIndex = Random.Range(0, weightedResourceList.Count);
        ResourceInfo selectedInfo = weightedResourceList[randomIndex];

        return GetResourceFromPool(selectedInfo.resourceType);
    }

    private GameObject GetResourceFromPool(ResourceType resourceType)
    {
        if (resourceType == null || !resourcePools.ContainsKey(resourceType)) return null;

        Queue<GameObject> pool = resourcePools[resourceType];
        GameObject obj = null;

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

        if (obj != null)
        {
            obj.SetActive(true);
            activeResources.Add(obj);
        }

        return obj;
    }

    public void ReturnToPool(GameObject obj)
    {
        if (obj == null || !obj.activeInHierarchy) return;

        activeResources.Remove(obj);

        CollectibleResource resource = obj.GetComponent<CollectibleResource>();
        if (resource == null || resource.resourceType == null)
        {
            Destroy(obj);
            return;
        }

        ResourceType resourceType = resource.resourceType;
        resource.isCollected = false;

        obj.SetActive(false);
        obj.transform.SetParent(poolContainer);

        Rigidbody2D rb = obj.GetComponent<Rigidbody2D>();
        if (rb != null)
        {
            rb.linearVelocity = Vector2.zero;
            rb.angularVelocity = 0f;
        }

        if (!resourcePools.ContainsKey(resourceType))
        {
            resourcePools[resourceType] = new Queue<GameObject>();
        }

        resourcePools[resourceType].Enqueue(obj);
    }

    private void SpawnResource()
    {
        if (blackHoleCore == null) return;

        Vector2 randomDirection = Random.insideUnitCircle.normalized;
        float randomDistance = Random.Range(minSpawnRadius, maxSpawnRadius);
        Vector3 spawnPosition = blackHoleCore.transform.position + new Vector3(randomDirection.x, randomDirection.y, 0) * randomDistance;

        if (Physics2D.OverlapCircle(spawnPosition, 1f, obstacleLayer)) return;

        float distanceToCenter = Vector2.Distance(spawnPosition, blackHoleCore.Position);
        if (distanceToCenter <= blackHoleCore.EventHorizonRadius * 1.5f) return;

        GameObject resource = GetRandomResource();
        if (resource != null)
        {
            resource.transform.position = spawnPosition;
            resource.transform.rotation = Quaternion.Euler(0, 0, Random.Range(0, 360));

            Rigidbody2D rb = resource.GetComponent<Rigidbody2D>();
            if (rb != null)
            {
                rb.linearVelocity = Random.insideUnitCircle.normalized * Random.Range(1f, 2f);
            }
        }
    }

    private void CheckAndCleanupResources()
    {
        List<GameObject> problematicResources = new List<GameObject>();

        foreach (GameObject resource in activeResources)
        {
            if (resource == null) continue;

            bool shouldCleanup = false;

            CollectibleResource collectible = resource.GetComponent<CollectibleResource>();
            if (collectible != null && collectible.isCollected)
            {
                shouldCleanup = true;
            }
            else
            {
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
                    if (allDisabled) shouldCleanup = true;
                }
            }

            if (shouldCleanup)
            {
                problematicResources.Add(resource);
            }
        }

        foreach (GameObject resource in problematicResources)
        {
            ReturnToPool(resource);
        }
    }

    public void SetBlackHoleReference(BlackHoleCore newBlackHole)
    {
        blackHoleCore = newBlackHole;
    }

    public void AdjustSpawnRadiusBasedOnBlackHole()
    {
        if (blackHoleCore == null) return;

        float intensity = blackHoleCore.CurrentIntensity;
        minSpawnRadius = 3f + (intensity - 1f) * 2f;
        maxSpawnRadius = 5f + (intensity - 1f) * 3f;
        minSpawnRadius = Mathf.Max(minSpawnRadius, blackHoleCore.EventHorizonRadius * 2f);
    }
}