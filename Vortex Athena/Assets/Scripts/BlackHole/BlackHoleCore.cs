using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Componente principal del agujero negro - maneja estados y coordinación
/// </summary>
[RequireComponent(typeof(CircleCollider2D))]
public class BlackHoleCore : MonoBehaviour
{
    [Header("Configuration")]
    [SerializeField] private BlackHoleConfiguration config;
    [SerializeField] private LayerMask affectedLayers = -1;

    [Header("Runtime State")]
    [SerializeField, ReadOnly] private float currentIntensity = 1f;
    [SerializeField, ReadOnly] private float currentInfluenceRadius;
    [SerializeField, ReadOnly] private int objectsInField = 0;

    private CircleCollider2D gravityTrigger;
    private BlackHoleGravityProcessor gravityProcessor;
    private BlackHoleZoneManager zoneManager;
    private readonly HashSet<IGravityAffected> affectedObjects = new HashSet<IGravityAffected>();
    private float gameStartTime;
    private bool isActive = true;

    public Vector2 Position => transform.position;
    public float CurrentIntensity => currentIntensity;
    public float CurrentInfluenceRadius => currentInfluenceRadius;
    public float EventHorizonRadius => config.EventHorizonRadius;
    public bool IsActive => isActive;
    public int AffectedObjectsCount => affectedObjects.Count;

    private void Awake()
    {
        InitializeComponents();
        ValidateConfiguration();
    }

    private void Start()
    {
        gameStartTime = Time.time;
        SetupInitialState();
    }

    private void InitializeComponents()
    {
        gravityTrigger = GetComponent<CircleCollider2D>();
        gravityTrigger.isTrigger = true;

        gravityProcessor = GetComponent<BlackHoleGravityProcessor>() ??
                          gameObject.AddComponent<BlackHoleGravityProcessor>();

        zoneManager = GetComponent<BlackHoleZoneManager>() ??
                     gameObject.AddComponent<BlackHoleZoneManager>();

        gravityProcessor.Initialize(this, config);
        zoneManager.Initialize(this, config);
    }

    private void ValidateConfiguration()
    {
        if (config == null)
        {
            Debug.LogError($"BlackHoleCore requires configuration! Disabling {name}", this);
            enabled = false;
            return;
        }

        if (config.EventHorizonRadius >= config.InfluenceRadius)
        {
            Debug.LogWarning($"Event horizon should be smaller than influence radius on {name}", this);
        }
    }

    private void SetupInitialState()
    {
        currentInfluenceRadius = config.InfluenceRadius;
        gravityTrigger.radius = currentInfluenceRadius;
        BlackHoleEvents.TriggerInfluenceRadiusChanged(currentInfluenceRadius);
    }

    private void Update()
    {
        if (!isActive) return;

        UpdateIntensity();
        UpdateInfluenceRadius();
        gravityProcessor.ProcessGravity(affectedObjects);
    }

    private void UpdateIntensity()
    {
        float timeElapsed = Time.time - gameStartTime;
        float normalizedTime = timeElapsed / 300f; // 5 minutes to max intensity

        float newIntensity = config.IntensityOverTime.Evaluate(normalizedTime);

        if (Mathf.Abs(newIntensity - currentIntensity) > 0.01f)
        {
            currentIntensity = newIntensity;
            BlackHoleEvents.TriggerGravityIntensityChanged(currentIntensity);
        }
    }

    private void UpdateInfluenceRadius()
    {
        float targetRadius = Mathf.Lerp(config.InfluenceRadius, config.MaxInfluenceRadius,
                                       (currentIntensity - 1f) / 1f);

        if (Mathf.Abs(targetRadius - currentInfluenceRadius) > 0.1f)
        {
            currentInfluenceRadius = targetRadius;
            gravityTrigger.radius = currentInfluenceRadius;
            BlackHoleEvents.TriggerInfluenceRadiusChanged(currentInfluenceRadius);
        }
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        if (!IsValidTarget(other)) return;

        var gravityAffected = other.GetComponent<IGravityAffected>();
        if (gravityAffected != null && affectedObjects.Add(gravityAffected))
        {
            gravityAffected.OnEnterGravityField(this);
            BlackHoleEvents.TriggerObjectEnteredField(gravityAffected);
            objectsInField = affectedObjects.Count;
        }
    }

    private void OnTriggerExit2D(Collider2D other)
    {
        if (!IsValidTarget(other)) return;

        var gravityAffected = other.GetComponent<IGravityAffected>();
        if (gravityAffected != null && affectedObjects.Remove(gravityAffected))
        {
            gravityAffected.OnExitGravityField(this);
            BlackHoleEvents.TriggerObjectExitedField(gravityAffected);
            objectsInField = affectedObjects.Count;
        }
    }

    private bool IsValidTarget(Collider2D collider)
    {
        return ((1 << collider.gameObject.layer) & affectedLayers) != 0;
    }

    public void ConsumeObject(IGravityAffected obj)
    {
        if (affectedObjects.Remove(obj))
        {
            obj.OnReachEventHorizon(this);
            BlackHoleEvents.TriggerObjectConsumed(obj);
            objectsInField = affectedObjects.Count;
        }
    }

    public void SetActive(bool active)
    {
        isActive = active;
        gravityTrigger.enabled = active;
    }

    public void SetIntensityMultiplier(float multiplier)
    {
        currentIntensity *= multiplier;
        BlackHoleEvents.TriggerGravityIntensityChanged(currentIntensity);
    }
}