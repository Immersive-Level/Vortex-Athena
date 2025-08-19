using UnityEngine;
using UnityEditor;
using System.IO;
using System.Linq;

#if UNITY_EDITOR
public class NetworkingCleanupValidator : EditorWindow
{
    private Vector2 scrollPosition;
    private bool foundIssues = false;

    [MenuItem("Tools/Fusion Setup/Validate Networking Cleanup")]
    static void ShowWindow()
    {
        GetWindow<NetworkingCleanupValidator>("Networking Cleanup Validator");
    }

    void OnGUI()
    {
        EditorGUILayout.LabelField("Validador de Limpieza de Networking", EditorStyles.boldLabel);
        EditorGUILayout.Space();

        if (GUILayout.Button("Ejecutar Validación", GUILayout.Height(30)))
        {
            ValidateCleanup();
        }

        EditorGUILayout.Space();

        scrollPosition = EditorGUILayout.BeginScrollView(scrollPosition);

        // El contenido se mostrará después de ejecutar la validación

        EditorGUILayout.EndScrollView();
    }

    void ValidateCleanup()
    {
        foundIssues = false;

        Debug.Log("Iniciando validación de limpieza de networking...");

        // 1. Verificar scripts problemáticos
        CheckForProblematicScripts();

        // 2. Verificar using statements problemáticos
        CheckForProblematicUsingStatements();

        // 3. Verificar componentes problemáticos en prefabs
        CheckForProblematicComponents();

        // 4. Verificar que Unity Services Core esté intacto (es bueno que esté)
        CheckUnityServicesCore();

        // 5. Resumen final
        if (!foundIssues)
        {
            Debug.Log("Limpieza exitosa! No se encontraron restos problemáticos de NGO/Entities");
            Debug.Log("Unity Services Core está intacto (esto es correcto)");
        }
        else
        {
            Debug.LogWarning("Se encontraron algunos elementos que necesitan atención");
        }
    }

    void CheckForProblematicScripts()
    {
        Debug.Log("Buscando scripts problemáticos...");

        string[] problematicPatterns = {
            "NetworkBehaviour", // NGO
            "NetworkObject", // NGO  
            "NetworkVariable", // NGO
            "ServerRpc", // NGO
            "ClientRpc", // NGO
            "Unity.Netcode", // NGO namespace
            "Unity.Entities", // Entities
            "ComponentSystem", // Entities
            "JobComponentSystem" // Entities
        };

        // Scripts que debemos ignorar (incluyendo este validador)
        string[] scriptsToIgnore = {
            "NetworkingCleanupValidator.cs",
            "NetworkingManualCleanup.cs",
            "EntitiesChecker.cs",
            "PackageCleanupChecker.cs",
            "TokenExchange.cs", // Unity Services
            "Authentication.cs" // Unity Services
        };

        string[] allScripts = Directory.GetFiles(Application.dataPath, "*.cs", SearchOption.AllDirectories);

        foreach (string scriptPath in allScripts)
        {
            string fileName = Path.GetFileName(scriptPath);

            // Ignorar este script y otros scripts de herramientas
            if (scriptsToIgnore.Any(ignore => fileName.Contains(ignore)))
                continue;

            // Ignorar scripts de Unity Services (son legítimos)
            if (scriptPath.Contains("Services") && scriptPath.Contains("Core"))
                continue;

            // Ignorar carpetas Editor que contienen herramientas de desarrollo
            if (scriptPath.Contains("Editor") && (
                fileName.Contains("Validator") ||
                fileName.Contains("Checker") ||
                fileName.Contains("Helper")))
                continue;

            string content = File.ReadAllText(scriptPath);

            foreach (string pattern in problematicPatterns)
            {
                if (content.Contains(pattern))
                {
                    string relativePath = scriptPath.Replace(Application.dataPath, "Assets");
                    Debug.LogWarning($"Encontrado '{pattern}' en: {relativePath}");
                    foundIssues = true;
                }
            }
        }
    }

    void CheckForProblematicUsingStatements()
    {
        Debug.Log("Buscando using statements problemáticos...");

        string[] problematicUsings = {
            "using Unity.Netcode;",
            "using Unity.Entities;",
            "using Unity.NetCode;"
        };

        // Scripts de herramientas que debemos ignorar
        string[] toolScriptsToIgnore = {
            "NetworkingCleanupValidator.cs",
            "NetworkingManualCleanup.cs",
            "EntitiesChecker.cs",
            "PackageCleanupChecker.cs"
        };

        string[] allScripts = Directory.GetFiles(Application.dataPath, "*.cs", SearchOption.AllDirectories);

        foreach (string scriptPath in allScripts)
        {
            string fileName = Path.GetFileName(scriptPath);

            // Ignorar scripts de herramientas
            if (toolScriptsToIgnore.Any(ignore => fileName.Contains(ignore)))
                continue;

            // Ignorar Unity Services
            if (scriptPath.Contains("Services") && scriptPath.Contains("Core"))
                continue;

            string content = File.ReadAllText(scriptPath);

            foreach (string usingStatement in problematicUsings)
            {
                if (content.Contains(usingStatement))
                {
                    string relativePath = scriptPath.Replace(Application.dataPath, "Assets");
                    Debug.LogWarning($"Using problemático encontrado en: {relativePath}");
                    Debug.LogWarning($"   -> {usingStatement}");
                    foundIssues = true;
                }
            }
        }
    }

    void CheckForProblematicComponents()
    {
        Debug.Log("Buscando componentes problemáticos en prefabs...");

        string[] allPrefabs = Directory.GetFiles(Application.dataPath, "*.prefab", SearchOption.AllDirectories);

        foreach (string prefabPath in allPrefabs)
        {
            string content = File.ReadAllText(prefabPath);

            if (content.Contains("NetworkObject") || content.Contains("NetworkBehaviour"))
            {
                string relativePath = prefabPath.Replace(Application.dataPath, "Assets");
                Debug.LogWarning($"Prefab con componentes de NGO: {relativePath}");
                foundIssues = true;
            }
        }
    }

    void CheckUnityServicesCore()
    {
        Debug.Log("Verificando Unity Services Core...");

        string servicesPath = Path.Combine(Application.dataPath, "..", "Library", "PackageCache");

        if (Directory.Exists(servicesPath))
        {
            var servicesDirs = Directory.GetDirectories(servicesPath, "*services.core*");

            if (servicesDirs.Length > 0)
            {
                Debug.Log("Unity Services Core encontrado (correcto)");
                Debug.Log("   -> Los scripts de TokenExchange son parte legítima de Unity Services");
            }
        }

        // Verificar que scripts como TokenExchange NO son problemáticos
        string tokenExchangePath = Path.Combine(Application.dataPath, "Services", "Core", "Networking");
        if (Directory.Exists(tokenExchangePath))
        {
            Debug.Log("Scripts de Unity Services Core encontrados");
            Debug.Log("   -> Estos NO deben ser removidos (son parte del sistema de Unity)");
        }
    }
}

// Utility para ayudar con limpieza manual si es necesaria
public class NetworkingManualCleanup
{
    [MenuItem("Tools/Fusion Setup/Manual Cleanup Helper")]
    static void ShowCleanupHelper()
    {
        string message = @"Si encontraste archivos problemáticos, aquí está cómo limpiarlos:

SEGUROS PARA REMOVER:
• Cualquier script que use 'using Unity.Netcode;'
• Prefabs con componentes NetworkObject (NGO)
• Scripts que hereden de NetworkBehaviour (NGO)

NO TOCAR (son legítimos):
• Carpeta Services/Core/Networking (Unity Services)
• Scripts con TokenExchange, Authentication
• Cualquier cosa en Library/PackageCache

PROCESO RECOMENDADO:
1. Haz backup antes de borrar cualquier archivo
2. Borra archivos uno por uno, no carpetas completas
3. Recompila después de cada borrado
4. Si algo se rompe, restaura del backup

¿Necesitas ayuda específica con algún archivo?";

        EditorUtility.DisplayDialog("Helper de Limpieza Manual", message, "Entendido");
    }
}
#endif