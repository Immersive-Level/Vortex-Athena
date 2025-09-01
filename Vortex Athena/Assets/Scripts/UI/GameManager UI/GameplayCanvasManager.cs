using UnityEngine;
using System.Collections.Generic;

/// <summary>
/// Controla la visibilidad de los distintos canvas según el estado actual del juego.
/// </summary>
public class GameplayCanvasManager : MonoBehaviour
{
    [Tooltip("Canvas que se muestra en el menú inicial.")]
    public GameObject MenuCanvas;

    [Tooltip("Canvas que se muestra durante la partida.")]
    public GameObject InGameCanvas;

    [Tooltip("Canvas que se muestra al finalizar la partida.")]
    public GameObject EndGameCanvas;

    private Dictionary<GameState, GameObject> canvasPorEstado;

    /// <summary>
    /// Inicializa el diccionario y valida que todos los canvases estén asignados.
    /// </summary>
    private void Awake()
    {
        canvasPorEstado = new Dictionary<GameState, GameObject>
        {
            //agregar mas estados y su respectivo canvas relacionado, si se requiere
            { GameState.InMenu, MenuCanvas },
            { GameState.InGame, InGameCanvas },
            { GameState.InGameEnd, EndGameCanvas }
        };

        foreach (var canvas in canvasPorEstado)
        {
            if (canvas.Value == null)
            {
                Debug.LogWarning($"[GameplayCanvasManager] Canvas para estado {canvas.Key} es null");
            }
        }
    }

    private void Start()
    {
        if (GameManager.Instance != null)
        {
            GameManager.Instance.OnGameStateChanged += HandleGameStateChanged;
        }
        HandleGameStateChanged(GameState.InMenu);
    }

    private void OnDisable()
    {
        if (GameManager.Instance != null)
        {
            GameManager.Instance.OnGameStateChanged -= HandleGameStateChanged;
        }
    }

    private void HandleGameStateChanged(GameState newState)
    {
        SetActiveCanvas(newState);
    }

    /// <summary>
    /// Activa el canvas correspondiente al estado actual y desactiva los demás.
    /// </summary>
    /// <param name="estadoActivo">Estado del juego que debe mostrarse.</param>
    private void SetActiveCanvas(GameState estadoActivo)
    {
        foreach (var canvas in canvasPorEstado)
        {
            if (canvas.Value != null)
                canvas.Value.SetActive(canvas.Key == estadoActivo);
        }
    }
}