using UnityEngine;
using System.Collections.Generic;
using GameSystems; // Para acceder a los nuevos sistemas

/// <summary>
/// Gestor centralizado de inputs para múltiples jugadores
/// ACTUALIZADO: Compatible con PlayerGravityHandler y BlackHoleCore
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
        public ShipInputController shipInputController;
        public FuelManager fuelManager;
        public UnifiedDeathManager deathManager;

        [Header("NUEVO: Sistema de Gravedad")]
        public PlayerGravityHandler playerGravityHandler; // NUEVO: Reemplaza AffectedByBlackHole

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

    [Header("NUEVO: Sistema de Agujero Negro")]
    [SerializeField] private BlackHoleCore blackHoleCore; // Referencia al agujero negro
    [SerializeField] private bool autoFindBlackHole = true;

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

        // NUEVO: Auto-detectar BlackHoleCore
        if (autoFindBlackHole && blackHoleCore == null)
        {
            blackHoleCore = FindAnyObjectByType<BlackHoleCore>();
        }
    }

    void Start()
    {
        // Suscribirse a eventos de los sistemas
        SetupEventListeners();

        if (debugMode)
            Debug.Log($"[PlayerInputManager] Inicializado con {players.Count} jugadores");
    }

    /// <summary>
    /// ACTUALIZADO: Incluye validación del nuevo PlayerGravityHandler
    /// </summary>
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

            // NUEVO: Auto-obtener PlayerGravityHandler
            if (player.playerGravityHandler == null)
                player.playerGravityHandler = player.naveObject.GetComponent<PlayerGravityHandler>();

            // Validar componentes necesarios
            if (player.shipController == null)
                Debug.LogWarning($"[PlayerInputManager] {player.playerName} no tiene ShipController");

            if (player.shipInputController == null)
                Debug.LogWarning($"[PlayerInputManager] {player.playerName} no tiene ShipInputController");

            if (player.fuelManager == null)
                Debug.LogWarning($"[PlayerInputManager] {player.playerName} no tiene FuelManager");

            // NUEVO: Validar PlayerGravityHandler
            if (player.playerGravityHandler == null)
                Debug.LogError($"[PlayerInputManager] {player.playerName} no tiene PlayerGravityHandler - " +
                              "No podrá interactuar con agujeros negros!");

            // NUEVO: Configurar referencia al agujero negro en InicioNave
            if (player.inicioNave != null && blackHoleCore != null)
            {
                player.inicioNave.SetBlackHoleReference(blackHoleCore);
            }
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

            // NUEVO: Eventos del sistema de gravedad
            if (player.playerGravityHandler != null)
            {
                int playerIndex = player.playerIndex;

                // Podríamos añadir eventos específicos aquí si los necesitamos
                // Por ejemplo, cuando entra en zona de peligro, etc.
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

    // === NUEVOS MÉTODOS PARA EL SISTEMA DE GRAVEDAD ===

    /// <summary>
    /// NUEVO: Activa empuje de emergencia para un jugador específico
    /// </summary>
    public void ActivateEmergencyThrust(int playerIndex, float duration = 2f)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            var player = players[playerIndex];
            if (player.playerGravityHandler != null && player.isActive)
            {
                player.playerGravityHandler.TriggerManualEmergencyThrust(duration);

                if (debugMode)
                    Debug.Log($"[PlayerInputManager] Empuje de emergencia activado para {player.playerName}");
            }
        }
    }

    /// <summary>
    /// NUEVO: Obtiene información de gravedad de un jugador
    /// </summary>
    public bool IsPlayerInGravityField(int playerIndex)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            var player = players[playerIndex];
            return player.playerGravityHandler?.IsInGravityField ?? false;
        }
        return false;
    }

    /// <summary>
    /// NUEVO: Verifica si un jugador está en zona de peligro
    /// </summary>
    public bool IsPlayerInDangerZone(int playerIndex)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            var player = players[playerIndex];
            return player.playerGravityHandler?.IsInDangerZone ?? false;
        }
        return false;
    }

    /// <summary>
    /// NUEVO: Establece la referencia al BlackHoleCore para todos los jugadores
    /// </summary>
    public void SetBlackHoleReference(BlackHoleCore newBlackHole)
    {
        blackHoleCore = newBlackHole;

        foreach (var player in players)
        {
            if (player.inicioNave != null)
            {
                player.inicioNave.SetBlackHoleReference(blackHoleCore);
            }
        }

        if (debugMode)
            Debug.Log($"[PlayerInputManager] Referencia BlackHoleCore actualizada para todos los jugadores");
    }

    void OnDestroy()
    {
        if (instance == this)
            instance = null;
    }

    // === MÉTODOS DE DEBUG ===

#if UNITY_EDITOR
    [ContextMenu("Debug: Show All Players Gravity Status")]
    private void DebugShowAllPlayersGravityStatus()
    {
        Debug.Log("=== ESTADO DE GRAVEDAD DE TODOS LOS JUGADORES ===");
        for (int i = 0; i < players.Count; i++)
        {
            var player = players[i];
            if (player.playerGravityHandler != null)
            {
                Debug.Log($"{player.playerName}:\n" +
                         $"  - In Gravity Field: {player.playerGravityHandler.IsInGravityField}\n" +
                         $"  - In Danger Zone: {player.playerGravityHandler.IsInDangerZone}\n" +
                         $"  - Gravity Intensity: {player.playerGravityHandler.CurrentGravityIntensity:F2}\n" +
                         $"  - Emergency Thrust: {player.playerGravityHandler.EmergencyThrustActive}\n" +
                         $"  - Distance to Black Hole: {player.playerGravityHandler.GetDistanceToBlackHole():F1}");
            }
            else
            {
                Debug.LogWarning($"{player.playerName}: No tiene PlayerGravityHandler");
            }
        }
    }

    [ContextMenu("Debug: Test Emergency Thrust All Players")]
    private void DebugTestEmergencyThrustAll()
    {
        for (int i = 0; i < players.Count; i++)
        {
            if (players[i].isActive)
            {
                ActivateEmergencyThrust(i, 3f);
            }
        }
    }

    [ContextMenu("Debug: Find and Assign BlackHoleCore")]
    private void DebugFindBlackHole()
    {
        blackHoleCore = FindAnyObjectByType<BlackHoleCore>();
        if (blackHoleCore != null)
        {
            SetBlackHoleReference(blackHoleCore);
            Debug.Log($"[PlayerInputManager] BlackHoleCore encontrado y asignado: {blackHoleCore.name}");
        }
        else
        {
            Debug.LogWarning("[PlayerInputManager] No se encontró BlackHoleCore en la escena");
        }
    }

    [ContextMenu("Debug: Validate All Player Components")]
    private void DebugValidateAllComponents()
    {
        Debug.Log("=== VALIDACIÓN DE COMPONENTES DE JUGADORES ===");
        for (int i = 0; i < players.Count; i++)
        {
            var player = players[i];
            Debug.Log($"{player.playerName}:\n" +
                     $"  - ShipController: {(player.shipController != null ? "✓" : "✗")}\n" +
                     $"  - ShipInputController: {(player.shipInputController != null ? "✓" : "✗")}\n" +
                     $"  - FuelManager: {(player.fuelManager != null ? "✓" : "✗")}\n" +
                     $"  - UnifiedDeathManager: {(player.deathManager != null ? "✓" : "✗")}\n" +
                     $"  - PlayerGravityHandler: {(player.playerGravityHandler != null ? "✓" : "✗")}\n" +
                     $"  - InicioNave: {(player.inicioNave != null ? "✓" : "✗")}");
        }
    }
#endif
}