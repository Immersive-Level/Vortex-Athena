using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Manager centralizado para gestionar la atracción gravitacional de todos los agujeros negros.
/// Optimizado para manejar múltiples agujeros negros y objetos afectables de manera eficiente.
/// </summary>
public class BlackHoleAttractionManager : MonoBehaviour
{
    #region Singleton

    public static BlackHoleAttractionManager Instance { get; private set; }

    #endregion

    #region Inspector Properties

    [Header("⚙️ Configuración")]
    [Space(10)]

    [Tooltip("Usar FixedUpdate para cálculos físicos (recomendado)")]
    [SerializeField]
    private bool useFixedUpdate = true;

    [Tooltip("Optimización: Solo procesar objetos que se han movido")]
    [SerializeField]
    private bool onlyProcessMovingObjects = true;

    [Tooltip("Distancia mínima de movimiento para considerar que un objeto se movió")]
    [SerializeField, Range(0.01f, 1f)]
    private float movementThreshold = 0.1f;

    [Header("📊 Debug")]
    [Space(10)]

    [Tooltip("Mostrar estadísticas del sistema")]
    [SerializeField]
    private bool showDebugInfo = false;

    [Tooltip("Dibujar líneas de atracción en Scene View")]
    [SerializeField]
    private bool drawAttractionLines = false;

    #endregion

    #region Private Variables

    // Listas de objetos activos
    private readonly List<BlackHole> activeBlackHoles = new List<BlackHole>();
    private readonly List<AffectedByBlackHole> activeAffectableObjects = new List<AffectedByBlackHole>();

    // Cache para optimización
    private readonly Dictionary<AffectedByBlackHole, Vector2> lastPositions = new Dictionary<AffectedByBlackHole, Vector2>();
    private readonly Dictionary<AffectedByBlackHole, List<BlackHole>> objectToBlackHoles = new Dictionary<AffectedByBlackHole, List<BlackHole>>();

    // Estadísticas
    private int totalCalculations = 0;
    private float lastUpdateTime = 0f;
    private int skippedCalculations = 0;

    #endregion

    #region Properties

    /// <summary>
    /// Número de agujeros negros activos
    /// </summary>
    public int ActiveBlackHoleCount => activeBlackHoles.Count;

    /// <summary>
    /// Número de objetos afectables activos
    /// </summary>
    public int ActiveAffectableCount => activeAffectableObjects.Count;

    #endregion

    #region Unity Lifecycle

    private void Awake()
    {
        // Configurar singleton
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Debug.LogWarning("[BlackHoleAttractionManager] Ya existe una instancia. Destruyendo duplicado.");
            Destroy(gameObject);
            return;
        }
    }

    private void Start()
    {
        // Buscar objetos iniciales
        RefreshAllObjects();
    }

    private void Update()
    {
        if (!useFixedUpdate)
        {
            ProcessAllAttractions();
        }

        if (showDebugInfo && Time.frameCount % 60 == 0) // Actualizar debug cada segundo
        {
            LogDebugInfo();
        }
    }

    private void FixedUpdate()
    {
        if (useFixedUpdate)
        {
            ProcessAllAttractions();
        }
    }

    private void OnDestroy()
    {
        if (Instance == this)
        {
            Instance = null;
        }
    }

    #endregion

    #region Object Registration

    /// <summary>
    /// Registra un agujero negro en el sistema
    /// </summary>
    public void RegisterBlackHole(BlackHole blackHole)
    {
        if (blackHole == null) return;

        if (!activeBlackHoles.Contains(blackHole))
        {
            activeBlackHoles.Add(blackHole);
            Debug.Log($"[AttractionManager] Agujero negro '{blackHole.name}' registrado. Total: {activeBlackHoles.Count}");
        }
    }

    /// <summary>
    /// Desregistra un agujero negro del sistema
    /// </summary>
    public void UnregisterBlackHole(BlackHole blackHole)
    {
        if (activeBlackHoles.Remove(blackHole))
        {
            // Limpiar cache relacionado
            foreach (var kvp in objectToBlackHoles)
            {
                kvp.Value.Remove(blackHole);
            }

            Debug.Log($"[AttractionManager] Agujero negro '{blackHole.name}' desregistrado. Total: {activeBlackHoles.Count}");
        }
    }

    /// <summary>
    /// Registra un objeto afectable en el sistema
    /// </summary>
    public void RegisterAffectableObject(AffectedByBlackHole affectableObject)
    {
        if (affectableObject == null) return;

        if (!activeAffectableObjects.Contains(affectableObject))
        {
            activeAffectableObjects.Add(affectableObject);
            lastPositions[affectableObject] = affectableObject.transform.position;
            objectToBlackHoles[affectableObject] = new List<BlackHole>();

            if (showDebugInfo)
            {
                Debug.Log($"[AttractionManager] Objeto '{affectableObject.name}' registrado. Total: {activeAffectableObjects.Count}");
            }
        }
    }

    /// <summary>
    /// Desregistra un objeto afectable del sistema
    /// </summary>
    public void UnregisterAffectableObject(AffectedByBlackHole affectableObject)
    {
        if (activeAffectableObjects.Remove(affectableObject))
        {
            // Limpiar cache
            lastPositions.Remove(affectableObject);
            objectToBlackHoles.Remove(affectableObject);

            // Asegurar que sale del horizonte de eventos si estaba dentro
            if (affectableObject.isWithinEventHorizon)
            {
                affectableObject.ExitEventHorizon();
            }

            if (showDebugInfo)
            {
                Debug.Log($"[AttractionManager] Objeto '{affectableObject.name}' desregistrado. Total: {activeAffectableObjects.Count}");
            }
        }
    }

    /// <summary>
    /// Busca y registra todos los objetos en la escena
    /// </summary>
    public void RefreshAllObjects()
    {
        // Limpiar listas actuales
        activeBlackHoles.Clear();
        activeAffectableObjects.Clear();
        lastPositions.Clear();
        objectToBlackHoles.Clear();

        // Buscar agujeros negros
        BlackHole[] foundBlackHoles = FindObjectsByType<BlackHole>(FindObjectsSortMode.None);
        foreach (var bh in foundBlackHoles)
        {
            if (bh.enabled)
            {
                RegisterBlackHole(bh);
            }
        }

        // Buscar objetos afectables
        AffectedByBlackHole[] foundAffectables = FindObjectsByType<AffectedByBlackHole>(FindObjectsSortMode.None);
        foreach (var obj in foundAffectables)
        {
            if (obj.enabled && obj.gameObject.activeInHierarchy)
            {
                RegisterAffectableObject(obj);
            }
        }

        Debug.Log($"[AttractionManager] Sistema actualizado: {activeBlackHoles.Count} agujeros negros, " +
                  $"{activeAffectableObjects.Count} objetos afectables");
    }

    #endregion

    #region Attraction Processing

    /// <summary>
    /// Procesa la atracción de todos los agujeros negros sobre todos los objetos
    /// </summary>
    private void ProcessAllAttractions()
    {
        if (activeBlackHoles.Count == 0 || activeAffectableObjects.Count == 0)
            return;

        float deltaTime = useFixedUpdate ? Time.fixedDeltaTime : Time.deltaTime;
        totalCalculations = 0;
        skippedCalculations = 0;

        // Limpiar mapeo de objetos a agujeros negros
        foreach (var list in objectToBlackHoles.Values)
        {
            list.Clear();
        }

        // Procesar cada objeto afectable
        for (int i = activeAffectableObjects.Count - 1; i >= 0; i--)
        {
            var affectableObject = activeAffectableObjects[i];

            // Validar que el objeto sigue existiendo
            if (affectableObject == null || !affectableObject.gameObject.activeInHierarchy)
            {
                activeAffectableObjects.RemoveAt(i);
                continue;
            }

            // Skip si no puede ser afectado
            if (!affectableObject.canBeAffected)
            {
                skippedCalculations++;
                continue;
            }

            // Optimización: Skip si el objeto no se ha movido significativamente
            if (onlyProcessMovingObjects && HasObjectMoved(affectableObject))
            {
                skippedCalculations++;
                continue;
            }

            ProcessObjectAttraction(affectableObject, deltaTime);
        }

        lastUpdateTime = Time.time;
    }

    /// <summary>
    /// Procesa la atracción de un objeto específico
    /// </summary>
    private void ProcessObjectAttraction(AffectedByBlackHole affectableObject, float deltaTime)
    {
        Vector2 objectPosition = affectableObject.transform.position;
        Vector2 totalForce = Vector2.zero;
        bool isInAnyEventHorizon = false;
        BlackHole strongestBlackHole = null;
        float strongestForce = 0f;

        // Calcular fuerza combinada de todos los agujeros negros
        foreach (var blackHole in activeBlackHoles)
        {
            if (blackHole == null || !blackHole.IsActive)
                continue;

            float distance = Vector2.Distance(blackHole.transform.position, objectPosition);

            // Skip si está fuera del rango
            if (distance > blackHole.MaxEffectDistance)
                continue;

            // Calcular y aplicar fuerza
            Vector2 attractionForce = blackHole.CalculateAttractionVector(objectPosition);
            totalForce += attractionForce;

            float forceMagnitude = attractionForce.magnitude;
            if (forceMagnitude > strongestForce)
            {
                strongestForce = forceMagnitude;
                strongestBlackHole = blackHole;
            }

            // Verificar horizonte de eventos
            if (distance <= blackHole.EventHorizonRadius)
            {
                isInAnyEventHorizon = true;
            }

            objectToBlackHoles[affectableObject].Add(blackHole);
            totalCalculations++;

            // Debug visual
            if (drawAttractionLines && attractionForce.magnitude > 0.01f)
            {
                Debug.DrawLine(objectPosition, blackHole.transform.position,
                              Color.Lerp(Color.yellow, Color.red, forceMagnitude / blackHole.MaxEffectDistance));
            }
        }

        // Aplicar la fuerza total
        if (totalForce.magnitude > 0.001f)
        {
            affectableObject.ApplyAttractionForce(totalForce * deltaTime);
        }

        // Gestionar estado del horizonte de eventos
        if (isInAnyEventHorizon && !affectableObject.isWithinEventHorizon)
        {
            affectableObject.EnterEventHorizon();
        }
        else if (!isInAnyEventHorizon && affectableObject.isWithinEventHorizon)
        {
            affectableObject.ExitEventHorizon();
        }

        // Actualizar última posición
        lastPositions[affectableObject] = objectPosition;
    }

    /// <summary>
    /// Verifica si un objeto se ha movido significativamente
    /// </summary>
    private bool HasObjectMoved(AffectedByBlackHole affectableObject)
    {
        if (!lastPositions.TryGetValue(affectableObject, out Vector2 lastPos))
            return true; // Si no hay registro previo, procesar

        float distance = Vector2.Distance(lastPos, affectableObject.transform.position);
        return distance > movementThreshold;
    }

    #endregion

    #region Utility Methods

    /// <summary>
    /// Obtiene los agujeros negros que están afectando a un objeto específico
    /// </summary>
    public List<BlackHole> GetAffectingBlackHoles(AffectedByBlackHole affectableObject)
    {
        if (objectToBlackHoles.TryGetValue(affectableObject, out List<BlackHole> blackHoles))
        {
            return new List<BlackHole>(blackHoles); // Retornar copia
        }
        return new List<BlackHole>();
    }

    /// <summary>
    /// Obtiene el agujero negro más cercano a una posición
    /// </summary>
    public BlackHole GetNearestBlackHole(Vector2 position)
    {
        BlackHole nearest = null;
        float nearestDistance = float.MaxValue;

        foreach (var blackHole in activeBlackHoles)
        {
            if (blackHole == null || !blackHole.IsActive)
                continue;

            float distance = Vector2.Distance(blackHole.transform.position, position);
            if (distance < nearestDistance)
            {
                nearestDistance = distance;
                nearest = blackHole;
            }
        }

        return nearest;
    }

    /// <summary>
    /// Verifica si una posición está dentro de algún horizonte de eventos
    /// </summary>
    public bool IsPositionInEventHorizon(Vector2 position)
    {
        foreach (var blackHole in activeBlackHoles)
        {
            if (blackHole == null || !blackHole.IsActive)
                continue;

            float distance = Vector2.Distance(blackHole.transform.position, position);
            if (distance <= blackHole.EventHorizonRadius)
                return true;
        }

        return false;
    }

    #endregion

    #region Debug

    private void LogDebugInfo()
    {
        string info = "=== BlackHole Attraction Manager ===\n";
        info += $"Agujeros Negros Activos: {activeBlackHoles.Count}\n";
        info += $"Objetos Afectables: {activeAffectableObjects.Count}\n";
        info += $"Cálculos por Frame: {totalCalculations}\n";
        info += $"Cálculos Omitidos: {skippedCalculations}\n";
        info += $"Eficiencia: {(skippedCalculations / (float)(totalCalculations + skippedCalculations) * 100f):F1}%\n";
        info += $"Última Actualización: {Time.time - lastUpdateTime:F3}s atrás";

        Debug.Log(info);
    }

    private void OnDrawGizmos()
    {
        if (!showDebugInfo || !Application.isPlaying)
            return;

        // Dibujar conexiones entre objetos y agujeros negros
        foreach (var kvp in objectToBlackHoles)
        {
            if (kvp.Key == null) continue;

            Vector3 objPos = kvp.Key.transform.position;

            foreach (var blackHole in kvp.Value)
            {
                if (blackHole == null) continue;

                Gizmos.color = new Color(1f, 0.5f, 0f, 0.3f);
                Gizmos.DrawLine(objPos, blackHole.transform.position);
            }
        }
    }

    #endregion
}