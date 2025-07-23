using UnityEngine;

public class CombatSystem : MonoBehaviour
{
    [HideInInspector] public ShipController shipController { get; private set; }
    [HideInInspector] public BlackHoleDeathHandler deathHandler { get; private set; }
    [HideInInspector] public Fuel_System fuelSystem { get; private set; }

    [Tooltip("valor de la fuerza del empujo contra el mapa o otras naves")]
    public float PushMagnitude;
    [Range(0, 100)]
    [Tooltip("valor del slow contra otras naves")]
    public float SlowMagnitude = 35;
    [Tooltip("Daño recibido al chocar")]
    public float CollideDamageValue;
    public bool IsInvencible { get; set; }
    public Collider2D[] CollidersToIgnore;

    public ShieldController Shield;

    private void OnEnable()
    {
        shipController = GetComponent<ShipController>();
        deathHandler = GetComponent<BlackHoleDeathHandler>();
        fuelSystem = GetComponent<Fuel_System>();
    }

    public void Kill()
    {
        if (IsInvencible) return;

        deathHandler?.Death();
    }

}
