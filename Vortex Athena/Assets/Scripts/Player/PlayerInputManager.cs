using UnityEngine;
using System.Collections.Generic;

/// <summary>
/// Gestor centralizado de inputs para m�ltiples jugadores
/// Es el �nico responsable de capturar y procesar inputs
/// </summary>
public class PlayerInputManager : MonoBehaviour
{
    [System.Serializable]
    public class PlayerConfig
    {
        [Header("Identificaci�n")]
        public string playerName = "Player 1";
        public int playerIndex = 0;

        [Header("Control")]
        public KeyCode controlKey = KeyCode.Alpha1;

        [Header("Referencias")]
        public GameObject naveObject;
        public InicioNave inicioNave;
        public ShipController shipController;
        public Boton fuelButton;

        [Header("Estado")]
        public bool isActive = false;
        public bool isMoving = false;
    }

    [Header("Configuraci�n de Jugadores")]
    public List<PlayerConfig> players = new List<PlayerConfig>();

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

            // Auto-obtener componentes si no est�n asignados
            if (player.shipController == null)
                player.shipController = player.naveObject.GetComponent<ShipController>();

            if (player.inicioNave == null)
            {
                // Buscar en el padre o en el mismo objeto
                player.inicioNave = player.naveObject.GetComponent<InicioNave>();
                if (player.inicioNave == null)
                    player.inicioNave = player.naveObject.GetComponentInParent<InicioNave>();
            }

            // Validar componentes necesarios
            if (player.shipController == null)
                Debug.LogWarning($"[PlayerInputManager] {player.playerName} no tiene ShipController");

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
        // Verificar si la tecla est� siendo presionada
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
        // Si la nave no est� activa, activarla
        if (!player.isActive)
        {
            ActivatePlayer(player);
            return;
        }

        // Si ya est� activa, iniciar movimiento
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
        // Solo procesar si la nave est� activa y en movimiento
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

            if (debugMode)
                Debug.Log($"[PlayerInputManager] {player.playerName} activado");
        }
        else if (player.naveObject != null)
        {
            // Activaci�n directa si no hay InicioNave
            player.naveObject.SetActive(true);
            player.isActive = true;

            Debug.LogWarning($"[PlayerInputManager] {player.playerName} activado sin InicioNave");
        }
    }

    /// <summary>
    /// Activa un jugador espec�fico por �ndice (�til para UI)
    /// </summary>
    public void ActivatePlayerByIndex(int index)
    {
        if (index >= 0 && index < players.Count && !players[index].isActive)
        {
            ActivatePlayer(players[index]);
        }
    }

    /// <summary>
    /// Desactiva un jugador espec�fico
    /// </summary>
    public void DeactivatePlayer(int index)
    {
        if (index >= 0 && index < players.Count)
        {
            var player = players[index];

            // Detener movimiento si est� activo
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
    /// Obtiene la configuraci�n de un jugador
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