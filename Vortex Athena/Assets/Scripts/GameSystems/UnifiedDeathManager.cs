using UnityEngine;
using System.Collections;
using System;
using TMPro;

namespace GameSystems
{
    /// <summary>
    /// Sistema unificado de muerte y respawn - Versión optimizada para producción
    /// </summary>
    public class UnifiedDeathManager : MonoBehaviour
    {
        public enum DeathType
        {
            BlackHole,
            PlayerCollision,
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

        [Header("Configuración")]
        [SerializeField] private float respawnWaitTime = 3f;
        [SerializeField] private float fuelOnRespawn = 30f;
        [SerializeField] private bool autoRespawn = false;

        [Header("Efectos")]
        [SerializeField] private GameObject deathEffectPrefab;
        [SerializeField] private AudioClip[] deathSounds;

        // Estado optimizado
        private bool isDead = false;
        private bool isRespawning = false;
        private Vector3 originalScale;
        private Coroutine currentDeathCoroutine;

        // Referencias cacheadas para optimización
        private PlayerGravityHandler playerGravityHandler;
        private BlackHoleCore blackHoleCore;
        private PlayerMain playerMain; // Cache para evitar GetComponentInParent repetidos

        // Eventos
        public event Action<DeathType> OnDeath;
        public event Action OnRespawn;
        public event Action OnRespawnReady;

        public bool IsDead => isDead;
        public bool IsRespawning => isRespawning;

        private void Awake()
        {
            CacheReferences();
            originalScale = transform.localScale;
        }

        private void Start()
        {
            if (respawnUI != null)
                respawnUI.SetActive(false);
        }

        private void CacheReferences()
        {
            // Cache de referencias para evitar llamadas repetidas
            playerGravityHandler = GetComponent<PlayerGravityHandler>();
            playerMain = GetComponentInParent<PlayerMain>();

            // Auto-asignar referencias si no están configuradas
            if (shipController == null) shipController = GetComponent<ShipController>();
            if (fuelManager == null) fuelManager = GetComponent<FuelManager>();
            if (inputController == null) inputController = GetComponentInChildren<ShipInputController>();
            if (invulnerability == null) invulnerability = GetComponent<ShipInvulnerability>();
            if (shipRigidbody == null) shipRigidbody = GetComponent<Rigidbody2D>();

            // Buscar BlackHoleCore
            if (blackHoleCore == null)
                blackHoleCore = FindAnyObjectByType<BlackHoleCore>();

            // Validación crítica
            if (respawnPoint == null)
                Debug.LogError("[DeathManager] respawnPoint no asignado!", this);
        }

        public void TriggerDeath(DeathType deathType)
        {
            if (isDead) return;

            // Detener corrutina anterior si existe
            if (currentDeathCoroutine != null)
                StopCoroutine(currentDeathCoroutine);

            currentDeathCoroutine = StartCoroutine(DeathSequence(deathType));
        }

        private IEnumerator DeathSequence(DeathType deathType)
        {
            isDead = true;

            // Eventos y efectos
            OnDeath?.Invoke(deathType);
            StopShip();
            PlayDeathEffects(deathType);
            HideShipVisual();

            // Score (optimizado con cache)
            if (playerMain != null)
                playerMain.PlayerScoreSystem.AddScore(inDeaths: 1);

            // Respawn sequence
            yield return autoRespawn ?
                StartCoroutine(AutoRespawnSequence()) :
                StartCoroutine(ManualRespawnSequence());
        }

        private IEnumerator AutoRespawnSequence()
        {
            isRespawning = true;

            if (respawnUI != null)
            {
                respawnUI.SetActive(true);
                yield return StartCoroutine(CountdownCoroutine("Respawn en"));
                respawnUI.SetActive(false);
            }
            else
            {
                yield return new WaitForSeconds(respawnWaitTime);
            }

            ExecuteRespawn();
        }

        private IEnumerator ManualRespawnSequence()
        {
            isRespawning = true;

            if (respawnUI != null)
            {
                respawnUI.SetActive(true);
                yield return StartCoroutine(CountdownCoroutine("Esperando..."));

                if (respawnText != null)
                    respawnText.text = "¡Presiona para respawn!";
            }
            else
            {
                yield return new WaitForSeconds(respawnWaitTime);
            }

            EnableRespawnButton();
            OnRespawnReady?.Invoke();

            // Esperar hasta respawn
            while (isRespawning)
                yield return null;
        }

        private IEnumerator CountdownCoroutine(string baseText)
        {
            float timeLeft = respawnWaitTime;
            while (timeLeft > 0)
            {
                if (respawnText != null)
                    respawnText.text = $"{baseText} {Mathf.Ceil(timeLeft)}";

                yield return new WaitForSeconds(1f);
                timeLeft--;
            }
        }

        private void EnableRespawnButton()
        {
            if (inputController != null)
                inputController.EnableForRespawn();
        }

        public void OnRespawnButtonPressed()
        {
            if (!isRespawning || !isDead) return;

            if (respawnUI != null)
                respawnUI.SetActive(false);

            ExecuteRespawn();
            isRespawning = false;
        }

        private void ExecuteRespawn()
        {
            // Reset físico
            transform.position = respawnPoint.position;
            transform.rotation = Quaternion.identity;
            transform.localScale = originalScale;
            ResetPhysics();

            // Restaurar sistemas
            if (fuelManager != null)
                fuelManager.AddFuel(fuelOnRespawn);

            ShowShipVisual();

            if (invulnerability != null)
                invulnerability.ActivarInvulnerabilidad();

            if (inputController != null)
                inputController.ResetInputState();

            // Reset flags
            isDead = false;
            isRespawning = false;

            // Gravity fix optimizado
            StartCoroutine(PostRespawnGravityFix());

            OnRespawn?.Invoke();
        }

        /// <summary>
        /// Fix optimizado para el problema de gravedad post-respawn
        /// </summary>
        private IEnumerator PostRespawnGravityFix()
        {
            // Reset gravedad
            if (playerGravityHandler != null)
                playerGravityHandler.ResetGravityState();

            // Wait para física
            yield return new WaitForFixedUpdate();

            // Re-verificar gravedad si es necesario
            if (blackHoleCore != null && playerGravityHandler != null)
                blackHoleCore.CheckAndAddGravityObject(playerGravityHandler);
        }

        private void StopShip()
        {
            if (shipController != null)
            {
                shipController.StopMoving();
                shipController.ResetMovement();
            }

            if (fuelManager != null)
                fuelManager.StopConsuming();

            ResetPhysics();
        }

        private void ResetPhysics()
        {
            if (shipRigidbody != null)
            {
                shipRigidbody.linearVelocity = Vector2.zero;
                shipRigidbody.angularVelocity = 0f;
                shipRigidbody.WakeUp();
            }
        }

        private void PlayDeathEffects(DeathType deathType)
        {
            // Efecto visual
            if (deathEffectPrefab != null)
            {
                var effect = Instantiate(deathEffectPrefab, transform.position, Quaternion.identity);
                Destroy(effect, 3f);
            }

            // Sonido optimizado
            int soundIndex = (int)deathType;
            if (deathSounds != null && soundIndex < deathSounds.Length && deathSounds[soundIndex] != null)
            {
                AudioSource.PlayClipAtPoint(deathSounds[soundIndex], transform.position);
            }
        }

        private void HideShipVisual()
        {
            if (shipVisual != null)
                shipVisual.SetActive(false);
        }

        private void ShowShipVisual()
        {
            if (shipVisual != null)
            {
                shipVisual.SetActive(true);

                // Optimización: Activar SpriteRenderers en una pasada
                var renderers = shipVisual.GetComponentsInChildren<SpriteRenderer>(true);
                foreach (var renderer in renderers)
                    renderer.enabled = true;
            }
        }

        public void SetBlackHoleReference(BlackHoleCore newBlackHole)
        {
            blackHoleCore = newBlackHole;
        }

        private void OnTriggerEnter2D(Collider2D other)
        {
            if (other.CompareTag("BlackHoleDeathZone") && !isDead)
                TriggerDeath(DeathType.BlackHole);
        }

        private void OnCollisionEnter2D(Collision2D collision)
        {
            if (isDead || !collision.gameObject.CompareTag("Player")) return;

            // Verificación optimizada de colisión trasera
            Vector2 impactDirection = collision.contacts[0].normal;
            float angle = Vector2.Angle(-transform.up, impactDirection);

            if (angle < 45f)
                TriggerDeath(DeathType.PlayerCollision);
        }

        private void OnDestroy()
        {
            if (currentDeathCoroutine != null)
                StopCoroutine(currentDeathCoroutine);

            OnDeath = null;
            OnRespawn = null;
            OnRespawnReady = null;
        }

#if UNITY_EDITOR
        [ContextMenu("Test: Black Hole Death")]
        private void TestBlackHoleDeath() => TriggerDeath(DeathType.BlackHole);

        [ContextMenu("Test: Collision Death")]
        private void TestCollisionDeath() => TriggerDeath(DeathType.PlayerCollision);

        [ContextMenu("Test: Force Respawn")]
        private void TestForceRespawn() => ExecuteRespawn();

        private void OnValidate()
        {
            respawnWaitTime = Mathf.Max(0f, respawnWaitTime);
            fuelOnRespawn = Mathf.Max(0f, fuelOnRespawn);
        }
#endif
    }
}