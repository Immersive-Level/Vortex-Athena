using UnityEngine;
using UnityEngine.Audio;
using System.Collections;

/// <summary>
/// Activa/para los AMBIENTES (AX) cuando entras/sales del panel de gameplay.
/// Si "usarFadePorMixer" está activo, hace fade con el parámetro expuesto del Mixer (bus AX).
/// </summary>
public class GameplayAmbienceHook : MonoBehaviour
{
    [Header("Referencia al sistema de ambientes (AX)")]
    [SerializeField] private AmbienceLayers ambientes;   // tu componente de ambientes (el de AudioSandbox)

    [Header("Fade (opcional por Mixer)")]
    [Tooltip("Si está activo, el volumen del bus AX hará fade con el Mixer.")]
    [SerializeField] private bool usarFadePorMixer = true;

    [Tooltip("AudioMixer del proyecto (el mismo que usa el AudioManager).")]
    [SerializeField] private AudioMixer mixer;

    [Tooltip("Nombre EXACTO del parámetro expuesto para AX (ej: \"AXVol\").")]
    [SerializeField] private string axParam = "AXVol";

    [Tooltip("Duración del fade IN al entrar al gameplay (seg).")]
    [SerializeField] private float fadeIn = 0.5f;

    [Tooltip("Duración del fade OUT al salir del gameplay (seg).")]
    [SerializeField] private float fadeOut = 0.5f;

    private Coroutine _fadeCo;
    private float _axDbObjetivo = 0f; // recordamos el valor objetivo (p.ej. 0 dB)

    void Reset()
    {
        // Buscar AmbienceLayers en escena (incluye inactivos)
#if UNITY_2023_1_OR_NEWER
        if (ambientes == null)
            ambientes = FindFirstObjectByType<AmbienceLayers>(FindObjectsInactive.Include);
#else
        if (ambientes == null)
            ambientes = FindObjectOfType<AmbienceLayers>(true); // API antigua (obsoleta, pero válida)
#endif
    }

    /// <summary> Llamar cuando se muestra el panel de gameplay. </summary>
    public void EntrarGameplay()
    {
        if (ambientes == null) return;

        if (usarFadePorMixer && mixer != null && !string.IsNullOrEmpty(axParam))
        {
            // Guardamos el dB actual/objetivo (si no existe, asumimos 0 dB)
            if (!mixer.GetFloat(axParam, out _axDbObjetivo))
                _axDbObjetivo = 0f;

            // Arrancamos ambientes en silencio y hacemos fade al valor objetivo
            mixer.SetFloat(axParam, -80f);   // silencio práctico
            ambientes.Play();                // sin argumentos (tu API actual)

            LanzarFade(-80f, _axDbObjetivo, fadeIn, onComplete: null);
        }
        else
        {
            // Sin fade por mixer
            ambientes.Play(); // sin argumentos
        }
    }

    /// <summary> Llamar cuando sales/ocultas el panel de gameplay. </summary>
    public void SalirGameplay()
    {
        if (ambientes == null) return;

        if (usarFadePorMixer && mixer != null && !string.IsNullOrEmpty(axParam))
        {
            float desde;
            if (!mixer.GetFloat(axParam, out desde))
                desde = _axDbObjetivo;

            // Fade a silencio y, al finalizar, parar los ambientes
            LanzarFade(desde, -80f, fadeOut, onComplete: () => ambientes.Stop());
        }
        else
        {
            // Sin fade por mixer
            ambientes.Stop(); // sin argumentos
        }
    }

    // -------- utilidades --------

    private void LanzarFade(float fromDb, float toDb, float dur, System.Action onComplete)
    {
        if (_fadeCo != null) StopCoroutine(_fadeCo);
        _fadeCo = StartCoroutine(CoFadeMixer(fromDb, toDb, Mathf.Max(0f, dur), onComplete));
    }

    private IEnumerator CoFadeMixer(float fromDb, float toDb, float dur, System.Action onComplete)
    {
        if (mixer == null || string.IsNullOrEmpty(axParam) || dur <= 0f)
        {
            mixer?.SetFloat(axParam, toDb);
            onComplete?.Invoke();
            yield break;
        }

        float t = 0f;
        while (t < dur)
        {
            t += Time.unscaledDeltaTime; // fade no afectado por timescale
            float k = Mathf.Clamp01(t / dur);
            float db = Mathf.Lerp(fromDb, toDb, k); // fade lineal en dB (suena natural)
            mixer.SetFloat(axParam, db);
            yield return null;
        }

        mixer.SetFloat(axParam, toDb);
        onComplete?.Invoke();
    }
}

