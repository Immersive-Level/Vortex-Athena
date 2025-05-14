using UnityEngine;
using UnityEngine.UI;
using System; // <- para Action


public class Fuel_System : MonoBehaviour
{

    public Image lineFuel; // Referencia a la imagen de la barra de combustible
    public float maxFuel = 100f; // Cantidad máxima de combustible
    public float fuelConsumptionRate = 10f; // Consumo de combustible por segundo

    private float currentFuel;

    public bool HasFuel => currentFuel > 0f;  // ¿Queda gasolina?

    // Evento que lanzamos al agotarse
    public event Action OnFuelEmpty;

    void Start()
    {
        currentFuel = maxFuel; // Inicia con el tanque lleno
        UpdateFuelBar();
    }

    public void ConsumeFuel()
    {
        
        
        if (currentFuel <= 0f) return;
        {
            currentFuel -= fuelConsumptionRate * Time.deltaTime;
            currentFuel = Mathf.Clamp(currentFuel, 0f, maxFuel);
            UpdateFuelBar();


            if (currentFuel <= 0f)
            {
                OnFuelEmpty?.Invoke();
            }

        }
    }

    void UpdateFuelBar()
    {
        lineFuel.fillAmount = currentFuel / maxFuel; // Actualiza el Fill Amount
    }
}
