using Unity.Entities;
using Unity.Mathematics;
using Unity.Transforms;
using Unity.NetCode;
using Unity.Physics;
using Unity.Burst;
using Unity.Physics.Systems;

// Sistema para aplicar la atracción del agujero negro a las entidades afectables
[UpdateInGroup(typeof(FixedStepSimulationSystemGroup))]
[UpdateAfter(typeof(PhysicsSystemGroup))]
public partial struct BlackHoleAttractionSystem : ISystem
{
    [BurstCompile]
    public void OnCreate(ref SystemState state)
    {
        state.RequireForUpdate<BlackHoleComponent>();
    }

    [BurstCompile]
    public void OnUpdate(ref SystemState state)
    {
        if (!SystemAPI.TryGetSingleton<BlackHoleComponent>(out var blackHole) || !blackHole.IsActive)
            return;

        // Obtener la posición del agujero negro (asumiendo que hay un transform asociado)
        if (!SystemAPI.TryGetSingleton<BlackHoleTransform>(out var blackHoleTransform))
            return;

        float3 blackHolePosition = blackHoleTransform.Position;
        float maxDistanceSq = blackHole.MaxEffectDistance * blackHole.MaxEffectDistance;

        // Procesar todas las entidades que pueden ser afectadas por el agujero negro
        foreach (var (transform, physicsVelocity, affectable) in
                 SystemAPI.Query<RefRW<LocalTransform>, RefRW<PhysicsVelocity>, RefRO<AffectedByBlackHoleTag>>())
        {
            float3 objectPosition = transform.ValueRO.Position;
            float3 directionToBlackHole = blackHolePosition - objectPosition;
            float distanceSq = math.lengthsq(directionToBlackHole);

            // Solo afecta objetos dentro del radio máximo de efecto
            if (distanceSq < maxDistanceSq && distanceSq > 0.0001f)
            {
                // Normaliza dirección
                float distance = math.sqrt(distanceSq);
                float3 direction = directionToBlackHole / distance;

                // Calcula fuerza basada en la distancia
                // Usa el exponente de curva para ajustar la caída de la fuerza
                float forceMagnitude = CalculateAttractionForce(blackHole, distance);

                // Aplica fuerza a la velocidad
                float3 force = direction * forceMagnitude * SystemAPI.Time.DeltaTime;
                physicsVelocity.ValueRW.Linear += force;
            }
        }
    }

    [BurstCompile]
    private float CalculateAttractionForce(BlackHoleComponent blackHole, float distance)
    {
        // Evitar división por cero
        if (distance < 0.0001f)
            return blackHole.MaxAttractionForce;

        // Si está dentro del radio, fuerza máxima
        if (distance <= blackHole.Radius)
            return blackHole.MaxAttractionForce;

        // Calcula caída de fuerza basada en distancia y exponente de curva
        float normalizedDistance = math.saturate((blackHole.MaxEffectDistance - distance) /
                                               (blackHole.MaxEffectDistance - blackHole.Radius));

        // Aplica la curva (usa pow para exponente)
        float forceFactor = math.pow(normalizedDistance, blackHole.AttractionCurve);

        return forceFactor * blackHole.MaxAttractionForce;
    }
}

// Componente para la posición del agujero negro
[GhostComponent]
public struct BlackHoleTransform : IComponentData
{
    [GhostField] public float3 Position;
}

// Tag para marcar entidades que pueden ser afectadas por el agujero negro
[GhostComponent]
public struct AffectedByBlackHoleTag : IComponentData { }