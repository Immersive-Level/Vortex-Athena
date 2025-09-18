using UnityEngine;
using UnityEngine.Audio;

/// <summary>
/// Núcleo de mezcla: SOLO gestiona el AudioMixer, grupos y volúmenes.
/// No reproduce nada. Otros sistemas (Música, SFX, VO, Ambientes) deben
/// usar sus propios scripts y ruteo hacia estos grupos.
/// </summary>
[AddComponentMenu("Audio/AudioManager (Mixer Core)")]
[DisallowMultipleComponent]
public class AudioManager : MonoBehaviour
{
    // ====== Singleton (opcional, útil si lo usas desde varias escenas) ======
    public static AudioManager Instance { get; private set; }

    [Header("Ciclo de vida")]
    [Tooltip("Mantener una única instancia y no destruir al cambiar de escena.")]
    public bool useSingleton = true;
    public bool dontDestroyOnLoad = true;

    // ====== Mixer y parámetros expuestos (dB) ======
    [Header("Mixer (asset)")]
    [Tooltip("Arrastra aquí tu asset 'AudioMixer'.")]
    public AudioMixer mixer;

    [Header("Parámetros EXPUESTOS en el Mixer (dB)")]
    [Tooltip("Nombre del parámetro expuesto para MASTER (p.ej. 'MasterVol').")]
    public string masterParam = "MasterVol";
    [Tooltip("Nombre del parámetro expuesto para MUS (p.ej. 'MUSVol').")]
    public string musParam = "MUSVol";
    [Tooltip("Nombre del parámetro expuesto para SFX (p.ej. 'SFXVol').")]
    public string sfxParam = "SFXVol";
    [Tooltip("Nombre del parámetro expuesto para AX (p.ej. 'AXVol').")]
    public string axParam = "AXVol";
    [Tooltip("Nombre del parámetro expuesto para UI (p.ej. 'UIVol').")]
    public string uiParam = "UIVol";
    [Tooltip("Nombre del parámetro expuesto para VO (p.ej. 'VOVol').")]
    public string voParam = "VOVol";

    // ====== Grupos para ruteo ======
    [Header("Grupos del Mixer (para ruteo desde otros sistemas)")]
    public AudioMixerGroup MUS;
    public AudioMixerGroup SFX;
    public AudioMixerGroup AX;
    public AudioMixerGroup UI;
    public AudioMixerGroup VO;

    // ====== Persistencia (opcional) ======
    [Header("Persistencia (opcional)")]
    [Tooltip("Al activarlo, guarda/carga volúmenes en PlayerPrefs.")]
    public bool persistVolumes = false;

    // Claves de PlayerPrefs (por si quieres cambiarlas)
    const string K_MASTER = "vol_master";
    const string K_MUS = "vol_mus";
    const string K_SFX = "vol_sfx";
    const string K_AX = "vol_ax";
    const string K_UI = "vol_ui";
    const string K_VO = "vol_vo";

    // =========================================================
    // Ciclo de vida
    // =========================================================
    private void Awake()
    {
        // Singleton básico (opcional)
        if (useSingleton)
        {
            if (Instance != null && Instance != this)
            {
                Destroy(gameObject);
                return;
            }
            Instance = this;
            if (dontDestroyOnLoad) DontDestroyOnLoad(gameObject);
        }

        // Inicializa volúmenes (1.0f = 0 dB)
        if (persistVolumes)
        {
            SetMasterVolume(PlayerPrefs.GetFloat(K_MASTER, 1f));
            SetMUSVolume(PlayerPrefs.GetFloat(K_MUS, 1f));
            SetSFXVolume(PlayerPrefs.GetFloat(K_SFX, 1f));
            SetAXVolume(PlayerPrefs.GetFloat(K_AX, 1f));
            SetUIVolume(PlayerPrefs.GetFloat(K_UI, 1f));
            SetVOVolume(PlayerPrefs.GetFloat(K_VO, 1f));
        }
        else
        {
            SetMasterVolume(1f);
            SetMUSVolume(1f);
            SetSFXVolume(1f);
            SetAXVolume(1f);
            SetUIVolume(1f);
            SetVOVolume(1f);
        }
    }

    // =========================================================
    // API de volúmenes (0..1 → dB). Úsalos desde sliders/UI.
    // =========================================================
    public void SetMasterVolume(float v) => SetDb(masterParam, v, persistVolumes ? K_MASTER : null);
    public void SetMUSVolume(float v) => SetDb(musParam, v, persistVolumes ? K_MUS : null);
    public void SetSFXVolume(float v) => SetDb(sfxParam, v, persistVolumes ? K_SFX : null);
    public void SetAXVolume(float v) => SetDb(axParam, v, persistVolumes ? K_AX : null);
    public void SetUIVolume(float v) => SetDb(uiParam, v, persistVolumes ? K_UI : null);
    public void SetVOVolume(float v) => SetDb(voParam, v, persistVolumes ? K_VO : null);

    /// <summary>
    /// Devuelve el volumen actual (0..1) leyendo del Mixer. Útil para inicializar sliders.
    /// </summary>
    public float GetVolumeLinear(string exposedParam, float fallback = 1f)
    {
        if (mixer == null || string.IsNullOrEmpty(exposedParam)) return fallback;
        if (mixer.GetFloat(exposedParam, out float dB))
        {
            // inversa de 20*log10(x)
            float lin = Mathf.Pow(10f, dB / 20f);
            return Mathf.Clamp01(lin);
        }
        return fallback;
    }

    // Helpers específicos (por comodidad)
    public float GetMasterVolume() => GetVolumeLinear(masterParam);
    public float GetMUSVolume() => GetVolumeLinear(musParam);
    public float GetSFXVolume() => GetVolumeLinear(sfxParam);
    public float GetAXVolume() => GetVolumeLinear(axParam);
    public float GetUIVolume() => GetVolumeLinear(uiParam);
    public float GetVOVolume() => GetVolumeLinear(voParam);

    // =========================================================
    // API de ruteo: grupos del Mixer para otros sistemas
    // =========================================================
    public AudioMixerGroup GetMUSGroup() => MUS;
    public AudioMixerGroup GetSFXGroup() => SFX;
    public AudioMixerGroup GetAXGroup() => AX;
    public AudioMixerGroup GetUIGroup() => UI;
    public AudioMixerGroup GetVOGroup() => VO;

    // =========================================================
    // Internos: conversión lineal↔dB y guardado
    // =========================================================
    void SetDb(string exposedParam, float linear01, string prefsKeyOrNull)
    {
        if (mixer != null && !string.IsNullOrEmpty(exposedParam))
        {
            float clamped = Mathf.Clamp(linear01, 0.0001f, 1f); // evita -∞ dB
            float dB = Mathf.Log10(clamped) * 20f;              // 1.0 → 0 dB, 0.5 → ~-6 dB
            mixer.SetFloat(exposedParam, dB);
        }

        if (!string.IsNullOrEmpty(prefsKeyOrNull))
        {
            PlayerPrefs.SetFloat(prefsKeyOrNull, Mathf.Clamp01(linear01));
            PlayerPrefs.Save();
        }
    }
}

