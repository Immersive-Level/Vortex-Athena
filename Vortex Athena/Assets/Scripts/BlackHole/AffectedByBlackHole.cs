using UnityEngine;

public class AffectedByBlackHole : MonoBehaviour
{
    [Tooltip("Factor de resistencia a la atracción (1 = normal, <1 = más resistente, >1 = menos resistente)")]
    [Range(0.1f, 5f)]
    public float attractionResistance = 1f;

    [Tooltip("Define si este objeto puede ser afectado por agujeros negros")]
    public bool canBeAffected = true;

    [Tooltip("Se activa cuando el objeto está dentro del horizonte de eventos")]
    public bool isWithinEventHorizon = false;

    // Opcionalmente agregar eventos o acciones que ocurren cuando entra al horizonte de eventos
    public System.Action onEnterEventHorizon;
    public System.Action onExitEventHorizon;

    // Referencia al componente Rigidbody2D
    private Rigidbody2D rb;

    private void Awake()
    {
        // Obtener el componente Rigidbody2D
        rb = GetComponent<Rigidbody2D>();

        // Verificar que haya un Rigidbody2D
        if (rb == null)
        {
            Debug.LogWarning("El objeto " + gameObject.name + " no tiene Rigidbody2D. No podrá ser afectado por agujeros negros.");
            canBeAffected = false;
        }
    }

    // Función para ser llamada cuando el objeto entra en el horizonte de eventos
    public void EnterEventHorizon()
    {
        if (!isWithinEventHorizon)
        {
            isWithinEventHorizon = true;
            onEnterEventHorizon?.Invoke();
        }
    }

    // Función para ser llamada cuando el objeto sale del horizonte de eventos
    public void ExitEventHorizon()
    {
        if (isWithinEventHorizon)
        {
            isWithinEventHorizon = false;
            onExitEventHorizon?.Invoke();
        }
    }

    // Método para aplicar la fuerza de atracción
    public void ApplyAttractionForce(Vector2 attractionForce)
    {
        if (canBeAffected && rb != null)
        {
            // Aplicar la fuerza modificada por la resistencia
            rb.AddForce(attractionForce / attractionResistance);
        }
    }
}