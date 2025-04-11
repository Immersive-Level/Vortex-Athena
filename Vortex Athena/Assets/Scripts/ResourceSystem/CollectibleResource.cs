using UnityEngine;

/// <summary>
/// Componente que representa un recurso recolectable en el juego
/// Se integra con AffectedByBlackHole para ser atraído por el agujero negro
/// </summary>
public class CollectibleResource : MonoBehaviour
{
    [Tooltip("Tipo de recurso que representa este objeto")]
    public ResourceType resourceType;

    [Tooltip("¿Debe rotarse aleatoriamente para efecto visual?")]
    public bool randomRotation = true;

    [Tooltip("Velocidad de rotación")]
    public float rotationSpeed = 30f;

    [Tooltip("Efecto visual cuando está cerca del agujero negro")]
    public bool pulseWhenClose = true;

    [Tooltip("Velocidad del pulso")]
    public float pulseSpeed = 2f;

    // Referencias a componentes
    private SpriteRenderer spriteRenderer;
    private AffectedByBlackHole affectedByBlackHole;
    private Transform blackHoleTransform;
    private bool isCollected = false;

    // Variables para efectos visuales
    private Vector3 rotationAxis;
    private float pulseTimer;
    private Vector3 originalScale;

    private void Awake()
    {
        // Obtener referencias a los componentes
        spriteRenderer = GetComponent<SpriteRenderer>();
        affectedByBlackHole = GetComponent<AffectedByBlackHole>();

        // Agregar el componente AffectedByBlackHole si no existe
        if (affectedByBlackHole == null)
        {
            affectedByBlackHole = gameObject.AddComponent<AffectedByBlackHole>();
        }

        // Configurar el sprite si tiene SpriteRenderer
        if (spriteRenderer != null && resourceType != null && resourceType.sprite != null)
        {
            spriteRenderer.sprite = resourceType.sprite;
            spriteRenderer.color = resourceType.resourceColor;
        }

        // Configurar rotación aleatoria
        if (randomRotation)
        {
            rotationAxis = Vector3.forward;
            rotationSpeed = Random.Range(20f, 50f) * (Random.value > 0.5f ? 1f : -1f);
        }

        // Guardar la escala original para efectos de pulso
        originalScale = transform.localScale;

        // Suscribirse a eventos del horizonte de eventos
        if (affectedByBlackHole != null)
        {
            affectedByBlackHole.onEnterEventHorizon += OnEnterEventHorizon;
        }

        // Buscar el agujero negro para efectos visuales
        BlackHole[] blackHoles = FindObjectsOfType<BlackHole>();
        if (blackHoles.Length > 0)
        {
            blackHoleTransform = blackHoles[0].transform;
        }
    }

    private void OnDestroy()
    {
        // Desuscribirse de eventos para evitar memory leaks
        if (affectedByBlackHole != null)
        {
            affectedByBlackHole.onEnterEventHorizon -= OnEnterEventHorizon;
        }
    }

    private void Update()
    {
        if (isCollected) return;

        // Rotación constante para efecto visual
        if (randomRotation)
        {
            transform.Rotate(rotationAxis, rotationSpeed * Time.deltaTime);
        }

        // Efecto de pulso cuando está cerca del agujero negro
        if (pulseWhenClose && affectedByBlackHole != null && affectedByBlackHole.isWithinEventHorizon)
        {
            pulseTimer += Time.deltaTime * pulseSpeed;
            float pulseFactor = 1f + Mathf.Sin(pulseTimer) * 0.2f;
            transform.localScale = originalScale * pulseFactor;
        }
        else if (transform.localScale != originalScale)
        {
            // Restaurar escala original gradualmente
            transform.localScale = Vector3.Lerp(transform.localScale, originalScale, Time.deltaTime * 5f);
        }

        // Verificar si está dentro del radio de absorción del agujero negro
        CheckForBlackHoleAbsorption();
    }

    /// <summary>
    /// Verifica si el recurso está dentro del radio de absorción del agujero negro
    /// </summary>
    private void CheckForBlackHoleAbsorption()
    {
        if (blackHoleTransform == null) return;

        // Buscar el componente de absorción en el agujero negro
        BlackHoleResourceAbsorber absorber = blackHoleTransform.GetComponent<BlackHoleResourceAbsorber>();

        if (absorber != null && absorber.IsWithinAbsorptionRadius(transform.position))
        {
            // Si está dentro del radio de absorción, ser absorbido
            AbsorbedByBlackHole();
        }
    }

    /// <summary>
    /// Se llama cuando el recurso entra en el horizonte de eventos del agujero negro
    /// </summary>
    private void OnEnterEventHorizon()
    {
        // Opcional: Activar efectos visuales específicos al entrar en el horizonte
        if (spriteRenderer != null)
        {
            // Aumentar el brillo o intensidad del color
            spriteRenderer.color = new Color(
                resourceType.resourceColor.r * 1.5f,
                resourceType.resourceColor.g * 1.5f,
                resourceType.resourceColor.b * 1.5f,
                resourceType.resourceColor.a
            );
        }
    }

    /// <summary>
    /// Se llama cuando este objeto es absorbido por el agujero negro
    /// </summary>
    public void AbsorbedByBlackHole()
    {
        if (isCollected) return;
        isCollected = true;

        // Solo aplicar efecto de puntos si es de ese tipo
        if (resourceType != null && resourceType.effect == ResourceType.ResourceEffect.Points)
        {
            // En un sistema multijugador, los puntos se asignarían al jugador más cercano
            // o podrían distribuirse entre todos los jugadores
            PlayerScoreSystem[] playerScoreSystems = FindObjectsOfType<PlayerScoreSystem>();

            if (playerScoreSystems.Length > 0)
            {
                // Asignar puntos al jugador más cercano, o a todos
                foreach (var scoreSystem in playerScoreSystems)
                {
                    scoreSystem.AddScore(Mathf.RoundToInt(resourceType.effectAmount / playerScoreSystems.Length));
                }
            }
        }

        // Reproducir sonido si tiene
        if (resourceType != null && resourceType.collectSound != null)
        {
            AudioSource.PlayClipAtPoint(resourceType.collectSound, transform.position);
        }

        // Mostrar efecto si tiene
        if (resourceType != null && resourceType.collectEffect != null)
        {
            Instantiate(resourceType.collectEffect, transform.position, Quaternion.identity);
        }

        // Devolver al pool o destruir
        DeactivateResource();
    }

    /// <summary>
    /// Se llama cuando este objeto es recolectado por el jugador
    /// </summary>
    public void CollectedByPlayer()
    {
        if (isCollected) return;
        isCollected = true;

        // La lógica de recolección específica ya se maneja en ResourceCollector
        // Este método solo marca el recurso como recolectado y lo desactiva

        // Devolver al pool o destruir
        DeactivateResource();
    }

    /// <summary>
    /// Desactiva o destruye el recurso
    /// </summary>
    private void DeactivateResource()
    {
        // Buscar el ResourceSpawner para devolver al pool
        ResourceSpawner spawner = FindObjectOfType<ResourceSpawner>();

        if (spawner != null)
        {
            spawner.ReturnToPool(gameObject);
        }
        else
        {
            // Si no hay spawner, simplemente destruir
            Destroy(gameObject);
        }
    }
}