using Fusion;
using UnityEngine;
using System;
using System.Collections.Generic;

public enum GameState : byte
{
    InMenu,
    InGame,
    InGameEnd
}

public class GameManager : NetworkBehaviour
{
    public static GameManager Instance { get; private set; }

    [Networked, OnChangedRender(nameof(OnStateChanged))]
    public GameState CurrentState { get; private set; }

    [Networked]
    public bool UseAbilities { get; private set; }

    [Networked] public float GameDuration { get; private set; }
    [Networked] private float GameStartTime { get; set; }

    public float Gametime => Runner.SimulationTime - GameStartTime;

    public event Action OnGameStateChanged;

    public List<GameObject> NavesActivas { get; private set; } = new();
    public GameObject TutorialRoot;

    public ScoreSystem ScoreSystem { get; private set; }

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }
        Instance = this;
    }

    private void Start()
    {
        if (NetworkManager.Instance != null)
        {
            NetworkManager.Instance.OnConnectionReady += HandleConnectionReady;
        }
    }

    public override void Spawned()
    {
        Log("Spawned!");

        if (Object.HasStateAuthority)
        {
            SetState(GameState.InMenu);
        }

        if (TutorialRoot != null && !Runner.IsSharedModeMasterClient)
        {
            ToggleTutorial();
        }
    }

    private void HandleConnectionReady()
    {
        if (Object == null || !Object.IsValid)
        {
            if (NetworkManager.Instance.IsHost)
            {
                Log("Spawneando GameManager tras conexión...");
                NetworkManager.Instance.Runner.Spawn(gameObject);
            }
        }
    }

    public void StartGame(float duration, bool abilitiesEnabled)
    {
        if (!Object.HasStateAuthority) return;

        GameDuration = duration;
        UseAbilities = abilitiesEnabled;
        GameStartTime = Runner.SimulationTime;

        SetState(GameState.InGame);
    }

    public void EndGame()
    {
        if (!Object.HasStateAuthority) return;
        SetState(GameState.InGameEnd);
    }

    public void ReturnToMenu()
    {
        if (!Object.HasStateAuthority) return;
        SetState(GameState.InMenu);
    }

    public void SetState(GameState newState)
    {
        if (!Object.HasStateAuthority || newState == CurrentState) return;
        CurrentState = newState;
    }

    private void OnStateChanged()
    {
        OnGameStateChanged?.Invoke();
        Log($" Estado cambiado a: {CurrentState}");
    }

    public void RegisterShip(GameObject inShip)
    {
        if (inShip != null)
        {
            NavesActivas.Add(inShip);
        }
    }

    public void RemoveRegisterShip(GameObject inShip)
    {
        if (inShip != null)
        {
            NavesActivas.Remove(inShip);
        }
    }

    public void ToggleTutorial()
    {
        Time.timeScale = Time.timeScale == 0 ? 1 : 0;
        TutorialRoot.SetActive(!TutorialRoot.activeInHierarchy);
    }

    #region extra
    private void Log(string inMessage, UnityEngine.LogType inType = UnityEngine.LogType.Log)
    {
        inMessage = $"<color=orange>[GameManager]</color>" + inMessage;
        switch (inType)
        {
            case UnityEngine.LogType.Error:
                Debug.LogError(inMessage);
                break;

            case UnityEngine.LogType.Warning:
                Debug.LogWarning(inMessage);
                break;

            default:
                Debug.Log(inMessage);
                break;
        }
    }
    #endregion
}