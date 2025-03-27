using Unity.Entities;
using Unity.Mathematics;
using Unity.NetCode;

// Singleton para el �nico agujero negro en la partida
[GhostComponent(PrefabType = GhostPrefabType.AllPredicted)]
public struct BlackHoleComponent : IComponentData
{
    // Radio del agujero negro
    [GhostField] public float Radius;

    // Fuerza de atracci�n m�xima
    [GhostField] public float MaxAttractionForce;

    // Distancia m�xima de efecto
    [GhostField] public float MaxEffectDistance;

    // Exponente para la curva de atracci�n (2 = gravitaci�n normal, mayor = m�s agresivo)
    [GhostField] public float AttractionCurve;

    // Flag para habilitar/deshabilitar la atracci�n durante la partida
    [GhostField] public bool IsActive;

    // ID �nico de la partida actual para sincronizaci�n
    [GhostField] public int GameSessionId;
}