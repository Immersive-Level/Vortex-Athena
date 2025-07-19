using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using TMPro;
using DG.Tweening;

public class ComboSystem : MonoBehaviour, IPointerDownHandler, IPointerUpHandler
{
    [Header("Sistema")]
    [SerializeField] private AbilityManager abilityManager;

    [Header("Configuración UI")]
    [SerializeField] private TextMeshProUGUI morseDisplayText;
    private RectTransform textRect;

    [Header("Configuración de entrada")]
    private float pressStartTime;
    private List<float> pressDurations = new List<float>();
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
        liveMorseCode += symbol;
        morseDisplayText.text = liveMorseCode;
        morseDisplayText.color = Color.white;

        lastReleaseTime = Time.time;
    }

    void Start()
    {
        textRect = morseDisplayText.GetComponent<RectTransform>();
        if (!abilityManager)
            abilityManager = GetComponentInParent<AbilityManager>(); // fallback automático
    }


    void Update()
    {
        if (Time.time - lastReleaseTime > entryCooldown && pressDurations.Count > 0)
        {
            ProcessMorseCode();
        }
    }

    private void ProcessMorseCode()
    {
        string finalCode = ConvertToMorse(pressDurations);

        bool success = abilityManager.TryActivate(finalCode);

        if (success)
        {
            morseDisplayText.color = Color.cyan;

            Vector3 originalScale = morseDisplayText.transform.localScale;
            Sequence bounceSequence = DOTween.Sequence();
            bounceSequence.Append(morseDisplayText.transform.DOScale(originalScale * 1.2f, 0.2f).SetEase(Ease.OutQuad));
            bounceSequence.Append(morseDisplayText.transform.DOScale(originalScale, 0.3f).SetEase(Ease.OutBounce));
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
        foreach (float duration in durations)
        {
            morseCode += (duration <= shortPressThreshold) ? "·" : "-";
        }
        return morseCode;
    }


    private void ClearText()
    {
        morseDisplayText.text = "";
        morseDisplayText.color = Color.white;
    }
}