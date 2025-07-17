using UnityEngine;

[CreateAssetMenu(menuName = "Abilities/Speed Boost")]
public class MisileAbility : AbilityData
{
    public bool followTarget;
    public GameObject MissilPrefab;

    public override void Activate(GameObject owner)
    {
        Debug.Log("spawn misil at: " + owner.transform.position);

        GameObject missile = Instantiate(MissilPrefab, owner.transform.position, owner.transform.rotation);
        MissileController controller = missile.GetComponent<MissileController>();

        controller.shouldFollowTarget = followTarget;
        controller.Launch(owner); // 👈 Ignora al invocador
    }
}