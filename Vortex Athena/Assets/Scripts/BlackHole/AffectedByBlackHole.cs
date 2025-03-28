using UnityEngine;

public class AffectedByBlackHole : MonoBehaviour
{
    [Tooltip("Factor de resistencia a la atracci�n (1 = normal, <1 = m�s resistente, >1 = menos resistente)")]
    [Range(0.1f, 5f)]
    public float attractionResistance = 1f;

    [Tooltip("Define si este objeto puede ser afectado por agujeros negros")]
    public bool canBeAffected = true;

    [Tooltip("Se activa cuando el objeto est� dentro del horizonte de eventos")]
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
            Debug.LogWarning("El objeto " + gameObject.name + " no tiene Rigidbody2D. No podr� ser afectado por agujeros negros.");
            canBeAffected = false;
        }
    }

    // Funci�n para ser llamada cuando el objeto entra en el horizonte de eventos
    public void EnterEventHorizon()
    {
        if (!isWithinEventHorizon)
        {
            isWithinEventHorizon = true;
            onEnterEventHorizon?.Invoke();
        }
    }

    // Funci�n para ser llamada cuando el objeto sale del horizonte de eventos
    public void ExitEventHorizon()
    {
        if (isWithinEventHorizon)
        {
            isWithinEventHorizon = false;
            onExitEventHorizon?.Invoke();
        }
    }

    // M�todo para aplicar la fuerza de atracci�n
    public void ApplyAttractionForce(Vector2 attractionForce)
    {
        if (canBeAffected && rb != null)
        {
            // Aplicar la fuerza modificada por la resistencia
            rb.AddForce(attractionForce / attractionResistance);
        }
    }
}