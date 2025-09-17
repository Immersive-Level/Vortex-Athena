using UnityEngine;

/// <summary>
/// Configuración centralizada para el comportamiento del agujero negro
/// Versión optimizada para producción
/// </summary>
[CreateAssetMenu(fileName = "BlackHoleConfig", menuName = "GameSystems/BlackHole Configuration")]
public class BlackHoleConfiguration : ScriptableObject
{
    [Header("Size Behavior")]
    [SerializeField] private bool useConstantSize = false;
    [SerializeField, Tooltip("Solo se usa cuando 'Use Constant Size' está activado")]
    private float constantIntensityValue = 1f;

    [Header("Gravitational Physics")]
    [SerializeField] private float baseGravityStrength = 500f;
    [SerializeField] private float maxGravityStrength = 2000f;
    [SerializeField] private AnimationCurve gravityFalloffCurve = AnimationCurve.Linear(0, 1, 1, 0);
    [SerializeField] private AnimationCurve intensityOverTime = AnimationCurve.Linear(0, 1, 1, 2);

    [Header("Zone Configuration")]
    [SerializeField] private float eventHorizonRadius = 2f;
    [SerializeField] private float influenceRadius = 20f;
    [SerializeField] private float maxInfluenceRadius = 35f;

    [Header("Performance")]
    [SerializeField] private int maxAffectedObjects = 50;
    [SerializeField] private float updateFrequency = 0.02f;

    // Propiedades públicas (readonly para evitar modificaciones accidentales)
    public bool UseConstantSize => useConstantSize;
    public float ConstantIntensityValue => constantIntensityValue;
    public float BaseGravityStrength => baseGravityStrength;
    public float MaxGravityStrength => maxGravityStrength;
    public AnimationCurve GravityFalloffCurve => gravityFalloffCurve;
    public AnimationCurve IntensityOverTime => intensityOverTime;
    public float EventHorizonRadius => eventHorizonRadius;
    public float InfluenceRadius => influenceRadius;
    public float MaxInfluenceRadius => maxInfluenceRadius;
    public int MaxAffectedObjects => maxAffectedObjects;
    public float UpdateFrequency => updateFrequency;

    // Valores calculados en cache para evitar recálculos
    private float _cachedEventHorizonSqr = -1f;
    private float _cachedInfluenceRadiusSqr = -1f;
    private float _cachedMaxInfluenceRadiusSqr = -1f;

    public float EventHorizonRadiusSqr
    {
        get
        {
            if (_cachedEventHorizonSqr < 0f)
                _cachedEventHorizonSqr = eventHorizonRadius * eventHorizonRadius;
            return _cachedEventHorizonSqr;
        }
    }

    public float InfluenceRadiusSqr
    {
        get
        {
            if (_cachedInfluenceRadiusSqr < 0f)
                _cachedInfluenceRadiusSqr = influenceRadius * influenceRadius;
            return _cachedInfluenceRadiusSqr;
        }
    }

    public float MaxInfluenceRadiusSqr
    {
        get
        {
            if (_cachedMaxInfluenceRadiusSqr < 0f)
                _cachedMaxInfluenceRadiusSqr = maxInfluenceRadius * maxInfluenceRadius;
            return _cachedMaxInfluenceRadiusSqr;
        }
    }

    private void OnValidate()
    {
        // Limpiar cache cuando se modifican valores
        _cachedEventHorizonSqr = -1f;
        _cachedInfluenceRadiusSqr = -1f;
        _cachedMaxInfluenceRadiusSqr = -1f;

        // Validar rangos
        constantIntensityValue = Mathf.Max(1f, constantIntensityValue);
        baseGravityStrength = Mathf.Max(0f, baseGravityStrength);
        maxGravityStrength = Mathf.Max(baseGravityStrength, maxGravityStrength);
        eventHorizonRadius = Mathf.Max(0.1f, eventHorizonRadius);
        influenceRadius = Mathf.Max(eventHorizonRadius + 0.1f, influenceRadius);
        maxInfluenceRadius = Mathf.Max(influenceRadius, maxInfluenceRadius);
        updateFrequency = Mathf.Clamp(updateFrequency, 0.01f, 0.1f);
        maxAffectedObjects = Mathf.Clamp(maxAffectedObjects, 1, 100);

        // Validar curvas
        if (gravityFalloffCurve == null || gravityFalloffCurve.length == 0)
            gravityFalloffCurve = AnimationCurve.Linear(0, 1, 1, 0);

        if (intensityOverTime == null || intensityOverTime.length == 0)
            intensityOverTime = AnimationCurve.Linear(0, 1, 1, 2);
    }
}