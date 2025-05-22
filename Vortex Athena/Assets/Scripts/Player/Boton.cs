using UnityEngine;
using UnityEngine.UI;

public class Boton : MonoBehaviour
{

    public Fuel_System fuelSystem; // Referencia al sistema de combustible
    public ShipController shipController; // Controlador de la nave

    bool isPressing = false; // Para saber si el botón está presionado
    bool canPress = true;


    void Update()
    {
        // Mientras el botón esté presionado y quede combustible, consumimos
        if (isPressing && canPress)
        {
            fuelSystem.ConsumeFuel();

            // Si ya no queda nada, bloqueamos y detenemos
            if (fuelSystem.lineFuel.fillAmount <= 0f)
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
        if (!canPress || fuelSystem.lineFuel.fillAmount <= 0f) return;

        isPressing = true;
        shipController.StartMoving();
    }

    // Se llama cuando el jugador SUELTA el botón
    public void OnRelease()
    {
        isPressing = false;
        shipController.StopMoving();
    }
}
