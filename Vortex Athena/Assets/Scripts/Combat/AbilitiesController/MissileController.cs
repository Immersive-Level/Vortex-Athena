using UnityEngine;

public class MissileController : MonoBehaviour
{
    [Header("Movimiento")]
    public float speed = 10f;
    public float turnSpeed = 5f;
    public float waveFrequency = 2f;
    public float waveAmplitude = 0.5f;

    [Header("Targeting")]
    public float searchRadius = 50f;
    public bool shouldFollowTarget = true;
    private GameObject OwnerObject;

    [Header("Debug")]
    public Transform target;
    private Vector3 launchDirection;
    private float lifeTimer;
    private float lifetime = 10f;

    public void Launch(GameObject owner)
    {
        Debug.Log("Launch misil");
        OwnerObject = owner;
        launchDirection = transform.up;
        FindInitialTarget();
    }

    void Update()
    {
        lifeTimer += Time.deltaTime;
        if (lifeTimer > lifetime)
        {
            Destroy(gameObject);
            return;
        }

        Vector3 moveDir = launchDirection;

        if (shouldFollowTarget && target)
        {
            Vector3 dirToTarget = (target.position - transform.position).normalized;
            launchDirection = Vector3.Slerp(launchDirection, dirToTarget, turnSpeed * Time.deltaTime);
        }

        // Movimiento serpenteante
        Vector3 waveOffset = transform.right * Mathf.Sin(Time.time * waveFrequency) * waveAmplitude;
        Vector3 finalDirection = (launchDirection + waveOffset).normalized;

        transform.position += finalDirection * speed * Time.deltaTime;

        // Rotación en plano 2D(Z)
        float angle = Mathf.Atan2(finalDirection.y, finalDirection.x) * Mathf.Rad2Deg;
        transform.rotation = Quaternion.Euler(0f, 0f, angle - 90f);

        // Debug visual de la dirección del misil
        Debug.DrawRay(transform.position, finalDirection * 2f, Color.red);
    }

    void FindInitialTarget()
    {
        if (GameManager.Instance == null || GameManager.Instance.NavesActivas == null || GameManager.Instance.NavesActivas.Count == 0)
        {
            Debug.LogWarning("Misil target NOT found: lista vacía o GameManager ausente");
            shouldFollowTarget = false;
            return;
        }

        float closestDistance = Mathf.Infinity;
        Transform bestTarget = null;

        foreach (GameObject nave in GameManager.Instance.NavesActivas)
        {
            if (nave == null || nave == OwnerObject) continue; // Evita comparar con sí mismo

            float distance = Vector3.Distance(transform.position, nave.transform.position);
            Vector3 directionTo = (nave.transform.position - transform.position).normalized;
            float forwardDot = Vector3.Dot(transform.up, directionTo); // En 2D usamos transform.up como dirección "forward"

            if (forwardDot > 0.5f && distance < closestDistance)
            {
                closestDistance = distance;
                bestTarget = nave.transform;
            }
        }

        if (bestTarget)
        {
            Debug.Log("Misil target found: " + bestTarget.name);
            target = bestTarget;
        }
        else
        {
            Debug.Log("Misil target NOT found: disparando hacia adelante");
            shouldFollowTarget = false;
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        Debug.Log("Missil collide wit: " + collision.gameObject.name);
        if (collision.gameObject.CompareTag("Nave"))
        {
            GameObject otherShip = collision.gameObject.transform.parent.gameObject;
            if (otherShip != OwnerObject)
            {
                Debug.Log($"Misil hit player {otherShip.name}");
                PlayerScoreSystem otherScore = otherShip.GetComponent<PlayerScoreSystem>();
                otherScore?.AddScore(inKills: 1);//le añade una kill al jugador

                CombatSystem otherCombatSystem = otherScore.GetComponent<CombatSystem>();
                otherCombatSystem?.Kill();
                Debug.Log("Misil hit destroy");
                Destroy(gameObject);
            }
        }

        if (collision.gameObject.CompareTag("Arena"))
        {
            Debug.Log("Misil hit destroy");
            Destroy(gameObject);
        }
    }
}