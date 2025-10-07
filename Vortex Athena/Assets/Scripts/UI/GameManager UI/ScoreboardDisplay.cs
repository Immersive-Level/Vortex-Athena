using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Sistema principal para mostrar la tabla de puntajes al final del juego.
/// Responsabilidad: Generar y poblar la tabla con datos del ScoreSystem.
/// Uso: Attachar a un GameObject que contenga el contenedor de la tabla.
/// </summary>
public class ScoreboardDisplay : MonoBehaviour
{
    [Header("Configuración")]
    [Tooltip("Prefab de la fila (debe tener componente ScoreboardRow)")]
    public GameObject RowPrefab;

    [Tooltip("Contenedor donde se generarán las filas (Content de un ScrollRect)")]
    public Transform RowContainer;

    [Tooltip("Cantidad máxima de jugadores a mostrar")]
    public int MaxPlayersToShow = 10;

    [Header("Colores de destacado (opcional)")]
    [Tooltip("Color para el 1er lugar")]
    public Color FirstPlaceColor = new Color(1f, 0.84f, 0f); // Dorado

    [Tooltip("Color para el 2do lugar")]
    public Color SecondPlaceColor = new Color(0.75f, 0.75f, 0.75f); // Plateado

    [Tooltip("Color para el 3er lugar")]
    public Color ThirdPlaceColor = new Color(0.8f, 0.5f, 0.2f); // Bronce

    [Tooltip("Aplicar colores de destacado a los primeros 3 lugares")]
    public bool UseHighlightColors = true;

    // Lista de filas generadas para reutilización
    private List<GameObject> spawnedRows = new List<GameObject>();

    private void OnEnable()
    {
        // Suscribirse al evento de cambio de estado
        if (GameManager.Instance != null)
        {
            GameManager.Instance.OnGameStateChanged += OnGameStateChanged;

            // Si ya estamos en InGameEnd cuando nos activamos, generar la tabla inmediatamente
            if (GameManager.Instance.CurrentState == GameState.InGameEnd)
            {
                PopulateScoreboard();
            }
        }
    }

    private void OnDisable()
    {
        // Desuscribirse para evitar memory leaks
        if (GameManager.Instance != null)
        {
            GameManager.Instance.OnGameStateChanged -= OnGameStateChanged;
        }
    }

    /// <summary>
    /// Listener del evento de cambio de estado del juego
    /// </summary>
    private void OnGameStateChanged()
    {
        var newState = GameManager.Instance?.CurrentState;

        // Solo mostrar la tabla cuando el juego termina
        if (newState == GameState.InGameEnd)
        {
            PopulateScoreboard();
        }
    }

    /// <summary>
    /// Genera y puebla la tabla con los datos actuales del ScoreSystem
    /// </summary>
    public void PopulateScoreboard()
    {
        Debug.Log("=== POPULATE SCOREBOARD INICIADO ===");

        // Validar referencias
        if (RowPrefab == null || RowContainer == null)
        {
            Debug.LogError("ScoreboardDisplay: Faltan referencias (RowPrefab o RowContainer)");
            return;
        }

        if (GameManager.Instance == null || GameManager.Instance.ScoreSystem == null)
        {
            Debug.LogError("ScoreboardDisplay: No se encontró GameManager o ScoreSystem");
            return;
        }

        Debug.Log($"ScoreSystem contiene {GameManager.Instance.ScoreSystem.ScoreMap.Count} jugadores");

        // Limpiar filas anteriores
        ClearScoreboard();

        // Obtener jugadores ordenados
        List<PlayerScore> sortedPlayers = GetSortedPlayers();

        Debug.Log($"Jugadores ordenados: {sortedPlayers.Count}");

        // Limitar cantidad de jugadores a mostrar
        int playersToShow = Mathf.Min(sortedPlayers.Count, MaxPlayersToShow);

        // Generar una fila por cada jugador
        for (int i = 0; i < playersToShow; i++)
        {
            Debug.Log($"Generando fila {i + 1} para: {sortedPlayers[i].PlayerName} - Score: {sortedPlayers[i].Score}");
            CreateRow(i + 1, sortedPlayers[i]);
        }

        Debug.Log($"=== Scoreboard generado con {playersToShow} jugadores ===");
    }

    /// <summary>
    /// Obtiene la lista de jugadores ordenada por puntaje
    /// </summary>
    private List<PlayerScore> GetSortedPlayers()
    {
        ScoreSystem scoreSystem = GameManager.Instance.ScoreSystem;
        List<PlayerScore> players = new List<PlayerScore>(scoreSystem.ScoreMap.Values);

        // Ordenar de mayor a menor puntaje
        players.Sort((a, b) => b.Score.CompareTo(a.Score));

        return players;
    }

    /// <summary>
    /// Crea una fila individual en la tabla
    /// </summary>
    private void CreateRow(int position, PlayerScore playerScore)
    {
        // Instanciar el prefab
        GameObject rowObject = Instantiate(RowPrefab, RowContainer);
        spawnedRows.Add(rowObject);

        // Obtener el componente ScoreboardRow
        ScoreboardRow row = rowObject.GetComponent<ScoreboardRow>();

        if (row == null)
        {
            Debug.LogError("ScoreboardDisplay: El prefab no tiene componente ScoreboardRow");
            return;
        }

        // Configurar los datos
        row.Setup(position, playerScore);

        // Aplicar colores de destacado si está habilitado
        if (UseHighlightColors)
        {
            ApplyHighlightColor(row, position);
        }
    }

    /// <summary>
    /// Aplica color especial a las primeras 3 posiciones
    /// </summary>
    private void ApplyHighlightColor(ScoreboardRow row, int position)
    {
        switch (position)
        {
            case 1:
                row.SetHighlightColor(FirstPlaceColor);
                break;
            case 2:
                row.SetHighlightColor(SecondPlaceColor);
                break;
            case 3:
                row.SetHighlightColor(ThirdPlaceColor);
                break;
        }
    }

    /// <summary>
    /// Limpia todas las filas generadas anteriormente
    /// </summary>
    private void ClearScoreboard()
    {
        foreach (GameObject row in spawnedRows)
        {
            if (row != null)
                Destroy(row);
        }
        spawnedRows.Clear();
    }

    /// <summary>
    /// Método público para refrescar manualmente la tabla (útil para debug)
    /// </summary>
    public void RefreshScoreboard()
    {
        PopulateScoreboard();
    }
}