using UnityEngine;

/// <summary>
/// Gestiona las zonas de influencia - Versión optimizada para producción
/// </summary>
public class BlackHoleZoneManager : MonoBehaviour
{
    private BlackHoleCore blackHole;
    private BlackHoleConfiguration config;

    // Cache para evitar repeated property access
    private Vector2 cachedBlackHolePosition;
    private float cachedEventHorizonRadius;
    private float cachedCurrentInfluenceRadius;
    private bool cacheValid = false;

    public void Initialize(BlackHoleCore core, BlackHoleConfiguration configuration)
    {
        blackHole = core;
        config = configuration;
        InvalidateCache();
    }

    private void InvalidateCache()
    {
        cacheValid = false;
    }

    private void ValidateCache()
    {
        if (!cacheValid)
        {
            cachedBlackHolePosition = blackHole.Position;
            cachedEventHorizonRadius = config.EventHorizonRadius;
            cachedCurrentInfluenceRadius = blackHole.CurrentInfluenceRadius;
            cacheValid = true;
        }
    }

    public float GetZoneIntensity(Vector2 position)
    {
        ValidateCache();

        // Optimización: Usar squared distance para comparaciones iniciales
        Vector2 direction = position - cachedBlackHolePosition;
        float sqrDistance = direction.sqrMagnitude;

        // Event horizon check usando squared distance
        float sqrEventHorizon = cachedEventHorizonRadius * cachedEventHorizonRadius;
        if (sqrDistance <= sqrEventHorizon)
            return 1f;

        // Influence radius check usando squared distance
        float sqrInfluenceRadius = cachedCurrentInfluenceRadius * cachedCurrentInfluenceRadius;
        if (sqrDistance >= sqrInfluenceRadius)
            return 0f;

        // Solo calcular distance real cuando sea necesario
        float distance = Mathf.Sqrt(sqrDistance);
        float normalizedDistance = distance / cachedCurrentInfluenceRadius;

        return config.GravityFalloffCurve.Evaluate(1f - normalizedDistance);
    }

    public bool IsInEventHorizon(Vector2 position)
    {
        ValidateCache();

        // Optimización: Usar squared distance
        Vector2 diff = position - cachedBlackHolePosition;
        float sqrDistance = diff.sqrMagnitude;
        float sqrEventHorizon = cachedEventHorizonRadius * cachedEventHorizonRadius;

        return sqrDistance <= sqrEventHorizon;
    }

    public bool IsInInfluenceZone(Vector2 position)
    {
        ValidateCache();

        // Optimización: Usar squared distance
        Vector2 diff = position - cachedBlackHolePosition;
        float sqrDistance = diff.sqrMagnitude;
        float sqrInfluenceRadius = cachedCurrentInfluenceRadius * cachedCurrentInfluenceRadius;

        return sqrDistance <= sqrInfluenceRadius;
    }

    /// <summary>
    /// Método optimizado que retorna múltiples valores de zona en una sola pasada
    /// Útil cuando se necesita verificar múltiples condiciones
    /// </summary>
    public void GetZoneInfo(Vector2 position, out bool inEventHorizon, out bool inInfluenceZone, out float intensity)
    {
        ValidateCache();

        Vector2 diff = position - cachedBlackHolePosition;
        float sqrDistance = diff.sqrMagnitude;

        // Event horizon check
        float sqrEventHorizon = cachedEventHorizonRadius * cachedEventHorizonRadius;
        inEventHorizon = sqrDistance <= sqrEventHorizon;

        // Influence zone check
        float sqrInfluenceRadius = cachedCurrentInfluenceRadius * cachedCurrentInfluenceRadius;
        inInfluenceZone = sqrDistance <= sqrInfluenceRadius;

        // Intensity calculation
        if (inEventHorizon)
        {
            intensity = 1f;
        }
        else if (!inInfluenceZone)
        {
            intensity = 0f;
        }
        else
        {
            float distance = Mathf.Sqrt(sqrDistance);
            float normalizedDistance = distance / cachedCurrentInfluenceRadius;
            intensity = config.GravityFalloffCurve.Evaluate(1f - normalizedDistance);
        }
    }

    private void LateUpdate()
    {
        // Invalidar cache cada frame para que se actualice en la próxima consulta
        InvalidateCache();
    }

    private void OnDestroy()
    {
        blackHole = null;
        config = null;
    }
}