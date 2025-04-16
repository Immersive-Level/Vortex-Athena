using UnityEngine;

public enum ColliderType
{
    Front,
    Back
}

public class ShipCollider : MonoBehaviour
{
    public ColliderType type;
    private CombatSystem combatSystem;

    private void OnEnable()
    {
        combatSystem = transform.parent.GetComponent<CombatSystem>();

        if (combatSystem == null)
        {
            Debug.Log("combat systems is null");
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {

        // Recorremos los colliders que queremos ignorar
        foreach (Collider2D ignoreCollider in combatSystem?.CollidersToIgnore)
        {
            // Si el collider actual es igual al collider de la colisión, retornamos sin hacer nada
            if (ignoreCollider == collision.collider)
            {
                return;
            }
        }

        Debug.Log($"collide {collision.gameObject.name}");

        if (collision.gameObject.CompareTag("Nave"))
        {
            if (type == ColliderType.Back)
            {
                combatSystem?.deathHandler.Death();
            }
        }

        Vector2 forceDirection = (collision.transform.position - transform.position).normalized; // Dirección del empujon
        combatSystem?.shipController.PushShip(forceDirection, combatSystem.PushMagnitude);

        combatSystem?.fuelSystem.RemoveFuel(combatSystem.CollideDamageValue);
    }

}
