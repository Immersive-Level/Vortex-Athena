using UnityEngine;
using GameSystems;

/// <summary>
/// Maneja la interacción del jugador con el agujero negro
/// Integra con UnifiedDeathManager, FuelManager y ShipController
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

    [Header("Runtime State")]
    [SerializeField, ReadOnly] private bool isInGravityField = false;
    [SerializeField, ReadOnly] private bool isInDangerZone = false;
    [SerializeField, ReadOnly] private float currentGravityIntensity = 0f;
    [SerializeField, ReadOnly] private bool emergencyThrustActive = false;

    private Rigidbody2D rigidBody;
    private ShipController shipController;
    private FuelManager fuelManager;
    private UnifiedDeathManager deathManager;
    private PlayerMain playerMain;

    private BlackHoleCore currentBlackHole;
    private float baseGravityMultiplier;
    private bool hasBeenConsumed = false;

    public Transform Transform => transform;
    public Rigidbody2D Rigidbody => rigidBody;
    public float GravityMultiplier => gravityMultiplier;
    public bool IsActive => gameObject.activeInHierarchy && !hasBeenConsumed &&
                           (deathManager == null || !deathManager.IsDead);

    public bool IsInGravityField => isInGravityField;
    public bool IsInDangerZone => isInDangerZone;
    public float CurrentGravityIntensity => currentGravityIntensity;
    public bool EmergencyThrustActive => emergencyThrustActive;

    private void Awake()
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
        playerMain = GetComponentInParent<PlayerMain>();

        baseGravityMultiplier = gravityMultiplier;
    }

    private void Update()
    {
        if (!isInGravityField || currentBlackHole == null) return;

        UpdateGravityInfo();
        HandleAutoEmergencyThrust();
    }

    private void UpdateGravityInfo()
    {
        var zoneManager = currentBlackHole.GetComponent<BlackHoleZoneManager>();
        if (zoneManager != null)
        {
            currentGravityIntensity = zoneManager.GetZoneIntensity(transform.position);

            float distanceToCenter = Vector2.Distance(transform.position, currentBlackHole.Position);
            bool wasInDangerZone = isInDangerZone;
            isInDangerZone = distanceToCenter <= dangerZoneRadius;

            if (isInDangerZone && !wasInDangerZone)
            {
                OnEnteredDangerZone();
            }
            else if (!isInDangerZone && wasInDangerZone)
            {
                OnExitedDangerZone();
            }
        }
    }

    private void HandleAutoEmergencyThrust()
    {
        if (!autoEmergencyOnDanger || fuelManager == null) return;

        bool shouldActivateEmergency = isInDangerZone && fuelManager.HasFuel && shipController.IsMoving;

        if (shouldActivateEmergency && !emergencyThrustActive)
        {
            ActivateEmergencyThrust();
        }
        else if (!shouldActivateEmergency && emergencyThrustActive)
        {
            DeactivateEmergencyThrust();
        }
    }

    public void OnEnterGravityField(BlackHoleCore blackHole)
    {
        currentBlackHole = blackHole;
        isInGravityField = true;
        OnGravityFieldEntered();
    }

    public void OnExitGravityField(BlackHoleCore blackHole)
    {
        currentBlackHole = null;
        isInGravityField = false;
        currentGravityIntensity = 0f;

        if (isInDangerZone)
        {
            isInDangerZone = false;
            OnExitedDangerZone();
        }

        DeactivateEmergencyThrust();
        OnGravityFieldExited();
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

    private void OnGravityFieldEntered() { }
    private void OnGravityFieldExited() { }

    private void OnEnteredDangerZone()
    {
        if (!enableDangerZoneEffects) return;
        gravityMultiplier = baseGravityMultiplier * dangerZoneMultiplier;
    }

    private void OnExitedDangerZone()
    {
        if (!enableDangerZoneEffects) return;
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
        Invoke(nameof(DeactivateEmergencyThrust), duration);
    }

    public void ResetGravityState()
    {
        hasBeenConsumed = false;
        isInGravityField = false;
        isInDangerZone = false;
        currentGravityIntensity = 0f;
        currentBlackHole = null;

        DeactivateEmergencyThrust();
        gravityMultiplier = baseGravityMultiplier;
    }

    public float GetDistanceToBlackHole()
    {
        if (currentBlackHole == null) return float.MaxValue;
        return Vector2.Distance(transform.position, currentBlackHole.Position);
    }

    public bool IsNearEventHorizon(float threshold = 1.5f)
    {
        if (currentBlackHole == null) return false;
        return GetDistanceToBlackHole() <= currentBlackHole.EventHorizonRadius * threshold;
    }

    private void OnEnable()
    {
        if (deathManager != null)
        {
            deathManager.OnRespawn += OnPlayerRespawned;
        }
    }

    private void OnDisable()
    {
        if (deathManager != null)
        {
            deathManager.OnRespawn -= OnPlayerRespawned;
        }
    }

    private void OnPlayerRespawned()
    {
        ResetGravityState();
    }

    private void OnDestroy()
    {
        CancelInvoke();
    }
}