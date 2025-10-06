using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

/// <summary>
/// Controlador de la UI de configuración de gameplay.
/// Maneja los selectores horizontales de tiempo y habilidades.
/// </summary>
public class GameplaySettings_UI : MonoBehaviour
{
    [Header("Referencias UI - Selectores")]
    [Tooltip("Selector horizontal para el tiempo de juego")]
    public HorizontalSelector selectorTiempo;

    [Tooltip("Selector horizontal para activar/desactivar habilidades")]
    public HorizontalSelector selectorHabilidades;

    [Header("Referencias UI - Botones")]
    [Tooltip("Botón para iniciar el juego con la configuración seleccionada")]
    public Button startButton;

    [Tooltip("Botón para salir/volver al menú anterior")]
    public Button quitButton;

    [Header("Configuración")]
    [Tooltip("ScriptableObject con los tiempos disponibles")]
    public GameplayTimeConfig timeConfig;

    // Opciones fijas para el selector de habilidades
    private readonly string[] opcionesHabilidades = { "OFF", "ON" };

    private void Awake()
    {
        // Validar referencias críticas
        if (timeConfig == null)
        {
            Debug.LogError("GameplaySettings_UI: No se asignó el GameplayTimeConfig", this);
            return;
        }

        // Inicializar selector de habilidades
        InicializarSelectorHabilidades();

        // Inicializar selector de tiempo
        InicializarSelectorTiempo();

        // Configurar botones
        if (startButton != null)
            startButton.onClick.AddListener(OnStartClicked);
        else
            Debug.LogWarning("GameplaySettings_UI: Start Button no asignado", this);

        if (quitButton != null)
            quitButton.onClick.AddListener(OnQuitClicked);
        else
            Debug.LogWarning("GameplaySettings_UI: Quit Button no asignado", this);
    }

    /// <summary>
    /// Configura el selector de habilidades con las opciones ON/OFF
    /// </summary>
    private void InicializarSelectorHabilidades()
    {
        if (selectorHabilidades == null)
        {
            Debug.LogWarning("GameplaySettings_UI: Selector de habilidades no asignado", this);
            return;
        }

        // Establecer opciones OFF/ON (índice 0 = OFF, índice 1 = ON)
        selectorHabilidades.EstablecerOpciones(opcionesHabilidades, 1); // Por defecto ON (índice 1)
        selectorHabilidades.permitirLoop = true; // Permitir loop entre ON y OFF
    }

    /// <summary>
    /// Configura el selector de tiempo con las opciones del ScriptableObject
    /// </summary>
    private void InicializarSelectorTiempo()
    {
        if (selectorTiempo == null)
        {
            Debug.LogWarning("GameplaySettings_UI: Selector de tiempo no asignado", this);
            return;
        }

        // Generar opciones de texto desde el config
        string[] opcionesTiempo = new string[timeConfig.CantidadOpciones];
        for (int i = 0; i < timeConfig.CantidadOpciones; i++)
        {
            opcionesTiempo[i] = timeConfig.GetTextoTiempo(i);
        }

        // Establecer opciones (índice 0 como default - primer tiempo disponible)
        selectorTiempo.EstablecerOpciones(opcionesTiempo, 0);
        selectorTiempo.permitirLoop = true; // Permitir loop entre tiempos
    }

    /// <summary>
    /// Callback cuando se presiona el botón Start
    /// </summary>
    private void OnStartClicked()
    {
        // Validar que tengamos los selectores configurados
        if (selectorTiempo == null || selectorHabilidades == null)
        {
            Debug.LogError("GameplaySettings_UI: Selectores no configurados correctamente", this);
            return;
        }

        // Obtener tiempo seleccionado desde el config usando el índice
        float tiempoSeleccionado = timeConfig.GetTiempo(selectorTiempo.IndiceActual);

        // Obtener estado de habilidades (índice 0 = OFF = false, índice 1 = ON = true)
        bool usarHabilidades = selectorHabilidades.IndiceActual == 1;

        // Log para debug (remover en producción si es necesario)
        Debug.Log($"Iniciando juego - Tiempo: {tiempoSeleccionado}s, Habilidades: {usarHabilidades}");

        // Llamar al GameManager con la configuración seleccionada
        if (GameManager.Instance != null)
        {
            GameManager.Instance.StartGame(tiempoSeleccionado, usarHabilidades);
        }
        else
        {
            Debug.LogError("GameplaySettings_UI: GameManager.Instance no encontrado", this);
        }
    }

    /// <summary>
    /// Callback cuando se presiona el botón Quit
    /// </summary>
    private void OnQuitClicked()
    {
        // Volver a la escena anterior (índice 1)
        SceneManager.LoadScene(1);
    }

    private void OnDestroy()
    {
        // Limpiar listeners de botones
        if (startButton != null)
            startButton.onClick.RemoveListener(OnStartClicked);

        if (quitButton != null)
            quitButton.onClick.RemoveListener(OnQuitClicked);
    }
}