using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Componente principal del agujero negro - Versión optimizada para producción
/// </summary>
[RequireComponent(typeof(CircleCollider2D))]
public class BlackHoleCore : MonoBehaviour
{
    [Header("Configuration")]
    [SerializeField] private BlackHoleConfiguration config;
    [SerializeField] private LayerMask affectedLayers = -1;

    [Header("Runtime State - ReadOnly")]
    [SerializeField, ReadOnly] private float currentIntensity = 1f;
    [SerializeField, ReadOnly] private float currentInfluenceRadius;
    [SerializeField, ReadOnly] private int objectsInField = 0;
    [SerializeField, ReadOnly] private float gameDuration = 300f;

    // Componentes cacheados
    private CircleCollider2D gravityTrigger;
    private BlackHoleGravityProcessor gravityProcessor;
    private BlackHoleZoneManager zoneManager;

    // Colección optimizada para objetos afectados
    private readonly HashSet<IGravityAffected> affectedObjects = new HashSet<IGravityAffected>();

    // Estado de tiempo optimizado
    private float gameStartTime;
    private bool isActive = true;
    private bool gameDurationSet = false;

    // Cache para evitar recálculos
    private Vector2 cachedPosition;
    private bool positionCacheValid = false;

    // Propiedades públicas optimizadas
    public Vector2 Position
    {
        get
        {
            if (!positionCacheValid)
            {
                cachedPosition = transform.position;
                positionCacheValid = true;
            }
            return cachedPosition;
        }
    }

    public float CurrentIntensity => currentIntensity;
    public float CurrentInfluenceRadius => currentInfluenceRadius;
    public float EventHorizonRadius => config.EventHorizonRadius;
    public bool IsActive => isActive;
    public int AffectedObjectsCount => affectedObjects.Count;

    private void Awake()
    {
        InitializeComponents();
        ValidateConfiguration();

        // Optimización: Solo suscribirse si GameManager existe
        var gameManager = GameManager.Instance;
        if (gameManager != null)
            gameManager.OnGameStateChanged += OnGameStateChanged;
    }

    private void Start()
    {
        gameStartTime = Time.time;
        SetupInitialState();
    }

    private void OnDestroy()
    {
        var gameManager = GameManager.Instance;
        if (gameManager != null)
            gameManager.OnGameStateChanged -= OnGameStateChanged;
    }

    public void SetGameDuration(float duration)
    {
        gameDuration = Mathf.Max(30f, duration);
        gameDurationSet = true;
    }

    private void OnGameStateChanged(GameState newState)
    {
        switch (newState)
        {
            case GameState.InGame:
                if (!gameDurationSet)
                {
                    var gameManager = GameManager.Instance;
                    if (gameManager != null)
                        SetGameDuration(gameManager.GameDuration);
                }
                gameStartTime = Time.time;
                break;

            case GameState.InMenu:
                gameDurationSet = false;
                ResetToInitialState();
                break;
        }
    }

    private void InitializeComponents()
    {
        gravityTrigger = GetComponent<CircleCollider2D>();
        gravityTrigger.isTrigger = true;

        // Optimización: Evitar múltiples GetComponent calls
        gravityProcessor = GetComponent<BlackHoleGravityProcessor>();
        if (gravityProcessor == null)
            gravityProcessor = gameObject.AddComponent<BlackHoleGravityProcessor>();

        zoneManager = GetComponent<BlackHoleZoneManager>();
        if (zoneManager == null)
            zoneManager = gameObject.AddComponent<BlackHoleZoneManager>();

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
        if (config.UseConstantSize)
        {
            currentIntensity = config.ConstantIntensityValue;
            currentInfluenceRadius = Mathf.Lerp(config.InfluenceRadius, config.MaxInfluenceRadius,
                                               (currentIntensity - 1f));
        }
        else
        {
            currentIntensity = 1f;
            currentInfluenceRadius = config.InfluenceRadius;
        }

        gravityTrigger.radius = currentInfluenceRadius;

        // Optimización: Solo disparar eventos si hay listeners
        BlackHoleEvents.TriggerInfluenceRadiusChanged(currentInfluenceRadius);
        BlackHoleEvents.TriggerGravityIntensityChanged(currentIntensity);
    }

    private void ResetToInitialState()
    {
        currentIntensity = config.UseConstantSize ? config.ConstantIntensityValue : 1f;
    }

    private void Update()
    {
        if (!isActive) return;

        // Invalidar cache de posición cada frame
        positionCacheValid = false;

        // Solo actualizar tamaño si no está en modo constante
        if (!config.UseConstantSize)
        {
            UpdateIntensity();
            UpdateInfluenceRadius();
        }

        gravityProcessor.ProcessGravity(affectedObjects);
    }

    private void UpdateIntensity()
    {
        float timeElapsed = Time.time - gameStartTime;
        float normalizedTime = timeElapsed / gameDuration;
        float newIntensity = config.IntensityOverTime.Evaluate(normalizedTime);

        // Optimización: Solo actualizar si hay cambio significativo
        if (Mathf.Abs(newIntensity - currentIntensity) > 0.01f)
        {
            currentIntensity = newIntensity;
            BlackHoleEvents.TriggerGravityIntensityChanged(currentIntensity);
        }
    }

    private void UpdateInfluenceRadius()
    {
        float targetRadius = Mathf.Lerp(config.InfluenceRadius, config.MaxInfluenceRadius,
                                       currentIntensity - 1f);

        // Optimización: Solo actualizar si hay cambio significativo
        if (Mathf.Abs(targetRadius - currentInfluenceRadius) > 0.1f)
        {
            currentInfluenceRadius = targetRadius;
            gravityTrigger.radius = currentInfluenceRadius;
            BlackHoleEvents.TriggerInfluenceRadiusChanged(currentInfluenceRadius);
        }
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        // Optimización: Verificación rápida de layer antes de GetComponent
        if (((1 << other.gameObject.layer) & affectedLayers) == 0) return;

        var gravityAffected = other.GetComponent<IGravityAffected>();
        if (gravityAffected != null && gravityAffected.IsActive && affectedObjects.Add(gravityAffected))
        {
            gravityAffected.OnEnterGravityField(this);
            BlackHoleEvents.TriggerObjectEnteredField(gravityAffected);
            objectsInField = affectedObjects.Count;
        }
    }

    private void OnTriggerExit2D(Collider2D other)
    {
        if (((1 << other.gameObject.layer) & affectedLayers) == 0) return;

        var gravityAffected = other.GetComponent<IGravityAffected>();
        if (gravityAffected != null && affectedObjects.Remove(gravityAffected))
        {
            gravityAffected.OnExitGravityField(this);
            BlackHoleEvents.TriggerObjectExitedField(gravityAffected);
            objectsInField = affectedObjects.Count;
        }
    }

    public void ConsumeObject(IGravityAffected obj)
    {
        if (obj == null || !affectedObjects.Contains(obj)) return;

        obj.OnReachEventHorizon(this);
        affectedObjects.Remove(obj);
        objectsInField = affectedObjects.Count;
        BlackHoleEvents.TriggerObjectConsumed(obj);
    }

    /// <summary>
    /// Verifica manualmente si un objeto debería estar en el campo gravitacional
    /// Optimizado para usar squared distance y evitar allocaciones
    /// </summary>
    public void CheckAndAddGravityObject(IGravityAffected gravityAffected)
    {
        if (gravityAffected?.Transform == null || !gravityAffected.IsActive) return;
        if (affectedObjects.Contains(gravityAffected)) return;

        // Optimización: Usar squared distance para evitar sqrt
        Vector2 position = Position;
        Vector2 objectPos = gravityAffected.Transform.position;
        float sqrDistance = (position - objectPos).sqrMagnitude;
        float sqrRadius = currentInfluenceRadius * currentInfluenceRadius;

        if (sqrDistance <= sqrRadius)
        {
            int objectLayer = gravityAffected.Transform.gameObject.layer;
            if (((1 << objectLayer) & affectedLayers) != 0)
            {
                affectedObjects.Add(gravityAffected);
                gravityAffected.OnEnterGravityField(this);
                BlackHoleEvents.TriggerObjectEnteredField(gravityAffected);
                objectsInField = affectedObjects.Count;
            }
        }
    }

    public void SetActive(bool active)
    {
        isActive = active;
        if (gravityTrigger != null)
            gravityTrigger.enabled = active;
    }

    public void SetIntensityMultiplier(float multiplier)
    {
        currentIntensity = Mathf.Max(1f, currentIntensity * multiplier);
        BlackHoleEvents.TriggerGravityIntensityChanged(currentIntensity);
    }

    public float GetProgressPercentage()
    {
        if (!gameDurationSet || config.UseConstantSize)
            return 0f;

        float timeElapsed = Time.time - gameStartTime;
        return Mathf.Clamp01(timeElapsed / gameDuration);
    }

#if UNITY_EDITOR
    [ContextMenu("Force Gravity Check")]
    private void ForceGravityCheck()
    {
        var gravityObjects = FindObjectsOfType<MonoBehaviour>();
        foreach (var obj in gravityObjects)
        {
            if (obj is IGravityAffected gravityAffected)
                CheckAndAddGravityObject(gravityAffected);
        }
        Debug.Log($"Gravity check completed. Objects in field: {objectsInField}");
    }
#endif
}