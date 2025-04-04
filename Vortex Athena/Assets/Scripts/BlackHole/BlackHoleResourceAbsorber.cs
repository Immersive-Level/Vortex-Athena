using UnityEngine;

/// <summary>
/// Componente dedicado a la absorción de recursos por el agujero negro.
/// Se agrega al mismo GameObject que contiene el BlackHole para mantener
/// la separación de responsabilidades (principio SRP de SOLID).
/// </summary>
public class BlackHoleResourceAbsorber : MonoBehaviour
{
    [Tooltip("Radio de absorción de recursos")]
    public float absorptionRadius = 1.5f;

    [Tooltip("Efecto visual al absorber un recurso")]
    public GameObject absorptionEffect;

    [Tooltip("Sonido al absorber un recurso")]
    public AudioClip absorptionSound;

    // Referencia al BlackHole
    private BlackHole blackHole;

    private void Start()
    {
        // Obtener referencia al BlackHole en el mismo objeto
        blackHole = GetComponent<BlackHole>();

        if (blackHole == null)
        {
            Debug.LogError("BlackHoleResourceAbsorber debe estar en el mismo GameObject que BlackHole");
            enabled = false;
            return;
        }
    }

    private void Update()
    {
        // Solo verificar si el agujero negro está activo
        if (blackHole == null || !blackHole.isActive) return;

        // Buscar recursos dentro del radio de absorción
        Collider2D[] colliders = Physics2D.OverlapCircleAll(transform.position, absorptionRadius);

        foreach (var collider in colliders)
        {
            // Verificar si es un recurso
            CollectibleResource resource = collider.GetComponent<CollectibleResource>();

            if (resource != null)
            {
                // Llamar al método de absorción del recurso
                resource.AbsorbedByBlackHole();

                // Mostrar efecto visual si está configurado
                if (absorptionEffect != null)
                {
                    Instantiate(absorptionEffect, collider.transform.position, Quaternion.identity);
                }

                // Reproducir sonido si está configurado
                if (absorptionSound != null)
                {
                    AudioSource.PlayClipAtPoint(absorptionSound, transform.position);
                }
            }
        }
    }

    /// <summary>
    /// Verifica si un objeto está dentro del radio de absorción
    /// </summary>
    /// <param name="position">Posición a verificar</param>
    /// <returns>True si está dentro del radio</returns>
    public bool IsWithinAbsorptionRadius(Vector3 position)
    {
        return Vector3.Distance(transform.position, position) <= absorptionRadius;
    }

    // Dibujar radio de absorción para facilitar el diseño
    private void OnDrawGizmosSelected()
    {
        Gizmos.color = new Color(1f, 0.3f, 0.3f, 0.4f);
        Gizmos.DrawSphere(transform.position, absorptionRadius);
    }
}