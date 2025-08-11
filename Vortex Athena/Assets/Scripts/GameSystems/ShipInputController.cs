using UnityEngine;
using UnityEngine.EventSystems;
using System;

namespace GameSystems
{
    /// <summary>
    /// Controlador de input para la nave - Reemplaza Boton.cs
    /// Simple y robusto, maneja el input del jugador
    /// FIXED: El botón NUNCA se oculta, solo cambia su comportamiento
    /// </summary>
    public class ShipInputController : MonoBehaviour, IPointerDownHandler, IPointerUpHandler
    {
        [Header("Referencias")]
        [SerializeField] private FuelManager fuelManager;
        [SerializeField] private ShipController shipController;

        [Header("Configuración Tap")]
        [SerializeField] private float tapThreshold = 0.15f; // Tiempo máximo para considerar "tap"
        [SerializeField] private bool tapNudgeEnabled = true;

        [Header("Estado Visual")]
        [SerializeField] private Animator buttonAnimator; // Opcional: animación del botón

        [Header("Debug")]
        [SerializeField] private bool debugMode = false;

        // Estado interno
        private bool isPressing = false;
        private bool canPress = true;
        private float pressStartTime = 0f;
        private bool isRespawning = false;

        // Eventos
        public event Action OnButtonPressed;
        public event Action OnButtonReleased;
        public event Action OnTapDetected;

        private void Awake()
        {
            ValidateReferences();
        }

        private void Start()
        {
            // Suscribirse a eventos del sistema de combustible
            if (fuelManager != null)
            {
                fuelManager.OnFuelEmpty += HandleFuelEmpty;
                fuelManager.OnFuelRestored += HandleFuelRestored;
            }

            UpdateButtonState();
        }

        private void OnEnable()
        {
            // Limpiar estado al activarse
            ResetInputState();
        }

        /// <summary>
        /// Método público para el botón - Iniciar press
        /// </summary>
        public void OnButtonPress()
        {
            OnPointerDown(null);
        }

        /// <summary>
        /// Método público para el botón - Finalizar press
        /// </summary>
        public void OnButtonRelease()
        {
            OnPointerUp(null);
        }

        /// <summary>
        /// Maneja el inicio del press (PointerDown)
        /// </summary>
        public void OnPointerDown(PointerEventData eventData)
        {
            if (!canPress || !fuelManager.HasFuel)
            {
                if (debugMode)
                    Debug.Log($"[ShipInput] Press ignorado - CanPress:{canPress}, HasFuel:{fuelManager.HasFuel}");
                return;
            }

            isPressing = true;
            pressStartTime = Time.time;

            // Iniciar movimiento y consumo
            shipController.StartMoving();
            fuelManager.StartConsuming();

            OnButtonPressed?.Invoke();
            UpdateButtonAnimation("Pressed");

            if (debugMode)
                Debug.Log("[ShipInput] Botón presionado - Iniciando movimiento");
        }

        /// <summary>
        /// Maneja el fin del press (PointerUp)
        /// </summary>
        public void OnPointerUp(PointerEventData eventData)
        {
            if (!isPressing) return;

            isPressing = false;

            // Detener movimiento y consumo
            shipController.StopMoving();
            fuelManager.StopConsuming();

            // Verificar si fue un tap
            float pressDuration = Time.time - pressStartTime;
            if (pressDuration <= tapThreshold && tapNudgeEnabled)
            {
                shipController.TapNudge();
                OnTapDetected?.Invoke();

                if (debugMode)
                    Debug.Log($"[ShipInput] Tap detectado ({pressDuration:F2}s)");
            }

            OnButtonReleased?.Invoke();
            UpdateButtonAnimation(canPress ? "Ready" : "Disabled");
        }

        /// <summary>
        /// Maneja cuando se agota el combustible
        /// </summary>
        private void HandleFuelEmpty()
        {
            canPress = false;

            // Forzar release si está presionando
            if (isPressing)
            {
                OnPointerUp(null);
            }

            UpdateButtonState();

            if (debugMode)
                Debug.Log("[ShipInput] Combustible agotado - Botón deshabilitado");
        }

        /// <summary>
        /// Maneja cuando se restaura el combustible
        /// </summary>
        private void HandleFuelRestored()
        {
            if (!isRespawning) // Solo rehabilitar si no estamos en proceso de respawn
            {
                canPress = true;
                UpdateButtonState();

                if (debugMode)
                    Debug.Log("[ShipInput] Combustible restaurado - Botón habilitado");
            }
        }

        /// <summary>
        /// Habilita el botón para respawn manual
        /// </summary>
        public void EnableForRespawn()
        {
            isRespawning = true;
            canPress = true;
            UpdateButtonAnimation("RespawnReady");

            if (debugMode)
                Debug.Log("[ShipInput] Botón habilitado para respawn");
        }

        /// <summary>
        /// Ejecuta el respawn cuando se presiona el botón
        /// </summary>
        public void ExecuteRespawn()
        {
            if (!isRespawning) return;

            isRespawning = false;

            // El DeathManager se encargará del respawn real
            // Este método solo notifica que el botón fue presionado

            if (debugMode)
                Debug.Log("[ShipInput] Respawn ejecutado");
        }

        /// <summary>
        /// Actualiza el estado visual del botón
        /// </summary>
        private void UpdateButtonState()
        {
            bool isEnabled = canPress && fuelManager.HasFuel;

            // Actualizar visual del botón (cambiar alpha, color, etc.)
            var canvasGroup = GetComponent<CanvasGroup>();
            if (canvasGroup != null)
            {
                canvasGroup.alpha = isEnabled ? 1f : 0.5f;
                canvasGroup.interactable = isEnabled;
            }

            UpdateButtonAnimation(isEnabled ? "Ready" : "Disabled");
        }

        /// <summary>
        /// Actualiza la animación del botón
        /// </summary>
        private void UpdateButtonAnimation(string stateName)
        {
            if (buttonAnimator != null)
            {
                buttonAnimator.SetTrigger(stateName);
            }
        }

        /// <summary>
        /// Reinicia el estado del input
        /// </summary>
        public void ResetInputState()
        {
            isPressing = false;
            canPress = fuelManager.HasFuel;
            isRespawning = false;
            pressStartTime = 0f;

            UpdateButtonState();

            if (debugMode)
                Debug.Log("[ShipInput] Estado reiniciado");
        }

        /// <summary>
        /// Valida que todas las referencias estén configuradas
        /// </summary>
        private void ValidateReferences()
        {
            if (fuelManager == null)
            {
                fuelManager = GetComponentInParent<FuelManager>();
                if (fuelManager == null)
                    Debug.LogError("[ShipInput] FuelManager no encontrado!");
            }

            if (shipController == null)
            {
                shipController = GetComponentInParent<ShipController>();
                if (shipController == null)
                    Debug.LogError("[ShipInput] ShipController no encontrado!");
            }
        }

        private void OnDestroy()
        {
            // Desuscribirse de eventos
            if (fuelManager != null)
            {
                fuelManager.OnFuelEmpty -= HandleFuelEmpty;
                fuelManager.OnFuelRestored -= HandleFuelRestored;
            }
        }

#if UNITY_EDITOR
        private void OnValidate()
        {
            tapThreshold = Mathf.Max(0.01f, tapThreshold);
        }
#endif
    }
}