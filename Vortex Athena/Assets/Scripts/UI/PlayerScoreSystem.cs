using UnityEngine;
using TMPro; // Importamos TextMeshPro

/// <summary>
/// Sistema de puntuaci�n individual para cada jugador
/// Reemplaza al GameManager centralizado para permitir m�ltiples jugadores
/// </summary>
public class PlayerScoreSystem : MonoBehaviour
{
    [Header("Puntuaci�n")]
    [Tooltip("Puntuaci�n actual del jugador")]
    public int score = 0;

    [Tooltip("Componente TextMeshPro para mostrar puntuaci�n")]
    public TMP_Text scoreText;

    [Tooltip("Formato del texto de puntuaci�n")]
    public string scoreFormat = "Puntos: {0}";

    [Header("Efectos")]
    [Tooltip("Efecto al ganar puntos")]
    public GameObject scoreEffect;

    [Tooltip("Sonido al ganar puntos")]
    public AudioClip scoreSound;

    [Header("Identificaci�n")]
    [Tooltip("ID del jugador (de 1 a 4)")]
    public int playerID = 1;

    private void Start()
    {
        // Inicializar puntuaci�n
        UpdateScoreUI();
    }

    /// <summary>
    /// A�ade puntos a la puntuaci�n del jugador
    /// </summary>
    /// <param name="points">Cantidad de puntos a a�adir</param>
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
    /// Actualiza el texto de puntuaci�n en la UI
    /// </summary>
    private void UpdateScoreUI()
    {
        if (scoreText != null)
        {
            scoreText.text = string.Format(scoreFormat, score);
        }
    }

    /// <summary>
    /// Obtiene la puntuaci�n actual del jugador
    /// </summary>
    public int GetScore()
    {
        return score;
    }
}
