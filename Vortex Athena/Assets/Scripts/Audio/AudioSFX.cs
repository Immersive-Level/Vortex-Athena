using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Audio;

/// <summary>
/// SFX de propulsión:
/// - Dos contenedores aleatorios (A y B) que se reproducen en simultáneo (capas).
/// - En Press: elige 1 clip aleatorio por capa y lo lanza (one-shot).
/// - En Release: si el tiempo pulsado < duración del clip, hace fade logarítmico corto.
///               si el tiempo pulsado >= duración, deja que el clip termine solo.
/// - Opción de pitch aleatorio en semitonos.
/// - Ruteo al bus SFX (AudioMixerGroup).
/// </summary>
[AddComponentMenu("Audio/SFX")]
public class AudioSFX : MonoBehaviour
{
    [Header("Ruteo")]
    [Tooltip("Grupo de salida del AudioMixer. Si se deja vacío, intenta usar AudioManager.Instance.GetSFXGroup().")]
    public AudioMixerGroup outputGroup;

    [Header("Capa A (random)")]
    public bool layerAEnabled = true;
    [Tooltip("Clips candidatos de la capa A (elige 1 aleatorio en cada Press).")]
    public List<AudioClip> clipsA = new List<AudioClip>();
    [Range(0f, 1f)] public float volumeA = 1f;

    [Header("Capa B (random, opcional)")]
    public bool layerBEnabled = false;
    [Tooltip("Clips candidatos de la capa B (elige 1 aleatorio en cada Press).")]
    public List<AudioClip> clipsB = new List<AudioClip>();
    [Range(0f, 1f)] public float volumeB = 1f;

    [Header("Pitch aleatorio (semitonos)")]
    [Tooltip("Si está activo, aplica un pitch aleatorio en semitonos a cada disparo.")]
    public bool randomPitch = false;
    [Range(-12f, 12f)] public float pitchSemitoneMin = 0f;
    [Range(-12f, 12f)] public float pitchSemitoneMax = 0f;

    [Header("Atenuación al soltar")]
    [Tooltip("Si está activo, el fade usa interpolación en dB (percepción más suave).")]
    public bool useLogFade = true;
    [Tooltip("Tiempo del fade-out cuando se suelta antes de que termine el clip.")]
    [Range(0.02f, 0.6f)] public float fadeOutSeconds = 0.12f;
    [Tooltip("Nivel objetivo del fade (en dB). -80 dB ≈ silencio.")]
    public float fadeEndDb = -80f;

    // --- Estado interno / runtime ---
    private AudioSource srcA, srcB;        // 1 fuente por capa
    private int lastIndexA = -1, lastIndexB = -1;
    private float pressStartTime;
    private Coroutine fadeCoA, fadeCoB;

    void Awake()
    {
        // Resolver grupo de salida si no fue asignado (SFX del AudioManager)
        if (outputGroup == null)
        {
            var am = AudioManager.Instance;
            if (am != null) outputGroup = am.GetSFXGroup();
        }

        // Crear fuentes (2D, one-shots)
        srcA = CreateSource("Thrust_A");
        srcB = CreateSource("Thrust_B");
    }

    AudioSource CreateSource(string name)
    {
        var go = new GameObject(name);
        go.transform.SetParent(transform);
        var src = go.AddComponent<AudioSource>();
        src.playOnAwake = false;
        src.loop = false;   // no loopeamos; duración depende del hold
        src.spatialBlend = 0f;      // 2D (ajusta a 3D si quieres espacializar)
        src.priority = 120;     // prioridad buena para móvil
        if (outputGroup != null) src.outputAudioMixerGroup = outputGroup;
        return src;
    }

    /// <summary>
    /// Llamar cuando el jugador PRESIONA el botón de propulsión.
    /// </summary>
    public void OnThrustPressed()
    {
        pressStartTime = Time.time;

        // Si había fades en curso, los cortamos para relanzar limpio
        if (fadeCoA != null) { StopCoroutine(fadeCoA); fadeCoA = null; ResetVolume(srcA, volumeA); }
        if (fadeCoB != null) { StopCoroutine(fadeCoB); fadeCoB = null; ResetVolume(srcB, volumeB); }

        // Disparo por capa
        if (layerAEnabled) PlayRandom(clipsA, srcA, ref lastIndexA, volumeA);
        if (layerBEnabled) PlayRandom(clipsB, srcB, ref lastIndexB, volumeB);
    }

    /// <summary>
    /// Llamar cuando el jugador SUELTA el botón de propulsión.
    /// - Si el hold fue corto (clip aún suena), hacemos fade-out corto.
    /// - Si el hold fue >= duración del clip (ya terminó), no hacemos nada.
    /// </summary>
    public void OnThrustReleased()
    {
        float held = Time.time - pressStartTime;

        TryFadeIfNeeded(srcA, held, volumeA, ref fadeCoA);
        TryFadeIfNeeded(srcB, held, volumeB, ref fadeCoB);
    }

    /// <summary>Detiene cualquier sonido de propulsión inmediatamente.</summary>
    public void StopImmediate()
    {
        if (fadeCoA != null) { StopCoroutine(fadeCoA); fadeCoA = null; }
        if (fadeCoB != null) { StopCoroutine(fadeCoB); fadeCoB = null; }
        if (srcA != null) { srcA.Stop(); ResetVolume(srcA, volumeA); }
        if (srcB != null) { srcB.Stop(); ResetVolume(srcB, volumeB); }
    }

    // ===================== Helpers internos =====================

    void PlayRandom(List<AudioClip> list, AudioSource src, ref int lastIndex, float baseVol)
    {
        if (list == null || list.Count == 0 || src == null) return;

        // Elige índice evitando repetir el último si hay >1
        int idx = 0;
        if (list.Count == 1) idx = 0;
        else
        {
            do { idx = Random.Range(0, list.Count); }
            while (idx == lastIndex);
        }
        lastIndex = idx;

        var clip = list[idx];
        if (clip == null) return;

        // Config de pitch (semitonos → factor)
        float pitch = 1f;
        if (randomPitch)
        {
            float semi = Random.Range(
                Mathf.Min(pitchSemitoneMin, pitchSemitoneMax),
                Mathf.Max(pitchSemitoneMin, pitchSemitoneMax)
            );
            pitch = Mathf.Pow(2f, semi / 12f);
        }

        // Reproducir
        src.Stop();
        src.clip = clip;
        src.volume = baseVol;
        src.pitch = pitch;
        src.Play();
    }

    void TryFadeIfNeeded(AudioSource src, float heldSeconds, float baseVol, ref Coroutine fadeCo)
    {
        if (src == null || src.clip == null) return;

        // Duración efectiva teniendo en cuenta el pitch (si != 1)
        float effectiveLen = src.clip.length / Mathf.Max(Mathf.Abs(src.pitch), 0.0001f);

        // Si el jugador soltó antes de que terminara el clip y el clip aún suena → fade
        bool clipStillPlaying = src.isPlaying; // robusto ante taps
        bool heldShorterThanClip = heldSeconds < (effectiveLen - 0.001f);

        if (clipStillPlaying && heldShorterThanClip)
        {
            // Si está a punto de terminar, acortamos el fade para evitar "cola" rara
            float remaining = Mathf.Max(0f, effectiveLen - src.time);
            float fadeTime = Mathf.Min(fadeOutSeconds, remaining);

            if (fadeCo != null) StopCoroutine(fadeCo);
            fadeCo = StartCoroutine(FadeOutDb(src, baseVol, fadeTime, fadeEndDb, useLogFade));
        }
        // Si no, no hacemos nada: el audio terminará por sí solo.
    }

    IEnumerator FadeOutDb(AudioSource src, float startLinear, float seconds, float endDb, bool logMode)
    {
        if (src == null) yield break;
        if (seconds <= 0f)
        {
            src.Stop();
            src.volume = startLinear;
            yield break;
        }

        float t = 0f;
        while (t < seconds && src.isPlaying)
        {
            t += Time.unscaledDeltaTime;
            float k = Mathf.Clamp01(t / seconds);

            if (logMode)
            {
                // Interpola en dB: 0 dB → endDb (p.ej. -80 dB), luego convierte a lineal
                float db = Mathf.Lerp(0f, endDb, k);
                float lin = Mathf.Pow(10f, db / 20f);
                src.volume = startLinear * lin;
            }
            else
            {
                // Lineal simple
                src.volume = Mathf.Lerp(startLinear, 0f, k);
            }
            yield return null;
        }

        src.Stop();
        src.volume = startLinear; // restaurar para el siguiente disparo
    }

    void ResetVolume(AudioSource src, float baseVol)
    {
        if (src == null) return;
        src.volume = baseVol;
    }

    // ===================== MENÚS CONTEXTUALES (TEST) =====================
#if UNITY_EDITOR
    [ContextMenu("SFX: Thrust Press")]
    private void Ctx_TestThrustPress()
    {
        OnThrustPressed();
    }

    [ContextMenu("SFX: Thrust Release")]
    private void Ctx_TestThrustRelease()
    {
        OnThrustReleased();
    }

    [ContextMenu("SFX: Stop Immediate")]
    private void Ctx_TestStopImmediate()
    {
        StopImmediate();
    }

    [ContextMenu("SFX: Short Tap (0.1s)")]
    private void Ctx_TestShortTap()
    {
        // Solo funciona en Play Mode (las corutinas no avanzan fuera de Play).
        if (!Application.isPlaying)
        {
            Debug.LogWarning("[AudioSFX] Entra a Play Mode para probar el Short Tap.");
            return;
        }
        StartCoroutine(Co_Tap());
    }

    private IEnumerator Co_Tap()
    {
        OnThrustPressed();
        yield return new WaitForSeconds(0.1f);
        OnThrustReleased();
    }
#endif
}


