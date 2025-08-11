using UnityEngine;
using System.Collections;
using System;
using TMPro;

namespace GameSystems
{
    /// <summary>
    /// Sistema unificado de muerte y respawn
    /// Maneja todos los tipos de muerte en un solo lugar
    /// </summary>
    public class UnifiedDeathManager : MonoBehaviour
    {
        public enum DeathType
        {
            BlackHole,
            PlayerCollision,
            FuelEmpty,
            OutOfBounds
        }

        [Header("Referencias")]
        [SerializeField] private Transform respawnPoint;
        [SerializeField] private GameObject shipVisual;
        [SerializeField] private ShipController shipController;
        [SerializeField] private FuelManager fuelManager;
        [SerializeField] private ShipInputController inputController;
        [SerializeField] private ShipInvulnerability invulnerability;
        [SerializeField] private Rigidbody2D shipRigidbody;

        [Header("UI Respawn")]
        [SerializeField] private GameObject respawnUI;
        [SerializeField] private TextMeshProUGUI respawnText;
        [SerializeField] private GameObject respawnButton; // El botón de gasolina

        [Header("Configuración")]
        [SerializeField] private float respawnWaitTime = 3f; // Tiempo antes de habilitar botón
        [SerializeField] private float fuelOnRespawn = 30f; // Combustible al respawnear
        [SerializeField] private float invulnerabilityDuration = 2f;
        [SerializeField] private bool autoRespawn = false; // false = respawn manual con botón

        [Header("Efectos de Muerte")]
        [SerializeField] private GameObject deathEffectPrefab;
        [SerializeField] private AudioClip[] deathSounds; // Sonidos por tipo de muerte

        [Header("Debug")]
        [SerializeField] private bool debugMode = false;

        // Estado
        private bool isDead = false;
        private bool isRespawning = false;
        private Vector3 originalScale;
        private Coroutine currentDeathCoroutine;

        // Eventos
        public event Action<DeathType> OnDeath;
        public event Action OnRespawn;
        public event Action OnRespawnReady; // Cuando el botón está listo

        // Propiedades públicas
        public bool IsDead => isDead;
        public bool IsRespawning => isRespawning;

        private void Awake()
        {
            ValidateReferences();
            originalScale = transform.localScale;
        }

        private void Start()
        {
            // Suscribirse a eventos
            if (fuelManager != null)
            {
                fuelManager.OnFuelEmpty += () => TriggerDeath(DeathType.FuelEmpty);
            }

            // Ocultar UI de respawn al inicio
            if (respawnUI != null)
                respawnUI.SetActive(false);

            if (respawnButton != null)
                respawnButton.SetActive(false);
        }

        /// <summary>
        /// Trigger público para iniciar muerte
        /// </summary>
        public void TriggerDeath(DeathType deathType)
        {
            if (isDead) return;

            if (debugMode)
                Debug.Log($"[DeathManager] Muerte triggered: {deathType}");

            if (currentDeathCoroutine != null)
                StopCoroutine(currentDeathCoroutine);

            currentDeathCoroutine = StartCoroutine(DeathSequence(deathType));
        }

        /// <summary>
        /// Secuencia de muerte
        /// </summary>
        private IEnumerator DeathSequence(DeathType deathType)
        {
            isDead = true;

            // 1. Invocar evento de muerte
            OnDeath?.Invoke(deathType);

            // 2. Detener la nave completamente
            StopShip();

            // 3. Efectos visuales y sonoros
            PlayDeathEffects(deathType);

            // 4. Ocultar visual de la nave
            HideShipVisual();

            // 5. Registrar muerte en el score
            var playerMain = GetComponentInParent<PlayerMain>();
            if (playerMain != null)
                playerMain.PlayerScoreSystem.AddScore(inDeaths: 1);

            // 6. Iniciar secuencia de respawn
            if (autoRespawn)
            {
                yield return StartCoroutine(AutoRespawnSequence());
            }
            else
            {
                yield return StartCoroutine(ManualRespawnSequence());
            }
        }

        /// <summary>
        /// Secuencia de respawn automático
        /// </summary>
        private IEnumerator AutoRespawnSequence()
        {
            isRespawning = true;

            // Mostrar countdown
            if (respawnUI != null)
            {
                respawnUI.SetActive(true);

                float timeLeft = respawnWaitTime;
                while (timeLeft > 0)
                {
                    if (respawnText != null)
                        respawnText.text = $"Respawn en {Mathf.Ceil(timeLeft)}...";

                    yield return new WaitForSeconds(1f);
                    timeLeft--;
                }

                respawnUI.SetActive(false);
            }
            else
            {
                yield return new WaitForSeconds(respawnWaitTime);
            }

            // Ejecutar respawn
            ExecuteRespawn();
        }

        /// <summary>
        /// Secuencia de respawn manual con botón
        /// </summary>
        private IEnumerator ManualRespawnSequence()
        {
            isRespawning = true;

            // Mostrar countdown antes de habilitar botón
            if (respawnUI != null)
            {
                respawnUI.SetActive(true);

                float timeLeft = respawnWaitTime;
                while (timeLeft > 0)
                {
                    if (respawnText != null)
                        respawnText.text = $"Esperando... {Mathf.Ceil(timeLeft)}";

                    yield return new WaitForSeconds(1f);
                    timeLeft--;
                }

                // Cambiar texto para indicar que está listo
                if (respawnText != null)
                    respawnText.text = "¡Presiona para respawn!";
            }
            else
            {
                yield return new WaitForSeconds(respawnWaitTime);
            }

            // Habilitar botón de respawn
            EnableRespawnButton();
            OnRespawnReady?.Invoke();

            // Esperar hasta que el jugador presione el botón
            while (isRespawning)
            {
                yield return null;
            }
        }

        /// <summary>
        /// Habilita el botón para respawn manual
        /// </summary>
        private void EnableRespawnButton()
        {
            if (respawnButton != null)
            {
                respawnButton.SetActive(true);

                // Añadir animación de "listo"
                var animator = respawnButton.GetComponent<Animator>();
                if (animator != null)
                    animator.SetTrigger("Ready");
            }

            // Notificar al input controller
            if (inputController != null)
                inputController.EnableForRespawn();

            if (debugMode)
                Debug.Log("[DeathManager] Botón de respawn habilitado");
        }

        /// <summary>
        /// Llamado cuando el jugador presiona el botón de respawn
        /// </summary>
        public void OnRespawnButtonPressed()
        {
            if (!isRespawning || !isDead) return;

            if (debugMode)
                Debug.Log("[DeathManager] Botón de respawn presionado");

            // Ocultar UI
            if (respawnUI != null)
                respawnUI.SetActive(false);

            if (respawnButton != null)
                respawnButton.SetActive(false);

            // Ejecutar respawn
            ExecuteRespawn();
            isRespawning = false;
        }

        /// <summary>
        /// Ejecuta el respawn de la nave
        /// </summary>
        private void ExecuteRespawn()
        {
            if (debugMode)
                Debug.Log("[DeathManager] Ejecutando respawn");

            // 1. Resetear posición y escala
            transform.position = respawnPoint.position;
            transform.rotation = Quaternion.identity;
            transform.localScale = originalScale;

            // 2. Limpiar velocidades
            ResetPhysics();

            // 3. Restaurar combustible
            if (fuelManager != null)
                fuelManager.AddFuel(fuelOnRespawn);

            // 4. Mostrar visual de la nave
            ShowShipVisual();

            // 5. Activar invulnerabilidad
            if (invulnerability != null)
                invulnerability.ActivarInvulnerabilidad();

            // 6. Resetear input
            if (inputController != null)
                inputController.ResetInputState();

            // 7. Resetear flags
            isDead = false;
            isRespawning = false;

            // 8. Invocar evento
            OnRespawn?.Invoke();

            if (debugMode)
                Debug.Log("[DeathManager] Respawn completado");
        }

        /// <summary>
        /// Detiene completamente la nave
        /// </summary>
        private void StopShip()
        {
            // Detener movimiento
            if (shipController != null)
            {
                shipController.StopMoving();
                shipController.ResetMovement();
            }

            // Detener consumo de combustible
            if (fuelManager != null)
                fuelManager.StopConsuming();

            // Limpiar física
            ResetPhysics();
        }

        /// <summary>
        /// Resetea toda la física del Rigidbody
        /// </summary>
        private void ResetPhysics()
        {
            if (shipRigidbody != null)
            {
                shipRigidbody.linearVelocity = Vector2.zero;
                shipRigidbody.angularVelocity = 0f;
                shipRigidbody.totalForce = Vector2.zero;
                shipRigidbody.totalTorque = 0f;

                // Despertar el rigidbody por si estaba dormido
                shipRigidbody.WakeUp();
            }
        }

        /// <summary>
        /// Reproduce efectos de muerte según el tipo
        /// </summary>
        private void PlayDeathEffects(DeathType deathType)
        {
            // Efecto visual
            if (deathEffectPrefab != null)
            {
                var effect = Instantiate(deathEffectPrefab, transform.position, Quaternion.identity);
                Destroy(effect, 3f);
            }

            // Sonido específico por tipo
            if (deathSounds != null && deathSounds.Length > (int)deathType)
            {
                var clip = deathSounds[(int)deathType];
                if (clip != null)
                    AudioSource.PlayClipAtPoint(clip, transform.position);
            }
        }

        /// <summary>
        /// Oculta el visual de la nave
        /// </summary>
        private void HideShipVisual()
        {
            if (shipVisual != null)
                shipVisual.SetActive(false);
        }

        /// <summary>
        /// Muestra el visual de la nave
        /// </summary>
        private void ShowShipVisual()
        {
            if (shipVisual != null)
                shipVisual.SetActive(true);
        }

        /// <summary>
        /// Valida que todas las referencias estén configuradas
        /// </summary>
        private void ValidateReferences()
        {
            if (shipController == null)
                shipController = GetComponent<ShipController>();

            if (fuelManager == null)
                fuelManager = GetComponent<FuelManager>();

            if (inputController == null)
                inputController = GetComponentInChildren<ShipInputController>();

            if (invulnerability == null)
                invulnerability = GetComponent<ShipInvulnerability>();

            if (shipRigidbody == null)
                shipRigidbody = GetComponent<Rigidbody2D>();

            // Validar referencias críticas
            if (respawnPoint == null)
                Debug.LogError("[DeathManager] respawnPoint no asignado!");
        }

        /// <summary>
        /// Maneja colisión con agujero negro
        /// </summary>
        private void OnTriggerEnter2D(Collider2D other)
        {
            // Detectar zona de muerte del agujero negro
            if (other.CompareTag("BlackHoleDeathZone") && !isDead)
            {
                TriggerDeath(DeathType.BlackHole);
            }
        }

        /// <summary>
        /// Maneja colisión con otros jugadores
        /// </summary>
        private void OnCollisionEnter2D(Collision2D collision)
        {
            if (isDead) return;

            // Detectar colisión trasera con otro jugador
            if (collision.gameObject.CompareTag("Player"))
            {
                // Verificar si el impacto fue por detrás
                Vector2 impactDirection = collision.contacts[0].normal;
                float angle = Vector2.Angle(-transform.up, impactDirection);

                if (angle < 45f) // Impacto trasero
                {
                    TriggerDeath(DeathType.PlayerCollision);
                }
            }
        }

        /// <summary>
        /// Limpieza al destruir
        /// </summary>
        private void OnDestroy()
        {
            if (currentDeathCoroutine != null)
                StopCoroutine(currentDeathCoroutine);

            // Limpiar eventos
            OnDeath = null;
            OnRespawn = null;
            OnRespawnReady = null;
        }

#if UNITY_EDITOR
        [ContextMenu("Test: Trigger Black Hole Death")]
        private void TestBlackHoleDeath() => TriggerDeath(DeathType.BlackHole);

        [ContextMenu("Test: Trigger Collision Death")]
        private void TestCollisionDeath() => TriggerDeath(DeathType.PlayerCollision);

        [ContextMenu("Test: Trigger Fuel Death")]
        private void TestFuelDeath() => TriggerDeath(DeathType.FuelEmpty);

        [ContextMenu("Test: Force Respawn")]
        private void TestForceRespawn() => ExecuteRespawn();

        private void OnValidate()
        {
            respawnWaitTime = Mathf.Max(0f, respawnWaitTime);
            fuelOnRespawn = Mathf.Max(0f, fuelOnRespawn);
            invulnerabilityDuration = Mathf.Max(0f, invulnerabilityDuration);
        }
#endif
    }
}