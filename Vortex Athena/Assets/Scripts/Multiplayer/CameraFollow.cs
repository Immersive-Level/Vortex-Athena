public class CameraFollow : MonoBehaviour
{
    [Header("Seguimiento")]
    [Tooltip("Etiqueta que tendrá la nave (por defecto: Nave)")]
    public string targetTag = "Nave";   // ← usa exactamente la etiqueta que ya tienes

    public float smoothTime = 0.2f;
    public float searchInterval = 0.5f;

    Transform target;
    Vector3 velocity = Vector3.zero;
    float nextSearchTime;

    void LateUpdate()
    {
        // 1. Buscar diana si aún no la tenemos
        if (target == null)
        {
            if (Time.time >= nextSearchTime)
            {
                GameObject obj = GameObject.FindGameObjectWithTag(targetTag);
                if (obj != null && obj.activeInHierarchy)
                    target = obj.transform;

                nextSearchTime = Time.time + searchInterval;
            }
            return; // nada más que hacer este frame
        }

        // 2. Seguir suavemente
        Vector3 tgt = target.position;
        tgt.z = transform.position.z;

        transform.position = Vector3.SmoothDamp(
            transform.position,
            tgt,
            ref velocity,
            smoothTime
        );
    }
}



