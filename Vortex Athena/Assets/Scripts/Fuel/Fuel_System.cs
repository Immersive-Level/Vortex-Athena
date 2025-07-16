// Assets/Scripts/Fuel_System.cs
using UnityEngine;
using UnityEngine.UI;
using System; // para Action

public class Fuel_System : MonoBehaviour
{
    [HideInInspector] public BlackHoleDeathHandler deathHandler;

    public Image lineFuel;                   // Barra UI de combustible :contentReference[oaicite:0]{index=0}
    public float maxFuel = 100f;             // Combustible máximo
    public float fuelConsumptionRate = 10f;  // Consumo por segundo

    private float currentFuel;
    public bool HasFuel => currentFuel > 0f; // ¿Queda combustible?

    // Evento que lanzamos cuando se acaba el combustible
    public event Action OnFuelEmpty;

    void Start()
    {
        currentFuel = maxFuel;
        UpdateFuelBar();
        deathHandler = GetComponent<BlackHoleDeathHandler>();
    }

    void OnEnable()
    {
        // Al reaparecer o reactivar la nave, recargamos al máximo
        currentFuel = maxFuel;
        UpdateFuelBar();
    }

    // ===== Se deshabilita la recarga automática por segundo =====
    // private float refuelTimer = 0f;
    // private void LateUpdate()
    // {
    //     refuelTimer += Time.deltaTime;
    //     if (refuelTimer >= 1f)
    //     {
    //         refuelTimer = 0f;
    //         AddFuel(1);
    //     }
    // }

    /// <summary>Consume combustible mientras aceleras</summary>
    public void ConsumeFuel()
    {
        if (currentFuel <= 0f) return;

        currentFuel -= fuelConsumptionRate * Time.deltaTime;
        currentFuel = Mathf.Clamp(currentFuel, 0f, maxFuel);
        UpdateFuelBar();

        if (currentFuel <= 0f)
            OnFuelEmpty?.Invoke();  // Disparar bloqueo inmediato
    }

    void UpdateFuelBar()
    {
        lineFuel.fillAmount = currentFuel / maxFuel;
    }

    /// <summary>Recolección de fuel pickups</summary>
    public void AddFuel(float amount, bool showEffects = true)
    {
        if (amount <= 0) return;
        currentFuel = Mathf.Clamp(currentFuel + amount, 0f, maxFuel);
        UpdateFuelBar();
        // ... efectos visuales/sonoros opcionales ...
    }

    /// <summary>Daño de choque contra entorno o naves</summary>
    public void RemoveFuel(float amount)
    {
        if (amount <= 0) return;
        currentFuel = Mathf.Clamp(currentFuel - amount, 0f, maxFuel);
        UpdateFuelBar();

        // Aseguramos que el evento se dispare al llegar a 0 incluso por choque :contentReference[oaicite:1]{index=1}
        if (currentFuel <= 0f)
            OnFuelEmpty?.Invoke();

        if (deathHandler != null && currentFuel <= 0f)
            deathHandler.Death();
    }

    /// <summary>Opcionales getters para debugging</summary>
    public float GetFuelPercentage() => currentFuel / maxFuel;
    public float GetCurrentFuel() => currentFuel;
}

