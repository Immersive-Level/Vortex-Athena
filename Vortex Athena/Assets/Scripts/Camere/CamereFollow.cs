using UnityEngine;

public class CamereFollow : MonoBehaviour
{
    public Transform objetivo; // La nave a seguir
    public float suavizado = 5f; // Velocidad de seguimiento
    public Vector3 offset; // Ajuste de posici�n (por defecto, 0 si no quieres modificar)

    void LateUpdate()
    {
        if (objetivo != null)
        {
            // Interpola la posici�n de la c�mara hacia la nave con suavizado
            Vector3 posicionDeseada = objetivo.position + offset;
            transform.position = Vector3.Lerp(transform.position, posicionDeseada, suavizado * Time.deltaTime);
        }
    }
}
