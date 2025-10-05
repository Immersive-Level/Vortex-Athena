using UnityEngine;
using System;
using System.IO;

#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
using System.IO.Ports;
#endif

/// <summary>
/// Puente serie configurable por Inspector para comunicar el estado
/// de los jugadores con el Arduino.
/// </summary>
[DisallowMultipleComponent]
public class SerialBridgeBehaviour : MonoBehaviour
{
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

    string LogPath => Path.Combine(Application.persistentDataPath, logFileName);

#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
    private SerialPort port;
#endif

    private bool triedOpen = false;
    private bool platformSimulateForced = false;

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Debug.LogWarning("[SerialBridge] Ya existe una instancia. Destruyendo duplicada.");
            Destroy(gameObject);
            return;
        }
        Instance = this;
        // REMOVIDO: DontDestroyOnLoad(gameObject);
        // Ahora el ArcadeSystem se destruye al recargar la escena

#if !(UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN)
        platformSimulateForced = true;
        simulate = true;
#endif

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

    public void EnsureOpen()
    {
        if (simulate) return;

#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
        if (port != null && port.IsOpen) return;
        if (triedOpen && port == null) return;

        triedOpen = true;

        try
        {
            port = new SerialPort(portName, baudRate)
            {
                NewLine = "\n",
                DtrEnable = true
            };

            port.Open();
            port.DiscardInBuffer();
            port.DiscardOutBuffer();

            System.Threading.Thread.Sleep(300);

            Log($"CONNECTED {portName} @{baudRate}");
        }
        catch (Exception e)
        {
            Log($"CONNECT ERROR {portName}: {e.Message}");
            port = null;
        }
#else
        platformSimulateForced = true;
        simulate = true;
        Log("RUNNING IN SIMULATE (non-Windows platform)");
#endif
    }

    public void SendState(int playerId, bool alive)
    {
        if (playerId < 1) playerId = 1;

        string line = $"STATE {playerId} {(alive ? 1 : 0)}";

        if (simulate)
        {
            Log($"SIM SEND  {line}");
            return;
        }

        EnsureOpen();

#if UNITY_STANDALONE_WIN || UNITY_EDITOR_WIN
        if (port == null || !port.IsOpen)
        {
            Log($"SEND DROPPED (port closed)  {line}");
            return;
        }

        try
        {
            port.Write(line + "\n");
            Log($"SEND  {line}");
        }
        catch (Exception e)
        {
            Log($"SEND ERROR {e.Message}  [{line}]");
        }
#else
        Log($"SIM SEND (non-Windows)  {line}");
#endif
    }

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

    private void Log(string msg)
    {
        if (verboseLogs) Debug.Log($"[SerialBridge] {msg}");
        if (logToFile) SafeAppend($"{DateTime.Now:HH:mm:ss.fff}  {msg}");
    }

    private void SafeAppend(string line)
    {
        try
        {
            File.AppendAllText(LogPath, line + Environment.NewLine);
        }
        catch { /* ignore */ }
    }

    [ContextMenu("Test: STATE 1 0 (DEAD)")]
    private void TestSendDead() => SendState(1, false);

    [ContextMenu("Test: STATE 1 1 (ALIVE)")]
    private void TestSendAlive() => SendState(1, true);
}