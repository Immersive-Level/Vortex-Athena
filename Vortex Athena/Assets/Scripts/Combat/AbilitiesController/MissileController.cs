using UnityEngine;
using GameSystems;

/// <summary>
/// Controlador de misiles con FIX CRÍTICO del sistema de puntaje
/// 
/// FIX PRINCIPAL: Ahora da la kill al SHOOTER (dueño del misil), NO a la víctima
/// Esto resuelve el bug donde los puntos saltaban de -50 a 150
/// </summary>
public class MissileController : MonoBehaviour
{
    [Header("Movimiento")]
    [SerializeField] private float speed = 10f;
    [SerializeField] private float turnSpeed = 5f;
    [SerializeField] private float waveFrequency = 2f;
    [SerializeField] private float waveAmplitude = 0.5f;

    [Header("Targeting")]
    [SerializeField] private float searchRadius = 50f;
    public bool shouldFollowTarget = true; // Público para ser configurado por MisileAbility
    [SerializeField] private Transform target;

    [Header("Configuración")]
    [SerializeField] private float lifetime = 10f;

    [Header("Debug")]
    [SerializeField] private bool enableDebugLogs = true;

    // Referencias al dueño del misil
    private GameObject ownerObject;
    private PlayerScoreSystem ownerScoreSystem;

    // Estado del misil
    private Vector3 launchDirection;
    private float lifeTimer;
    private bool hasHitTarget = false; // NUEVO: Prevenir hits duplicados

    #region Inicialización

    /// <summary>
    /// Lanza el misil desde el owner especificado
    /// </summary>
    public void Launch(GameObject owner)
    {
        if (owner == null)
        {
            LogError("Launch: owner es nulo. Destruyendo misil.");
            Destroy(gameObject);
            return;
        }

        ownerObject = owner;
        launchDirection = transform.up;

        // NUEVO: Cachear el score system del owner
        ownerScoreSystem = ownerObject.GetComponent<PlayerScoreSystem>();
        if (ownerScoreSystem == null)
        {
            ownerScoreSystem = ownerObject.GetComponentInParent<PlayerScoreSystem>();
            if (ownerScoreSystem == null)
                ownerScoreSystem = ownerObject.GetComponentInChildren<PlayerScoreSystem>();
        }

        if (ownerScoreSystem == null)
        {
            LogWarning($"No se encontró PlayerScoreSystem en el owner: {owner.name}");
        }

        FindInitialTarget();

        Log($"Misil lanzado por {owner.name}");
    }

    #endregion

    #region Update

    private void Update()
    {
        lifeTimer += Time.deltaTime;
        if (lifeTimer > lifetime)
        {
            Log("Misil expiró por tiempo");
            Destroy(gameObject);
            return;
        }

        Vector3 moveDir = launchDirection;

        if (shouldFollowTarget && target != null)
        {
            Vector3 dirToTarget = (target.position - transform.position).normalized;
            launchDirection = Vector3.Slerp(launchDirection, dirToTarget, turnSpeed * Time.deltaTime);
        }

        Vector3 waveOffset = transform.right * Mathf.Sin(Time.time * waveFrequency) * waveAmplitude;
        Vector3 finalDirection = (launchDirection + waveOffset).normalized;

        transform.position += finalDirection * speed * Time.deltaTime;

        float angle = Mathf.Atan2(finalDirection.y, finalDirection.x) * Mathf.Rad2Deg;
        transform.rotation = Quaternion.Euler(0f, 0f, angle - 90f);

        if (enableDebugLogs)
        {
            Debug.DrawRay(transform.position, finalDirection * 2f, Color.red);
        }
    }

    #endregion

    #region Targeting

    private void FindInitialTarget()
    {
        if (GameManager.Instance == null || GameManager.Instance.NavesActivas == null || GameManager.Instance.NavesActivas.Count == 0)
        {
            LogWarning("No se encontraron naves activas para targeting");
            shouldFollowTarget = false;
            return;
        }

        float closestDistance = Mathf.Infinity;
        Transform bestTarget = null;

        foreach (GameObject nave in GameManager.Instance.NavesActivas)
        {
            if (nave == null || nave == ownerObject) continue;

            float distance = Vector3.Distance(transform.position, nave.transform.position);
            Vector3 directionTo = (nave.transform.position - transform.position).normalized;
            float forwardDot = Vector3.Dot(transform.up, directionTo);

            if (forwardDot > 0.5f && distance < closestDistance)
            {
                closestDistance = distance;
                bestTarget = nave.transform;
            }
        }

        if (bestTarget != null)
        {
            target = bestTarget;
            Log($"Objetivo encontrado: {bestTarget.name}");
        }
        else
        {
            shouldFollowTarget = false;
            Log("No se encontró objetivo válido - disparando en línea recta");
        }
    }

    #endregion

    #region Colisiones

    private void OnTriggerEnter2D(Collider2D collision)
    {
        // NUEVO: Prevenir múltiples hits
        if (hasHitTarget)
        {
            return;
        }

        if (collision.gameObject.CompareTag("Nave") || collision.gameObject.CompareTag("Player"))
        {
            HandleShipCollision(collision);
            return;
        }

        if (collision.gameObject.CompareTag("Arena"))
        {
            Log("Misil impactó arena");
            Destroy(gameObject);
            return;
        }
    }

    /// <summary>
    /// Maneja la colisión con una nave
    /// 
    /// ═══════════════════════════════════════════════════════════════
    /// FIX CRÍTICO: Ahora da la kill al SHOOTER, NO a la víctima
    /// ═══════════════════════════════════════════════════════════════
    /// 
    /// ANTES (❌ INCORRECTO):
    /// - Se obtenía el PlayerScoreSystem de la VÍCTIMA
    /// - Se le daba la kill a la VÍCTIMA (+100)
    /// - La víctima moría (-50)
    /// - Resultado: Víctima con +50 puntos (BUG)
    /// 
    /// AHORA (✅ CORRECTO):
    /// - Se usa el ownerScoreSystem (del SHOOTER)
    /// - Se le da la kill al SHOOTER (+100)
    /// - La víctima muere (-50)
    /// - Resultado: Correcto
    /// </summary>
    private void HandleShipCollision(Collider2D collision)
    {
        GameObject hitShip = GetRootShipObject(collision.gameObject);

        if (hitShip == null)
        {
            LogWarning("No se pudo determinar la nave impactada");
            Destroy(gameObject);
            return;
        }

        // Prevenir auto-impacto
        if (hitShip == ownerObject)
        {
            Log("Misil ignorado - auto-impacto");
            return;
        }

        // Marcar como impactado
        hasHitTarget = true;

        Log($"✓ Misil impactó a {hitShip.name}");

        // ════════════════════════════════════════════════════════════════════
        // FIX CRÍTICO: DAR KILL AL SHOOTER (OWNER), NO A LA VÍCTIMA
        // ════════════════════════════════════════════════════════════════════

        // ✅ CORRECTO: Dar kill al OWNER del misil (el que disparó)
        if (ownerScoreSystem != null)
        {
            bool success = ownerScoreSystem.AddKill("Missile Kill");
            if (success)
            {
                Log($"✓ Kill otorgada a {ownerObject.name}");
            }
            else
            {
                LogError($"Error al otorgar kill a {ownerObject.name}");
            }
        }
        else
        {
            LogWarning($"No se pudo otorgar kill - owner sin PlayerScoreSystem");
        }

        // ════════════════════════════════════════════════════════════════════
        // MATAR A LA VÍCTIMA USANDO UNIFIED DEATH MANAGER
        // ════════════════════════════════════════════════════════════════════

        UnifiedDeathManager victimDeathManager = hitShip.GetComponent<UnifiedDeathManager>();
        if (victimDeathManager == null)
            victimDeathManager = hitShip.GetComponentInChildren<UnifiedDeathManager>();

        if (victimDeathManager != null)
        {
            // Reproducir SFX de impacto
            victimDeathManager.PlayMissileImpactSfx();

            // Trigger muerte (automáticamente suma death al morir)
            victimDeathManager.TriggerDeath(UnifiedDeathManager.DeathType.PlayerCollision);
            Log($"✓ Muerte procesada para {hitShip.name} via UnifiedDeathManager");
        }
        else
        {
            // Fallback al sistema anterior si no hay UnifiedDeathManager
            LogWarning($"No se encontró UnifiedDeathManager en {hitShip.name} - usando fallback");

            CombatSystem victimCombatSystem = hitShip.GetComponent<CombatSystem>();
            if (victimCombatSystem == null)
                victimCombatSystem = hitShip.GetComponentInChildren<CombatSystem>();

            if (victimCombatSystem != null)
            {
                victimCombatSystem.Kill();
            }
            else
            {
                LogError($"No se encontró sistema de combate en {hitShip.name}");
            }
        }

        // Destruir el misil
        Destroy(gameObject);
    }

    /// <summary>
    /// Obtiene el GameObject raíz de la nave desde cualquier collider hijo
    /// Sube por la jerarquía hasta encontrar el objeto con PlayerScoreSystem
    /// </summary>
    private GameObject GetRootShipObject(GameObject obj)
    {
        Transform current = obj.transform;
        int maxIterations = 5;
        int iterations = 0;

        while (current != null && iterations < maxIterations)
        {
            PlayerScoreSystem scoreSystem = current.GetComponent<PlayerScoreSystem>();
            if (scoreSystem != null)
            {
                return current.gameObject;
            }

            current = current.parent;
            iterations++;
        }

        if (obj.CompareTag("Nave") || obj.CompareTag("Player"))
        {
            Transform parent = obj.transform;
            while (parent != null)
            {
                if (parent.CompareTag("Nave") || parent.CompareTag("Player"))
                {
                    if (parent.GetComponent<PlayerScoreSystem>() != null)
                    {
                        return parent.gameObject;
                    }
                }
                parent = parent.parent;
            }
        }

        return obj;
    }

    #endregion

    #region Logging

    private void Log(string message)
    {
        if (enableDebugLogs)
            Debug.Log($"[Missile-{GetInstanceID()}] {message}");
    }

    private void LogWarning(string message)
    {
        Debug.LogWarning($"[Missile-{GetInstanceID()}] ⚠ {message}");
    }

    private void LogError(string message)
    {
        Debug.LogError($"[Missile-{GetInstanceID()}] ✖ {message}");
    }

    #endregion

    #region Debug

    private void OnDrawGizmos()
    {
        if (!Application.isPlaying || !enableDebugLogs) return;

        if (target != null)
        {
            Gizmos.color = Color.yellow;
            Gizmos.DrawLine(transform.position, target.position);
        }

        Gizmos.color = Color.red;
        Gizmos.DrawRay(transform.position, launchDirection * 2f);
    }

    #endregion
}