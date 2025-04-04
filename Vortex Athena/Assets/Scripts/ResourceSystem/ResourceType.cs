using UnityEngine;

/// <summary>
/// Define un tipo de recurso recolectable en el juego
/// </summary>
[CreateAssetMenu(fileName = "New Resource Type", menuName = "Game/Resource Type")]
public class ResourceType : ScriptableObject
{
    public enum ResourceEffect
    {
        Fuel,    // Aumenta el combustible/vida del jugador
        Points   // Aumenta los puntos del jugador
    }

    [Tooltip("Nombre del recurso")]
    public string resourceName;

    [Tooltip("Efecto que produce este recurso")]
    public ResourceEffect effect;

    [Tooltip("Cantidad de efecto que produce (combustible o puntos)")]
    public float effectAmount = 10f;

    [Tooltip("Sprite del recurso")]
    public Sprite sprite;

    [Tooltip("Sonido que se reproduce al recolectar")]
    public AudioClip collectSound;

    [Tooltip("Prefab de efecto de partículas al recolectar (opcional)")]
    public GameObject collectEffect;

    [Tooltip("Color para efectos visuales")]
    public Color resourceColor = Color.white;
}
