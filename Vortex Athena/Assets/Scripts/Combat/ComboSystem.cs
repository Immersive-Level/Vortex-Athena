using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using TMPro;
using DG.Tweening;

public class ComboSystem : MonoBehaviour, IPointerDownHandler, IPointerUpHandler
{
    [Header("Sistema")]
    [SerializeField] private AbilityManager abilityManager;

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

    public void OnPointerDown(PointerEventData eventData)
    {
        pressStartTime = Time.time;
    }

    public void OnPointerUp(PointerEventData eventData)
    {
        float pressDuration = Time.time - pressStartTime;
        pressDurations.Add(pressDuration);

        string symbol = (pressDuration <= shortPressThreshold) ? "·" : "-";

        // Validar cabida antes de aceptar el nuevo símbolo
        if (!CanFit(liveMorseCode + symbol))
        {
            // Feedback sutil y no intrusivo
            morseDisplayText.color = Color.yellow;
            textRect.DOPunchScale(Vector3.one * 0.05f, 0.15f, 8, 0.9f);
            // No añadimos el símbolo si no cabe
            lastReleaseTime = Time.time;
            return;
        }

        liveMorseCode += symbol;
        morseDisplayText.text = liveMorseCode;
        morseDisplayText.color = Color.white;

        lastReleaseTime = Time.time;
    }

    void Start()
    {
        textRect = morseDisplayText.GetComponent<RectTransform>();
        if (!abilityManager)
            abilityManager = GetComponentInParent<AbilityManager>();

        // Asegurar configuración consistente
        morseDisplayText.enableWordWrapping = false;
        morseDisplayText.overflowMode = TextOverflowModes.Truncate;
        // Si el texto tiene Auto Size activo, también funciona porque GetPreferredValues lo respeta.
    }

    void Update()
    {
        if (Time.time - lastReleaseTime > entryCooldown && pressDurations.Count > 0)
            ProcessMorseCode();
    }

    private void ProcessMorseCode()
    {
        string finalCode = ConvertToMorse(pressDurations);
        bool success = abilityManager.TryActivate(finalCode); // Usa AbilityManager existente :contentReference[oaicite:1]{index=1}

        if (success)
        {
            morseDisplayText.color = Color.cyan;
            var original = morseDisplayText.transform.localScale;
            DOTween.Sequence()
                .Append(morseDisplayText.transform.DOScale(original * 1.2f, 0.2f).SetEase(Ease.OutQuad))
                .Append(morseDisplayText.transform.DOScale(original, 0.3f).SetEase(Ease.OutBounce));
        }
        else
        {
            morseDisplayText.color = Color.red;
            textRect.DOShakeRotation(0.4f, 30).SetEase(Ease.OutQuad);
        }

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

    // === Núcleo del límite de escritura ===
    private bool CanFit(string candidate)
    {
        // Ancho “ideal” del texto con la fuente/tamaño actuales
        Vector2 pref = morseDisplayText.GetPreferredValues(candidate);
        float allowed = Mathf.Max(0f, textRect.rect.width - (horizontalPadding * 2f));
        return pref.x <= allowed;
    }
    // ======================================

    private void ClearText()
    {
        morseDisplayText.text = "";
        morseDisplayText.color = Color.white;
    }
}
