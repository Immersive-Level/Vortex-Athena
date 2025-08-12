using UnityEngine;
using System;
using GameSystems; // Para acceder a los nuevos sistemas
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

    // Referencias a los componentes
    public InicioNave InicioNave { get; private set; }
    public ShipController ShipController { get; private set; }
    public CombatSystem CombatSystem { get; private set; }
    public PlayerScoreSystem PlayerScoreSystem { get; private set; }
    public AffectedByBlackHole AffectedByBlackHole { get; private set; }
    public UnifiedDeathManager UnifiedDeathManager { get; private set; } // CAMBIADO
    public ResourceCollector ResourceCollector { get; private set; }
    public ShipInvulnerability ShipInvulnerability { get; private set; }
    public FuelManager FuelManager { get; private set; } // CAMBIADO
    public ShipInputController ShipInputController { get; private set; } // NUEVO
    public AbilityManager AbilityManager { get; private set; }

    private void Awake()
    {
        // Buscar componentes en los hijos
        InicioNave = GetComponentInChildren<InicioNave>();
        ShipController = GetComponentInChildren<ShipController>();
        CombatSystem = GetComponentInChildren<CombatSystem>();
        PlayerScoreSystem = GetComponentInChildren<PlayerScoreSystem>();
        AffectedByBlackHole = GetComponentInChildren<AffectedByBlackHole>();

        // Buscar nuevos componentes
        UnifiedDeathManager = GetComponentInChildren<UnifiedDeathManager>();
        FuelManager = GetComponentInChildren<FuelManager>();
        ShipInputController = GetComponentInChildren<ShipInputController>();

        // Componentes existentes
        ResourceCollector = GetComponentInChildren<ResourceCollector>();
        ShipInvulnerability = GetComponentInChildren<ShipInvulnerability>();
        AbilityManager = GetComponentInChildren<AbilityManager>();

        // Validación de componentes críticos
        ValidateComponents();
    }

    private void Start()
    {
        PlayerScoreSystem?.Initialize(this);

        if (ObjetoNave == null)
        {
            Debug.LogError($"[PlayerMain] {gameObject.name}: ObjetoNave is Null!!");
            return;
        }

        if (GameManager.Instance == null)
        {
            Debug.LogError($"[PlayerMain] {gameObject.name}: GameManager is Null!!");
            return;
        }
    }

    /// <summary>
    /// Valida que los componentes críticos estén presentes
    /// </summary>
    private void ValidateComponents()
    {
        if (FuelManager == null)
            Debug.LogWarning($"[PlayerMain] {gameObject.name}: FuelManager no encontrado");

        if (UnifiedDeathManager == null)
            Debug.LogWarning($"[PlayerMain] {gameObject.name}: UnifiedDeathManager no encontrado");

        if (ShipController == null)
            Debug.LogWarning($"[PlayerMain] {gameObject.name}: ShipController no encontrado");

        if (ShipInputController == null)
            Debug.LogWarning($"[PlayerMain] {gameObject.name}: ShipInputController no encontrado");
    }

    /// <summary>
    /// Método de utilidad para obtener si el jugador está vivo
    /// </summary>
    public bool IsAlive()
    {
        if (UnifiedDeathManager != null)
            return !UnifiedDeathManager.IsDead;
        return true;
    }

    /// <summary>
    /// Método de utilidad para obtener el porcentaje de combustible
    /// </summary>
    public float GetFuelPercentage()
    {
        if (FuelManager != null)
            return FuelManager.FuelPercentage;
        return 0f;
    }

    private void OnDestroy()
    {
        if (ObjetoNave != null && GameManager.Instance != null)
        {
            GameManager.Instance.RemoveRegisterShip(ObjetoNave);
        }
    }
}