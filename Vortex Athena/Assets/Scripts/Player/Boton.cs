using UnityEngine;

public class Boton : MonoBehaviour
{

    public Fuel_System fuelSystem; // Referencia al sistema de combustible
    private bool isPressing = false; // Para saber si el bot�n est� presionado

    void Update()
    {
        // Si el bot�n est� presionado, consume combustible
        if (isPressing)
        {
            fuelSystem.ConsumeFuel();
        }
    }

    // Se llama cuando el jugador PRESIONA el bot�n
    public void OnPress()
    {
        isPressing = true;
    }

    // Se llama cuando el jugador SUELTA el bot�n
    public void OnRelease()
    {
        isPressing = false;
    }

}
