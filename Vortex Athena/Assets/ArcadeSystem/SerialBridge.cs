using UnityEngine;

public static class SerialBridge
{
    public static void SendState(int playerId, bool alive)
    {
        var inst = SerialBridgeBehaviour.Instance;
        if (inst == null)
        {
            Debug.LogWarning("[SerialBridge] No hay instancia en escena. " +
                             "Agrega 'SerialBridgeBehaviour' a un GameObject.");
            return;
        }
        inst.SendState(playerId, alive);
    }
}


