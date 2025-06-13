using System.Collections;
using Unity.VisualScripting;
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
    private bool hasEffect;
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
    public void ResetMovemnt()
    {
        rb.linearVelocity = Vector2.zero;
        rb.angularVelocity = 0f;
    }

    /// <summary>
    ///  reduce la velocidad de la nave por un tiempo determinado
    /// </summary>
    /// <param name="inSlowMagnitude">porcentaje de reducion de vel (0% - 100%)</param>
    /// <param name="inSlowTime">Tiempo en segundos del slow</param>
    public void SlowShip(float inSlowMagnitude, float inSlowTime = 1)
    {
        if (hasEffect) return;

        StartCoroutine(SlowTimer(inSlowMagnitude, inSlowTime));
    }

    private IEnumerator SlowTimer(float inSlowMagnitude, float inSlowTime)
    {
        hasEffect = true;
        float saveVelocity = velocidad;
        float slowVelocity = (inSlowMagnitude * inSlowMagnitude) / 100;
        velocidad -= slowVelocity;

        //Debug.Log($"Ship: {gameObject.name} slow: {saveVelocity} -> {slowVelocity} : {velocidad} for {inSlowTime}");

        yield return new WaitForSeconds(inSlowTime);

        //Debug.Log($"Ship: {gameObject.name} slow end.");

        velocidad = saveVelocity;
    }

    public void PushShip(Vector2 inForceDirection, float inForceMagnitude)
    {
        // Aplicamos la fuerza
        rb.AddForce(inForceDirection * inForceMagnitude, ForceMode2D.Impulse);

        // Calculamos los puntos inicial y final del rayo
        Vector2 start = transform.position; // Punto inicial del rayo (posición actual de la nave)
        Vector2 end = start + inForceDirection * inForceMagnitude; // Punto final del rayo

        // Dibujamos el rayo
        Debug.DrawRay(start, inForceDirection * inForceMagnitude, Color.red, 2.0f); // Rayo principal

        Debug.DrawLine(end, end + Vector2.one * 0.1f, Color.blue, 2.0f); // Marcador en el final (azul)

        Debug.Log($"Rayo dibujado desde {start} hasta {end} en dirección {inForceDirection}");
    }

    void OnDrawGizmos()
    {
        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(transform.position, distanciaBorde);
    }

    private void OnDestroy()
    {
        StopAllCoroutines();
    }
}
