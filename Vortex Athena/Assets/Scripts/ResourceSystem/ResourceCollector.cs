using UnityEngine;

/// <summary>
/// Componente que permite al jugador recolectar recursos
/// </summary>
public class ResourceCollector : MonoBehaviour
{
    [Tooltip("ID del jugador para identificación")]
    public int playerID = 1;

    [Tooltip("Referencia al sistema de puntuación")]
    public PlayerScoreSystem scoreSystem;

    [Tooltip("Referencia al sistema de combustible")]
    public Fuel_System fuelSystem;

    [Tooltip("Efecto visual al recolectar")]
    public GameObject collectEffect;

    [Tooltip("Radio para detectar recursos")]
    public float collectionRadius = 0.8f;

    [Tooltip("Capa de recursos recolectables")]
    public LayerMask resourceLayer;

    [Tooltip("Usar verificación adicional con OverlapCircle")]
    public bool useCircleCheck = true;

    [Tooltip("Intervalo para verificación adicional")]
    public float checkInterval = 0.2f;

    // Control de tiempo para verificación adicional
    private float lastCheckTime;

    // Buffer para resultados de OverlapCircle para evitar creación de arrays
    private Collider2D[] colliderBuffer = new Collider2D[10];

    private void Start()
    {
        // Auto-referencias si no están asignadas
        if (scoreSystem == null)
        {
            scoreSystem = GetComponent<PlayerScoreSystem>();
        }

        if (fuelSystem == null)
        {
            fuelSystem = GetComponent<Fuel_System>();
        }
    }

    private void Update()
    {
        // Verificación adicional con OverlapCircle si está habilitada
        if (useCircleCheck && Time.time > lastCheckTime + checkInterval)
        {
            CheckNearbyResources();
            lastCheckTime = Time.time;
        }
    }

    /// <summary>
    /// Verifica recursos cercanos usando OverlapCircle
    /// </summary>
    private void CheckNearbyResources()
    {
        // Usar buffer preasignado para evitar creación de arrays
        int count = Physics2D.OverlapCircleNonAlloc(transform.position, collectionRadius, colliderBuffer, resourceLayer);

        for (int i = 0; i < count; i++)
        {
            // Verificar si es un recurso válido
            Collider2D collider = colliderBuffer[i];
            if (collider == null) continue;

            CollectibleResource resource = collider.GetComponent<CollectibleResource>();
            if (resource != null && !resource.isCollected)
            {
                ProcessResource(resource);

                // Efecto visual
                if (collectEffect != null)
                {
                    Instantiate(collectEffect, collider.transform.position, Quaternion.identity);
                }
            }
        }
    }

    /// <summary>
    /// Procesa la recolección según el tipo de recurso
    /// </summary>
    private void ProcessResource(CollectibleResource resource)
    {
        if (resource == null || resource.resourceType == null) return;

        // Aplicar efecto según tipo
        switch (resource.resourceType.effect)
        {
            case ResourceType.ResourceEffect.Fuel:
                if (fuelSystem != null)
                {
                    fuelSystem.AddFuel(resource.resourceType.effectAmount);
                }
                break;

            case ResourceType.ResourceEffect.Points:
                if (scoreSystem != null)
                {
                    scoreSystem.AddScore(inScore: Mathf.RoundToInt(resource.resourceType.effectAmount));
                }
                break;
        }

        // Marcar como recolectado
        resource.CollectedByPlayer();
    }

    /// <summary>
    /// Detección por colisión
    /// </summary>
    private void OnTriggerEnter2D(Collider2D other)
    {
        CollectibleResource resource = other.GetComponent<CollectibleResource>();
        if (resource != null && !resource.isCollected)
        {
            ProcessResource(resource);

            // Efecto visual
            if (collectEffect != null)
            {
                Instantiate(collectEffect, other.transform.position, Quaternion.identity);
            }
        }
    }

    // Visualizar radio de recolección
    private void OnDrawGizmosSelected()
    {
        Gizmos.color = new Color(0.2f, 0.8f, 0.2f, 0.3f);
        Gizmos.DrawSphere(transform.position, collectionRadius);
    }
}