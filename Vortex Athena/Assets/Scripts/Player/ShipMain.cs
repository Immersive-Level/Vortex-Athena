using UnityEngine;

public class ShipMain : MonoBehaviour
{
    public Boton BotonNave { get; private set; }

    [Header("Combat Systems")]
    public CombatSystem combatSystem { get; private set; }
    public ShipInvulnerability shipInvulnerability { get; private set; }
    public ComboSystem comboSystem { get; private set; }

    [Header("Fuel Systems")]
    public Fuel_System fuelSystem { get; private set; }

    [Header("BlackHole Systems")]
    public AffectedByBlackHole blackHoleEffect { get; private set; }
    public BlackHoleDeathHandler blackHoleDeathHandler { get; private set; }

    [Header("Score Systems")]
    public PlayerScoreSystem playerScoreSystem { get; private set; }

    [Header("Ship controller Systems")]
    public ShipController shipController { get; private set; }
    public InicioNave shipStart { get; private set; }

    [Header("Resources Systems")]
    public ResourceCollector collector { get; private set; }

}
