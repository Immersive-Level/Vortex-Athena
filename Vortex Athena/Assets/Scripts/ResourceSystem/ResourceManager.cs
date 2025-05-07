using UnityEngine;

/// <summary>
/// Componente para supervisión global del sistema de recursos
/// </summary>
public class ResourceManager : MonoBehaviour
{
    [Tooltip("Tiempo de vida máximo de recursos huérfanos")]
    public float orphanedResourceLifetime = 30f;

    /// <summary>
    /// Limpia recursos huérfanos (sin spawner) cada cierto tiempo
    /// </summary>
    private void Update()
    {
        // Evitar llamado frecuente al usar Invoke
        if (Time.frameCount % 300 == 0)  // Cada ~5 segundos a 60fps
        {
            Invoke("CleanupOrphanedResources", 0.1f); // Fuera del Update para no impactar rendimiento
        }
    }

    /// <summary>
    /// Limpia recursos huérfanos
    /// </summary>
    private void CleanupOrphanedResources()
    {
        // Si hay un spawner funcionando, no es necesario
        if (ResourceSpawner.Instance != null) return;

        // Buscar recursos activos sin spawner
        CollectibleResource[] resources = FindObjectsOfType<CollectibleResource>();
        foreach (CollectibleResource resource in resources)
        {
            if (resource != null && resource.gameObject.activeInHierarchy)
            {
                // Destruir directamente
                Destroy(resource.gameObject);
                Debug.LogWarning("Destroyed orphaned resource: " + resource.name);
            }
        }
    }
}