using UnityEngine;

public class ShieldController : MonoBehaviour
{
    // # Refs principales
    private CombatSystem _combatSystem;
    private Rigidbody2D _shipRb;          // cache (se resuelve JIT para evitar el bug del primer respawn)

    // # Temporizador robusto (FIX variación de duración)
    [Header("Shield Lifetime (Timer)")]
    [Tooltip("Usar tiempo no escalado para la duración del escudo (opcional).")]
    [SerializeField] private bool useUnscaledTime = false; // si tu juego usa timeScale en menú, puedes activarlo
    private float _shieldEndTime = -1f;
    private bool _lifetimeRunning = false;

    // # Black hole repel (config)
    [Header("Black Hole Repel")]
    [Tooltip("Activa la repulsión cuando el escudo toca el collider central del agujero negro (por LayerMask).")]
    [SerializeField] private bool repelBlackHole = true;

    [Tooltip("Layers que identifican el collider central del agujero negro.")]
    [SerializeField] private LayerMask blackHoleCoreLayers;

    [Tooltip("Impulso lineal aplicado a la nave al repeler.")]
    [SerializeField] private float blackHoleImpulse = 45f;

    [Tooltip("Aleatoriedad (grados) aplicada a la dirección de salida.")]
    [SerializeField] private float randomAngle = 20f;

    [Tooltip("Si es true, el escudo se consume al repeler el agujero.")]
    [SerializeField] private bool consumeShieldOnRepel = false;

    [Tooltip("Pequeño cooldown para evitar múltiples impulsos por solapes de colliders.")]
    [SerializeField] private float repelCooldown = 0.15f;

    // # Spin al repeler (config)
    [Header("Spin al repeler")]
    [Tooltip("Aplica un pequeño giro cuando el escudo expulsa la nave del agujero negro.")]
    [SerializeField] private bool addSpinOnRepel = true;

    [Tooltip("Impulso de torque (valores típicos: 8–16).")]
    [SerializeField] private float spinImpulse = 12f;

    [Tooltip("Variación ± en porcentaje sobre el impulso de giro.")]
    [Range(0f, 1f)]
    [SerializeField] private float spinVariance = 0.35f;

    [Tooltip("Si está activo, el signo del spin se elige al azar.")]
    [SerializeField] private bool randomizeSpinSign = true;

    [Tooltip("Limitar la velocidad angular tras aplicar el giro.")]
    [SerializeField] private bool limitAngularVelocity = true;

    [Tooltip("Máximo absoluto de angularVelocity (°/s).")]
    [SerializeField] private float maxAngularSpeed = 240f;

    // # Runtime
    private float _lastRepelTime = -999f;

    // # API pública (ACTIVATE / DEACTIVATE)
    public void ActivateShield(float inTimer, CombatSystem combatSystem)
    {
        Debug.Log("Active shield");
        _combatSystem = combatSystem;

        if (_combatSystem == null)
        {
            Debug.Log("_combatSystem null");
            return;
        }

        // Re-resolver RB al activar (por si es el primer spawn)
        _shipRb = null;
        GetShipRB();

        // Cancelar cualquier temporizador previo (FIX variaciones)
        CancelInvoke();
        _lifetimeRunning = false;
        _shieldEndTime = Now() + Mathf.Max(0f, inTimer);

        gameObject.SetActive(true);
        _combatSystem.IsInvencible = true;

        // Arrancar temporizador robusto
        if (!_lifetimeRunning)
        {
            _lifetimeRunning = true;
            // Usamos UpdateTick en vez de Invoke/Coroutine para no depender del estado activo
            // (cuando se desactiva el GO, OnDisable limpia todo).
        }
    }

    public void DeactivateShield()
    {
        Debug.Log("deActive shield");
        if (_combatSystem == null)
        {
            Debug.Log("_combatSystem null");
            return;
        }

        gameObject.SetActive(false);
        _combatSystem.IsInvencible = false;

        // Limpiar temporizador (FIX: evita “residuos” entre activaciones)
        CancelInvoke();
        _lifetimeRunning = false;
        _shieldEndTime = -1f;

        // Si tu respawn destruye/instancia, evita mantener refs muertas
        _shipRb = null;
    }

    // # Ciclo de vida del temporizador (tick por frame)
    private void Update()
    {
        if (!_lifetimeRunning) return;
        if (_shieldEndTime < 0f) return;

        if (Now() >= _shieldEndTime)
        {
            _lifetimeRunning = false;
            DeactivateShield();
        }
    }

    // # Colisiones
    private void OnTriggerEnter2D(Collider2D collision)
    {
        // — Repulsión de agujero negro (núcleo por LayerMask)
        if (repelBlackHole)
        {
            int bit = 1 << collision.gameObject.layer;
            if ((blackHoleCoreLayers.value & bit) != 0)
            {
                if (Time.time - _lastRepelTime >= repelCooldown)
                {
                    _lastRepelTime = Time.time;

                    var rb = GetShipRB(); // JIT: arregla el fallo del primer respawn

                    Vector2 center = collision.bounds.center;
                    Vector2 outDir = (rb != null ? rb.position : (Vector2)transform.position) - center;
                    if (outDir.sqrMagnitude < 0.0001f) outDir = Vector2.up;
                    outDir.Normalize();

                    // jitter angular para que no salga siempre igual
                    if (randomAngle > 0f)
                    {
                        float jitter = Random.Range(-randomAngle, randomAngle);
                        outDir = (Vector2)(Quaternion.Euler(0f, 0f, jitter) * outDir);
                    }

                    // aplicar impulsos
                    if (rb != null)
                    {
                        rb.AddForce(outDir * blackHoleImpulse, ForceMode2D.Impulse);

                        if (addSpinOnRepel && Mathf.Abs(spinImpulse) > 0f)
                        {
                            float spin = spinImpulse * (1f + Random.Range(-spinVariance, spinVariance));
                            if (randomizeSpinSign && Random.value < 0.5f) spin = -spin;
                            rb.AddTorque(spin, ForceMode2D.Impulse);

                            if (limitAngularVelocity)
                                rb.angularVelocity = Mathf.Clamp(rb.angularVelocity, -maxAngularSpeed, maxAngularSpeed);
                        }
                    }
                    else
                    {
                        // Fallback sin RB (desaconsejado, pero seguro)
                        transform.root.position += (Vector3)(outDir * blackHoleImpulse * 0.02f);
                    }

                    if (consumeShieldOnRepel)
                    {
                        DeactivateShield();
                        return;
                    }
                }
            }
        }

        // — Comportamiento original (conservado)
        bool isArena = collision.gameObject.CompareTag("Arena");
        bool isNave = collision.gameObject.CompareTag("Nave");
        bool isMissil = collision.gameObject.CompareTag("Missil");
        if (isArena || isNave || isMissil)
        {
            DeactivateShield();
        }
    }

    private void OnDisable()
    {
        // Si alguien desactiva el GO desde fuera, asegúrate de limpiar el temporizador
        CancelInvoke();
        _lifetimeRunning = false;
        _shieldEndTime = -1f;
    }

    // # Helpers
    /// <summary>Resuelve (y cachea) el Rigidbody2D de la nave de forma robusta.</summary>
    Rigidbody2D GetShipRB()
    {
        if (_shipRb != null) return _shipRb;

        if (_combatSystem != null)
        {
            _shipRb = _combatSystem.GetComponent<Rigidbody2D>()
                  ?? _combatSystem.GetComponentInParent<Rigidbody2D>()
                  ?? _combatSystem.GetComponentInChildren<Rigidbody2D>();
            if (_shipRb != null) return _shipRb;
        }

        var root = transform.root;
        if (root != null)
        {
            _shipRb = root.GetComponent<Rigidbody2D>()
                  ?? root.GetComponentInChildren<Rigidbody2D>();
        }
        return _shipRb;
    }

    /// <summary>Reloj según configuración (scaled/unscaled).</summary>
    float Now() => useUnscaledTime ? Time.unscaledTime : Time.time;
}


