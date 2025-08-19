using System.Collections.Generic;
using System.Threading.Tasks;
using UnityEngine;
using Fusion;
using Fusion.Sockets;
using System;

public class NetworkManager : MonoBehaviour //INetworkRunnerCallbacks
{
    [Header("Connection Settings")]
    [SerializeField] private bool _autoConnect = true;
    [SerializeField] private bool _createPrivateRoom = true;
    [SerializeField] private string _roomName = "DevRoom";
    [SerializeField] private int _maxPlayers = 4;

    [Header("Player Settings")]
    [SerializeField] private GameObject _playerPrefab;
    [SerializeField] private bool _spawnPlayer = true;

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

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    #endregion
}
