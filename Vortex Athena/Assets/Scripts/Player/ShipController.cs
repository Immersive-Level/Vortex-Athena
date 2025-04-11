using UnityEngine;

public class ShipController : MonoBehaviour
{

    [Header("Propiedades de Movimiento")]
    [Tooltip("La velocidad base con la que la nave va a moverse")]
    public float velocidad = 5f;

    [Tooltip("Distancia en la que la nave empieza a girar para alejarse")]
    public float distanciaMaxGiro = 5f; // Distancia en la que la nave empieza a girar para alejarse

    [Tooltip("Intensidad con la que gira al acercarse")]
    public float intensidadGiro = 2f; // Intensidad con la que gira al acercarse

    [Tooltip("Factor de estabilización cuando hay colisiones")]
    public float estabilidadRotacion = 3f; // Factor de estabilización cuando hay colisiones

    [Tooltip("Distancia para empezar a girar cerca del borde (Radio indicador visual color rojo)")]
    public float distanciaBorde = 2f; // Distancia para empezar a girar cerca del borde

    [Tooltip("Límite de ángulo de giro al evitar el borde")]
    public float maxAnguloBorde = 20f; // Límite de ángulo de giro al evitar el borde

    [Header("Referencia GameObject")]
    [Tooltip("Referencia del GameObject que contiene el script de la gasolina")]
    public Boton consumeFuel;

    [Header("Controles")]
    [Tooltip("Tecla para activar el movimiento de la nave")]
    public KeyCode teclaMovimiento = KeyCode.Alpha1;

    private Rigidbody2D rb;
    private bool isMoving = false;
    private Vector2 centroMapa = Vector2.zero; // Se asume que el centro del mapa es (0,0)
    private int direccionGiro = 1; // Dirección del giro (1 o -1)

    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        // Comprobamos si la tecla está siendo presionada
        if (Input.GetKeyDown(teclaMovimiento))
        {
            StartMoving();
            consumeFuel.OnPress();
        }
        else if (Input.GetKeyUp(teclaMovimiento))
        {
            StopMoving();
            consumeFuel.OnRelease();
        }
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
            float factorGiro = (distanciaMaxGiro - distanciaAlCentro) / distanciaMaxGiro; // Se vuelve más fuerte cerca del centro
            float anguloGiro = factorGiro * intensidadGiro * direccionGiro;
            transform.Rotate(Vector3.forward, anguloGiro);
        }

        // Evitar el borde del mapa
        EvitarBorde();

        // Estabilizador automático para evitar giros descontrolados
        rb.angularVelocity *= 1f - (estabilidadRotacion * Time.fixedDeltaTime);
    }

    void EvitarBorde()
    {
        RaycastHit2D hit = Physics2D.Raycast(transform.position, transform.up, distanciaBorde, LayerMask.GetMask("Borde"));

        if (hit.collider != null)
        {
            // Debug.Log("¡Borde detectado con Raycast!");

            float factorGiroBorde = Mathf.Clamp01((distanciaBorde - hit.distance) / distanciaBorde);
            float anguloBorde = factorGiroBorde * maxAnguloBorde * direccionGiro;
            transform.Rotate(Vector3.forward, anguloBorde);
        }
    }

    public void StartMoving()
    {
        isMoving = true;
        direccionGiro = (Random.value < 0.5f) ? -1 : 1; // Asignar una dirección de giro al iniciar el movimiento
    }

    public void StopMoving()
    {
        isMoving = false;
    }

    void OnDrawGizmos()
    {
        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(transform.position, distanciaBorde);
    }
}
