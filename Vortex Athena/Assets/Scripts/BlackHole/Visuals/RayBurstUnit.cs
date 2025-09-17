using System.Collections;
using UnityEngine;
using UnityEngine.Events;

[RequireComponent(typeof(Animator), typeof(SpriteRenderer))]
public class RayBurstUnit : MonoBehaviour
{
    [Header("Estados del Animator")]
    public string[] nombresEstados = new[] { "Ray_A", "Ray_B", "Ray_C" };

    [Header("Audio (opcional)")]
    public bool dispararSFXAlActivar = true;
    public UnityEvent onDisparoSFX;

    private Animator _anim;
    private Coroutine _rutina;

    void Awake()
    {
        _anim = GetComponent<Animator>();
        _anim.cullingMode = AnimatorCullingMode.AlwaysAnimate;
        gameObject.SetActive(false);
    }

    public void Activar(int indiceEstado, float velocidadAnimator = 1f)
    {
        if (nombresEstados == null || nombresEstados.Length == 0) return;
        if (indiceEstado < 0 || indiceEstado >= nombresEstados.Length) indiceEstado = 0;

        // Activa el GO primero
        if (!gameObject.activeSelf) gameObject.SetActive(true);
        if (!isActiveAndEnabled) return; // si el componente está deshabilitado, aborta

        // Reinicia cualquier corrutina previa
        if (_rutina != null) StopCoroutine(_rutina);
        _rutina = StartCoroutine(CoReproducir(indiceEstado, Mathf.Max(0.01f, velocidadAnimator)));
    }

    private IEnumerator CoReproducir(int idx, float speed)
    {
        // Espera 1 frame para garantizar que el Animator ya está “vivo”
        yield return null;
        if (!isActiveAndEnabled) yield break;

        _anim.speed = speed;
        _anim.Play(nombresEstados[idx], 0, 0f);

        if (dispararSFXAlActivar)
            onDisparoSFX?.Invoke();

        // Espera a que el estado termine 1 reproducción.
        while (isActiveAndEnabled && gameObject.activeInHierarchy)
        {
            var st = _anim.GetCurrentAnimatorStateInfo(0);
            if (!_anim.IsInTransition(0) && st.normalizedTime >= 1f) break;
            yield return null;
        }

        if (gameObject.activeSelf) gameObject.SetActive(false);
    }

    // Opción por Animation Event (si quieres disparar en un frame específico)
    public void DispararSFX() => onDisparoSFX?.Invoke();
}

