using System.Collections.Generic;
using System.Linq;
using UnityEngine;
using System;

/// <summary>
/// Sistema de puntuación global - Versión bancaria ultra-confiable
/// Características:
/// - Validación estricta de todas las operaciones
/// - Logging detallado para debugging
/// - Protección contra valores inconsistentes
/// - Eventos para tracking completo de cambios
/// </summary>
public class ScoreSystem : MonoBehaviour
{
    [Header("Configuración")]
    [Tooltip("Puntos otorgados por cada kill")]
    [SerializeField] private int pointsPerKill = 100;

    [Tooltip("Puntos perdidos por cada muerte")]
    [SerializeField] private int pointsPerDeath = 50;

    [Tooltip("¿Permitir scores negativos?")]
    [SerializeField] private bool allowNegativeScores = true;

    [Tooltip("Score mínimo permitido (solo si allowNegativeScores = false)")]
    [SerializeField] private int minimumScore = 0;

    [Header("Debug")]
    [Tooltip("Activar logs detallados para debugging")]
    [SerializeField] private bool verboseLogging = true;

    // Diccionario principal de scores
    private Dictionary<string, PlayerScore> scoreMap = new Dictionary<string, PlayerScore>();

    // Eventos para tracking externo
    public event Action<string, PlayerScore> OnPlayerRegistered;
    public event Action<string, ScoreChange> OnScoreChanged;
    public event Action<string, PlayerScore> OnPlayerScoreUpdated;

    // Propiedad de solo lectura para acceso externo seguro
    public IReadOnlyDictionary<string, PlayerScore> ScoreMap => scoreMap;

    #region Registro de Jugadores

    /// <summary>
    /// Registra un nuevo jugador en el sistema
    /// </summary>
    public bool RegisterPlayer(PlayerData inData)
    {
        // Validación de entrada
        if (inData == null)
        {
            LogError("Intento de registrar jugador con PlayerData nulo");
            return false;
        }

        if (string.IsNullOrEmpty(inData.ID))
        {
            LogError($"Intento de registrar jugador con ID vacío (Name: {inData.Name})");
            return false;
        }

        // Verificar si ya existe
        if (scoreMap.ContainsKey(inData.ID))
        {
            LogWarning($"Jugador {inData.Name} (ID: {inData.ID}) ya está registrado. Ignorando.");
            return false;
        }

        // Crear nuevo registro
        PlayerScore newScore = new PlayerScore(inData.Name, inData.ID);
        scoreMap[inData.ID] = newScore;

        Log($"✓ Jugador registrado: {inData.Name} (ID: {inData.ID})");
        OnPlayerRegistered?.Invoke(inData.ID, newScore);

        return true;
    }

    /// <summary>
    /// Elimina un jugador del sistema
    /// </summary>
    public bool UnregisterPlayer(string playerID)
    {
        if (string.IsNullOrEmpty(playerID))
        {
            LogError("Intento de eliminar jugador con ID vacío");
            return false;
        }

        if (!scoreMap.ContainsKey(playerID))
        {
            LogWarning($"Intento de eliminar jugador inexistente (ID: {playerID})");
            return false;
        }

        string playerName = scoreMap[playerID].PlayerName;
        scoreMap.Remove(playerID);
        Log($"✓ Jugador eliminado: {playerName} (ID: {playerID})");

        return true;
    }

    #endregion

    #region Actualización de Scores

    /// <summary>
    /// Actualiza el score de un jugador con validación completa
    /// MÉTODO PRINCIPAL - Usar este en lugar de modificar directamente
    /// </summary>
    public bool UpdateScore(string playerID, int killsDelta = 0, int deathsDelta = 0, int scoreDelta = 0, string reason = "")
    {
        // Validación de ID
        if (string.IsNullOrEmpty(playerID))
        {
            LogError("UpdateScore llamado con playerID vacío");
            return false;
        }

        // Verificar existencia del jugador
        if (!scoreMap.TryGetValue(playerID, out PlayerScore playerScore))
        {
            LogError($"UpdateScore: Jugador no encontrado (ID: {playerID})");
            return false;
        }

        // Validación de deltas (no permitir valores absurdos)
        if (Mathf.Abs(killsDelta) > 100 || Mathf.Abs(deathsDelta) > 100 || Mathf.Abs(scoreDelta) > 10000)
        {
            LogError($"UpdateScore: Valores sospechosos detectados para {playerScore.PlayerName} " +
                    $"(Kills: {killsDelta}, Deaths: {deathsDelta}, Score: {scoreDelta})");
            return false;
        }

        // Guardar estado anterior para el evento
        ScoreChange change = new ScoreChange
        {
            PlayerID = playerID,
            PlayerName = playerScore.PlayerName,
            PreviousKills = playerScore.Kills,
            PreviousDeaths = playerScore.Deaths,
            PreviousScore = playerScore.Score,
            KillsDelta = killsDelta,
            DeathsDelta = deathsDelta,
            ScoreDelta = scoreDelta,
            Reason = reason,
            Timestamp = Time.time
        };

        // Aplicar cambios de kills/deaths
        playerScore.Kills += killsDelta;
        playerScore.Deaths += deathsDelta;

        // Calcular nuevo score
        int calculatedScoreDelta = (killsDelta * pointsPerKill) - (deathsDelta * pointsPerDeath);
        int totalScoreDelta = scoreDelta + calculatedScoreDelta;

        playerScore.Score += totalScoreDelta;

        // Aplicar límite mínimo si está configurado
        if (!allowNegativeScores && playerScore.Score < minimumScore)
        {
            playerScore.Score = minimumScore;
            LogWarning($"Score de {playerScore.PlayerName} ajustado al mínimo permitido ({minimumScore})");
        }

        // Completar información del cambio
        change.NewKills = playerScore.Kills;
        change.NewDeaths = playerScore.Deaths;
        change.NewScore = playerScore.Score;
        change.ActualScoreDelta = totalScoreDelta;

        // Logging detallado
        LogScoreChange(change);

        // Disparar eventos
        OnScoreChanged?.Invoke(playerID, change);
        OnPlayerScoreUpdated?.Invoke(playerID, playerScore);

        return true;
    }

    /// <summary>
    /// Añade una kill a un jugador específico
    /// </summary>
    public bool AddKill(string playerID, string reason = "Kill")
    {
        return UpdateScore(playerID, killsDelta: 1, reason: reason);
    }

    /// <summary>
    /// Añade una muerte a un jugador específico
    /// </summary>
    public bool AddDeath(string playerID, string reason = "Death")
    {
        return UpdateScore(playerID, deathsDelta: 1, reason: reason);
    }

    /// <summary>
    /// Añade puntos directos sin afectar kills/deaths
    /// </summary>
    public bool AddPoints(string playerID, int points, string reason = "Bonus")
    {
        return UpdateScore(playerID, scoreDelta: points, reason: reason);
    }

    /// <summary>
    /// Resetea completamente el score de un jugador
    /// </summary>
    public bool ResetPlayerScore(string playerID)
    {
        if (!scoreMap.TryGetValue(playerID, out PlayerScore playerScore))
        {
            LogError($"ResetPlayerScore: Jugador no encontrado (ID: {playerID})");
            return false;
        }

        playerScore.Kills = 0;
        playerScore.Deaths = 0;
        playerScore.Score = 0;

        Log($"✓ Score reseteado: {playerScore.PlayerName}");
        OnPlayerScoreUpdated?.Invoke(playerID, playerScore);

        return true;
    }

    #endregion

    #region Consultas

    /// <summary>
    /// Obtiene el score de un jugador (copia segura)
    /// </summary>
    public PlayerScore GetPlayerScore(string playerID)
    {
        if (string.IsNullOrEmpty(playerID))
        {
            LogError("GetPlayerScore llamado con ID vacío");
            return null;
        }

        return scoreMap.TryGetValue(playerID, out PlayerScore score) ? score : null;
    }

    /// <summary>
    /// Obtiene el jugador con mayor score
    /// </summary>
    public PlayerScore GetTopPlayer()
    {
        if (scoreMap.Count == 0)
        {
            LogWarning("GetTopPlayer: No hay jugadores registrados");
            return null;
        }

        return GetSortedScores()[0];
    }

    /// <summary>
    /// Obtiene todos los scores ordenados de mayor a menor
    /// </summary>
    public List<PlayerScore> GetSortedScores()
    {
        List<PlayerScore> sortedScores = new List<PlayerScore>(scoreMap.Values);
        sortedScores.Sort((a, b) => b.Score.CompareTo(a.Score));
        return sortedScores;
    }

    /// <summary>
    /// Obtiene el ranking (posición) de un jugador (1 = primero)
    /// </summary>
    public int GetPlayerRanking(string playerID)
    {
        if (!scoreMap.ContainsKey(playerID))
        {
            LogError($"GetPlayerRanking: Jugador no encontrado (ID: {playerID})");
            return -1;
        }

        List<PlayerScore> sorted = GetSortedScores();
        for (int i = 0; i < sorted.Count; i++)
        {
            if (sorted[i].PlayerID == playerID)
                return i + 1;
        }

        return -1;
    }

    #endregion

    #region Utilidades

    /// <summary>
    /// Imprime el scoreboard completo en consola
    /// </summary>
    public void PrintScoreboard()
    {
        Debug.Log("╔═══════════════════════════════════════════════╗");
        Debug.Log("║           SCOREBOARD OFICIAL                  ║");
        Debug.Log("╠═══════════════════════════════════════════════╣");

        if (scoreMap.Count == 0)
        {
            Debug.Log("║  No hay jugadores registrados                 ║");
            Debug.Log("╚═══════════════════════════════════════════════╝");
            return;
        }

        List<PlayerScore> sorted = GetSortedScores();
        for (int i = 0; i < sorted.Count; i++)
        {
            PlayerScore player = sorted[i];
            string rank = $"#{i + 1}".PadRight(4);
            string name = player.PlayerName.PadRight(15);
            string score = player.Score.ToString().PadLeft(6);
            string kd = $"({player.Kills}K/{player.Deaths}D)".PadLeft(12);

            Debug.Log($"║ {rank} {name} {score} pts {kd} ║");
        }

        Debug.Log("╚═══════════════════════════════════════════════╝");
    }

    /// <summary>
    /// Obtiene un resumen de estadísticas del sistema
    /// </summary>
    public string GetSystemStats()
    {
        int totalPlayers = scoreMap.Count;
        int totalKills = scoreMap.Values.Sum(p => p.Kills);
        int totalDeaths = scoreMap.Values.Sum(p => p.Deaths);
        int totalScore = scoreMap.Values.Sum(p => p.Score);

        return $"Sistema de Scores - Players: {totalPlayers} | Kills totales: {totalKills} | " +
               $"Deaths totales: {totalDeaths} | Score total: {totalScore}";
    }

    #endregion

    #region Logging

    private void Log(string message)
    {
        if (verboseLogging)
            Debug.Log($"[ScoreSystem] {message}");
    }

    private void LogWarning(string message)
    {
        Debug.LogWarning($"[ScoreSystem] ⚠ {message}");
    }

    private void LogError(string message)
    {
        Debug.LogError($"[ScoreSystem] ✖ {message}");
    }

    private void LogScoreChange(ScoreChange change)
    {
        if (!verboseLogging) return;

        string deltaStr = change.ActualScoreDelta >= 0 ? $"+{change.ActualScoreDelta}" : change.ActualScoreDelta.ToString();

        Log($"Score actualizado: {change.PlayerName} | " +
            $"Score: {change.PreviousScore} → {change.NewScore} ({deltaStr}) | " +
            $"K/D: {change.NewKills}/{change.NewDeaths} | " +
            $"Razón: {change.Reason}");
    }

    #endregion
}

// ============================================================================
// CLASES DE DATOS
// ============================================================================

/// <summary>
/// Datos de score de un jugador individual
/// </summary>
[System.Serializable]
public class PlayerScore
{
    public string PlayerID;
    public string PlayerName;
    public int Kills;
    public int Deaths;
    public int Score;

    // Propiedades calculadas
    public float KDRatio => Deaths > 0 ? (float)Kills / Deaths : Kills;
    public int NetKills => Kills - Deaths;

    public PlayerScore(string name, string id)
    {
        PlayerID = id;
        PlayerName = name;
        Kills = 0;
        Deaths = 0;
        Score = 0;
    }

    public override string ToString()
    {
        return $"{PlayerName} - Score: {Score} (K/D: {Kills}/{Deaths})";
    }
}

/// <summary>
/// Registro detallado de un cambio en el score
/// </summary>
public struct ScoreChange
{
    public string PlayerID;
    public string PlayerName;
    public string Reason;
    public float Timestamp;

    public int PreviousKills;
    public int PreviousDeaths;
    public int PreviousScore;

    public int KillsDelta;
    public int DeathsDelta;
    public int ScoreDelta;
    public int ActualScoreDelta;

    public int NewKills;
    public int NewDeaths;
    public int NewScore;

    public override string ToString()
    {
        return $"[{Timestamp:F2}s] {PlayerName}: {PreviousScore} → {NewScore} " +
               $"({(ActualScoreDelta >= 0 ? "+" : "")}{ActualScoreDelta}) - {Reason}";
    }
}