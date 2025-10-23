using UnityEngine;
using UnityEngine.Events;
using TMPro;
using System.Collections;

/// <summary>
/// Sistema de scroll de créditos con soporte para reproducción única o loop infinito.
/// Usa 2 bloques de texto (A/B) para scroll eficiente sin recortes laterales.
/// </summary>
public class CreditsScrollSystem : MonoBehaviour
{
    #region Configuration

    [Header("Contenido")]
    [Tooltip("Plantilla de estilo para los textos (puede estar desactivada)")]
    public TMP_Text textTemplate;

    [TextArea(10, 40)]
    [Tooltip("Texto de créditos (se usa si no hay TextAsset)")]
    public string creditsTextRaw;

    [Tooltip("Archivo de texto con créditos (tiene prioridad sobre creditsTextRaw)")]
    public TextAsset creditsFile;

    [Header("Modo de Reproducción")]
    [Tooltip("OneShot: Se reproduce una vez completo y se detiene\nLoop: Se reproduce infinitamente")]
    public PlaybackMode playbackMode = PlaybackMode.OneShot;

    [Header("Movimiento")]
    [Tooltip("Velocidad de scroll en píxeles por segundo")]
    public float speed = 80f;

    [Tooltip("Usar Time.unscaledDeltaTime (ignora pausas de Time.timeScale)")]
    public bool useUnscaledTime = true;

    [Tooltip("Comenzar reproducción automáticamente al activarse")]
    public bool autoStart = true;

    [Header("Espaciado y Padding")]
    [Tooltip("Espacio en píxeles entre bloques en modo Loop")]
    public float gapPixels = 0f; // <— deja 0 si no quieres huecos nunca

    [Tooltip("Margen horizontal interno del viewport (evita recorte lateral)")]
    public float horizontalPadding = 24f;

    [Tooltip("Margen vertical en el componente TMP (evita recorte al entrar/salir)")]
    public float verticalMarginTMP = 8f;

    [Header("Robustez")]
    [Tooltip("Espera a que el viewport estabilice tamaño/aspecto antes de medir")]
    public bool waitForViewportSettle = true;

    [Tooltip("Frames consecutivos con mismo tamaño para considerarlo 'estable'")]
    public int settleFrames = 2;

    [Tooltip("Máximo de frames de espera tras habilitar")]
    public int maxWaitFrames = 12;

    [Tooltip("Reconstruir si cambia el tamaño del viewport en runtime")]
    public bool rebuildOnViewportResize = false;

    [Header("Eventos")]
    [Tooltip("Se invoca cuando los créditos terminan (solo en modo OneShot)")]
    public UnityEvent onCreditsCompleted;

    #endregion

    #region Runtime Variables

    private RectTransform _viewport;
    private TMP_Text _blockA, _blockB;
    private RectTransform _rtA, _rtB;

    // Altura REAL de cada bloque (igual contenido, pero lo almacenamos separado por seguridad)
    private float _heightA, _heightB;

    private bool _isPlaying;
    private bool _hasCompleted; // Para modo OneShot
    private bool _blockAIsLeading = true;

    // Tracking de viewport para reconstrucciones
    private Vector2 _lastViewportSize;

    #endregion

    #region Public API

    public void Play() { _isPlaying = true; }
    public void Pause() { _isPlaying = false; }
    public void Stop() { _isPlaying = false; _hasCompleted = false; }
    public bool IsPlaying => _isPlaying;
    public bool HasCompleted => _hasCompleted;

    public void Restart()
    {
        _hasCompleted = false;
        BuildCreditsBlocks();
        _isPlaying = true;
    }

    #endregion

    #region Unity Lifecycle

    private void OnEnable()
    {
        _viewport = GetComponent<RectTransform>();
        _isPlaying = false; // arrancamos tras construir
        _hasCompleted = false;
        StartCoroutine(InitAfterViewportSettle());
    }

    private IEnumerator InitAfterViewportSettle()
    {
        if (waitForViewportSettle && _viewport != null)
        {
            int stable = 0, tries = 0;
            Vector2 last = Vector2.negativeInfinity;

            while (stable < settleFrames && tries < maxWaitFrames)
            {
                Vector2 now = _viewport.rect.size;
                if (Approximately(now, last)) stable++; else { stable = 0; last = now; }
                tries++;
                yield return null; // espera frame
            }
        }

        BuildCreditsBlocks();
        _isPlaying = autoStart;
    }

    private void Update()
    {
        if (!_isPlaying || _hasCompleted) return;
        if (_rtA == null || _rtB == null) return;

        // Detectar cambio de tamaño del viewport y reconstruir si está activado
        if (rebuildOnViewportResize && _viewport != null)
        {
            Vector2 size = _viewport.rect.size;
            if (!Approximately(size, _lastViewportSize))
            {
                BuildCreditsBlocks();
            }
        }

        float deltaTime = useUnscaledTime ? Time.unscaledDeltaTime : Time.deltaTime;
        if (deltaTime <= 0f) return;

        // Mover ambos bloques hacia arriba
        float displacement = speed * deltaTime;
        _rtA.anchoredPosition += new Vector2(0f, displacement);
        _rtB.anchoredPosition += new Vector2(0f, displacement);

        if (playbackMode == PlaybackMode.Loop) ProcessLoopMode();
        else ProcessOneShotMode();
    }

    #endregion

    #region Loop Mode Logic

    private void ProcessLoopMode()
    {
        float viewportTop = _viewport.rect.height;

        // Protección contra saltos grandes de frame
        int maxRecycles = 4;

        while (maxRecycles-- > 0)
        {
            bool recycled = false;

            if (BlockIsCompletelyAboveViewport(_rtA, viewportTop))
            {
                RecycleBlock(_rtA, _rtB, _heightA);
                SwapBlocks(); // A <-> B para mantener referencia de “líder”
                recycled = true;
            }
            else if (BlockIsCompletelyAboveViewport(_rtB, viewportTop))
            {
                RecycleBlock(_rtB, _rtA, _heightB);
                SwapBlocks();
                recycled = true;
            }

            if (!recycled) break;
        }
    }

    /// <summary>
    /// Posiciona blockToRecycle justo DEBAJO de referenceBlock usando su ALTURA real + gap.
    /// </summary>
    private void RecycleBlock(RectTransform blockToRecycle, RectTransform referenceBlock, float recycleHeight)
    {
        float newY = referenceBlock.anchoredPosition.y - (recycleHeight + gapPixels);
        blockToRecycle.anchoredPosition = new Vector2(0f, newY);
    }

    #endregion

    #region OneShot Mode Logic

    private void ProcessOneShotMode()
    {
        float viewportTop = _viewport.rect.height;
        RectTransform leadingBlock = _blockAIsLeading ? _rtA : _rtB;

        if (BlockIsCompletelyAboveViewport(leadingBlock, viewportTop))
        {
            CompleteCredits();
        }
    }

    private void CompleteCredits()
    {
        _isPlaying = false;
        _hasCompleted = true;
        onCreditsCompleted?.Invoke();
        Debug.Log("[CreditsScrollSystem] Créditos completados");
    }

    #endregion

    #region Helper Methods

    private static bool Approximately(Vector2 a, Vector2 b)
        => Mathf.Approximately(a.x, b.x) && Mathf.Approximately(a.y, b.y);

    private bool BlockIsCompletelyAboveViewport(RectTransform block, float viewportTop)
    {
        // Con pivot inferior (0,0), la posición Y del bloque es su borde inferior.
        // Está 100% fuera cuando el borde inferior >= altura del viewport.
        return block.anchoredPosition.y >= viewportTop;
    }

    private void SwapBlocks()
    {
        var tempRT = _rtA; _rtA = _rtB; _rtB = tempRT;
        var tempTx = _blockA; _blockA = _blockB; _blockB = tempTx;
        (_heightA, _heightB) = (_heightB, _heightA);
        _blockAIsLeading = !_blockAIsLeading;
    }

    #endregion

    #region Setup & Initialization

    private void BuildCreditsBlocks()
    {
        CleanupPreviousBlocks();

        string creditsText = GetCreditsText();

        // Guardar tamaño actual del viewport para detectar cambios posteriores
        _lastViewportSize = _viewport != null ? _viewport.rect.size : Vector2.zero;

        // Crear bloques
        CreateBlock(ref _blockA, ref _rtA, "Credits_BlockA", creditsText);
        CreateBlock(ref _blockB, ref _rtB, "Credits_BlockB", creditsText);

        // Medir y fijar altura real de cada bloque (muy importante)
        _heightA = MeasureAndFixHeight(_blockA, _rtA);
        _heightB = MeasureAndFixHeight(_blockB, _rtB);

        PositionInitialBlocks();

        _blockAIsLeading = true;
    }

    private void CleanupPreviousBlocks()
    {
        if (_blockA != null) DestroyImmediate(_blockA.gameObject);
        if (_blockB != null) DestroyImmediate(_blockB.gameObject);
        _blockA = _blockB = null;
        _rtA = _rtB = null;
    }

    private string GetCreditsText()
    {
        if (creditsFile != null && !string.IsNullOrEmpty(creditsFile.text))
            return creditsFile.text;

        if (!string.IsNullOrEmpty(creditsTextRaw))
            return creditsTextRaw;

        return "(Sin créditos configurados)";
    }

    private void CreateBlock(ref TMP_Text block, ref RectTransform rt, string name, string text)
    {
        block = Instantiate(textTemplate, transform as RectTransform);
        block.gameObject.name = name;

        rt = block.rectTransform;
        ConfigureBlockRectTransform(rt);
        ConfigureTextComponent(block);

        block.text = text;
        block.gameObject.SetActive(true);
    }

    private void ConfigureBlockRectTransform(RectTransform rt)
    {
        // Anchors: stretch horizontal, anclado abajo
        rt.anchorMin = new Vector2(0f, 0f);
        rt.anchorMax = new Vector2(1f, 0f);
        rt.pivot = new Vector2(0.5f, 0f);

        // Padding horizontal via offsets
        Vector2 offsetMin = rt.offsetMin;
        Vector2 offsetMax = rt.offsetMax;
        offsetMin.x = horizontalPadding;
        offsetMax.x = -horizontalPadding;
        rt.offsetMin = offsetMin;
        rt.offsetMax = offsetMax;

        // Reset X/Y y tamaño Y provisional
        rt.anchoredPosition = Vector2.zero;
        rt.SetSizeWithCurrentAnchors(RectTransform.Axis.Vertical, 10f);
    }

    private void ConfigureTextComponent(TMP_Text text)
    {
        text.enableWordWrapping = true;
        text.overflowMode = TextOverflowModes.Overflow;
        text.margin = new Vector4(0f, verticalMarginTMP, 0f, verticalMarginTMP);
    }

    /// <summary>
    /// Fuerza el cálculo de layout y fija la altura del RectTransform al preferredHeight.
    /// Devuelve la altura final usada por el bloque.
    /// </summary>
    private float MeasureAndFixHeight(TMP_Text txt, RectTransform rt)
    {
        Canvas.ForceUpdateCanvases();
        float h = Mathf.Ceil(Mathf.Max(1f, txt.preferredHeight));
        rt.SetSizeWithCurrentAnchors(RectTransform.Axis.Vertical, h);
        return h;
    }

    private void PositionInitialBlocks()
    {
        if (playbackMode == PlaybackMode.Loop)
        {
            _rtA.anchoredPosition = new Vector2(0f, 0f);                         // A visible
            _rtB.anchoredPosition = new Vector2(0f, -(_heightB + gapPixels));    // B justo debajo
        }
        else
        {
            _rtA.anchoredPosition = new Vector2(0f, 0f);
            _rtB.anchoredPosition = new Vector2(0f, -10000f);
        }
    }

    #endregion
}

/// <summary>
/// Modo de reproducción de los créditos
/// </summary>
public enum PlaybackMode
{
    /// <summary>Los créditos se reproducen una vez completa y se detienen</summary>
    OneShot,
    /// <summary>Los créditos se reproducen infinitamente en loop</summary>
    Loop
}
