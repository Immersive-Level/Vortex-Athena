using UnityEngine;
using UnityEngine.Events;

/// <summary>
/// Componente que permite a un objeto ser afectado por la gravedad de los agujeros negros.
/// Requiere un Rigidbody2D para aplicar las fuerzas físicas.
/// </summary>
[RequireComponent(typeof(Rigidbody2D))]
public class AffectedByBlackHole : MonoBehaviour
{
    #region Inspector Properties

    [Header("⚙️ Configuración de Atracción")]
    [Space(10)]

    [Tooltip("Define si este objeto puede ser afectado por agujeros negros")]
    [SerializeField]
    private bool _canBeAffected = true;

    [Tooltip("Factor de resistencia a la atracción (1 = normal, <1 = más atraído, >1 = más resistente)")]
    [SerializeField, Range(0.1f, 5f)]
    private float attractionResistance = 1f;

    [Tooltip("Límite máximo de velocidad causada por agujeros negros")]
    [SerializeField, Range(0f, 100f)]
    private float maxVelocityFromBlackHole = 50f;

    [Header("⚡ Estado")]
    [Space(10)]

    [Tooltip("Indica si el objeto está dentro del horizonte de eventos")]
    [SerializeField, ReadOnly]
    private bool _isWithinEventHorizon = false;

    [Tooltip("Fuerza total siendo aplicada actualmente")]
    [SerializeField, ReadOnly]
    private Vector2 currentAttractionForce = Vector2.zero;

    [Header("🎮 Eventos")]
    [Space(10)]

    [Tooltip("Evento cuando el objeto entra al horizonte de eventos")]
    public UnityEvent onEnterEventHorizon = new UnityEvent();

    [Tooltip("Evento cuando el objeto sale del horizonte de eventos")]
    public UnityEvent onExitEventHorizon = new UnityEvent();

    [Tooltip("Evento cuando el objeto es destruido por un agujero negro")]
    public UnityEvent onDestroyedByBlackHole = new UnityEvent();

    [Header("📊 Debug")]
    [Space(10)]

    [Tooltip("Mostrar información de debug")]
    [SerializeField]
    private bool debugMode = false;

    #endregion

    #region Private Variables

    private Rigidbody2D rb;
    private Vector2 accumulatedForce = Vector2.zero;
    private float timeInEventHorizon = 0f;
    private bool isRegistered = false;

    // Cache para optimización
    private Transform cachedTransform;
    private float lastForceApplicationTime;

    #endregion

    #region Properties

    /// <summary>
    /// Define si este objeto puede ser afectado por agujeros negros
    /// </summary>
    public bool canBeAffected
    {
        get => _canBeAffected;
        set
        {
            _canBeAffected = value;
            if (!_canBeAffected && _isWithinEventHorizon)
            {
                ExitEventHorizon();
            }
        }
    }

    /// <summary>
    /// Indica si el objeto está dentro del horizonte de eventos
    /// </summary>
    public bool isWithinEventHorizon => _isWithinEventHorizon;

    /// <summary>
    /// Obtiene el Rigidbody2D del objeto
    /// </summary>
    public Rigidbody2D Rigidbody => rb;

    /// <summary>
    /// Obtiene la fuerza de atracción actual
    /// </summary>
    public Vector2 CurrentAttractionForce => currentAttractionForce;

    #endregion

    #region Unity Lifecycle

    private void Awake()
    {
        InitializeComponents();
    }

    private void OnEnable()
    {
        RegisterToManager();
    }

    private void OnDisable()
    {
        UnregisterFromManager();

        // Limpiar estado
        if (_isWithinEventHorizon)
        {
            ExitEventHorizon();
        }
    }

    private void FixedUpdate()
    {
        // Aplicar fuerzas acumuladas
        if (accumulatedForce.magnitude > 0.001f)
        {
            ApplyAccumulatedForces();
        }

        // Actualizar tiempo en horizonte de eventos
        if (_isWithinEventHorizon)
        {
            timeInEventHorizon += Time.fixedDeltaTime;
        }

        // Resetear fuerza actual para debug
        currentAttractionForce = Vector2.zero;
    }

    private void OnValidate()
    {
        // Validar configuración en el editor
        if (maxVelocityFromBlackHole <= 0)
        {
            maxVelocityFromBlackHole = 50f;
        }
    }

    #endregion

    #region Initialization

    /// <summary>
    /// Inicializa los componentes necesarios
    /// </summary>
    private void InitializeComponents()
    {
        // Cache del transform
        cachedTransform = transform;

        // Obtener Rigidbody2D
        rb = GetComponent<Rigidbody2D>();
        if (rb == null)
        {
            rb = gameObject.AddComponent<Rigidbody2D>();
            Debug.LogWarning($"[AffectedByBlackHole] Se agregó Rigidbody2D a '{name}' automáticamente");
        }

        // Configuración recomendada para Rigidbody2D
        if (rb.isKinematic)
        {
            Debug.LogWarning($"[AffectedByBlackHole] '{name}' tiene Rigidbody2D kinematic. " +
                           "No podrá ser afectado por fuerzas de agujeros negros.");
            _canBeAffected = false;
        }
    }

    /// <summary>
    /// Registra el objeto en el manager de atracción
    /// </summary>
    private void RegisterToManager()
    {
        if (!isRegistered && BlackHoleAttractionManager.Instance != null)
        {
            BlackHoleAttractionManager.Instance.RegisterAffectableObject(this);
            isRegistered = true;

            if (debugMode)
            {
                Debug.Log($"[AffectedByBlackHole] '{name}' registrado en el manager");
            }
        }
    }

    /// <summary>
    /// Desregistra el objeto del manager de atracción
    /// </summary>
    private void UnregisterFromManager()
    {
        if (isRegistered && BlackHoleAttractionManager.Instance != null)
        {
            BlackHoleAttractionManager.Instance.UnregisterAffectableObject(this);
            isRegistered = false;

            if (debugMode)
            {
                Debug.Log($"[AffectedByBlackHole] '{name}' desregistrado del manager");
            }
        }
    }

    #endregion

    #region Force Application

    /// <summary>
    /// Aplica una fuerza de atracción al objeto
    /// </summary>
    /// <param name="attractionForce">Vector de fuerza a aplicar</param>
    public void ApplyAttractionForce(Vector2 attractionForce)
    {
        if (!_canBeAffected || rb == null || rb.isKinematic)
            return;

        // Aplicar resistencia
        Vector2 adjustedForce = attractionForce / attractionResistance;

        // Acumular fuerza para aplicar en FixedUpdate
        accumulatedForce += adjustedForce;
        currentAttractionForce += adjustedForce;

        // Limitar acumulación excesiva
        float maxForce = maxVelocityFromBlackHole * rb.mass;
        if (accumulatedForce.magnitude > maxForce)
        {
            accumulatedForce = accumulatedForce.normalized * maxForce;
        }

        lastForceApplicationTime = Time.time;

        if (debugMode && attractionForce.magnitude > 0.1f)
        {
            Debug.DrawRay(cachedTransform.position, adjustedForce.normalized * 2f, Color.red, 0.1f);
        }
    }

    /// <summary>
    /// Aplica las fuerzas acumuladas al Rigidbody
    /// </summary>
    private void ApplyAccumulatedForces()
    {
        if (rb == null) return;

        // Aplicar la fuerza
        rb.AddForce(accumulatedForce, ForceMode2D.Force);

        // Limitar velocidad máxima
        if (rb.linearVelocity.magnitude > maxVelocityFromBlackHole)
        {
            rb.linearVelocity = rb.linearVelocity.normalized * maxVelocityFromBlackHole;
        }

        // Resetear acumulador
        accumulatedForce = Vector2.zero;
    }

    #endregion

    #region Event Horizon Management

    /// <summary>
    /// Llamado cuando el objeto entra en el horizonte de eventos
    /// </summary>
    public void EnterEventHorizon()
    {
        if (_isWithinEventHorizon) return;

        _isWithinEventHorizon = true;
        timeInEventHorizon = 0f;

        // Invocar evento
        onEnterEventHorizon?.Invoke();

        if (debugMode)
        {
            Debug.Log($"[AffectedByBlackHole] '{name}' entró al horizonte de eventos");
        }

        // Opcional: Cambiar propiedades físicas dentro del horizonte
        ModifyPhysicsForEventHorizon(true);
    }

    /// <summary>
    /// Llamado cuando el objeto sale del horizonte de eventos
    /// </summary>
    public void ExitEventHorizon()
    {
        if (!_isWithinEventHorizon) return;

        _isWithinEventHorizon = false;
        float totalTimeInHorizon = timeInEventHorizon;
        timeInEventHorizon = 0f;

        // Invocar evento
        onExitEventHorizon?.Invoke();

        if (debugMode)
        {
            Debug.Log($"[AffectedByBlackHole] '{name}' salió del horizonte de eventos " +
                     $"(estuvo {totalTimeInHorizon:F2}s dentro)");
        }

        // Restaurar propiedades físicas
        ModifyPhysicsForEventHorizon(false);
    }

    /// <summary>
    /// Modifica las propiedades físicas cuando entra/sale del horizonte
    /// </summary>
    private void ModifyPhysicsForEventHorizon(bool isEntering)
    {
        if (rb == null) return;

        if (isEntering)
        {
            // Reducir drag para simular caída libre
            rb.linearDamping *= 0.5f;
            rb.angularDamping *= 0.5f;
        }
        else
        {
            // Restaurar valores normales (asumiendo valores por defecto)
            rb.linearDamping = 0f;
            rb.angularDamping = 0.05f;
        }
    }

    #endregion

    #region Black Hole Absorption

    /// <summary>
    /// Llamado cuando el objeto es absorbido por un agujero negro
    /// </summary>
    public void AbsorbedByBlackHole()
    {
        if (debugMode)
        {
            Debug.Log($"[AffectedByBlackHole] '{name}' fue absorbido por un agujero negro");
        }

        // Invocar evento de destrucción
        onDestroyedByBlackHole?.Invoke();

        // Desregistrar antes de destruir
        UnregisterFromManager();

        // Destruir o desactivar el objeto
        // Nota: Podrías cambiar esto para usar un pool de objetos
        gameObject.SetActive(false);
    }

    #endregion

    #region Utility Methods

    /// <summary>
    /// Resetea todas las fuerzas aplicadas
    /// </summary>
    public void ResetForces()
    {
        accumulatedForce = Vector2.zero;
        currentAttractionForce = Vector2.zero;

        if (rb != null)
        {
            rb.linearVelocity = Vector2.zero;
            rb.angularVelocity = 0f;
        }
    }

    /// <summary>
    /// Obtiene información de debug del estado actual
    /// </summary>
    public string GetDebugInfo()
    {
        return $"Object: {name}\n" +
               $"Can Be Affected: {_canBeAffected}\n" +
               $"In Event Horizon: {_isWithinEventHorizon}\n" +
               $"Current Force: {currentAttractionForce.magnitude:F2}\n" +
               $"Velocity: {(rb != null ? rb.linearVelocity.magnitude : 0f):F2}\n" +
               $"Time in Horizon: {timeInEventHorizon:F2}s";
    }

    #endregion

    #region Custom Attributes

    /// <summary>
    /// Atributo para mostrar campos como solo lectura en el inspector
    /// </summary>
    public class ReadOnlyAttribute : PropertyAttribute { }

    #endregion
}