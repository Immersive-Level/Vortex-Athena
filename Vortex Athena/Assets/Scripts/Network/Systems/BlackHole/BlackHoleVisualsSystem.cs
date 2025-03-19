using Unity.Entities;
using Unity.NetCode;
using UnityEngine;

[UpdateInGroup(typeof(PresentationSystemGroup))]
public partial class BlackHoleVisualsSystem : SystemBase
{
    protected override void OnUpdate()
    {
        // Encuentra todos los controladores de shader de agujero negro
        var controllers = Object.FindObjectsOfType<BlackHoleShaderController>();

        if (controllers.Length == 0) return;

        // Para cada agujero negro en el sistema ECS
        foreach (var (blackHoleTransform, blackHole) in
                 SystemAPI.Query<RefRO<Unity.Transforms.LocalTransform>, RefRO<BlackHoleComponent>>())
        {
            // Obtiene la fuerza máxima del agujero negro
            float maxForce = blackHole.ValueRO.MaxAttractionForce;

            // Normaliza la fuerza para efectos visuales (0-1)
            float normalizedForce = maxForce / 30.0f; // Ajusta según sea necesario

            // Aplica el efecto a todos los controladores visuales
            foreach (var controller in controllers)
            {
                controller.ReactToGravityStrength(normalizedForce);
            }
        }
    }
}