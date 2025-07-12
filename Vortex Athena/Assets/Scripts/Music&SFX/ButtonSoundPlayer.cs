using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Componente simple para reproducir sonidos en botones de UI.
/// Se puede agregar directamente a cualquier botón para sonidos automáticos de click.
/// También permite ser llamado manualmente desde otros scripts.
/// </summary>
[RequireComponent(typeof(Button))]
public class ButtonSoundPlayer : MonoBehaviour
{
    [Header("Configuración de Sonido")]
    [SerializeField] private AudioClip clickSound;
    [SerializeField] private AudioClip hoverSound;

    [Header("Configuración de Volumen")]
    [Range(0f, 1f)]
    [SerializeField] private float clickVolume = 1f;
    [Range(0f, 1f)]
    [SerializeField] private float hoverVolume = 0.7f;

    [Header("Configuración de Comportamiento")]
    [SerializeField] private bool playOnClick = true;
    [SerializeField] private bool playOnHover = false;
    [SerializeField] private bool useGlobalSoundManager = true;

    // Referencias a componentes
    private Button button;
    private AudioSource audioSource;

    // Cache para optimización
    private static AudioSource globalAudioSource;

    void Awake()
    {
        // Obtener referencia al botón
        button = GetComponent<Button>();

        // Configurar AudioSource según las preferencias
        SetupAudioSource();

        // Suscribirse a eventos del botón
        SubscribeToButtonEvents();
    }

    /// <summary>
    /// Configura el AudioSource según si usa el global o uno local
    /// </summary>
    private void SetupAudioSource()
    {
        if (useGlobalSoundManager)
        {
            // Crear un AudioSource global compartido para eficiencia
            if (globalAudioSource == null)
            {
                GameObject soundManagerObject = new GameObject("UI_SoundManager");
                globalAudioSource = soundManagerObject.AddComponent<AudioSource>();
                globalAudioSource.playOnAwake = false;
                globalAudioSource.loop = false;
                DontDestroyOnLoad(soundManagerObject);
            }
            audioSource = globalAudioSource;
        }
        else
        {
            // Usar AudioSource local para este botón específico
            audioSource = GetComponent<AudioSource>();
            if (audioSource == null)
            {
                audioSource = gameObject.AddComponent<AudioSource>();
            }

            audioSource.playOnAwake = false;
            audioSource.loop = false;
        }
    }

    /// <summary>
    /// Suscribe los eventos del botón a los métodos de sonido
    /// </summary>
    private void SubscribeToButtonEvents()
    {
        if (button != null)
        {
            // Sonido de click
            if (playOnClick)
            {
                button.onClick.AddListener(PlayClickSound);
            }

            // Sonido de hover (requiere EventTrigger adicional)
            if (playOnHover)
            {
                SetupHoverEvents();
            }
        }
    }

    /// <summary>
    /// Configura los eventos de hover usando EventTrigger
    /// </summary>
    private void SetupHoverEvents()
    {
        UnityEngine.EventSystems.EventTrigger eventTrigger = GetComponent<UnityEngine.EventSystems.EventTrigger>();
        if (eventTrigger == null)
        {
            eventTrigger = gameObject.AddComponent<UnityEngine.EventSystems.EventTrigger>();
        }

        // Crear entrada para PointerEnter (hover)
        UnityEngine.EventSystems.EventTrigger.Entry hoverEntry = new UnityEngine.EventSystems.EventTrigger.Entry();
        hoverEntry.eventID = UnityEngine.EventSystems.EventTriggerType.PointerEnter;
        hoverEntry.callback.AddListener((data) => PlayHoverSound());

        eventTrigger.triggers.Add(hoverEntry);
    }

    /// <summary>
    /// Reproduce el sonido de click del botón
    /// </summary>
    public void PlayClickSound()
    {
        if (clickSound != null && audioSource != null)
        {
            audioSource.PlayOneShot(clickSound, clickVolume);
        }
    }

    /// <summary>
    /// Reproduce el sonido de hover del botón
    /// </summary>
    public void PlayHoverSound()
    {
        if (hoverSound != null && audioSource != null)
        {
            audioSource.PlayOneShot(hoverSound, hoverVolume);
        }
    }

    /// <summary>
    /// Reproduce un sonido personalizado con volumen específico
    /// </summary>
    /// <param name="sound">AudioClip a reproducir</param>
    /// <param name="volume">Volumen de reproducción (0-1)</param>
    public void PlayCustomSound(AudioClip sound, float volume = 1f)
    {
        if (sound != null && audioSource != null)
        {
            audioSource.PlayOneShot(sound, Mathf.Clamp01(volume));
        }
    }

    /// <summary>
    /// Cambia el sonido de click en tiempo de ejecución
    /// </summary>
    /// <param name="newClickSound">Nuevo AudioClip para el click</param>
    public void SetClickSound(AudioClip newClickSound)
    {
        clickSound = newClickSound;
    }

    /// <summary>
    /// Cambia el sonido de hover en tiempo de ejecución
    /// </summary>
    /// <param name="newHoverSound">Nuevo AudioClip para el hover</param>
    public void SetHoverSound(AudioClip newHoverSound)
    {
        hoverSound = newHoverSound;
    }

    /// <summary>
    /// Ajusta el volumen de los sonidos de click
    /// </summary>
    /// <param name="volume">Nuevo volumen (0-1)</param>
    public void SetClickVolume(float volume)
    {
        clickVolume = Mathf.Clamp01(volume);
    }

    /// <summary>
    /// Ajusta el volumen de los sonidos de hover
    /// </summary>
    /// <param name="volume">Nuevo volumen (0-1)</param>
    public void SetHoverVolume(float volume)
    {
        hoverVolume = Mathf.Clamp01(volume);
    }

    void OnDestroy()
    {
        // Limpiar eventos al destruir el objeto
        if (button != null)
        {
            button.onClick.RemoveListener(PlayClickSound);
        }
    }

    // Métodos de debug para el inspector
#if UNITY_EDITOR
    [ContextMenu("Test Click Sound")]
    private void TestClickSound() => PlayClickSound();

    [ContextMenu("Test Hover Sound")]
    private void TestHoverSound() => PlayHoverSound();
#endif
}