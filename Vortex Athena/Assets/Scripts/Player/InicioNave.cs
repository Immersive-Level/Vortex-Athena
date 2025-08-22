using UnityEngine;
using GameSystems;

/// <summary>
/// Gestiona SOLO la inicialización y activación de una nave
/// No maneja estados del botón - eso lo hace ShipInputController
/// </summary>
public class InicioNave : MonoBehaviour
{
    [Header("Configuración de Nave")]
    public GameObject nave;
    public float impulsoInicial = 5f;
    public Vector2 direccionImpulso;

    [Header("Configuración Inicial")]
    [Tooltip("Combustible inicial al activar la nave")]
    public float combustibleInicial = 100f;

    [Header("Órbita inicial")]
    [SerializeField] private bool usarOrbitaInicial = true;
    [SerializeField] private Transform orbitaCentro; // Asigna el Transform del agujero negro
    [SerializeField] private int sentidoOrbita = 1;  // 1 = CCW, -1 = CW

    [Header("Referencias")]
    [SerializeField] private BlackHoleAttractionManager blackHoleManager;
    [SerializeField] private ShipInputController shipInputController;

    // Estado
    private bool juegoIniciado = false;
    public bool JuegoIniciado => juegoIniciado;

    void Start()
    {
        if (GameManager.Instance != null)
        {
            GameManager.Instance.RegisterShip(nave);
            //nave.SetActive(false);
        }
    }

    /// <summary>
    /// Inicia el juego activando la nave con impulso inicial y velocidad angular de órbita
    /// </summary>
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
            Vector2 centroParaOrbita = Vector2.zero; // guardamos para calcular ω

            if (usarOrbitaInicial)
            {
                // Centro de órbita: override -> manager -> (0,0)
                centroParaOrbita = orbitaCentro ? (Vector2)orbitaCentro.position :
                                   (blackHoleManager ? (Vector2)blackHoleManager.transform.position : Vector2.zero);

                // Vector radial desde centro -> nave
                Vector2 radial = ((Vector2)rb.worldCenterOfMass - centroParaOrbita);
                if (radial.sqrMagnitude < 0.0001f) radial = Vector2.right;
                radial.Normalize();

                // Tangente 2D: (-y, x). Aplica sentido de órbita.
                Vector2 tangente = new Vector2(-radial.y, radial.x) * Mathf.Sign(sentidoOrbita == 0 ? 1 : sentidoOrbita);
                vDir = tangente;
            }
            else
            {
                vDir = direccionImpulso.sqrMagnitude > 0f ? direccionImpulso.normalized : Vector2.right;
            }

            // Velocidad lineal inicial
            rb.linearVelocity = vDir * impulsoInicial;

            // Velocidad angular inicial: ω = v / r (en grados/seg para 2D)
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

        Debug.Log($"[InicioNave] Nave {nave.name} iniciada con {combustibleInicial} de combustible");
    }

    /// <summary>
    /// Configura los sistemas de la nave al iniciar
    /// </summary>
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
    }

    /// <summary>
    /// Reinicia el estado de la nave
    /// </summary>
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

            nave.SetActive(false);
            juegoIniciado = false;

            Debug.Log($"[InicioNave] Nave {nave.name} reiniciada");
        }
    }

    private void RegistrarEnBlackHole()
    {
        if (blackHoleManager != null && nave != null)
        {
            AffectedByBlackHole affected = nave.GetComponent<AffectedByBlackHole>();
            if (affected != null)
            {
                blackHoleManager.RegisterAffectableObject(affected);
                Debug.Log($"[InicioNave] Nave {nave.name} registrada en BlackHoleAttractionManager");
            }
        }
    }

    private void DesregistrarDeBlackHole()
    {
        if (blackHoleManager != null && nave != null)
        {
            AffectedByBlackHole affected = nave.GetComponent<AffectedByBlackHole>();
            if (affected != null)
            {
                blackHoleManager.UnregisterAffectableObject(affected);
                Debug.Log($"[InicioNave] Nave {nave.name} desregistrada del BlackHoleAttractionManager");
            }
        }
    }

    private void OnValidate()
    {
        impulsoInicial = Mathf.Max(0f, impulsoInicial);
        if (sentidoOrbita == 0) sentidoOrbita = 1;
    }

    void OnDisable() => DesregistrarDeBlackHole();
    void OnDestroy() => DesregistrarDeBlackHole();
}
