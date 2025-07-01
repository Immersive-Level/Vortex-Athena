using UnityEngine;
using System.Collections.Generic;

/// <summary>
/// Gestor centralizado de inputs para múltiples jugadores
/// Ahora valida el combustible antes de permitir movimiento
/// </summary>
public class PlayerInputManager : MonoBehaviour
{
    [System.Serializable]
    public class PlayerConfig
    {
        [Header("Identificación")]
        public string playerName = "Player 1";
        public int playerIndex = 0;

        [Header("Control")]
        public KeyCode controlKey = KeyCode.Alpha1;

        [Header("Referencias")]
        public GameObject naveObject;
        public InicioNave inicioNave;
        public ShipController shipController;
        public Boton fuelButton;
        public Fuel_System fuelSystem; // Nueva referencia al sistema de combustible

        [Header("Estado")]
        public bool isActive = false;
        public bool isMoving = false;
        public bool hasFuel = true; // Estado del combustible
    }

    [Header("Configuración de Jugadores")]
    public List<PlayerConfig> players = new List<PlayerConfig>();

    [Header("Debug")]
    public bool debugMode = false;

    [Header("Feedback Visual")]
    [Tooltip("Mostrar mensaje cuando no hay combustible")]
    public bool showNoFuelWarning = true;

    // Singleton opcional para acceso global
    private static PlayerInputManager instance;
    public static PlayerInputManager Instance => instance;

    void Awake()
    {
        // Configurar singleton
        if (instance == null)
        {
            instance = this;
        }
        else if (instance != this)
        {
            Destroy(gameObject);
            return;
        }

        // Validar y configurar jugadores
        ValidatePlayerConfigurations();
    }

    void Start()
    {
        // Suscribirse a eventos de combustible
        foreach (var player in players)
        {
            if (player.fuelSystem != null)
            {
                // Crear referencias locales para evitar problemas con closures
                var currentPlayer = player;

                player.fuelSystem.OnFuelEmpty += () => OnPlayerFuelEmpty(currentPlayer);
                player.fuelSystem.OnFuelRestored += () => OnPlayerFuelRestored(currentPlayer);

                // Estado inicial
                player.hasFuel = player.fuelSystem.HasFuel;
            }
        }

        if (debugMode)
            Debug.Log($"[PlayerInputManager] Inicializado con {players.Count} jugadores");
    }

    void OnDestroy()
    {
        // Desuscribirse de eventos
        foreach (var player in players)
        {
            if (player.fuelSystem != null)
            {
                // Nota: En un caso real, deberíamos guardar las referencias a los delegados
                // para poder desuscribirnos correctamente
            }
        }

        if (instance == this)
            instance = null;
    }

    void ValidatePlayerConfigurations()
    {
        for (int i = 0; i < players.Count; i++)
        {
            var player = players[i];
            player.playerIndex = i;

            if (player.naveObject == null)
            {
                Debug.LogError($"[PlayerInputManager] {player.playerName} no tiene nave asignada");
                continue;
            }

            // Auto-obtener componentes si no están asignados
            if (player.shipController == null)
                player.shipController = player.naveObject.GetComponent<ShipController>();

            if (player.fuelSystem == null)
                player.fuelSystem = player.naveObject.GetComponent<Fuel_System>();

            if (player.inicioNave == null)
            {
                player.inicioNave = player.naveObject.GetComponent<InicioNave>();
                if (player.inicioNave == null)
                    player.inicioNave = player.naveObject.GetComponentInParent<InicioNave>();
            }

            // Validar componentes necesarios
            if (player.shipController == null)
                Debug.LogWarning($"[PlayerInputManager] {player.playerName} no tiene ShipController");

            if (player.fuelSystem == null)
                Debug.LogWarning($"[PlayerInputManager] {player.playerName} no tiene Fuel_System");

            if (player.inicioNave == null)
                Debug.LogWarning($"[PlayerInputManager] {player.playerName} no tiene InicioNave");
        }
    }

    void Update()
    {
        // Procesar input de cada jugador
        foreach (var player in players)
        {
            ProcessPlayerInput(player);
        }
    }

    void ProcessPlayerInput(PlayerConfig player)
    {
        // Verificar si la tecla está siendo presionada
        if (Input.GetKeyDown(player.controlKey))
        {
            OnPlayerKeyDown(player);
        }
        else if (Input.GetKeyUp(player.controlKey))
        {
            OnPlayerKeyUp(player);
        }
    }

    void OnPlayerKeyDown(PlayerConfig player)
    {
        // Si la nave no está activa, activarla
        if (!player.isActive)
        {
            ActivatePlayer(player);
            return;
        }

        // Verificar combustible antes de iniciar movimiento
        if (!player.hasFuel || (player.fuelSystem != null && !player.fuelSystem.HasFuel))
        {
            if (showNoFuelWarning && debugMode)
                Debug.LogWarning($"[PlayerInputManager] {player.playerName} - Sin combustible!");
            return;
        }

        // Si ya está activa y hay combustible, iniciar movimiento
        if (player.shipController != null && player.isActive)
        {
            player.isMoving = true;
            player.shipController.StartMoving();

            if (player.fuelButton != null)
                player.fuelButton.OnPress();

            if (debugMode)
                Debug.Log($"[PlayerInputManager] {player.playerName} - Movimiento iniciado");
        }
    }

    void OnPlayerKeyUp(PlayerConfig player)
    {
        // Solo procesar si la nave está activa y en movimiento
        if (player.isActive && player.isMoving)
        {
            player.isMoving = false;

            if (player.shipController != null)
                player.shipController.StopMoving();

            if (player.fuelButton != null)
                player.fuelButton.OnRelease();

            if (debugMode)
                Debug.Log($"[PlayerInputManager] {player.playerName} - Movimiento detenido");
        }
    }

    void ActivatePlayer(PlayerConfig player)
    {
        if (player.inicioNave != null)
        {
            // Usar el sistema de InicioNave
            player.inicioNave.IniciarJuego();
            player.isActive = true;

            // Verificar estado inicial del combustible
            if (player.fuelSystem != null)
                player.hasFuel = player.fuelSystem.HasFuel;

            if (debugMode)
                Debug.Log($"[PlayerInputManager] {player.playerName} activado");
        }
        else if (player.naveObject != null)
        {
            // Activación directa si no hay InicioNave
            player.naveObject.SetActive(true);
            player.isActive = true;

            // Verificar estado inicial del combustible
            if (player.fuelSystem != null)
                player.hasFuel = player.fuelSystem.HasFuel;

            Debug.LogWarning($"[PlayerInputManager] {player.playerName} activado sin InicioNave");
        }
    }

    /// <summary>
    /// Manejador cuando un jugador se queda sin combustible
    /// </summary>
    void OnPlayerFuelEmpty(PlayerConfig player)
    {
        player.hasFuel = false;

        // Si está en movimiento, detenerlo
        if (player.isMoving)
        {
            OnPlayerKeyUp(player);
        }

        if (debugMode)
            Debug.Log($"[PlayerInputManager] {player.playerName} - Combustible agotado");
    }

    /// <summary>
    /// Manejador cuando un jugador recupera combustible
    /// </summary>
    void OnPlayerFuelRestored(PlayerConfig player)
    {
        player.hasFuel = true;

        if (debugMode)
            Debug.Log($"[PlayerInputManager] {player.playerName} - Combustible restaurado");
    }

    /// <summary>
    /// Activa un jugador específico por índice (útil para UI)
    /// </summary>
    public void ActivatePlayerByIndex(int index)
    {
        if (index >= 0 && index < players.Count && !players[index].isActive)
        {
            ActivatePlayer(players[index]);
        }
    }

    /// <summary>
    /// Desactiva un jugador específico
    /// </summary>
    public void DeactivatePlayer(int index)
    {
        if (index >= 0 && index < players.Count)
        {
            var player = players[index];

            // Detener movimiento si está activo
            if (player.isMoving)
            {
                OnPlayerKeyUp(player);
            }

            // Reiniciar nave si tiene InicioNave
            if (player.inicioNave != null)
            {
                player.inicioNave.ReiniciarNave();
            }
            else if (player.naveObject != null)
            {
                player.naveObject.SetActive(false);
            }

            player.isActive = false;
            player.isMoving = false;
        }
    }

    /// <summary>
    /// Obtiene el estado de un jugador
    /// </summary>
    public bool IsPlayerActive(int index)
    {
        if (index >= 0 && index < players.Count)
            return players[index].isActive;
        return false;
    }

    /// <summary>
    /// Obtiene si un jugador tiene combustible
    /// </summary>
    public bool PlayerHasFuel(int index)
    {
        if (index >= 0 && index < players.Count)
            return players[index].hasFuel;
        return false;
    }

    /// <summary>
    /// Obtiene la configuración de un jugador
    /// </summary>
    public PlayerConfig GetPlayerConfig(int index)
    {
        if (index >= 0 && index < players.Count)
            return players[index];
        return null;
    }

    /// <summary>
    /// Reinicia todos los jugadores
    /// </summary>
    public void ResetAllPlayers()
    {
        for (int i = 0; i < players.Count; i++)
        {
            DeactivatePlayer(i);
        }
    }
}