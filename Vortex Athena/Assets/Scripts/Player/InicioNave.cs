using UnityEngine;

public class InicioNave : MonoBehaviour
{
    public GameObject nave;  // Referencia a la nave
    public float impulsoInicial = 5f; // Fuerza del impulso inicial
    private bool juegoIniciado = false; // Controla si la nave ya apareció
    [SerializeField] private BlackHoleAttractionManager blackHoleManager;

    void Start()
    {
        // Ocultar la nave al inicio
        nave.SetActive(false);
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

            // Asegurar que el Rigidbody2D esté en Dynamic para ser afectado por la gravedad
            Rigidbody2D rb = nave.GetComponent<Rigidbody2D>();
            rb.bodyType = RigidbodyType2D.Dynamic;
            rb.simulated = true;

            // Aplicar impulso inicial
            Vector2 direccionInicial = new Vector2(1, 1).normalized; // Ajustable
            rb.linearVelocity = direccionInicial * impulsoInicial; // Usamos velocity en vez de AddForce

            blackHoleManager.FindAllAffectableObjects();
        }
    }
}
