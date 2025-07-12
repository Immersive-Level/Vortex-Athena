using UnityEngine;

[CreateAssetMenu(menuName = "Abilities/Shield Ability")]
public class ShieldAbility : AbilityData
{
    public float boostAmount = 10f;
    public float duration = 2f;

    public override void Activate(GameObject owner)
    {
        Debug.Log($"Activando boost de velocidad para {owner.name}");
        // Aplica velocidad, puedes acceder al Rigidbody, controlador, etc.
    }
}