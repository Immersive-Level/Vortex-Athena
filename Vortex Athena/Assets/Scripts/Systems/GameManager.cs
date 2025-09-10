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

    //[Networked(OnChanged = nameof(OnStateChanged))]
    public GameState CurrentState { get; private set; }

    //[Networked(OnChanged = nameof(OnUseAbilitiesChanged))]
    public bool UseAbilities { get; private set; }

    [Networked] public float GameDuration { get; private set; }
    [Networked] private float GameStartTime { get; set; }

    public float Gametime => Runner.SimulationTime - GameStartTime;

    public event Action<GameState> OnGameStateChanged;

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
        DontDestroyOnLoad(gameObject);
    }

    public override void Spawned()
    {
        if (Object.HasStateAuthority)
        {
            SetState(GameState.InMenu);
        }

        if (TutorialRoot != null && !Runner.IsSharedModeMasterClient)
        {
            ToggleTutorial();
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

    //private static void OnStateChanged(Changed<GameManager> changed)
    //{
    //    changed.Behaviour.OnGameStateChanged?.Invoke(changed.Behaviour.CurrentState);
    //    Debug.Log($"Estado cambiado a: {changed.Behaviour.CurrentState}");
    //}

    //private static void OnUseAbilitiesChanged(Changed<GameManager> changed)
    //{
    //    Debug.Log($"UseAbilities cambiado a: {changed.Behaviour.UseAbilities}");
    //}

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
}