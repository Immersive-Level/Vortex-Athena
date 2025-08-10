using UnityEngine;
using UnityEngine.UI;
using System;

namespace GameSystems
{
    /// <summary>
    /// Sistema de combustible refactorizado - Simple, robusto y modular
    /// Solo maneja la lógica del combustible, no UI ni muerte
    /// </summary>
    public class FuelManager : MonoBehaviour
    {
        [Header("Configuración")]
        [SerializeField] private float maxFuel = 100f;
        [SerializeField] private float startingFuel = 100f;
        [SerializeField] private float consumptionRate = 10f; // Por segundo
        [SerializeField] private bool autoRefuel = true; // ¿Se recarga automáticamente?
        [SerializeField] private float autoRefuelRate = 1f; // Por segundo
        [SerializeField] private float autoRefuelDelay = 1f; // Delay antes de empezar a recargar

        [Header("UI Reference")]
        [SerializeField] private Image fuelBarImage; // Barra de combustible UI

        [Header("Debug")]
        [SerializeField] private bool debugMode = false;

        // Estado interno
        private float currentFuel;
        private float timeSinceLastConsumption = 0f;
        private bool isConsuming = false;

        // Eventos
        public event Action OnFuelEmpty;
        public event Action OnFuelRestored; // Cuando vuelve a tener combustible
        public event Action<float> OnFuelChanged; // Envía el porcentaje actual

        // Propiedades públicas
        public bool HasFuel => currentFuel > 0f;
        public float CurrentFuel => currentFuel;
        public float MaxFuel => maxFuel;
        public float FuelPercentage => currentFuel / maxFuel;

        private void Awake()
        {
            // Validación inicial
            if (maxFuel <= 0)
            {
                Debug.LogError("[FuelManager] maxFuel debe ser mayor a 0!");
                maxFuel = 100f;
            }

            // Inicializar combustible
            currentFuel = Mathf.Clamp(startingFuel, 0, maxFuel);
        }

        private void Start()
        {
            UpdateUI();

            if (debugMode)
                Debug.Log($"[FuelManager] Inicializado con {currentFuel}/{maxFuel} fuel");
        }

        private void Update()
        {
            // Auto-recarga si está habilitada
            if (autoRefuel && !isConsuming)
            {
                timeSinceLastConsumption += Time.deltaTime;

                if (timeSinceLastConsumption >= autoRefuelDelay)
                {
                    AddFuel(autoRefuelRate * Time.deltaTime);
                }
            }

            // Consumo activo
            if (isConsuming && HasFuel)
            {
                ConsumeFuel(consumptionRate * Time.deltaTime);
            }
        }

        /// <summary>
        /// Inicia el consumo continuo de combustible
        /// </summary>
        public void StartConsuming()
        {
            if (!HasFuel) return;

            isConsuming = true;
            timeSinceLastConsumption = 0f;

            if (debugMode)
                Debug.Log("[FuelManager] Consumo iniciado");
        }

        /// <summary>
        /// Detiene el consumo de combustible
        /// </summary>
        public void StopConsuming()
        {
            isConsuming = false;

            if (debugMode)
                Debug.Log("[FuelManager] Consumo detenido");
        }

        /// <summary>
        /// Consume una cantidad específica de combustible
        /// </summary>
        private void ConsumeFuel(float amount)
        {
            if (amount <= 0) return;

            float previousFuel = currentFuel;
            currentFuel = Mathf.Max(0, currentFuel - amount);

            if (currentFuel != previousFuel)
            {
                UpdateUI();
                OnFuelChanged?.Invoke(FuelPercentage);

                // Verificar si se agotó el combustible
                if (currentFuel <= 0 && previousFuel > 0)
                {
                    HandleFuelEmpty();
                }
            }
        }

        /// <summary>
        /// Añade combustible al tanque
        /// </summary>
        public void AddFuel(float amount)
        {
            if (amount <= 0) return;

            float previousFuel = currentFuel;
            bool wasEmpty = !HasFuel;

            currentFuel = Mathf.Min(maxFuel, currentFuel + amount);

            if (currentFuel != previousFuel)
            {
                UpdateUI();
                OnFuelChanged?.Invoke(FuelPercentage);

                // Si estaba vacío y ahora tiene combustible
                if (wasEmpty && HasFuel)
                {
                    OnFuelRestored?.Invoke();

                    if (debugMode)
                        Debug.Log("[FuelManager] Combustible restaurado");
                }
            }
        }

        /// <summary>
        /// Establece el combustible a un valor específico
        /// </summary>
        public void SetFuel(float amount)
        {
            float previousFuel = currentFuel;
            bool wasEmpty = !HasFuel;

            currentFuel = Mathf.Clamp(amount, 0, maxFuel);

            UpdateUI();
            OnFuelChanged?.Invoke(FuelPercentage);

            // Verificar cambios de estado
            if (currentFuel <= 0 && previousFuel > 0)
            {
                HandleFuelEmpty();
            }
            else if (wasEmpty && HasFuel)
            {
                OnFuelRestored?.Invoke();
            }
        }

        /// <summary>
        /// Rellena el tanque completamente
        /// </summary>
        public void RefillTank()
        {
            SetFuel(maxFuel);

            if (debugMode)
                Debug.Log("[FuelManager] Tanque rellenado completamente");
        }

        /// <summary>
        /// Vacía el tanque completamente
        /// </summary>
        public void EmptyTank()
        {
            SetFuel(0);

            if (debugMode)
                Debug.Log("[FuelManager] Tanque vaciado");
        }

        /// <summary>
        /// Maneja el evento de tanque vacío
        /// </summary>
        private void HandleFuelEmpty()
        {
            isConsuming = false;
            OnFuelEmpty?.Invoke();

            if (debugMode)
                Debug.Log("[FuelManager] ¡Combustible agotado!");
        }

        /// <summary>
        /// Actualiza la UI de la barra de combustible
        /// </summary>
        private void UpdateUI()
        {
            if (fuelBarImage != null)
            {
                // Asegurar que el fillAmount siempre refleje el estado real
                float targetFill = FuelPercentage;
                fuelBarImage.fillAmount = targetFill;

                if (debugMode && Mathf.Abs(fuelBarImage.fillAmount - targetFill) > 0.01f)
                {
                    Debug.LogWarning($"[FuelManager] Discrepancia en UI: fillAmount={fuelBarImage.fillAmount}, target={targetFill}");
                }
            }
        }

        /// <summary>
        /// Reinicia el sistema de combustible
        /// </summary>
        public void ResetFuelSystem()
        {
            currentFuel = startingFuel;
            isConsuming = false;
            timeSinceLastConsumption = 0f;
            UpdateUI();

            if (debugMode)
                Debug.Log("[FuelManager] Sistema reiniciado");
        }

        private void OnValidate()
        {
            // Validación en el editor
            maxFuel = Mathf.Max(1f, maxFuel);
            startingFuel = Mathf.Clamp(startingFuel, 0, maxFuel);
            consumptionRate = Mathf.Max(0, consumptionRate);
            autoRefuelRate = Mathf.Max(0, autoRefuelRate);
            autoRefuelDelay = Mathf.Max(0, autoRefuelDelay);
        }

        private void OnDestroy()
        {
            // Limpiar eventos
            OnFuelEmpty = null;
            OnFuelRestored = null;
            OnFuelChanged = null;
        }

#if UNITY_EDITOR
        [ContextMenu("Test: Add 25 Fuel")]
        private void TestAdd25Fuel() => AddFuel(25f);

        [ContextMenu("Test: Remove 25 Fuel")]
        private void TestRemove25Fuel() => ConsumeFuel(25f);

        [ContextMenu("Test: Empty Tank")]
        private void TestEmptyTank() => EmptyTank();

        [ContextMenu("Test: Refill Tank")]
        private void TestRefillTank() => RefillTank();
#endif
    }
}