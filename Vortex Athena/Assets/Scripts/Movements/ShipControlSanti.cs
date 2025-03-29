using UnityEngine;
using UnityEngine.UI;  // Necesario para manejar botones UI

public class ShipControllerSanti : MonoBehaviour
{
    public float fuerzaPropulsion2 = 10f; // Fuerza de empuje
    private Rigidbody2D rb2;

    void Start()
    {
        rb2 = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        // Si el jugador presiona la tecla "1", aplicar propulsión
        if (Input.GetKeyDown(KeyCode.Alpha1))
        {
            Propulsar();
        }
    }

    void Propulsar()
    {
        rb2.AddForce(transform.up * fuerzaPropulsion2, ForceMode2D.Impulse);
    }

    // ✅ Método para el botón de la UI
    public void ActivarPropulsion()
    {
        Propulsar();
    }
}
