using UnityEngine;
using GameSystems;

/// <summary>
/// Gestiona SOLO la inicialización y activación de una nave
/// No maneja estados del botón - eso lo hace ShipInputController
/// </summary>
public class InicioNave : MonoBehaviour
{
    [Header("Configuración de Nave")]
    public GameObject nave;
    public float impulsoInicial = 5f;
    public Vector2 direccionImpulso = new Vector2(1, 1);

    [Header("Configuración Inicial")]
    [Tooltip("Combustible inicial al activar la nave")]
    public float combustibleInicial = 100f;

    [Header("Referencias")]
    [SerializeField] private BlackHoleAttractionManager blackHoleManager;
    [SerializeField] private ShipInputController shipInputController;

    // Estado
    private bool juegoIniciado = false;
    public bool JuegoIniciado => juegoIniciado;

    void Awake()
    {
        // Validar referencias
        if (nave == null)
        {
            Debug.LogError($"[InicioNave] No se asignó la nave en {gameObject.name}");
            enabled = false;
            return;
        }
    }

    void Start()
    {
        if (GameManager.Instance != null)
            GameManager.Instance.RegisterShip(nave);

        // Ocultar la nave al inicio
        nave.SetActive(false);

        // Buscar ShipInputController si no está asignado
        if (shipInputController == null)
        {
            shipInputController = GetComponentInChildren<ShipInputController>();
        }

        // Obtener referencia al BlackHoleAttractionManager si no está asignada
        if (blackHoleManager == null)
        {
            blackHoleManager = BlackHoleAttractionManager.Instance;
            if (blackHoleManager == null)
            {
                Debug.LogWarning("[InicioNave] No se encontró un BlackHoleAttractionManager");
            }
        }
    }

    /// <summary>
    /// Inicia el juego activando la nave con impulso inicial
    /// </summary>
    public void IniciarJuego()
    {
        if (juegoIniciado || nave == null) return;

        juegoIniciado = true;

        // Activar la nave
        nave.SetActive(true);

        // Configurar Rigidbody2D
        Rigidbody2D rb = nave.GetComponent<Rigidbody2D>();
        if (rb != null)
        {
            rb.bodyType = RigidbodyType2D.Dynamic;
            rb.simulated = true;

            // Aplicar impulso inicial
            Vector2 direccionInicial = direccionImpulso.normalized;
            rb.linearVelocity = direccionInicial * impulsoInicial;
        }

        // Configurar sistemas
        ConfigurarSistemas();

        // Notificar al ShipInputController que el juego inició
        if (shipInputController != null)
        {
            shipInputController.OnGameStarted();
        }

        // Registrar en BlackHoleAttractionManager
        RegistrarEnBlackHole();

        Debug.Log($"[InicioNave] Nave {nave.name} iniciada con {combustibleInicial} de combustible");
    }

    /// <summary>
    /// Configura los sistemas de la nave al iniciar
    /// </summary>
    private void ConfigurarSistemas()
    {
        // Configurar combustible
        var fuelManager = nave.GetComponentInChildren<FuelManager>();
        if (fuelManager != null)
        {
            fuelManager.SetFuel(combustibleInicial);
            fuelManager.ResetFuelSystem();
        }

        // Resetear el controlador de la nave
        var shipController = nave.GetComponentInChildren<ShipController>();
        if (shipController != null)
        {
            shipController.ResetMovement();
        }
    }

    /// <summary>
    /// Reinicia el estado de la nave
    /// </summary>
    public void ReiniciarNave()
    {
        if (nave != null)
        {
            // Desregistrar del BlackHole
            DesregistrarDeBlackHole();

            // Resetear todos los sistemas
            var shipController = nave.GetComponentInChildren<ShipController>();
            if (shipController != null)
            {
                shipController.ResetMovement();
            }

            var fuelManager = nave.GetComponentInChildren<FuelManager>();
            if (fuelManager != null)
            {
                fuelManager.ResetFuelSystem();
            }

            if (shipInputController != null)
            {
                shipInputController.ResetInputState();
            }

            // Desactivar nave
            nave.SetActive(false);
            juegoIniciado = false;

            Debug.Log($"[InicioNave] Nave {nave.name} reiniciada");
        }
    }

    private void RegistrarEnBlackHole()
    {
        if (blackHoleManager != null && nave != null)
        {
            AffectedByBlackHole affected = nave.GetComponent<AffectedByBlackHole>();
            if (affected != null)
            {
                blackHoleManager.RegisterAffectableObject(affected);
                Debug.Log($"[InicioNave] Nave {nave.name} registrada en BlackHoleAttractionManager");
            }
        }
    }

    private void DesregistrarDeBlackHole()
    {
        if (blackHoleManager != null && nave != null)
        {
            AffectedByBlackHole affected = nave.GetComponent<AffectedByBlackHole>();
            if (affected != null)
            {
                blackHoleManager.UnregisterAffectableObject(affected);
                Debug.Log($"[InicioNave] Nave {nave.name} desregistrada del BlackHoleAttractionManager");
            }
        }
    }

    void OnDisable()
    {
        DesregistrarDeBlackHole();
    }

    void OnDestroy()
    {
        DesregistrarDeBlackHole();
    }
}