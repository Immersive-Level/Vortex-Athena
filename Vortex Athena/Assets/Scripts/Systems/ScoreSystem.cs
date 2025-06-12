using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class PlayerScore
{
    public string PlayerName;
    public int Kills;
    public int Deaths;
    public int Score;

    public PlayerScore(string name)
    {
        PlayerName = name;
        Kills = 0;
        Deaths = 0;
        Score = 0;
    }
}

public class ScoreSystem : MonoBehaviour
{
    public Dictionary<string, PlayerScore> ScoreMap = new();

    public void RegisterPlayer(PlayerData inData)
    {
        if (!ScoreMap.ContainsKey(inData.ID))
        {
            ScoreMap[inData.ID] = new PlayerScore(inData.Name);
        }
    }

    public void UpdateScore(string inID, int killsDelta = 0, int deathsDelta = 0, int scoreDelta = 0)
    {
        if (ScoreMap.TryGetValue(inID, out PlayerScore playerScore))
        {
            playerScore.Kills += killsDelta;
            playerScore.Deaths += deathsDelta;
            playerScore.Score += scoreDelta + (killsDelta * 100) - (deathsDelta * 50);
        }
    }

    public PlayerScore GetPlayerScore(string inID)
    {
        return ScoreMap.TryGetValue(inID, out PlayerScore player) ? player : null;
    }

    public PlayerScore GetTopPlayer()
    {
        if (ScoreMap.Count == 0) return null;
        return GetSortedScores()[0];
    }

    private List<PlayerScore> GetSortedScores()
    {
        List<PlayerScore> sortedScores = new List<PlayerScore>(ScoreMap.Values);
        sortedScores.Sort((a, b) => b.Score.CompareTo(a.Score)); // Ordenar de mayor a menor
        return sortedScores;
    }

    public void PrintScores()
    {
        Debug.Log("=== SCOREBOARD ===");
        foreach (var player in GetSortedScores())
        {
            Debug.Log($"{player.PlayerName} - Puntos: {player.Score} (Kills: {player.Kills}, Deaths: {player.Deaths})");
        }
    }
}