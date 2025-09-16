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
    public GameObject TutorialRoot;

    // Hacer GameDuration público para que BlackHole pueda accederlo
    public float GameDuration { get; private set; } = 60f;
    private float GameStartTime;
    public float Gametime { get; private set; }
    [HideInInspector] public bool UseAbilities = true;

    [Header("Tutorial")]
    [SerializeField] private bool tutorialCompletado = false;

    // Propiedades públicas para InicioNave
    public bool TutorialCompletado => tutorialCompletado;
    public bool SkipTutorialEnabled => tutorialCompletado; // Simplificado: mismo valor

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

        // Mostrar tutorial si no está completado
        if (!tutorialCompletado && TutorialRoot != null)
        {
            TutorialRoot.SetActive(true);
            Time.timeScale = 0;
        }
    }

    private void Update()
    {
        if (CurrentState != GameState.InGame)
            return;

        Gametime = Time.time - GameStartTime;
        if (Gametime >= GameDuration)
            EndGame();
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

        Debug.Log($"Iniciando juego con duración: {GameDuration} segundos");

        SetState(GameState.InGame);
    }

    public void EndGame()
    {
        SetState(GameState.InGameEnd);
    }

    public void ReturnToMenu()
    {
        Time.timeScale = 1f;
        if (TutorialRoot != null)
            TutorialRoot.SetActive(false);
        SetState(GameState.InMenu);
    }

    public void RegisterShip(GameObject inShip)
    {
        if (inShip != null && !NavesActivas.Contains(inShip))
            NavesActivas.Add(inShip);
    }

    public void RemoveRegisterShip(GameObject inShip)
    {
        if (inShip != null)
            NavesActivas.Remove(inShip);
    }

    /// <summary>
    /// Alterna el tutorial - Las naves se manejan automáticamente
    /// </summary>
    public void ToggleTutorial()
    {
        if (TutorialRoot == null) return;

        bool tutorialActivo = TutorialRoot.activeInHierarchy;

        if (tutorialActivo)
        {
            // Cerrar tutorial
            Time.timeScale = 1f;
            TutorialRoot.SetActive(false);
            tutorialCompletado = true;

            // Las naves se desactivarán automáticamente cuando el estado cambie a InGame
            // InicioNave maneja esto en OnGameStateChanged
        }
        else
        {
            // Abrir tutorial
            Time.timeScale = 0f;
            TutorialRoot.SetActive(true);
        }
    }

    /// <summary>
    /// Obtiene el tiempo restante del juego
    /// </summary>
    public float GetRemainingTime()
    {
        if (CurrentState != GameState.InGame) return GameDuration;
        return Mathf.Max(0f, GameDuration - Gametime);
    }

    /// <summary>
    /// Obtiene el progreso del juego (0-1)
    /// </summary>
    public float GetGameProgress()
    {
        if (CurrentState != GameState.InGame) return 0f;
        return Mathf.Clamp01(Gametime / GameDuration);
    }
}