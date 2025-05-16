using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.UI;

public class Boton : MonoBehaviour
{
    public Button ShipButton { get; private set; }

    private ShipMain _shipMain;
    private Fuel_System _fuelSystem;
    private ShipController _shipController;

    bool isPressing = false; // Para saber si el botón está presionado
    bool canPress = true;

    private void Start()
    {
        _shipMain = transform.parent.GetComponent<ShipMain>();

        if (_shipMain != null)
        {
            _fuelSystem = _shipMain.fuelSystem;
            _shipController = _shipMain.shipController;
        }

        ShipButton.OnPointerDown
    }

    void Update()
    {
        // Mientras el botón esté presionado y quede combustible, consumimos
        if (isPressing && canPress)
        {
            _fuelSystem.ConsumeFuel();

            // Si ya no queda nada, bloqueamos y detenemos
            if (_fuelSystem.lineFuel.fillAmount <= 0f)
            {
                canPress = false;
                OnRelease();

                // Ya no necesitamos este script activo
                enabled = false;
            }
        }
    }

    // Se llama cuando el jugador PRESIONA el botón
    public void OnPress()
    {
        if (!canPress || _fuelSystem.lineFuel.fillAmount <= 0f) return;

        isPressing = true;
        _shipController.StartMoving();
    }

    // Se llama cuando el jugador SUELTA el botón
    public void OnRelease()
    {
        isPressing = false;
        _shipController.StopMoving();
    }
}
