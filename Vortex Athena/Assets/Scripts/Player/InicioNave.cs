using UnityEngine;
using GameSystems;

/// <summary>
/// Gestiona inicialización de naves - Simple y eficiente
/// </summary>
public class InicioNave : MonoBehaviour
{
    [Header("Configuración de Nave")]
    public GameObject nave;
    //public float impulsoInicial = 5f;
    //public Vector2 direccionImpulso;

    [Header("Configuración Inicial")]
    public float combustibleInicial = 100f;

    [Header("Órbita Inicial")]
    [SerializeField] private bool usarOrbitaInicial = true;
    [SerializeField] private Transform orbitaCentro;
    [SerializeField] private int sentidoOrbita = 1;

    [Header("Sistema BlackHole")]
    [SerializeField] private BlackHoleCore blackHoleCore;
    [SerializeField] private bool autoFindBlackHole = true;
    [SerializeField] private ShipInputController shipInputController;

    private bool juegoIniciado = false;
    public bool JuegoIniciado => juegoIniciado;

    void Start()
    {
        // Mostrar nave durante tutorial (modo arcade - mostrar slots disponibles)
        nave.SetActive(true);

        GameManager.Instance?.RegisterShip(nave);

        if (autoFindBlackHole && blackHoleCore == null)
            blackHoleCore = FindAnyObjectByType<BlackHoleCore>();

        if (shipInputController == null)
            shipInputController = nave.GetComponentInChildren<ShipInputController>();

        // Suscribirse a cambios de estado del juego
        if (GameManager.Instance != null)
            GameManager.Instance.OnGameStateChanged += OnGameStateChanged;
    }

    private void OnGameStateChanged(GameState newState)
    {
        if (newState == GameState.InGame)
        {
            // Al iniciar juego, desactivar nave para esperar join-in manual
            if (!juegoIniciado)
            {
                nave.SetActive(false);
            }
        }
        else if (newState == GameState.InMenu)
        {
            ReiniciarNave();
        }
    }

    /// <summary>
    /// Inicialización manual (input del jugador) - Join-in durante juego
    /// </summary>
    public void IniciarJuego()
    {
        if (juegoIniciado) return;

        ActivarYConfigurarNave();
        shipInputController?.OnGameStarted();
    }

    private void ActivarYConfigurarNave()
    {
        juegoIniciado = true;
        nave.SetActive(true);

        ConfigurarSistemas();
    }


    private void ConfigurarSistemas()
    {
        // Combustible
        var fuelManager = nave.GetComponent<FuelManager>();
        fuelManager?.SetFuel(combustibleInicial);
        fuelManager?.ResetFuelSystem();

        // Controlador
        var shipController = nave.GetComponent<ShipController>();
        if (shipController != null)
        {
            shipController.ResetMovement();
            if (blackHoleCore != null)
                shipController.SetMapCenter(blackHoleCore.Position);
        }

        // Gravedad
        var gravityHandler = nave.GetComponent<PlayerGravityHandler>();
        gravityHandler?.ResetGravityState();
    }

    public void ReiniciarNave()
    {
        if (nave != null)
        {
            var shipController = nave.GetComponent<ShipController>();
            shipController?.ResetMovement();

            var fuelManager = nave.GetComponent<FuelManager>();
            fuelManager?.ResetFuelSystem();

            shipInputController?.ResetInputState();

            var gravityHandler = nave.GetComponent<PlayerGravityHandler>();
            gravityHandler?.ResetGravityState();

            // Volver al estado inicial: activa para mostrar slot disponible
            nave.SetActive(true);
            juegoIniciado = false;
        }
    }

    public void SetBlackHoleReference(BlackHoleCore newBlackHole)
    {
        blackHoleCore = newBlackHole;
        if (juegoIniciado)
        {
            var shipController = nave?.GetComponent<ShipController>();
            if (shipController != null)
                shipController.SetMapCenter(blackHoleCore.Position);
        }
    }


    private void OnDestroy()
    {
        if (GameManager.Instance != null)
            GameManager.Instance.OnGameStateChanged -= OnGameStateChanged;
    }
}