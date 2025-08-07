using UnityEngine;

public class CameraFollow : MonoBehaviour
{
    public Transform target;        // arrastra la nave
    public float smoothTime = 0.2f; // suavizado

    Vector3 velocity = Vector3.zero;

    void Update()
    {
        if (target == null) return;

        Vector3 targetPos = target.position;
        targetPos.z = transform.position.z; // mantener z

        transform.position = Vector3.SmoothDamp(
            transform.position,
            targetPos,
            ref velocity,
            smoothTime
        );
    }
}




