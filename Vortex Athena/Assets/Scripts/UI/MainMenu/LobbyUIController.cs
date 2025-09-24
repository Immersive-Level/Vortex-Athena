using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using Fusion;

public class LobbyUIController : MonoBehaviour
{
    [Header("UI References")]
    [SerializeField] private TMP_InputField _roomCodeInput;
    [SerializeField] private Button _joinButton;
    [SerializeField] private Button _createButton;
    [SerializeField] private Button _startGameButton;
    [SerializeField] private TMP_InputField _roomCodeDisplay;
    [SerializeField] private TMP_Text _errorText;
    [SerializeField] private Transform _playerListContainer;
    [SerializeField] private GameObject _playerEntryPrefab;

    [Header("Scene Settings")]
    [SerializeField] private string _gameSceneName = "GameScene";

    [Header("Managers")]
    [SerializeField] private LobbyManager _lobbyManager;

    void Start()
    {
        _joinButton.onClick.AddListener(() => _lobbyManager.TryJoinLobby(_roomCodeInput.text));
        _createButton.onClick.AddListener(() => _lobbyManager.CreateLobby());
        _startGameButton.onClick.AddListener(() => _lobbyManager.StartGame(_gameSceneName));
    }

    public void SetPlayButtonState(bool inState)
    {
        _startGameButton?.gameObject.SetActive(inState);
    }

    public void ShowRoomCode(string code)
    {
        Debug.Log($"nombre de la sala: {code}");
        _roomCodeDisplay.text = $"{code}";
        _errorText.text = "";
    }

    public void ShowError(string message)
    {
        _errorText.text = message;
    }

    public void UpdatePlayerList(List<PlayerRef> players)
    {
        foreach (Transform child in _playerListContainer)
            Destroy(child.gameObject);

        foreach (var player in players)
        {
            var entry = Instantiate(_playerEntryPrefab, _playerListContainer);
            entry.GetComponentInChildren<TMP_Text>().text = $"Jugador {player.PlayerId}";
        }
    }
}