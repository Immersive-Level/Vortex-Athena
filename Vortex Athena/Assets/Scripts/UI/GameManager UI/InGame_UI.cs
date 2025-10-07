using TMPro;
using UnityEngine;

public class InGame_UI : MonoBehaviour
{
    [SerializeField] private TMP_Text timeText;
    [SerializeField] private TMP_Text timeText2;

    private void Update()
    {
        // Validación de estado del juego
        if (GameManager.Instance.CurrentState != GameState.InGame)
        {
            return;
        }

        // Obtener tiempo actual de partida
        float gameTime = GameManager.Instance.Gametime;

        // Convertir a minutos y segundos
        int minutes = Mathf.FloorToInt(gameTime / 60f);
        int seconds = Mathf.FloorToInt(gameTime % 60f);

        // Actualizar texto en formato mm:ss
        timeText.text = $"{minutes:00}:{seconds:00}";
        timeText2.text = $"{minutes:00}:{seconds:00}";
    }


}
