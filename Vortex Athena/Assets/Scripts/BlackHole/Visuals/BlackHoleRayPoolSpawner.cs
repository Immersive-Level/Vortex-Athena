using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Emisor de rayos para el agujero negro con POOL interno (sin prefabs externos).
/// - Usa un HIJO plantilla (desactivado) con SpriteRenderer + Animator + RayBurstUnit.
/// - Crea N copias como hijos y las reutiliza (evita GC).
/// - Emite rayos a intervalos aleatorios.
/// - Dos modos de aparición:
///     * SoloPivote: no mueve la posición; solo rota alrededor del centro.
///     * Anillo     : coloca la unidad sobre un anillo (radio) y la rota “hacia afuera”.
/// </summary>
public class BlackHoleRayPoolSpawner : MonoBehaviour
{
    public enum ModoAparicion { SoloPivote, Anillo }

    [Header("Plantilla (hijo desactivado)")]
    [Tooltip("Hijo del agujero negro: debe tener RayBurstUnit + Animator con 3 estados (sin loop).")]
    public RayBurstUnit plantillaRayo;

    [Header("Pool")]
    [Tooltip("Cantidad de unidades a pre-crear (límite de rayos simultáneos).")]
    public int tamanoPool = 6;

    [Header("Modo de aparición")]
    [Tooltip("SoloPivote = en (0,0) y solo rota; Anillo = posiciona en un radio alrededor.")]
    public ModoAparicion modo = ModoAparicion.SoloPivote;

    [Tooltip("Desplazamiento local (en unidades) si el pivote del arte no coincide con el centro real.")]
    public Vector2 desplazamientoPivoteLocal = Vector2.zero;

    [Header("Tiempos (segundos)")]
    [Tooltip("Tiempo mínimo entre emisiones.")]
    public float intervaloMin = 1.5f;

    [Tooltip("Tiempo máximo entre emisiones.")]
    public float intervaloMax = 4.0f;

    [Header("Geometría (solo para modo Anillo)")]
    [Tooltip("Radio base donde aparecerá la unidad (modo Anillo).")]
    public float radioAparicion = 1.2f;

    [Tooltip("Variación aleatoria del radio (+/-).")]
    public float variacionRadio = 0.3f;

    [Header("Rotación")]
    [Tooltip("Jitter aleatorio (± grados) a sumar a la rotación calculada.")]
    public float jitterAnguloGrados = 10f;

    [Header("Escala y velocidad de animación")]
    [Tooltip("Rango aleatorio de escala uniforme (X=Y).")]
    public Vector2 rangoEscalaUniforme = new Vector2(0.9f, 1.2f);

    [Tooltip("Rango aleatorio para Animator.speed (1 = normal).")]
    public Vector2 rangoVelocidadAnimator = new Vector2(0.95f, 1.05f);

    [Header("Límites")]
    [Tooltip("Máximo de rayos activos. 0 = sin límite.")]
    public int maxSimultaneos = 0;

    [Header("Depuración")]
    [Tooltip("Muestra mensajes en la consola con detalles de cada emisión.")]
    public bool logsDepuracion = false;

    // --- Runtime ---
    private readonly List<RayBurstUnit> _pool = new List<RayBurstUnit>();
    private Coroutine _bucle;

    void Awake()
    {
        if (plantillaRayo == null)
        {
            Debug.LogError("[BlackHoleRayPoolSpawner] Asigna 'plantillaRayo' (hijo con RayBurstUnit).");
            enabled = false;
            return;
        }

        // Aseguramos que la plantilla esté desactivada (no se usa directamente)
        plantillaRayo.gameObject.SetActive(false);

        // Contenedor para mantener el pool ordenado en jerarquía
        var contenedor = new GameObject("Pool_Rayos");
        contenedor.transform.SetParent(transform);
        contenedor.transform.localPosition = Vector3.zero;
        contenedor.transform.localRotation = Quaternion.identity;
        contenedor.transform.localScale = Vector3.one;

        // Crear el pool como hijos (copias de la plantilla)
        for (int i = 0; i < tamanoPool; i++)
        {
            var copia = Instantiate(plantillaRayo, contenedor.transform);
            copia.name = $"Rayo_{i:00}";
            copia.gameObject.SetActive(false);
            _pool.Add(copia);
        }
    }

    void OnEnable()
    {
        if (_bucle == null) _bucle = StartCoroutine(BucleEmision());
    }

    void OnDisable()
    {
        if (_bucle != null) { StopCoroutine(_bucle); _bucle = null; }
    }

    /// <summary>
    /// Bucle principal: espera aleatoria y dispara un rayo cuando haya una unidad libre.
    /// </summary>
    private IEnumerator BucleEmision()
    {
        var esperarFinDeFrame = new WaitForEndOfFrame();

        while (true)
        {
            // Respeta límite de simultáneos (si aplica)
            if (maxSimultaneos > 0 && ContarRayosActivos() >= maxSimultaneos)
            {
                yield return esperarFinDeFrame;
                continue;
            }

            // Espera aleatoria entre emisiones
            float espera = Random.Range(intervaloMin, intervaloMax);
            yield return new WaitForSeconds(espera);

            EmitirUno();
        }
    }

    /// <summary> Devuelve cuántos hijos del pool están activos. </summary>
    private int ContarRayosActivos()
    {
        int conteo = 0;
        for (int i = 0; i < transform.childCount; i++)
        {
            var ch = transform.GetChild(i);
            // Cuenta los que tengan Animator (nuestros rayos) y estén activos
            var anim = ch.GetComponentInChildren<Animator>(true);
            if (anim != null && ch.gameObject.activeInHierarchy)
                conteo++;
        }
        return conteo;
    }

    /// <summary> Busca una unidad libre (inactiva) dentro del pool. </summary>
    private RayBurstUnit ObtenerUnidadLibre()
    {
        for (int i = 0; i < _pool.Count; i++)
            if (!_pool[i].gameObject.activeSelf)
                return _pool[i];
        return null;
    }

    /// <summary>
    /// Configura posición/rotación/escala y activa la unidad con un estado aleatorio.
    /// </summary>
    private void EmitirUno()
    {
        var unidad = ObtenerUnidadLibre();
        if (unidad == null) return;

        // Escala aleatoria
        float escala = Random.Range(rangoEscalaUniforme.x, rangoEscalaUniforme.y);
        unidad.transform.localScale = new Vector3(escala, escala, 1f);

        // Velocidad aleatoria del Animator
        float vel = Random.Range(rangoVelocidadAnimator.x, rangoVelocidadAnimator.y);

        // Estado (clip) aleatorio por índice
        int idxEstado = (unidad.nombresEstados != null && unidad.nombresEstados.Length > 0)
            ? Random.Range(0, unidad.nombresEstados.Length)
            : 0;

        switch (modo)
        {
            case ModoAparicion.SoloPivote:
                {
                    // Posición: centrada en el pivote (más un pequeño offset si lo requieres)
                    unidad.transform.localPosition = (Vector3)desplazamientoPivoteLocal;

                    // Rotación: completamente aleatoria 0..360 + jitter
                    float anguloBase = Random.Range(0f, 360f);
                    float jitter = Random.Range(-jitterAnguloGrados, jitterAnguloGrados);
                    unidad.transform.localRotation = Quaternion.Euler(0f, 0f, anguloBase + jitter);
                }
                break;

            case ModoAparicion.Anillo:
                {
                    // Posición: punto aleatorio en un anillo alrededor del centro
                    Vector2 dir = Random.insideUnitCircle.normalized;
                    float r = radioAparicion + Random.Range(-variacionRadio, variacionRadio);
                    unidad.transform.localPosition = (Vector3)(dir * Mathf.Max(0f, r)) + (Vector3)desplazamientoPivoteLocal;

                    // Rotación: mirando hacia afuera (suponiendo sprites apuntan a +Y) + jitter
                    float anguloBase = Mathf.Atan2(dir.y, dir.x) * Mathf.Rad2Deg - 90f;
                    float jitter = Random.Range(-jitterAnguloGrados, jitterAnguloGrados);
                    unidad.transform.localRotation = Quaternion.Euler(0f, 0f, anguloBase + jitter);
                }
                break;
        }

        // ¡Reproducir!
        unidad.Activar(idxEstado, vel);

        if (logsDepuracion)
            Debug.Log($"[BlackHole] Emitido estado #{idxEstado} | modo {modo} | rotZ={unidad.transform.localEulerAngles.z:0.0}");
    }

    void OnDrawGizmosSelected()
    {
        if (modo == ModoAparicion.Anillo)
        {
            Gizmos.color = new Color(1f, 0.7f, 0.1f, 0.5f);
            Gizmos.DrawWireSphere(transform.position, radioAparicion);
        }
    }
}

