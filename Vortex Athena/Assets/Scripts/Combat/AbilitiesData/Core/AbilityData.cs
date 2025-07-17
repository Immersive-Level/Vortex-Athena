using UnityEngine;

public abstract class AbilityData : ScriptableObject, IAbility
{
    public string abilityName;
    public string description;
    public Sprite icon;

    public abstract void Activate(GameObject owner);
}
