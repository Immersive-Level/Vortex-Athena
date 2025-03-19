using Unity.Entities;
using Unity.Mathematics;
using Unity.NetCode;

// Componente para marcar la entidad como agujero negro
[GhostComponent]
public struct BlackHoleComponent : IComponentData
{
    // Radio del agujero negro
    public float Radius;

    // Fuerza de atracci�n m�xima
    public float MaxAttractionForce;

    // Distancia m�xima de efecto
    public float MaxEffectDistance;

    // Exponente para la curva de atracci�n (2 = gravitaci�n normal, mayor = m�s agresivo)
    public float AttractionCurve;
}