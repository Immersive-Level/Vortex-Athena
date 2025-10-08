using UnityEngine;

/// <summary>
/// Adaptador para conectar recursos existentes con el sistema de gravedad
/// </summary>
[RequireComponent(typeof(CollectibleResource))]
public class CollectibleResourceAdapter : MonoBehaviour, IGravityAffected
{
    [Header("Gravity Configuration")]
    [SerializeField] private float gravityMultiplier = 1f;
    [SerializeField] private bool isImmuneToEventHorizon = false;

    private CollectibleResource collectibleResource;
    private Rigidbody2D rigidBody;
    private bool hasBeenCollected = false;

    public Transform Transform => transform;
    public Rigidbody2D Rigidbody => rigidBody;
    public float GravityMultiplier => gravityMultiplier;
    public bool IsActive => gameObject.activeInHierarchy && !hasBeenCollected;

    private void Awake()
    {
        collectibleResource = GetComponent<CollectibleResource>();
        rigidBody = GetComponent<Rigidbody2D>();
        ConfigureGravityByResourceType();
    }

    private void ConfigureGravityByResourceType()
    {
        if (collectibleResource?.resourceType == null) return;

        string resourceName = collectibleResource.resourceType.name.ToLower();

        switch (resourceName)
        {
            case "fuel":
            case "combustible":
                gravityMultiplier = 0.7f;
                break;
            case "points":
            case "puntos":
                gravityMultiplier = 0.7f;
                break;
            case "powerup":
            case "shield":
                gravityMultiplier = 0.6f;
                isImmuneToEventHorizon = true;
                break;
            default:
                gravityMultiplier = 1f;
                break;
        }
    }

    private void OnEnable()
    {
        hasBeenCollected = false;
    }

    private void Update()
    {
        if (collectibleResource != null && collectibleResource.isCollected && !hasBeenCollected)
        {
            hasBeenCollected = true;
        }
    }

    public void OnEnterGravityField(BlackHoleCore blackHole) { }

    public void OnExitGravityField(BlackHoleCore blackHole) { }

    public void OnReachEventHorizon(BlackHoleCore blackHole)
    {
        if (hasBeenCollected || isImmuneToEventHorizon) return;

        hasBeenCollected = true;

        if (collectibleResource != null)
        {
            collectibleResource.OnConsumedByGravitySystem();
        }
    }
}
