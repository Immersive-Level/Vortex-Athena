using UnityEngine;
using System;               // DateTime
using System.IO;            // File / Path

#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
using System.IO.Ports;      // SerialPort (solo en Windows)
#endif

/// <summary>
/// Puente serie configurable por Inspector para comunicar el estado
/// de los jugadores con el Arduino.
/// - Envío: líneas "STATE <playerId> <0|1>\n"
/// - Soporta modo Simulate (no abre puerto; solo loguea).
/// - Guarda log a archivo opcional (para builds de campo).
/// Arrastra este componente a un GameObject (p.ej. "ArcadeSystem").
/// </summary>
[DisallowMultipleComponent]
public class SerialBridgeBehaviour : MonoBehaviour
{
    // Singleton conveniente para que la fachada estática pueda redirigir.
    public static SerialBridgeBehaviour Instance { get; private set; }

    [Header("Serial (Windows)")]
    [Tooltip("Nombre del puerto COM que usa el Arduino (ej. COM6). Solo Windows.")]
    public string portName = "COM6";

    [Tooltip("Velocidad en baudios. Debe coincidir con el sketch del Arduino.")]
    public int baudRate = 115200;

    [Header("Opciones")]
    [Tooltip("Si está activado NO se abre el puerto: solo se registran los mensajes (pruebas sin Arduino).")]
    public bool simulate = true;

    [Tooltip("Intentar conexión automáticamente al habilitar la escena.")]
    public bool autoConnect = true;

    [Tooltip("Mostrar mensajes en la consola de Unity (Editor/Development build).")]
    public bool verboseLogs = true;

    [Header("Logging a archivo (opcional)")]
    [Tooltip("Guardar cada evento en un archivo de log (útil en máquinas de hardware).")]
    public bool logToFile = true;

    [Tooltip("Nombre del archivo de log; se guarda en Application.persistentDataPath.")]
    public string logFileName = "ArcadeSerial.log";

    // Ruta completa al archivo de log (carpeta por usuario/juego)
    string LogPath => Path.Combine(Application.persistentDataPath, logFileName);

#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
    private SerialPort port;       // Puerto serie real (Windows)
#endif

    private bool triedOpen = false; // Evita reintentos infinitos si falló abrir
    private bool platformSimulateForced = false; // true si forzamos simulate por no ser Windows

    // ------------------------------ Ciclo de vida ------------------------------

    private void Awake()
    {
        // Singleton simple
        if (Instance != null && Instance != this)
        {
            Debug.LogWarning("[SerialBridge] Ya existe una instancia. Destruyendo duplicada.");
            Destroy(gameObject);
            return;
        }
        Instance = this;
        // Opcional: persistir entre escenas
        DontDestroyOnLoad(gameObject);

        // En plataformas que NO sean Windows, forzamos simulate para evitar errores de compilación/ejecución.
#if !(UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN)
        platformSimulateForced = true;
        simulate = true;
#endif

        // Cabecera del log a archivo
        if (logToFile)
        {
            SafeAppend($"===== START {DateTime.Now:yyyy-MM-dd HH:mm:ss} =====");
            SafeAppend($"Platform={Application.platform}  Port={portName}  Baud={baudRate}  Simulate={simulate}");
        }
    }

    private void OnEnable()
    {
        if (autoConnect) EnsureOpen();
    }

    private void OnDisable()
    {
        Close();
    }

    private void OnDestroy()
    {
        Close();
        if (Instance == this) Instance = null;
    }

    private void OnApplicationQuit()
    {
        Close();
    }

    // ------------------------------ API pública ------------------------------

    /// <summary>
    /// Abre el puerto si corresponde (Windows + simulate=false).
    /// En modo simulate o en no-Windows, no hace nada.
    /// </summary>
    public void EnsureOpen()
    {
        // Si estamos simulando, no abrimos nada
        if (simulate) return;

        // Solo Windows soporta SerialPort en runtime
#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
        // Ya está abierto
        if (port != null && port.IsOpen) return;

        // Si ya intentamos y falló, no insistir en el mismo frame (se puede reintentar más tarde si quieres)
        if (triedOpen && port == null) return;

        triedOpen = true;

        try
        {
            port = new SerialPort(portName, baudRate)
            {
                NewLine = "\n",  // Terminador LF (Arduino: readStringUntil('\n'))
                DtrEnable = true   // 32U4: indica al Arduino que se “despierte” (puede resetear)
            };

            port.Open();
            port.DiscardInBuffer();
            port.DiscardOutBuffer();

            // Espera breve por el reset del 32U4 al abrir (evita perder el primer mensaje)
            System.Threading.Thread.Sleep(300);

            Log($"CONNECTED {portName} @{baudRate}");
        }
        catch (Exception e)
        {
            Log($"CONNECT ERROR {portName}: {e.Message}");
            // limpiar referencia para permitir intentos posteriores si se desea
            port = null;
        }
#else
        // No-Windows: siempre en simulate
        platformSimulateForced = true;
        simulate = true;
        Log("RUNNING IN SIMULATE (non-Windows platform)");
#endif
    }

    /// <summary>
    /// Envía el estado de vida/muerte de un jugador.
    /// Formato: "STATE <playerId> <0|1>\n"
    /// </summary>
    public void SendState(int playerId, bool alive)
    {
        // Sanitizar playerId (tu juego suele mapear 1..4)
        if (playerId < 1) playerId = 1;

        string line = $"STATE {playerId} {(alive ? 1 : 0)}";

        // Simulación: NO se abre puerto, solo log
        if (simulate)
        {
            Log($"SIM SEND  {line}");
            return;
        }

        // Abrir si hace falta
        EnsureOpen();

#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
        if (port == null || !port.IsOpen)
        {
            Log($"SEND DROPPED (port closed)  {line}");
            return;
        }

        try
        {
            port.Write(line + "\n"); // Importante: \n final, coincide con readStringUntil('\n')
            Log($"SEND  {line}");
        }
        catch (Exception e)
        {
            Log($"SEND ERROR {e.Message}  [{line}]");
        }
#else
        // No-Windows: por seguridad mantenemos simulate
        Log($"SIM SEND (non-Windows)  {line}");
#endif
    }

    /// <summary>
    /// Cierra el puerto si está abierto. Seguro de llamar múltiples veces.
    /// </summary>
    public void Close()
    {
#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
        if (port != null)
        {
            try
            {
                if (port.IsOpen) port.Close();
                Log("DISCONNECTED");
            }
            catch (Exception e)
            {
                Log($"DISCONNECT ERROR {e.Message}");
            }
            finally
            {
                try { port.Dispose(); } catch { /* ignore */ }
                port = null;
            }
        }
#endif
        triedOpen = false;
    }

    // ------------------------------ Utilidades ------------------------------

    /// <summary>Log a consola (si verbose) y a archivo (si logToFile).</summary>
    private void Log(string msg)
    {
        if (verboseLogs) Debug.Log($"[SerialBridge] {msg}");
        if (logToFile) SafeAppend($"{DateTime.Now:HH:mm:ss.fff}  {msg}");
    }

    /// <summary>Append protegido para que errores de IO no rompan el juego.</summary>
    private void SafeAppend(string line)
    {
        try
        {
            File.AppendAllText(LogPath, line + Environment.NewLine);
        }
        catch
        {
            // Ignorar errores de escritura (disco bloqueado, permisos, etc.)
        }
    }

    // ------------------------------ Tests desde el Inspector ------------------------------

    [ContextMenu("Test: STATE 1 0 (DEAD)")]
    private void TestSendDead() => SendState(1, false);

    [ContextMenu("Test: STATE 1 1 (ALIVE)")]
    private void TestSendAlive() => SendState(1, true);
}


