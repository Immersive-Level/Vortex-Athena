using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using UnityEngine;

/// <summary>
/// Datos de un jugador en una partida específica
/// </summary>
[System.Serializable]
public class PlayerMatchData
{
    public string PlayerName;
    public int Score;
    public int Position; // 1 = primero, 2 = segundo, etc.
}

/// <summary>
/// Datos completos de una partida
/// </summary>
[System.Serializable]
public class MatchData
{
    public string MatchID;              // ID único de la partida
    public string DateTime;             // Fecha y hora exacta
    public int EventDay;                // Día del evento (1-5)
    public List<PlayerMatchData> Players = new List<PlayerMatchData>();
    public string WinnerName;           // Ganador de esta partida
    public int WinnerScore;             // Puntaje del ganador
}

/// <summary>
/// Contenedor de todas las partidas del evento
/// </summary>
[System.Serializable]
public class EventDatabase
{
    public string EventName = "SOFA Event";
    public List<MatchData> Matches = new List<MatchData>();
}

/// <summary>
/// Sistema de persistencia para almacenar datos de partidas.
/// Genera archivos JSON (estructurado) y CSV (para Excel) en carpeta accesible.
/// 
/// USO EN BUILD:
/// 1. Los archivos se guardarán en: [Carpeta del .exe]/EventData/
/// 2. Cambiar "CurrentEventDay" cada día del evento (mediante inspector antes de buildear o config file)
/// 3. Al finalizar cada partida, se guardará automáticamente
/// 4. Encontrarás los archivos junto al ejecutable del juego
/// </summary>
public class MatchDataPersistence : MonoBehaviour
{
    [Header("Configuración del Evento")]
    [Tooltip("Día actual del evento (1-5) - Se carga automáticamente del config.txt")]
    [Range(1, 5)]
    public int CurrentEventDay = 1;

    [Tooltip("Nombre del evento (para los archivos)")]
    public string EventName = "SOFA_Event";

    [Tooltip("Usar archivo de configuración externo (recomendado para builds)")]
    public bool UseExternalConfig = true;

    [Header("Ubicación de Archivos")]
    [Tooltip("Guardar junto al ejecutable (recomendado para builds)")]
    public bool SaveNextToExecutable = true;

    [Tooltip("Nombre de la carpeta donde se guardarán los datos")]
    public string DataFolderName = "EventData";

    [Header("Configuración de Guardado")]
    [Tooltip("Guardar automáticamente al finalizar cada partida")]
    public bool AutoSaveOnMatchEnd = true;

    [Tooltip("También generar CSV cada vez que se guarda")]
    public bool GenerateCSVOnSave = true;

    [Tooltip("Crear archivo de ayuda con la ubicación de los datos")]
    public bool CreateHelpFile = true;

    // Base de datos en memoria
    private EventDatabase eventDatabase;

    // Rutas de archivos
    private string saveFolderPath;
    private string jsonFilePath;
    private string csvFilePath;
    private string helpFilePath;
    private string configFilePath;

    // Singleton pattern (opcional pero útil)
    public static MatchDataPersistence Instance { get; private set; }

    private void Awake()
    {
        // Configurar singleton
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
            Initialize();
        }
        else
        {
            Destroy(gameObject);
        }
    }

    /// <summary>
    /// Inicializa el sistema y carga datos existentes
    /// </summary>
    private void Initialize()
    {
        // Determinar carpeta de guardado
        if (SaveNextToExecutable)
        {
            // Guardar junto al .exe (fácil de encontrar en builds)
            string exeFolder = Path.GetDirectoryName(Application.dataPath);
            saveFolderPath = Path.Combine(exeFolder, DataFolderName);

            // Config file en la carpeta raíz (junto al .exe)
            configFilePath = Path.Combine(exeFolder, "EventConfig.txt");
        }
        else
        {
            // Usar persistentDataPath (carpeta de usuario)
            saveFolderPath = Path.Combine(Application.persistentDataPath, DataFolderName);
            configFilePath = Path.Combine(Application.persistentDataPath, "EventConfig.txt");
        }

        // Cargar configuración externa si está habilitado
        if (UseExternalConfig)
        {
            LoadConfig();
        }

        // Crear carpeta si no existe
        if (!Directory.Exists(saveFolderPath))
        {
            Directory.CreateDirectory(saveFolderPath);
            Debug.Log($"[MatchPersistence] Carpeta creada: {saveFolderPath}");
        }

        // Definir rutas de archivos
        jsonFilePath = Path.Combine(saveFolderPath, $"{EventName}_Data.json");
        csvFilePath = Path.Combine(saveFolderPath, $"{EventName}_Data.csv");
        helpFilePath = Path.Combine(saveFolderPath, "LEER_AQUI.txt");

        Debug.Log($"[MatchPersistence] Ruta de guardado: {saveFolderPath}");
        Debug.Log($"[MatchPersistence] Día del evento: {CurrentEventDay}");

        // Crear archivo de ayuda
        if (CreateHelpFile)
        {
            CreateHelpTextFile();
        }

        // Cargar datos existentes o crear nueva base de datos
        LoadOrCreateDatabase();
    }

    private void OnEnable()
    {
        // Suscribirse al evento de fin de partida
        if (GameManager.Instance != null)
        {
            GameManager.Instance.OnGameStateChanged += OnGameStateChanged;
        }
    }

    private void OnDisable()
    {
        if (GameManager.Instance != null)
        {
            GameManager.Instance.OnGameStateChanged -= OnGameStateChanged;
        }
    }

    /// <summary>
    /// Crea un archivo de texto con instrucciones para encontrar los datos
    /// </summary>
    private void CreateHelpTextFile()
    {
        try
        {
            using (StreamWriter writer = new StreamWriter(helpFilePath))
            {
                writer.WriteLine("==============================================");
                writer.WriteLine("  DATOS DEL EVENTO - INSTRUCCIONES");
                writer.WriteLine("==============================================");
                writer.WriteLine();
                writer.WriteLine("Los datos de las partidas se guardan en esta carpeta:");
                writer.WriteLine($"  {saveFolderPath}");
                writer.WriteLine();
                writer.WriteLine("CONFIGURACIÓN DEL DÍA DEL EVENTO:");
                if (UseExternalConfig)
                {
                    writer.WriteLine($"  • Abre el archivo: EventConfig.txt (está junto al .exe)");
                    writer.WriteLine("  • Cambia DAY=1 por DAY=2, DAY=3, etc.");
                    writer.WriteLine("  • Guarda y reinicia el juego");
                }
                else
                {
                    writer.WriteLine("  • La configuración está fija en el juego");
                }
                writer.WriteLine();
                writer.WriteLine("ARCHIVOS GENERADOS:");
                writer.WriteLine($"  • {EventName}_Data.json - Base de datos completa (formato estructurado)");
                writer.WriteLine($"  • {EventName}_Data.csv  - Tabla para Excel/Google Sheets");
                writer.WriteLine();
                writer.WriteLine("CÓMO ANALIZAR LOS DATOS:");
                writer.WriteLine("  1. Abre el archivo CSV con Excel o Google Sheets");
                writer.WriteLine("  2. Usa filtros para ver datos por día");
                writer.WriteLine("  3. Ordena por 'Puntaje' para ver los mejores");
                writer.WriteLine("  4. Filtra 'Es Ganador' = TRUE para ver solo ganadores");
                writer.WriteLine();
                writer.WriteLine("COLUMNAS DEL CSV:");
                writer.WriteLine("  - Match ID: Identificador único de la partida");
                writer.WriteLine("  - Fecha: Día en que se jugó");
                writer.WriteLine("  - Hora: Hora exacta");
                writer.WriteLine("  - Día Evento: Número del día del evento (1-5)");
                writer.WriteLine("  - Posición: Lugar que ocupó el jugador (1=primero)");
                writer.WriteLine("  - Jugador: Nombre del jugador");
                writer.WriteLine("  - Puntaje: Puntos obtenidos");
                writer.WriteLine("  - Es Ganador: TRUE si ganó esa partida");
                writer.WriteLine();
                writer.WriteLine("==============================================");
                writer.WriteLine($"Evento: {EventName}");
                writer.WriteLine($"Día actual: {CurrentEventDay}");
                writer.WriteLine($"Generado: {System.DateTime.Now:yyyy-MM-dd HH:mm:ss}");
                writer.WriteLine("==============================================");
            }
        }
        catch (Exception e)
        {
            Debug.LogError($"[MatchPersistence] Error al crear archivo de ayuda: {e.Message}");
        }
    }

    /// <summary>
    /// Carga la configuración desde archivo externo
    /// </summary>
    private void LoadConfig()
    {
        // Si no existe el archivo, crearlo con valores por defecto
        if (!File.Exists(configFilePath))
        {
            CreateDefaultConfigFile();
            Debug.Log($"[MatchPersistence] Archivo de configuración creado: {configFilePath}");
            return;
        }

        try
        {
            // Leer el archivo línea por línea
            string[] lines = File.ReadAllLines(configFilePath);

            foreach (string line in lines)
            {
                // Ignorar líneas vacías y comentarios
                if (string.IsNullOrWhiteSpace(line) || line.TrimStart().StartsWith("#"))
                    continue;

                // Buscar configuración del día
                if (line.StartsWith("DAY="))
                {
                    string dayValue = line.Replace("DAY=", "").Trim();

                    if (int.TryParse(dayValue, out int day))
                    {
                        // Validar que esté en rango 1-5
                        if (day >= 1 && day <= 5)
                        {
                            CurrentEventDay = day;
                            Debug.Log($"[MatchPersistence] Día cargado desde config: {CurrentEventDay}");
                        }
                        else
                        {
                            Debug.LogWarning($"[MatchPersistence] Día inválido en config: {day}. Usando valor por defecto.");
                        }
                    }
                }

                // Buscar configuración del nombre del evento
                if (line.StartsWith("EVENT_NAME="))
                {
                    string nameValue = line.Replace("EVENT_NAME=", "").Trim();
                    if (!string.IsNullOrEmpty(nameValue))
                    {
                        EventName = nameValue;
                        Debug.Log($"[MatchPersistence] Nombre del evento cargado: {EventName}");
                    }
                }
            }
        }
        catch (Exception e)
        {
            Debug.LogError($"[MatchPersistence] Error al leer configuración: {e.Message}");
        }
    }

    /// <summary>
    /// Crea el archivo de configuración con valores por defecto
    /// </summary>
    private void CreateDefaultConfigFile()
    {
        try
        {
            using (StreamWriter writer = new StreamWriter(configFilePath))
            {
                writer.WriteLine("# ===============================================");
                writer.WriteLine("# CONFIGURACIÓN DEL EVENTO SOFA");
                writer.WriteLine("# ===============================================");
                writer.WriteLine("#");
                writer.WriteLine("# INSTRUCCIONES:");
                writer.WriteLine("# 1. Edita este archivo con el Bloc de notas");
                writer.WriteLine("# 2. Cambia el número del DAY cada día del evento");
                writer.WriteLine("# 3. Guarda el archivo");
                writer.WriteLine("# 4. Reinicia el juego");
                writer.WriteLine("#");
                writer.WriteLine("# IMPORTANTE: Las líneas que empiezan con # son comentarios");
                writer.WriteLine("#");
                writer.WriteLine("# ===============================================");
                writer.WriteLine();
                writer.WriteLine("# Día actual del evento (valores válidos: 1, 2, 3, 4, 5)");
                writer.WriteLine($"DAY={CurrentEventDay}");
                writer.WriteLine();
                writer.WriteLine("# Nombre del evento (opcional)");
                writer.WriteLine($"EVENT_NAME={EventName}");
                writer.WriteLine();
                writer.WriteLine("# ===============================================");
                writer.WriteLine("# EJEMPLOS DE USO:");
                writer.WriteLine("# ===============================================");
                writer.WriteLine("#");
                writer.WriteLine("# Para el día 1:");
                writer.WriteLine("# DAY=1");
                writer.WriteLine("#");
                writer.WriteLine("# Para el día 2:");
                writer.WriteLine("# DAY=2");
                writer.WriteLine("#");
                writer.WriteLine("# Y así sucesivamente hasta el día 5");
                writer.WriteLine("#");
                writer.WriteLine("# ===============================================");
                writer.WriteLine($"# Archivo generado: {System.DateTime.Now:yyyy-MM-dd HH:mm:ss}");
                writer.WriteLine("# ===============================================");
            }

            Debug.Log($"[MatchPersistence] Archivo de configuración creado en: {configFilePath}");
        }
        catch (Exception e)
        {
            Debug.LogError($"[MatchPersistence] Error al crear archivo de configuración: {e.Message}");
        }
    }

    /// <summary>
    /// Listener para detectar cuando termina una partida
    /// </summary>
    private void OnGameStateChanged(GameState newState)
    {
        if (newState == GameState.InGameEnd && AutoSaveOnMatchEnd)
        {
            // Pequeño delay para asegurar que el scoreboard ya se generó
            Invoke(nameof(SaveCurrentMatch), 0.5f);
        }
    }

    /// <summary>
    /// Carga la base de datos existente o crea una nueva
    /// </summary>
    private void LoadOrCreateDatabase()
    {
        if (File.Exists(jsonFilePath))
        {
            try
            {
                string json = File.ReadAllText(jsonFilePath);
                eventDatabase = JsonUtility.FromJson<EventDatabase>(json);
                Debug.Log($"[MatchPersistence] Base de datos cargada: {eventDatabase.Matches.Count} partidas");
            }
            catch (Exception e)
            {
                Debug.LogError($"[MatchPersistence] Error al cargar datos: {e.Message}");
                eventDatabase = new EventDatabase { EventName = EventName };
            }
        }
        else
        {
            eventDatabase = new EventDatabase { EventName = EventName };
            Debug.Log("[MatchPersistence] Nueva base de datos creada");
        }
    }

    /// <summary>
    /// Guarda los datos de la partida actual
    /// </summary>
    public void SaveCurrentMatch()
    {
        if (GameManager.Instance == null || GameManager.Instance.ScoreSystem == null)
        {
            Debug.LogError("[MatchPersistence] No se encontró ScoreSystem");
            return;
        }

        // Crear datos de la partida
        MatchData matchData = new MatchData
        {
            MatchID = GenerateMatchID(),
            DateTime = System.DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss"),
            EventDay = CurrentEventDay,
            Players = new List<PlayerMatchData>()
        };

        // Obtener jugadores ordenados
        List<PlayerScore> sortedPlayers = GetSortedPlayers();

        // Llenar datos de jugadores
        for (int i = 0; i < sortedPlayers.Count; i++)
        {
            PlayerScore player = sortedPlayers[i];

            matchData.Players.Add(new PlayerMatchData
            {
                PlayerName = player.PlayerName,
                Score = player.Score,
                Position = i + 1
            });

            // Guardar datos del ganador
            if (i == 0)
            {
                matchData.WinnerName = player.PlayerName;
                matchData.WinnerScore = player.Score;
            }
        }

        // Agregar partida a la base de datos
        eventDatabase.Matches.Add(matchData);

        // Guardar en archivos
        SaveToJSON();

        if (GenerateCSVOnSave)
        {
            SaveToCSV();
        }

        // Actualizar archivo de ayuda con estadísticas
        if (CreateHelpFile)
        {
            UpdateHelpFileWithStats();
        }

        Debug.Log($"[MatchPersistence] Partida guardada: {matchData.MatchID} - Ganador: {matchData.WinnerName} ({matchData.WinnerScore} pts)");
    }

    /// <summary>
    /// Guarda la base de datos en formato JSON
    /// </summary>
    private void SaveToJSON()
    {
        try
        {
            string json = JsonUtility.ToJson(eventDatabase, true);
            File.WriteAllText(jsonFilePath, json);
            Debug.Log($"[MatchPersistence] JSON guardado: {jsonFilePath}");
        }
        catch (Exception e)
        {
            Debug.LogError($"[MatchPersistence] Error al guardar JSON: {e.Message}");
        }
    }

    /// <summary>
    /// Genera archivo CSV para análisis en Excel
    /// </summary>
    private void SaveToCSV()
    {
        try
        {
            using (StreamWriter writer = new StreamWriter(csvFilePath))
            {
                // Encabezados
                writer.WriteLine("Match ID,Fecha,Hora,Día Evento,Posición,Jugador,Puntaje,Es Ganador");

                // Datos de cada partida
                foreach (MatchData match in eventDatabase.Matches)
                {
                    string[] dateTimeParts = match.DateTime.Split(' ');
                    string date = dateTimeParts.Length > 0 ? dateTimeParts[0] : "";
                    string time = dateTimeParts.Length > 1 ? dateTimeParts[1] : "";

                    foreach (PlayerMatchData player in match.Players)
                    {
                        bool isWinner = player.PlayerName == match.WinnerName;

                        writer.WriteLine($"{match.MatchID},{date},{time},{match.EventDay},{player.Position},{player.PlayerName},{player.Score},{isWinner}");
                    }
                }
            }

            Debug.Log($"[MatchPersistence] CSV generado: {csvFilePath}");
        }
        catch (Exception e)
        {
            Debug.LogError($"[MatchPersistence] Error al generar CSV: {e.Message}");
        }
    }

    /// <summary>
    /// Actualiza el archivo de ayuda con estadísticas actuales
    /// </summary>
    private void UpdateHelpFileWithStats()
    {
        try
        {
            // Leer el archivo actual
            string content = File.ReadAllText(helpFilePath);

            // Agregar estadísticas al final
            using (StreamWriter writer = new StreamWriter(helpFilePath, false))
            {
                writer.Write(content);
                writer.WriteLine();
                writer.WriteLine("==============================================");
                writer.WriteLine("  ESTADÍSTICAS ACTUALES");
                writer.WriteLine("==============================================");
                writer.WriteLine($"Última actualización: {System.DateTime.Now:yyyy-MM-dd HH:mm:ss}");
                writer.WriteLine($"Total de partidas jugadas: {eventDatabase.Matches.Count}");
                writer.WriteLine();

                // Mejor puntaje general
                var overall = GetBestScoreOverall();
                if (overall.score > 0)
                {
                    writer.WriteLine($"MEJOR PUNTAJE GENERAL:");
                    writer.WriteLine($"  {overall.playerName} - {overall.score} pts (Día {overall.day})");
                    writer.WriteLine();
                }

                // Mejor por día
                writer.WriteLine("MEJORES PUNTAJES POR DÍA:");
                for (int day = 1; day <= 5; day++)
                {
                    var dayBest = GetBestScoreOfDay(day);
                    int dayMatches = eventDatabase.Matches.Count(m => m.EventDay == day);

                    if (dayMatches > 0)
                    {
                        writer.WriteLine($"  Día {day}: {dayBest.playerName} - {dayBest.score} pts ({dayMatches} partidas)");
                    }
                }
                writer.WriteLine("==============================================");
            }
        }
        catch (Exception e)
        {
            Debug.LogError($"[MatchPersistence] Error al actualizar stats: {e.Message}");
        }
    }

    /// <summary>
    /// Genera un ID único para la partida
    /// </summary>
    private string GenerateMatchID()
    {
        return $"D{CurrentEventDay}_M{eventDatabase.Matches.Count + 1}_{System.DateTime.Now:HHmmss}";
    }

    /// <summary>
    /// Obtiene jugadores ordenados del ScoreSystem
    /// </summary>
    private List<PlayerScore> GetSortedPlayers()
    {
        List<PlayerScore> players = new List<PlayerScore>(
            GameManager.Instance.ScoreSystem.ScoreMap.Values
        );

        players.Sort((a, b) => b.Score.CompareTo(a.Score));
        return players;
    }

    #region Métodos de Consulta (para análisis en runtime)

    /// <summary>
    /// Obtiene el mejor puntaje de un día específico
    /// </summary>
    public (string playerName, int score) GetBestScoreOfDay(int day)
    {
        var dayMatches = eventDatabase.Matches.Where(m => m.EventDay == day);

        if (!dayMatches.Any())
            return ("Ninguno", 0);

        int bestScore = dayMatches.Max(m => m.WinnerScore);
        var bestMatch = dayMatches.First(m => m.WinnerScore == bestScore);

        return (bestMatch.WinnerName, bestMatch.WinnerScore);
    }

    /// <summary>
    /// Obtiene el mejor puntaje de todo el evento
    /// </summary>
    public (string playerName, int score, int day) GetBestScoreOverall()
    {
        if (eventDatabase.Matches.Count == 0)
            return ("Ninguno", 0, 0);

        var bestMatch = eventDatabase.Matches.OrderByDescending(m => m.WinnerScore).First();
        return (bestMatch.WinnerName, bestMatch.WinnerScore, bestMatch.EventDay);
    }

    /// <summary>
    /// Obtiene estadísticas generales del evento
    /// </summary>
    public string GetEventStats()
    {
        int totalMatches = eventDatabase.Matches.Count;

        if (totalMatches == 0)
            return "No hay partidas registradas";

        var overall = GetBestScoreOverall();

        string stats = $"=== ESTADÍSTICAS DEL EVENTO ===\n";
        stats += $"Total de partidas: {totalMatches}\n";
        stats += $"Mejor puntaje general: {overall.playerName} - {overall.score} pts (Día {overall.day})\n\n";

        for (int day = 1; day <= 5; day++)
        {
            var dayBest = GetBestScoreOfDay(day);
            int dayMatches = eventDatabase.Matches.Count(m => m.EventDay == day);
            stats += $"Día {day}: {dayMatches} partidas - Mejor: {dayBest.playerName} ({dayBest.score} pts)\n";
        }

        return stats;
    }

    #endregion
}