using UnityEngine;
using UnityEditor;

/// <summary>
/// Herramienta para configurar automáticamente el sistema de agujeros negros
/// y migrar desde el sistema antiguo al refactorizado.
/// </summary>
public class BlackHoleSystemSetup : MonoBehaviour
{
#if UNITY_EDITOR

    [MenuItem("Tools/Black Hole System/Setup Manager")]
    public static void SetupBlackHoleManager()
    {
        // Buscar si ya existe un manager
        BlackHoleAttractionManager existingManager = FindObjectOfType<BlackHoleAttractionManager>();

        if (existingManager != null)
        {
            Debug.Log("[Setup] Manager ya existe en la escena");
            Selection.activeGameObject = existingManager.gameObject;
            return;
        }

        // Crear nuevo manager
        GameObject managerGO = new GameObject("BlackHoleAttractionManager");
        BlackHoleAttractionManager manager = managerGO.AddComponent<BlackHoleAttractionManager>();

        // Configuración recomendada
        SerializedObject serializedManager = new SerializedObject(manager);
        serializedManager.FindProperty("useFixedUpdate").boolValue = true;
        serializedManager.FindProperty("onlyProcessMovingObjects").boolValue = true;
        serializedManager.FindProperty("movementThreshold").floatValue = 0.1f;
        serializedManager.ApplyModifiedProperties();

        Debug.Log("[Setup] BlackHoleAttractionManager creado exitosamente");
        Selection.activeGameObject = managerGO;

        // Buscar y actualizar agujeros negros existentes
        UpdateExistingBlackHoles();
    }

    [MenuItem("Tools/Black Hole System/Create Black Hole")]
    public static void CreateBlackHole()
    {
        // Crear GameObject
        GameObject blackHoleGO = new GameObject("BlackHole");

        // Posicionar en el centro de la vista de la escena
        SceneView sceneView = SceneView.lastActiveSceneView;
        if (sceneView != null)
        {
            blackHoleGO.transform.position = sceneView.pivot;
        }

        // Agregar componentes necesarios
        BlackHole blackHole = blackHoleGO.AddComponent<BlackHole>();
        BlackHoleResourceAbsorber absorber = blackHoleGO.AddComponent<BlackHoleResourceAbsorber>();

        // Configuración inicial recomendada
        SerializedObject serializedBH = new SerializedObject(blackHole);
        serializedBH.FindProperty("coreRadius").floatValue = 2f;
        serializedBH.FindProperty("eventHorizonRadius").floatValue = 5f;
        serializedBH.FindProperty("maxEffectDistance").floatValue = 30f;
        serializedBH.FindProperty("maxAttractionForce").floatValue = 50f;
        serializedBH.FindProperty("attractionCurve").floatValue = 2f;
        serializedBH.FindProperty("rotationalForceMultiplier").floatValue = 0.5f;
        serializedBH.ApplyModifiedProperties();

        // Configurar absorber
        SerializedObject serializedAbsorber = new SerializedObject(absorber);
        serializedAbsorber.FindProperty("useCoreRadiusForAbsorption").boolValue = true;
        serializedAbsorber.FindProperty("absorptionDelay").floatValue = 0.1f;
        serializedAbsorber.ApplyModifiedProperties();

        Debug.Log("[Setup] Agujero negro creado exitosamente");
        Selection.activeGameObject = blackHoleGO;
    }

    [MenuItem("Tools/Black Hole System/Add Debugger")]
    public static void AddDebugger()
    {
        // Verificar si ya existe
        BlackHoleDebugger existingDebugger = FindObjectOfType<BlackHoleDebugger>();
        if (existingDebugger != null)
        {
            Debug.LogWarning("[Setup] Ya existe un BlackHoleDebugger en la escena");
            Selection.activeGameObject = existingDebugger.gameObject;
            return;
        }

        // Crear debugger
        GameObject debuggerGO = new GameObject("BlackHoleDebugger");
        BlackHoleDebugger debugger = debuggerGO.AddComponent<BlackHoleDebugger>();

        Debug.Log("[Setup] BlackHoleDebugger agregado a la escena");
        Selection.activeGameObject = debuggerGO;
    }

    [MenuItem("Tools/Black Hole System/Migrate from Old System")]
    public static void MigrateFromOldSystem()
    {
        int migratedCount = 0;

        // Buscar todos los GameObjects con componentes del sistema antiguo
        GameObject[] allObjects = FindObjectsOfType<GameObject>();

        foreach (GameObject obj in allObjects)
        {
            bool migrated = false;

            // Si tiene el componente BlackHole antiguo
            Component oldBlackHole = obj.GetComponent("BlackHole");
            if (oldBlackHole != null)
            {
                MigrateBlackHole(obj, oldBlackHole);
                migrated = true;
                migratedCount++;
            }

            // Si tiene el componente AffectedByBlackHole antiguo
            Component oldAffected = obj.GetComponent("AffectedByBlackHole");
            if (oldAffected != null && !migrated)
            {
                // El componente AffectedByBlackHole es compatible
                Debug.Log($"[Migration] '{obj.name}' ya tiene AffectedByBlackHole compatible");
            }
        }

        if (migratedCount > 0)
        {
            Debug.Log($"[Migration] Migración completada. {migratedCount} objetos actualizados.");

            // Crear manager si no existe
            SetupBlackHoleManager();
        }
        else
        {
            Debug.Log("[Migration] No se encontraron objetos para migrar.");
        }
    }

    private static void MigrateBlackHole(GameObject obj, Component oldComponent)
    {
        Debug.Log($"[Migration] Migrando BlackHole en '{obj.name}'");

        // Remover componentes visuales/UI si existen
        UnityEngine.UI.Image image = obj.GetComponent<UnityEngine.UI.Image>();
        if (image != null)
        {
            Debug.Log($"[Migration] Removiendo componente Image de '{obj.name}'");
            DestroyImmediate(image);
        }

        // Remover Canvas Renderer si existe
        CanvasRenderer canvasRenderer = obj.GetComponent<CanvasRenderer>();
        if (canvasRenderer != null)
        {
            Debug.Log($"[Migration] Removiendo CanvasRenderer de '{obj.name}'");
            DestroyImmediate(canvasRenderer);
        }

        // El componente BlackHole debería ser compatible, solo necesita limpieza
        BlackHole blackHole = obj.GetComponent<BlackHole>();
        if (blackHole != null)
        {
            // Resetear referencias visuales mediante reflexión si es necesario
            SerializedObject serializedBH = new SerializedObject(blackHole);

            // Limpiar propiedades visuales que ya no se usan
            var imageProperty = serializedBH.FindProperty("blackHoleImage");
            if (imageProperty != null)
            {
                imageProperty.objectReferenceValue = null;
            }

            serializedBH.ApplyModifiedProperties();
            Debug.Log($"[Migration] BlackHole en '{obj.name}' limpiado de referencias visuales");
        }

        // Agregar ResourceAbsorber si no existe
        if (obj.GetComponent<BlackHoleResourceAbsorber>() == null)
        {
            obj.AddComponent<BlackHoleResourceAbsorber>();
            Debug.Log($"[Migration] BlackHoleResourceAbsorber agregado a '{obj.name}'");
        }
    }

    private static void UpdateExistingBlackHoles()
    {
        BlackHole[] blackHoles = FindObjectsOfType<BlackHole>();
        foreach (var bh in blackHoles)
        {
            // Asegurar que tengan el ResourceAbsorber
            if (bh.GetComponent<BlackHoleResourceAbsorber>() == null)
            {
                bh.gameObject.AddComponent<BlackHoleResourceAbsorber>();
                Debug.Log($"[Setup] ResourceAbsorber agregado a '{bh.name}'");
            }
        }

        Debug.Log($"[Setup] {blackHoles.Length} agujeros negros actualizados");
    }

    [MenuItem("Tools/Black Hole System/Validate Setup")]
    public static void ValidateSetup()
    {
        Debug.Log("=== VALIDACIÓN DEL SISTEMA DE AGUJEROS NEGROS ===");

        bool isValid = true;

        // Verificar Manager
        BlackHoleAttractionManager manager = FindObjectOfType<BlackHoleAttractionManager>();
        if (manager == null)
        {
            Debug.LogError("[Validation] ❌ No se encontró BlackHoleAttractionManager");
            isValid = false;
        }
        else
        {
            Debug.Log("[Validation] ✓ BlackHoleAttractionManager encontrado");
        }

        // Verificar Black Holes
        BlackHole[] blackHoles = FindObjectsOfType<BlackHole>();
        if (blackHoles.Length == 0)
        {
            Debug.LogWarning("[Validation] ⚠ No se encontraron agujeros negros en la escena");
        }
        else
        {
            Debug.Log($"[Validation] ✓ {blackHoles.Length} agujeros negros encontrados");

            // Verificar configuración de cada agujero negro
            foreach (var bh in blackHoles)
            {
                // Verificar que no estén en UI
                if (bh.GetComponentInParent<Canvas>() != null)
                {
                    Debug.LogWarning($"[Validation] ⚠ '{bh.name}' está dentro de un Canvas UI");
                }

                // Verificar ResourceAbsorber
                if (bh.GetComponent<BlackHoleResourceAbsorber>() == null)
                {
                    Debug.LogWarning($"[Validation] ⚠ '{bh.name}' no tiene BlackHoleResourceAbsorber");
                }

                // Verificar CircleCollider2D
                if (bh.GetComponent<CircleCollider2D>() == null)
                {
                    Debug.LogError($"[Validation] ❌ '{bh.name}' no tiene CircleCollider2D");
                    isValid = false;
                }
            }
        }

        // Verificar objetos afectables
        AffectedByBlackHole[] affectables = FindObjectsOfType<AffectedByBlackHole>();
        Debug.Log($"[Validation] ℹ {affectables.Length} objetos afectables encontrados");

        foreach (var obj in affectables)
        {
            if (obj.GetComponent<Rigidbody2D>() == null)
            {
                Debug.LogWarning($"[Validation] ⚠ '{obj.name}' no tiene Rigidbody2D");
            }
        }

        // Resultado final
        if (isValid)
        {
            Debug.Log("[Validation] ✅ Sistema validado correctamente");
        }
        else
        {
            Debug.LogError("[Validation] ❌ El sistema tiene errores que deben corregirse");
        }
    }

    [MenuItem("Tools/Black Hole System/Create Test Scene")]
    public static void CreateTestScene()
    {
        // Crear manager
        SetupBlackHoleManager();

        // Crear un agujero negro
        CreateBlackHole();

        // Crear objetos de prueba
        for (int i = 0; i < 5; i++)
        {
            GameObject testObj = GameObject.CreatePrimitive(PrimitiveType.Sphere);
            testObj.name = $"TestObject_{i}";

            // Posicionar aleatoriamente
            float angle = i * (360f / 5f) * Mathf.Deg2Rad;
            testObj.transform.position = new Vector3(
                Mathf.Cos(angle) * 15f,
                Mathf.Sin(angle) * 15f,
                0
            );

            // Escalar
            testObj.transform.localScale = Vector3.one * 0.5f;

            // Agregar componentes físicos
            Rigidbody2D rb = testObj.AddComponent<Rigidbody2D>();
            rb.gravityScale = 0; // Sin gravedad normal

            // Agregar AffectedByBlackHole
            AffectedByBlackHole affected = testObj.AddComponent<AffectedByBlackHole>();

            // Agregar CollectibleResource
            CollectibleResource resource = testObj.AddComponent<CollectibleResource>();
            //resource.SetResourceData(
            //    (CollectibleResource.ResourceType)(i % 4),
            //    Random.Range(10, 50)
            //);
        }

        // Agregar debugger
        AddDebugger();

        Debug.Log("[Setup] Escena de prueba creada exitosamente");
    }

#endif
}

/// <summary>
/// Inspector personalizado para el componente ReadOnly
/// </summary>
#if UNITY_EDITOR
[CustomPropertyDrawer(typeof(AffectedByBlackHole.ReadOnlyAttribute))]
[CustomPropertyDrawer(typeof(BlackHoleResourceAbsorber.ReadOnlyAttribute))]
//[CustomPropertyDrawer(typeof(CollectibleResource.ReadOnlyAttribute))]
public class ReadOnlyDrawer : PropertyDrawer
{
    public override void OnGUI(Rect position, SerializedProperty property, GUIContent label)
    {
        GUI.enabled = false;
        EditorGUI.PropertyField(position, property, label, true);
        GUI.enabled = true;
    }
}
#endif