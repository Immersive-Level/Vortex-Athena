using Fusion;
using Fusion.Sockets;
using System;
using System.Collections.Generic;
using UnityEngine;

public class NetworkCallbacksHandler : MonoBehaviour, INetworkRunnerCallbacks
{

    public static event Action<PlayerRef> OnPlayerJoinedGlobal;
    public static event Action<PlayerRef> OnPlayerLeftGlobal;

    public void OnPlayerJoined(NetworkRunner runner, PlayerRef player)
    {
        NetworkManager.Instance?.HandlePlayerJoined(player);
        OnPlayerJoinedGlobal?.Invoke(player);

    }

    public void OnPlayerLeft(NetworkRunner runner, PlayerRef player)
    {
        NetworkManager.Instance?.HandlePlayerLeft(player);
        OnPlayerLeftGlobal?.Invoke(player);
    }

    public void OnShutdown(NetworkRunner runner, ShutdownReason shutdownReason)
    {
        NetworkManager.Instance?.HandleShutdown(shutdownReason);
    }

    public void OnConnectedToServer(NetworkRunner runner) => Debug.Log("[Callbacks] Conectado al servidor");
    public void OnDisconnectedFromServer(NetworkRunner runner) => Debug.Log("[Callbacks] Desconectado del servidor");

    // Callbacks vacíos que puedes implementar luego
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
}