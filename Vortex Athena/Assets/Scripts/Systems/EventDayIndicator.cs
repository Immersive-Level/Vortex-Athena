using UnityEngine;
using TMPro;

/// <summary>
/// Componente UI simple para mostrar el día del evento actual.
/// Útil para confirmar que la configuración se cargó correctamente.
/// 
/// USO:
/// 1. Crear un TextMeshPro en el Canvas (esquina superior)
/// 2. Attachar este componente al TextMeshPro
/// 3. Se actualizará automáticamente con el día del evento
/// </summary>
[RequireComponent(typeof(TextMeshProUGUI))]
public class EventDayIndicator : MonoBehaviour
{
    [Header("Configuración")]
    [Tooltip("Formato del texto a mostrar. {0} será reemplazado por el número del día")]
    public string TextFormat = "DÍA DEL EVENTO: {0}";

    [Tooltip("Color del texto")]
    public Color TextColor = Color.white;

    [Tooltip("Tamaño de la fuente")]
    public float FontSize = 24f;

    [Header("Opcional - Alertas visuales")]
    [Tooltip("Activar parpadeo si no se encuentra el sistema de persistencia")]
    public bool BlinkOnError = true;

    [Tooltip("Velocidad del parpadeo")]
    public float BlinkSpeed = 2f;

    private TextMeshProUGUI textComponent;
    private bool hasError = false;
    private float blinkTimer = 0f;

    private void Awake()
    {
        textComponent = GetComponent<TextMeshProUGUI>();

        // Configurar estilo inicial
        textComponent.color = TextColor;
        textComponent.fontSize = FontSize;
    }

    private void Start()
    {
        UpdateDisplay();
    }

    private void Update()
    {
        // Parpadear si hay error y está activado
        if (hasError && BlinkOnError)
        {
            blinkTimer += Time.deltaTime * BlinkSpeed;
            float alpha = Mathf.PingPong(blinkTimer, 1f);
            Color currentColor = textComponent.color;
            currentColor.a = alpha;
            textComponent.color = currentColor;
        }
    }

    /// <summary>
    /// Actualiza el texto con el día actual del evento
    /// </summary>
    public void UpdateDisplay()
    {
        if (MatchDataPersistence.Instance != null)
        {
            int currentDay = MatchDataPersistence.Instance.CurrentEventDay;
            textComponent.text = string.Format(TextFormat, currentDay);
            hasError = false;

            // Restaurar opacidad completa
            Color currentColor = textComponent.color;
            currentColor.a = 1f;
            textComponent.color = currentColor;

            Debug.Log($"[EventDayIndicator] Mostrando día: {currentDay}");
        }
        else
        {
            textComponent.text = "ERROR: Sistema no encontrado";
            textComponent.color = Color.red;
            hasError = true;
            Debug.LogError("[EventDayIndicator] No se encontró MatchDataPersistence");
        }
    }

    /// <summary>
    /// Actualiza el display cuando se activa el objeto
    /// </summary>
    private void OnEnable()
    {
        // Pequeño delay para asegurar que MatchDataPersistence ya se inicializó
        Invoke(nameof(UpdateDisplay), 0.1f);
    }
}