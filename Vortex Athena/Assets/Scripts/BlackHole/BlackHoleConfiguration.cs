using UnityEngine;

/// <summary>
/// Configuración centralizada para el comportamiento del agujero negro
/// </summary>
[CreateAssetMenu(fileName = "BlackHoleConfig", menuName = "GameSystems/BlackHole Configuration")]
public class BlackHoleConfiguration : ScriptableObject
{
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

    public float BaseGravityStrength => baseGravityStrength;
    public float MaxGravityStrength => maxGravityStrength;
    public AnimationCurve GravityFalloffCurve => gravityFalloffCurve;
    public AnimationCurve IntensityOverTime => intensityOverTime;
    public float EventHorizonRadius => eventHorizonRadius;
    public float InfluenceRadius => influenceRadius;
    public float MaxInfluenceRadius => maxInfluenceRadius;
    public int MaxAffectedObjects => maxAffectedObjects;
    public float UpdateFrequency => updateFrequency;
}