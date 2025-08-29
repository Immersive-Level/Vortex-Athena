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
    public InicioNave InicioNave;
    public ShipController ShipController;
    public CombatSystem CombatSystem;
    public PlayerScoreSystem PlayerScoreSystem;
    public AffectedByBlackHole AffectedByBlackHole;
    public UnifiedDeathManager UnifiedDeathManager; // CAMBIADO
    public ResourceCollector ResourceCollector;
    public ShipInvulnerability ShipInvulnerability;
    public FuelManager FuelManager; // CAMBIADO
    public ShipInputController ShipInputController; // NUEVO
    public AbilityManager AbilityManager;

    private void Awake()
    {
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