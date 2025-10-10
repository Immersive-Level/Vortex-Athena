using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using TMPro;
using DG.Tweening;
using GameSystems;

/// <summary>
/// Sistema de combos basado en código Morse
/// Integrado con ShipInputController para respetar estados del juego
/// </summary>
public class ComboSystem : MonoBehaviour, IPointerDownHandler, IPointerUpHandler
{
    [Header("Sistema")]
    [SerializeField] private AbilityManager abilityManager;

    [Header("Control de Estado")]
    [Tooltip("Referencia al controlador de input de la nave para validar estados")]
    [SerializeField] private ShipInputController shipInputController;

    [Tooltip("Si true, muestra feedback visual cuando el input está deshabilitado")]
    [SerializeField] private bool showDisabledFeedback = true;

    [Header("UI")]
    [SerializeField] private TextMeshProUGUI morseDisplayText;
    private RectTransform textRect;

    [Tooltip("Padding horizontal interno usado para el cálculo de cabida")]
    [SerializeField] private float horizontalPadding = 6f;

    [Header("Entrada")]
    private float pressStartTime;
    private readonly List<float> pressDurations = new();
    private const float shortPressThreshold = 0.15f;
    private float lastReleaseTime;
    private float entryCooldown = 1f;

    private string liveMorseCode = "";

    [Header("Debug")]
    [SerializeField] private bool debugMode = false;

    // ============================================================
    // LIFECYCLE
    // ============================================================

    void Awake()
    {
        textRect = morseDisplayText.GetComponent<RectTransform>();

        // Auto-localizar ShipInputController si no está asignado
        if (shipInputController == null)
            shipInputController = GetComponentInParent<ShipInputController>();

        if (!abilityManager)
            abilityManager = GetComponentInParent<AbilityManager>();
    }

    void Start()
    {
        // Asegurar configuración consistente del texto
        morseDisplayText.textWrappingMode = TextWrappingModes.NoWrap;
        morseDisplayText.overflowMode = TextOverflowModes.Truncate;

        // Suscribirse a cambios de estado para limpiar input cuando sea necesario
        if (shipInputController != null)
        {
            shipInputController.OnStateChanged += HandleShipStateChanged;
        }
        else
        {
            Debug.LogWarning("[ComboSystem] No se encontró ShipInputController. El sistema funcionará sin validación de estados.");
        }
    }

    void Update()
    {
        // Procesar código morse solo si hay duraciones acumuladas y pasó el cooldown
        if (Time.time - lastReleaseTime > entryCooldown && pressDurations.Count > 0)
            ProcessMorseCode();
    }

    void OnDestroy()
    {
        // Limpiar suscripciones
        if (shipInputController != null)
            shipInputController.OnStateChanged -= HandleShipStateChanged;
    }

    // ============================================================
    // INPUT HANDLERS
    // ============================================================

    public void OnPointerDown(PointerEventData eventData)
    {
        // VALIDACIÓN DE ESTADO: Solo procesar input en estado Playing
        if (!CanProcessInput())
        {
            if (showDisabledFeedback)
                ShowDisabledFeedback();

            if (debugMode)
            {
                string reason = GetDisabledReason();
                Debug.Log($"[ComboSystem] Input bloqueado: {reason}");
            }
            return;
        }

        pressStartTime = Time.time;
    }

    public void OnPointerUp(PointerEventData eventData)
    {
        // VALIDACIÓN DE ESTADO: Solo procesar input en estado Playing
        if (!CanProcessInput())
        {
            // Si se inició un press válido pero el estado cambió, limpiar
            if (pressStartTime > 0)
                pressStartTime = 0;
            return;
        }

        float pressDuration = Time.time - pressStartTime;
        pressDurations.Add(pressDuration);

        string symbol = (pressDuration <= shortPressThreshold) ? "·" : "-";

        // Validar cabida antes de aceptar el nuevo símbolo
        if (!CanFit(liveMorseCode + symbol))
        {
            ShowCapacityFeedback();
            lastReleaseTime = Time.time;
            return;
        }

        // Añadir símbolo válido
        liveMorseCode += symbol;
        morseDisplayText.text = liveMorseCode;
        morseDisplayText.color = Color.white;

        lastReleaseTime = Time.time;

        if (debugMode)
            Debug.Log($"[ComboSystem] Símbolo añadido: {symbol} | Código actual: {liveMorseCode}");
    }

    // ============================================================
    // VALIDACIÓN DE ESTADO
    // ============================================================

    /// <summary>
    /// Determina si el sistema puede procesar input en el estado actual
    /// </summary>
    private bool CanProcessInput()
    {
        // Si no hay referencia al controlador, permitir input (modo legacy)
        if (shipInputController == null)
            return true;

        // Solo permitir input en estado Playing
        return shipInputController.IsPlayingState;
    }

    /// <summary>
    /// Obtiene la razón por la cual el input está deshabilitado (para debug)
    /// </summary>
    private string GetDisabledReason()
    {
        if (shipInputController == null)
            return "No ShipInputController";

        switch (shipInputController.CurrentState)
        {
            case ShipInputController.ButtonState.Inactive:
                return "Juego no iniciado";
            case ShipInputController.ButtonState.Dead:
                return "Jugador muerto";
            case ShipInputController.ButtonState.RespawnReady:
                return "Esperando respawn";
            default:
                return "Estado desconocido";
        }
    }

    /// <summary>
    /// Maneja cambios de estado del ShipInputController
    /// </summary>
    private void HandleShipStateChanged(ShipInputController.ButtonState newState)
    {
        // Si salimos del estado Playing, limpiar input pendiente
        if (newState != ShipInputController.ButtonState.Playing)
        {
            ClearInput();

            if (debugMode)
                Debug.Log($"[ComboSystem] Estado cambiado a {newState} - Input limpiado");
        }
    }

    // ============================================================
    // PROCESAMIENTO DE MORSE
    // ============================================================

    private void ProcessMorseCode()
    {
        // Verificar estado antes de procesar
        if (!CanProcessInput())
        {
            ClearInput();
            return;
        }

        string finalCode = ConvertToMorse(pressDurations);
        bool success = abilityManager.TryActivate(finalCode);

        if (success)
        {
            ShowSuccessFeedback();
        }
        else
        {
            ShowFailureFeedback();
        }

        // Limpiar después de procesar
        liveMorseCode = "";
        pressDurations.Clear();
        Invoke(nameof(ClearText), 1.5f);
    }

    private string ConvertToMorse(List<float> durations)
    {
        string morseCode = "";
        foreach (float d in durations)
            morseCode += (d <= shortPressThreshold) ? "·" : "-";
        return morseCode;
    }

    // ============================================================
    // VALIDACIÓN DE CAPACIDAD
    // ============================================================

    /// <summary>
    /// Verifica si el texto candidato cabe en el área disponible
    /// </summary>
    private bool CanFit(string candidate)
    {
        // Ancho "ideal" del texto con la fuente/tamaño actuales
        Vector2 pref = morseDisplayText.GetPreferredValues(candidate);
        float allowed = Mathf.Max(0f, textRect.rect.width - (horizontalPadding * 2f));
        return pref.x <= allowed;
    }

    // ============================================================
    // FEEDBACK VISUAL
    // ============================================================

    /// <summary>
    /// Feedback cuando el input está deshabilitado por estado del juego
    /// </summary>
    private void ShowDisabledFeedback()
    {
        morseDisplayText.color = new Color(1f, 1f, 1f, 0.3f);
        textRect.DOShakePosition(0.2f, 2f, 20, 90, false, true);
    }

    /// <summary>
    /// Feedback cuando se alcanza el límite de capacidad
    /// </summary>
    private void ShowCapacityFeedback()
    {
        morseDisplayText.color = Color.yellow;
        textRect.DOPunchScale(Vector3.one * 0.05f, 0.15f, 8, 0.9f);
    }

    /// <summary>
    /// Feedback cuando el combo es exitoso
    /// </summary>
    private void ShowSuccessFeedback()
    {
        morseDisplayText.color = Color.cyan;
        var original = morseDisplayText.transform.localScale;
        DOTween.Sequence()
            .Append(morseDisplayText.transform.DOScale(original * 1.2f, 0.2f).SetEase(Ease.OutQuad))
            .Append(morseDisplayText.transform.DOScale(original, 0.3f).SetEase(Ease.OutBounce));
    }

    /// <summary>
    /// Feedback cuando el combo falla
    /// </summary>
    private void ShowFailureFeedback()
    {
        morseDisplayText.color = Color.red;
        textRect.DOShakeRotation(0.4f, 30).SetEase(Ease.OutQuad);
    }

    // ============================================================
    // UTILIDADES
    // ============================================================

    /// <summary>
    /// Limpia el texto visible
    /// </summary>
    private void ClearText()
    {
        morseDisplayText.text = "";
        morseDisplayText.color = Color.white;
    }

    /// <summary>
    /// Limpia todo el input pendiente (texto y duraciones)
    /// </summary>
    private void ClearInput()
    {
        liveMorseCode = "";
        pressDurations.Clear();
        pressStartTime = 0;
        ClearText();
    }

#if UNITY_EDITOR
    void OnValidate()
    {
        horizontalPadding = Mathf.Max(0f, horizontalPadding);
        entryCooldown = Mathf.Max(0.1f, entryCooldown);
    }
#endif
}