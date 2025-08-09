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

    //[Header("Asistente de Giro (opcional)")]
    //public bool asistenteGiro = true;          // activar/desactivar fácilmente
    //public bool soloCercaAgujeroNegro = true;  // si true, solo actúa cerca del centro
    //public float radioAsistente = 7f;          // radio desde el centro (0,0) donde se activa
    //public float fuerzaAsistente = 10f;         // cuánta torsión aplica
    //public float pesoVelocidad = 0.1f;         // 0..1, cuánto seguir la dirección de la velocidad
    //public float umbralVelocidad = 0.5f;       // mínimo para considerar dirección de velocidad
    //public float anguloMuerto = 3f;            // grados; evita vibración al mantener
    //public float limiteVelAng = 150f;          // clamp de angularVelocity



    // === Tap Nudge (empujón con toque corto) ===
    [Header("Tap Nudge")]
    public bool tapNudgeEnabled = true;          // activar/desactivar
    public float nudgeTorqueImpulse = 0.4f;      // fuerza del impulso (torque) por toque
    public float nudgeMaxAngle = 45f;            // escalado: a mayor desalineación, más impulso
    public float nudgeCooldown = 0.15f;          // anti-spam entre nudges

    private float _nextNudgeTime = 0f;

    public void TapNudge()
    {
        if (!tapNudgeEnabled) return;
        if (Time.time < _nextNudgeTime) return;

        // Requiere info de velocidad para saber hacia dónde corregir
        Vector2 v = rb.linearVelocity;
        if (v.sqrMagnitude < 0.001f) return; // si estás casi parado, no hay dirección a la cual alinear

        Vector2 forward = transform.up;
        float angDelta = Vector2.SignedAngle(forward, v); // grados (-180..180)

        // Impulso proporcional: si estás muy desalineado, empuja más (hasta nudgeMaxAngle)
        float sign = Mathf.Sign(angDelta);
        float strength = Mathf.Clamp01(Mathf.Abs(angDelta) / nudgeMaxAngle);

        float impulse = -sign * nudgeTorqueImpulse * strength; // signo contrario al error angular
        rb.AddTorque(impulse, ForceMode2D.Impulse);

        _nextNudgeTime = Time.time + nudgeCooldown;
    }




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

        //// --- ASISTENTE DE GIRO SUAVE ---
        //if (asistenteGiro && isMoving)
        //{
        //    // Si solo debe actuar cerca del agujero negro, comprobamos el radio
        //    float distanciaAlCentro = Vector2.Distance(transform.position, centroMapa);
        //    if (!soloCercaAgujeroNegro || distanciaAlCentro <= radioAsistente)
        //    {
        //        Vector2 forward = transform.up;
        //        Vector2 desiredDir = forward;

        //        // 1) Mezcla hacia la dirección de la velocidad para “limpiar” derrape
        //        if (rb.linearVelocity.magnitude > umbralVelocidad)
        //        {
        //            Vector2 velDir = rb.linearVelocity.normalized;
        //            desiredDir = Vector2.Lerp(forward, velDir, pesoVelocidad).normalized;
        //        }

        //        // 2) Si hay borde delante, empujamos desiredDir hacia adentro (normal del borde)
        //        RaycastHit2D hit = Physics2D.Raycast(transform.position, forward, distanciaBorde, LayerMask.GetMask("Borde"));
        //        if (hit.collider != null)
        //        {
        //            Vector2 awayFromWall = hit.normal;
        //            desiredDir = Vector2.Lerp(desiredDir, awayFromWall, 0.6f).normalized;
        //        }

        //        // 3) Calcula ángulo a corregir y aplica torque con dead-zone
        //        float angDelta = Vector2.SignedAngle(forward, desiredDir); // (-180..180)
        //        if (Mathf.Abs(angDelta) > anguloMuerto)
        //        {
        //            float torque = -angDelta * fuerzaAsistente * Mathf.Deg2Rad; // proporcional
        //            rb.AddTorque(torque, ForceMode2D.Force);

        //            // 4) Limita velocidad angular para evitar oscilaciones
        //            rb.angularVelocity = Mathf.Clamp(rb.angularVelocity, -limiteVelAng, limiteVelAng);
        //        }
        //    }
        //}

        //// Calcular distancia al centro y aplicar giro progresivo
        //float distanciaAlCentro = Vector2.Distance(transform.position, centroMapa);
        //if (isMoving && distanciaAlCentro < distanciaMaxGiro)
        //{
        //    float factorGiro = (distanciaMaxGiro - distanciaAlCentro) / distanciaMaxGiro;
        //    float anguloGiro = factorGiro * intensidadGiro * direccionGiro;
        //    transform.Rotate(Vector3.forward, anguloGiro);
        //}

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