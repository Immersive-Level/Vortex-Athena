using UnityEngine;

public class ShieldController : MonoBehaviour
{
    private CombatSystem _combatSystem;
    public void ActivateShield(float inTimer, CombatSystem combatSystem)
    {
        Debug.Log("Active shield");
        _combatSystem = combatSystem;

        if (_combatSystem == null)
        {
            Debug.Log("_combatSystem null");
            return;
        }

        gameObject.SetActive(true);
        _combatSystem.IsInvencible = true;

        Invoke(nameof(DeactivateShield), inTimer);
    }

    public void DeactivateShield()
    {
        Debug.Log("deActive shield");
        if (_combatSystem == null)
        {
            Debug.Log("_combatSystem null");
            return;
        }

        gameObject.SetActive(false);
        _combatSystem.IsInvencible = false;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        bool isArena = collision.gameObject.CompareTag("Arena");
        bool isNave = collision.gameObject.CompareTag("Nave");
        bool isMissil = collision.gameObject.CompareTag("Missil");
        if (isArena || isNave || isMissil)
        {
            DeactivateShield();
        }
    }

}
