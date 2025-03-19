using UnityEngine;

public class Boton : MonoBehaviour
{

    public Fuel_System fuelSystem; // Referencia al sistema de combustible
    private bool isPressing = false; // Para saber si el botón está presionado

    void Update()
    {
        // Si el botón está presionado, consume combustible
        if (isPressing)
        {
            fuelSystem.ConsumeFuel();
        }
    }

    // Se llama cuando el jugador PRESIONA el botón
    public void OnPress()
    {
        isPressing = true;
    }

    // Se llama cuando el jugador SUELTA el botón
    public void OnRelease()
    {
        isPressing = false;
    }

}
