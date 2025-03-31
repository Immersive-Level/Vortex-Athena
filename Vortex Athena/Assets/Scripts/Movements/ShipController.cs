using UnityEngine;

public class ShipController : MonoBehaviour
{

    [Header("Propiedades de Movimiento")]
    [Tooltip("La velocidad base con la que la nave va a moverse")]
    public float velocidad = 5f;

    [Tooltip("La fuera que tendra la nave cuando presione la tecla 'F' ")]
    public float fuerzaPropulsion = 10f;

    [Tooltip("La velocidad con la que la nave va a girar")]
    public float velocidadRotacion = 100f;

    [Tooltip("En que distancia empiea a girar la nave con respecto al colider")]
    public float rangoDeteccionY = 2f; // Distancia en la que empieza a girar

    [Tooltip("La intensidad con la que la nave va a girar")]
    public float fuerzaGiro = 30f; // Intensidad del giro automático

    private Rigidbody2D rb;
    private bool girando = false;
    private float direccionGiro = 0f;
    private bool isMoving = false;

    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        // Movimiento hacia adelante
        if (isMoving)
        {
            rb.AddForce(transform.up * velocidad);
        }

        // Propulsión extra
        if (Input.GetKey(KeyCode.F))
        {
            rb.AddForce(transform.up * fuerzaPropulsion);
        }

        // Verificar si está cerca de un punto Y y determinar la dirección de giro
        DetectarPuntoYGiro();
    }

    void FixedUpdate()
    {
        // Aplicar el giro de forma gradual
        if (girando)
        {
            rb.rotation += direccionGiro * velocidadRotacion * Time.fixedDeltaTime;
        }
    }

    void DetectarPuntoYGiro()
    {
        float puntoY = Mathf.Round(transform.position.y / 10) * 10; // Redondear a múltiplos de 10
        float distanciaY = Mathf.Abs(transform.position.y - puntoY);

        if (distanciaY < rangoDeteccionY)
        {
            girando = true;

            // Si la nave está a la izquierda del punto, girar a la derecha
            if (transform.position.x < 0)
                direccionGiro = 1f;
            else
                direccionGiro = -1f;
        }
        else
        {
            girando = false;
        }
    }
    public void StartMoving()
    {
        isMoving = true;
    }

    public void StopMoving()
    {
        isMoving = false;
    }
}
