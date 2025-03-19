using Unity.Entities;
using Unity.Mathematics;
using Unity.NetCode;

// Componente para marcar la entidad como agujero negro
[GhostComponent]
public struct BlackHoleComponent : IComponentData
{
    // Radio del agujero negro
    public float Radius;

    // Fuerza de atracción máxima
    public float MaxAttractionForce;

    // Distancia máxima de efecto
    public float MaxEffectDistance;

    // Exponente para la curva de atracción (2 = gravitación normal, mayor = más agresivo)
    public float AttractionCurve;
}