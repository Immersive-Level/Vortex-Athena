using UnityEngine;

public class InicioNave : MonoBehaviour
{
    public GameObject nave;  // Referencia a la nave
    public float impulsoInicial = 5f; // Fuerza del impulso inicial
    public Vector2 direccionImpulso = new Vector2(1, 1); // Dirección ajustable desde el Inspector
    public KeyCode teclaInicio = KeyCode.Alpha1; // Tecla para iniciar la nave (ajustable)

    private bool juegoIniciado = false; // Controla si la nave ya apareció
    [SerializeField] private BlackHoleAttractionManager blackHoleManager;

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
                Debug.LogWarning("InicioNave: No se encontró un BlackHoleAttractionManager. La atracción gravitacional podría no funcionar correctamente.");
            }
        }
    }

    void Update()
    {
        // Si el jugador presiona la tecla "1", iniciar el juego
        if (Input.GetKeyDown(teclaInicio))
        {
            IniciarJuego();
        }
    }

    public void IniciarJuego()
    {
        if (!juegoIniciado)
        {
            juegoIniciado = true;

            // Activar la nave
            nave.SetActive(true);

            // Asegurar que el Rigidbody2D esté en Dynamic para ser afectado por la gravedad
            Rigidbody2D rb = nave.GetComponent<Rigidbody2D>();
            rb.bodyType = RigidbodyType2D.Dynamic;
            rb.simulated = true;

            // Aplicar impulso inicial
            Vector2 direccionInicial = direccionImpulso.normalized; // Ajustable
            rb.linearVelocity = direccionInicial * impulsoInicial; // Usamos velocity en vez de AddForce

            // Registrar explícitamente la nave en el BlackHoleAttractionManager
            if (blackHoleManager != null)
            {
                AffectedByBlackHole affected = nave.GetComponent<AffectedByBlackHole>();
                if (affected != null)
                {
                    blackHoleManager.RegisterAffectableObject(affected);
                    Debug.Log("Nave registrada en BlackHoleAttractionManager");
                }
                else
                {
                    Debug.LogWarning("InicioNave: La nave no tiene el componente AffectedByBlackHole");
                }
            }
        }
    }

    // Si la nave se destruye o desactiva, desregistrarla
    void OnDisable()
    {
        if (blackHoleManager != null && nave != null)
        {
            AffectedByBlackHole affected = nave.GetComponent<AffectedByBlackHole>();
            if (affected != null)
            {
                blackHoleManager.UnregisterAffectableObject(affected);
                Debug.Log("Nave desregistrada del BlackHoleAttractionManager");
            }
        }
    }
}