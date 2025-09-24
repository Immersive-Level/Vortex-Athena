using UnityEngine;
using GameSystems;

/// <summary>
/// Validador simplificado para verificar configuración correcta del sistema BlackHole
/// </summary>
public class SystemValidator : MonoBehaviour
{
    [Header("Validation Settings")]
    [SerializeField] private bool validateOnStart = true;

    [Header("System References")]
    [SerializeField, ReadOnly] private BlackHoleCore blackHoleCore;
    [SerializeField, ReadOnly] private int playersFound;
    [SerializeField, ReadOnly] private int playersValid;

    private void Start()
    {
        if (validateOnStart)
        {
            ValidateSystem();
        }
    }

    [ContextMenu("Validate System")]
    public void ValidateSystem()
    {
        bool systemValid = true;

        systemValid &= ValidateBlackHole();
        systemValid &= ValidatePlayers();

        if (systemValid)
        {
            Debug.Log("[SystemValidator] System validation PASSED - All components functional");
        }
        else
        {
            Debug.LogError("[SystemValidator] System validation FAILED - Check error messages above");
        }
    }

    private bool ValidateBlackHole()
    {
        blackHoleCore = FindAnyObjectByType<BlackHoleCore>();
        if (blackHoleCore == null)
        {
            Debug.LogError("[SystemValidator] BlackHoleCore not found in scene");
            return false;
        }

        // Verify required components
        if (blackHoleCore.GetComponent<BlackHoleGravityProcessor>() == null)
        {
            Debug.LogError("[SystemValidator] BlackHoleCore missing BlackHoleGravityProcessor");
            return false;
        }

        if (blackHoleCore.GetComponent<BlackHoleZoneManager>() == null)
        {
            Debug.LogError("[SystemValidator] BlackHoleCore missing BlackHoleZoneManager");
            return false;
        }

        var collider = blackHoleCore.GetComponent<CircleCollider2D>();
        if (collider == null || !collider.isTrigger)
        {
            Debug.LogError("[SystemValidator] BlackHoleCore requires CircleCollider2D as trigger");
            return false;
        }

        return true;
    }

    private bool ValidatePlayers()
    {
        var playerMains = FindObjectsByType<PlayerMain>(FindObjectsSortMode.None);
        playersFound = playerMains.Length;
        playersValid = 0;

        if (playerMains.Length == 0)
        {
            Debug.LogError("[SystemValidator] No PlayerMain components found");
            return false;
        }

        foreach (var playerMain in playerMains)
        {
            if (ValidatePlayer(playerMain))
            {
                playersValid++;
            }
        }

        return playersValid == playersFound;
    }

    private bool ValidatePlayer(PlayerMain playerMain)
    {
        if (playerMain.ObjetoNave == null)
        {
            Debug.LogError($"[SystemValidator] {playerMain.name} has no ObjetoNave");
            return false;
        }

        var gravityHandler = playerMain.ObjetoNave.GetComponent<PlayerGravityHandler>();
        if (gravityHandler == null)
        {
            Debug.LogError($"[SystemValidator] {playerMain.name} missing PlayerGravityHandler");
            return false;
        }

        if (gravityHandler.Rigidbody == null)
        {
            Debug.LogError($"[SystemValidator] {playerMain.name} PlayerGravityHandler has no Rigidbody2D");
            return false;
        }

        return true;
    }

    [ContextMenu("Auto-Fix Common Issues")]
    public void AutoFixIssues()
    {
        // Add missing PlayerGravityHandler components
        var playerMains = FindObjectsByType<PlayerMain>(FindObjectsSortMode.None);
        foreach (var playerMain in playerMains)
        {
            if (playerMain.ObjetoNave != null)
            {
                var gravityHandler = playerMain.ObjetoNave.GetComponent<PlayerGravityHandler>();
                if (gravityHandler == null)
                {
                    playerMain.ObjetoNave.AddComponent<PlayerGravityHandler>();
                    Debug.Log($"[SystemValidator] Added PlayerGravityHandler to {playerMain.name}");
                }
            }
        }

        Debug.Log("[SystemValidator] Auto-fix completed");
    }
}