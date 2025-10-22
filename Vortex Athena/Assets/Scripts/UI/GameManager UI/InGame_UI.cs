using TMPro;
using UnityEngine;

public class InGame_UI : MonoBehaviour
{
    [SerializeField] private TMP_Text timeText;
    [SerializeField] private TMP_Text timeText2;

    private void Update()
    {
        float remaining;

        // Si estamos en juego, usamos el tiempo restante; si no, mostramos 00:00
        if (GameManager.Instance.CurrentState == GameState.InGame)
        {
            remaining = GameManager.Instance.GetRemainingTime(); // ya viene con Mathf.Max(0, ...)
        }
        else
        {
            remaining = 0f;
        }

        // Convertir a mm:ss (regresivo)
        int minutes = Mathf.FloorToInt(remaining / 60f);
        int seconds = Mathf.FloorToInt(remaining % 60f);

        string formatted = $"{minutes:00}:{seconds:00}";
        if (timeText != null) timeText.text = formatted;
        if (timeText2 != null) timeText2.text = formatted;
    }
}

