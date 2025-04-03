using UnityEngine;

public class ShipController : MonoBehaviour
{

    [Header("Propiedades de Movimiento")]
    [Tooltip("La velocidad base con la que la nave va a moverse")]
    public float velocidad = 5f;

    [Tooltip("Distancia en la que la nave empieza a girar para alejarse")]
    public float distanciaMaxGiro = 3f; // Distancia en la que la nave empieza a girar para alejarse

    [Tooltip("Intensidad con la que gira al acercarse")]
    public float intensidadGiro = 2f; // Intensidad con la que gira al acercarse

    [Tooltip("Factor de estabilizaci�n cuando hay colisiones")]
    public float estabilidadRotacion = 5f; // Factor de estabilizaci�n cuando hay colisiones

    private Rigidbody2D rb;
    private bool isMoving = false;
    private Vector2 centroMapa = Vector2.zero; // Se asume que el centro del mapa es (0,0)
    private int direccionGiro = 1; // Direcci�n del giro (1 o -1)

    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        
    }

    void FixedUpdate()
    {// Movimiento hacia adelante
        if (isMoving)
        {
            rb.AddForce(transform.up * velocidad);

        }
        // Calcular distancia al centro y aplicar giro progresivo cuando la nave se acerca
        float distanciaAlCentro = Vector2.Distance(transform.position, centroMapa);
        if (isMoving && distanciaAlCentro < distanciaMaxGiro)
        {
            float factorGiro = (distanciaMaxGiro - distanciaAlCentro) / distanciaMaxGiro; // Se vuelve m�s fuerte cerca del centro
            float anguloGiro = factorGiro * intensidadGiro * direccionGiro;
            transform.Rotate(Vector3.forward, anguloGiro);
        }
        // Estabilizador autom�tico para evitar giros descontrolados
        rb.angularVelocity *= 1f - (estabilidadRotacion * Time.fixedDeltaTime);
    }
    public void StartMoving()
    {
        isMoving = true;
        direccionGiro = (Random.value < 0.5f) ? -1 : 1; // Asignar una direcci�n de giro al iniciar el movimiento
    }

    public void StopMoving()
    {
        isMoving = false;
    }
}
