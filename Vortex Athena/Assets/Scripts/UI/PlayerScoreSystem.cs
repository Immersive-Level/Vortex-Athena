using UnityEngine;
using TMPro; // Importamos TextMeshPro

/// <summary>
/// Sistema de puntuación individual para cada jugador
/// Reemplaza al GameManager centralizado para permitir múltiples jugadores
/// </summary>
public class PlayerScoreSystem : MonoBehaviour
{
    [Header("Puntuación")]
    [Tooltip("Puntuación actual del jugador")]
    public int score = 0;

    [Tooltip("Componente TextMeshPro para mostrar puntuación")]
    public TMP_Text scoreText;

    [Tooltip("Formato del texto de puntuación")]
    public string scoreFormat = "Puntos: {0}";

    [Header("Efectos")]
    [Tooltip("Efecto al ganar puntos")]
    public GameObject scoreEffect;

    [Tooltip("Sonido al ganar puntos")]
    public AudioClip scoreSound;

    [Header("Identificación")]
    [Tooltip("ID del jugador (de 1 a 4)")]
    public int playerID = 1;

    private void Start()
    {
        // Inicializar puntuación
        UpdateScoreUI();
    }

    /// <summary>
    /// Añade puntos a la puntuación del jugador
    /// </summary>
    /// <param name="points">Cantidad de puntos a añadir</param>
    public void AddScore(int points)
    {
        if (points <= 0) return;

        score += points;
        UpdateScoreUI();

        // Efectos visuales y sonoros
        if (scoreEffect != null)
        {
            Instantiate(scoreEffect, transform.position, Quaternion.identity);
        }

        if (scoreSound != null)
        {
            AudioSource.PlayClipAtPoint(scoreSound, transform.position);
        }
    }

    /// <summary>
    /// Actualiza el texto de puntuación en la UI
    /// </summary>
    private void UpdateScoreUI()
    {
        if (scoreText != null)
        {
            scoreText.text = string.Format(scoreFormat, score);
        }
    }

    /// <summary>
    /// Obtiene la puntuación actual del jugador
    /// </summary>
    public int GetScore()
    {
        return score;
    }
}
