using UnityEngine;
using TMPro;

/// <summary>
/// Componente simple que representa una fila en la tabla de puntajes.
/// Responsabilidad: Mostrar los datos de un jugador individual.
/// </summary>
public class ScoreboardRow : MonoBehaviour
{
    [Header("Referencias UI")]
    [Tooltip("Texto para la posición del jugador (#1, #2, etc)")]
    public TextMeshProUGUI PositionText;

    [Tooltip("Texto para el nombre del jugador")]
    public TextMeshProUGUI PlayerNameText;

    [Tooltip("Texto para los kills")]
    public TextMeshProUGUI KillsText;

    [Tooltip("Texto para las muertes")]
    public TextMeshProUGUI DeathsText;

    [Tooltip("Texto para el puntaje total")]
    public TextMeshProUGUI ScoreText;

    /// <summary>
    /// Configura los datos de esta fila con la información del jugador
    /// </summary>
    /// <param name="position">Posición en el ranking (1, 2, 3...)</param>
    /// <param name="playerScore">Datos del jugador</param>
    public void Setup(int position, PlayerScore playerScore)
    {
        if (PositionText != null)
            PositionText.text = $"#{position}";

        if (PlayerNameText != null)
            PlayerNameText.text = playerScore.PlayerName;

        if (KillsText != null)
            KillsText.text = playerScore.Kills.ToString();

        if (DeathsText != null)
            DeathsText.text = playerScore.Deaths.ToString();

        if (ScoreText != null)
            ScoreText.text = playerScore.Score.ToString();
    }

    /// <summary>
    /// Aplica un color especial para destacar posiciones (ej: oro para 1er lugar)
    /// </summary>
    public void SetHighlightColor(Color color)
    {
        if (PositionText != null)
            PositionText.color = color;

        if (ScoreText != null)
            ScoreText.color = color;
    }
}