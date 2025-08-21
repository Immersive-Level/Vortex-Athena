using UnityEngine;
using UnityEngine.EventSystems;
using System;
using System.Collections;

namespace GameSystems
{
    /// <summary>
    /// Controlador de input para la nave - Reemplaza Boton.cs
    /// FIXED: Auto-gestiona su estado visual, NUNCA se oculta
    /// </summary>
    public class ShipInputController : MonoBehaviour, IPointerDownHandler, IPointerUpHandler
    {
        public enum ButtonState
        {
            Inactive,       // Antes de iniciar (alpha 0.5)
            Playing,        // Jugando normal (alpha 1.0)
            // NoFuel,         // Sin combustible (alpha 0.5) - COMENTADO: No se usa muerte por combustible
            Dead,           // Muerto, esperando (alpha 0.3)
            RespawnReady    // Listo para respawn (alpha 1.0, puede parpadear)
        }

        [Header("Referencias")]
        [SerializeField] private FuelManager fuelManager;
        [SerializeField] private ShipController shipController;
        [SerializeField] private UnifiedDeathManager deathManager;

        [Header("Configuración Tap")]
        [SerializeField] private float tapThreshold = 0.15f;
        [SerializeField] private bool tapNudgeEnabled = true;

        [Header("Visual del Botón")]
        [SerializeField] private float inactiveAlpha = 0.5f;
        [SerializeField] private float deadAlpha = 1f;
        // [SerializeField] private float noFuelAlpha = 0.5f; // COMENTADO: No se usa estado NoFuel
        [SerializeField] private bool blinkOnRespawnReady = true;
        [SerializeField] private float blinkSpeed = 2f;

        [SerializeField] private FuelButtonRespawnFX respawnFx;

        [Header("Debug")]
        [SerializeField] private bool debugMode = false;
        [SerializeField] private ButtonState currentButtonState = ButtonState.Inactive;

        // Estado interno
        private bool isPressing = false;
        private bool canPress = true;
        private float pressStartTime = 0f;
        private bool isRespawning = false;
        private CanvasGroup canvasGroup;
        private Coroutine blinkCoroutine;
        private bool gameStarted = false;

        // Eventos
        public event Action OnButtonPressed;
        public event Action OnButtonReleased;
        public event Action OnTapDetected;

        private void Awake()
        {
            // Obtener o crear CanvasGroup
            canvasGroup = GetComponent<CanvasGroup>();
            if (canvasGroup == null)
            {
                canvasGroup = gameObject.AddComponent<CanvasGroup>();
            }

            // IMPORTANTE: El botón SIEMPRE está activo
            gameObject.SetActive(true);

            ValidateReferences();
        }

        private void Start()
        {
            // Estado inicial: Inactivo
            SetButtonState(ButtonState.Inactive);

            // COMENTADO: Suscripciones a eventos de combustible ya no necesarias para muerte
            /*
            // Suscribirse a eventos del sistema de combustible
            if (fuelManager != null)
            {
                fuelManager.OnFuelEmpty += HandleFuelEmpty;
                fuelManager.OnFuelRestored += HandleFuelRestored;
            }
            */

            // Suscribirse a eventos del sistema de muerte
            if (deathManager != null)
            {
                deathManager.OnDeath += HandleDeath;
                deathManager.OnRespawn += HandleRespawn;
                deathManager.OnRespawnReady += HandleRespawnReady;
            }

            // Detectar cuando el juego inicia
            var inicioNave = GetComponentInParent<InicioNave>();
            if (inicioNave != null)
            {
                // Podríamos suscribirnos a un evento si existiera
                StartCoroutine(CheckGameStarted(inicioNave));
            }
        }

        private IEnumerator CheckGameStarted(InicioNave inicioNave)
        {
            while (!gameStarted)
            {
                if (inicioNave.JuegoIniciado)
                {
                    gameStarted = true;
                    SetButtonState(ButtonState.Playing);
                }
                yield return new WaitForSeconds(0.1f);
            }
        }

        private void OnEnable()
        {
            // Asegurar que el botón siempre esté visible
            if (canvasGroup != null)
            {
                canvasGroup.blocksRaycasts = true;
            }
        }

        /// <summary>
        /// Cambia el estado visual del botón
        /// </summary>
        public void SetButtonState(ButtonState newState)
        {
            if (currentButtonState == newState) return;

            currentButtonState = newState;

            // Detener parpadeo si existe
            if (blinkCoroutine != null)
            {
                StopCoroutine(blinkCoroutine);
                blinkCoroutine = null;
            }

            switch (newState)
            {
                case ButtonState.Inactive:
                    respawnFx?.FuelButtonRespawnFXHide();
                    canvasGroup.alpha = inactiveAlpha;
                    canvasGroup.interactable = false;
                    canPress = false;
                    break;

                case ButtonState.Playing:
                    respawnFx?.FuelButtonRespawnFXHide();
                    canvasGroup.alpha = 1f;
                    canvasGroup.interactable = true;
                    canPress = true;
                    break;

                // COMENTADO: Estado NoFuel ya no se usa
                /*
                case ButtonState.NoFuel:
                    canvasGroup.alpha = noFuelAlpha;
                    canvasGroup.interactable = false;
                    canPress = false;
                    break;
                */

                case ButtonState.Dead:
                    canvasGroup.alpha = deadAlpha;
                    respawnFx?.Show();
                    canvasGroup.interactable = false;
                    canPress = false;
                    isRespawning = false;
                    break;

                case ButtonState.RespawnReady:
                    respawnFx?.FuelButtonRespawnFXHide();
                    canvasGroup.interactable = true;
                    canPress = true;
                    isRespawning = true;

                    if (blinkOnRespawnReady)
                    {
                        blinkCoroutine = StartCoroutine(BlinkEffect());
                    }
                    else
                    {
                        canvasGroup.alpha = 1f;
                    }
                    break;
            }

            if (debugMode)
                Debug.Log($"[ShipInput] Estado del botón: {newState}");
        }

        /// <summary>
        /// Efecto de parpadeo para respawn ready
        /// </summary>
        private IEnumerator BlinkEffect()
        {
            while (currentButtonState == ButtonState.RespawnReady)
            {
                float alpha = Mathf.PingPong(Time.time * blinkSpeed, 1f);
                alpha = Mathf.Lerp(0.5f, 1f, alpha); // Parpadeo entre 0.5 y 1
                canvasGroup.alpha = alpha;
                yield return null;
            }
        }

        /// <summary>
        /// Maneja el inicio del press (PointerDown)
        /// </summary>
        public void OnPointerDown(PointerEventData eventData)
        {
            // Si estamos esperando respawn, ejecutar respawn
            if (isRespawning && currentButtonState == ButtonState.RespawnReady)
            {
                ExecuteRespawn();
                return;
            }

            // Si el juego no ha iniciado, iniciar
            if (!gameStarted)
            {
                var inicioNave = GetComponentInParent<InicioNave>();
                if (inicioNave != null && !inicioNave.JuegoIniciado)
                {
                    // Este press iniciará el juego a través del PlayerInputManager
                    // No hacemos nada más aquí
                    return;
                }
            }

            // SIMPLIFICADO: Solo verificar si se puede presionar (sin verificar combustible para muerte)
            if (!canPress)
            {
                if (debugMode)
                    Debug.Log($"[ShipInput] Press ignorado - CanPress:{canPress}, State:{currentButtonState}");
                return;
            }

            // NOTA: Verificamos combustible solo para evitar movimiento, NO para muerte
            if (!fuelManager.HasFuel)
            {
                if (debugMode)
                    Debug.Log($"[ShipInput] Press ignorado - Sin combustible (pero no causa muerte)");
                return;
            }

            isPressing = true;
            pressStartTime = Time.time;

            // Iniciar movimiento y consumo
            shipController.StartMoving();
            fuelManager.StartConsuming();

            OnButtonPressed?.Invoke();

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
        }

        // COMENTADO: Métodos de manejo de combustible ya no necesarios para muerte
        /*
        /// <summary>
        /// Maneja cuando se agota el combustible
        /// </summary>
        private void HandleFuelEmpty()
        {
            if (currentButtonState == ButtonState.Playing)
            {
                SetButtonState(ButtonState.NoFuel);

                // Forzar release si está presionando
                if (isPressing)
                {
                    OnPointerUp(null);
                }
            }
        }

        /// <summary>
        /// Maneja cuando se restaura el combustible
        /// </summary>
        private void HandleFuelRestored()
        {
            if (currentButtonState == ButtonState.NoFuel && !deathManager.IsDead)
            {
                SetButtonState(ButtonState.Playing);
            }
        }
        */

        /// <summary>
        /// Maneja cuando el jugador muere
        /// </summary>
        private void HandleDeath(UnifiedDeathManager.DeathType deathType)
        {
            SetButtonState(ButtonState.Dead);

            // Forzar release si está presionando
            if (isPressing)
            {
                OnPointerUp(null);
            }

            if (debugMode)
                Debug.Log($"[ShipInput] Jugador murió por {deathType}");
        }

        /// <summary>
        /// Maneja cuando el respawn está listo
        /// </summary>
        private void HandleRespawnReady()
        {
            SetButtonState(ButtonState.RespawnReady);

            if (debugMode)
                Debug.Log("[ShipInput] Respawn listo - Presiona el botón");
        }

        /// <summary>
        /// Maneja cuando el jugador respawnea
        /// </summary>
        private void HandleRespawn()
        {
            // Volver al estado de juego
            SetButtonState(ButtonState.Playing);
            isRespawning = false;

            if (debugMode)
                Debug.Log("[ShipInput] Jugador respawneado");
        }

        /// <summary>
        /// Habilita el botón para respawn manual
        /// </summary>
        public void EnableForRespawn()
        {
            SetButtonState(ButtonState.RespawnReady);
        }

        /// <summary>
        /// Ejecuta el respawn cuando se presiona el botón
        /// </summary>
        public void ExecuteRespawn()
        {
            if (!isRespawning || currentButtonState != ButtonState.RespawnReady) return;

            isRespawning = false;

            // Cambiar estado visual inmediatamente
            SetButtonState(ButtonState.Dead);

            // Notificar al UnifiedDeathManager que ejecute el respawn
            if (deathManager != null)
            {
                deathManager.OnRespawnButtonPressed();
            }

            if (debugMode)
                Debug.Log("[ShipInput] Respawn ejecutado");
        }

        /// <summary>
        /// Reinicia el estado del input
        /// </summary>
        public void ResetInputState()
        {
            isPressing = false;
            isRespawning = false;
            pressStartTime = 0f;

            // Determinar el estado apropiado (SIN considerar NoFuel)
            if (!gameStarted)
            {
                SetButtonState(ButtonState.Inactive);
            }
            else if (deathManager != null && deathManager.IsDead)
            {
                SetButtonState(ButtonState.Dead);
            }
            // COMENTADO: Ya no verificamos estado sin combustible para muerte
            /*
            else if (fuelManager != null && !fuelManager.HasFuel)
            {
                SetButtonState(ButtonState.NoFuel);
            }
            */
            else
            {
                SetButtonState(ButtonState.Playing);
            }

            if (debugMode)
                Debug.Log("[ShipInput] Estado reiniciado");
        }

        /// <summary>
        /// Llamado cuando el juego inicia (desde InicioNave)
        /// </summary>
        public void OnGameStarted()
        {
            gameStarted = true;
            SetButtonState(ButtonState.Playing);
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

            if (deathManager == null)
            {
                deathManager = GetComponentInParent<UnifiedDeathManager>();
                if (deathManager == null)
                    Debug.LogWarning("[ShipInput] UnifiedDeathManager no encontrado");
            }
        }

        private void OnDestroy()
        {
            // COMENTADO: Desuscripciones de eventos de combustible ya no necesarias
            /*
            // Desuscribirse de eventos
            if (fuelManager != null)
            {
                fuelManager.OnFuelEmpty -= HandleFuelEmpty;
                fuelManager.OnFuelRestored -= HandleFuelRestored;
            }
            */

            if (deathManager != null)
            {
                deathManager.OnDeath -= HandleDeath;
                deathManager.OnRespawn -= HandleRespawn;
                deathManager.OnRespawnReady -= HandleRespawnReady;
            }

            // Detener corrutinas
            if (blinkCoroutine != null)
            {
                StopCoroutine(blinkCoroutine);
            }
        }

#if UNITY_EDITOR
        private void OnValidate()
        {
            tapThreshold = Mathf.Max(0.01f, tapThreshold);
            inactiveAlpha = Mathf.Clamp01(inactiveAlpha);
            deadAlpha = Mathf.Clamp01(deadAlpha);
            // noFuelAlpha = Mathf.Clamp01(noFuelAlpha); // COMENTADO: Variable no usada
            blinkSpeed = Mathf.Max(0.1f, blinkSpeed);
        }
#endif
    }
}