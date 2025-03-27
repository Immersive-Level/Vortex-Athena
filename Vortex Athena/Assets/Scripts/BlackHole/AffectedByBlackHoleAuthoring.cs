// Authoring para marcar entidades que pueden ser afectadas por el agujero negro
using Unity.Entities;
using UnityEngine;

public class AffectedByBlackHoleAuthoring : MonoBehaviour
{
    class AffectedByBlackHoleBaker : Baker<AffectedByBlackHoleAuthoring>
    {
        public override void Bake(AffectedByBlackHoleAuthoring authoring)
        {
            var entity = GetEntity(TransformUsageFlags.Dynamic);
            AddComponent<AffectedByBlackHoleTag>(entity);
        }
    }
}