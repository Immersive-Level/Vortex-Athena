using Unity.Entities;
using Unity.Mathematics;
using Unity.NetCode;

// Componente para objetos afectados por la gravedad
[GhostComponent]
public struct GravityAffectedComponent : IComponentData
{
    // Factor de resistencia a la gravedad (1 = normal, <1 = m�s resistente, >1 = menos resistente)
    public float GravityResistanceFactor;

    // Indica si el objeto est� dentro del horizonte de eventos (para efectos especiales)
    [GhostField]
    public bool IsWithinEventHorizon;
}
