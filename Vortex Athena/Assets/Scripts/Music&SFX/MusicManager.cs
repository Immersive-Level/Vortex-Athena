using UnityEngine;

/// <summary>
/// Gestor de m�sica de fondo persistente entre escenas.
/// Se auto-destruye si ya existe una instancia para evitar duplicados.
/// Mantiene la m�sica reproduci�ndose continuamente hasta el cierre de la aplicaci�n.
/// </summary>
public class MusicManager : MonoBehaviour
{
    [Header("Configuraci�n de M�sica")]
    [SerializeField] private AudioClip backgroundMusic;
    [SerializeField] private bool playOnAwake = true;

    [Header("Configuraci�n de Audio")]
    [Range(0f, 1f)]
    [SerializeField] private float volume = 0.5f;
    [Range(-3f, 3f)]
    [SerializeField] private float pitch = 1f;

    // Instancia est�tica para el patr�n Singleton
    private static MusicManager instance;

    // Referencia al componente AudioSource
    private AudioSource audioSource;

    /// <summary>
    /// Propiedad p�blica para acceder a la instancia del MusicManager
    /// </summary>
    public static MusicManager Instance => instance;

    /// <summary>
    /// Propiedad para controlar el volumen de la m�sica
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
    /// Verifica si la m�sica est� reproduci�ndose actualmente
    /// </summary>
    public bool IsPlaying => audioSource != null && audioSource.isPlaying;

    void Awake()
    {
        // Implementaci�n del patr�n Singleton
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
    /// Inicializa el componente AudioSource y configura la m�sica
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

        // Reproducir m�sica si est� configurado para hacerlo
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
    /// Inicia la reproducci�n de la m�sica de fondo
    /// </summary>
    public void PlayMusic()
    {
        if (audioSource != null && backgroundMusic != null && !audioSource.isPlaying)
        {
            audioSource.Play();
        }
    }

    /// <summary>
    /// Pausa la m�sica de fondo
    /// </summary>
    public void PauseMusic()
    {
        if (audioSource != null && audioSource.isPlaying)
        {
            audioSource.Pause();
        }
    }

    /// <summary>
    /// Reanuda la m�sica de fondo si estaba pausada
    /// </summary>
    public void ResumeMusic()
    {
        if (audioSource != null && !audioSource.isPlaying)
        {
            audioSource.UnPause();
        }
    }

    /// <summary>
    /// Detiene completamente la m�sica de fondo
    /// </summary>
    public void StopMusic()
    {
        if (audioSource != null)
        {
            audioSource.Stop();
        }
    }

    /// <summary>
    /// Cambia la m�sica de fondo por otra nueva
    /// </summary>
    /// <param name="newMusic">El nuevo AudioClip a reproducir</param>
    /// <param name="fadeTransition">Si debe hacer una transici�n suave (no implementado en esta versi�n simple)</param>
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
    /// Silencia o des-silencia la m�sica
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
        // Limpiar la referencia est�tica si este objeto se destruye
        if (instance == this)
        {
            instance = null;
        }
    }

    // M�todos de debug para el inspector (solo en builds de desarrollo)
#if UNITY_EDITOR
    [ContextMenu("Play Music")]
    private void DebugPlayMusic() => PlayMusic();

    [ContextMenu("Pause Music")]
    private void DebugPauseMusic() => PauseMusic();

    [ContextMenu("Stop Music")]
    private void DebugStopMusic() => StopMusic();
#endif
}