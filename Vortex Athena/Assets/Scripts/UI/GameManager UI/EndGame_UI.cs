using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

/// <summary>
/// Controlador de la UI de fin de juego.
/// Responsabilidad: Manejar la pantalla de fin de partida y botones de navegación.
/// </summary>
public class EndGame_UI : MonoBehaviour
{
    [Header("Botones")]
    public Button RestartButton;
    public Button QuitButton;

    [Header("Referencias opcionales")]
    [Tooltip("Panel de la tabla de puntajes (opcional, se activa automáticamente)")]
    public GameObject ScoreboardPanel;

    private void Start()
    {
        if (RestartButton != null)
        {
            RestartButton.onClick.AddListener(OnRestartPressed);
        }

        if (QuitButton != null)
        {
            QuitButton.onClick.AddListener(OnQuitPressed);
        }
    }

    private void OnEnable()
    {
        if (GameManager.Instance != null)
        {
            GameManager.Instance.OnGameStateChanged += OnGameStateChanged;
        }
    }

    private void OnDisable()
    {
        if (GameManager.Instance != null)
        {
            GameManager.Instance.OnGameStateChanged -= OnGameStateChanged;
        }
    }

    private void OnGameStateChanged()
    {
        var newState = GameManager.Instance?.CurrentState;
        gameObject.SetActive(newState == GameState.InGameEnd);

        if (newState == GameState.InGameEnd && ScoreboardPanel != null)
        {
            ScoreboardPanel.SetActive(true);
        }
    }

    /// <summary>
    /// Reinicia la partida recargando la escena actual
    /// </summary>
    public void OnRestartPressed()
    {
        Time.timeScale = 1f;
        int sceneIndex = SceneManager.GetActiveScene().buildIndex;
        SceneManager.LoadScene(sceneIndex);
    }

    /// <summary>
    /// Regresa al menú principal recargando la escena
    /// </summary>
    public void OnQuitPressed()
    {
        Time.timeScale = 1f;
        SceneManager.LoadScene("MainMenu");
    }
}