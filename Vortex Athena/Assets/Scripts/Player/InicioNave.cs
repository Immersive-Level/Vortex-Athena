using UnityEngine;
using GameSystems;

/// <summary>
/// Gestiona inicialización de naves optimizado para BlackHoleCore
/// </summary>
public class InicioNave : MonoBehaviour
{
    [Header("Configuración de Nave")]
    public GameObject nave;
    public float impulsoInicial = 5f;
    public Vector2 direccionImpulso;

    [Header("Configuración Inicial")]
    public float combustibleInicial = 100f;

    [Header("Órbita Inicial")]
    [SerializeField] private bool usarOrbitaInicial = true;
    [SerializeField] private Transform orbitaCentro;
    [SerializeField] private int sentidoOrbita = 1;

    [Header("Sistema BlackHole")]
    [SerializeField] private BlackHoleCore blackHoleCore;
    [SerializeField] private bool autoFindBlackHole = true;
    [SerializeField] private ShipInputController shipInputController;

    private bool juegoIniciado = false;
    public bool JuegoIniciado => juegoIniciado;

    void Start()
    {
        if (GameManager.Instance != null)
        {
            GameManager.Instance.RegisterShip(nave);
        }

        if (autoFindBlackHole && blackHoleCore == null)
        {
            blackHoleCore = FindAnyObjectByType<BlackHoleCore>();
            if (blackHoleCore == null)
            {
                Debug.LogWarning("InicioNave: BlackHoleCore not found in scene", this);
            }
        }
    }

    public void IniciarJuego()
    {
        if (juegoIniciado || nave == null) return;

        juegoIniciado = true;
        nave.SetActive(true);

        Rigidbody2D rb = nave.GetComponent<Rigidbody2D>();
        if (rb != null)
        {
            rb.bodyType = RigidbodyType2D.Dynamic;
            rb.simulated = true;

            Vector2 vDir;
            Vector2 centroParaOrbita = Vector2.zero;

            if (usarOrbitaInicial)
            {
                centroParaOrbita = orbitaCentro ? (Vector2)orbitaCentro.position :
                                   (blackHoleCore ? (Vector2)blackHoleCore.transform.position : Vector2.zero);

                Vector2 radial = ((Vector2)rb.worldCenterOfMass - centroParaOrbita);
                if (radial.sqrMagnitude < 0.0001f) radial = Vector2.right;
                radial.Normalize();

                Vector2 tangente = new Vector2(-radial.y, radial.x) * Mathf.Sign(sentidoOrbita == 0 ? 1 : sentidoOrbita);
                vDir = tangente;
            }
            else
            {
                vDir = direccionImpulso.sqrMagnitude > 0f ? direccionImpulso.normalized : Vector2.right;
            }

            rb.linearVelocity = vDir * impulsoInicial;

            if (usarOrbitaInicial)
            {
                float r = Vector2.Distance(rb.worldCenterOfMass, centroParaOrbita);
                if (r > 0.001f)
                {
                    float omegaDegPerSec = (impulsoInicial / r) * Mathf.Rad2Deg;
                    rb.angularVelocity = omegaDegPerSec * Mathf.Sign(sentidoOrbita == 0 ? 1 : sentidoOrbita);
                }
                else
                {
                    rb.angularVelocity = 0f;
                }
            }
            else
            {
                rb.angularVelocity = 0f;
            }
        }

        ConfigurarSistemas();

        if (shipInputController != null)
            shipInputController.OnGameStarted();

        RegistrarEnBlackHole();
    }

    private void ConfigurarSistemas()
    {
        var fuelManager = nave.GetComponentInChildren<FuelManager>();
        if (fuelManager != null)
        {
            fuelManager.SetFuel(combustibleInicial);
            fuelManager.ResetFuelSystem();
        }

        var shipController = nave.GetComponentInChildren<ShipController>();
        if (shipController != null)
        {
            shipController.ResetMovement();
        }

        var playerGravityHandler = nave.GetComponent<PlayerGravityHandler>();
        if (playerGravityHandler != null)
        {
            playerGravityHandler.ResetGravityState();
        }
    }

    public void ReiniciarNave()
    {
        if (nave != null)
        {
            DesregistrarDeBlackHole();

            var shipController = nave.GetComponentInChildren<ShipController>();
            if (shipController != null)
                shipController.ResetMovement();

            var fuelManager = nave.GetComponentInChildren<FuelManager>();
            if (fuelManager != null)
                fuelManager.ResetFuelSystem();

            if (shipInputController != null)
                shipInputController.ResetInputState();

            var playerGravityHandler = nave.GetComponent<PlayerGravityHandler>();
            if (playerGravityHandler != null)
            {
                playerGravityHandler.ResetGravityState();
            }

            nave.SetActive(false);
            juegoIniciado = false;
        }
    }

    private void RegistrarEnBlackHole()
    {
        if (blackHoleCore != null && nave != null)
        {
            PlayerGravityHandler playerGravityHandler = nave.GetComponent<PlayerGravityHandler>();
            if (playerGravityHandler != null)
            {
                var shipController = nave.GetComponentInChildren<ShipController>();
                if (shipController != null)
                {
                    shipController.SetMapCenter(blackHoleCore.Position);
                }
            }
            else
            {
                Debug.LogError($"InicioNave: Ship {nave.name} missing PlayerGravityHandler!", this);
            }
        }
    }

    private void DesregistrarDeBlackHole()
    {
        // El BlackHoleCore maneja esto automáticamente
    }

    public void SetBlackHoleReference(BlackHoleCore newBlackHole)
    {
        blackHoleCore = newBlackHole;

        if (juegoIniciado)
        {
            var shipController = nave?.GetComponentInChildren<ShipController>();
            if (shipController != null && blackHoleCore != null)
            {
                shipController.SetMapCenter(blackHoleCore.Position);
            }
        }
    }

    public bool IsShipReadyForGravitySystem()
    {
        if (nave == null) return false;

        var playerGravityHandler = nave.GetComponent<PlayerGravityHandler>();
        var rigidbody = nave.GetComponent<Rigidbody2D>();
        var collider = nave.GetComponent<Collider2D>();

        return playerGravityHandler != null && rigidbody != null && collider != null;
    }

    private void OnValidate()
    {
        impulsoInicial = Mathf.Max(0f, impulsoInicial);
        if (sentidoOrbita == 0) sentidoOrbita = 1;
    }

    void OnDisable() => DesregistrarDeBlackHole();
    void OnDestroy() => DesregistrarDeBlackHole();
}
