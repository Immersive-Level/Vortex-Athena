using UnityEngine;
using TMPro;

/// <summary>
/// Créditos “tipo película” con loop infinito usando un único TMP_Text.
/// - Pega el texto en 'creditsTextRaw' o asigna un TextAsset.
/// - Requiere un Viewport con RectMask2D y dentro un TMP_Text (creditsText).
/// - Controla el espaciado entre bloques desde el Inspector con 'gapBlankLines'.
/// </summary>
[RequireComponent(typeof(RectTransform))]
public class CreditsLoopText : MonoBehaviour
{
    [Header("Referencias")]
    [Tooltip("Rect del área visible (panel con RectMask2D). (Solo para validar que está asignado)")]
    public RectTransform viewport;

    [Tooltip("TextMeshProUGUI que mostrará los créditos.")]
    public TMP_Text creditsText;

    [Header("Contenido")]
    [Tooltip("Pega aquí la lista completa de créditos (texto plano, puede tener saltos de línea).")]
    [TextArea(10, 40)]
    public string creditsTextRaw;

    [Tooltip("Opcional: asigna un TextAsset (.txt) con los créditos. Si se asigna, tiene prioridad sobre el texto pegado.")]
    public TextAsset creditsFile;

    [Header("Espaciado")]
    [Tooltip("Líneas en blanco entre el final y el inicio del loop (separador entre bloques).")]
    [Min(0)] public int gapBlankLines = 2;

    [Header("Movimiento")]
    [Tooltip("Velocidad del scroll en píxeles por segundo.")]
    public float speed = 80f;

    [Tooltip("Usar tiempo no escalado (ignora Time.timeScale).")]
    public bool useUnscaledTime = true;

    [Tooltip("Arranca automáticamente al habilitar el objeto.")]
    public bool autoStart = true;

    // runtime
    RectTransform _rt;
    string _originalBlock;
    float _blockHeight;
    bool _running;

    void Awake()
    {
        _rt = GetComponent<RectTransform>();
    }

    void OnEnable()
    {
        if (creditsText == null || viewport == null)
        {
            Debug.LogWarning("[CreditsLoopText] Asigna viewport y creditsText.");
            return;
        }

        BuildAndMeasure();
        _running = autoStart;
    }

    void Update()
    {
        if (!_running || creditsText == null) return;

        float dt = useUnscaledTime ? Time.unscaledDeltaTime : Time.deltaTime;
        if (dt <= 0f) return;

        // Mover hacia arriba
        RectTransform txtRT = creditsText.rectTransform;
        Vector2 pos = txtRT.anchoredPosition;
        pos.y += speed * dt;
        txtRT.anchoredPosition = pos;

        // Cuando recorrió al menos la altura de UN bloque, retrocede esa misma altura
        if (pos.y >= _blockHeight)
        {
            pos.y -= _blockHeight;
            txtRT.anchoredPosition = pos;
        }
    }

    void BuildAndMeasure()
    {
        // 1) Cargar contenido (file > raw > fallback)
        if (creditsFile != null && !string.IsNullOrEmpty(creditsFile.text))
            _originalBlock = creditsFile.text;
        else
            _originalBlock = creditsTextRaw;

        if (string.IsNullOrWhiteSpace(_originalBlock))
        {
            Debug.LogWarning("[CreditsLoopText] No hay texto de créditos.");
            return;
        }

        // 2) Preparar loop: bloque + separador + bloque
        string sep = MakeSeparator(gapBlankLines);
        creditsText.text = _originalBlock + sep + _originalBlock;

        // 3) Forzar layout para medir PreferredHeight del bloque ORIGINAL
        Canvas.ForceUpdateCanvases();
        _blockHeight = MeasureSingleBlockHeight(_originalBlock, creditsText);

        // 4) Reset posición al inicio
        Vector2 pos = creditsText.rectTransform.anchoredPosition;
        pos.y = 0f;
        creditsText.rectTransform.anchoredPosition = pos;
    }

    float MeasureSingleBlockHeight(string block, TMP_Text tmp)
    {
        // Guardamos y restauramos el texto para medir la altura del bloque original
        string backup = tmp.text;

        tmp.text = block;
        tmp.ForceMeshUpdate(); // asegura cálculo de preferredHeight
        float h = tmp.preferredHeight;

        // Restaurar el duplicado para el loop
        string sep = MakeSeparator(gapBlankLines);
        tmp.text = block + sep + block;
        tmp.ForceMeshUpdate();

        return Mathf.Max(1f, h);
    }

    string MakeSeparator(int emptyLines)
    {
        if (emptyLines <= 0) return "\n"; // al menos un salto para evitar empalme duro
        return new string('\n', emptyLines);
    }

    public void Play() => _running = true;
    public void Pause() => _running = false;

    public void Restart()
    {
        _running = true;
        if (creditsText != null)
        {
            var pos = creditsText.rectTransform.anchoredPosition;
            pos.y = 0f;
            creditsText.rectTransform.anchoredPosition = pos;
        }
    }

    /// <summary>Reconstruye el contenido y recalcula alturas (útil al cambiar gap o el texto en Play).</summary>
    [ContextMenu("Credits/Refresh")]
    public void Refresh()
    {
        BuildAndMeasure();
    }
}
