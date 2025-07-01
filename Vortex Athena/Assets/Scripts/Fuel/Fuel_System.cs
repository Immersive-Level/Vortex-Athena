using UnityEngine;
using UnityEngine.UI;
using System;

public class Fuel_System : MonoBehaviour
{
    [HideInInspector] public BlackHoleDeathHandler deathHandler;

    [Header("Configuración de Combustible")]
    public Image lineFuel; // Referencia a la imagen de la barra de combustible
    public float maxFuel = 100f; // Cantidad máxima de combustible
    public float fuelConsumptionRate = 10f; // Consumo de combustible por segundo

    [Header("Regeneración Automática")]
    [Tooltip("¿Se regenera el combustible automáticamente?")]
    public bool autoRegenEnabled = false;
    [Tooltip("Cantidad de combustible regenerado por segundo")]
    public float autoRegenRate = 1f;

    private float currentFuel;
    private float refuelTimer = 0f;

    [Header("Recolección de Recursos")]
    [Tooltip("Efecto visual al recolectar combustible")]
    public GameObject fuelCollectEffect;
    [Tooltip("Sonido al recolectar combustible")]
    public AudioClip fuelCollectSound;

    // Propiedad pública para verificar si hay combustible
    public bool HasFuel => currentFuel > 0f;

    // Eventos
    public event Action OnFuelEmpty;
    public event Action OnFuelRestored; // Nuevo evento cuando se recupera combustible

    void Start()
    {
        currentFuel = maxFuel; // Inicia con el tanque lleno
        UpdateFuelBar();

        deathHandler = GetComponent<BlackHoleDeathHandler>();
    }

    void LateUpdate()
    {
        // Solo regenerar si está habilitado
        if (autoRegenEnabled && currentFuel < maxFuel)
        {
            refuelTimer += Time.deltaTime;
            if (refuelTimer >= 1f)
            {
                refuelTimer = 0f;
                AddFuel(autoRegenRate, false); // Sin efectos visuales
            }
        }
    }

    /// <summary>
    /// Consume combustible si hay disponible
    /// </summary>
    /// <returns>True si se pudo consumir, False si no hay combustible</returns>
    public bool ConsumeFuel()
    {
        // Si no hay combustible, no consumir
        if (currentFuel <= 0f)
        {
            currentFuel = 0f; // Asegurar que no sea negativo
            UpdateFuelBar();
            return false;
        }

        // Consumir combustible
        currentFuel -= fuelConsumptionRate * Time.deltaTime;
        currentFuel = Mathf.Clamp(currentFuel, 0f, maxFuel);
        UpdateFuelBar();

        // Verificar si se agotó el combustible
        if (currentFuel <= 0f && HasFuel == false)
        {
            OnFuelEmpty?.Invoke();
        }

        return true;
    }

    void UpdateFuelBar()
    {
        if (lineFuel != null)
        {
            lineFuel.fillAmount = currentFuel / maxFuel;
        }
    }

    /// <summary>
    /// Añade combustible al jugador
    /// </summary>
    public void AddFuel(float amount, bool showEffects = true)
    {
        if (amount <= 0) return;

        bool wasEmpty = !HasFuel;

        // Aumentar combustible sin exceder el máximo
        currentFuel += amount;
        currentFuel = Mathf.Clamp(currentFuel, 0, maxFuel);

        // Actualizar la barra de combustible
        UpdateFuelBar();

        // Si estaba vacío y ahora tiene combustible, lanzar evento
        if (wasEmpty && HasFuel)
        {
            OnFuelRestored?.Invoke();
        }

        // Efectos visuales y sonoros
        if (showEffects)
        {
            if (fuelCollectEffect != null)
            {
                Instantiate(fuelCollectEffect, transform.position, Quaternion.identity);
            }

            if (fuelCollectSound != null)
            {
                AudioSource.PlayClipAtPoint(fuelCollectSound, transform.position);
            }
        }
    }

    /// <summary>
    /// Quita combustible al jugador
    /// </summary>
    public void RemoveFuel(float amount)
    {
        if (amount <= 0) return;

        currentFuel -= amount;
        currentFuel = Mathf.Clamp(currentFuel, 0, maxFuel);

        // Actualizar la barra de combustible
        UpdateFuelBar();

        // Verificar si se agotó
        if (currentFuel <= 0)
        {
            OnFuelEmpty?.Invoke();

            if (deathHandler != null)
            {
                deathHandler.Death();
            }
        }
    }

    /// <summary>
    /// Obtiene el porcentaje actual de combustible
    /// </summary>
    public float GetFuelPercentage()
    {
        return currentFuel / maxFuel;
    }

    /// <summary>
    /// Obtiene la cantidad actual de combustible
    /// </summary>
    public float GetCurrentFuel()
    {
        return currentFuel;
    }

    /// <summary>
    /// Establece el combustible actual (útil para debug o mecánicas especiales)
    /// </summary>
    public void SetFuel(float amount)
    {
        bool wasEmpty = !HasFuel;

        currentFuel = Mathf.Clamp(amount, 0, maxFuel);
        UpdateFuelBar();

        if (currentFuel <= 0)
        {
            OnFuelEmpty?.Invoke();
        }
        else if (wasEmpty && HasFuel)
        {
            OnFuelRestored?.Invoke();
        }
    }
}