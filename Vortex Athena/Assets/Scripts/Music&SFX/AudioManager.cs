using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Audio;

[AddComponentMenu("Audio/AudioManager")]
[DisallowMultipleComponent]
public class AudioManager : MonoBehaviour
{
    // =======================
    // CONFIGURACIÓN GENERAL
    // =======================

    [Header("Mixer (asset)")]
    [Tooltip("Arrastra aquí tu asset 'AudioMixer' desde el Project.")]
    public AudioMixer mixer;                 // AudioMixer 

    [Header("Nombres de parámetros EXPUESTOS en el Mixer (dB)")]
    [Tooltip("Parámetro expuesto en MASTER (ej: MasterVol)")]
    public string masterParam = "MasterVol";
    [Tooltip("Parámetro expuesto en el grupo MUS (ej: MUSVol)")]
    public string musParam = "MUSVol";
    [Tooltip("Parámetro expuesto en el grupo SFX (ej: SFXVol)")]
    public string sfxParam = "SFXVol";
    [Tooltip("Parámetro expuesto en el grupo AX (ambiente)")]
    public string axParam = "AXVol";
    [Tooltip("Parámetro expuesto en el grupo UI")]
    public string uiParam = "UIVol";
    [Tooltip("Parámetro expuesto en el grupo VO (voice-over)")]
    public string voParam = "VOVol";

    [Header("Salidas del Mixer (opcional pero recomendado)")]
    [Tooltip("Grupo MUS del AudioMixer (para música).")]
    public AudioMixerGroup MUS;
    [Tooltip("Grupo SFX del AudioMixer (para efectos).")]
    public AudioMixerGroup SFX;
    [Tooltip("Grupo AX del AudioMixer (ambiente).")]
    public AudioMixerGroup AX;
    [Tooltip("Grupo UI del AudioMixer (sonidos de interfaz).")]
    public AudioMixerGroup UI;
    [Tooltip("Grupo VO del AudioMixer (locuciones).")]
    public AudioMixerGroup VO;

    [Header("Pool de SFX")]
    [Tooltip("Cantidad de AudioSources para reproducir efectos en paralelo.")]
    public int sfxPoolSize = 8;

    // =======================
    // CAMPOS INTERNOS
    // =======================

    private AudioSource musicSrc;          // fuente dedicada a música (loop)
    private List<AudioSource> sfxPool;     // fuentes reutilizables para SFX

    // =======================
    // CICLO DE VIDA
    // =======================

    private void Awake()
    {
        // --- Fuente para música (loop infinito, 2D) ---
        musicSrc = gameObject.AddComponent<AudioSource>();
        musicSrc.playOnAwake = false;
        musicSrc.loop = true;
        musicSrc.spatialBlend = 0f;              // 0 = 2D
        if (MUS != null) musicSrc.outputAudioMixerGroup = MUS;

        // --- Pool de SFX (varias fuentes 2D) ---
        sfxPool = new List<AudioSource>(sfxPoolSize);
        for (int i = 0; i < sfxPoolSize; i++)
        {
            var child = new GameObject("SFX_" + i);
            child.transform.SetParent(transform);
            var src = child.AddComponent<AudioSource>();
            src.playOnAwake = false;
            src.loop = false;
            src.spatialBlend = 0f;               // efectos 2D en sandbox
            if (SFX != null) src.outputAudioMixerGroup = SFX;
            sfxPool.Add(src);
        }

        // Valores por defecto (lineal 0..1). El método convierte a dB.
        SetMasterVolume(1f);
        SetMUSVolume(1f);
        SetSFXVolume(1f);
        SetAXVolume(1f);
        SetUIVolume(1f);
        SetVOVolume(1f);
    }

    // =======================
    // API: MÚSICA
    // =======================

    /// <summary>
    /// Reproduce un clip de música en loop (canal MUS).
    /// Llamar con un botón de prueba desde UI.
    /// </summary>
    public void PlayMusic(AudioClip clip, float volume = 1f, float pitch = 1f)
    {
        if (clip == null) return;
        musicSrc.clip = clip;
        musicSrc.volume = Mathf.Clamp01(volume);
        musicSrc.pitch = pitch;
        musicSrc.Play();
    }

    /// <summary>Detiene la música actual.</summary>
    public void StopMusic() => musicSrc.Stop();

    // =======================
    // API: EFECTOS (SFX)
    // =======================

    /// <summary>
    /// Reproduce un SFX una sola vez (no bloquea otros, usa el pool).
    /// Ideal para asignar directo desde botones en sandbox.
    /// </summary>
    public void PlaySFX(AudioClip clip, float volume = 1f, float pitch = 1f)
    {
        if (clip == null) return;
        var src = GetFreeSFXSource();
        src.outputAudioMixerGroup = SFX ?? src.outputAudioMixerGroup; // por si no se asignó
        src.volume = Mathf.Clamp01(volume);
        src.pitch = pitch;
        src.PlayOneShot(clip, src.volume);
    }

    /// <summary>
    /// Reproduce un SFX en una posición del mundo (para pruebas 3D rápidas).
    /// </summary>
    public void PlaySFXAt(AudioClip clip, Vector3 worldPos, float volume = 1f, float pitch = 1f)
    {
        if (clip == null) return;
        var src = GetFreeSFXSource();
        src.transform.position = worldPos;
        src.spatialBlend = 1f; // 3D
        src.outputAudioMixerGroup = SFX ?? src.outputAudioMixerGroup;
        src.volume = Mathf.Clamp01(volume);
        src.pitch = pitch;
        src.PlayOneShot(clip, src.volume);
        src.spatialBlend = 0f; // volver a 2D para siguientes
    }

    // =======================
    // API: VOLUMEN (sliders 0..1)
    // =======================

    public void SetMasterVolume(float v) => SetDb(masterParam, v);
    public void SetMUSVolume(float v) => SetDb(musParam, v);
    public void SetSFXVolume(float v) => SetDb(sfxParam, v);
    public void SetAXVolume(float v) => SetDb(axParam, v);
    public void SetUIVolume(float v) => SetDb(uiParam, v);
    public void SetVOVolume(float v) => SetDb(voParam, v);

    // =======================
    // UTILIDADES INTERNAS
    // =======================

    private AudioSource GetFreeSFXSource()
    {
        // Busca una fuente libre; si todas están ocupadas, reutiliza la primera.
        foreach (var s in sfxPool) if (!s.isPlaying) return s;
        return sfxPool[0];
    }

    /// <summary>
    /// Convierte un valor lineal [0..1] a dB y lo aplica al parámetro EXPUESTO del mixer.
    /// 1.0 → 0 dB (unidad). 0.5 → ~-6 dB. Valores cercanos a 0 → muy atenuados.
    /// </summary>
    private void SetDb(string exposedParam, float linear01)
    {
        if (mixer == null || string.IsNullOrEmpty(exposedParam)) return;
        float clamped = Mathf.Clamp(linear01, 0.0001f, 1f);
        float dB = Mathf.Log10(clamped) * 20f;
        mixer.SetFloat(exposedParam, dB);
    }
}

