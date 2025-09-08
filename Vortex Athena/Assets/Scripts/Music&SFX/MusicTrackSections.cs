using System.Collections;
using UnityEngine;
using UnityEngine.Audio;

/// <summary>
/// Reproductor por secciones dentro de UN AudioClip:
/// - Intro (opcional)  [intro.start .. intro.end)
/// - Loop  (opcional)  [loop.start  .. loop.end)  con opción de repetir o continuar a Outro
/// - Outro (opcional)  [outro.start .. outro.end)
///
/// Cada sección tiene: enabled, startSec, endSec.
/// Tiempos SIEMPRE en segundos (Inspector).
///
/// Opciones de Crossfade:
/// - crossfadeBetweenSections: Intro→Loop, Loop→Outro
/// - crossfadeLoopRepeats: entre repeticiones del Loop
///
/// La Outro puede solicitarse desde código con RequestOutro();
/// (entra en el siguiente cambio de sección).
///
/// Recomendación de import para el clip:
/// - Load Type: Decompress On Load
/// - Preload Audio Data: ON
/// </summary>
[AddComponentMenu("Audio/Music Sections Player")]
public class MusicSectionsPlayer : MonoBehaviour
{
    [System.Serializable]
    public struct Section
    {
        public bool enabled;
        [Tooltip("Inicio de la sección (segundos, inclusive).")]
        public float start;
        [Tooltip("Fin de la sección (segundos, exclusivo).")]
        public float end;
    }

    [Header("Salida (opcional)")]
    public AudioMixerGroup outputGroup;

    [Header("Clip único con todas las secciones")]
    public AudioClip clip;

    [Header("Intro")]
    public Section intro;     // intro.enabled para usarla o no

    [Header("Loop")]
    public Section loop;      // loop.enabled para usarla o no
    [Tooltip("Si está activo, repite el rango del loop hasta que se pida Outro.")]
    public bool loopRepeat = true;

    [Header("Outro")]
    public Section outro;     // outro.enabled para usarla o no

    [Header("Crossfades")]
    [Tooltip("Hacer crossfade entre secciones (Intro→Loop, Loop→Outro).")]
    public bool crossfadeBetweenSections = false;
    [Range(0f, 2f)] public float crossfadeSectionsSeconds = 0.2f;

    [Tooltip("Hacer crossfade entre repeticiones del loop.")]
    public bool crossfadeLoopRepeats = false;
    [Range(0f, 2f)] public float crossfadeLoopSeconds = 0.2f;

    [Header("Reproducción")]
    public bool playOnStart = true;
    [Range(0f, 1f)] public float volume = 1f;

    [Tooltip("Anticipación para preparar (DSP). No es fade; es margen de programación.")]
    [Range(0.02f, 0.5f)] public double scheduleLookAhead = 0.08;

    [Header("Debug")]
    public bool debugLogs = false;

    // ---- runtime ----
    private AudioSource srcA, srcB;   // alternamos A/B
    private AudioSource current, nextSrc;
    private bool isPlaying;
    private bool outroRequested;
    private Coroutine scheduler;

    private enum Stage { None, Intro, Loop, Outro }
    private Stage currentStage = Stage.None;
    private Stage nextStage = Stage.None;

    // Tiempos DSP programados
    private double currentEndDSP;   // fin del segmento actual
    private double nextStartDSP;    // inicio DSP del siguiente segmento
    private double nextEndDSP;      // fin DSP del siguiente segmento

    void Awake()
    {
        if (outputGroup == null && AudioManager.Instance != null)
            outputGroup = AudioManager.Instance.GetMUSGroup();

        srcA = CreateSource("Music_A");
        srcB = CreateSource("Music_B");
        current = srcA; nextSrc = srcB;
    }

    void Start()
    {
        if (playOnStart) Play();
    }

    AudioSource CreateSource(string name)
    {
        var go = new GameObject(name);
        go.transform.SetParent(transform);
        var s = go.AddComponent<AudioSource>();
        s.playOnAwake = false;
        s.loop = false;
        s.spatialBlend = 0f;
        s.priority = 64;
        s.volume = volume;
        if (outputGroup != null) s.outputAudioMixerGroup = outputGroup;
        return s;
    }

    // ===================== API =====================

    public void Play()
    {
        if (clip == null)
        {
            Debug.LogWarning("[MusicSectionsPlayer] Sin clip.");
            return;
        }

        SanitizeAll();

        StopImmediate();

        // Decide sección de arranque
        if (intro.enabled && Duration(intro) > 0f)
        {
            StartNow(current, intro.start, Duration(intro));
            currentStage = Stage.Intro;

            // Prepara el siguiente (Loop si existe; si no, Outro; si no, nada)
            var next = ChooseNextAfterIntro();
            ScheduleNextSegment(next);
        }
        else if (loop.enabled && Duration(loop) > 0f)
        {
            StartNow(current, loop.start, Duration(loop));
            currentStage = Stage.Loop;

            var next = ChooseNextAfterLoop(); // siguiente puede ser Otro o Loop (según flags)
            ScheduleNextSegment(next);
        }
        else if (outro.enabled && Duration(outro) > 0f)
        {
            StartNow(current, outro.start, Duration(outro));
            currentStage = Stage.Outro;
            // No hay “next” por defecto
        }
        else
        {
            Debug.LogWarning("[MusicSectionsPlayer] No hay secciones válidas para reproducir.");
            return;
        }

        isPlaying = true;

        if (scheduler != null) StopCoroutine(scheduler);
        scheduler = StartCoroutine(SchedulerLoop());
    }

    public void StopImmediate()
    {
        isPlaying = false;
        outroRequested = false;
        currentStage = Stage.None;
        nextStage = Stage.None;

        if (scheduler != null) { StopCoroutine(scheduler); scheduler = null; }
        if (current != null) current.Stop();
        if (nextSrc != null) nextSrc.Stop();
        current.volume = volume;
        nextSrc.volume = volume;

        // Reset order
        current = srcA; nextSrc = srcB;
    }

    /// <summary>
    /// Señala que, al terminar la repetición/segmento actual, debe pasar a OUTRO (si está configurado).
    /// No corta de inmediato; toma efecto en la siguiente transición.
    /// </summary>
    public void RequestOutro()
    {
        if (!outro.enabled || Duration(outro) <= 0f) return;
        outroRequested = true;
        if (debugLogs) Debug.Log("[MusicSectionsPlayer] Outro solicitado.");
    }

    public bool IsPlaying() => isPlaying;

    // ===================== Núcleo =====================

    IEnumerator SchedulerLoop()
    {
        while (isPlaying)
        {
            // Esperar hasta que llegue el momento de empezar el “next”
            if (nextStage != Stage.None)
            {
                // Si aún falta para el start DSP, espera
                while (isPlaying && AudioSettings.dspTime < nextStartDSP - scheduleLookAhead * 0.5)
                    yield return null;

                // En el instante exacto, arranca crossfade (si aplica) y deja que empiece el next
                if (nextStage == Stage.Loop)
                {
                    float cf = crossfadeLoopRepeats ? Mathf.Min(crossfadeLoopSeconds, (float)(nextEndDSP - nextStartDSP) * 0.5f) : 0f;
                    if (cf > 0f) StartCoroutine(CrossfadeAt(nextStartDSP, current, nextSrc, cf));
                }
                else
                {
                    float cf = crossfadeBetweenSections ? Mathf.Min(crossfadeSectionsSeconds, (float)(nextEndDSP - nextStartDSP) * 0.5f) : 0f;
                    if (cf > 0f) StartCoroutine(CrossfadeAt(nextStartDSP, current, nextSrc, cf));
                }

                // Espera hasta que comience efectivamente el “next”
                while (isPlaying && AudioSettings.dspTime < nextStartDSP)
                    yield return null;

                // Swap: ahora el next pasa a ser el current
                var tmp = current; current = nextSrc; nextSrc = tmp;
                currentStage = nextStage;
                currentEndDSP = nextEndDSP;

                if (debugLogs)
                    Debug.Log($"[Music] → {currentStage} started @ {nextStartDSP:0.000}  ends @ {currentEndDSP:0.000}");
            }

            // Decidir qué viene después y programarlo
            var following = ChooseNextAfter(currentStage);
            if (following == Stage.None)
            {
                // No hay más: esperar a que termine el current y salir
                while (isPlaying && AudioSettings.dspTime < currentEndDSP)
                    yield return null;
                break;
            }

            ScheduleNextSegment(following);
        }

        // Termina todo
        StopImmediate();
    }

    // Elige la etapa que sigue después de haber arrancado en Intro
    Stage ChooseNextAfterIntro()
    {
        if (loop.enabled && Duration(loop) > 0f) return Stage.Loop;
        if (outro.enabled && Duration(outro) > 0f) return Stage.Outro;
        return Stage.None;
    }

    // Elige después de Loop (depende de loopRepeat y de si hay outroRequested)
    Stage ChooseNextAfterLoop()
    {
        if (outroRequested && outro.enabled && Duration(outro) > 0f) return Stage.Outro;
        if (loopRepeat && loop.enabled && Duration(loop) > 0f) return Stage.Loop;
        if (outro.enabled && Duration(outro) > 0f) return Stage.Outro;
        return Stage.None;
    }

    // Genérico: qué sigue después del “stage” actual
    Stage ChooseNextAfter(Stage stage)
    {
        switch (stage)
        {
            case Stage.Intro: return ChooseNextAfterIntro();
            case Stage.Loop: return ChooseNextAfterLoop();
            case Stage.Outro: return Stage.None;
            default: return Stage.None;
        }
    }

    // Programa el siguiente segmento (establece nextStage, nextStartDSP, nextEndDSP y agenda el AudioSource)
    void ScheduleNextSegment(Stage stageToSchedule)
    {
        nextStage = stageToSchedule;

        double now = AudioSettings.dspTime;

        // Info de segmento a programar
        float segStart = 0f, segDur = 0f;
        float cross = 0f;

        switch (nextStage)
        {
            case Stage.Loop:
                segStart = loop.start;
                segDur = Duration(loop);
                cross = crossfadeLoopRepeats ? crossfadeLoopSeconds : 0f;
                break;

            case Stage.Outro:
                segStart = outro.start;
                segDur = Duration(outro);
                cross = crossfadeBetweenSections ? crossfadeSectionsSeconds : 0f;
                break;

            case Stage.Intro:
                segStart = intro.start;
                segDur = Duration(intro);
                cross = crossfadeBetweenSections ? crossfadeSectionsSeconds : 0f;
                break;

            default:
                return;
        }

        // Clamp del crossfade a la mitad de la duración del segmento
        cross = Mathf.Clamp(cross, 0f, segDur * 0.5f);

        // ¿Cuándo empieza el siguiente? Justo cuando termina el actual, menos crossfade (si lo hay)
        double start = (currentEndDSP > 0.0) ? currentEndDSP - cross : AudioSettings.dspTime + 0.02;

        // Programamos el nextSrc
        PrepareScheduled(nextSrc, clip, segStart, start);
        nextSrc.SetScheduledEndTime(start + segDur);

        nextStartDSP = start;
        nextEndDSP = start + segDur;

        if (debugLogs)
            Debug.Log($"[Music] Schedule {nextStage}  start:{segStart:0.###}s  dur:{segDur:0.###}s  DSP@{nextStartDSP:0.000}..{nextEndDSP:0.000}");
    }

    // Arranca YA el segmento (se usa para el primer segmento)
    void StartNow(AudioSource s, float startSec, float durSec)
    {
        PrepareStart(s, clip, startSec);
        s.volume = volume;
        s.Play();

        currentEndDSP = AudioSettings.dspTime + durSec;
        if (debugLogs)
            Debug.Log($"[Music] StartNow {startSec:0.###}..{startSec + durSec:0.###}  ends@{currentEndDSP:0.000}");
    }

    // Posiciona en 'startSec' y agenda PlayScheduled en 'dspStart'
    void PrepareScheduled(AudioSource s, AudioClip c, float startSec, double dspStart)
    {
        PrepareStart(s, c, startSec);
        s.volume = (s == nextSrc) ? (crossfadeLoopRepeats || crossfadeBetweenSections ? 0f : volume) : volume;
        s.PlayScheduled(dspStart);
    }

    // Posiciona el source en el punto de inicio (por muestras)
    void PrepareStart(AudioSource s, AudioClip c, float startSec)
    {
        startSec = Mathf.Clamp(startSec, 0f, c.length);
        s.Stop();
        s.clip = c;
        int startSamples = Mathf.FloorToInt(startSec * c.frequency);
        s.timeSamples = Mathf.Clamp(startSamples, 0, c.samples - 1);
        s.outputAudioMixerGroup = outputGroup != null ? outputGroup : s.outputAudioMixerGroup;
    }

    float Duration(Section sec) => Mathf.Max(0f, sec.end - sec.start);

    // Crossfade en tiempo real, alineado al DSP
    IEnumerator CrossfadeAt(double dspStart, AudioSource from, AudioSource to, float seconds)
    {
        // Espera al instante de inicio
        while (AudioSettings.dspTime < dspStart) yield return null;

        // Fade simultáneo
        float t = 0f;
        float fromStart = from != null ? from.volume : 1f;
        float toStart = to != null ? to.volume : 0f;

        while (t < seconds)
        {
            t += Time.unscaledDeltaTime;
            float k = Mathf.Clamp01(t / seconds);

            if (from != null) from.volume = Mathf.Lerp(fromStart, 0f, k);
            if (to != null) to.volume = Mathf.Lerp(toStart, volume, k);

            yield return null;
        }

        if (from != null) from.volume = 0f;
        if (to != null) to.volume = volume;
    }

    // Sanear/validar rangos en segundos
    void SanitizeAll()
    {
        if (clip == null) return;
        float L = clip.length;

        // Intro
        if (intro.enabled)
        {
            intro.start = Mathf.Clamp(intro.start, 0f, L);
            intro.end = Mathf.Clamp(intro.end, intro.start, L);
            if (Duration(intro) <= 0f) intro.enabled = false;
        }

        // Loop
        if (loop.enabled)
        {
            loop.start = Mathf.Clamp(loop.start, 0f, L);
            loop.end = Mathf.Clamp(loop.end, loop.start, L);
            if (Duration(loop) <= 0f) loop.enabled = false;
        }

        // Outro
        if (outro.enabled)
        {
            outro.start = Mathf.Clamp(outro.start, 0f, L);
            outro.end = Mathf.Clamp(outro.end, outro.start, L);
            if (Duration(outro) <= 0f) outro.enabled = false;
        }
    }
}

