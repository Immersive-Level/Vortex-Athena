using System;

/// <summary>
/// Sistema de eventos centralizado para comunicación desacoplada
/// </summary>
public static class BlackHoleEvents
{
    public static event Action<IGravityAffected> ObjectEnteredField;
    public static event Action<IGravityAffected> ObjectExitedField;
    public static event Action<IGravityAffected> ObjectConsumed;
    public static event Action<float> GravityIntensityChanged;
    public static event Action<float> InfluenceRadiusChanged;

    public static void TriggerObjectEnteredField(IGravityAffected obj) => ObjectEnteredField?.Invoke(obj);
    public static void TriggerObjectExitedField(IGravityAffected obj) => ObjectExitedField?.Invoke(obj);
    public static void TriggerObjectConsumed(IGravityAffected obj) => ObjectConsumed?.Invoke(obj);
    public static void TriggerGravityIntensityChanged(float intensity) => GravityIntensityChanged?.Invoke(intensity);
    public static void TriggerInfluenceRadiusChanged(float radius) => InfluenceRadiusChanged?.Invoke(radius);
}