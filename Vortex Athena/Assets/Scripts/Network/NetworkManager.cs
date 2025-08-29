using System.Collections.Generic;
using System.Threading.Tasks;
using UnityEngine;
using Fusion;

public class NetworkManager : MonoBehaviour
{
    public static NetworkManager Instance { get; private set; }

    [Header("Connection Settings")]
    [SerializeField] private bool _autoConnect = true;
    [SerializeField] private bool _createPrivateRoom = true;
    [SerializeField] private string _roomName = "DevRoom";
    [SerializeField] private int _maxPlayers = 4;

    [Header("Player Settings")]
    [SerializeField] private GameObject _playerPrefab;
    [SerializeField] private bool _spawnPlayer = true;
    [SerializeField] private Vector3 _p1StartLoc;

    [Header("Debug")]
    [SerializeField] private bool _showDebugLogs = true;

    private NetworkRunner _runner;
    private Dictionary<PlayerRef, NetworkObject> _spawnedPlayers = new();

    public bool IsConnected => _runner != null && _runner.IsRunning;
    public bool IsHost => _runner != null && _runner.IsSharedModeMasterClient;
    public NetworkRunner Runner => _runner;

    #region Unity Life Cycle

    void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;
        DontDestroyOnLoad(gameObject);
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

    #region Connection Logic

    public async Task<bool> StartConnection()
    {
        if (IsConnected)
        {
            LogDebug("Ya está conectado");
            return false;
        }

        LogDebug("Iniciando conexión");

        _runner = GetOrAddComponent<NetworkRunner>();
        _runner.ProvideInput = true;

        // Delegar callbacks a handler externo
        var handler = GetOrAddComponent<NetworkCallbacksHandler>();
        _runner.AddCallbacks(handler);

        var startArgs = new StartGameArgs()
        {
            GameMode = GameMode.Shared,
            SessionName = GenerateRoomName()
        };

        var result = await _runner.StartGame(startArgs);

        if (result.Ok)
        {
            LogDebug($"Conectado exitosamente a: {startArgs.SessionName}");
            return true;
        }
        //else
        Debug.LogError($"Error de conexión: {result.ShutdownReason}");
        return false;
    }

    public async Task Disconnect()
    {
        if (_runner != null && _runner.IsRunning)
        {
            LogDebug("Desconectando");
            await _runner.Shutdown();
        }
    }

    public async Task Reconnect()
    {
        LogDebug("Reconectando");
        await Disconnect();
        await Task.Delay(500);
        await StartConnection();
    }

    string GenerateRoomName()
    {
        return _createPrivateRoom
            ? $"{_roomName}_Private_{Random.Range(10000, 99999)}"
            : _roomName;
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

    public async Task<bool> TryJoinRoom(string roomCode)
    {
        if (string.IsNullOrEmpty(roomCode))
        {
            Debug.LogWarning("Código de sala vacío");
            return false;
        }

        _roomName = roomCode;
        _createPrivateRoom = false;

        var result = await StartConnection();
        return result;
    }

    public async Task<bool> CreateRoom()
    {
        _roomName = GenerateRoomName();
        _createPrivateRoom = true;

        var result = await StartConnection();
        return result;
    }

    public void LoadGameScene(string sceneName)
    {
        if (!IsHost)
        {
            Debug.LogWarning("Solo el host puede cargar escenas en modo Shared");
            return;
        }

        _runner.LoadScene(sceneName);

    }

    #endregion

    #region Public API

    public void HandlePlayerJoined(PlayerRef player)
    {
        LogDebug($"Jugador {player} se unió");

        if (_spawnPlayer && _playerPrefab != null && IsHost)
        {
            var obj = _runner.Spawn(_playerPrefab, _p1StartLoc, Quaternion.identity, player);
            _spawnedPlayers[player] = obj;

            LogDebug($"Player instanciado en {_p1StartLoc}");
        }
    }

    public void HandlePlayerLeft(PlayerRef player)
    {
        LogDebug($"Jugador {player} se desconectó");

        if (_spawnedPlayers.TryGetValue(player, out var obj))
        {
            if (obj != null)
                _runner.Despawn(obj);

            _spawnedPlayers.Remove(player);
        }
    }

    public void HandleShutdown(ShutdownReason reason)
    {
        LogDebug($"Shutdown: {reason}");
        _spawnedPlayers.Clear();
    }

    public NetworkObject SpawnNetworkObject(GameObject prefab, Vector3 position, Quaternion rotation, PlayerRef? player = null)
    {
        if (!IsConnected)
        {
            LogDebug("No conectado, no se puede hacer spawn");
            return null;
        }

        return _runner.Spawn(prefab, position, rotation, player);
    }

    #endregion

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
        var comp = GetComponent<T>();
        return comp != null ? comp : gameObject.AddComponent<T>();
    }

    #endregion

    #region Editor Tools

#if UNITY_EDITOR
    [Header("Editor Tools")]
    [SerializeField] private bool _editorFoldout = false;

    void OnValidate()
    {
        if (string.IsNullOrEmpty(_roomName))
            _roomName = "DevRoom";

        if (_maxPlayers < 1)
            _maxPlayers = 1;
    }
#endif

    #endregion
}