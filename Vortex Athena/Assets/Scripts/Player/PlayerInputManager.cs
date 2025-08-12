using UnityEngine;
using System.Collections.Generic;
using GameSystems; // Para acceder a los nuevos sistemas

/// <summary>
/// Gestor centralizado de inputs para múltiples jugadores
/// Actualizado para trabajar con ShipInputController y el nuevo sistema
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
        public ShipInputController shipInputController; // NUEVO: Reemplaza a Boton
        public FuelManager fuelManager; // NUEVO: Para verificar combustible
        public UnifiedDeathManager deathManager; // NUEVO: Para verificar estado

        [Header("Estado")]
        public bool isActive = false;
        public bool isMoving = false;
        public bool canMove = true; // Para controlar si puede moverse
    }

    [Header("Configuración de Jugadores")]
    public List<PlayerConfig> players = new List<PlayerConfig>();

    [Header("Opciones")]
    [Tooltip("Si es true, las teclas controlan directamente el movimiento. Si es false, solo activan la nave")]
    public bool directKeyControl = true;

    [Header("Debug")]
    public bool debugMode = false;

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
        // Suscribirse a eventos de los sistemas
        SetupEventListeners();

        if (debugMode)
            Debug.Log($"[PlayerInputManager] Inicializado con {players.Count} jugadores");
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
                player.shipController = player.naveObject.GetComponentInChildren<ShipController>();

            if (player.shipInputController == null)
                player.shipInputController = player.naveObject.GetComponentInChildren<ShipInputController>();

            if (player.fuelManager == null)
                player.fuelManager = player.naveObject.GetComponentInChildren<FuelManager>();

            if (player.deathManager == null)
                player.deathManager = player.naveObject.GetComponentInChildren<UnifiedDeathManager>();

            if (player.inicioNave == null)
            {
                player.inicioNave = player.naveObject.GetComponent<InicioNave>();
                if (player.inicioNave == null)
                    player.inicioNave = player.naveObject.GetComponentInParent<InicioNave>();
            }

            // Validar componentes necesarios
            if (player.shipController == null)
                Debug.LogWarning($"[PlayerInputManager] {player.playerName} no tiene ShipController");

            if (player.shipInputController == null)
                Debug.LogWarning($"[PlayerInputManager] {player.playerName} no tiene ShipInputController");

            if (player.fuelManager == null)
                Debug.LogWarning($"[PlayerInputManager] {player.playerName} no tiene FuelManager");
        }
    }

    void SetupEventListeners()
    {
        foreach (var player in players)
        {
            if (player.fuelManager != null)
            {
                // Capturar el índice del jugador en el closure
                int playerIndex = player.playerIndex;

                // Cuando se agota el combustible, deshabilitar movimiento
                player.fuelManager.OnFuelEmpty += () => OnPlayerFuelEmpty(playerIndex);

                // Cuando se restaura el combustible, habilitar movimiento
                player.fuelManager.OnFuelRestored += () => OnPlayerFuelRestored(playerIndex);
            }

            if (player.deathManager != null)
            {
                int playerIndex = player.playerIndex;

                // Cuando muere, deshabilitar controles
                player.deathManager.OnDeath += (deathType) => OnPlayerDeath(playerIndex, deathType);

                // Cuando respawnea, rehabilitar controles
                player.deathManager.OnRespawn += () => OnPlayerRespawn(playerIndex);
            }
        }
    }

    void Update()
    {
        // Solo procesar inputs si el control directo está habilitado
        if (directKeyControl)
        {
            foreach (var player in players)
            {
                ProcessPlayerInput(player);
            }
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

        // Para tap/nudge (toques cortos)
        if (Input.GetKeyDown(player.controlKey) && Input.GetKeyUp(player.controlKey))
        {
            // El ShipInputController manejará esto automáticamente
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

        // Verificar si puede moverse
        if (!player.canMove)
        {
            if (debugMode)
                Debug.Log($"[PlayerInputManager] {player.playerName} no puede moverse");
            return;
        }

        // Si ya está activa, usar el nuevo sistema de input
        if (player.shipInputController != null && player.isActive)
        {
            // Simular el press del botón
            player.shipInputController.OnPointerDown(null);
            player.isMoving = true;

            if (debugMode)
                Debug.Log($"[PlayerInputManager] {player.playerName} - Movimiento iniciado");
        }
        // Fallback al sistema directo si no hay ShipInputController
        else if (player.shipController != null && player.isActive)
        {
            player.isMoving = true;
            player.shipController.StartMoving();

            if (player.fuelManager != null)
                player.fuelManager.StartConsuming();
        }
    }

    void OnPlayerKeyUp(PlayerConfig player)
    {
        // Solo procesar si la nave está activa y en movimiento
        if (player.isActive && player.isMoving)
        {
            player.isMoving = false;

            if (player.shipInputController != null)
            {
                // Simular el release del botón
                player.shipInputController.OnPointerUp(null);
            }
            // Fallback al sistema directo
            else if (player.shipController != null)
            {
                player.shipController.StopMoving();

                if (player.fuelManager != null)
                    player.fuelManager.StopConsuming();
            }

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
            player.canMove = true;

            if (debugMode)
                Debug.Log($"[PlayerInputManager] {player.playerName} activado");
        }
        else if (player.naveObject != null)
        {
            // Activación directa si no hay InicioNave
            player.naveObject.SetActive(true);
            player.isActive = true;
            player.canMove = true;

            Debug.LogWarning($"[PlayerInputManager] {player.playerName} activado sin InicioNave");
        }
    }

    // === EVENTOS DEL SISTEMA ===

    void OnPlayerFuelEmpty(int playerIndex)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            players[playerIndex].canMove = false;

            if (debugMode)
                Debug.Log($"[PlayerInputManager] {players[playerIndex].playerName} sin combustible");
        }
    }

    void OnPlayerFuelRestored(int playerIndex)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            var player = players[playerIndex];

            // Solo restaurar si no está muerto
            if (player.deathManager == null || !player.deathManager.IsDead)
            {
                player.canMove = true;

                if (debugMode)
                    Debug.Log($"[PlayerInputManager] {player.playerName} combustible restaurado");
            }
        }
    }

    void OnPlayerDeath(int playerIndex, UnifiedDeathManager.DeathType deathType)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            var player = players[playerIndex];
            player.canMove = false;

            // Forzar stop si está en movimiento
            if (player.isMoving)
            {
                OnPlayerKeyUp(player);
            }

            if (debugMode)
                Debug.Log($"[PlayerInputManager] {player.playerName} murió por {deathType}");
        }
    }

    void OnPlayerRespawn(int playerIndex)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            var player = players[playerIndex];
            player.canMove = true;

            if (debugMode)
                Debug.Log($"[PlayerInputManager] {player.playerName} respawneó");
        }
    }

    // === MÉTODOS PÚBLICOS ===

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
            player.canMove = false;
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

    void OnDestroy()
    {
        if (instance == this)
            instance = null;
    }
}