using TMPro;
using UnityEngine;

public class InGame_UI : MonoBehaviour
{
    [SerializeField] private TMP_Text timeText;

    private void Update()
    {
        // Validar que GameManager esté disponible y haya sido spawneado en red
        if (GameManager.Instance == null || !GameManager.Instance.Object || !GameManager.Instance.Object.IsValid) return;

        // Validar que el estado sea InGame
        if (GameManager.Instance.CurrentState != GameState.InGame) return;

        // Obtener tiempo actual de partida
        float gameTime = GameManager.Instance.Gametime;

        // Convertir a minutos y segundos
        int minutes = Mathf.FloorToInt(gameTime / 60f);
        int seconds = Mathf.FloorToInt(gameTime % 60f);

        // Actualizar texto en formato mm:ss
        timeText.text = $"{minutes:00}:{seconds:00}";
    }


}
