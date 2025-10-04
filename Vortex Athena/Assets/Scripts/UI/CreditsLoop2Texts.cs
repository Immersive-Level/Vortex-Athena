using UnityEngine;
using TMPro;

/// Loop de créditos con 2 TMP_Text como HIJOS del Viewport (sin contenedor extra).
/// Usa offsets para padding (no sizeDelta), así no se recorta en los laterales.
/// Recicla cuando el BLOQUE sale COMPLETAMENTE por arriba.
public class CreditsLoop2Texts : MonoBehaviour
{
    [Header("Plantilla / Contenido")]
    public TMP_Text textTemplate;              // tu TMP de estilo (puede estar desactivado)
    [TextArea(10, 40)] public string creditsTextRaw;
    public TextAsset creditsFile;              // opcional (prioridad)

    [Header("Movimiento")]
    public float speed = 80f;
    public bool useUnscaledTime = true;
    public bool autoStart = true;

    [Header("Espaciado y Padding")]
    public float gapPixels = 0f;              // 0 = sin hueco
    public float horizontalPadding = 24f;     // margen interior izq/der dentro del Viewport
    public float verticalMarginTMP = 8f;      // margen superior/inferior en TMP (no recorte)

    // runtime
    RectTransform _viewport;                  // este mismo RT
    TMP_Text _A, _B; RectTransform _rtA, _rtB;
    float _blockHeight;
    bool _running;

    void OnEnable()
    {
        _viewport = GetComponent<RectTransform>();
        Build();
        _running = autoStart;
    }

    void Update()
    {
        if (!_running || _rtA == null || _rtB == null) return;

        float dt = useUnscaledTime ? Time.unscaledDeltaTime : Time.deltaTime;
        if (dt <= 0f) return;

        float dy = speed * dt;
        _rtA.anchoredPosition += new Vector2(0f, dy);
        _rtB.anchoredPosition += new Vector2(0f, dy);

        // Reciclar cuando el BLOQUE ha salido completamente por arriba:
        // con pivot inferior, "bottom" del bloque = anchoredPosition.y
        float topLimit = _viewport.rect.height;

        // seguridad por si el frame salta mucho
        int safety = 4;
        while (safety-- > 0)
        {
            bool recycled = false;

            if (_rtA.anchoredPosition.y >= topLimit)
            {
                _rtA.anchoredPosition = new Vector2(0f, _rtB.anchoredPosition.y - (_blockHeight + gapPixels));
                Swap(ref _rtA, ref _rtB); Swap(ref _A, ref _B);
                recycled = true;
            }
            if (_rtB.anchoredPosition.y >= topLimit)
            {
                _rtB.anchoredPosition = new Vector2(0f, _rtA.anchoredPosition.y - (_blockHeight + gapPixels));
                Swap(ref _rtA, ref _rtB); Swap(ref _A, ref _B);
                recycled = true;
            }
            if (!recycled) break;
        }
    }

    // ------- helpers -------
    void Build()
    {
        // Limpia instancias previas
        if (_A) DestroyImmediate(_A.gameObject);
        if (_B) DestroyImmediate(_B.gameObject);

        // Texto
        string block = (creditsFile && !string.IsNullOrEmpty(creditsFile.text)) ? creditsFile.text : creditsTextRaw;
        if (string.IsNullOrWhiteSpace(block)) block = "(Sin créditos)";

        // Crear probe para medir altura con el ANCHO útil = viewport - padding*2
        float widthUseful = Mathf.Max(1f, _viewport.rect.width - 2f * Mathf.Max(0f, horizontalPadding));
        var probe = Instantiate(textTemplate, _viewport);
        PrepareAsChildOfViewport(probe.rectTransform, widthUseful);
        ApplyTmpSetup(probe);
        probe.text = block;
        probe.gameObject.SetActive(true);
        Canvas.ForceUpdateCanvases();
        _blockHeight = Mathf.Ceil(Mathf.Max(1f, probe.preferredHeight));
        DestroyImmediate(probe.gameObject);

        // Instanciar A y B como HIJOS DIRECTOS del Viewport
        _A = Instantiate(textTemplate, _viewport);
        _B = Instantiate(textTemplate, _viewport);
        _A.gameObject.name = "Credits_A";
        _B.gameObject.name = "Credits_B";
        PrepareAsChildOfViewport(_A.rectTransform, widthUseful);
        PrepareAsChildOfViewport(_B.rectTransform, widthUseful);
        ApplyTmpSetup(_A); ApplyTmpSetup(_B);
        _A.text = block; _B.text = block;
        _A.gameObject.SetActive(true); _B.gameObject.SetActive(true);
        _rtA = _A.rectTransform; _rtB = _B.rectTransform;

        Canvas.ForceUpdateCanvases();
        _blockHeight = Mathf.Ceil(Mathf.Max(_A.preferredHeight, _B.preferredHeight));

        // Posición de arranque visible inmediata:
        // A en y=0 (pegado abajo), B justo debajo
        _rtA.anchoredPosition = new Vector2(0f, 0f);
        _rtB.anchoredPosition = new Vector2(0f, -(_blockHeight + gapPixels));
    }

    void PrepareAsChildOfViewport(RectTransform rt, float widthUseful)
    {
        // Anchors al bottom, stretch horizontal y PIVOT INFERIOR
        rt.anchorMin = new Vector2(0f, 0f);
        rt.anchorMax = new Vector2(1f, 0f);
        rt.pivot = new Vector2(0.5f, 0f);

        // Offsets para padding lateral: offsetMin.x = +padding (izq), offsetMax.x = -padding (der)
        var offMin = rt.offsetMin;
        var offMax = rt.offsetMax;
        offMin.x = horizontalPadding;
        offMax.x = -horizontalPadding;
        // bottom/top offsets se mantienen (usamos márgenes de TMP para el padding vertical)
        rt.offsetMin = offMin;
        rt.offsetMax = offMax;
    }

    void ApplyTmpSetup(TMP_Text t)
    {
        t.enableWordWrapping = true;
        t.overflowMode = TextOverflowModes.Overflow; // el Viewport ya recorta con RectMask2D
        // Márgenes verticales en TMP para que no "peine" al entrar/salir
        t.margin = new Vector4(0f, verticalMarginTMP, 0f, verticalMarginTMP);
    }

    void Swap<T>(ref T a, ref T b) { var tmp = a; a = b; b = tmp; }

    public void Play() => _running = true;
    public void Pause() => _running = false;
    public void Restart() { Build(); _running = true; }
}
