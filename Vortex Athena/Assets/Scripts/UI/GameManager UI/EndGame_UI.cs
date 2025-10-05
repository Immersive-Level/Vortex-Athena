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
        // Configurar listeners de botones
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
        // Suscribirse al evento de cambio de estado
        if (GameManager.Instance != null)
        {
            GameManager.Instance.OnGameStateChanged += OnGameStateChanged;
        }
    }

    private void OnDisable()
    {
        // Desuscribirse para evitar memory leaks
        if (GameManager.Instance != null)
        {
            GameManager.Instance.OnGameStateChanged -= OnGameStateChanged;
        }
    }

    /// <summary>
    /// Listener del evento de cambio de estado del juego
    /// </summary>
    private void OnGameStateChanged(GameState newState)
    {
        // Mostrar/ocultar este panel según el estado
        gameObject.SetActive(newState == GameState.InGameEnd);

        // Activar el panel de scoreboard si existe
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
        Time.timeScale = 1f; // Asegurar que el tiempo esté normal
        int sceneIndex = SceneManager.GetActiveScene().buildIndex;
        SceneManager.LoadScene(sceneIndex);
    }

    /// <summary>
    /// Regresa al menú principal
    /// </summary>
    public void OnQuitPressed()
    {
        Time.timeScale = 1f; // Asegurar que el tiempo esté normal

        // Opción 1: Por nombre de escena
        SceneManager.LoadScene("Main Menu");

        // Opción 2: O puedes usar el GameManager para regresar al menú
        // if (GameManager.Instance != null)
        // {
        //     GameManager.Instance.ReturnToMenu();
        // }
    }
}