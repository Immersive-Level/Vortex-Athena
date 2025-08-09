// Assets/Scripts/Boton.cs

using UnityEngine;
using UnityEngine.UI;

public class Boton : MonoBehaviour
{
    public Fuel_System fuelSystem;         // Referencia al Fuel_System :contentReference[oaicite:2]{index=2}
    public ShipController shipController; // Controlador de movimiento

    bool isPressing = false;             // ¿Está presionando?
    bool canPress = true;              // ¿Puede acelerar?

    [Header("Tap Nudge")]
    public float tapThreshold = 0.15f;  // toques menores a este tiempo se consideran "tap"
    private float pressStartTime = 0f;


    void OnEnable()
    {
        // Al reaparecer, limpiamos estado interno
        canPress = fuelSystem.HasFuel;
        isPressing = false;
    }

    void Start()
    {
        // Suscripción al evento de tanque vacío
        fuelSystem.OnFuelEmpty += HandleFuelEmpty;
    }

    void Update()
    {
        // Si antes estaba bloqueado y ahora hay fuel, rearmamos
        if (!canPress && fuelSystem.HasFuel)
            canPress = true;

        // Mientras mantenga pulsado y pueda, consume
        if (isPressing && canPress)
        {
            fuelSystem.ConsumeFuel();
        }
    }

    // Llamado por PointerDown
    public void OnPress()
    {
        if (!canPress || !fuelSystem.HasFuel) return;
        isPressing = true;
        pressStartTime = Time.time;   // ← medir duración del toque
        shipController.StartMoving();
    }

    // Llamado por PointerUp
    public void OnRelease()
    {
        isPressing = false;
        shipController.StopMoving();

        float held = Time.time - pressStartTime;
        if (held <= tapThreshold)
        {
            // El “nudge” NO gasta combustible y ayuda a corregir rumbo
            shipController.TapNudge();
        }

    }

    // Se dispara cuando el tanque llega a cero
    void HandleFuelEmpty()
    {
        canPress = false;
        OnRelease();
    }
}

