using UnityEngine;
using TMPro;
using System;

/// <summary>
/// Sistema de puntuación individual para cada jugador
/// Versión refactorizada con validación estricta y protección contra bugs
/// </summary>
public class PlayerScoreSystem : MonoBehaviour
{
    [Header("Referencias")]
    [SerializeField] private PlayerMain playerMain;
    [SerializeField] private ScoreSystem scoreSystem;

    [Header("UI")]
    [SerializeField] private TMP_Text scoreText;
    [SerializeField] private string scoreFormat = "{0}";

    [Header("UI Adicional (Opcional)")]
    [SerializeField] private TMP_Text killsText;
    [SerializeField] private TMP_Text deathsText;
    [SerializeField] private TMP_Text rankingText;

    [Header("Configuración")]
    [Tooltip("Actualizar UI automáticamente cuando cambie el score")]
    [SerializeField] private bool autoUpdateUI = true;

    [Tooltip("Cooldown mínimo entre actualizaciones de score (previene spam)")]
    [SerializeField] private float updateCooldown = 0.01f;

    [Header("Debug")]
    [SerializeField] private bool enableDebugLogs = true;

    // Estado interno
    private string playerID;
    private float lastUpdateTime = -999f;
    private int lastKnownScore = 0;
    private bool isInitialized = false;

    // Eventos locales
    public event Action<int> OnScoreChanged;
    public event Action<int> OnKillAdded;
    public event Action<int> OnDeathAdded;

    // Propiedades de solo lectura
    public int CurrentScore => GetCurrentScore();
    public int CurrentKills => GetCurrentKills();
    public int CurrentDeaths => GetCurrentDeaths();
    public bool IsInitialized => isInitialized;

    #region Inicialización

    private void Awake()
    {
        if (playerMain == null)
        {
            playerMain = GetComponentInParent<PlayerMain>();
            if (playerMain == null)
                playerMain = GetComponent<PlayerMain>();
        }
    }

    private void Start()
    {
        if (playerMain != null && !isInitialized)
        {
            Initialize(playerMain);
        }
    }

    public bool Initialize(PlayerMain inPlayerMain)
    {
        if (inPlayerMain == null)
        {
            LogError("Initialize: PlayerMain es nulo");
            return false;
        }

        if (inPlayerMain.data == null)
        {
            LogError("Initialize: PlayerMain.data es nulo");
            return false;
        }

        if (isInitialized)
        {
            LogWarning("Ya está inicializado. Ignorando llamada duplicada.");
            return false;
        }

        playerMain = inPlayerMain;
        playerID = playerMain.data.ID;

        if (scoreSystem == null)
        {
            scoreSystem = GameManager.Instance?.ScoreSystem;
        }

        if (scoreSystem == null)
        {
            LogError("Initialize: ScoreSystem no encontrado en GameManager");
            return false;
        }

        if (!scoreSystem.RegisterPlayer(playerMain.data))
        {
            LogWarning("El jugador ya estaba registrado en ScoreSystem");
        }

        scoreSystem.OnScoreChanged += OnGlobalScoreChanged;

        UpdateScoreUI();

        isInitialized = true;

        Log($"✓ PlayerScoreSystem inicializado para {playerMain.data.Name} (ID: {playerID})");

        return true;
    }

    #endregion

    #region Modificación de Score

    /// <summary>
    /// Añade score con validación completa
    /// MÉTODO PRINCIPAL que deben usar otros sistemas
    /// </summary>
    public bool AddScore(int inKills = 0, int inDeaths = 0, int inScore = 0, string reason = "")
    {
        if (!ValidateInitialization())
            return false;

        if (!CheckCooldown())
        {
            LogWarning($"AddScore ignorado: demasiado rápido (cooldown: {updateCooldown}s)");
            return false;
        }

        if (!ValidateScoreDeltas(inKills, inDeaths, inScore))
            return false;

        string fullReason = BuildScoreReason(inKills, inDeaths, inScore, reason);

        bool success = scoreSystem.UpdateScore(playerID, inKills, inDeaths, inScore, fullReason);

        if (success)
        {
            lastUpdateTime = Time.time;

            if (autoUpdateUI)
            {
                UpdateScoreUI();
            }

            if (inKills > 0) OnKillAdded?.Invoke(inKills);
            if (inDeaths > 0) OnDeathAdded?.Invoke(inDeaths);

            Log($"✓ Score actualizado: {fullReason}");
        }
        else
        {
            LogError($"Error al actualizar score: {fullReason}");
        }

        return success;
    }

    public bool AddKill(string reason = "Kill") => AddScore(inKills: 1, reason: reason);
    public bool AddDeath(string reason = "Death") => AddScore(inDeaths: 1, reason: reason);
    public bool AddPoints(int points, string reason = "Bonus") => AddScore(inScore: points, reason: reason);

    public bool ResetScore()
    {
        if (!ValidateInitialization())
            return false;

        bool success = scoreSystem.ResetPlayerScore(playerID);

        if (success && autoUpdateUI)
        {
            UpdateScoreUI();
        }

        return success;
    }

    #endregion

    #region Consultas

    public int GetCurrentScore()
    {
        if (!isInitialized || scoreSystem == null) return 0;
        PlayerScore score = scoreSystem.GetPlayerScore(playerID);
        return score?.Score ?? 0;
    }

    public int GetCurrentKills()
    {
        if (!isInitialized || scoreSystem == null) return 0;
        PlayerScore score = scoreSystem.GetPlayerScore(playerID);
        return score?.Kills ?? 0;
    }

    public int GetCurrentDeaths()
    {
        if (!isInitialized || scoreSystem == null) return 0;
        PlayerScore score = scoreSystem.GetPlayerScore(playerID);
        return score?.Deaths ?? 0;
    }

    public int GetCurrentRanking()
    {
        if (!isInitialized || scoreSystem == null) return -1;
        return scoreSystem.GetPlayerRanking(playerID);
    }

    public float GetKDRatio()
    {
        if (!isInitialized || scoreSystem == null) return 0f;
        PlayerScore score = scoreSystem.GetPlayerScore(playerID);
        return score?.KDRatio ?? 0f;
    }

    #endregion

    #region UI

    public void UpdateScoreUI()
    {
        if (!isInitialized || scoreSystem == null) return;

        PlayerScore currentScore = scoreSystem.GetPlayerScore(playerID);
        if (currentScore == null) return;

        if (scoreText != null)
        {
            scoreText.text = string.Format(scoreFormat, currentScore.Score);
        }

        if (killsText != null)
        {
            killsText.text = currentScore.Kills.ToString();
        }

        if (deathsText != null)
        {
            deathsText.text = currentScore.Deaths.ToString();
        }

        if (rankingText != null)
        {
            int ranking = scoreSystem.GetPlayerRanking(playerID);
            rankingText.text = ranking > 0 ? $"#{ranking}" : "-";
        }

        if (currentScore.Score != lastKnownScore)
        {
            OnScoreChanged?.Invoke(currentScore.Score);
            lastKnownScore = currentScore.Score;
        }
    }

    public void ForceUpdateUI()
    {
        UpdateScoreUI();
    }

    #endregion

    #region Validaciones

    private bool ValidateInitialization()
    {
        if (!isInitialized)
        {
            LogError("Sistema no inicializado. Llama a Initialize() primero.");
            return false;
        }

        if (scoreSystem == null)
        {
            LogError("ScoreSystem es nulo");
            return false;
        }

        if (string.IsNullOrEmpty(playerID))
        {
            LogError("PlayerID es vacío");
            return false;
        }

        return true;
    }

    private bool CheckCooldown()
    {
        return (Time.time - lastUpdateTime) >= updateCooldown;
    }

    private bool ValidateScoreDeltas(int kills, int deaths, int score)
    {
        if (Mathf.Abs(kills) > 10 || Mathf.Abs(deaths) > 10 || Mathf.Abs(score) > 1000)
        {
            LogError($"Valores de score sospechosos: K:{kills} D:{deaths} S:{score}");
            return false;
        }

        if (kills < 0 || deaths < 0)
        {
            LogError($"No se permiten kills/deaths negativos: K:{kills} D:{deaths}");
            return false;
        }

        return true;
    }

    private string BuildScoreReason(int kills, int deaths, int score, string customReason)
    {
        string reason = "";

        if (kills > 0) reason += $"+{kills}K ";
        if (deaths > 0) reason += $"+{deaths}D ";
        if (score != 0) reason += $"{(score >= 0 ? "+" : "")}{score}pts ";
        if (!string.IsNullOrEmpty(customReason)) reason += $"({customReason})";

        return reason.Trim();
    }

    #endregion

    #region Eventos

    private void OnGlobalScoreChanged(string changedPlayerID, ScoreChange change)
    {
        if (changedPlayerID != playerID) return;

        if (autoUpdateUI)
        {
            UpdateScoreUI();
        }
    }

    #endregion

    #region Logging

    private void Log(string message)
    {
        if (!enableDebugLogs) return;
        Debug.Log($"[PlayerScore-{playerMain?.data?.Name ?? "Unknown"}] {message}");
    }

    private void LogWarning(string message)
    {
        Debug.LogWarning($"[PlayerScore-{playerMain?.data?.Name ?? "Unknown"}] ⚠ {message}");
    }

    private void LogError(string message)
    {
        Debug.LogError($"[PlayerScore-{playerMain?.data?.Name ?? "Unknown"}] ✖ {message}");
    }

    #endregion

    #region Lifecycle

    private void OnDestroy()
    {
        if (scoreSystem != null)
        {
            scoreSystem.OnScoreChanged -= OnGlobalScoreChanged;
        }

        OnScoreChanged = null;
        OnKillAdded = null;
        OnDeathAdded = null;
    }

    #endregion

    #region Editor Utilities

#if UNITY_EDITOR
    [ContextMenu("Print Current Score")]
    private void PrintCurrentScore()
    {
        if (!isInitialized)
        {
            Debug.Log("Sistema no inicializado");
            return;
        }

        PlayerScore score = scoreSystem.GetPlayerScore(playerID);
        if (score != null)
        {
            Debug.Log($"=== SCORE DE {playerMain.data.Name} ===\n" +
                     $"Score: {score.Score}\n" +
                     $"Kills: {score.Kills}\n" +
                     $"Deaths: {score.Deaths}\n" +
                     $"K/D: {score.KDRatio:F2}\n" +
                     $"Ranking: #{GetCurrentRanking()}");
        }
    }

    [ContextMenu("Test: Add Kill")]
    private void TestAddKill() => AddKill("Test");

    [ContextMenu("Test: Add Death")]
    private void TestAddDeath() => AddDeath("Test");

    [ContextMenu("Test: Add 50 Points")]
    private void TestAddPoints() => AddPoints(50, "Test");

    [ContextMenu("Test: Reset Score")]
    private void TestResetScore() => ResetScore();
#endif

    #endregion
}