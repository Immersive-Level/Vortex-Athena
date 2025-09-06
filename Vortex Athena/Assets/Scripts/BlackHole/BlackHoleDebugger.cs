using UnityEngine;
using System.Text;

/// <summary>
/// Herramienta de debugging para el sistema de agujeros negros.
/// Proporciona visualización en tiempo real y controles de prueba.
/// </summary>
public class BlackHoleDebugger : MonoBehaviour
{
    #region Inspector Properties

    [Header("⚙️ Configuración de Debug")]
    [Space(10)]

    [Tooltip("Tecla para activar/desactivar el debug overlay")]
    [SerializeField]
    private KeyCode toggleDebugKey = KeyCode.F1;

    [Tooltip("Mostrar overlay de debug en pantalla")]
    [SerializeField]
    private bool showDebugOverlay = true;

    [Tooltip("Mostrar líneas de fuerza en Scene View")]
    [SerializeField]
    private bool showForceLines = true;

    [Tooltip("Mostrar zonas de gravedad con colores")]
    [SerializeField]
    private bool showGravityZones = true;

    [Header("🎨 Colores de Visualización")]
    [Space(10)]

    [SerializeField] private Color coreZoneColor = new Color(1f, 0f, 0f, 0.5f);
    [SerializeField] private Color eventHorizonColor = new Color(1f, 0.5f, 0f, 0.4f);
    [SerializeField] private Color attractionZoneColor = new Color(1f, 1f, 0f, 0.3f);
    [SerializeField] private Color forceLineColor = Color.yellow;

    [Header("📊 Configuración de Overlay")]
    [Space(10)]

    [Tooltip("Posición del overlay en pantalla")]
    [SerializeField]
    private TextAnchor overlayPosition = TextAnchor.UpperLeft;

    [Tooltip("Tamaño de fuente del overlay")]
    [SerializeField, Range(10, 20)]
    private int fontSize = 12;

    [Tooltip("Color de fondo del overlay")]
    [SerializeField]
    private Color backgroundColor = new Color(0, 0, 0, 0.7f);

    [Header("🧪 Herramientas de Prueba")]
    [Space(10)]

    [Tooltip("Prefab de objeto de prueba para spawn")]
    [SerializeField]
    private GameObject testObjectPrefab;

    [Tooltip("Tecla para spawnear objeto de prueba")]
    [SerializeField]
    private KeyCode spawnTestObjectKey = KeyCode.F2;

    [Tooltip("Distancia de spawn desde el agujero negro")]
    [SerializeField, Range(5f, 30f)]
    private float spawnDistance = 15f;

    #endregion

    #region Private Variables

    private BlackHoleAttractionManager attractionManager;
    private BlackHole[] allBlackHoles;
    private AffectedByBlackHole[] allAffectableObjects;

    private GUIStyle overlayStyle;
    private GUIStyle backgroundStyle;
    private StringBuilder debugText = new StringBuilder();

    private float updateInterval = 0.5f;
    private float lastUpdateTime = 0f;
    private float currentFPS = 0f;
    private int frameCount = 0;

    #endregion

    #region Unity Lifecycle

    private void Start()
    {
        InitializeDebugger();
    }

    private void Update()
    {
        // Toggle debug overlay
        if (Input.GetKeyDown(toggleDebugKey))
        {
            showDebugOverlay = !showDebugOverlay;
        }

        // Spawn test object
        if (Input.GetKeyDown(spawnTestObjectKey) && testObjectPrefab != null)
        {
            SpawnTestObject();
        }

        // Update FPS counter
        UpdateFPSCounter();

        // Update references periodically
        if (Time.time - lastUpdateTime > updateInterval)
        {
            UpdateReferences();
            lastUpdateTime = Time.time;
        }

        // Draw debug visualizations
        if (showForceLines || showGravityZones)
        {
            DrawDebugVisualization();
        }
    }

    private void OnGUI()
    {
        if (!showDebugOverlay) return;

        DrawDebugOverlay();
    }

    #endregion

    #region Initialization

    private void InitializeDebugger()
    {
        // Get reference to manager
        attractionManager = BlackHoleAttractionManager.Instance;

        if (attractionManager == null)
        {
            Debug.LogWarning("[BlackHoleDebugger] No se encontró BlackHoleAttractionManager");
        }

        // Initialize GUI styles
        InitializeGUIStyles();

        // Initial reference update
        UpdateReferences();
    }

    private void InitializeGUIStyles()
    {
        overlayStyle = new GUIStyle();
        overlayStyle.normal.textColor = Color.white;
        overlayStyle.fontSize = fontSize;
        overlayStyle.padding = new RectOffset(10, 10, 10, 10);

        backgroundStyle = new GUIStyle();
        backgroundStyle.normal.background = MakeColorTexture(backgroundColor);
    }

    private Texture2D MakeColorTexture(Color color)
    {
        Texture2D texture = new Texture2D(1, 1);
        texture.SetPixel(0, 0, color);
        texture.Apply();
        return texture;
    }

    #endregion

    #region Reference Management

    private void UpdateReferences()
    {
        allBlackHoles = FindObjectsByType<BlackHole>(FindObjectsSortMode.None);
        allAffectableObjects = FindObjectsByType<AffectedByBlackHole>(FindObjectsSortMode.None);
    }

    #endregion

    #region Debug Overlay

    private void DrawDebugOverlay()
    {
        // Build debug text
        BuildDebugText();

        // Calculate position
        Vector2 position = GetOverlayPosition();

        // Calculate size
        GUIContent content = new GUIContent(debugText.ToString());
        Vector2 size = overlayStyle.CalcSize(content);
        size.x += 20;
        size.y += 20;

        // Draw background
        Rect backgroundRect = new Rect(position.x, position.y, size.x, size.y);
        GUI.Box(backgroundRect, "", backgroundStyle);

        // Draw text
        Rect textRect = new Rect(position.x + 10, position.y + 10, size.x - 20, size.y - 20);
        GUI.Label(textRect, content, overlayStyle);
    }

    private void BuildDebugText()
    {
        debugText.Clear();
        debugText.AppendLine("=== BLACK HOLE SYSTEM DEBUG ===");
        debugText.AppendLine($"FPS: {currentFPS:F1}");
        debugText.AppendLine();

        // Manager info
        if (attractionManager != null)
        {
            debugText.AppendLine("【 Attraction Manager 】");
            debugText.AppendLine($"  Active Black Holes: {attractionManager.ActiveBlackHoleCount}");
            debugText.AppendLine($"  Affectable Objects: {attractionManager.ActiveAffectableCount}");
            debugText.AppendLine();
        }

        // Black holes info
        if (allBlackHoles != null && allBlackHoles.Length > 0)
        {
            debugText.AppendLine("【 Black Holes 】");
            foreach (var bh in allBlackHoles)
            {
                if (bh == null) continue;

                debugText.AppendLine($"  ▸ {bh.name}:");
                debugText.AppendLine($"    Status: {(bh.IsActive ? "ACTIVE" : "INACTIVE")}");
                debugText.AppendLine($"    Core/Horizon/Max: {bh.CoreRadius:F1}/{bh.EventHorizonRadius:F1}/{bh.MaxEffectDistance:F1}");

                // Check for absorber
                var absorber = bh.GetComponent<BlackHoleResourceAbsorber>();
                if (absorber != null)
                {
                    debugText.AppendLine($"    Resources Absorbed: {absorber.TotalResourcesAbsorbed}");
                    debugText.AppendLine($"    Resources in Range: {absorber.ResourcesInRange}");
                }
            }
            debugText.AppendLine();
        }

        // Affected objects info
        int objectsInEventHorizon = 0;
        int activeObjects = 0;

        if (allAffectableObjects != null)
        {
            foreach (var obj in allAffectableObjects)
            {
                if (obj == null) continue;

                if (obj.canBeAffected) activeObjects++;
                if (obj.isWithinEventHorizon) objectsInEventHorizon++;
            }

            debugText.AppendLine("【 Affected Objects 】");
            debugText.AppendLine($"  Total: {allAffectableObjects.Length}");
            debugText.AppendLine($"  Active: {activeObjects}");
            debugText.AppendLine($"  In Event Horizon: {objectsInEventHorizon}");
        }

        debugText.AppendLine();
        debugText.AppendLine($"Press {toggleDebugKey} to toggle overlay");
        if (testObjectPrefab != null)
        {
            debugText.AppendLine($"Press {spawnTestObjectKey} to spawn test object");
        }
    }

    private Vector2 GetOverlayPosition()
    {
        float margin = 20f;
        float width = Screen.width;
        float height = Screen.height;

        switch (overlayPosition)
        {
            case TextAnchor.UpperLeft:
                return new Vector2(margin, margin);
            case TextAnchor.UpperCenter:
                return new Vector2(width / 2 - 150, margin);
            case TextAnchor.UpperRight:
                return new Vector2(width - 350 - margin, margin);
            case TextAnchor.MiddleLeft:
                return new Vector2(margin, height / 2 - 100);
            case TextAnchor.MiddleCenter:
                return new Vector2(width / 2 - 150, height / 2 - 100);
            case TextAnchor.MiddleRight:
                return new Vector2(width - 350 - margin, height / 2 - 100);
            case TextAnchor.LowerLeft:
                return new Vector2(margin, height - 250 - margin);
            case TextAnchor.LowerCenter:
                return new Vector2(width / 2 - 150, height - 250 - margin);
            case TextAnchor.LowerRight:
                return new Vector2(width - 350 - margin, height - 250 - margin);
            default:
                return new Vector2(margin, margin);
        }
    }

    #endregion

    #region Debug Visualization

    private void DrawDebugVisualization()
    {
        if (allBlackHoles == null) return;

        foreach (var blackHole in allBlackHoles)
        {
            if (blackHole == null || !blackHole.IsActive) continue;

            Vector3 bhPosition = blackHole.transform.position;

            // Draw gravity zones
            if (showGravityZones)
            {
                // Core zone
                DrawCircle(bhPosition, blackHole.CoreRadius, coreZoneColor, 20);

                // Event horizon
                DrawCircle(bhPosition, blackHole.EventHorizonRadius, eventHorizonColor, 30);

                // Attraction zone
                DrawCircle(bhPosition, blackHole.MaxEffectDistance, attractionZoneColor, 40);
            }

            // Draw force lines
            if (showForceLines && allAffectableObjects != null)
            {
                foreach (var obj in allAffectableObjects)
                {
                    if (obj == null || !obj.canBeAffected) continue;

                    Vector3 objPosition = obj.transform.position;
                    float distance = Vector3.Distance(bhPosition, objPosition);

                    if (distance <= blackHole.MaxEffectDistance)
                    {
                        float force = blackHole.CalculateAttractionForce(distance);
                        float normalizedForce = force / 100f; // Normalize for visualization

                        Color lineColor = Color.Lerp(Color.green, Color.red, normalizedForce);
                        Debug.DrawLine(objPosition, bhPosition, lineColor);

                        // Draw force magnitude indicator
                        Vector3 midPoint = (objPosition + bhPosition) / 2;
                        Debug.DrawRay(midPoint, Vector3.up * normalizedForce * 2, lineColor);
                    }
                }
            }
        }
    }

    private void DrawCircle(Vector3 center, float radius, Color color, int segments)
    {
        float angleStep = 360f / segments;
        Vector3 prevPoint = center + new Vector3(radius, 0, 0);

        for (int i = 1; i <= segments; i++)
        {
            float angle = i * angleStep * Mathf.Deg2Rad;
            Vector3 newPoint = center + new Vector3(Mathf.Cos(angle) * radius, Mathf.Sin(angle) * radius, 0);
            Debug.DrawLine(prevPoint, newPoint, color);
            prevPoint = newPoint;
        }
    }

    #endregion

    #region Test Tools

    private void SpawnTestObject()
    {
        if (testObjectPrefab == null)
        {
            Debug.LogWarning("[BlackHoleDebugger] No hay prefab de prueba asignado");
            return;
        }

        // Find nearest black hole
        BlackHole nearestBH = null;
        float nearestDistance = float.MaxValue;

        foreach (var bh in allBlackHoles)
        {
            if (bh == null) continue;

            float dist = Vector3.Distance(Camera.main.transform.position, bh.transform.position);
            if (dist < nearestDistance)
            {
                nearestDistance = dist;
                nearestBH = bh;
            }
        }

        if (nearestBH == null)
        {
            Debug.LogWarning("[BlackHoleDebugger] No hay agujeros negros en la escena");
            return;
        }

        // Calculate spawn position
        float angle = Random.Range(0, 360) * Mathf.Deg2Rad;
        Vector3 spawnPos = nearestBH.transform.position +
                          new Vector3(Mathf.Cos(angle), Mathf.Sin(angle), 0) * spawnDistance;

        // Spawn object
        GameObject testObj = Instantiate(testObjectPrefab, spawnPos, Quaternion.identity);
        testObj.name = $"TestObject_{System.DateTime.Now:HHmmss}";

        // Ensure it has AffectedByBlackHole component
        if (testObj.GetComponent<AffectedByBlackHole>() == null)
        {
            testObj.AddComponent<AffectedByBlackHole>();
        }

        Debug.Log($"[BlackHoleDebugger] Objeto de prueba spawneado en {spawnPos}");
    }

    #endregion

    #region Utilities

    private void UpdateFPSCounter()
    {
        frameCount++;
        float timeElapsed = Time.time - lastUpdateTime;

        if (timeElapsed >= updateInterval)
        {
            currentFPS = frameCount / timeElapsed;
            frameCount = 0;
        }
    }

    #endregion
}