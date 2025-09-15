using UnityEngine;
using GameSystems;

/// <summary>
/// Gestiona SOLO la inicialización y activación de una nave
/// No maneja estados del botón - eso lo hace ShipInputController
/// ACTUALIZADO: Compatible con el nuevo sistema BlackHoleCore
/// </summary>
public class InicioNave : MonoBehaviour
{
    [Header("Configuración de Nave")]
    public GameObject nave;
    public float impulsoInicial = 5f;
    public Vector2 direccionImpulso;

    [Header("Configuración Inicial")]
    [Tooltip("Combustible inicial al activar la nave")]
    public float combustibleInicial = 100f;

    [Header("Órbita inicial")]
    [SerializeField] private bool usarOrbitaInicial = true;
    [SerializeField] private Transform orbitaCentro; // Asigna el Transform del agujero negro
    [SerializeField] private int sentidoOrbita = 1;  // 1 = CCW, -1 = CW

    [Header("Referencias ACTUALIZADAS")]
    [SerializeField] private BlackHoleCore blackHoleCore; // NUEVO: Reemplaza BlackHoleAttractionManager
    [SerializeField] private ShipInputController shipInputController;

    [Header("Auto-detección")]
    [SerializeField] private bool autoFindBlackHole = true; // Buscar automáticamente el agujero negro

    // Estado
    private bool juegoIniciado = false;
    public bool JuegoIniciado => juegoIniciado;

    void Start()
    {
        if (GameManager.Instance != null)
        {
            GameManager.Instance.RegisterShip(nave);
            //nave.SetActive(false);
        }

        // NUEVO: Auto-detectar BlackHoleCore si no está asignado
        if (autoFindBlackHole && blackHoleCore == null)
        {
            blackHoleCore = FindAnyObjectByType<BlackHoleCore>();
            if (blackHoleCore == null)
            {
                Debug.LogWarning("InicioNave: No se encontró un BlackHoleCore en la escena. El registro con el agujero negro no funcionará.");
            }
        }
    }

    /// <summary>
    /// Inicia el juego activando la nave con impulso inicial y velocidad angular de órbita
    /// ACTUALIZADO: Compatible con el nuevo sistema de gravedad
    /// </summary>
    public void IniciarJuego()
    {
        if (juegoIniciado || nave == null) return;

        juegoIniciado = true;
        nave.SetActive(true);

        Rigidbody2D rb = nave.GetComponent<Rigidbody2D>();
        if (rb != null)
        {
            rb.bodyType = RigidbodyType2D.Dynamic;
            rb.simulated = true;

            Vector2 vDir;
            Vector2 centroParaOrbita = Vector2.zero; // guardamos para calcular ω

            if (usarOrbitaInicial)
            {
                // Centro de órbita: override -> blackHoleCore -> (0,0)
                centroParaOrbita = orbitaCentro ? (Vector2)orbitaCentro.position :
                                   (blackHoleCore ? (Vector2)blackHoleCore.transform.position : Vector2.zero);

                // Vector radial desde centro -> nave
                Vector2 radial = ((Vector2)rb.worldCenterOfMass - centroParaOrbita);
                if (radial.sqrMagnitude < 0.0001f) radial = Vector2.right;
                radial.Normalize();

                // Tangente 2D: (-y, x). Aplica sentido de órbita.
                Vector2 tangente = new Vector2(-radial.y, radial.x) * Mathf.Sign(sentidoOrbita == 0 ? 1 : sentidoOrbita);
                vDir = tangente;
            }
            else
            {
                vDir = direccionImpulso.sqrMagnitude > 0f ? direccionImpulso.normalized : Vector2.right;
            }

            // Velocidad lineal inicial
            rb.linearVelocity = vDir * impulsoInicial;

            // Velocidad angular inicial: ω = v / r (en grados/seg para 2D)
            if (usarOrbitaInicial)
            {
                float r = Vector2.Distance(rb.worldCenterOfMass, centroParaOrbita);
                if (r > 0.001f)
                {
                    float omegaDegPerSec = (impulsoInicial / r) * Mathf.Rad2Deg;
                    rb.angularVelocity = omegaDegPerSec * Mathf.Sign(sentidoOrbita == 0 ? 1 : sentidoOrbita);
                }
                else
                {
                    rb.angularVelocity = 0f;
                }
            }
            else
            {
                rb.angularVelocity = 0f;
            }
        }

        ConfigurarSistemas();

        if (shipInputController != null)
            shipInputController.OnGameStarted();

        // ACTUALIZADO: Registrar con el nuevo sistema BlackHoleCore
        RegistrarEnBlackHole();

        Debug.Log($"[InicioNave] Nave {nave.name} iniciada con {combustibleInicial} de combustible");
    }

    /// <summary>
    /// Configura los sistemas de la nave al iniciar
    /// </summary>
    private void ConfigurarSistemas()
    {
        var fuelManager = nave.GetComponentInChildren<FuelManager>();
        if (fuelManager != null)
        {
            fuelManager.SetFuel(combustibleInicial);
            fuelManager.ResetFuelSystem();
        }

        var shipController = nave.GetComponentInChildren<ShipController>();
        if (shipController != null)
        {
            shipController.ResetMovement();
        }

        // NUEVO: Resetear estado de gravedad si existe
        var playerGravityHandler = nave.GetComponent<PlayerGravityHandler>();
        if (playerGravityHandler != null)
        {
            playerGravityHandler.ResetGravityState();
        }
    }

    /// <summary>
    /// Reinicia el estado de la nave
    /// ACTUALIZADO: Compatible con el nuevo sistema
    /// </summary>
    public void ReiniciarNave()
    {
        if (nave != null)
        {
            // ACTUALIZADO: Desregistrar del nuevo sistema
            DesregistrarDeBlackHole();

            var shipController = nave.GetComponentInChildren<ShipController>();
            if (shipController != null)
                shipController.ResetMovement();

            var fuelManager = nave.GetComponentInChildren<FuelManager>();
            if (fuelManager != null)
                fuelManager.ResetFuelSystem();

            if (shipInputController != null)
                shipInputController.ResetInputState();

            // NUEVO: Resetear sistema de gravedad
            var playerGravityHandler = nave.GetComponent<PlayerGravityHandler>();
            if (playerGravityHandler != null)
            {
                playerGravityHandler.ResetGravityState();
            }

            nave.SetActive(false);
            juegoIniciado = false;

            Debug.Log($"[InicioNave] Nave {nave.name} reiniciada");
        }
    }

    /// <summary>
    /// ACTUALIZADO: Registra la nave con el nuevo sistema BlackHoleCore
    /// NOTA: El nuevo sistema maneja el registro automáticamente via triggers,
    /// pero mantenemos la funcionalidad para compatibilidad
    /// </summary>
    private void RegistrarEnBlackHole()
    {
        if (blackHoleCore != null && nave != null)
        {
            // Verificar que la nave tenga el PlayerGravityHandler
            PlayerGravityHandler playerGravityHandler = nave.GetComponent<PlayerGravityHandler>();
            if (playerGravityHandler != null)
            {
                Debug.Log($"[InicioNave] Nave {nave.name} lista para interactuar con BlackHoleCore - " +
                         "El registro se hará automáticamente al entrar en la zona de influencia");

                // OPCIONAL: Configurar el centro del mapa en el ShipController
                var shipController = nave.GetComponentInChildren<ShipController>();
                if (shipController != null)
                {
                    shipController.SetMapCenter(blackHoleCore.Position);
                }
            }
            else
            {
                Debug.LogError($"[InicioNave] Nave {nave.name} no tiene PlayerGravityHandler - " +
                              "No podrá interactuar con el agujero negro!");
            }
        }
        else if (blackHoleCore == null)
        {
            Debug.LogWarning($"[InicioNave] No se encontró BlackHoleCore - " +
                           "La nave {nave.name} no podrá interactuar con agujeros negros");
        }
    }

    /// <summary>
    /// ACTUALIZADO: Desregistra la nave del sistema BlackHoleCore
    /// NOTA: El nuevo sistema maneja esto automáticamente, pero mantenemos por compatibilidad
    /// </summary>
    private void DesregistrarDeBlackHole()
    {
        if (nave != null)
        {
            // El nuevo sistema BlackHoleCore maneja el desregistro automáticamente
            // cuando los objetos salen del trigger o se desactivan
            Debug.Log($"[InicioNave] Nave {nave.name} será desregistrada automáticamente del BlackHoleCore");
        }
    }

    /// <summary>
    /// NUEVO: Método público para establecer la referencia al BlackHoleCore
    /// Útil para configuración dinámica o multiple agujeros negros
    /// </summary>
    public void SetBlackHoleReference(BlackHoleCore newBlackHole)
    {
        blackHoleCore = newBlackHole;

        if (juegoIniciado)
        {
            // Actualizar centro del mapa si el juego ya ha iniciado
            var shipController = nave?.GetComponentInChildren<ShipController>();
            if (shipController != null && blackHoleCore != null)
            {
                shipController.SetMapCenter(blackHoleCore.Position);
            }
        }

        Debug.Log($"[InicioNave] Referencia BlackHoleCore actualizada para {nave?.name}");
    }

    /// <summary>
    /// NUEVO: Método para verificar si la nave está lista para el nuevo sistema
    /// </summary>
    public bool IsShipReadyForGravitySystem()
    {
        if (nave == null) return false;

        var playerGravityHandler = nave.GetComponent<PlayerGravityHandler>();
        var rigidbody = nave.GetComponent<Rigidbody2D>();
        var collider = nave.GetComponent<Collider2D>();

        bool isReady = playerGravityHandler != null && rigidbody != null && collider != null;

        if (!isReady)
        {
            Debug.LogWarning($"[InicioNave] Nave {nave.name} no está lista para el sistema de gravedad:\n" +
                           $"- PlayerGravityHandler: {(playerGravityHandler != null ? "✓" : "✗")}\n" +
                           $"- Rigidbody2D: {(rigidbody != null ? "✓" : "✗")}\n" +
                           $"- Collider2D: {(collider != null ? "✓" : "✗")}");
        }

        return isReady;
    }

    private void OnValidate()
    {
        impulsoInicial = Mathf.Max(0f, impulsoInicial);
        if (sentidoOrbita == 0) sentidoOrbita = 1;
    }

    void OnDisable() => DesregistrarDeBlackHole();
    void OnDestroy() => DesregistrarDeBlackHole();

    // === MÉTODOS DE DEBUG ===

#if UNITY_EDITOR
    [ContextMenu("Debug: Check Ship Gravity Readiness")]
    private void DebugCheckShipReadiness()
    {
        bool isReady = IsShipReadyForGravitySystem();
        Debug.Log($"[InicioNave] Nave {nave?.name} ready for gravity system: {isReady}");
    }

    [ContextMenu("Debug: Find BlackHoleCore")]
    private void DebugFindBlackHole()
    {
        blackHoleCore = FindAnyObjectByType<BlackHoleCore>();
        if (blackHoleCore != null)
        {
            Debug.Log($"[InicioNave] BlackHoleCore encontrado: {blackHoleCore.name}");
        }
        else
        {
            Debug.LogWarning("[InicioNave] No se encontró BlackHoleCore en la escena");
        }
    }

    [ContextMenu("Debug: Test Initialize Ship")]
    private void DebugTestInitialize()
    {
        if (Application.isPlaying)
        {
            IniciarJuego();
        }
        else
        {
            Debug.LogWarning("[InicioNave] Este test solo funciona en Play Mode");
        }
    }
#endif
}