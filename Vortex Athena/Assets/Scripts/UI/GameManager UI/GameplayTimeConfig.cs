using UnityEngine;

/// <summary>
/// ScriptableObject que almacena las opciones de tiempo disponibles para el gameplay.
/// Crear mediante: Assets > Create > Game Config > Gameplay Time Config
/// </summary>
[CreateAssetMenu(fileName = "GameplayTimeConfig", menuName = "Game Config/Gameplay Time Config")]
public class GameplayTimeConfig : ScriptableObject
{
    [Header("Opciones de Tiempo")]
    [Tooltip("Tiempos disponibles en segundos para seleccionar en la configuración")]
    public float[] tiemposDisponibles = { 60f, 90f, 120f };

    /// <summary>
    /// Obtiene el texto formateado para mostrar en UI
    /// </summary>
    public string GetTextoTiempo(int index)
    {
        if (index < 0 || index >= tiemposDisponibles.Length)
            return "";

        return $"{tiemposDisponibles[index]} segundos";
    }

    /// <summary>
    /// Obtiene el valor de tiempo en el índice especificado
    /// </summary>
    public float GetTiempo(int index)
    {
        if (index < 0 || index >= tiemposDisponibles.Length)
            return tiemposDisponibles[0];

        return tiemposDisponibles[index];
    }

    /// <summary>
    /// Retorna el número total de opciones disponibles
    /// </summary>
    public int CantidadOpciones => tiemposDisponibles.Length;
}