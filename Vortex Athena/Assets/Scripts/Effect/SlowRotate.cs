using UnityEngine;

/// <summary>Gira el objeto a un ritmo constante (grados por segundo).</summary>
public class SlowRotate : MonoBehaviour
{
    [Tooltip("Velocidad de rotación (grados/segundo)")]
    public float degreesPerSecond = 1f;   // ~1°/s = 360° en 6 min

    void Update()
    {
        transform.Rotate(0f, 0f, degreesPerSecond * Time.deltaTime);
    }
}
