using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;
using TMPro;
using DG.Tweening;

public class ComboSystem : MonoBehaviour, IPointerDownHandler, IPointerUpHandler
{
    [Header("Configuración UI")]
    [SerializeField] private TextMeshProUGUI morseDisplayText;

    [Header("Configuración de entrada")]
    private float pressStartTime;
    private List<float> pressDurations = new List<float>();
    private const float shortPressThreshold = 0.2f;
    private float lastReleaseTime;
    private float entryCooldown = 1.5f;

    private string liveMorseCode = "";

    [Header("Habilidades Morse")]
    private Dictionary<string, string> morseAbilities = new Dictionary<string, string>
    {
        { ".-", "Boost de velocidad" },
        { "--.", "Escudo temporal" },
        { "-..", "Disparo especial" }
    };

    public void OnPointerDown(PointerEventData eventData)
    {
        pressStartTime = Time.time;
    }

    public void OnPointerUp(PointerEventData eventData)
    {
        float pressDuration = Time.time - pressStartTime;
        pressDurations.Add(pressDuration);

        string symbol = (pressDuration <= shortPressThreshold) ? "." : "-";
        liveMorseCode += symbol;
        morseDisplayText.text = liveMorseCode;
        morseDisplayText.color = Color.white;

        lastReleaseTime = Time.time;
    }

    private void Start()
    {
        morseDisplayText.text = "";
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

        if (morseAbilities.ContainsKey(finalCode))
        {
            morseDisplayText.color = Color.green;
            //Scale Effect
            Sequence bounceSequence = DOTween.Sequence();
            Vector3 originalScale = morseDisplayText.transform.localScale;
            bounceSequence.Append(morseDisplayText.transform.DOScale(originalScale * 1.3f, 0.2f).SetEase(Ease.OutQuad));
            bounceSequence.Append(morseDisplayText.transform.DOScale(originalScale, 0.3f).SetEase(Ease.OutBounce));

            Debug.Log($"¡Poder activado: {morseAbilities[finalCode]}!");
        }
        else
        {
            morseDisplayText.color = Color.red;
            //shake effect
            morseDisplayText.transform.DOShakeRotation(0.4f);
            Debug.Log("Patrón desconocido.");
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
            morseCode += (duration <= shortPressThreshold) ? "." : "-";
        }
        return morseCode;
    }

    private void ClearText()
    {
        morseDisplayText.text = "";
        morseDisplayText.color = Color.white;
    }
}