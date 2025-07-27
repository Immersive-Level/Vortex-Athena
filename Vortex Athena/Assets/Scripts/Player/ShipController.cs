using System.Collections;
using UnityEngine;

/// <summary>
/// Controlador de la nave - Solo maneja física y movimiento
/// No gestiona inputs ni inicialización
/// </summary>
public class ShipController : MonoBehaviour
{
    [Header("Propiedades de Movimiento")]
    [Tooltip("La velocidad base con la que la nave va a moverse")]
    public float velocidad = 5f;

    [Tooltip("Distancia en la que la nave empieza a girar para alejarse")]
    public float distanciaMaxGiro = 5f;

    [Tooltip("Intensidad con la que gira al acercarse")]
    public float intensidadGiro = 2f;

    [Tooltip("Factor de estabilización cuando hay colisiones")]
    public float estabilidadRotacion = 3f;

    [Tooltip("Distancia para empezar a girar cerca del borde")]
    public float distanciaBorde = 2f;

    [Tooltip("Límite de ángulo de giro al evitar el borde")]
    public float maxAnguloBorde = 20f;

    [Header("Debug")]
    [Tooltip("Mostrar mensajes de debug")]
    public bool debugMode = false;

    [Header("Efecto de propulsión")]
    public GameObject thrusterFX;   // ← arrastrar aquí el objeto PropulsionFX

    // Estado interno
    private Rigidbody2D rb;
    private bool isMoving = false;
    private bool hasEffect = false;
    private Vector2 centroMapa = Vector2.zero;
    private int direccionGiro = 1;

    // Propiedades públicas de solo lectura
    public bool IsMoving => isMoving;
    public bool HasEffect => hasEffect;

    void Awake()
    {
        rb = GetComponent<Rigidbody2D>();

        if (rb == null)
        {
            Debug.LogError($"[ShipController] No se encontró Rigidbody2D en {gameObject.name}");
            enabled = false;
        }
    }

    void Start()
    {
        if (debugMode)
        {
            Debug.Log($"[ShipController] Inicializado en {gameObject.name}");
        }
    }

    void FixedUpdate()
    {
        if (!rb) return;

        // Movimiento hacia adelante
        if (isMoving)
        {
            rb.AddForce(transform.up * velocidad);
        }

        // Calcular distancia al centro y aplicar giro progresivo
        float distanciaAlCentro = Vector2.Distance(transform.position, centroMapa);
        if (isMoving && distanciaAlCentro < distanciaMaxGiro)
        {
            float factorGiro = (distanciaMaxGiro - distanciaAlCentro) / distanciaMaxGiro;
            float anguloGiro = factorGiro * intensidadGiro * direccionGiro;
            transform.Rotate(Vector3.forward, anguloGiro);
        }

        // Evitar el borde del mapa
        EvitarBorde();

        // Estabilizador automático
        rb.angularVelocity *= 1f - (estabilidadRotacion * Time.fixedDeltaTime);
    }

    void EvitarBorde()
    {
        RaycastHit2D hit = Physics2D.Raycast(transform.position, transform.up, distanciaBorde, LayerMask.GetMask("Borde"));

        if (hit.collider != null)
        {
            float factorGiroBorde = Mathf.Clamp01((distanciaBorde - hit.distance) / distanciaBorde);
            float anguloBorde = factorGiroBorde * maxAnguloBorde * direccionGiro;
            transform.Rotate(Vector3.forward, anguloBorde);
        }
    }

    /// <summary>
    /// Inicia el movimiento de la nave
    /// </summary>
    public void StartMoving()
    {
        if (!enabled || !rb) return;

        isMoving = true;
        direccionGiro = (Random.value < 0.5f) ? -1 : 1;

        if (thrusterFX != null)
            thrusterFX.SetActive(true);   // enciende la llama

        //if (debugMode)
        //    Debug.Log($"[ShipController] Movimiento iniciado en {gameObject.name}");
    }

    /// <summary>
    /// Detiene el movimiento de la nave
    /// </summary>
    public void StopMoving()
    {
        isMoving = false;

        if (thrusterFX != null)
            thrusterFX.SetActive(false);  // apaga la llama

        //if (debugMode)
        //    Debug.Log($"[ShipController] Movimiento detenido en {gameObject.name}");
    }

    /// <summary>
    /// Reinicia completamente el estado de movimiento
    /// </summary>
    public void ResetMovement()
    {
        if (rb != null)
        {
            rb.linearVelocity = Vector2.zero;
            rb.angularVelocity = 0f;
        }
        isMoving = false;
        StopAllCoroutines();
        hasEffect = false;
    }

    /// <summary>
    /// Aplica un efecto de ralentización temporal
    /// </summary>
    public void SlowShip(float inSlowMagnitude, float inSlowTime = 1f)
    {
        if (hasEffect || !enabled) return;
        StartCoroutine(SlowTimer(inSlowMagnitude, inSlowTime));
    }

    private IEnumerator SlowTimer(float inSlowMagnitude, float inSlowTime)
    {
        hasEffect = true;
        float saveVelocity = velocidad;
        float slowPercentage = Mathf.Clamp01(inSlowMagnitude / 100f);
        float slowVelocity = velocidad * slowPercentage;
        velocidad -= slowVelocity;

        if (debugMode)
        {
            Debug.Log($"[ShipController] {gameObject.name} ralentizado: {saveVelocity} -> {velocidad} por {inSlowTime}s");
        }

        yield return new WaitForSeconds(inSlowTime);

        velocidad = saveVelocity;
        hasEffect = false;

        if (debugMode)
        {
            Debug.Log($"[ShipController] {gameObject.name} velocidad restaurada");
        }
    }

    /// <summary>
    /// Aplica una fuerza de empuje instantánea
    /// </summary>
    public void PushShip(Vector2 inForceDirection, float inForceMagnitude)
    {
        if (rb == null || !enabled) return;

        rb.AddForce(inForceDirection * inForceMagnitude, ForceMode2D.Impulse);

        if (debugMode)
        {
            Vector2 start = transform.position;
            Debug.DrawRay(start, inForceDirection * inForceMagnitude, Color.red, 2.0f);
            Debug.Log($"[ShipController] Empuje aplicado: dirección {inForceDirection}, magnitud {inForceMagnitude}");
        }
    }

    /// <summary>
    /// Configura el centro del mapa para cálculos de giro
    /// </summary>
    public void SetMapCenter(Vector2 center)
    {
        centroMapa = center;
    }

    void OnDrawGizmos()
    {
        Gizmos.color = Color.red;
        Gizmos.DrawWireSphere(transform.position, distanciaBorde);
    }

    void OnDestroy()
    {
        StopAllCoroutines();
    }
}