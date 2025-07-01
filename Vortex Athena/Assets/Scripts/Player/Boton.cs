using UnityEngine;
using UnityEngine.UI;

public class Boton : MonoBehaviour
{
    [Header("Referencias")]
    public Fuel_System fuelSystem; // Referencia al sistema de combustible
    public ShipController shipController; // Controlador de la nave

    [Header("Configuración Visual")]
    [Tooltip("Cambiar el color del botón cuando no hay combustible")]
    public bool changeColorOnEmpty = true;
    public Color normalColor = Color.white;
    public Color emptyFuelColor = new Color(0.5f, 0.5f, 0.5f, 0.5f);

    private Button uiButton; // Referencia al componente Button de UI
    private Image buttonImage; // Imagen del botón para cambiar color
    private bool isPressing = false; // Para saber si el botón está presionado
    private bool hasFuel = true; // Estado del combustible

    void Start()
    {
        // Obtener referencias de UI
        uiButton = GetComponent<Button>();
        buttonImage = GetComponent<Image>();

        // Validar referencias
        if (fuelSystem == null)
        {
            Debug.LogError("[Boton] Fuel_System no asignado!");
            enabled = false;
            return;
        }

        if (shipController == null)
        {
            Debug.LogError("[Boton] ShipController no asignado!");
            enabled = false;
            return;
        }

        // Suscribirse a eventos del sistema de combustible
        fuelSystem.OnFuelEmpty += OnFuelEmpty;
        fuelSystem.OnFuelRestored += OnFuelRestored;

        // Estado inicial
        hasFuel = fuelSystem.HasFuel;
        UpdateButtonVisual();
    }

    void OnDestroy()
    {
        // Desuscribirse de eventos para evitar referencias nulas
        if (fuelSystem != null)
        {
            fuelSystem.OnFuelEmpty -= OnFuelEmpty;
            fuelSystem.OnFuelRestored -= OnFuelRestored;
        }
    }

    void Update()
    {
        // Solo consumir si está presionado Y hay combustible
        if (isPressing && hasFuel)
        {
            // Intentar consumir combustible
            bool consumed = fuelSystem.ConsumeFuel();

            // Si no se pudo consumir (no hay combustible), soltar el botón
            if (!consumed)
            {
                OnRelease();
            }
        }
    }

    /// <summary>
    /// Se llama cuando el jugador PRESIONA el botón
    /// </summary>
    public void OnPress()
    {
        // Solo procesar si hay combustible
        if (!hasFuel || !fuelSystem.HasFuel)
        {
            Debug.Log("[Boton] No hay combustible disponible");
            return;
        }

        isPressing = true;
        shipController.StartMoving();
    }

    /// <summary>
    /// Se llama cuando el jugador SUELTA el botón
    /// </summary>
    public void OnRelease()
    {
        if (!isPressing) return;

        isPressing = false;
        shipController.StopMoving();
    }

    /// <summary>
    /// Manejador cuando se agota el combustible
    /// </summary>
    private void OnFuelEmpty()
    {
        hasFuel = false;

        // Forzar soltar el botón si está presionado
        if (isPressing)
        {
            OnRelease();
        }

        UpdateButtonVisual();
        Debug.Log("[Boton] Combustible agotado - Botón deshabilitado");
    }

    /// <summary>
    /// Manejador cuando se restaura el combustible
    /// </summary>
    private void OnFuelRestored()
    {
        hasFuel = true;
        UpdateButtonVisual();
        Debug.Log("[Boton] Combustible restaurado - Botón habilitado");
    }

    /// <summary>
    /// Actualiza el aspecto visual del botón según el estado del combustible
    /// </summary>
    private void UpdateButtonVisual()
    {
        if (!changeColorOnEmpty || buttonImage == null) return;

        // Cambiar color según estado
        buttonImage.color = hasFuel ? normalColor : emptyFuelColor;

        // Opcional: También se puede deshabilitar la interacción del botón UI
        if (uiButton != null)
        {
            uiButton.interactable = hasFuel;
        }
    }

    /// <summary>
    /// Método alternativo para verificar manualmente el estado del combustible
    /// </summary>
    public void CheckFuelStatus()
    {
        bool currentFuelStatus = fuelSystem.HasFuel;

        if (currentFuelStatus != hasFuel)
        {
            hasFuel = currentFuelStatus;

            if (!hasFuel)
            {
                OnFuelEmpty();
            }
            else
            {
                OnFuelRestored();
            }
        }
    }
}