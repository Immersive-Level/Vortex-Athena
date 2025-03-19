using Unity.Entities;
using Unity.NetCode;

[GhostComponent]
public struct GameplayStateComponent : IComponentData
{
    public bool ShouldSpawnBlackHole;
    public bool BlackHoleActive;
    public float BlackHoleSpawnTimer;
}
