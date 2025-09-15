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

    // ACTUALIZADO: Reemplazar AffectedByBlackHole con PlayerGravityHandler
    public PlayerGravityHandler PlayerGravityHandler; // NUEVO: Sistema de gravedad del jugador

    public UnifiedDeathManager UnifiedDeathManager;
    public ResourceCollector ResourceCollector;
    public ShipInvulnerability ShipInvulnerability;
    public FuelManager FuelManager;
    public ShipInputController ShipInputController;
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
    /// ACTUALIZADO: Incluye validación del nuevo PlayerGravityHandler
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

        // NUEVO: Validación del PlayerGravityHandler
        if (PlayerGravityHandler == null)
        {
            Debug.LogWarning($"[PlayerMain] {gameObject.name}: PlayerGravityHandler no encontrado - buscando automáticamente");
            PlayerGravityHandler = ObjetoNave?.GetComponent<PlayerGravityHandler>();

            if (PlayerGravityHandler == null)
                Debug.LogError($"[PlayerMain] {gameObject.name}: PlayerGravityHandler es crítico para la interacción con agujeros negros!");
        }
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

    /// <summary>
    /// NUEVO: Método de utilidad para obtener estado de gravedad
    /// </summary>
    public bool IsInGravityField()
    {
        if (PlayerGravityHandler != null)
            return PlayerGravityHandler.IsInGravityField;
        return false;
    }

    /// <summary>
    /// NUEVO: Método de utilidad para verificar zona de peligro
    /// </summary>
    public bool IsInDangerZone()
    {
        if (PlayerGravityHandler != null)
            return PlayerGravityHandler.IsInDangerZone;
        return false;
    }

    /// <summary>
    /// NUEVO: Método para activar empuje de emergencia manualmente
    /// </summary>
    public void ActivateEmergencyThrust(float duration = 2f)
    {
        if (PlayerGravityHandler != null && IsAlive())
        {
            PlayerGravityHandler.TriggerManualEmergencyThrust(duration);
        }
    }

    /// <summary>
    /// NUEVO: Método para obtener distancia al agujero negro
    /// </summary>
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

    // === MÉTODOS PARA COMPATIBILIDAD CON CÓDIGO EXISTENTE ===

    /// <summary>
    /// COMPATIBILIDAD: Para código que busque el antiguo AffectedByBlackHole
    /// </summary>
    [System.Obsolete("Use PlayerGravityHandler instead of AffectedByBlackHole")]
    public PlayerGravityHandler AffectedByBlackHole => PlayerGravityHandler;

    // === MÉTODOS DE DEBUG ===

#if UNITY_EDITOR
    [ContextMenu("Debug: Show Gravity Info")]
    private void DebugShowGravityInfo()
    {
        if (PlayerGravityHandler != null)
        {
            Debug.Log($"[PlayerMain] {gameObject.name} Gravity Info:\n" +
                      $"- In Gravity Field: {PlayerGravityHandler.IsInGravityField}\n" +
                      $"- In Danger Zone: {PlayerGravityHandler.IsInDangerZone}\n" +
                      $"- Gravity Intensity: {PlayerGravityHandler.CurrentGravityIntensity:F2}\n" +
                      $"- Emergency Thrust: {PlayerGravityHandler.EmergencyThrustActive}\n" +
                      $"- Distance to Black Hole: {PlayerGravityHandler.GetDistanceToBlackHole():F1}");
        }
        else
        {
            Debug.LogWarning($"[PlayerMain] {gameObject.name}: PlayerGravityHandler no encontrado");
        }
    }

    [ContextMenu("Debug: Test Emergency Thrust")]
    private void DebugTestEmergencyThrust()
    {
        ActivateEmergencyThrust(3f);
    }
#endif
}