using System.Collections;
using UnityEngine;
using UnityEngine.Events;

/// <summary>
/// Unidad visual de "rayo" controlada por un Animator.
/// Reproduce un estado (por nombre) y se DESACTIVA automáticamente
/// cuando el clip termina (sirve para reutilizar en un pool).
/// Ahora expone un evento para disparar SFX (con tu propio script de audio).
/// </summary>
[RequireComponent(typeof(Animator), typeof(SpriteRenderer))]
public class RayBurstUnit : MonoBehaviour
{
    [Header("Estados del Animator")]
    [Tooltip("Nombres EXACTOS de los estados en el Animator Controller (sin loop).")]
    public string[] nombresEstados = new[] { "Ray_A", "Ray_B", "Ray_C" };

    [Header("Audio (opcional)")]
    [Tooltip("Si está activo, dispara el evento SFX justo al activar la unidad.")]
    public bool dispararSFXAlActivar = true;

    [Tooltip("Evento que se invoca para reproducir el SFX del rayo. Conecta aquí tu script de SFX (método Play/Trigger).")]
    public UnityEvent onDisparoSFX;

    private Animator _anim;
    private Coroutine _rutina;

    void Awake()
    {
        _anim = GetComponent<Animator>();
        // Importante: que la animación avance aunque esté fuera de cámara
        _anim.cullingMode = AnimatorCullingMode.AlwaysAnimate;

        // Esta unidad normalmente vive desactivada hasta que el spawner la use
        gameObject.SetActive(false);
    }

    /// <summary>
    /// Activa la unidad, reproduce el estado indicado y se auto-desactiva al finalizar.
    /// </summary>
    /// <param name="indiceEstado">Índice dentro de 'nombresEstados'.</param>
    /// <param name="velocidadAnimator">Escala de velocidad (1 = normal).</param>
    public void Activar(int indiceEstado, float velocidadAnimator = 1f)
    {
        if (nombresEstados == null || nombresEstados.Length == 0) return;
        if (indiceEstado < 0 || indiceEstado >= nombresEstados.Length) indiceEstado = 0;

        gameObject.SetActive(true);

        _anim.speed = Mathf.Max(0.01f, velocidadAnimator);
        _anim.Play(nombresEstados[indiceEstado], 0, 0f);

        // 🔊 Opción A: disparar SFX justo al activar
        if (dispararSFXAlActivar)
            onDisparoSFX?.Invoke();

        if (_rutina != null) StopCoroutine(_rutina);
        _rutina = StartCoroutine(EsperarYDesactivar());
    }

    /// <summary>
    /// Espera a que el clip en curso termine (una reproducción) y desactiva el GO.
    /// </summary>
    private IEnumerator EsperarYDesactivar()
    {
        yield return null; // permitir que el Animator entre al estado

        while (true)
        {
            var st = _anim.GetCurrentAnimatorStateInfo(0);
            if (!_anim.IsInTransition(0) && st.normalizedTime >= 1f)
                break;
            yield return null;
        }

        gameObject.SetActive(false);
    }

    // 🔊 Opción B: llamado desde un Animation Event (colócalo en el frame deseado del clip)
    public void DispararSFX()
    {
        onDisparoSFX?.Invoke();
    }
}

