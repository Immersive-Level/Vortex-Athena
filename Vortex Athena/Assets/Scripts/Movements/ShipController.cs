using UnityEngine;

public class ShipController : MonoBehaviour
{

    public float velocidad = 5f;
    public float fuerzaPropulsion = 10f;
    public float velocidadRotacion = 100f;
    public float rangoDeteccionY = 2f; // Distancia en la que empieza a girar
    public float fuerzaGiro = 30f; // Intensidad del giro autom�tico

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
        //if (isMoving)
        //{
          //  rb.AddForce(transform.up * velocidad);
        //}

        // Propulsi�n extra
        if (Input.GetKey(KeyCode.F))
        {
            rb.AddForce(transform.up * fuerzaPropulsion);
        }

        // Verificar si est� cerca de un punto Y y determinar la direcci�n de giro
        DetectarPuntoYGiro();
    }

    void FixedUpdate()
    {
        // Aplicar movimiento normal si el jugador presion� el bot�n en pantalla
        if (isMoving)
        {
            rb.AddForce(transform.up * velocidad, ForceMode2D.Force);
        }

        // Aplicar el giro de forma gradual
        if (girando)
        {
            rb.rotation += direccionGiro * velocidadRotacion * Time.fixedDeltaTime;
        }
    }

    void DetectarPuntoYGiro()
    {
        float puntoY = Mathf.Round(transform.position.y / 10) * 10; // Redondear a m�ltiplos de 10
        float distanciaY = Mathf.Abs(transform.position.y - puntoY);

        if (distanciaY < rangoDeteccionY)
        {
            girando = true;

            // Si la nave est� a la izquierda del punto, girar a la derecha
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
