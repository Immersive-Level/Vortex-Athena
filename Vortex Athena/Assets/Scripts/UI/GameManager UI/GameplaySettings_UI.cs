using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameplaySettings_UI : MonoBehaviour
{
    [Header("Referencias UI")]
    public TMP_Dropdown tiempoDropdown;
    public Toggle habilidadesToggle;
    public Button startButton;
    public Button quitButton;

    private readonly float[] tiemposDisponibles = { 60f, 90f, 120f };

    private void Start()
    {
        // Inicializar dropdown con opciones legibles
        tiempoDropdown.ClearOptions();
        var opciones = new List<string>();
        foreach (var tiempo in tiemposDisponibles)
        {
            opciones.Add($"{tiempo} segundos");
        }
        tiempoDropdown.AddOptions(opciones);

        startButton?.onClick.AddListener(OnStartClicked);
        quitButton?.onClick.AddListener(OnQuitClicked);
    }

    private void OnStartClicked()
    {
        int index = tiempoDropdown.value;
        float tiempoSeleccionado = tiemposDisponibles[index];
        bool usarHabilidades = habilidadesToggle.isOn;

        GameManager.Instance.StartGame(tiempoSeleccionado, usarHabilidades);
    }

    private void OnQuitClicked()
    {
        SceneManager.LoadScene(0);
    }
}
