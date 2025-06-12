using UnityEngine;
using TMPro;

/// <summary>
/// Sistema de puntuación individual para cada jugador
/// Reemplaza al GameManager centralizado para permitir múltiples jugadores
/// </summary>
public class PlayerScoreSystem : MonoBehaviour
{
    private PlayerMain playerMain;
    private ScoreSystem scoreSystem;

    [Header("UI")]
    public TMP_Text scoreText;
    public string scoreFormat = "Puntos: {0}";

    public void Initialize(PlayerMain inPlayerMain)
    {
        scoreSystem = GameManager.Instance?.ScoreSystem;
        playerMain = inPlayerMain;

        if (scoreSystem != null && playerMain != null)
        {
            scoreSystem.RegisterPlayer(playerMain.data);
            UpdateScoreUI();
        }
    }

    public void AddScore(int inKills = 0, int inDeaths = 0, int inScore = 0)
    {
        if ( scoreSystem == null) return;

        // Actualizar puntuación en el sistema global
        scoreSystem.UpdateScore(playerMain.data.ID, inKills, inDeaths, inScore);
        UpdateScoreUI();

    }

    private void UpdateScoreUI()
    {
        if (scoreText != null && scoreSystem != null)
        {
            int currentScore = scoreSystem.GetPlayerScore(playerMain.data.ID)?.Score ?? 0;
            scoreText.text = string.Format(scoreFormat, currentScore);
        }
    }
}
