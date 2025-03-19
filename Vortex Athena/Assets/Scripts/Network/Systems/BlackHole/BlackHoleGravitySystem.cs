using Unity.Burst;
using Unity.Entities;
using Unity.Mathematics;
using Unity.NetCode;
using Unity.Transforms;
using Unity.Physics;

// Sistema para calcular la física del agujero negro (ejecutado en el servidor)
[WorldSystemFilter(WorldSystemFilterFlags.ServerSimulation)]
[BurstCompile]
public partial struct BlackHoleGravitySystem : ISystem
{
    [BurstCompile]
    public void OnCreate(ref SystemState state)
    {
        state.RequireForUpdate<BlackHoleComponent>();
    }

    [BurstCompile]
    public void OnUpdate(ref SystemState state)
    {
        var deltaTime = SystemAPI.Time.DeltaTime;

        // Query para encontrar todos los agujeros negros
        foreach (var (blackHoleTransform, blackHole) in
                 SystemAPI.Query<RefRO<LocalTransform>, RefRO<BlackHoleComponent>>())
        {
            var blackHolePosition = blackHoleTransform.ValueRO.Position;
            var maxDistance = blackHole.ValueRO.MaxEffectDistance;
            var maxDistanceSq = maxDistance * maxDistance;
            var radius = blackHole.ValueRO.Radius;
            var attractionCurve = blackHole.ValueRO.AttractionCurve;
            var maxForce = blackHole.ValueRO.MaxAttractionForce;

            // Query para encontrar todos los objetos afectables por gravedad
            foreach (var (transform, velocity, gravityAffected) in
                     SystemAPI.Query<RefRW<LocalTransform>, RefRW<PhysicsVelocity>, RefRW<GravityAffectedComponent>>())
            {
                var objectPosition = transform.ValueRO.Position;

                // Vector desde el objeto al agujero negro
                var toBlackHole = blackHolePosition - objectPosition;
                var distanceSq = math.lengthsq(toBlackHole);

                // Verificar si está dentro del rango de efecto
                if (distanceSq <= maxDistanceSq)
                {
                    var distance = math.sqrt(distanceSq);

                    // Establecer si está dentro del horizonte de eventos
                    gravityAffected.ValueRW.IsWithinEventHorizon = distance <= radius * 1.5f;

                    // Calcular factor de atracción basado en la distancia
                    var normalizedDistance = math.saturate(distance / maxDistance);
                    var attractionFactor = 1.0f - math.pow(normalizedDistance, attractionCurve);

                    // Calcular dirección de atracción
                    var direction = math.normalizesafe(toBlackHole);

                    // Aplicar fuerza considerando la resistencia del objeto
                    var appliedForce = direction * maxForce * attractionFactor / gravityAffected.ValueRO.GravityResistanceFactor;

                    // Aplicar la fuerza a la velocidad del objeto
                    velocity.ValueRW.Linear += appliedForce * deltaTime;
                }
            }
        }
    }
}
