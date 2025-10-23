using UnityEngine;

public class ShieldController : MonoBehaviour
{
    private CombatSystem _combatSystem;

    // ─────────────────────────────────────────────────────────────
    // Black Hole Repel (ya lo tenías)
    // ─────────────────────────────────────────────────────────────
    [Header("Black Hole Repel")]
    [SerializeField] private bool repelBlackHole = true;
    [SerializeField] private LayerMask blackHoleCoreLayers;
    [SerializeField] private float blackHoleImpulse = 45f;
    [SerializeField] private float randomAngle = 20f;
    [SerializeField] private bool consumeShieldOnRepel = false;
    [SerializeField] private float repelCooldown = 0.15f;

    // ─────────────────────────────────────────────────────────────
    // NUEVO: Spin al repeler
    // ─────────────────────────────────────────────────────────────
    [Header("NUEVO · Spin al repeler")]
    [Tooltip("Aplica un pequeño giro cuando el escudo expulsa la nave del agujero negro.")]
    [SerializeField] private bool addSpinOnRepel = true; // NUEVO

    [Tooltip("Impulso de torque (grados·masa·unidad / s). Valores pequeños: 5–25.")]
    [SerializeField] private float spinImpulse = 8f; // NUEVO

    [Tooltip("Variación ± en porcentaje sobre el impulso de giro.")]
    [Range(0f, 1f)][SerializeField] private float spinVariance = 0.35f; // NUEVO

    [Tooltip("Si está activo, el signo del spin se elige al azar.")]
    [SerializeField] private bool randomizeSpinSign = true; // NUEVO

    private Rigidbody2D _shipRb;
    private float _lastRepelTime = -999f;

    public void ActivateShield(float inTimer, CombatSystem combatSystem)
    {
        Debug.Log("Active shield");
        _combatSystem = combatSystem;

        if (_combatSystem == null)
        {
            Debug.Log("_combatSystem null");
            return;
        }

        if (_shipRb == null)
        {
            _shipRb = _combatSystem.GetComponent<Rigidbody2D>()
                   ?? _combatSystem.GetComponentInParent<Rigidbody2D>()
                   ?? _combatSystem.GetComponentInChildren<Rigidbody2D>();
        }

        gameObject.SetActive(true);
        _combatSystem.IsInvencible = true;

        Invoke(nameof(DeactivateShield), inTimer);
    }

    public void DeactivateShield()
    {
        Debug.Log("deActive shield");
        if (_combatSystem == null)
        {
            Debug.Log("_combatSystem null");
            return;
        }

        gameObject.SetActive(false);
        _combatSystem.IsInvencible = false;
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        // Repeler agujero negro (núcleo en LayerMask)
        if (repelBlackHole)
        {
            int bit = 1 << collision.gameObject.layer;
            if ((blackHoleCoreLayers.value & bit) != 0)
            {
                if (Time.time - _lastRepelTime >= repelCooldown)
                {
                    _lastRepelTime = Time.time;

                    Vector2 center = collision.bounds.center;
                    Vector2 outDir = (_shipRb != null ? _shipRb.position : (Vector2)transform.position) - center;
                    if (outDir.sqrMagnitude < 0.0001f) outDir = Vector2.up;
                    outDir.Normalize();

                    if (randomAngle > 0f)
                    {
                        float jitter = Random.Range(-randomAngle, randomAngle);
                        outDir = (Vector2)(Quaternion.Euler(0f, 0f, jitter) * outDir);
                    }

                    if (_shipRb != null)
                    {
                        // Impulso lineal
                        _shipRb.AddForce(outDir * blackHoleImpulse, ForceMode2D.Impulse);

                        // ─────────────────────────────────────────────
                        // NUEVO: Impulso angular para que salga girando
                        // ─────────────────────────────────────────────
                        if (addSpinOnRepel && Mathf.Abs(spinImpulse) > 0f)
                        {
                            float spin = spinImpulse * (1f + Random.Range(-spinVariance, spinVariance));
                            if (randomizeSpinSign && Random.value < 0.5f) spin = -spin;
                            _shipRb.AddTorque(spin, ForceMode2D.Impulse);
                        }
                    }
                    else
                    {
                        // Fallback suave sin Rigidbody2D
                        transform.root.position += (Vector3)(outDir * blackHoleImpulse * 0.02f);
                        // (Sin RB2D no hay torque posible)
                    }

                    if (consumeShieldOnRepel)
                    {
                        DeactivateShield();
                        return;
                    }
                }
            }
        }

        // Lógica original: consumir por Arena/Nave/Missil si aplica en tu proyecto
        bool isArena = collision.gameObject.CompareTag("Arena");
        bool isNave = collision.gameObject.CompareTag("Nave");
        bool isMissil = collision.gameObject.CompareTag("Missil");
        if (isArena || isNave || isMissil)
        {
            DeactivateShield();
        }
    }
}
