using UnityEngine;
using GameSystems;
using UnityEngine.UI;

/// <summary>
/// Gestiona la inicialización y activación de una nave
/// FIXED: El botón NUNCA se oculta, solo cambia su función
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

    [Header("Referencias UI")]
    [Tooltip("El botón de control de esta nave - NUNCA SE OCULTA")]
    public GameObject botonControl;

    [Header("Referencias Sistemas")]
    [SerializeField] private BlackHoleAttractionManager blackHoleManager;
    [SerializeField] private FuelManager fuelManager;
    [SerializeField] private ShipInputController shipInputController;
    [SerializeField] private UnifiedDeathManager deathManager;
    [SerializeField] private ShipController shipController;

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

        // Auto-buscar componentes si no están asignados
        ValidateAndFindComponents();
    }

    void Start()
    {
        if (GameManager.Instance != null)
            GameManager.Instance.RegisterShip(nave);

        // Configurar estado inicial
        ConfigurarEstadoInicial();

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
    /// Valida y busca componentes automáticamente
    /// </summary>
    private void ValidateAndFindComponents()
    {
        // Buscar FuelManager
        if (fuelManager == null && nave != null)
        {
            fuelManager = nave.GetComponent<FuelManager>();
            if (fuelManager == null)
                fuelManager = nave.GetComponentInChildren<FuelManager>();
        }

        // Buscar ShipInputController (puede estar en el botón)
        if (shipInputController == null)
        {
            if (botonControl != null)
            {
                shipInputController = botonControl.GetComponent<ShipInputController>();
            }
            if (shipInputController == null && nave != null)
            {
                shipInputController = nave.GetComponentInChildren<ShipInputController>();
            }
        }

        // Buscar UnifiedDeathManager
        if (deathManager == null && nave != null)
        {
            deathManager = nave.GetComponent<UnifiedDeathManager>();
            if (deathManager == null)
                deathManager = nave.GetComponentInChildren<UnifiedDeathManager>();
        }

        // Buscar ShipController
        if (shipController == null && nave != null)
        {
            shipController = nave.GetComponent<ShipController>();
            if (shipController == null)
                shipController = nave.GetComponentInChildren<ShipController>();
        }
    }

    /// <summary>
    /// Configura el estado inicial de la nave y UI
    /// </summary>
    private void ConfigurarEstadoInicial()
    {
        // Ocultar la nave al inicio
        nave.SetActive(false);

        // IMPORTANTE: El botón SIEMPRE está activo
        if (botonControl != null)
        {
            // El botón NUNCA se desactiva, siempre visible
            botonControl.SetActive(true);

            // Solo cambiar su interactividad
            var canvasGroup = botonControl.GetComponent<CanvasGroup>();
            if (canvasGroup == null)
            {
                canvasGroup = botonControl.AddComponent<CanvasGroup>();
            }

            // Al inicio, el botón está semi-transparente esperando activación
            canvasGroup.alpha = 0.5f;
            canvasGroup.interactable = false;
            canvasGroup.blocksRaycasts = true; // Siempre puede recibir clicks
        }

        // Configurar combustible inicial
        if (fuelManager != null)
        {
            fuelManager.SetFuel(combustibleInicial);
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

        // Habilitar el botón para control
        SetBotonModoJuego();

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
        if (fuelManager != null)
        {
            fuelManager.SetFuel(combustibleInicial);
            fuelManager.ResetFuelSystem();
        }

        // Resetear el sistema de muerte
        if (deathManager != null)
        {
            // El death manager ya debería estar en buen estado
            if (deathManager.IsDead)
            {
                Debug.LogWarning("[InicioNave] El DeathManager estaba en estado muerto, forzando reset");
            }
        }

        // Resetear el controlador de la nave
        if (shipController != null)
        {
            shipController.ResetMovement();
        }

        // Resetear el input controller
        if (shipInputController != null)
        {
            shipInputController.ResetInputState();
        }
    }

    /// <summary>
    /// Configura el botón para modo juego (puede controlar la nave)
    /// </summary>
    private void SetBotonModoJuego()
    {
        if (botonControl != null)
        {
            // El botón NUNCA se oculta
            botonControl.SetActive(true);

            // Habilitar interacción completa
            var canvasGroup = botonControl.GetComponent<CanvasGroup>();
            if (canvasGroup != null)
            {
                canvasGroup.alpha = 1f;
                canvasGroup.interactable = true;
                canvasGroup.blocksRaycasts = true;
            }

            // Asegurar que el Button component esté habilitado
            var button = botonControl.GetComponent<Button>();
            if (button != null)
            {
                button.interactable = true;
            }

            // Si tiene ShipInputController, asegurarse de que esté activo
            if (shipInputController != null)
            {
                shipInputController.enabled = true;
                shipInputController.ResetInputState();
            }

            Debug.Log("[InicioNave] Botón configurado para modo juego");
        }
    }

    /// <summary>
    /// Configura el botón para modo espera (semi-transparente)
    /// </summary>
    private void SetBotonModoEspera()
    {
        if (botonControl != null)
        {
            // El botón NUNCA se oculta, solo se vuelve semi-transparente
            botonControl.SetActive(true);

            var canvasGroup = botonControl.GetComponent<CanvasGroup>();
            if (canvasGroup != null)
            {
                canvasGroup.alpha = 0.5f;
                canvasGroup.interactable = false;
                canvasGroup.blocksRaycasts = true; // Aún puede recibir eventos
            }

            // El Button se deshabilita pero el GameObject sigue activo
            var button = botonControl.GetComponent<Button>();
            if (button != null)
            {
                button.interactable = false;
            }

            Debug.Log("[InicioNave] Botón configurado para modo espera");
        }
    }

    /// <summary>
    /// Configura el botón para modo muerte (esperando respawn)
    /// </summary>
    public void SetBotonModoMuerte()
    {
        if (botonControl != null)
        {
            // El botón sigue visible pero deshabilitado temporalmente
            botonControl.SetActive(true);

            var canvasGroup = botonControl.GetComponent<CanvasGroup>();
            if (canvasGroup != null)
            {
                canvasGroup.alpha = 0.3f; // Más transparente durante muerte
                canvasGroup.interactable = false;
                canvasGroup.blocksRaycasts = true;
            }

            Debug.Log("[InicioNave] Botón configurado para modo muerte");
        }
    }

    /// <summary>
    /// Configura el botón para modo respawn (listo para presionar)
    /// </summary>
    public void SetBotonModoRespawn()
    {
        if (botonControl != null)
        {
            // El botón se vuelve brillante indicando que puede respawnear
            botonControl.SetActive(true);

            var canvasGroup = botonControl.GetComponent<CanvasGroup>();
            if (canvasGroup != null)
            {
                canvasGroup.alpha = 1f; // Full opacidad para respawn
                canvasGroup.interactable = true;
                canvasGroup.blocksRaycasts = true;
            }

            var button = botonControl.GetComponent<Button>();
            if (button != null)
            {
                button.interactable = true;
            }

            Debug.Log("[InicioNave] Botón configurado para modo respawn");
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
            if (shipController != null)
            {
                shipController.ResetMovement();
            }

            if (fuelManager != null)
            {
                fuelManager.ResetFuelSystem();
            }

            if (shipInputController != null)
            {
                shipInputController.ResetInputState();
            }

            // Botón en modo espera (NO se oculta)
            SetBotonModoEspera();

            // Desactivar nave
            nave.SetActive(false);
            juegoIniciado = false;

            Debug.Log($"[InicioNave] Nave {nave.name} reiniciada");
        }
    }

    /// <summary>
    /// Método llamado cuando el jugador muere
    /// </summary>
    public void OnPlayerDeath()
    {
        SetBotonModoMuerte();
        Debug.Log($"[InicioNave] Nave {nave.name} ha muerto");
    }

    /// <summary>
    /// Método llamado cuando el jugador puede respawnear
    /// </summary>
    public void OnPlayerRespawnReady()
    {
        SetBotonModoRespawn();
        Debug.Log($"[InicioNave] Nave {nave.name} lista para respawn");
    }

    /// <summary>
    /// Método llamado cuando el jugador respawnea
    /// </summary>
    public void OnPlayerRespawn()
    {
        SetBotonModoJuego();

        // Rehabilitar sistemas después del respawn
        if (shipInputController != null)
        {
            shipInputController.ResetInputState();
        }

        Debug.Log($"[InicioNave] Nave {nave.name} respawneada");
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