using UnityEngine;
using UnityEngine.UI;


public class Fuel_System : MonoBehaviour
{

    public Image lineFuel; // Referencia a la imagen de la barra de combustible
    public float maxFuel = 100f; // Cantidad máxima de combustible
    public float fuelConsumptionRate = 10f; // Consumo de combustible por segundo

    private float currentFuel;

    [Header("Recolección de Recursos")]
    [Tooltip("Efecto visual al recolectar combustible")]
    public GameObject fuelCollectEffect;

    [Tooltip("Sonido al recolectar combustible")]
    public AudioClip fuelCollectSound;
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

    /// <summary>
    /// Añade combustible al jugador
    /// </summary>
    /// <param name="amount">Cantidad de combustible a añadir</param>
    public void AddFuel(float amount)
    {
        if (amount <= 0) return;

        // Aumentar combustible sin exceder el máximo
        currentFuel += amount;
        currentFuel = Mathf.Clamp(currentFuel, 0, maxFuel);

        // Actualizar la barra de combustible
        UpdateFuelBar();

        // Efectos visuales y sonoros
        if (fuelCollectEffect != null)
        {
            Instantiate(fuelCollectEffect, transform.position, Quaternion.identity);
        }

        if (fuelCollectSound != null)
        {
            AudioSource.PlayClipAtPoint(fuelCollectSound, transform.position);
        }
    }

    /// <summary>
    /// Obtiene el porcentaje actual de combustible
    /// </summary>
    /// <returns>Valor entre 0 y 1 que representa el porcentaje de combustible</returns>
    public float GetFuelPercentage()
    {
        return currentFuel / maxFuel;
    }

    /// <summary>
    /// Obtiene la cantidad actual de combustible
    /// </summary>
    /// <returns>Cantidad actual de combustible</returns>
    public float GetCurrentFuel()
    {
        return currentFuel;
    }
}
