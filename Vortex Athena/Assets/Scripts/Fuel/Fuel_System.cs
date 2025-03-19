using UnityEngine;
using UnityEngine.UI;


public class Fuel_System : MonoBehaviour
{

    public Image lineFuel; // Referencia a la imagen de la barra de combustible
    public float maxFuel = 100f; // Cantidad máxima de combustible
    public float fuelConsumptionRate = 10f; // Consumo de combustible por segundo

    private float currentFuel;

    void Start()
    {
        currentFuel = maxFuel; // Inicia con el tanque lleno
        UpdateFuelBar();
    }

    public void ConsumeFuel()
    {
        if (currentFuel > 0)
        {
            currentFuel -= fuelConsumptionRate * Time.deltaTime;
            currentFuel = Mathf.Clamp(currentFuel, 0, maxFuel);
            UpdateFuelBar();
        }
    }

    void UpdateFuelBar()
    {
        lineFuel.fillAmount = currentFuel / maxFuel; // Actualiza el Fill Amount
    }
}
