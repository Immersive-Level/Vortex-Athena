using UnityEngine;

/// <summary>
/// Escucha el GameManager y enciende/apaga los AMBIENTES (AX) según el estado del juego.
/// </summary>
public class AudioStateBridge : MonoBehaviour
{
    [Header("Ambientes")]
    [Tooltip("Hook que ya hace fade vía Mixer (EntrarGameplay / SalirGameplay).")]
    [SerializeField] private GameplayAmbienceHook ambienceHook;

    // Si prefieres llamar directo a tu reproductor de ambientes:
    [Tooltip("Alternativa directa: si no usas el hook, referencia al componente AmbienceLayers.")]
    [SerializeField] private AmbienceLayers ambienceDirect;
    [SerializeField] private bool usarLlamadaDirecta = false;

    void Awake()
    {
        // Suscribirse al cambio de estado del juego
        if (GameManager.Instance != null)
            GameManager.Instance.OnGameStateChanged += OnGameStateChanged;
    }

    void OnDestroy()
    {
        if (GameManager.Instance != null)
            GameManager.Instance.OnGameStateChanged -= OnGameStateChanged;
    }

    void Start()
    {
        // Alinear el audio con el estado actual al entrar a la escena
        if (GameManager.Instance != null)
            OnGameStateChanged();
    }

    private void OnGameStateChanged()
    {
        var state = GameManager.Instance.CurrentState;
        switch (state)
        {
            case GameState.InGame:
                EncenderAmbientes();
                break;

            case GameState.InMenu:
            case GameState.InGameEnd:
            default:
                ApagarAmbientes();
                break;
        }
    }

    private void EncenderAmbientes()
    {
        if (usarLlamadaDirecta)
        {
            // Llamada directa (sin fade del Mixer)
            ambienceDirect?.Play();
        }
        else
        {
            // Usa el hook con fade por Mixer
            ambienceHook?.EntrarGameplay();
        }
    }

    private void ApagarAmbientes()
    {
        if (usarLlamadaDirecta)
        {
            ambienceDirect?.Stop();
        }
        else
        {
            ambienceHook?.SalirGameplay();
        }
    }
}

