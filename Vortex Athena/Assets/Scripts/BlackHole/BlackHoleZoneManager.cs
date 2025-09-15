using UnityEngine;

/// <summary>
/// Gestiona las zonas de influencia y cálculos de intensidad espacial
/// </summary>
public class BlackHoleZoneManager : MonoBehaviour
{
    private BlackHoleCore blackHole;
    private BlackHoleConfiguration config;

    public void Initialize(BlackHoleCore core, BlackHoleConfiguration configuration)
    {
        blackHole = core;
        config = configuration;
    }

    public float GetZoneIntensity(Vector2 position)
    {
        float distance = Vector2.Distance(position, blackHole.Position);

        if (distance <= config.EventHorizonRadius)
            return 1f;

        if (distance >= blackHole.CurrentInfluenceRadius)
            return 0f;

        float normalizedDistance = distance / blackHole.CurrentInfluenceRadius;
        return config.GravityFalloffCurve.Evaluate(1f - normalizedDistance);
    }

    public bool IsInEventHorizon(Vector2 position)
    {
        return Vector2.Distance(position, blackHole.Position) <= config.EventHorizonRadius;
    }

    public bool IsInInfluenceZone(Vector2 position)
    {
        return Vector2.Distance(position, blackHole.Position) <= blackHole.CurrentInfluenceRadius;
    }
}