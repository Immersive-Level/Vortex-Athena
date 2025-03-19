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
        // Aplicar efectos visuales a los objetos que est�n dentro del horizonte de eventos
        foreach (var gravityAffected in
                 SystemAPI.Query<RefRO<GravityAffectedComponent>>().WithAll<GhostOwnerIsLocal>())
        {
            if (gravityAffected.ValueRO.IsWithinEventHorizon)
            {
                // Aqu� aplicar�amos efectos visuales como distorsi�n, cambio de color, etc.
                // Estos efectos ser�an puramente visuales y no afectar�an la jugabilidad

                // Como ejemplo, podr�amos enviar un evento para que un sistema de part�culas
                // o un shader se active en este objeto
            }
        }
    }
}