using UnityEngine;

/// <summary>
/// Gestiona la inicialización y activación de una nave
/// No maneja inputs directamente
/// </summary>
public class InicioNave : MonoBehaviour
{
    [Header("Configuración de Nave")]
    public GameObject nave;
    public float impulsoInicial = 5f;
    public Vector2 direccionImpulso = new Vector2(1, 1);

    [Header("Referencias")]
    [SerializeField] private BlackHoleAttractionManager blackHoleManager;

    // Estado
    private bool juegoIniciado = false;
    public bool JuegoIniciado => juegoIniciado;

    void Awake()
    {
        // Validar referencias
        if (nave == null)
        {
            Debug.LogError($"[InicioNave] No se asignó la nave en {gameObject.name}");
            enabled = false;
            return;
        }
    }

    void Start()
    {
        // Ocultar la nave al inicio
        nave.SetActive(false);

        // Obtener referencia al BlackHoleAttractionManager si no está asignada
        if (blackHoleManager == null)
        {
            blackHoleManager = BlackHoleAttractionManager.Instance;
            if (blackHoleManager == null)
            {
                Debug.LogWarning("[InicioNave] No se encontró un BlackHoleAttractionManager");
            }
        }
    }

    /// <summary>
    /// Inicia el juego activando la nave con impulso inicial
    /// </summary>
    public void IniciarJuego()
    {
        if (juegoIniciado || nave == null) return;

        juegoIniciado = true;

        // Activar la nave
        nave.SetActive(true);

        // Configurar Rigidbody2D
        Rigidbody2D rb = nave.GetComponent<Rigidbody2D>();
        if (rb != null)
        {
            rb.bodyType = RigidbodyType2D.Dynamic;
            rb.simulated = true;

            // Aplicar impulso inicial
            Vector2 direccionInicial = direccionImpulso.normalized;
            rb.linearVelocity = direccionInicial * impulsoInicial;
        }

        // Registrar en BlackHoleAttractionManager
        RegistrarEnBlackHole();

        Debug.Log($"[InicioNave] Nave {nave.name} iniciada");
    }

    /// <summary>
    /// Reinicia el estado de la nave
    /// </summary>
    public void ReiniciarNave()
    {
        if (nave != null)
        {
            // Desregistrar del BlackHole
            DesregistrarDeBlackHole();

            // Resetear componentes
            ShipController shipController = nave.GetComponent<ShipController>();
            if (shipController != null)
            {
                shipController.ResetMovement();
            }

            // Desactivar nave
            nave.SetActive(false);
            juegoIniciado = false;
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

    void OnDisable()
    {
        DesregistrarDeBlackHole();
    }

    void OnDestroy()
    {
        DesregistrarDeBlackHole();
    }
}