using System.IO.Ports;
using UnityEngine;

/// <summary>
/// Puente serie configurable por Inspector. Abre el puerto COM y envía
/// líneas "STATE <playerId> <0/1>" al Arduino. Si "Simulate" está activo,
/// no abre puerto: solo loguea lo que se enviaría.
/// HAZ: Arrastrar este componente a un GameObject en la escena.
/// </summary>
[DisallowMultipleComponent]
public class SerialBridgeBehaviour : MonoBehaviour
{
    public static SerialBridgeBehaviour Instance { get; private set; }

    [Header("Serial (Windows)")]
    [Tooltip("Nombre del puerto COM (Administración de dispositivos)")]
    public string portName = "COM6";

    [Tooltip("Baudrate")]
    public int baudRate = 115200;

    [Header("Opciones")]
    [Tooltip("Si está activo, no abre puerto: solo loguea (para pruebas sin Arduino).")]
    public bool simulate = true;

    [Tooltip("Conectarse automáticamente al habilitar la escena.")]
    public bool autoConnect = true;

    [Tooltip("Mostrar logs de conexión y mensajes enviados.")]
    public bool verboseLogs = true;

    private SerialPort port;      // instancia real del puerto
    private bool triedOpen = false;

    void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Debug.LogWarning("[SerialBridgeBehaviour] Ya existe una instancia. Destruyendo duplicado.");
            Destroy(gameObject);
            return;
        }
        Instance = this;
        DontDestroyOnLoad(gameObject); // opcional: persiste entre escenas
    }

    void OnEnable()
    {
        if (autoConnect) EnsureOpen();
    }

    void OnDisable()
    {
        Close();
    }

    void OnDestroy()
    {
        Close();
        if (Instance == this) Instance = null;
    }

    /// <summary>Abre el puerto (si no está abierto) o simula si simulate=true.</summary>
    public void EnsureOpen()
    {
        if (simulate) return; // en simulación no se abre nada

        if (port != null && port.IsOpen) return;

        // Evita spamear intentos si falla
        if (triedOpen && port == null)
            return;

        triedOpen = true;

        try
        {
            port = new SerialPort(portName, baudRate)
            {
                NewLine = "\n",
                DtrEnable = true // despierta el Leonardo 32U4
            };
            port.Open();
            port.DiscardInBuffer();
            port.DiscardOutBuffer();

            if (verboseLogs)
                Debug.Log($"[SerialBridge] Conectado a {portName} @ {baudRate}");
        }
        catch (System.Exception e)
        {
            if (verboseLogs)
                Debug.LogWarning($"[SerialBridge] No se pudo abrir {portName}: {e.Message}");
            // Si falla, dejamos port = null; otro EnsureOpen() puede reintentar
            port = null;
        }
    }

    /// <summary>Envía el estado al Arduino. Si simulate=true, solo loguea.</summary>
    public void SendState(int playerId, bool alive)
    {
        string line = $"STATE {playerId} {(alive ? 1 : 0)}";

        if (simulate)
        {
            if (verboseLogs) Debug.Log($"[SerialBridge SIM] {line}");
            return;
        }

        EnsureOpen();
        if (port == null || !port.IsOpen)
        {
            if (verboseLogs) Debug.LogWarning("[SerialBridge] Puerto no disponible. Mensaje descartado: " + line);
            return;
        }

        try
        {
            port.Write(line + "\n");
            if (verboseLogs) Debug.Log("[SerialBridge] " + line);
        }
        catch (System.Exception e)
        {
            if (verboseLogs) Debug.LogWarning("[SerialBridge] " + e.Message);
        }
    }

    /// <summary>Cierra el puerto si está abierto.</summary>
    public void Close()
    {
        if (port != null)
        {
            try
            {
                if (port.IsOpen) port.Close();
            }
            catch { /* ignore */ }
            finally
            {
                port.Dispose();
                port = null;
            }
        }
        triedOpen = false;
    }
}

