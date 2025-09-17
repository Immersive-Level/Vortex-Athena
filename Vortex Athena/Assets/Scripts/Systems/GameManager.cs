using Fusion;
using UnityEngine;
using System;
using System.Collections.Generic;
using UnityEngine.PlayerLoop;

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
    [Networked]
    public float GameDuration { get; private set; }
    [Networked]
    private float GameStartTime { get; set; }
    public float Gametime => Runner.SimulationTime - GameStartTime;

    public event Action OnGameStateChanged;

    public List<GameObject> NavesActivas { get; private set; } = new();
    public GameObject TutorialRoot;

    public ScoreSystem ScoreSystem { get; private set; }

    [Header("Tutorial")]
    [SerializeField] private bool tutorialCompletado = false;

    // Propiedades p�blicas para InicioNave
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
    }

    private void Start()
    {
        NavesActivas = new List<GameObject>();

        // Mostrar tutorial si no est� completado
        if (!tutorialCompletado && TutorialRoot != null)
        {
            TutorialRoot.SetActive(true);
            Time.timeScale = 0;
        }
        if (NetworkManager.Instance != null)
        {
            NetworkManager.Instance.OnConnectionReady += HandleConnectionReady;
        }
    }

    public override void Spawned()
    {
        SetState(GameState.InMenu);
        Log("Spawned!");
    }
    private void Update()
    {
        if (CurrentState != GameState.InGame) return;

        if (Gametime >= GameDuration)
        {
            EndGame();
        }
    }

    private void HandleConnectionReady()
    {
        if (Object == null || !Object.IsValid)
        {
            if (NetworkManager.Instance.IsHost)
            {
                Log("Spawneando GameManager tras conexi�n...");
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
        Time.timeScale = 1f;
        if (TutorialRoot != null)
            TutorialRoot.SetActive(false);
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
        if (inShip != null && !NavesActivas.Contains(inShip))
            NavesActivas.Add(inShip);
    }

    public void RemoveRegisterShip(GameObject inShip)
    {
        if (inShip != null)
            NavesActivas.Remove(inShip);
    }

    /// <summary>
    /// Alterna el tutorial - Las naves se manejan autom�ticamente
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

            // Las naves se desactivar�n autom�ticamente cuando el estado cambie a InGame
            // InicioNave maneja esto en OnGameStateChanged
        }
        else
        {
            // Abrir tutorial
            Time.timeScale = 0f;
            TutorialRoot.SetActive(true);
        }
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
    #endregion
}