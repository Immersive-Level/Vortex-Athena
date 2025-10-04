using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Audio;

[AddComponentMenu("Audio/Ambience Layers")]
public class AmbienceLayers : MonoBehaviour
{
    [Header("Salida (opcional recomendado)")]
    [Tooltip("Grupo del AudioMixer al que se enviarán las capas (p. ej. AX).")]
    public AudioMixerGroup outputGroup;

    [Header("Reproducción global")]
    [Tooltip("Si está activo, se reproduce automáticamente al iniciar la escena.")]
    public bool playOnStart = true;

    [Tooltip("Si está activo, ambas capas arrancan exactamente a la vez.")]
    public bool syncStart = true;

    [Tooltip("Activar crossfade al CAMBIAR de clip dentro de la capa.")]
    public bool enableCrossfadeOnSwitch = false;

    [Tooltip("Duración del crossfade al CAMBIAR de clip (segundos).")]
    [Range(0.01f, 1.0f)] public float crossfadeSeconds = 0.12f;

    [Tooltip("Usar 'constant power' en vez de crossfade lineal al cambiar de clip.")]
    public bool useConstantPowerCrossfade = true;

    [System.Serializable]
    public class Layer
    {
        [Tooltip("Nombre solo informativo en el inspector.")]
        public string name = "Layer";

        [Tooltip("Habilita/deshabilita por completo esta capa.")]
        public bool enabled = true;

        [Tooltip("Clips disponibles; se elige uno al azar.")]
        public List<AudioClip> clips = new List<AudioClip>();

        [Tooltip("Volumen base (0..1) de la capa.")]
        [Range(0f, 1f)] public float volume = 1f;

        [Header("Pitch aleatorio (en semitonos)")]
        [Tooltip("¿Aplicar variación de pitch aleatoria al iniciar/cambiar clip?")]
        public bool randomPitch = false;

        [Tooltip("Rango mínimo en semitonos.")]
        [Range(-12f, 12f)] public float pitchSemitoneMin = 0f;

        [Tooltip("Rango máximo en semitonos.")]
        [Range(-12f, 12f)] public float pitchSemitoneMax = 0f;

        [Header("Cambio automático (opcional)")]
        [Tooltip("Si > 0, cada X segundos cambiará de clip aleatoriamente.")]
        public float autoSwitchEverySeconds = 0f;
    }

    [Header("Contenedores (se reproducen en simultáneo)")]
    public Layer layerA = new Layer { name = "Layer A" };
    public Layer layerB = new Layer { name = "Layer B" };

    // ---- Runtime ----
    class LayerRuntime
    {
        public Layer cfg;
        public AudioSource current;
        public AudioSource next;
        public int lastIndex = -1;
        public Coroutine autoSwitchCo;
    }

    LayerRuntime _A, _B;

    void Awake()
    {
        _A = CreateLayerRuntime(layerA, "A");
        _B = CreateLayerRuntime(layerB, "B");
    }

    void Start()
    {
        if (playOnStart) Play();
    }

    LayerRuntime CreateLayerRuntime(Layer cfg, string tag)
    {
        var rt = new LayerRuntime { cfg = cfg };

        // Dos fuentes por capa (nos sirven también si NO usamos crossfade)
        rt.current = CreateSource($"Amb_{tag}_Current");
        rt.next = CreateSource($"Amb_{tag}_Next");
        return rt;
    }

    AudioSource CreateSource(string name)
    {
        var go = new GameObject(name);
        go.transform.SetParent(transform);
        var src = go.AddComponent<AudioSource>();
        src.playOnAwake = false;
        src.loop = true;   // loops perfectos por defecto
        src.spatialBlend = 0f;     // 2D (para ambiente); cámbialo si quieres 3D
        src.priority = 180;    // prioridad media
        if (outputGroup) src.outputAudioMixerGroup = outputGroup;
        return src;
    }

    // ======================================================
    // API pública
    // ======================================================

    /// <summary>Inicia la reproducción de ambas capas (si están habilitadas).</summary>
    public void Play()
    {
        double start = syncStart ? AudioSettings.dspTime + 0.05 : 0.0;

        StartLayer(_A, start);
        StartLayer(_B, start);
    }

    // En AmbienceLayers.cs (dentro de la clase)
    public void TogglePlay()
    {
        if (IsPlaying()) Stop();
        else Play();
    }

    public bool IsPlaying()
    {
        // “Reproduciendo” si cualquiera de las capas tiene su fuente actual sonando
        return (_A != null && _A.current != null && _A.current.isPlaying)
            || (_B != null && _B.current != null && _B.current.isPlaying);
    }

    /// <summary>Detiene ambas capas inmediatamente.</summary>
    public void Stop()
    {
        StopLayer(_A);
        StopLayer(_B);
    }

    /// <summary>Cambia aleatoriamente el clip de la capa A (con/sin crossfade).</summary>
    public void NextA() => SwitchRandom(_A);

    /// <summary>Cambia aleatoriamente el clip de la capa B (con/sin crossfade).</summary>
    public void NextB() => SwitchRandom(_B);

    /// <summary>Ajusta volúmenes en runtime (0..1).</summary>
    public void SetVolumes(float volA, float volB)
    {
        if (_A?.current) _A.current.volume = Mathf.Clamp01(volA);
        if (_A?.next) _A.next.volume = Mathf.Clamp01(volA);
        if (_B?.current) _B.current.volume = Mathf.Clamp01(volB);
        if (_B?.next) _B.next.volume = Mathf.Clamp01(volB);
        if (_A != null) _A.cfg.volume = Mathf.Clamp01(volA);
        if (_B != null) _B.cfg.volume = Mathf.Clamp01(volB);
    }

    // ======================================================
    // Internos por capa
    // ======================================================

    void StartLayer(LayerRuntime rt, double dspStart)
    {
        if (rt == null || rt.cfg == null || !rt.cfg.enabled) return;
        if (rt.cfg.clips == null || rt.cfg.clips.Count == 0) return;

        var clip = PickRandomClip(rt);
        ApplyClipAndPitch(rt.current, rt.cfg, clip);
        rt.current.volume = rt.cfg.volume;

        if (syncStart && dspStart > 0.0)
            rt.current.PlayScheduled(dspStart);
        else
            rt.current.Play();

        // Cambio automático si se configuró
        if (rt.autoSwitchCo != null) StopCoroutine(rt.autoSwitchCo);
        if (rt.cfg.autoSwitchEverySeconds > 0f)
            rt.autoSwitchCo = StartCoroutine(AutoSwitchRoutine(rt));
    }

    void StopLayer(LayerRuntime rt)
    {
        if (rt == null) return;
        if (rt.autoSwitchCo != null) { StopCoroutine(rt.autoSwitchCo); rt.autoSwitchCo = null; }
        if (rt.current) rt.current.Stop();
        if (rt.next) rt.next.Stop();
    }

    IEnumerator AutoSwitchRoutine(LayerRuntime rt)
    {
        var wait = new WaitForSeconds(rt.cfg.autoSwitchEverySeconds);
        while (true)
        {
            yield return wait;
            SwitchRandom(rt);
        }
    }

    void SwitchRandom(LayerRuntime rt)
    {
        if (rt == null || rt.cfg == null || !rt.cfg.enabled) return;
        if (rt.cfg.clips == null || rt.cfg.clips.Count == 0) return;

        var clip = PickRandomClip(rt);
        if (!enableCrossfadeOnSwitch || crossfadeSeconds <= 0.01f)
        {
            // Sin crossfade: reemplaza el actual
            ApplyClipAndPitch(rt.current, rt.cfg, clip);
            rt.current.volume = rt.cfg.volume;
            rt.current.Play();
            return;
        }

        // Con crossfade: prepara "next", lanza y cruza volúmenes
        ApplyClipAndPitch(rt.next, rt.cfg, clip);
        rt.next.volume = 0f;
        rt.next.Play();

        StartCoroutine(Crossfade(rt, crossfadeSeconds));
    }

    IEnumerator Crossfade(LayerRuntime rt, float t)
    {
        var a = rt.current;
        var b = rt.next;
        float baseVol = rt.cfg.volume;
        float time = 0f;

        while (time < t)
        {
            time += Time.unscaledDeltaTime;
            float k = Mathf.Clamp01(time / t);

            if (useConstantPowerCrossfade)
            {
                // Constant power: ganancias sen/cos para mantener energía percibida
                float aGain = Mathf.Cos(k * 0.5f * Mathf.PI); // 1 -> 0
                float bGain = Mathf.Sin(k * 0.5f * Mathf.PI); // 0 -> 1
                if (a) a.volume = baseVol * aGain;
                if (b) b.volume = baseVol * bGain;
            }
            else
            {
                // Lineal (por si quieres volver a probar)
                if (a) a.volume = Mathf.Lerp(baseVol, 0f, k);
                if (b) b.volume = Mathf.Lerp(0f, baseVol, k);
            }

            yield return null;
        }

        // Intercambia roles
        if (a) a.Stop();
        rt.current = b;
        rt.next = a;
    }


    AudioClip PickRandomClip(LayerRuntime rt)
    {
        if (rt.cfg.clips.Count == 1) { rt.lastIndex = 0; return rt.cfg.clips[0]; }

        int idx;
        do { idx = Random.Range(0, rt.cfg.clips.Count); }
        while (idx == rt.lastIndex && rt.cfg.clips.Count > 1);

        rt.lastIndex = idx;
        return rt.cfg.clips[idx];
    }

    void ApplyClipAndPitch(AudioSource src, Layer cfg, AudioClip clip)
    {
        if (!src || clip == null) return;
        src.clip = clip;
        src.loop = true; // loops perfectos
        src.volume = cfg.volume;
        src.pitch = 1f;

        if (cfg.randomPitch)
        {
            float semi = Random.Range(Mathf.Min(cfg.pitchSemitoneMin, cfg.pitchSemitoneMax),
                                      Mathf.Max(cfg.pitchSemitoneMin, cfg.pitchSemitoneMax));
            // semitonos → factor de pitch
            src.pitch = Mathf.Pow(2f, semi / 12f);
        }
    }

#if UNITY_EDITOR
    void OnValidate()
    {
        // Asegura rangos correctos si se mueven sliders en el Inspector
        if (layerA.pitchSemitoneMax < layerA.pitchSemitoneMin) layerA.pitchSemitoneMax = layerA.pitchSemitoneMin;
        if (layerB.pitchSemitoneMax < layerB.pitchSemitoneMin) layerB.pitchSemitoneMax = layerB.pitchSemitoneMin;
        crossfadeSeconds = Mathf.Clamp(crossfadeSeconds, 0.01f, 1.0f);
    }
#endif
}

