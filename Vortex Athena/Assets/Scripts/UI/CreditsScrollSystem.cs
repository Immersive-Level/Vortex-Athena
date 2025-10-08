using UnityEngine;
using UnityEngine.Events;
using TMPro;

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
    public float gapPixels = 200f;

    [Tooltip("Margen horizontal interno del viewport (evita recorte lateral)")]
    public float horizontalPadding = 24f;

    [Tooltip("Margen vertical en el componente TMP (evita recorte al entrar/salir)")]
    public float verticalMarginTMP = 8f;

    [Header("Eventos")]
    [Tooltip("Se invoca cuando los créditos terminan (solo en modo OneShot)")]
    public UnityEvent onCreditsCompleted;

    #endregion

    #region Runtime Variables

    private RectTransform _viewport;
    private TMP_Text _blockA, _blockB;
    private RectTransform _rtA, _rtB;
    private float _blockHeight;
    private bool _isPlaying;
    private bool _hasCompleted; // Para modo OneShot

    // Control de cuál bloque está "adelante" en modo OneShot
    private bool _blockAIsLeading = true;

    #endregion

    #region Public API

    /// <summary>
    /// Inicia la reproducción de los créditos
    /// </summary>
    public void Play()
    {
        _isPlaying = true;
    }

    /// <summary>
    /// Pausa la reproducción
    /// </summary>
    public void Pause()
    {
        _isPlaying = false;
    }

    /// <summary>
    /// Reinicia los créditos desde el principio
    /// </summary>
    public void Restart()
    {
        _hasCompleted = false;
        BuildCreditsBlocks();
        _isPlaying = true;
    }

    /// <summary>
    /// Detiene y resetea los créditos
    /// </summary>
    public void Stop()
    {
        _isPlaying = false;
        _hasCompleted = false;
    }

    /// <summary>
    /// Indica si los créditos están reproduciéndose actualmente
    /// </summary>
    public bool IsPlaying => _isPlaying;

    /// <summary>
    /// Indica si los créditos han completado su reproducción (solo OneShot)
    /// </summary>
    public bool HasCompleted => _hasCompleted;

    #endregion

    #region Unity Lifecycle

    private void OnEnable()
    {
        _viewport = GetComponent<RectTransform>();
        BuildCreditsBlocks();
        _isPlaying = autoStart;
        _hasCompleted = false;
    }

    private void Update()
    {
        if (!_isPlaying || _hasCompleted) return;
        if (_rtA == null || _rtB == null) return;

        float deltaTime = useUnscaledTime ? Time.unscaledDeltaTime : Time.deltaTime;
        if (deltaTime <= 0f) return;

        // Mover ambos bloques hacia arriba
        float displacement = speed * deltaTime;
        _rtA.anchoredPosition += new Vector2(0f, displacement);
        _rtB.anchoredPosition += new Vector2(0f, displacement);

        // Procesar según el modo de reproducción
        if (playbackMode == PlaybackMode.Loop)
        {
            ProcessLoopMode();
        }
        else // OneShot
        {
            ProcessOneShotMode();
        }
    }

    #endregion

    #region Loop Mode Logic

    /// <summary>
    /// En modo Loop, recicla los bloques cuando salen completamente por arriba
    /// </summary>
    private void ProcessLoopMode()
    {
        float viewportTop = _viewport.rect.height;

        // Protección contra saltos grandes de frame
        int maxRecycles = 4;

        while (maxRecycles-- > 0)
        {
            bool recycled = false;

            // Si el bloque A salió completamente por arriba
            if (BlockIsCompletelyAboveViewport(_rtA, viewportTop))
            {
                RecycleBlock(_rtA, _rtB);
                SwapBlocks();
                recycled = true;
            }
            // Si el bloque B salió completamente por arriba
            else if (BlockIsCompletelyAboveViewport(_rtB, viewportTop))
            {
                RecycleBlock(_rtB, _rtA);
                SwapBlocks();
                recycled = true;
            }

            if (!recycled) break;
        }
    }

    /// <summary>
    /// Recicla un bloque posicionándolo debajo del otro bloque
    /// </summary>
    private void RecycleBlock(RectTransform blockToRecycle, RectTransform referenceBlock)
    {
        float newY = referenceBlock.anchoredPosition.y - (_blockHeight + gapPixels);
        blockToRecycle.anchoredPosition = new Vector2(0f, newY);
    }

    #endregion

    #region OneShot Mode Logic

    /// <summary>
    /// En modo OneShot, detiene la reproducción cuando el último bloque sale por arriba
    /// </summary>
    private void ProcessOneShotMode()
    {
        float viewportTop = _viewport.rect.height;

        // Determinar cuál es el bloque que va adelante (el que está más arriba)
        RectTransform leadingBlock = _blockAIsLeading ? _rtA : _rtB;

        // Si el bloque líder sale completamente por arriba, terminamos
        if (BlockIsCompletelyAboveViewport(leadingBlock, viewportTop))
        {
            CompleteCredits();
        }
    }

    /// <summary>
    /// Finaliza la reproducción de créditos
    /// </summary>
    private void CompleteCredits()
    {
        _isPlaying = false;
        _hasCompleted = true;

        // Invocar evento de completado
        onCreditsCompleted?.Invoke();

        Debug.Log("[CreditsScrollSystem] Créditos completados");
    }

    #endregion

    #region Helper Methods

    /// <summary>
    /// Verifica si un bloque ha salido completamente del viewport por arriba
    /// </summary>
    private bool BlockIsCompletelyAboveViewport(RectTransform block, float viewportTop)
    {
        // Con pivot inferior (0,0), la posición Y del bloque es su borde inferior
        // Ha salido completamente cuando su borde inferior >= altura del viewport
        return block.anchoredPosition.y >= viewportTop;
    }

    /// <summary>
    /// Intercambia las referencias de los bloques
    /// </summary>
    private void SwapBlocks()
    {
        // Swap de referencias de RectTransform
        var tempRT = _rtA;
        _rtA = _rtB;
        _rtB = tempRT;

        // Swap de referencias de TMP_Text
        var tempText = _blockA;
        _blockA = _blockB;
        _blockB = tempText;

        // Alternar cuál está liderando
        _blockAIsLeading = !_blockAIsLeading;
    }

    #endregion

    #region Setup & Initialization

    /// <summary>
    /// Construye los bloques de texto para los créditos
    /// </summary>
    private void BuildCreditsBlocks()
    {
        // Limpiar instancias previas
        CleanupPreviousBlocks();

        // Obtener texto de créditos
        string creditsText = GetCreditsText();

        // Calcular ancho útil (viewport menos padding lateral)
        float usefulWidth = CalculateUsefulWidth();

        // Medir altura necesaria del bloque
        _blockHeight = MeasureBlockHeight(creditsText, usefulWidth);

        // Crear los bloques A y B
        CreateBlock(ref _blockA, ref _rtA, "Credits_BlockA", creditsText, usefulWidth);
        CreateBlock(ref _blockB, ref _rtB, "Credits_BlockB", creditsText, usefulWidth);

        // Posicionar bloques según el modo
        PositionInitialBlocks();

        // Resetear estado
        _blockAIsLeading = true;
    }

    /// <summary>
    /// Limpia bloques previos si existen
    /// </summary>
    private void CleanupPreviousBlocks()
    {
        if (_blockA != null) DestroyImmediate(_blockA.gameObject);
        if (_blockB != null) DestroyImmediate(_blockB.gameObject);
    }

    /// <summary>
    /// Obtiene el texto de créditos desde el archivo o la variable raw
    /// </summary>
    private string GetCreditsText()
    {
        string text = "";

        if (creditsFile != null && !string.IsNullOrEmpty(creditsFile.text))
        {
            text = creditsFile.text;
        }
        else if (!string.IsNullOrEmpty(creditsTextRaw))
        {
            text = creditsTextRaw;
        }
        else
        {
            text = "(Sin créditos configurados)";
        }

        return text;
    }

    /// <summary>
    /// Calcula el ancho útil disponible en el viewport
    /// </summary>
    private float CalculateUsefulWidth()
    {
        float viewportWidth = _viewport.rect.width;
        float totalHorizontalPadding = 2f * Mathf.Max(0f, horizontalPadding);
        return Mathf.Max(1f, viewportWidth - totalHorizontalPadding);
    }

    /// <summary>
    /// Mide la altura necesaria para un bloque de texto
    /// </summary>
    private float MeasureBlockHeight(string text, float width)
    {
        // Crear un probe temporal para medir
        var probe = Instantiate(textTemplate, _viewport);
        ConfigureBlockRectTransform(probe.rectTransform, width);
        ConfigureTextComponent(probe);
        probe.text = text;
        probe.gameObject.SetActive(true);

        // Forzar actualización y medir
        Canvas.ForceUpdateCanvases();
        float height = Mathf.Ceil(Mathf.Max(1f, probe.preferredHeight));

        // Limpiar probe
        DestroyImmediate(probe.gameObject);

        return height;
    }

    /// <summary>
    /// Crea y configura un bloque de texto
    /// </summary>
    private void CreateBlock(ref TMP_Text block, ref RectTransform rt, string name, string text, float width)
    {
        block = Instantiate(textTemplate, _viewport);
        block.gameObject.name = name;

        rt = block.rectTransform;
        ConfigureBlockRectTransform(rt, width);
        ConfigureTextComponent(block);

        block.text = text;
        block.gameObject.SetActive(true);

        Canvas.ForceUpdateCanvases();
    }

    /// <summary>
    /// Configura el RectTransform de un bloque como hijo del viewport
    /// </summary>
    private void ConfigureBlockRectTransform(RectTransform rt, float usefulWidth)
    {
        // Anchors: bottom-left a bottom-right (stretch horizontal, anclado abajo)
        rt.anchorMin = new Vector2(0f, 0f);
        rt.anchorMax = new Vector2(1f, 0f);

        // Pivot inferior (0 en Y) para que anchoredPosition.y sea el borde inferior
        rt.pivot = new Vector2(0.5f, 0f);

        // Aplicar padding horizontal usando offsets
        // offsetMin.x controla el margen izquierdo
        // offsetMax.x controla el margen derecho (negativo porque es desde la derecha)
        Vector2 offsetMin = rt.offsetMin;
        Vector2 offsetMax = rt.offsetMax;

        offsetMin.x = horizontalPadding;
        offsetMax.x = -horizontalPadding;

        rt.offsetMin = offsetMin;
        rt.offsetMax = offsetMax;
    }

    /// <summary>
    /// Configura el componente TMP_Text
    /// </summary>
    private void ConfigureTextComponent(TMP_Text text)
    {
        text.enableWordWrapping = true;
        text.overflowMode = TextOverflowModes.Overflow; // El viewport recorta con RectMask2D

        // Márgenes verticales para evitar recorte visual al entrar/salir del viewport
        text.margin = new Vector4(0f, verticalMarginTMP, 0f, verticalMarginTMP);
    }

    /// <summary>
    /// Posiciona los bloques en su estado inicial según el modo
    /// </summary>
    private void PositionInitialBlocks()
    {
        if (playbackMode == PlaybackMode.Loop)
        {
            // En modo Loop: A visible abajo (y=0), B esperando debajo
            _rtA.anchoredPosition = new Vector2(0f, 0f);
            _rtB.anchoredPosition = new Vector2(0f, -(_blockHeight + gapPixels));
        }
        else // OneShot
        {
            // En modo OneShot: A visible abajo (y=0), B no se usa (oculto muy abajo)
            _rtA.anchoredPosition = new Vector2(0f, 0f);
            _rtB.anchoredPosition = new Vector2(0f, -10000f); // Muy abajo, fuera de vista
        }
    }

    #endregion
}

/// <summary>
/// Modo de reproducción de los créditos
/// </summary>
public enum PlaybackMode
{
    /// <summary>
    /// Los créditos se reproducen una vez completa y se detienen
    /// </summary>
    OneShot,

    /// <summary>
    /// Los créditos se reproducen infinitamente en loop
    /// </summary>
    Loop
}