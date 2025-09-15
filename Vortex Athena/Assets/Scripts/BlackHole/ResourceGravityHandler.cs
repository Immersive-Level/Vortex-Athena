using UnityEngine;

/// <summary>
/// Maneja la interacción específica de recursos con el agujero negro
/// </summary>
public class ResourceGravityHandler : GravityAffectedBase
{
    [Header("Resource Configuration")]
    [SerializeField] private ResourceType resourceType;
    [SerializeField] private float value = 1f;
    [SerializeField] private bool isAutoCollected = true;
    [SerializeField] private float autoCollectRadius = 1f;

    private bool isBeingCollected = false;
    private SphereCollider collectionTrigger;

    public ResourceType Type => resourceType;
    public float Value => value;
    public bool IsBeingCollected => isBeingCollected;

    protected override void Awake()
    {
        base.Awake();
        SetupCollectionTrigger();
    }

    private void SetupCollectionTrigger()
    {
        if (!isAutoCollected) return;

        collectionTrigger = gameObject.AddComponent<SphereCollider>();
        collectionTrigger.isTrigger = true;
        collectionTrigger.radius = autoCollectRadius;
    }

    protected override void OnConsumedByBlackHole(BlackHoleCore blackHole)
    {
        OnResourceDestroyed();
        Destroy(gameObject);
    }

    private void OnTriggerEnter(Collider other)
    {
        if (!isAutoCollected || isBeingCollected) return;

        var resourceCollector = other.GetComponent<ResourceCollector>();
        if (resourceCollector != null)
        {
            isBeingCollected = true;
            OnResourceCollected(resourceCollector);
        }
    }

    protected virtual void OnResourceCollected(ResourceCollector collector) { }
    protected virtual void OnResourceDestroyed() { }

    public void SetValue(float newValue)
    {
        value = Mathf.Max(0f, newValue);
    }
}