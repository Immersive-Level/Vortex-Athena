using UnityEngine;

[CreateAssetMenu(menuName = "Abilities/Shield Ability")]
public class ShieldAbility : AbilityData
{
    public float duration = 5f;

    public override void Activate(GameObject owner)
    {
        Debug.Log("Activate shield");
        if (owner.TryGetComponent<CombatSystem>(out var combatSystem))
        {
            combatSystem.Shield.ActivateShield(duration, combatSystem);
        }
        else
        {
            Debug.Log("[Shield] Combat system is null");
        }
    }
}