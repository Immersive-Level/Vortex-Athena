// Assets/ArcadeSystem/Scripts/ArcadeEvents.cs
// --------------------------------------------------------
// Bus de eventos simple para desacoplar el IO de la lógica
// del gameplay. Tu core escucha aquí sin referenciar Scripts
// de ArcadeSystem directamente.

using System;

public static class ArcadeEvents
{
    // Se dispara cuando un jugador (1..4) presiona su botón físico
    public static event Action<int> OnPress;

    public static void RaisePress(int player)
        => OnPress?.Invoke(player);
}
