using UnityEngine;

/// <summary>
/// Gestor de música de fondo persistente entre escenas.
/// Se auto-destruye si ya existe una instancia para evitar duplicados.
/// Mantiene la música reproduciéndose continuamente hasta el cierre de la aplicación.
/// </summary>
public class MusicManager : MonoBehaviour
{
    [Header("Configuración de Música")]
    [SerializeField] private AudioClip backgroundMusic;
    [SerializeField] private bool playOnAwake = true;

    [Header("Configuración de Audio")]
    [Range(0f, 1f)]
    [SerializeField] private float volume = 0.5f;
    [Range(-3f, 3f)]
    [SerializeField] private float pitch = 1f;

    // Instancia estática para el patrón Singleton
    private static MusicManager instance;

    // Referencia al componente AudioSource
    private AudioSource audioSource;

    /// <summary>
    /// Propiedad pública para acceder a la instancia del MusicManager
    /// </summary>
    public static MusicManager Instance => instance;

    /// <summary>
    /// Propiedad para controlar el volumen de la música
    /// </summary>
    public float Volume
    {
        get => audioSource != null ? audioSource.volume : volume;
        set
        {
            volume = Mathf.Clamp01(value);
            if (audioSource != null)
                audioSource.volume = volume;
        }
    }

    /// <summary>
    /// Verifica si la música está reproduciéndose actualmente
    /// </summary>
    public bool IsPlaying => audioSource != null && audioSource.isPlaying;

    void Awake()
    {
        // Implementación del patrón Singleton
        if (instance == null)
        {
            instance = this;
            DontDestroyOnLoad(gameObject);
            InitializeMusicManager();
        }
        else
        {
            // Si ya existe una instancia, destruir este objeto duplicado
            Destroy(gameObject);
        }
    }

    /// <summary>
    /// Inicializa el componente AudioSource y configura la música
    /// </summary>
    private void InitializeMusicManager()
    {
        // Obtener o crear el componente AudioSource
        audioSource = GetComponent<AudioSource>();
        if (audioSource == null)
        {
            audioSource = gameObject.AddComponent<AudioSource>();
        }

        // Configurar el AudioSource
        ConfigureAudioSource();

        // Reproducir música si está configurado para hacerlo
        if (playOnAwake && backgroundMusic != null)
        {
            PlayMusic();
        }
    }

    /// <summary>
    /// Configura las propiedades del AudioSource
    /// </summary>
    private void ConfigureAudioSource()
    {
        audioSource.clip = backgroundMusic;
        audioSource.loop = true;
        audioSource.playOnAwake = false;
        audioSource.volume = volume;
        audioSource.pitch = pitch;
    }

    /// <summary>
    /// Inicia la reproducción de la música de fondo
    /// </summary>
    public void PlayMusic()
    {
        if (audioSource != null && backgroundMusic != null && !audioSource.isPlaying)
        {
            audioSource.Play();
        }
    }

    /// <summary>
    /// Pausa la música de fondo
    /// </summary>
    public void PauseMusic()
    {
        if (audioSource != null && audioSource.isPlaying)
        {
            audioSource.Pause();
        }
    }

    /// <summary>
    /// Reanuda la música de fondo si estaba pausada
    /// </summary>
    public void ResumeMusic()
    {
        if (audioSource != null && !audioSource.isPlaying)
        {
            audioSource.UnPause();
        }
    }

    /// <summary>
    /// Detiene completamente la música de fondo
    /// </summary>
    public void StopMusic()
    {
        if (audioSource != null)
        {
            audioSource.Stop();
        }
    }

    /// <summary>
    /// Cambia la música de fondo por otra nueva
    /// </summary>
    /// <param name="newMusic">El nuevo AudioClip a reproducir</param>
    /// <param name="fadeTransition">Si debe hacer una transición suave (no implementado en esta versión simple)</param>
    public void ChangeMusic(AudioClip newMusic, bool fadeTransition = false)
    {
        if (newMusic == null) return;

        backgroundMusic = newMusic;

        if (audioSource != null)
        {
            audioSource.Stop();
            audioSource.clip = newMusic;
            audioSource.Play();
        }
    }

    /// <summary>
    /// Silencia o des-silencia la música
    /// </summary>
    /// <param name="mute">True para silenciar, false para des-silenciar</param>
    public void SetMute(bool mute)
    {
        if (audioSource != null)
        {
            audioSource.mute = mute;
        }
    }

    void OnDestroy()
    {
        // Limpiar la referencia estática si este objeto se destruye
        if (instance == this)
        {
            instance = null;
        }
    }

    // Métodos de debug para el inspector (solo en builds de desarrollo)
#if UNITY_EDITOR
    [ContextMenu("Play Music")]
    private void DebugPlayMusic() => PlayMusic();

    [ContextMenu("Pause Music")]
    private void DebugPauseMusic() => PauseMusic();

    [ContextMenu("Stop Music")]
    private void DebugStopMusic() => StopMusic();
#endif
}