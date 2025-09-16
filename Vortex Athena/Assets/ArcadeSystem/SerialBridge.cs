// Assets/ArcadeSystem/Scripts/SerialBridge.cs
// --------------------------------------------------------
// Abre el puerto serie hacia el Arduino Leonardo y envía
// comandos de estado de vida/muerte de los jugadores.
// Requiere en Player Settings -> Api Compatibility Level = .NET Framework / 4.x

using System.IO.Ports;
using System.Text;
using UnityEngine;

public class SerialBridge : MonoBehaviour
{
    [Header("Serial Config (Windows)")]
    [SerializeField] private string comPort = "COM6"; // cámbialo según el Administrador de dispositivos
    [SerializeField] private int baud = 115200;

    private static SerialPort port;

    private void OnEnable()
    {
        TryOpen();
    }

    private void OnDisable()
    {
        try { if (port != null && port.IsOpen) port.Close(); } catch { /* swallow */ }
    }

    private void TryOpen()
    {
        if (port != null && port.IsOpen) return;

        try
        {
            port = new SerialPort(comPort, baud)
            {
                NewLine = "\n",
                Encoding = Encoding.ASCII,
                DtrEnable = true // "despierta" el 32U4; si resetea, deja 300 ms antes de 1er Write
            };
            port.Open();
            port.DiscardInBuffer();
            port.DiscardOutBuffer();
            Debug.Log($"[SerialBridge] Opened {comPort} @ {baud}");
        }
        catch (System.Exception e)
        {
            Debug.LogWarning($"[SerialBridge] {e.Message}");
        }
    }

    /// <summary>
    /// Marca a un jugador (1..4) como vivo (true) o muerto (false).
    /// El Leonardo enciende/apaga o activa el patrón "latido" según corresponda.
    /// </summary>
    public static void SetAlive(int player, bool alive)
    {
        if (port == null || !port.IsOpen) return;
        string line = $"STATE {player} {(alive ? 1 : 0)}\n";
        try { port.Write(line); }
        catch (System.Exception e) { Debug.LogWarning($"[SerialBridge] {e.Message}"); }
    }
}

