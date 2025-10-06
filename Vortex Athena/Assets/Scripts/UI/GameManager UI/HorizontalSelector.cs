using System;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Selector horizontal personalizado con botones izquierda/derecha y texto central.
/// Componente reutilizable para cualquier tipo de selección en UI.
/// </summary>
public class HorizontalSelector : MonoBehaviour
{
    [Header("Referencias UI")]
    [Tooltip("Botón triángulo izquierdo para retroceder")]
    public Button botonIzquierda;

    [Tooltip("Botón triángulo derecho para avanzar")]
    public Button botonDerecha;

    [Tooltip("Texto central que muestra la opción actual")]
    public TextMeshProUGUI textoValor;

    [Header("Configuración")]
    [Tooltip("Opciones disponibles para mostrar")]
    public string[] opciones;

    [Tooltip("Índice inicial seleccionado (0 = primera opción)")]
    public int indiceInicial = 0;

    [Tooltip("¿Permitirループ circular? (última opción -> primera opción)")]
    public bool permitirLoop = true;

    // Índice actual seleccionado
    private int indiceActual;

    /// <summary>
    /// Evento que se dispara cuando cambia la selección.
    /// Parámetro: nuevo índice seleccionado
    /// </summary>
    public event Action<int> OnCambioSeleccion;

    /// <summary>
    /// Propiedad pública para obtener/establecer el índice actual
    /// </summary>
    public int IndiceActual
    {
        get => indiceActual;
        set
        {
            if (value >= 0 && value < opciones.Length)
            {
                indiceActual = value;
                ActualizarUI();
            }
        }
    }

    /// <summary>
    /// Obtiene el texto de la opción actual seleccionada
    /// </summary>
    public string OpcionActual => opciones[indiceActual];

    private void Start()
    {
        // Validar que tenemos opciones
        if (opciones == null || opciones.Length == 0)
        {
            Debug.LogError($"HorizontalSelector '{gameObject.name}': No hay opciones configuradas", this);
            return;
        }

        // Establecer índice inicial válido
        indiceActual = Mathf.Clamp(indiceInicial, 0, opciones.Length - 1);

        // Configurar listeners de botones
        if (botonIzquierda != null)
            botonIzquierda.onClick.AddListener(Retroceder);
        else
            Debug.LogWarning($"HorizontalSelector '{gameObject.name}': Botón izquierda no asignado", this);

        if (botonDerecha != null)
            botonDerecha.onClick.AddListener(Avanzar);
        else
            Debug.LogWarning($"HorizontalSelector '{gameObject.name}': Botón derecha no asignado", this);

        // Actualizar UI inicial
        ActualizarUI();
    }

    /// <summary>
    /// Avanza a la siguiente opción
    /// </summary>
    public void Avanzar()
    {
        int nuevoIndice = indiceActual + 1;

        // Si llegamos al final
        if (nuevoIndice >= opciones.Length)
        {
            // Loop circular o quedarse en el último
            nuevoIndice = permitirLoop ? 0 : opciones.Length - 1;
        }

        if (nuevoIndice != indiceActual)
        {
            indiceActual = nuevoIndice;
            ActualizarUI();
            OnCambioSeleccion?.Invoke(indiceActual);
        }
    }

    /// <summary>
    /// Retrocede a la opción anterior
    /// </summary>
    public void Retroceder()
    {
        int nuevoIndice = indiceActual - 1;

        // Si llegamos al principio
        if (nuevoIndice < 0)
        {
            // Loop circular o quedarse en el primero
            nuevoIndice = permitirLoop ? opciones.Length - 1 : 0;
        }

        if (nuevoIndice != indiceActual)
        {
            indiceActual = nuevoIndice;
            ActualizarUI();
            OnCambioSeleccion?.Invoke(indiceActual);
        }
    }

    /// <summary>
    /// Actualiza el texto en la UI con la opción actual
    /// </summary>
    private void ActualizarUI()
    {
        if (textoValor != null && opciones != null && indiceActual < opciones.Length)
        {
            textoValor.text = opciones[indiceActual];
        }

        // Opcional: Desactivar botones en los extremos si no hay loop
        if (!permitirLoop)
        {
            if (botonIzquierda != null)
                botonIzquierda.interactable = indiceActual > 0;

            if (botonDerecha != null)
                botonDerecha.interactable = indiceActual < opciones.Length - 1;
        }
    }

    /// <summary>
    /// Establece nuevas opciones dinámicamente (útil para configuraciones variables)
    /// </summary>
    public void EstablecerOpciones(string[] nuevasOpciones, int nuevoIndiceInicial = 0)
    {
        opciones = nuevasOpciones;
        indiceActual = Mathf.Clamp(nuevoIndiceInicial, 0, opciones.Length - 1);
        ActualizarUI();
    }

    private void OnDestroy()
    {
        // Limpiar listeners
        if (botonIzquierda != null)
            botonIzquierda.onClick.RemoveListener(Retroceder);

        if (botonDerecha != null)
            botonDerecha.onClick.RemoveListener(Avanzar);
    }
}