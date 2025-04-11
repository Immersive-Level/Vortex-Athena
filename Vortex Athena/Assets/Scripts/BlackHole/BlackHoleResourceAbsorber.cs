using UnityEngine;

/// <summary>
/// Componente dedicado a la absorci�n de recursos por el agujero negro.
/// Se agrega al mismo GameObject que contiene el BlackHole para mantener
/// la separaci�n de responsabilidades (principio SRP de SOLID).
/// </summary>
public class BlackHoleResourceAbsorber : MonoBehaviour
{
    [Tooltip("Radio de absorci�n de recursos")]
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
        // Solo verificar si el agujero negro est� activo
        if (blackHole == null || !blackHole.isActive) return;

        // Buscar recursos dentro del radio de absorci�n
        Collider2D[] colliders = Physics2D.OverlapCircleAll(transform.position, absorptionRadius);

        foreach (var collider in colliders)
        {
            // Verificar si es un recurso
            CollectibleResource resource = collider.GetComponent<CollectibleResource>();

            if (resource != null)
            {
                // Llamar al m�todo de absorci�n del recurso
                resource.AbsorbedByBlackHole();

                // Mostrar efecto visual si est� configurado
                if (absorptionEffect != null)
                {
                    Instantiate(absorptionEffect, collider.transform.position, Quaternion.identity);
                }

                // Reproducir sonido si est� configurado
                if (absorptionSound != null)
                {
                    AudioSource.PlayClipAtPoint(absorptionSound, transform.position);
                }
            }
        }
    }

    /// <summary>
    /// Verifica si un objeto est� dentro del radio de absorci�n
    /// </summary>
    /// <param name="position">Posici�n a verificar</param>
    /// <returns>True si est� dentro del radio</returns>
    public bool IsWithinAbsorptionRadius(Vector3 position)
    {
        return Vector3.Distance(transform.position, position) <= absorptionRadius;
    }

    // Dibujar radio de absorci�n para facilitar el dise�o
    private void OnDrawGizmosSelected()
    {
        Gizmos.color = new Color(1f, 0.3f, 0.3f, 0.4f);
        Gizmos.DrawSphere(transform.position, absorptionRadius);
    }
}