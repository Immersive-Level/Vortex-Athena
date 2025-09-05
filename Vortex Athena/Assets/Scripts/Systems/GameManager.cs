using System;
using System.Collections.Generic;
using UnityEngine;

public enum GameState
{
    InMenu,
    InGame,
    InGameEnd
}

public class GameManager : MonoBehaviour
{
    public static GameManager Instance { get; private set; }

    public GameState CurrentState { get; private set; }
    public event Action<GameState> OnGameStateChanged;

    [Header("Sistemas hijos")]
    public ScoreSystem ScoreSystem;

    public List<GameObject> NavesActivas { get; private set; } = new();

    [SerializeField] bool isMultiplayer;
    public GameObject TutorialRoot;

    [HideInInspector] public float GameDuration = 60f;
    private float GameStartTime;
    public float Gametime { get; private set; }
    [HideInInspector] public bool UseAbilities = true;


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

    private void Start()
    {
        SetState(GameState.InMenu);

        NavesActivas = new List<GameObject>();

        if (TutorialRoot != null)
        {
            if (!isMultiplayer)
                ToggleTutorial();
        }
    }

    private void Update()
    {
        if (CurrentState != GameState.InGame)
        {
            return;
        }

        Gametime = Time.time - GameStartTime;
        if (Gametime >= GameDuration)
        {
            EndGame();
        }
    }

    public void SetState(GameState newState)
    {
        if (newState == CurrentState) return;

        CurrentState = newState;
        Debug.Log($"Estado cambiado a: {newState}");
        OnGameStateChanged?.Invoke(newState);
    }

    public void StartGame(float duration, bool abilitiesEnabled)
    {
        GameDuration = duration;
        UseAbilities = abilitiesEnabled;

        GameStartTime = Time.time;

        SetState(GameState.InGame);
    }

    public void EndGame()
    {
        SetState(GameState.InGameEnd);
    }

    public void ReturnToMenu()
    {
        SetState(GameState.InMenu);
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
        if (Time.timeScale != 0)
            Time.timeScale = 0;
        else
            Time.timeScale = 1;

        if (!TutorialRoot.activeInHierarchy)
            TutorialRoot.SetActive(true);
        else
            TutorialRoot.SetActive(false);
    }
}