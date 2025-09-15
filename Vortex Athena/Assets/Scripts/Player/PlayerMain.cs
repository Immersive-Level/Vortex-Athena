using UnityEngine;
using System;
using GameSystems;

[Serializable]
public class PlayerData
{
    public string ID { get; } = Guid.NewGuid().ToString();
    public string Name;
}

/// <summary>
/// Componente principal del jugador optimizado para BlackHoleCore
/// </summary>
public class PlayerMain : MonoBehaviour
{
    public PlayerData data;
    public GameObject ObjetoNave;

    [Header("Referencias Core")]
    public InicioNave InicioNave;
    public ShipController ShipController;
    public CombatSystem CombatSystem;
    public PlayerScoreSystem PlayerScoreSystem;
    public UnifiedDeathManager UnifiedDeathManager;
    public ResourceCollector ResourceCollector;
    public ShipInvulnerability ShipInvulnerability;
    public FuelManager FuelManager;
    public ShipInputController ShipInputController;
    public AbilityManager AbilityManager;

    [Header("Sistema de Gravedad")]
    public PlayerGravityHandler PlayerGravityHandler { get; private set; }

    private void Awake()
    {
        ValidateComponents();

        if (ObjetoNave != null)
        {
            PlayerGravityHandler = ObjetoNave.GetComponent<PlayerGravityHandler>();
            if (PlayerGravityHandler == null)
            {
                PlayerGravityHandler = ObjetoNave.AddComponent<PlayerGravityHandler>();
            }
        }
    }

    private void Start()
    {
        PlayerScoreSystem?.Initialize(this);

        if (ObjetoNave == null)
        {
            Debug.LogError($"PlayerMain {gameObject.name}: ObjetoNave is null!", this);
            return;
        }

        if (GameManager.Instance == null)
        {
            Debug.LogError($"PlayerMain {gameObject.name}: GameManager is null!", this);
            return;
        }
    }

    private void ValidateComponents()
    {
        if (FuelManager == null)
            Debug.LogWarning($"PlayerMain {gameObject.name}: FuelManager not found", this);

        if (UnifiedDeathManager == null)
            Debug.LogWarning($"PlayerMain {gameObject.name}: UnifiedDeathManager not found", this);

        if (ShipController == null)
            Debug.LogWarning($"PlayerMain {gameObject.name}: ShipController not found", this);

        if (ShipInputController == null)
            Debug.LogWarning($"PlayerMain {gameObject.name}: ShipInputController not found", this);

        if (PlayerGravityHandler == null)
        {
            PlayerGravityHandler = ObjetoNave?.GetComponent<PlayerGravityHandler>();
            if (PlayerGravityHandler == null)
                Debug.LogError($"PlayerMain {gameObject.name}: PlayerGravityHandler is critical for black hole interaction!", this);
        }
    }

    public bool IsAlive()
    {
        if (UnifiedDeathManager != null)
            return !UnifiedDeathManager.IsDead;
        return true;
    }

    public float GetFuelPercentage()
    {
        if (FuelManager != null)
            return FuelManager.FuelPercentage;
        return 0f;
    }

    public bool IsInGravityField()
    {
        if (PlayerGravityHandler != null)
            return PlayerGravityHandler.IsInGravityField;
        return false;
    }

    public bool IsInDangerZone()
    {
        if (PlayerGravityHandler != null)
            return PlayerGravityHandler.IsInDangerZone;
        return false;
    }

    public void ActivateEmergencyThrust(float duration = 2f)
    {
        if (PlayerGravityHandler != null && IsAlive())
        {
            PlayerGravityHandler.TriggerManualEmergencyThrust(duration);
        }
    }

    public float GetDistanceToBlackHole()
    {
        if (PlayerGravityHandler != null)
            return PlayerGravityHandler.GetDistanceToBlackHole();
        return float.MaxValue;
    }

    private void OnDestroy()
    {
        if (ObjetoNave != null && GameManager.Instance != null)
        {
            GameManager.Instance.RemoveRegisterShip(ObjetoNave);
        }
    }

    [System.Obsolete("Use PlayerGravityHandler instead of AffectedByBlackHole")]
    public PlayerGravityHandler AffectedByBlackHole => PlayerGravityHandler;
}