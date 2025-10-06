using UnityEngine;

/// <summary>
/// Script temporal de debugging para el Scoreboard
/// USAR SOLO PARA DEBUG - ELIMINAR EN PRODUCCIÓN
/// </summary>
public class ScoreboardDebugger : MonoBehaviour
{
    [Header("Debug Settings")]
    [Tooltip("Forzar generación al presionar tecla")]
    public KeyCode ForceGenerateKey = KeyCode.F5;

    [Tooltip("Activar logs detallados")]
    public bool VerboseLogging = true;

    private ScoreboardDisplay scoreboardDisplay;

    private void Start()
    {
        scoreboardDisplay = GetComponent<ScoreboardDisplay>();

        if (scoreboardDisplay == null)
        {
            Debug.LogError("ScoreboardDebugger: No se encontró ScoreboardDisplay en este GameObject");
            return;
        }

        Debug.Log("=== SCOREBOARD DEBUGGER INICIADO ===");
        LogCurrentState();
    }

    private void Update()
    {
        // Forzar generación manual con tecla
        if (Input.GetKeyDown(ForceGenerateKey))
        {
            Debug.Log("=== GENERACIÓN FORZADA POR TECLA ===");
            LogCurrentState();

            if (scoreboardDisplay != null)
            {
                scoreboardDisplay.RefreshScoreboard();
            }
        }
    }

    private void OnEnable()
    {
        if (VerboseLogging)
        {
            Debug.Log($"ScoreboardPanel ACTIVADO en frame {Time.frameCount}");
            LogCurrentState();
        }
    }

    private void OnDisable()
    {
        if (VerboseLogging)
        {
            Debug.Log($"ScoreboardPanel DESACTIVADO en frame {Time.frameCount}");
        }
    }

    /// <summary>
    /// Muestra el estado actual del sistema completo
    /// </summary>
    public void LogCurrentState()
    {
        Debug.Log("╔════════════════════════════════════════╗");
        Debug.Log("║    SCOREBOARD DEBUG STATE CHECK       ║");
        Debug.Log("╚════════════════════════════════════════╝");

        // GameManager
        if (GameManager.Instance == null)
        {
            Debug.LogError("❌ GameManager.Instance es NULL");
            return;
        }
        Debug.Log($"✅ GameManager existe");
        Debug.Log($"   Estado actual: {GameManager.Instance.CurrentState}");

        // ScoreSystem
        if (GameManager.Instance.ScoreSystem == null)
        {
            Debug.LogError("❌ GameManager.ScoreSystem es NULL");
            return;
        }
        Debug.Log($"✅ ScoreSystem existe");

        // Jugadores
        var scoreMap = GameManager.Instance.ScoreSystem.ScoreMap;
        Debug.Log($"   Jugadores registrados: {scoreMap.Count}");

        if (scoreMap.Count == 0)
        {
            Debug.LogWarning("⚠️  No hay jugadores registrados en ScoreSystem");
        }
        else
        {
            Debug.Log("   Lista de jugadores:");
            foreach (var kvp in scoreMap)
            {
                var player = kvp.Value;
                Debug.Log($"     - {player.PlayerName}: {player.Score} pts (K:{player.Kills} D:{player.Deaths})");
            }
        }

        // Referencias del ScoreboardDisplay
        if (scoreboardDisplay != null)
        {
            Debug.Log($"✅ ScoreboardDisplay existe");

            if (scoreboardDisplay.RowPrefab == null)
                Debug.LogError("❌ RowPrefab NO está asignado");
            else
                Debug.Log($"✅ RowPrefab: {scoreboardDisplay.RowPrefab.name}");

            if (scoreboardDisplay.RowContainer == null)
                Debug.LogError("❌ RowContainer NO está asignado");
            else
                Debug.Log($"✅ RowContainer: {scoreboardDisplay.RowContainer.name}");
        }
        else
        {
            Debug.LogError("❌ ScoreboardDisplay NO encontrado");
        }

        // Content (filas generadas)
        if (scoreboardDisplay != null && scoreboardDisplay.RowContainer != null)
        {
            int childCount = scoreboardDisplay.RowContainer.childCount;
            Debug.Log($"   Filas actuales en Content: {childCount}");

            if (childCount > 0)
            {
                Debug.Log("   Filas existentes:");
                for (int i = 0; i < childCount; i++)
                {
                    var child = scoreboardDisplay.RowContainer.GetChild(i);
                    Debug.Log($"     - {child.name} (activo: {child.gameObject.activeSelf})");
                }
            }
        }

        Debug.Log("════════════════════════════════════════");
    }

    /// <summary>
    /// Botón en Inspector para verificar estado
    /// </summary>
    [ContextMenu("Check Current State")]
    public void CheckState()
    {
        LogCurrentState();
    }

    /// <summary>
    /// Botón en Inspector para forzar generación
    /// </summary>
    [ContextMenu("Force Generate Scoreboard")]
    public void ForceGenerate()
    {
        Debug.Log("=== GENERACIÓN FORZADA POR MENÚ ===");
        if (scoreboardDisplay != null)
        {
            scoreboardDisplay.RefreshScoreboard();
        }
        else
        {
            Debug.LogError("No se puede forzar: ScoreboardDisplay no encontrado");
        }
    }
}