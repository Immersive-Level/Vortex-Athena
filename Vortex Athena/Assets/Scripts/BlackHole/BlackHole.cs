using UnityEngine;

/// <summary>
/// Sistema de agujero negro enfocado exclusivamente en las propiedades físicas.
/// Maneja la atracción gravitacional de objetos cercanos.
/// </summary>
[RequireComponent(typeof(CircleCollider2D))]
public class BlackHole : MonoBehaviour
{
    #region Inspector Properties

    [Header("⚙️ Propiedades Físicas")]
    [Space(10)]

    [Tooltip("Radio del núcleo del agujero negro (zona de absorción instantánea)")]
    [SerializeField, Range(0.5f, 10f)]
    private float coreRadius = 2f;

    [Tooltip("Radio del horizonte de eventos (zona de no retorno)")]
    [SerializeField, Range(1f, 15f)]
    private float eventHorizonRadius = 5f;

    [Tooltip("Distancia máxima de atracción gravitacional")]
    [SerializeField, Range(5f, 50f)]
    private float maxEffectDistance = 30f;

    [Tooltip("Fuerza máxima de atracción en el borde del horizonte de eventos")]
    [SerializeField, Range(10f, 200f)]
    private float maxAttractionForce = 50f;

    [Tooltip("Curva de atracción (1 = lineal, 2 = cuadrática, >2 = más agresiva)")]
    [SerializeField, Range(1f, 5f)]
    private float attractionCurve = 2f;

    [Tooltip("Multiplicador de fuerza rotacional (efecto de espiral)")]
    [SerializeField, Range(0f, 2f)]
    private float rotationalForceMultiplier = 0.5f;

    [Header("⚙️ Configuración")]
    [Space(10)]

    [Tooltip("¿El agujero negro está activo?")]
    [SerializeField]
    private bool isActive = true;

    [Tooltip("Capas de física que pueden ser afectadas")]
    [SerializeField]
    private LayerMask affectedLayers = -1;

    [Header("📊 Debug")]
    [Space(10)]

    [Tooltip("Mostrar información de debug en consola")]
    [SerializeField]
    private bool debugMode = false;

    [Tooltip("Mostrar gizmos en el editor")]
    [SerializeField]
    private bool showGizmos = true;

    #endregion

    #region Private Variables

    private CircleCollider2D detectionCollider;
    private int objectsInRange = 0;
    private float lastForceCalculation = 0f;

    #endregion

    #region Properties

    /// <summary>
    /// Estado activo del agujero negro
    /// </summary>
    public bool IsActive
    {
        get => isActive;
        set
        {
            isActive = value;
            if (!isActive && debugMode)
            {
                Debug.Log($"[BlackHole] {name} desactivado");
            }
        }
    }

    /// <summary>
    /// Radio del núcleo del agujero negro
    /// </summary>
    public float CoreRadius => coreRadius;

    /// <summary>
    /// Radio del horizonte de eventos
    /// </summary>
    public float EventHorizonRadius => eventHorizonRadius;

    /// <summary>
    /// Distancia máxima de efecto
    /// </summary>
    public float MaxEffectDistance => maxEffectDistance;

    #endregion

    #region Unity Lifecycle

    private void Awake()
    {
        ValidateConfiguration();
        SetupCollider();
    }

    private void OnValidate()
    {
        // Asegurar que los radios tengan sentido lógico
        if (coreRadius > eventHorizonRadius)
        {
            coreRadius = eventHorizonRadius * 0.5f;
        }

        if (eventHorizonRadius > maxEffectDistance)
        {
            eventHorizonRadius = maxEffectDistance * 0.5f;
        }

        // Actualizar collider si existe
        if (Application.isPlaying && detectionCollider != null)
        {
            detectionCollider.radius = maxEffectDistance;
        }
    }

    #endregion

    #region Initialization

    /// <summary>
    /// Valida la configuración inicial del agujero negro
    /// </summary>
    private void ValidateConfiguration()
    {
        // Validar jerarquía de radios
        if (coreRadius > eventHorizonRadius || eventHorizonRadius > maxEffectDistance)
        {
            Debug.LogError($"[BlackHole] {name}: Configuración inválida de radios. " +
                          $"Debe ser: CoreRadius < EventHorizonRadius < MaxEffectDistance");
            enabled = false;
            return;
        }

        // Validar que no esté en un Canvas UI
        if (GetComponentInParent<Canvas>() != null)
        {
            Debug.LogWarning($"[BlackHole] {name}: Detectado dentro de un Canvas UI. " +
                           "El agujero negro debe estar en el espacio del mundo 2D.");
        }
    }

    /// <summary>
    /// Configura el collider de detección
    /// </summary>
    private void SetupCollider()
    {
        detectionCollider = GetComponent<CircleCollider2D>();
        if (detectionCollider == null)
        {
            detectionCollider = gameObject.AddComponent<CircleCollider2D>();
        }

        detectionCollider.isTrigger = true;
        detectionCollider.radius = maxEffectDistance;
    }

    #endregion

    #region Physics Calculations

    /// <summary>
    /// Calcula la fuerza de atracción basada en la distancia
    /// </summary>
    /// <param name="distance">Distancia al centro del agujero negro</param>
    /// <returns>Magnitud de la fuerza de atracción</returns>
    public float CalculateAttractionForce(float distance)
    {
        if (!isActive || distance > maxEffectDistance)
            return 0f;

        // Zona del núcleo - fuerza máxima absoluta
        if (distance <= coreRadius)
        {
            lastForceCalculation = maxAttractionForce * 2f; // Fuerza duplicada en el núcleo
            return lastForceCalculation;
        }

        // Zona del horizonte de eventos - fuerza muy alta
        if (distance <= eventHorizonRadius)
        {
            float t = (distance - coreRadius) / (eventHorizonRadius - coreRadius);
            lastForceCalculation = Mathf.Lerp(maxAttractionForce * 2f, maxAttractionForce, t);
            return lastForceCalculation;
        }

        // Zona de atracción normal
        float normalizedDistance = (maxEffectDistance - distance) / (maxEffectDistance - eventHorizonRadius);
        normalizedDistance = Mathf.Clamp01(normalizedDistance);

        // Aplicar curva de atracción
        float forceFactor = Mathf.Pow(normalizedDistance, attractionCurve);
        lastForceCalculation = forceFactor * maxAttractionForce;

        return lastForceCalculation;
    }

    /// <summary>
    /// Calcula el vector completo de fuerza incluyendo dirección y rotación
    /// </summary>
    /// <param name="targetPosition">Posición del objeto afectado</param>
    /// <returns>Vector de fuerza a aplicar</returns>
    public Vector2 CalculateAttractionVector(Vector2 targetPosition)
    {
        Vector2 myPosition = transform.position;
        Vector2 direction = myPosition - targetPosition;
        float distance = direction.magnitude;

        if (distance < 0.001f) // Evitar división por cero
            return Vector2.zero;

        // Normalizar dirección
        direction /= distance;

        // Calcular fuerza base
        float forceMagnitude = CalculateAttractionForce(distance);
        Vector2 attractionForce = direction * forceMagnitude;

        // Añadir componente rotacional si está configurado
        if (rotationalForceMultiplier > 0f && distance > coreRadius)
        {
            // Crear vector perpendicular para rotación
            Vector2 tangent = new Vector2(-direction.y, direction.x);

            // La rotación es más fuerte cerca del horizonte de eventos
            float rotationStrength = 1f - Mathf.Clamp01((distance - eventHorizonRadius) /
                                                        (maxEffectDistance - eventHorizonRadius));

            attractionForce += tangent * (forceMagnitude * rotationalForceMultiplier * rotationStrength);
        }

        return attractionForce;
    }

    /// <summary>
    /// Aplica la fuerza de atracción a un objeto específico
    /// </summary>
    /// <param name="affectedObject">Componente del objeto afectado</param>
    public void ApplyAttractionToObject(AffectedByBlackHole affectedObject)
    {
        if (affectedObject == null || !affectedObject.canBeAffected || !isActive)
            return;

        Vector2 attractionForce = CalculateAttractionVector(affectedObject.transform.position);
        affectedObject.ApplyAttractionForce(attractionForce * Time.fixedDeltaTime);

        // Verificar zonas especiales
        float distance = Vector2.Distance(transform.position, affectedObject.transform.position);

        if (distance <= eventHorizonRadius && !affectedObject.isWithinEventHorizon)
        {
            affectedObject.EnterEventHorizon();
            if (debugMode)
            {
                Debug.Log($"[BlackHole] {affectedObject.name} entró al horizonte de eventos");
            }
        }
        else if (distance > eventHorizonRadius && affectedObject.isWithinEventHorizon)
        {
            affectedObject.ExitEventHorizon();
            if (debugMode)
            {
                Debug.Log($"[BlackHole] {affectedObject.name} salió del horizonte de eventos");
            }
        }
    }

    /// <summary>
    /// Determina en qué zona se encuentra un punto
    /// </summary>
    public enum GravityZone
    {
        Outside,        // Fuera del área de efecto
        Attraction,     // Zona de atracción normal
        EventHorizon,   // Horizonte de eventos
        Core           // Núcleo del agujero negro
    }

    /// <summary>
    /// Obtiene la zona gravitacional de una posición
    /// </summary>
    public GravityZone GetGravityZone(Vector2 position)
    {
        float distance = Vector2.Distance(transform.position, position);

        if (distance <= coreRadius)
            return GravityZone.Core;
        if (distance <= eventHorizonRadius)
            return GravityZone.EventHorizon;
        if (distance <= maxEffectDistance)
            return GravityZone.Attraction;

        return GravityZone.Outside;
    }

    #endregion

    #region Trigger Events

    private void OnTriggerEnter2D(Collider2D other)
    {
        // Verificar si el objeto está en las capas afectadas
        if (((1 << other.gameObject.layer) & affectedLayers) == 0)
            return;

        objectsInRange++;

        if (debugMode)
        {
            Debug.Log($"[BlackHole] {other.name} entró al área de efecto. Total objetos: {objectsInRange}");
        }
    }

    private void OnTriggerExit2D(Collider2D other)
    {
        // Verificar si el objeto está en las capas afectadas
        if (((1 << other.gameObject.layer) & affectedLayers) == 0)
            return;

        objectsInRange = Mathf.Max(0, objectsInRange - 1);

        // Asegurar que se limpie el estado del horizonte de eventos
        var affectedObject = other.GetComponent<AffectedByBlackHole>();
        if (affectedObject != null && affectedObject.isWithinEventHorizon)
        {
            affectedObject.ExitEventHorizon();
        }

        if (debugMode)
        {
            Debug.Log($"[BlackHole] {other.name} salió del área de efecto. Total objetos: {objectsInRange}");
        }
    }

    #endregion

    #region Debug & Visualization

    private void OnDrawGizmos()
    {
        if (!showGizmos) return;

        // Núcleo - Rojo oscuro
        Gizmos.color = new Color(0.5f, 0f, 0f, 0.8f);
        Gizmos.DrawSphere(transform.position, coreRadius);

        // Horizonte de eventos - Naranja
        Gizmos.color = new Color(1f, 0.5f, 0f, 0.5f);
        Gizmos.DrawWireSphere(transform.position, eventHorizonRadius);

        // Área de efecto máximo - Amarillo
        Gizmos.color = new Color(1f, 1f, 0f, 0.3f);
        Gizmos.DrawWireSphere(transform.position, maxEffectDistance);

        // Mostrar información adicional cuando está seleccionado
        if (UnityEditor.Selection.activeGameObject == gameObject)
        {
            DrawDetailedGizmos();
        }
    }

    private void DrawDetailedGizmos()
    {
        // Dibujar anillos de fuerza para visualizar la curva de atracción
        int rings = 10;
        for (int i = 1; i <= rings; i++)
        {
            float distance = Mathf.Lerp(eventHorizonRadius, maxEffectDistance, i / (float)rings);
            float force = CalculateAttractionForce(distance);
            float intensity = force / maxAttractionForce;

            Gizmos.color = new Color(1f - intensity, intensity, 0f, 0.2f);
            Gizmos.DrawWireSphere(transform.position, distance);
        }
    }

    /// <summary>
    /// Obtiene estadísticas del sistema para debug
    /// </summary>
    public string GetDebugInfo()
    {
        return $"BlackHole '{name}'\n" +
               $"Estado: {(isActive ? "Activo" : "Inactivo")}\n" +
               $"Objetos en rango: {objectsInRange}\n" +
               $"Última fuerza calculada: {lastForceCalculation:F2}\n" +
               $"Radios: Core={coreRadius:F1}, Horizon={eventHorizonRadius:F1}, Max={maxEffectDistance:F1}";
    }

    #endregion
}