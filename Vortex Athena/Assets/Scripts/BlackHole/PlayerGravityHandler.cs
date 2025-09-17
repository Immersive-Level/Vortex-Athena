using UnityEngine;
using GameSystems;

/// <summary>
/// Maneja la interacción del jugador con el agujero negro - Versión optimizada para producción
/// </summary>
[RequireComponent(typeof(Rigidbody2D))]
public class PlayerGravityHandler : MonoBehaviour, IGravityAffected
{
    [Header("Gravity Configuration")]
    [SerializeField] private float gravityMultiplier = 1f;
    [SerializeField] private float emergencyThrustMultiplier = 1.5f;
    [SerializeField] private float dangerZoneMultiplier = 1.5f;

    [Header("Danger Zone Settings")]
    [SerializeField] private bool enableDangerZoneEffects = true;
    [SerializeField] private float dangerZoneRadius = 8f;

    [Header("Emergency Features")]
    [SerializeField] private bool autoEmergencyOnDanger = false;
    [SerializeField] private float emergencyFuelCost = 2f;

    [Header("Runtime State - ReadOnly")]
    [SerializeField, ReadOnly] private bool isInGravityField = false;
    [SerializeField, ReadOnly] private bool isInDangerZone = false;
    [SerializeField, ReadOnly] private float currentGravityIntensity = 0f;
    [SerializeField, ReadOnly] private bool emergencyThrustActive = false;

    // Componentes cacheados
    private Rigidbody2D rigidBody;
    private ShipController shipController;
    private FuelManager fuelManager;
    private UnifiedDeathManager deathManager;

    // Estado optimizado
    private BlackHoleCore currentBlackHole;
    private BlackHoleZoneManager zoneManager; // Cache del zone manager
    private float baseGravityMultiplier;
    private bool hasBeenConsumed = false;

    // Optimización de cálculos
    private float lastDistanceCheck = 0f;
    private const float DISTANCE_CHECK_INTERVAL = 0.1f; // Verificar distancia cada 100ms
    private float cachedDistance = float.MaxValue;
    private Vector2 lastPosition;

    // Propiedades de la interfaz IGravityAffected
    public Transform Transform => transform;
    public Rigidbody2D Rigidbody => rigidBody;
    public float GravityMultiplier => gravityMultiplier;
    public bool IsActive => gameObject.activeInHierarchy && !hasBeenConsumed &&
                           (deathManager == null || !deathManager.IsDead);

    // Propiedades públicas de estado
    public bool IsInGravityField => isInGravityField;
    public bool IsInDangerZone => isInDangerZone;
    public float CurrentGravityIntensity => currentGravityIntensity;
    public bool EmergencyThrustActive => emergencyThrustActive;

    private void Awake()
    {
        CacheComponents();
        baseGravityMultiplier = gravityMultiplier;
    }

    private void CacheComponents()
    {
        rigidBody = GetComponent<Rigidbody2D>();
        if (rigidBody == null)
        {
            Debug.LogError($"PlayerGravityHandler requires Rigidbody2D! Disabling {name}", this);
            enabled = false;
            return;
        }

        shipController = GetComponent<ShipController>();
        fuelManager = GetComponent<FuelManager>();
        deathManager = GetComponent<UnifiedDeathManager>();
    }

    private void Update()
    {
        if (!isInGravityField || currentBlackHole == null) return;

        UpdateGravityInfoOptimized();
        HandleAutoEmergencyThrust();
    }

    private void UpdateGravityInfoOptimized()
    {
        float currentTime = Time.time;

        // Optimización: Solo recalcular distancia periodicamente o si la posición cambió significativamente
        Vector2 currentPos = transform.position;
        bool forceUpdate = (currentPos - lastPosition).sqrMagnitude > 0.01f; // Movimiento significativo

        if (currentTime - lastDistanceCheck > DISTANCE_CHECK_INTERVAL || forceUpdate)
        {
            lastDistanceCheck = currentTime;
            lastPosition = currentPos;

            // Usar ZoneManager cache si está disponible
            if (zoneManager != null)
            {
                // Método optimizado que calcula todo en una pasada
                zoneManager.GetZoneInfo(currentPos, out bool inEventHorizon, out bool inInfluence, out float intensity);

                currentGravityIntensity = intensity;

                // Actualizar danger zone
                Vector2 blackHolePos = currentBlackHole.Position;
                float sqrDistance = (currentPos - blackHolePos).sqrMagnitude;
                float sqrDangerRadius = dangerZoneRadius * dangerZoneRadius;

                bool wasInDangerZone = isInDangerZone;
                isInDangerZone = sqrDistance <= sqrDangerRadius;

                if (isInDangerZone != wasInDangerZone)
                {
                    if (isInDangerZone)
                        OnEnteredDangerZone();
                    else
                        OnExitedDangerZone();
                }
            }
            else
            {
                // Fallback manual calculation
                UpdateGravityInfoManual(currentPos);
            }
        }
    }

    private void UpdateGravityInfoManual(Vector2 position)
    {
        Vector2 blackHolePos = currentBlackHole.Position;
        float sqrDistance = (position - blackHolePos).sqrMagnitude;

        // Intensity calculation
        float influenceRadius = currentBlackHole.CurrentInfluenceRadius;
        float sqrInfluenceRadius = influenceRadius * influenceRadius;

        if (sqrDistance >= sqrInfluenceRadius)
        {
            currentGravityIntensity = 0f;
        }
        else if (sqrDistance <= currentBlackHole.EventHorizonRadius * currentBlackHole.EventHorizonRadius)
        {
            currentGravityIntensity = 1f;
        }
        else
        {
            float distance = Mathf.Sqrt(sqrDistance);
            float normalizedDistance = distance / influenceRadius;
            currentGravityIntensity = 1f - normalizedDistance; // Simplified fallback
        }

        // Danger zone update
        float sqrDangerRadius = dangerZoneRadius * dangerZoneRadius;
        bool wasInDangerZone = isInDangerZone;
        isInDangerZone = sqrDistance <= sqrDangerRadius;

        if (isInDangerZone != wasInDangerZone)
        {
            if (isInDangerZone)
                OnEnteredDangerZone();
            else
                OnExitedDangerZone();
        }
    }

    private void HandleAutoEmergencyThrust()
    {
        if (!autoEmergencyOnDanger || fuelManager == null) return;

        bool shouldActivate = isInDangerZone && fuelManager.HasFuel &&
                             shipController != null && shipController.IsMoving;

        if (shouldActivate && !emergencyThrustActive)
        {
            ActivateEmergencyThrust();
        }
        else if (!shouldActivate && emergencyThrustActive)
        {
            DeactivateEmergencyThrust();
        }
    }

    public void OnEnterGravityField(BlackHoleCore blackHole)
    {
        currentBlackHole = blackHole;
        zoneManager = blackHole.GetComponent<BlackHoleZoneManager>(); // Cache zone manager
        isInGravityField = true;

        // Reset position cache to force immediate update
        lastDistanceCheck = 0f;
    }

    public void OnExitGravityField(BlackHoleCore blackHole)
    {
        currentBlackHole = null;
        zoneManager = null;
        isInGravityField = false;
        currentGravityIntensity = 0f;

        if (isInDangerZone)
        {
            isInDangerZone = false;
            OnExitedDangerZone();
        }

        DeactivateEmergencyThrust();
    }

    public void OnReachEventHorizon(BlackHoleCore blackHole)
    {
        if (hasBeenConsumed) return;

        hasBeenConsumed = true;

        if (deathManager != null)
        {
            deathManager.TriggerDeath(UnifiedDeathManager.DeathType.BlackHole);
        }
        else
        {
            Debug.LogError($"PlayerGravityHandler - No UnifiedDeathManager found for black hole death on {name}!");
            gameObject.SetActive(false);
        }
    }

    private void OnEnteredDangerZone()
    {
        if (enableDangerZoneEffects)
            gravityMultiplier = baseGravityMultiplier * dangerZoneMultiplier;
    }

    private void OnExitedDangerZone()
    {
        if (enableDangerZoneEffects)
            gravityMultiplier = baseGravityMultiplier;
    }

    public void ActivateEmergencyThrust()
    {
        if (emergencyThrustActive) return;

        emergencyThrustActive = true;
        gravityMultiplier *= emergencyThrustMultiplier;
    }

    public void DeactivateEmergencyThrust()
    {
        if (!emergencyThrustActive) return;

        emergencyThrustActive = false;
        gravityMultiplier /= emergencyThrustMultiplier;
    }

    public void TriggerManualEmergencyThrust(float duration = 2f)
    {
        if (fuelManager == null || !fuelManager.HasFuel) return;

        ActivateEmergencyThrust();
        fuelManager.AddFuel(-emergencyFuelCost);

        // Optimización: Usar Invoke en lugar de corrutina para casos simples
        Invoke(nameof(DeactivateEmergencyThrust), duration);
    }

    public void ResetGravityState()
    {
        hasBeenConsumed = false;
        isInGravityField = false;
        isInDangerZone = false;
        currentGravityIntensity = 0f;
        currentBlackHole = null;
        zoneManager = null;

        DeactivateEmergencyThrust();
        gravityMultiplier = baseGravityMultiplier;

        // Reset cache
        lastDistanceCheck = 0f;
        cachedDistance = float.MaxValue;
    }

    public float GetDistanceToBlackHole()
    {
        if (currentBlackHole == null) return float.MaxValue;

        // Usar distancia cached si está disponible y reciente
        float currentTime = Time.time;
        if (currentTime - lastDistanceCheck < DISTANCE_CHECK_INTERVAL && cachedDistance < float.MaxValue)
        {
            return cachedDistance;
        }

        // Calcular nueva distancia
        cachedDistance = Vector2.Distance(transform.position, currentBlackHole.Position);
        return cachedDistance;
    }

    public bool IsNearEventHorizon(float threshold = 1.5f)
    {
        if (currentBlackHole == null) return false;
        return GetDistanceToBlackHole() <= currentBlackHole.EventHorizonRadius * threshold;
    }

    private void OnEnable()
    {
        if (deathManager != null)
            deathManager.OnRespawn += OnPlayerRespawned;
    }

    private void OnDisable()
    {
        if (deathManager != null)
            deathManager.OnRespawn -= OnPlayerRespawned;
    }

    private void OnPlayerRespawned()
    {
        ResetGravityState();
    }

    private void OnDestroy()
    {
        CancelInvoke(); // Limpiar cualquier Invoke pendiente
    }

#if UNITY_EDITOR
    private void OnValidate()
    {
        gravityMultiplier = Mathf.Max(0.1f, gravityMultiplier);
        emergencyThrustMultiplier = Mathf.Max(1f, emergencyThrustMultiplier);
        dangerZoneMultiplier = Mathf.Max(1f, dangerZoneMultiplier);
        dangerZoneRadius = Mathf.Max(0.5f, dangerZoneRadius);
        emergencyFuelCost = Mathf.Max(0f, emergencyFuelCost);
    }
#endif
}