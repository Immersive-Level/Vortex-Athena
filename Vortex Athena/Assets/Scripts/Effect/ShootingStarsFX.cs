using UnityEngine;

[RequireComponent(typeof(ParticleSystem))]
[ExecuteAlways] // configura Trails también en modo Edit
public class ShootingStarsFX : MonoBehaviour
{
    [Header("Frecuencia de aparición")]
    public Vector2 intervaloSpawn = new Vector2(1.5f, 4f);   // seg entre estrellas

    [Header("Movimiento")]
    public Vector2 velocidadRango = new Vector2(6f, 10f);    // unidades/s
    public Vector2 anguloDesvio = new Vector2(-20f, 20f);  // grados de desvío respecto al eje de entrada
    public float padding = 0.5f;                              // nace un poco fuera del borde
    public float zDepth = 0f;                                // z en mundo

    [Header("Apariencia (partícula)")]
    public Vector2 tamanoRango = new Vector2(0.02f, 0.05f);
    public Vector2 alphaRango = new Vector2(0.7f, 1f);
    public Material materialParticula; // URP: Universal RP/Particles/Unlit (Transparent + Additive)

    [Header("Trail (estela)")]
    public bool habilitarTrail = true;
    public float trailLifetime = 0.25f;   // duración de la estela
    public float trailWidth = 0.05f;   // grosor constante en unidades de mundo

    private Camera cam;
    private ParticleSystem ps;
    private float tNext;

    // … campos existentes …
    [Header("Orden de dibujo")]
    public string sortingLayerName = "Fondo";
    public int sortingOrder = -100; // más bajo que muros/fondo

    void Awake()
    {
        ps = GetComponent<ParticleSystem>();
        ConfigurarPS();
        cam = Camera.main;

        if (Application.isPlaying)
            ProgramarSiguiente();
    }

    void OnEnable()
    {
        // En caso de reactivar el objeto en Play, reprogramamos
        if (Application.isPlaying)
            ProgramarSiguiente();
    }

    void OnValidate()
    {
        if (intervaloSpawn.x < 0.05f) intervaloSpawn.x = 0.05f;
        if (intervaloSpawn.y < intervaloSpawn.x) intervaloSpawn.y = intervaloSpawn.x;

        if (ps == null) ps = GetComponent<ParticleSystem>();
        ConfigurarPS();
    }

    void Update()
    {
        // No emitir en modo edición
        if (!Application.isPlaying) return;

        if (cam == null) cam = Camera.main;
        if (Time.time >= tNext)
        {
            EmitirUna();
            ProgramarSiguiente();
        }
    }

    // ---------- Configuración del ParticleSystem ----------
    void ConfigurarPS()
    {
        var main = ps.main;
        main.playOnAwake = true;
        main.loop = true;
        main.simulationSpace = ParticleSystemSimulationSpace.World;
        main.maxParticles = 1024;
        main.startSpeed = 0f;   // se lo damos por EmitParams
        main.startSize = 1f;   // se lo damos por EmitParams
        main.startLifetime = 1f;
        main.duration = 10f;
#if UNITY_2022_1_OR_NEWER
        main.scalingMode = ParticleSystemScalingMode.Shape;
#endif

        var emission = ps.emission;
        emission.enabled = false;    // emitimos manualmente

        var shape = ps.shape;
        shape.enabled = false;

        // Trails visibles también en modo edición
        var trails = ps.trails;
        trails.enabled = habilitarTrail;
        trails.lifetime = trailLifetime;
        trails.worldSpace = true;
        trails.sizeAffectsWidth = false; // grosor independiente del tamaño de partícula
        trails.minVertexDistance = 0.05f;
        trails.widthOverTrail = new ParticleSystem.MinMaxCurve(trailWidth);

        // Material tanto para partícula como para trail
        var r = ps.GetComponent<ParticleSystemRenderer>();
        if (materialParticula != null)
        {
            r.material = materialParticula;
            r.trailMaterial = materialParticula;
        }
        r.sortingLayerName = sortingLayerName;  // ⟵ AQUI
        r.sortingOrder = sortingOrder;      // ⟵ AQUI
    }

    // ---------- Emisión de una estrella fugaz ----------
    void ProgramarSiguiente()
    {
        tNext = Time.time + Random.Range(intervaloSpawn.x, intervaloSpawn.y);
    }

    void EmitirUna()
    {
        if (cam == null || !cam.orthographic) return;

        float halfH = cam.orthographicSize;
        float halfW = halfH * cam.aspect;

        // Elige un borde al azar: 0 izq, 1 der, 2 abajo, 3 arriba
        int borde = Random.Range(0, 4);
        Vector3 pos = Vector3.zero;
        Vector2 dirBase = Vector2.right;

        switch (borde)
        {
            case 0: pos = new Vector3(-halfW - padding, Random.Range(-halfH, halfH), zDepth); dirBase = Vector2.right; break;
            case 1: pos = new Vector3(halfW + padding, Random.Range(-halfH, halfH), zDepth); dirBase = Vector2.left; break;
            case 2: pos = new Vector3(Random.Range(-halfW, halfW), -halfH - padding, zDepth); dirBase = Vector2.up; break;
            default: pos = new Vector3(Random.Range(-halfW, halfW), halfH + padding, zDepth); dirBase = Vector2.down; break;
        }

        // Centrar respecto a la posición actual de la cámara
        Vector3 camCenter = cam.transform.position;
        pos += new Vector3(camCenter.x, camCenter.y, 0f);

        // Dirección con pequeño desvío
        float angle = Random.Range(anguloDesvio.x, anguloDesvio.y);
        Vector2 dir = (Quaternion.Euler(0, 0, angle) * dirBase).normalized;

        float speed = Random.Range(velocidadRango.x, velocidadRango.y);

        // Vida suficiente para cruzar la pantalla (según el eje de entrada)
        float distX = (halfW + padding) * 2f;
        float distY = (halfH + padding) * 2f;
        float distancia = (borde <= 1) ? distX : distY;
        float lifetime = Mathf.Max(0.05f, distancia / speed);

        var ep = new ParticleSystem.EmitParams();
        ep.position = pos;
        ep.velocity = dir * speed;
        ep.startLifetime = lifetime;
        ep.startSize = Random.Range(tamanoRango.x, tamanoRango.y);
        float a = Random.Range(alphaRango.x, alphaRango.y);
        ep.startColor = new Color(1f, 1f, 1f, a);

        ps.Emit(ep, 1);
    }
}

