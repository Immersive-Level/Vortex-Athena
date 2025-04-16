using UnityEngine;

public class CombatSystem : MonoBehaviour
{
    [HideInInspector] public ShipController shipController { get; private set; }
    [HideInInspector] public BlackHoleDeathHandler deathHandler { get; private set; }
    [HideInInspector] public Fuel_System fuelSystem { get; private set; }

    [Tooltip("valor de la fuerza del empujo contra el mapa o otras naves")]
    public float PushMagnitude;
    [Tooltip("Daño recibido al chocar")]
    public float CollideDamageValue;

    public Collider2D[] CollidersToIgnore;

    private void OnEnable()
    {
        shipController = GetComponent<ShipController>();
        deathHandler = GetComponent<BlackHoleDeathHandler>();
        fuelSystem = GetComponent<ResourceCollector>().fuelSystem; //Dolor T.T
    }

}
