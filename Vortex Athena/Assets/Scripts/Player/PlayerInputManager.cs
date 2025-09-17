using UnityEngine;
using System.Collections.Generic;
using GameSystems;

/// <summary>
/// Gestor de inputs optimizado para múltiples jugadores con BlackHoleCore
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

        [Header("Sistema de Gravedad")]
        public PlayerGravityHandler playerGravityHandler;

        [Header("Estado")]
        public bool isActive = false;
        public bool isMoving = false;
        public bool canMove = true;
    }

    [Header("Configuración")]
    public List<PlayerConfig> players = new List<PlayerConfig>();
    [SerializeField] private bool directKeyControl = true;

    [Header("Sistema BlackHole")]
    [SerializeField] private BlackHoleCore blackHoleCore;
    [SerializeField] private bool autoFindBlackHole = true;

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

        // Marcar a todos como "muertos" al inicio - Para el arduino
        for (int i = 0; i < players.Count; i++)
        {
            SerialBridge.SendState(i + 1, false); // false = muerto
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

    void OnPlayerKeyDown(PlayerConfig player)
    {
        if (!player.isActive)
        {
            ActivatePlayer(player);
            return;
        }

        if (!player.canMove) return;

        if (player.shipInputController != null && player.isActive)
        {
            player.shipInputController.OnPointerDown(null);
            player.isMoving = true;
        }
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
        if (player.isActive && player.isMoving)
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
    }

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

            // --- NUEVO: avisar al Arduino ---
            SerialBridge.SendState(playerIndex + 1, false);
        }
    }

    void OnPlayerRespawn(int playerIndex)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            players[playerIndex].canMove = true;

            // --- NUEVO: avisar al Arduino ---
            SerialBridge.SendState(playerIndex + 1, true);

        }
    }

    public void ActivatePlayerByIndex(int index)
    {
        if (index >= 0 && index < players.Count && !players[index].isActive)
        {
            ActivatePlayer(players[index]);
        }
    }

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

    public bool IsPlayerActive(int index)
    {
        if (index >= 0 && index < players.Count)
            return players[index].isActive;
        return false;
    }

    public PlayerConfig GetPlayerConfig(int index)
    {
        if (index >= 0 && index < players.Count)
            return players[index];
        return null;
    }

    public void ResetAllPlayers()
    {
        for (int i = 0; i < players.Count; i++)
        {
            DeactivatePlayer(i);
        }
    }

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

    public bool IsPlayerInGravityField(int playerIndex)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            var player = players[playerIndex];
            return player.playerGravityHandler?.IsInGravityField ?? false;
        }
        return false;
    }

    public bool IsPlayerInDangerZone(int playerIndex)
    {
        if (playerIndex >= 0 && playerIndex < players.Count)
        {
            var player = players[playerIndex];
            return player.playerGravityHandler?.IsInDangerZone ?? false;
        }
        return false;
    }

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

    void OnDestroy()
    {
        if (instance == this)
            instance = null;
    }
}