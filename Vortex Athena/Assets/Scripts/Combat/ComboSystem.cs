using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

public class ComboSystem : MonoBehaviour, IPointerDownHandler, IPointerUpHandler
{
    private float pressStartTime;
    private List<float> pressDurations = new List<float>();
    private const float shortPressThreshold = 0.3f; // tiempo para pulsasiones cortas 
    private float lastReleaseTime;
    private float entryCooldown = 2f; // Tiempo para considerar el patr�n completado

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
        lastReleaseTime = Time.time;
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
        string morseCode = ConvertToMorse(pressDurations);
        print("Code: " + morseCode);
        if (morseAbilities.ContainsKey(morseCode))
        {
            Debug.Log($"�Poder activado: {morseAbilities[morseCode]}!");
            // Aqu� activas la habilidad asociada
        }
        else
        {
            Debug.Log("Patr�n desconocido.");
        }

        // Limpia las entradas para el siguiente intento
        pressDurations.Clear();
    }

    private string ConvertToMorse(List<float> durations)
    {
        string morseCode = "";
        foreach (float duration in durations)
        {
            if (duration <= shortPressThreshold)
                morseCode += ".";
            else
                morseCode += "-";
        }
        return morseCode;
    }

}