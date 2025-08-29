using Fusion;
using System.Collections.Generic;
using UnityEngine;

public class LobbyManager : MonoBehaviour
{
    [SerializeField] private LobbyUIController _ui;

    private List<PlayerRef> _connectedPlayers = new();

    void Start()
    {
        NetworkCallbacksHandler.OnPlayerJoinedGlobal += OnPlayerJoined;
        NetworkCallbacksHandler.OnPlayerLeftGlobal += OnPlayerLeft;
    }

    void OnDestroy()
    {
        NetworkCallbacksHandler.OnPlayerJoinedGlobal -= OnPlayerJoined;
        NetworkCallbacksHandler.OnPlayerLeftGlobal -= OnPlayerLeft;
    }

    void OnPlayerJoined(PlayerRef player)
    {
        _connectedPlayers.Add(player);
        _ui.UpdatePlayerList(_connectedPlayers);
    }

    void OnPlayerLeft(PlayerRef player)
    {
        _connectedPlayers.Remove(player);
        _ui.UpdatePlayerList(_connectedPlayers);
    }

    public async void TryJoinLobby(string code)
    {
        bool success = await NetworkManager.Instance.TryJoinRoom(code);
        if (!success)
        {
            _ui.ShowError("No se pudo unir a la sala. ¿Código correcto?");
        }
    }

    public async void CreateLobby()
    {
        bool success = await NetworkManager.Instance.CreateRoom();
        if (success)
        {
            _ui.ShowRoomCode(NetworkManager.Instance.Runner.SessionInfo.Name);
            _ui.SetPlayButtonState(success);
        }
        else
        {
            _ui.ShowError("Error al crear la sala");
        }
    }

    public void StartGame(string sceneName)
    {
        if (NetworkManager.Instance.IsHost)
        {
            NetworkManager.Instance.LoadGameScene(sceneName);
        }
        else
        {
            _ui.ShowError("Solo el host puede iniciar la partida");
        }
    }

}
