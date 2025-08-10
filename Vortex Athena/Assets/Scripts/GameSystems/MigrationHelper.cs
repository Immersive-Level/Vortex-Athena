using UnityEngine;
using UnityEngine.UI;
#if UNITY_EDITOR
using UnityEditor;
#endif

namespace GameSystems
{
    /// <summary>
    /// Helper para migrar del sistema antiguo al nuevo
    /// Este script ayuda a la transición automática
    /// </summary>
    public class MigrationHelper : MonoBehaviour
    {
        [Header("Migración Automática")]
        [SerializeField] private bool autoMigrate = false;

        [Header("Referencias Antiguas")]
        [SerializeField] private Fuel_System oldFuelSystem;
        [SerializeField] private Boton oldBoton;
        [SerializeField] private BlackHoleDeathHandler oldDeathHandler;

        [Header("Referencias Nuevas")]
        [SerializeField] private FuelManager newFuelManager;
        [SerializeField] private ShipInputController newInputController;
        [SerializeField] private UnifiedDeathManager newDeathManager;

        [Header("Estado de Migración")]
        [SerializeField] private bool migrationComplete = false;

#if UNITY_EDITOR
        /// <summary>
        /// Migra los valores del sistema antiguo al nuevo
        /// </summary>
        [ContextMenu("Ejecutar Migración")]
        public void ExecuteMigration()
        {
            if (migrationComplete)
            {
                Debug.LogWarning("[Migration] La migración ya fue completada!");
                return;
            }

            Debug.Log("[Migration] Iniciando migración...");

            // 1. Buscar componentes antiguos si no están asignados
            FindOldComponents();

            // 2. Crear nuevos componentes si no existen
            CreateNewComponents();

            // 3. Migrar configuración
            MigrateConfiguration();

            // 4. Conectar referencias
            ConnectReferences();

            // 5. Desactivar componentes antiguos
            DisableOldComponents();

            migrationComplete = true;
            EditorUtility.SetDirty(gameObject);

            Debug.Log("[Migration] ¡Migración completada! Revisa la configuración y elimina los componentes antiguos cuando estés listo.");
        }

        /// <summary>
        /// Busca componentes antiguos en el GameObject
        /// </summary>
        private void FindOldComponents()
        {
            if (oldFuelSystem == null)
                oldFuelSystem = GetComponent<Fuel_System>();

            if (oldBoton == null)
                oldBoton = GetComponentInChildren<Boton>();

            if (oldDeathHandler == null)
                oldDeathHandler = GetComponent<BlackHoleDeathHandler>();

            Debug.Log($"[Migration] Componentes antiguos encontrados: Fuel={oldFuelSystem != null}, Boton={oldBoton != null}, Death={oldDeathHandler != null}");
        }

        /// <summary>
        /// Crea los nuevos componentes si no existen
        /// </summary>
        private void CreateNewComponents()
        {
            // Crear FuelManager
            if (newFuelManager == null)
            {
                newFuelManager = gameObject.GetComponent<FuelManager>();
                if (newFuelManager == null)
                {
                    newFuelManager = gameObject.AddComponent<FuelManager>();
                    Debug.Log("[Migration] FuelManager creado");
                }
            }

            // Crear UnifiedDeathManager
            if (newDeathManager == null)
            {
                newDeathManager = gameObject.GetComponent<UnifiedDeathManager>();
                if (newDeathManager == null)
                {
                    newDeathManager = gameObject.AddComponent<UnifiedDeathManager>();
                    Debug.Log("[Migration] UnifiedDeathManager creado");
                }
            }

            // Crear ShipInputController en el botón
            if (newInputController == null && oldBoton != null)
            {
                GameObject buttonObject = oldBoton.gameObject;
                newInputController = buttonObject.GetComponent<ShipInputController>();
                if (newInputController == null)
                {
                    newInputController = buttonObject.AddComponent<ShipInputController>();
                    Debug.Log("[Migration] ShipInputController creado en el botón");
                }
            }
        }

        /// <summary>
        /// Migra la configuración del sistema antiguo al nuevo
        /// </summary>
        private void MigrateConfiguration()
        {
            // Migrar configuración de Fuel_System a FuelManager
            if (oldFuelSystem != null && newFuelManager != null)
            {
                // Usar reflection para acceder a campos privados con SerializeField
                var fuelManagerType = typeof(FuelManager);

                // maxFuel
                var maxFuelField = fuelManagerType.GetField("maxFuel", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                if (maxFuelField != null)
                    maxFuelField.SetValue(newFuelManager, oldFuelSystem.maxFuel);

                // consumptionRate
                var consumptionField = fuelManagerType.GetField("consumptionRate", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                if (consumptionField != null)
                    consumptionField.SetValue(newFuelManager, oldFuelSystem.fuelConsumptionRate);

                // fuelBarImage
                var fuelBarField = fuelManagerType.GetField("fuelBarImage", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                if (fuelBarField != null)
                    fuelBarField.SetValue(newFuelManager, oldFuelSystem.lineFuel);

                Debug.Log("[Migration] Configuración de combustible migrada");
            }

            // Migrar configuración de Boton a ShipInputController
            if (oldBoton != null && newInputController != null)
            {
                var inputType = typeof(ShipInputController);

                // tapThreshold
                var tapField = inputType.GetField("tapThreshold", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                if (tapField != null)
                    tapField.SetValue(newInputController, oldBoton.tapThreshold);

                // Referencias
                var fuelField = inputType.GetField("fuelManager", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                if (fuelField != null)
                    fuelField.SetValue(newInputController, newFuelManager);

                var shipField = inputType.GetField("shipController", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                if (shipField != null)
                    shipField.SetValue(newInputController, oldBoton.shipController);

                Debug.Log("[Migration] Configuración de input migrada");
            }

            // Migrar configuración de BlackHoleDeathHandler a UnifiedDeathManager
            if (oldDeathHandler != null && newDeathManager != null)
            {
                var deathType = typeof(UnifiedDeathManager);

                // respawnPoint
                var respawnField = deathType.GetField("respawnPoint", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                if (respawnField != null && oldDeathHandler.respawnPoint != null)
                    respawnField.SetValue(newDeathManager, oldDeathHandler.respawnPoint);

                // shipVisual
                var visualField = deathType.GetField("shipVisual", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                if (visualField != null && oldDeathHandler.shipVisual != null)
                    visualField.SetValue(newDeathManager, oldDeathHandler.shipVisual);

                // UI
                var uiField = deathType.GetField("respawnUI", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                if (uiField != null && oldDeathHandler.countdownUI != null)
                    uiField.SetValue(newDeathManager, oldDeathHandler.countdownUI);

                var textField = deathType.GetField("respawnText", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                if (textField != null && oldDeathHandler.countdownText != null)
                    textField.SetValue(newDeathManager, oldDeathHandler.countdownText);

                Debug.Log("[Migration] Configuración de muerte/respawn migrada");
            }

            EditorUtility.SetDirty(gameObject);
        }

        /// <summary>
        /// Conecta las referencias entre los nuevos componentes
        /// </summary>
        private void ConnectReferences()
        {
            // Conectar referencias cruzadas
            if (newDeathManager != null)
            {
                var deathType = typeof(UnifiedDeathManager);

                var fuelField = deathType.GetField("fuelManager", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                if (fuelField != null)
                    fuelField.SetValue(newDeathManager, newFuelManager);

                var inputField = deathType.GetField("inputController", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                if (inputField != null)
                    inputField.SetValue(newDeathManager, newInputController);

                // Buscar ShipController
                var shipController = GetComponent<ShipController>();
                if (shipController != null)
                {
                    var shipField = deathType.GetField("shipController", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                    if (shipField != null)
                        shipField.SetValue(newDeathManager, shipController);
                }

                // Buscar ShipInvulnerability
                var invulnerability = GetComponent<ShipInvulnerability>();
                if (invulnerability != null)
                {
                    var invField = deathType.GetField("invulnerability", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                    if (invField != null)
                        invField.SetValue(newDeathManager, invulnerability);
                }

                // Buscar Rigidbody2D
                var rb = GetComponent<Rigidbody2D>();
                if (rb != null)
                {
                    var rbField = deathType.GetField("shipRigidbody", System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Instance);
                    if (rbField != null)
                        rbField.SetValue(newDeathManager, rb);
                }
            }

            Debug.Log("[Migration] Referencias conectadas");
            EditorUtility.SetDirty(gameObject);
        }

        /// <summary>
        /// Desactiva los componentes antiguos
        /// </summary>
        private void DisableOldComponents()
        {
            if (oldFuelSystem != null)
            {
                oldFuelSystem.enabled = false;
                Debug.Log("[Migration] Fuel_System desactivado");
            }

            if (oldBoton != null)
            {
                oldBoton.enabled = false;
                Debug.Log("[Migration] Boton desactivado");
            }

            if (oldDeathHandler != null)
            {
                oldDeathHandler.enabled = false;
                Debug.Log("[Migration] BlackHoleDeathHandler desactivado");
            }

            EditorUtility.SetDirty(gameObject);
        }

        /// <summary>
        /// Remueve los componentes antiguos (usar con precaución)
        /// </summary>
        [ContextMenu("Remover Componentes Antiguos")]
        public void RemoveOldComponents()
        {
            if (!migrationComplete)
            {
                Debug.LogError("[Migration] Ejecuta la migración primero!");
                return;
            }

            if (EditorUtility.DisplayDialog("Confirmar Eliminación",
                "¿Estás seguro de eliminar los componentes antiguos?\n\nEsta acción no se puede deshacer.",
                "Eliminar", "Cancelar"))
            {
                if (oldFuelSystem != null)
                    DestroyImmediate(oldFuelSystem);

                if (oldBoton != null)
                    DestroyImmediate(oldBoton);

                if (oldDeathHandler != null)
                    DestroyImmediate(oldDeathHandler);

                // Eliminar este helper también
                DestroyImmediate(this);

                Debug.Log("[Migration] Componentes antiguos eliminados");
            }
        }
#endif
    }
}