using NUnit.Compatibility;
using UnityEngine;

public enum ColliderType
{
    Front,
    Back
}

public class ShipCollider : MonoBehaviour
{
    [Header("Tipo de Collider")]
    public ColliderType type;

    [Header("Efecto de Colisi�n")]
    public GameObject collisionEffectPrefab;  // Prefab de animaci�n de colisi�n

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
        if (collision.gameObject.CompareTag("Resource")) return;
        foreach (Collider2D ignoreCollider in combatSystem?.CollidersToIgnore)
        {
            // Si el collider actual es igual al collider de la colisi�n, retornamos sin hacer nada
            if (ignoreCollider == collision.collider)
            {
                return;
            }
        }


        if (collision.gameObject.CompareTag("Nave"))
        {
            // Punto de contacto de la colisi�n
            ContactPoint2D contact = collision.GetContact(0);

            // Instanciar el prefab de animaci�n en el punto de impacto
            if (collisionEffectPrefab != null)
            {
                Instantiate(
                    collisionEffectPrefab,
                    contact.point,
                    Quaternion.identity
                );
            }

            Debug.Log("Collide with player" + collision.gameObject.name + " _ " + type);
            if (type == ColliderType.Back)
            {
                PlayerScoreSystem otherScore = collision.gameObject.GetComponent<PlayerScoreSystem>();
                otherScore?.AddScore(inKills: 1); // le a�ade una kill al oponente

                combatSystem?.deathHandler.Death();
            }
        }


        //////Empujon
        //Vector2 forceDirection = (collision.transform.position - transform.position).normalized; // Direcci�n del empujon
        //combatSystem?.shipController.PushShip(forceDirection, combatSystem.PushMagnitude);
        combatSystem?.shipController.SlowShip(combatSystem.SlowMagnitude);
        combatSystem?.fuelSystem.RemoveFuel(combatSystem.CollideDamageValue);

        if (collision.gameObject.CompareTag("Nave"))
        {
            Debug.Log("Collide with player" + collision.gameObject.name + " _ " + type);
            if (type == ColliderType.Back && !combatSystem.IsInvencible)
            {
                PlayerScoreSystem otherScore = collision.gameObject.GetComponent<PlayerScoreSystem>();
                otherScore?.AddScore(inKills: 1);//le a�ade una kill al oponente

                combatSystem?.Kill();
            }
        }
    }
}
