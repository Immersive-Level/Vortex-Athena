using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Mapeo simple de nombre de jugador a su prefab personalizado
/// </summary>
[System.Serializable]
public class PlayerPrefabMapping
{
    [Tooltip("Nombre del jugador (debe coincidir con PlayerScore.PlayerName)")]
    public string PlayerName;

    [Tooltip("Prefab personalizado para este jugador")]
    public GameObject CustomPrefab;
}

/// <summary>
/// Sistema principal para mostrar la tabla de puntajes al final del juego.
/// Responsabilidad: Generar y poblar la tabla con datos del ScoreSystem.
/// Uso: Attachar a un GameObject que contenga el contenedor de la tabla.
/// </summary>
public class ScoreboardDisplay : MonoBehaviour
{
    [Header("Configuración de Prefabs")]
    [Tooltip("Prefabs personalizados por jugador - Se selecciona automáticamente por nombre")]
    public List<PlayerPrefabMapping> PlayerPrefabs = new List<PlayerPrefabMapping>();

    [Tooltip("Prefab genérico de respaldo (si no se encuentra prefab personalizado)")]
    public GameObject FallbackPrefab;

    [Header("Configuración General")]
    [Tooltip("Contenedor donde se generarán las filas (Content de un ScrollRect)")]
    public Transform RowContainer;

    [Tooltip("Cantidad máxima de jugadores a mostrar")]
    public int MaxPlayersToShow = 4;

    [Header("Colores de destacado (opcional)")]
    [Tooltip("Color para el 1er lugar")]
    public Color FirstPlaceColor = new Color(1f, 0.84f, 0f); // Dorado

    [Tooltip("Color para el 2do lugar")]
    public Color SecondPlaceColor = new Color(0.75f, 0.75f, 0.75f); // Plateado

    [Tooltip("Color para el 3er lugar")]
    public Color ThirdPlaceColor = new Color(0.8f, 0.5f, 0.2f); // Bronce

    [Tooltip("Aplicar colores de destacado a los primeros 3 lugares")]
    public bool UseHighlightColors = true;

    // Caché de prefabs para búsqueda rápida
    private Dictionary<string, GameObject> prefabCache = new Dictionary<string, GameObject>();

    // Lista de filas generadas para reutilización
    private List<GameObject> spawnedRows = new List<GameObject>();

    private void Awake()
    {
        // Construir caché de prefabs para búsquedas O(1)
        BuildPrefabCache();
    }

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
    /// Construye el diccionario de caché para búsqueda rápida de prefabs
    /// </summary>
    private void BuildPrefabCache()
    {
        prefabCache.Clear();

        foreach (var mapping in PlayerPrefabs)
        {
            if (mapping.CustomPrefab != null && !string.IsNullOrEmpty(mapping.PlayerName))
            {
                // Usar el nombre exacto como key
                prefabCache[mapping.PlayerName] = mapping.CustomPrefab;
                Debug.Log($"Prefab mapeado: {mapping.PlayerName} ? {mapping.CustomPrefab.name}");
            }
        }

        Debug.Log($"Caché de prefabs construido con {prefabCache.Count} entradas");
    }

    /// <summary>
    /// Listener del evento de cambio de estado del juego
    /// </summary>
    private void OnGameStateChanged(GameState newState)
    {
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
        if (RowContainer == null)
        {
            Debug.LogError("ScoreboardDisplay: Falta RowContainer");
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
    /// Selecciona el prefab correcto para un jugador específico
    /// </summary>
    /// <param name="playerName">Nombre del jugador</param>
    /// <returns>Prefab personalizado o fallback</returns>
    private GameObject GetPrefabForPlayer(string playerName)
    {
        // Buscar en el caché
        if (prefabCache.TryGetValue(playerName, out GameObject customPrefab))
        {
            Debug.Log($"Usando prefab personalizado para {playerName}: {customPrefab.name}");
            return customPrefab;
        }

        // Si no se encontró, usar el fallback
        if (FallbackPrefab != null)
        {
            Debug.LogWarning($"No se encontró prefab personalizado para '{playerName}'. Usando Fallback.");
            return FallbackPrefab;
        }

        // Error si no hay ni personalizado ni fallback
        Debug.LogError($"No hay prefab para '{playerName}' y tampoco hay FallbackPrefab asignado");
        return null;
    }

    /// <summary>
    /// Crea una fila individual en la tabla
    /// </summary>
    private void CreateRow(int position, PlayerScore playerScore)
    {
        // Seleccionar el prefab correcto basándose en el nombre del jugador
        GameObject prefabToUse = GetPrefabForPlayer(playerScore.PlayerName);

        if (prefabToUse == null)
        {
            Debug.LogError($"No se puede crear fila para {playerScore.PlayerName}: no hay prefab disponible");
            return;
        }

        // Instanciar el prefab seleccionado
        GameObject rowObject = Instantiate(prefabToUse, RowContainer);
        spawnedRows.Add(rowObject);

        // Obtener el componente ScoreboardRow
        ScoreboardRow row = rowObject.GetComponent<ScoreboardRow>();

        if (row == null)
        {
            Debug.LogError($"El prefab {prefabToUse.name} no tiene componente ScoreboardRow");
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