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
    [SerializeField, ReadOnly] private float gameDuration = 300f; // Duración configurada del juego

    private CircleCollider2D gravityTrigger;
    private BlackHoleGravityProcessor gravityProcessor;
    private BlackHoleZoneManager zoneManager;
    private readonly HashSet<IGravityAffected> affectedObjects = new HashSet<IGravityAffected>();
    private float gameStartTime;
    private bool isActive = true;
    private bool gameDurationSet = false; // Para verificar si se configuró la duración

    public Vector2 Position => transform.position;
    public float CurrentIntensity => currentIntensity;
    public float CurrentInfluenceRadius => currentInfluenceRadius;
    public float EventHorizonRadius => config.EventHorizonRadius;
    public bool IsActive => isActive;
    public int AffectedObjectsCount => affectedObjects.Count;
    public float GameDuration => gameDuration;

    private void Awake()
    {
        InitializeComponents();
        ValidateConfiguration();

        // Suscribirse a eventos de GameManager para recibir configuración automáticamente
        if (GameManager.Instance != null)
        {
            GameManager.Instance.OnGameStateChanged += OnGameStateChanged;
        }
    }

    private void Start()
    {
        gameStartTime = Time.time;
        SetupInitialState();
    }

    private void OnDestroy()
    {
        // Desuscribirse del evento
        if (GameManager.Instance != null)
        {
            GameManager.Instance.OnGameStateChanged -= OnGameStateChanged;
        }
    }

    /// <summary>
    /// Configura la duración del juego para el cálculo de intensidad
    /// </summary>
    /// <param name="duration">Duración del juego en segundos</param>
    public void SetGameDuration(float duration)
    {
        gameDuration = Mathf.Max(30f, duration); // Mínimo 30 segundos para evitar valores muy pequeños
        gameDurationSet = true;

        Debug.Log($"BlackHole configurado con duración: {gameDuration} segundos", this);
    }

    /// <summary>
    /// Maneja los cambios de estado del juego automáticamente
    /// </summary>
    private void OnGameStateChanged(GameState newState)
    {
        switch (newState)
        {
            case GameState.InGame:
                // Configurar duración automáticamente cuando inicia el juego
                if (!gameDurationSet && GameManager.Instance != null)
                {
                    SetGameDuration(GameManager.Instance.GameDuration);
                }
                gameStartTime = Time.time; // Reiniciar tiempo de inicio
                break;

            case GameState.InMenu:
                // Resetear estado cuando vuelve al menú
                gameDurationSet = false;
                currentIntensity = 1f;
                break;
        }
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

        // Usar la duración configurada del juego en lugar de valor hardcodeado
        float normalizedTime = timeElapsed / gameDuration;

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
        // Verificar si el objeto está en la colección antes de intentar removerlo
        if (affectedObjects.Contains(obj))
        {
            // Marcar el objeto como consumido antes de removerlo
            obj.OnReachEventHorizon(this);

            // Remover de la colección
            affectedObjects.Remove(obj);

            // Actualizar contador y disparar evento
            objectsInField = affectedObjects.Count;
            BlackHoleEvents.TriggerObjectConsumed(obj);
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

    /// <summary>
    /// Obtiene el progreso actual del agujero negro (0-1)
    /// </summary>
    public float GetProgressPercentage()
    {
        if (!gameDurationSet) return 0f;

        float timeElapsed = Time.time - gameStartTime;
        return Mathf.Clamp01(timeElapsed / gameDuration);
    }
}