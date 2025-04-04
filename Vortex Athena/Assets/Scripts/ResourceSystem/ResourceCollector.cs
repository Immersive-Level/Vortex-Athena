using UnityEngine;

/// <summary>
/// Componente que permite a un jugador recolectar recursos.
/// Se debe agregar al objeto del jugador junto con ShipController.
/// </summary>
public class ResourceCollector : MonoBehaviour
{
    [Tooltip("ID del jugador para identificaci�n")]
    public int playerID = 1;
    
    [Tooltip("Referencia al sistema de puntuaci�n del jugador")]
    public PlayerScoreSystem scoreSystem;
    
    [Tooltip("Referencia al sistema de combustible del jugador")]
    public Fuel_System fuelSystem;
    
    [Tooltip("Efecto visual al recolectar un recurso")]
    public GameObject collectEffect;
    
    [Tooltip("Radio para detectar colisiones con recursos")]
    public float collectionRadius = 0.8f;
    
    private void Start()
    {
        // Buscar componentes en el mismo objeto si no est�n asignados
        if (scoreSystem == null)
        {
            scoreSystem = GetComponent<PlayerScoreSystem>();
        }
        
        if (fuelSystem == null)
        {
            fuelSystem = GetComponent<Fuel_System>();
        }
    }
    
    /// <summary>
    /// M�todo llamado cuando un recurso de tipo Fuel es recolectado
    /// </summary>
    /// <param name="amount">Cantidad de combustible</param>
    public void CollectFuel(float amount)
    {
        if (fuelSystem != null)
        {
            fuelSystem.AddFuel(amount);
        }
    }
    
    /// <summary>
    /// M�todo llamado cuando un recurso de tipo Points es recolectado
    /// </summary>
    /// <param name="points">Cantidad de puntos</param>
    public void CollectPoints(int points)
    {
        if (scoreSystem != null)
        {
            scoreSystem.AddScore(points);
        }
    }
    
    /// <summary>
    /// Maneja la colecci�n de recursos mediante colisi�n
    /// </summary>
    private void OnTriggerEnter2D(Collider2D other)
    {
        // Verificar si es un recurso
        CollectibleResource resource = other.GetComponent<CollectibleResource>();
        
        if (resource != null)
        {
            // Procesar el recurso seg�n su tipo
            ProcessResource(resource);
            
            // Crear efecto de recolecci�n
            if (collectEffect != null)
            {
                Instantiate(collectEffect, other.transform.position, Quaternion.identity);
            }
        }
    }
    
    /// <summary>
    /// Procesa un recurso seg�n su tipo
    /// </summary>
    private void ProcessResource(CollectibleResource resource)
    {
        if (resource.resourceType != null)
        {
            // Aplicar efecto seg�n el tipo
            if (resource.resourceType.effect == ResourceType.ResourceEffect.Fuel)
            {
                CollectFuel(resource.resourceType.effectAmount);
            }
            else if (resource.resourceType.effect == ResourceType.ResourceEffect.Points)
            {
                CollectPoints(Mathf.RoundToInt(resource.resourceType.effectAmount));
            }
            
            // Reproducir sonido si tiene
            if (resource.resourceType.collectSound != null)
            {
                AudioSource.PlayClipAtPoint(resource.resourceType.collectSound, transform.position);
            }
            
            // Mostrar efecto si tiene
            if (resource.resourceType.collectEffect != null)
            {
                Instantiate(resource.resourceType.collectEffect, resource.transform.position, Quaternion.identity);
            }
            
            // Marcar como recolectado
            resource.CollectedByPlayer();
        }
    }
    
    // Visualizar el radio de recolecci�n
    private void OnDrawGizmosSelected()
    {
        Gizmos.color = new Color(0.2f, 0.8f, 0.2f, 0.3f);
        Gizmos.DrawSphere(transform.position, collectionRadius);
    }
}
