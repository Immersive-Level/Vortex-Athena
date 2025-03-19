using Unity.Burst;
using Unity.Entities;
using Unity.Mathematics;
using Unity.NetCode;
using Unity.Transforms;

// Sistema para efectos visuales del agujero negro (ejecutado en el cliente)
[WorldSystemFilter(WorldSystemFilterFlags.ServerSimulation)]
[BurstCompile]
public partial struct BlackHoleVisualEffectsSystem : ISystem
{
    [BurstCompile]
    public void OnCreate(ref SystemState state)
    {
        state.RequireForUpdate<BlackHoleComponent>();
    }

    [BurstCompile]
    public void OnUpdate(ref SystemState state)
    {
        // Aplicar efectos visuales a los objetos que están dentro del horizonte de eventos
        foreach (var gravityAffected in
                 SystemAPI.Query<RefRO<GravityAffectedComponent>>().WithAll<GhostOwnerIsLocal>())
        {
            if (gravityAffected.ValueRO.IsWithinEventHorizon)
            {
                // Aquí aplicaríamos efectos visuales como distorsión, cambio de color, etc.
                // Estos efectos serían puramente visuales y no afectarían la jugabilidad

                // Como ejemplo, podríamos enviar un evento para que un sistema de partículas
                // o un shader se active en este objeto
            }
        }
    }
}