using UnityEngine;
using UnityEngine.UI;
using System; // <- para Action


public class Fuel_System : MonoBehaviour
{
    [HideInInspector] public BlackHoleDeathHandler deathHandler;

    public Image lineFuel; // Referencia a la imagen de la barra de combustible
    public float maxFuel = 100f; // Cantidad m�xima de combustible
    public float fuelConsumptionRate = 10f; // Consumo de combustible por segundo

    private float currentFuel;
    private float refuelTimer = 0f;

    [Header("Recolecci�n de Recursos")]
    [Tooltip("Efecto visual al recolectar combustible")]
    public GameObject fuelCollectEffect;

    [Tooltip("Sonido al recolectar combustible")]
    public AudioClip fuelCollectSound;
    public bool HasFuel => currentFuel > 0f;  // �Queda gasolina?

    // Evento que lanzamos al agotarse
    public event Action OnFuelEmpty;

    void Start()
    {
        currentFuel = maxFuel; // Inicia con el tanque lleno
        UpdateFuelBar();

        deathHandler = GetComponent<BlackHoleDeathHandler>();
    }

    private void LateUpdate()
    {
        refuelTimer += Time.deltaTime;
        if (refuelTimer >= 1f)
        {
            refuelTimer = 0f;
            AddFuel(1);
        }
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

    /// <summary>
    /// A�ade combustible al jugador
    /// </summary>
    /// <param name="amount">Cantidad de combustible a a�adir</param>   
    /// <param name="showEffects"> si se muestran los efectos, por defecto TRUE</param>
    public void AddFuel(float amount, bool showEffects = true)
    {
        if (amount <= 0) return;

        // Aumentar combustible sin exceder el m�ximo
        currentFuel += amount;
        currentFuel = Mathf.Clamp(currentFuel, 0, maxFuel);

        // Actualizar la barra de combustible
        UpdateFuelBar();

        //if (!showEffects) return;
        //// Efectos visuales y sonoros
        //if (fuelCollectEffect != null)
        //{
        //    Instantiate(fuelCollectEffect, transform.position, Quaternion.identity);
        //}

        //if (fuelCollectSound != null)
        //{
        //    AudioSource.PlayClipAtPoint(fuelCollectSound, transform.position);
        //}
    }

    /// <summary>
    /// Quita combustible al jugador
    /// </summary>
    /// <param name="amount"></param>
    public void RemoveFuel(float amount)
    {
        if (amount <= 0) return;

        currentFuel -= amount;
        currentFuel = Mathf.Clamp(currentFuel, 0, maxFuel);

        // Actualizar la barra de combustible
        UpdateFuelBar();

        if (deathHandler != null && currentFuel <= 0)
        {
            deathHandler.Death();
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
