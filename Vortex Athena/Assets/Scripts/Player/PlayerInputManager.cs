using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using System.Collections.Generic;
using GameSystems;

/// <summary>
/// Gestor de inputs optimizado para múltiples jugadores con integración completa de botones UI
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

        [Header("Referencias UI")]
        [Tooltip("Botón UI que controla esta nave")]
        public Button controlButton;

        [Header("Referencias de Nave")]
        public GameObject naveObject;
        public InicioNave inicioNave;
        public ShipController shipController;
        public ShipInputController shipInputController;
        public FuelManager fuelManager;
        public UnifiedDeathManager deathManager;

        [Header("Sistema de Gravedad")]
        public PlayerGravityHandler playerGravityHandler;

        [Header("Estado")]
        public bool isActive = false;
        public bool isMoving = false;
        public bool canMove = true;

        [Header("Configuración de Input")]
        [Tooltip("Si está habilitado, usa botones UI. Si no, usa control directo")]
        public bool useUIButton = true;

        // Cache para todos los componentes que manejan input en el botón
        [System.NonSerialized]
        public List<IPointerDownHandler> pointerDownHandlers = new List<IPointerDownHandler>();
        [System.NonSerialized]
        public List<IPointerUpHandler> pointerUpHandlers = new List<IPointerUpHandler>();
        [System.NonSerialized]
        public bool componentsCached = false;
    }

    [Header("Configuración")]
    public List<PlayerConfig> players = new List<PlayerConfig>();
    [SerializeField] private bool directKeyControl = true;

    [Header("Sistema BlackHole")]
    [SerializeField] private BlackHoleCore blackHoleCore;
    [SerializeField] private bool autoFindBlackHole = true;

    [Header("Debug")]
    [SerializeField] private bool debugInputEvents = false;

    private static PlayerInputManager instance;
    public static PlayerInputManager Instance => instance;

    void Awake()
    {
        if (instance == null)
        {
            instance = this;
        }
        else if (instance != this)
        {
            Destroy(gameObject);
            return;
        }

        ValidatePlayerConfigurations();

        if (autoFindBlackHole && blackHoleCore == null)
        {
            blackHoleCore = FindAnyObjectByType<BlackHoleCore>();
        }
    }

    void Start()
    {
        SetupEventListeners();
        CacheButtonComponents();

        // Marcar a todos como "muertos" al inicio - Para el arduino
        for (int i = 0; i < players.Count; i++)
        {
            SerialBridge.SendState(i + 1, false); // false = muerto
        }
    }

    /// <summary>
    /// Cachea TODOS los componentes de input en los botones para máximo control
    /// </summary>
    void CacheButtonComponents()
    {
        foreach (var player in players)
        {
            if (player.controlButton != null && player.useUIButton)
            {
                CachePlayerButtonComponents(player);
            }
        }
    }

    void CachePlayerButtonComponents(PlayerConfig player)
    {
        player.pointerDownHandlers.Clear();
        player.pointerUpHandlers.Clear();

        // Buscar en el GameObject del botón y todos sus hijos
        var allComponents = player.controlButton.GetComponentsInChildren<MonoBehaviour>();

        foreach (var component in allComponents)
        {
            // Buscar IPointerDownHandler
            if (component is IPointerDownHandler downHandler)
            {
                player.pointerDownHandlers.Add(downHandler);
                if (debugInputEvents)
                    Debug.Log($"[InputManager] Cached PointerDown handler: {component.GetType().Name} for {player.playerName}");
            }

            // Buscar IPointerUpHandler  
            if (component is IPointerUpHandler upHandler)
            {
                player.pointerUpHandlers.Add(upHandler);
                if (debugInputEvents)
                    Debug.Log($"[InputManager] Cached PointerUp handler: {component.GetType().Name} for {player.playerName}");
            }
        }

        player.componentsCached = true;

        if (player.pointerDownHandlers.Count == 0 && player.pointerUpHandlers.Count == 0)
        {
            Debug.LogWarning($"[InputManager] No se encontraron handlers de input en el botón de {player.playerName}. " +
                "Asegúrate de que el botón tenga componentes como ShipInputController o ComboSystem.", player.controlButton);
        }
    }

    void ValidatePlayerConfigurations()
    {
        for (int i = 0; i < players.Count; i++)
        {
            var player = players[i];
            player.playerIndex = i;

            if (player.naveObject == null)
            {
                Debug.LogError($"PlayerInputManager: {player.playerName} no ship assigned", this);
                continue;
            }

            // Validar botón UI si está configurado para usarlo
            if (player.useUIButton && player.controlButton == null)
            {
                Debug.LogWarning($"PlayerInputManager: {player.playerName} está configurado para usar botón UI pero no hay botón asignado. " +
                    "Cambiando a control directo.", this);
                player.useUIButton = false;
            }

            // Auto-buscar componentes si no están asignados
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

            if (player.playerGravityHandler == null)
                player.playerGravityHandler = player.naveObject.GetComponent<PlayerGravityHandler>();

            if (player.playerGravityHandler == null)
                Debug.LogError($"PlayerInputManager: {player.playerName} missing PlayerGravityHandler!", this);

            // Configurar referencia del agujero negro
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
                int playerIndex = player.playerIndex;
                player.fuelManager.OnFuelEmpty += () => OnPlayerFuelEmpty(playerIndex);
                player.fuelManager.OnFuelRestored += () => OnPlayerFuelRestored(playerIndex);
            }

            if (player.deathManager != null)
            {
                int playerIndex = player.playerIndex;
                player.deathManager.OnDeath += (deathType) => OnPlayerDeath(playerIndex, deathType);
                player.deathManager.OnRespawn += () => OnPlayerRespawn(playerIndex);
            }
        }
    }

    void Update()
    {
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
        if (Input.GetKeyDown(player.controlKey))
        {
            OnPlayerKeyDown(player);
        }
        else if (Input.GetKeyUp(player.controlKey))
        {
            OnPlayerKeyUp(player);
        }
    }

    /// <summary>
    /// Maneja la acción cuando se presiona la tecla del jugador
    /// </summary>
    void OnPlayerKeyDown(PlayerConfig player)
    {
        // Activar jugador si no está activo
        if (!player.isActive)
        {
            ActivatePlayer(player);
            return;
        }

        // Usar botón UI si está configurado
        if (player.useUIButton && player.controlButton != null)
        {
            SimulateButtonPress(player);
        }
        else
        {
            // Fallback al control directo legacy
            HandleDirectInput(player, true);
        }
    }

    /// <summary>
    /// Maneja la acción cuando se suelta la tecla del jugador
    /// </summary>
    void OnPlayerKeyUp(PlayerConfig player)
    {
        if (!player.isActive) return;

        // Usar botón UI si está configurado
        if (player.useUIButton && player.controlButton != null)
        {
            SimulateButtonRelease(player);
        }
        else
        {
            // Fallback al control directo legacy
            HandleDirectInput(player, false);
        }
    }

    /// <summary>
    /// Simula presionar el botón UI llamando a TODOS los handlers
    /// </summary>
    void SimulateButtonPress(PlayerConfig player)
    {
        // Re-cachear componentes si es necesario
        if (!player.componentsCached)
        {
            CachePlayerButtonComponents(player);
        }

        player.isMoving = true;

        // Crear datos de evento simulado
        var pointerData = new PointerEventData(EventSystem.current)
        {
            button = PointerEventData.InputButton.Left,
            position = player.controlButton.transform.position
        };

        // Llamar a TODOS los handlers de PointerDown
        foreach (var handler in player.pointerDownHandlers)
        {
            try
            {
                handler.OnPointerDown(pointerData);

                if (debugInputEvents)
                {
                    Debug.Log($"[InputManager] Called OnPointerDown on {handler.GetType().Name} for {player.playerName}");
                }
            }
            catch (System.Exception e)
            {
                Debug.LogError($"[InputManager] Error calling OnPointerDown on {handler.GetType().Name}: {e.Message}");
            }
        }

        // Fallback: Si no hay handlers o falla, intentar con el botón
        if (player.pointerDownHandlers.Count == 0 && player.controlButton.interactable)
        {
            player.controlButton.onClick.Invoke();
            if (debugInputEvents)
                Debug.Log($"[InputManager] Fallback: Called onClick for {player.playerName}");
        }

        if (debugInputEvents)
        {
            Debug.Log($"[InputManager] {player.playerName} - Botón presionado (Handlers: {player.pointerDownHandlers.Count})",
                player.controlButton);
        }
    }

    /// <summary>
    /// Simula soltar el botón UI llamando a TODOS los handlers
    /// </summary>
    void SimulateButtonRelease(PlayerConfig player)
    {
        player.isMoving = false;

        // Crear datos de evento simulado
        var pointerData = new PointerEventData(EventSystem.current)
        {
            button = PointerEventData.InputButton.Left,
            position = player.controlButton.transform.position
        };

        // Llamar a TODOS los handlers de PointerUp
        foreach (var handler in player.pointerUpHandlers)
        {
            try
            {
                handler.OnPointerUp(pointerData);

                if (debugInputEvents)
                {
                    Debug.Log($"[InputManager] Called OnPointerUp on {handler.GetType().Name} for {player.playerName}");
                }
            }
            catch (System.Exception e)
            {
                Debug.LogError($"[InputManager] Error calling OnPointerUp on {handler.GetType().Name}: {e.Message}");
            }
        }

        if (debugInputEvents)
        {
            Debug.Log($"[InputManager] {player.playerName} - Botón soltado (Handlers: {player.pointerUpHandlers.Count})",
                player.controlButton);
        }
    }

    /// <summary>
    /// Control directo legacy para compatibilidad
    /// </summary>
    void HandleDirectInput(PlayerConfig player, bool isPressed)
    {
        if (isPressed)
        {
            if (!player.canMove) return;

            player.isMoving = true;

            if (player.shipInputController != null)
            {
                player.shipInputController.OnPointerDown(null);
            }
            else if (player.shipController != null)
            {
                player.shipController.StartMoving();

                if (player.fuelManager != null)
                    player.fuelManager.StartConsuming();
            }
        }
        else
        {
            player.isMoving = false;

            if (player.shipInputController != null)
            {
                player.shipInputController.OnPointerUp(null);
            }
            else if (player.shipController != null)
            {
                player.shipController.StopMoving();

                if (player.fuelManager != null)
                    player.fuelManager.StopConsuming();
            }
        }
    }

    void ActivatePlayer(PlayerConfig player)
    {
        if (player.inicioNave != null)
        {
            player.inicioNave.IniciarJuego();
            player.isActive = true;
            player.canMove = true;
        }
        else if (player.naveObject != null)
        {
            player.naveObject.SetActive(true);
            player.isActive = true;
            player.canMove = true;
        }

        if (debugInputEvents)
            Debug.Log($"[InputManager] {player.playerName} activado");
    }

    #region Event Handlers

    void OnPlayerFuelEmpty(int playerIndex)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            players[playerIndex].canMove = false;
        }
    }

    void OnPlayerFuelRestored(int playerIndex)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            var player = players[playerIndex];
            if (player.deathManager == null || !player.deathManager.IsDead)
            {
                player.canMove = true;
            }
        }
    }

    void OnPlayerDeath(int playerIndex, UnifiedDeathManager.DeathType deathType)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            var player = players[playerIndex];
            player.canMove = false;

            if (player.isMoving)
            {
                OnPlayerKeyUp(player);
            }

            // Avisar al Arduino
            SerialBridge.SendState(playerIndex + 1, false);

            if (debugInputEvents)
                Debug.Log($"[InputManager] {player.playerName} murió por {deathType}");
        }
    }

    void OnPlayerRespawn(int playerIndex)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            players[playerIndex].canMove = true;

            // Avisar al Arduino
            SerialBridge.SendState(playerIndex + 1, true);

            var player = players[playerIndex];
            if (debugInputEvents)
                Debug.Log($"[InputManager] {player.playerName} respawned");
        }
    }

    #endregion

    #region Public API

    /// <summary>
    /// Activa un jugador por índice
    /// </summary>
    public void ActivatePlayerByIndex(int index)
    {
        if (index >= 0 && index < players.Count && !players[index].isActive)
        {
            ActivatePlayer(players[index]);
        }
    }

    /// <summary>
    /// Desactiva un jugador
    /// </summary>
    public void DeactivatePlayer(int index)
    {
        if (index >= 0 && index < players.Count)
        {
            var player = players[index];

            if (player.isMoving)
            {
                OnPlayerKeyUp(player);
            }

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
    /// Verifica si un jugador está activo
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

    /// <summary>
    /// Activa empuje de emergencia para un jugador
    /// </summary>
    public void ActivateEmergencyThrust(int playerIndex, float duration = 2f)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            var player = players[playerIndex];
            if (player.playerGravityHandler != null && player.isActive)
            {
                player.playerGravityHandler.TriggerManualEmergencyThrust(duration);
            }
        }
    }

    /// <summary>
    /// Verifica si un jugador está en campo gravitacional
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
    /// Verifica si un jugador está en zona de peligro
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
    /// Establece referencia del agujero negro
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
    }

    /// <summary>
    /// Cambia el modo de control de un jugador entre UI y directo
    /// </summary>
    public void ToggleControlMode(int playerIndex)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            var player = players[playerIndex];
            player.useUIButton = !player.useUIButton;

            if (player.useUIButton && player.controlButton == null)
            {
                Debug.LogWarning($"No hay botón UI asignado para {player.playerName}. Manteniendo control directo.");
                player.useUIButton = false;
            }
            else if (player.useUIButton)
            {
                // Re-cachear componentes al cambiar a modo UI
                CachePlayerButtonComponents(player);
            }
        }
    }

    /// <summary>
    /// Fuerza el re-cache de componentes de botón para un jugador
    /// </summary>
    public void RefreshButtonComponents(int playerIndex)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            var player = players[playerIndex];
            if (player.useUIButton && player.controlButton != null)
            {
                CachePlayerButtonComponents(player);
            }
        }
    }

    /// <summary>
    /// Fuerza el re-cache de componentes para todos los jugadores
    /// </summary>
    public void RefreshAllButtonComponents()
    {
        foreach (var player in players)
        {
            if (player.useUIButton && player.controlButton != null)
            {
                CachePlayerButtonComponents(player);
            }
        }
    }

    #endregion

    void OnDestroy()
    {
        if (instance == this)
            instance = null;
    }

#if UNITY_EDITOR
    [UnityEditor.CustomEditor(typeof(PlayerInputManager))]
    public class PlayerInputManagerEditor : UnityEditor.Editor
    {
        public override void OnInspectorGUI()
        {
            DrawDefaultInspector();

            if (Application.isPlaying)
            {
                GUILayout.Space(10);
                if (GUILayout.Button("Refresh All Button Components"))
                {
                    ((PlayerInputManager)target).RefreshAllButtonComponents();
                }
            }
        }
    }
#endif
}