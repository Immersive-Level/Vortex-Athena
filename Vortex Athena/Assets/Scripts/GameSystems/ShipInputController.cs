using UnityEngine;
using UnityEngine.EventSystems;
using System;
using System.Collections;
using Fusion;

namespace GameSystems
{
    public struct NetworkInputData : INetworkInput
    {
        public NetworkBool IsPressing;
    }

    /// <summary>
    /// Controlador de input para la nave - Integrado con nueva lógica de InicioNave
    /// </summary>
    /// 

    public class ShipInputController : MonoBehaviour, IPointerDownHandler, IPointerUpHandler
    {
        public enum ButtonState
        {
            Inactive,       // Antes de iniciar (alpha 0.5)
            Playing,        // Jugando normal (alpha 1.0)
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
        private InicioNave inicioNave;

        // Eventos
        public event Action OnButtonPressed;
        public event Action OnButtonReleased;
        public event Action OnTapDetected;
        public event Action<ButtonState> OnStateChanged;

        // ============================================================
        // NUEVAS PROPIEDADES PÚBLICAS PARA CONSULTA DE ESTADO
        // ============================================================

        /// <summary>
        /// Indica si el juego está en estado Playing (puede procesar input de gameplay)
        /// </summary>
        public bool IsPlayingState => currentButtonState == ButtonState.Playing;

        /// <summary>
        /// Obtiene el estado actual del botón
        /// </summary>
        public ButtonState CurrentState => currentButtonState;

        /// <summary>
        /// Indica si el sistema puede aceptar input de gameplay en este momento
        /// </summary>
        public bool CanAcceptGameplayInput()
        {
            return currentButtonState == ButtonState.Playing && canPress && gameStarted;
        }

        // ============================================================

        private void Awake()
        {
            canvasGroup = GetComponent<CanvasGroup>();
            if (canvasGroup == null)
                canvasGroup = gameObject.AddComponent<CanvasGroup>();

            gameObject.SetActive(true);
            ValidateReferences();
        }

        private void Start()
        {
            SetButtonState(ButtonState.Inactive);

            if (fuelManager != null)
                fuelManager.OnFuelEmpty += HandleFuelEmptyStopThrust;

            if (deathManager != null)
            {
                deathManager.OnDeath += HandleDeath;
                deathManager.OnRespawn += HandleRespawn;
                deathManager.OnRespawnReady += HandleRespawnReady;
            }

            // Obtener referencia a InicioNave
            inicioNave = GetComponentInParent<InicioNave>();
            if (inicioNave != null)
            {
                StartCoroutine(CheckGameStarted(inicioNave));
            }
        }

        public void SetScriptReferences(FuelManager FuelManager, ShipController ShipController, UnifiedDeathManager UnifiedDeathManager)
        {
            fuelManager = FuelManager;
            shipController = ShipController;
            deathManager = UnifiedDeathManager;
        }

        private IEnumerator CheckGameStarted(InicioNave inicioNave)
        {
            while (!gameStarted && inicioNave != null)
            {
                if (inicioNave.JuegoIniciado)
                {
                    gameStarted = true;
                    SetButtonState(ButtonState.Playing);
                    break;
                }
                yield return new WaitForSeconds(0.1f);
            }
        }

        private void OnEnable()
        {
            NetworkCallbacksHandler.OnPlayerInputGlobal += HandleInput;

            // Asegurar que el bot�n siempre est� visible
            if (canvasGroup != null)
                canvasGroup.blocksRaycasts = true;
        }

        private void OnDisable()
        {
            NetworkCallbacksHandler.OnPlayerInputGlobal -= HandleInput;
        }

        void HandleInput(NetworkInput input)
        {
            var myInput = new NetworkInputData();

            myInput.IsPressing = isPressing;

            input.Set(myInput);
        }

        /// <summary>
        /// Cambia el estado visual del bot�n
        /// </summary>
        public void SetButtonState(ButtonState newState)
        {
            if (currentButtonState == newState) return;

            ButtonState previousState = currentButtonState;
            currentButtonState = newState;

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
                        blinkCoroutine = StartCoroutine(BlinkEffect());
                    else
                        canvasGroup.alpha = 1f;
                    break;
            }

            // Notificar cambio de estado a otros sistemas
            OnStateChanged?.Invoke(newState);

            if (debugMode)
                Debug.Log($"[ShipInput] Estado del botón: {previousState} → {newState}");
        }

        private IEnumerator BlinkEffect()
        {
            while (currentButtonState == ButtonState.RespawnReady)
            {
                float alpha = Mathf.PingPong(Time.time * blinkSpeed, 1f);
                alpha = Mathf.Lerp(0.5f, 1f, alpha);
                canvasGroup.alpha = alpha;
                yield return null;
            }
        }

        public void OnPointerDown(PointerEventData eventData)
        {
            fuelManager?.BeginThrottleHold();

            // Si estamos esperando respawn, ejecutar respawn
            if (isRespawning && currentButtonState == ButtonState.RespawnReady)
            {
                ExecuteRespawn();
                return;
            }

            // Si el juego no ha iniciado pero estamos en estado InGame, iniciar manualmente
            if (!gameStarted && inicioNave != null && !inicioNave.JuegoIniciado)
            {
                // Verificar que estemos en estado de juego
                if (GameManager.Instance != null && GameManager.Instance.CurrentState == GameState.InGame)
                {
                    inicioNave.IniciarJuego();
                    return; // El juego se iniciará y el próximo press será para movimiento
                }
            }

            // Lógica normal de movimiento
            if (!canPress)
            {
                if (debugMode)
                    Debug.Log($"[ShipInput] Press ignorado - CanPress:{canPress}, State:{currentButtonState}");
                return;
            }

            if (fuelManager != null && !fuelManager.CanStartThrust())
            {
                fuelManager.RegisterConsumptionAttempt();
                if (debugMode) Debug.Log("[ShipInput] Press ignorado - Combustible insuficiente");
                return;
            }

            isPressing = true;
            pressStartTime = Time.time;

            shipController.StartMoving();
            fuelManager.StartConsuming();
            OnButtonPressed?.Invoke();

            if (debugMode)
                Debug.Log("[ShipInput] Botón presionado - Iniciando movimiento");
        }

        public void OnPointerUp(PointerEventData eventData)
        {
            if (!isPressing)
            {
                fuelManager?.EndThrottleHold();
                return;
            }

            isPressing = false;

            shipController.StopMoving();
            fuelManager.StopConsuming();
            fuelManager?.EndThrottleHold();

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

        private void HandleDeath(UnifiedDeathManager.DeathType deathType)
        {
            fuelManager?.EndThrottleHold();
            SetButtonState(ButtonState.Dead);

            if (isPressing)
                OnPointerUp(null);

            if (debugMode)
                Debug.Log($"[ShipInput] Jugador murió por {deathType}");
        }

        private void HandleRespawnReady()
        {
            SetButtonState(ButtonState.RespawnReady);

            if (debugMode)
                Debug.Log("[ShipInput] Respawn listo - Presiona el botón");
        }

        private void HandleRespawn()
        {
            fuelManager?.EndThrottleHold();
            SetButtonState(ButtonState.Playing);
            isRespawning = false;

            if (debugMode)
                Debug.Log("[ShipInput] Jugador respawneado");
        }

        public void EnableForRespawn()
        {
            SetButtonState(ButtonState.RespawnReady);
        }

        public void ExecuteRespawn()
        {
            if (!isRespawning || currentButtonState != ButtonState.RespawnReady) return;

            isRespawning = false;
            SetButtonState(ButtonState.Dead);

            if (deathManager != null)
                deathManager.OnRespawnButtonPressed();

            if (debugMode)
                Debug.Log("[ShipInput] Respawn ejecutado");
        }

        public void ResetInputState()
        {
            isPressing = false;
            isRespawning = false;
            pressStartTime = 0f;

            if (!gameStarted)
                SetButtonState(ButtonState.Inactive);
            else if (deathManager != null && deathManager.IsDead)
                SetButtonState(ButtonState.Dead);
            else
                SetButtonState(ButtonState.Playing);

            if (debugMode)
                Debug.Log("[ShipInput] Estado reiniciado");
        }

        public void OnGameStarted()
        {
            gameStarted = true;
            SetButtonState(ButtonState.Playing);
        }

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

        private void HandleFuelEmptyStopThrust()
        {
            if (isPressing)
            {
                isPressing = false;
                shipController.StopMoving();
                fuelManager.StopConsuming();
            }
        }

        private void OnDestroy()
        {
            if (fuelManager != null)
                fuelManager.OnFuelEmpty -= HandleFuelEmptyStopThrust;

            if (deathManager != null)
            {
                deathManager.OnDeath -= HandleDeath;
                deathManager.OnRespawn -= HandleRespawn;
                deathManager.OnRespawnReady -= HandleRespawnReady;
            }

            if (blinkCoroutine != null)
                StopCoroutine(blinkCoroutine);
        }

#if UNITY_EDITOR
        private void OnValidate()
        {
            tapThreshold = Mathf.Max(0.01f, tapThreshold);
            inactiveAlpha = Mathf.Clamp01(inactiveAlpha);
            deadAlpha = Mathf.Clamp01(deadAlpha);
            blinkSpeed = Mathf.Max(0.1f, blinkSpeed);
        }
#endif
    }
}