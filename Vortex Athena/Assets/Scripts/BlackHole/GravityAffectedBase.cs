using UnityEngine;

/// <summary>
/// Clase base para objetos afectados por gravedad - maneja comportamientos comunes
/// </summary>
[RequireComponent(typeof(Rigidbody2D))]
public abstract class GravityAffectedBase : MonoBehaviour, IGravityAffected
{
    [Header("Gravity Settings")]
    [SerializeField] protected float gravityMultiplier = 1f;
    [SerializeField] protected bool isImmuneToEventHorizon = false;

    [Header("Runtime State")]
    [SerializeField, ReadOnly] protected bool isInGravityField = false;
    [SerializeField, ReadOnly] protected float currentGravityIntensity = 0f;

    protected Rigidbody2D rigidBody;
    protected BlackHoleCore currentBlackHole;

    public Transform Transform => transform;
    public Rigidbody2D Rigidbody => rigidBody;
    public float GravityMultiplier => gravityMultiplier;
    public virtual bool IsActive => gameObject.activeInHierarchy && enabled;

    public bool IsInGravityField => isInGravityField;
    public float CurrentGravityIntensity => currentGravityIntensity;

    protected virtual void Awake()
    {
        rigidBody = GetComponent<Rigidbody2D>();
        if (rigidBody == null)
        {
            Debug.LogError($"GravityAffected {name} requires Rigidbody2D!", this);
            enabled = false;
        }
    }

    public virtual void OnEnterGravityField(BlackHoleCore blackHole)
    {
        currentBlackHole = blackHole;
        isInGravityField = true;
        OnGravityFieldEntered(blackHole);
    }

    public virtual void OnExitGravityField(BlackHoleCore blackHole)
    {
        currentBlackHole = null;
        isInGravityField = false;
        currentGravityIntensity = 0f;
        OnGravityFieldExited(blackHole);
    }

    public virtual void OnReachEventHorizon(BlackHoleCore blackHole)
    {
        if (isImmuneToEventHorizon)
        {
            OnEventHorizonImmunity(blackHole);
            return;
        }

        OnConsumedByBlackHole(blackHole);
    }

    protected virtual void Update()
    {
        if (isInGravityField && currentBlackHole != null)
        {
            UpdateGravityIntensity();
        }
    }

    private void UpdateGravityIntensity()
    {
        var zoneManager = currentBlackHole.GetComponent<BlackHoleZoneManager>();
        if (zoneManager != null)
        {
            currentGravityIntensity = zoneManager.GetZoneIntensity(transform.position);
        }
    }

    protected virtual void OnGravityFieldEntered(BlackHoleCore blackHole) { }
    protected virtual void OnGravityFieldExited(BlackHoleCore blackHole) { }
    protected virtual void OnConsumedByBlackHole(BlackHoleCore blackHole) { }
    protected virtual void OnEventHorizonImmunity(BlackHoleCore blackHole) { }

    public void SetGravityMultiplier(float multiplier)
    {
        gravityMultiplier = Mathf.Max(0f, multiplier);
    }

    public void SetEventHorizonImmunity(bool immunity)
    {
        isImmuneToEventHorizon = immunity;
    }
}