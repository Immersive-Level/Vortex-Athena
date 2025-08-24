using System.Collections.Generic;
using System.Threading.Tasks;
using UnityEngine;
using Fusion;
using Fusion.Sockets;
using System;

public class NetworkManager : MonoBehaviour, INetworkRunnerCallbacks
{
    [Header("Connection Settings")]
    [SerializeField] private bool _autoConnect = true;
    [SerializeField] private bool _createPrivateRoom = true;
    [SerializeField] private string _roomName = "DevRoom";
    [SerializeField] private int _maxPlayers = 4;

    [Header("Player Settings")]
    [SerializeField] private GameObject _playerPrefab;
    [SerializeField] private bool _spawnPlayer = true;
    [SerializeField] Vector3 _p1StartLoc;

    [Header("Debug")]
    [SerializeField] private bool _showDebugLogs = true;

    public static NetworkManager Instance { get; private set; }

    private NetworkRunner _runner;
    private Dictionary<PlayerRef, NetworkObject> _spawnedPlayers = new Dictionary<PlayerRef, NetworkObject>();

    //Estados publicos para otros scripts
    public bool IsConnected => _runner != null && _runner.IsRunning;
    public bool IsHost => _runner != null && _runner.IsServer;
    public NetworkRunner Runner => _runner;

    #region Unity Life Cycle
    void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        else
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
    }

    async void Start()
    {
        if (_autoConnect)
        {
            await StartConnection();
        }
    }

    private void OnDestroy()
    {
        if (_runner != null && _runner.IsRunning)
        {
            _runner.Shutdown();
        }
    }
    #endregion

    public async Task StartConnection()
    {
        if (IsConnected)
        {
            Debug.Log("Ya esta conectado");
            return;
        }

        Debug.Log("Iniciando conexion");

        //Crear runner si no existe
        if (_runner == null)
        {
            _runner = gameObject.GetComponent<NetworkRunner>();
            if (_runner == null)
            {
                _runner = gameObject.AddComponent<NetworkRunner>();
            }
        }

        //Config runner
        _runner.ProvideInput = true;

        _runner.AddCallbacks(this);

        var startArgs = new StartGameArgs()
        {
            GameMode = GameMode.Shared,
            SessionName = GenerateRoomName()
        };

        //Iniciar conexion
        var result = await _runner.StartGame(startArgs);

        if (result.Ok)
        {
            Debug.Log($"Conectado exitosamente a: {startArgs.SessionName}");
        }
        else
        {
            Debug.LogError($"Error de conexion: {result.ShutdownReason}");
        }
    }

    public async Task Disconnect()
    {
        if (_runner != null && _runner.IsRunning)
        {
            Debug.Log("Desconectando");
            await _runner.Shutdown();
        }
    }

    public async Task Reconnect()
    {
        Debug.Log("Reconectando");
        await Disconnect();
        await Task.Delay(500); //small pause
        await StartConnection();
    }

    string GenerateRoomName()
    {
        if (_createPrivateRoom)
        {
            return $"{_roomName}_Private_{UnityEngine.Random.Range(10000, 99999)}";
        }
        else
        {
            return _roomName;
        }
    }

    public async Task JoinSpecificRoom(string roomName)
    {
        _roomName = roomName;
        _createPrivateRoom = false;
        await Reconnect();
    }

    public async Task CreatePrivateRoom(string customRoomName = null)
    {
        if (!string.IsNullOrEmpty(customRoomName))
        {
            _roomName = customRoomName;
        }
        _createPrivateRoom = true;
        await Reconnect();
    }

    //----Fusion Callbacks----//
    public void OnPlayerJoined(NetworkRunner runner, PlayerRef player)
    {
        Debug.Log($"Jugador {player} se unio");

        if (_spawnPlayer && _playerPrefab != null && runner.IsServer)
        {
            //Vector3 spawnPos = GetSpawnPosition(); //Por ahora default en vector2 de P1
            NetworkObject playerObj = runner.Spawn(_playerPrefab, _p1StartLoc, Quaternion.identity, player);
            _spawnedPlayers[player] = playerObj;

            Debug.Log($"Player spawned en {_p1StartLoc}");
        }
    }

    public void OnPlayerLeft(NetworkRunner runner, PlayerRef player)
    {
        Debug.Log($"Jugador {player} se desconecto");

        if (_spawnedPlayers.TryGetValue(player, out NetworkObject playerObj))
        {
            if (playerObj != null)
            {
                runner.Despawn(playerObj);
            }
            _spawnedPlayers.Remove(player);
        }
    }

    public void OnConnectedToServer(NetworkRunner runner)
    {
        Debug.Log("Conectado al servidor Photon");
    }

    public void OnDisconnectedFromServer(NetworkRunner runner)
    {
        Debug.Log("Desconectado del servidor");
    }

    //-----Spawn Management------//
    public void OnShutdown(NetworkRunner runner, ShutdownReason shutdownReason)
    {
        Debug.Log($"Shutdown: {shutdownReason}");
    }

    public NetworkObject SpawnNetworkObject(GameObject prefab, Vector3 position, Quaternion rotation, PlayerRef? player = null)
    {
        if (!IsConnected)
        {
            Debug.Log("No conectado, no se puede hacer spawn");
            return null;
        }

        return _runner.Spawn(prefab, position, rotation, player);
    }

    #region Utility

    void LogDebug(string message)
    {
        if (_showDebugLogs)
        {
            Debug.Log($"[NetworkManager] {message}");
        }
    }

    T GetOrAddComponent<T>() where T : Component
    {
        T component = GetComponent<T>();
        if (component == null)
        {
            component = gameObject.AddComponent<T>();
        }
        return component;
    }

    #endregion

    #region Public API (Para expandir funcionalidad)

    /// <summary>
    /// Conecta manualmente (útil si AutoConnect está desactivado)
    /// </summary>
    [ContextMenu("Connect")]
    public void Connect()
    {
        _ = StartConnection();
    }

    /// <summary>
    /// Desconecta manualmente
    /// </summary>
    [ContextMenu("Disconnect")]
    public void DisconnectManual()
    {
        _ = Disconnect();
    }

    /// <summary>
    /// Reconecta manualmente
    /// </summary>
    [ContextMenu("Reconnect")]
    public void ReconnectManual()
    {
        _ = Reconnect();
    }

    #endregion

    #region Required Fusion Callbacks (Vacíos)

    public void OnConnectFailed(NetworkRunner runner, NetAddress remoteAddress, NetConnectFailedReason reason) { }
    public void OnConnectRequest(NetworkRunner runner, NetworkRunnerCallbackArgs.ConnectRequest request, byte[] token) { }
    public void OnCustomAuthenticationResponse(NetworkRunner runner, Dictionary<string, object> data) { }
    public void OnHostMigration(NetworkRunner runner, HostMigrationToken hostMigrationToken) { }
    public void OnInput(NetworkRunner runner, NetworkInput input) { }
    public void OnInputMissing(NetworkRunner runner, PlayerRef player, NetworkInput input) { }
    public void OnReliableDataReceived(NetworkRunner runner, PlayerRef player, ArraySegment<byte> data) { }
    public void OnSceneLoadDone(NetworkRunner runner) { }
    public void OnSceneLoadStart(NetworkRunner runner) { }
    public void OnSessionListUpdated(NetworkRunner runner, List<SessionInfo> sessionList) { }
    public void OnUserSimulationMessage(NetworkRunner runner, SimulationMessagePtr message) { }
    public void OnObjectExitAOI(NetworkRunner runner, NetworkObject networkObject, PlayerRef player) { }
    public void OnObjectEnterAOI(NetworkRunner runner, NetworkObject networkObject, PlayerRef player) { }
    public void OnDisconnectedFromServer(NetworkRunner runner, NetDisconnectReason reason) { }
    public void OnReliableDataReceived(NetworkRunner runner, PlayerRef player, ReliableKey reliableKey, ArraySegment<byte> vs) { }
    public void OnReliableDataProgress(NetworkRunner runner, PlayerRef player, ReliableKey reliableKey, float progress) { }

    #endregion

    #region Editor Helpers

#if UNITY_EDITOR
    [Header("Editor Tools")]
    [Space]
    [UnityEngine.SerializeField] private bool _editorFoldout = false;

    void OnValidate()
    {
        // Validaciones en editor
        if (string.IsNullOrEmpty(_roomName))
        {
            _roomName = "DevRoom";
        }

        if (_maxPlayers < 1)
        {
            _maxPlayers = 1;
        }
    }
#endif

    #endregion
}
