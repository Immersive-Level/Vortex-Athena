using Unity.Entities;
using Unity.NetCode;

[GhostComponent]
public struct PlayerComponent : IComponentData
{
    public int PlayerId;
}