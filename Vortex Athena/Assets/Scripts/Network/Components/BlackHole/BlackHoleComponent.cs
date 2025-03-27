using Unity.Entities;
using Unity.Mathematics;
using Unity.NetCode;

// Singleton para el único agujero negro en la partida
[GhostComponent(PrefabType = GhostPrefabType.AllPredicted)]
public struct BlackHoleComponent : IComponentData
{
    // Radio del agujero negro
    [GhostField] public float Radius;

    // Fuerza de atracción máxima
    [GhostField] public float MaxAttractionForce;

    // Distancia máxima de efecto
    [GhostField] public float MaxEffectDistance;

    // Exponente para la curva de atracción (2 = gravitación normal, mayor = más agresivo)
    [GhostField] public float AttractionCurve;

    // Flag para habilitar/deshabilitar la atracción durante la partida
    [GhostField] public bool IsActive;

    // ID único de la partida actual para sincronización
    [GhostField] public int GameSessionId;
}