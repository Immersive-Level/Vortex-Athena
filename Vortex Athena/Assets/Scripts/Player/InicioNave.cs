using UnityEngine;

public class InicioNave : MonoBehaviour
{
    public GameObject nave;  // Referencia a la nave
    public float impulsoInicial = 5f; // Fuerza del impulso inicial
    private bool juegoIniciado = false; // Controla si la nave ya apareci�
    [SerializeField] private BlackHoleAttractionManager blackHoleManager;

    void Start()
    {
        // Ocultar la nave al inicio
        nave.SetActive(false);

        // Obtener referencia al BlackHoleAttractionManager si no est� asignada
        if (blackHoleManager == null)
        {
            blackHoleManager = BlackHoleAttractionManager.Instance;

            if (blackHoleManager == null)
            {
                Debug.LogWarning("InicioNave: No se encontr� un BlackHoleAttractionManager. La atracci�n gravitacional podr�a no funcionar correctamente.");
            }
        }
    }

    void Update()
    {
        // Si el jugador presiona la tecla "1", iniciar el juego
        if (Input.GetKeyDown(KeyCode.Alpha1))
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

            // Asegurar que el Rigidbody2D est� en Dynamic para ser afectado por la gravedad
            Rigidbody2D rb = nave.GetComponent<Rigidbody2D>();
            rb.bodyType = RigidbodyType2D.Dynamic;
            rb.simulated = true;

            // Aplicar impulso inicial
            Vector2 direccionInicial = new Vector2(1, 1).normalized; // Ajustable
            rb.linearVelocity = direccionInicial * impulsoInicial; // Usamos velocity en vez de AddForce

            // Registrar expl�citamente la nave en el BlackHoleAttractionManager
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