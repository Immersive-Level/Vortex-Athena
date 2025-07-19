using UnityEngine;
using System;
using Newtonsoft.Json.Linq;
using UnityEngine.UIElements;

[Serializable]
public class PlayerData
{
    public string ID { get; } = Guid.NewGuid().ToString();
    public string Name;
}

public class PlayerMain : MonoBehaviour
{
    public PlayerData data;
    public GameObject ObjetoNave;
    public InicioNave InicioNave { get; private set; }
    public ShipController ShipController { get; private set; }
    public CombatSystem CombatSystem { get; private set; }
    public PlayerScoreSystem PlayerScoreSystem { get; private set; }
    public AffectedByBlackHole AffectedByBlackHole { get; private set; }
    public BlackHoleDeathHandler BlackHoleDeathHandler { get; private set; }
    public ResourceCollector ResourceCollector { get; private set; }
    public ShipInvulnerability ShipInvulnerability { get; private set; }
    public Fuel_System Fuel_System { get; private set; }
    public AbilityManager AbilityManager { get; private set; }



    private void Awake()
    {
        InicioNave = GetComponentInChildren<InicioNave>();
        ShipController = GetComponentInChildren<ShipController>();
        CombatSystem = GetComponentInChildren<CombatSystem>();
        PlayerScoreSystem = GetComponentInChildren<PlayerScoreSystem>();
        AffectedByBlackHole = GetComponentInChildren<AffectedByBlackHole>();
        BlackHoleDeathHandler = GetComponentInChildren<BlackHoleDeathHandler>();
        ResourceCollector = GetComponentInChildren<ResourceCollector>();
        ShipInvulnerability = GetComponentInChildren<ShipInvulnerability>();
        Fuel_System = GetComponentInChildren<Fuel_System>();
        AbilityManager = GetComponentInChildren<AbilityManager>();
    }

    private void Start()
    {
        PlayerScoreSystem.Initialize(this);

        if (ObjetoNave != null)
        {
            GameManager.Instance.RegisterShip(ObjetoNave);
        }
    }

    private void OnDestroy()
    {
        if (ObjetoNave != null)
        {
            GameManager.Instance.RemoveRegisterShip(ObjetoNave);
        }
    }

}
