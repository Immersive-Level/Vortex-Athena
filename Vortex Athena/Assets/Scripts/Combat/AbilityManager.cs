using System.Collections.Generic;
using UnityEngine;
using GameSystems; // Para acceder a UnifiedDeathManager

public static class MorseDictionary
{
    public static readonly Dictionary<string, string> AlphabetToMorse = new()
    {
        { "A", "·-" }, { "B", "-···" }, { "C", "-·-·" }, { "D", "-··" },
        { "E", "·" }, { "F", "··-·" }, { "G", "--·" }, { "H", "····" },
        { "I", "··" }, { "J", "·---" }, { "K", "-·-" }, { "L", "·-··" },
        { "M", "--" }, { "N", "-·" }, { "O", "---" }, { "P", "·--·" },
        { "Q", "--·-" }, { "R", "·-·" }, { "S", "···" }, { "T", "-" },
        { "U", "··-" }, { "V", "···-" }, { "W", "·--" }, { "X", "-··-" },
        { "Y", "-·--" }, { "Z", "--··" }
    };
}

public enum MorseLetter
{
    A, B, C, D, E, F, G, H, I, J,
    K, L, M, N, O, P, Q, R, S, T,
    U, V, W, X, Y, Z
}


public class AbilityManager : MonoBehaviour
{
    [SerializeField] public List<LetterAbility> abilityBindings;

    private Dictionary<string, AbilityData> morseRegistry = new();

    private PlayerMain _playerMain;
    private UnifiedDeathManager _deathManager; // NUEVO: Referencia directa al death manager

    void Awake()
    {
        foreach (var item in abilityBindings)
        {
            string letterStr = item.letter.ToString();
            if (MorseDictionary.AlphabetToMorse.TryGetValue(letterStr, out string morseCode))
            {
                morseRegistry[morseCode] = item.ability;
            }
            else
            {
                Debug.LogWarning($"Letra inválida: {letterStr}");
            }
        }
    }

    private void Start()
    {
        _playerMain = transform.parent.GetComponent<PlayerMain>();
        if (_playerMain == null)
        {
            Debug.LogError("[AbilityManager] PlayerMain is Null at " + transform.parent.name);
        }

        // NUEVO: Obtener referencia al UnifiedDeathManager
        _deathManager = _playerMain?.UnifiedDeathManager;
        if (_deathManager == null)
        {
            // Buscar en el mismo GameObject o en los hijos
            _deathManager = GetComponent<UnifiedDeathManager>();
            if (_deathManager == null)
                _deathManager = GetComponentInParent<UnifiedDeathManager>();
            if (_deathManager == null)
                _deathManager = GetComponentInChildren<UnifiedDeathManager>();
        }

        if (_deathManager == null)
        {
            Debug.LogWarning("[AbilityManager] UnifiedDeathManager no encontrado, las habilidades no verificarán el estado de muerte");
        }
    }

    public bool TryActivate(string morseCode)
    {
        // ACTUALIZADO: Usar el nuevo UnifiedDeathManager
        if (_deathManager != null && _deathManager.IsDead)
        {
            Debug.Log("[AbilityManager] No se puede activar habilidad - jugador muerto");
            return false;
        }

        if (morseRegistry.TryGetValue(morseCode, out AbilityData ability))
        {
            Debug.Log($"[AbilityManager] Activando {ability.abilityName}");
            ability.Activate(gameObject);
            return true;
        }

        Debug.Log($"[AbilityManager] Código morse no reconocido: {morseCode}");
        return false;
    }

    /// <summary>
    /// Método de utilidad para verificar si el jugador está vivo
    /// </summary>
    public bool IsPlayerAlive()
    {
        if (_deathManager != null)
            return !_deathManager.IsDead;

        // Si no hay death manager, asumimos que está vivo
        return true;
    }

    /// <summary>
    /// Obtiene una habilidad por su código morse
    /// </summary>
    public AbilityData GetAbilityByMorse(string morseCode)
    {
        if (morseRegistry.TryGetValue(morseCode, out AbilityData ability))
            return ability;
        return null;
    }

    /// <summary>
    /// Obtiene una habilidad por su letra
    /// </summary>
    public AbilityData GetAbilityByLetter(MorseLetter letter)
    {
        string letterStr = letter.ToString();
        if (MorseDictionary.AlphabetToMorse.TryGetValue(letterStr, out string morseCode))
        {
            return GetAbilityByMorse(morseCode);
        }
        return null;
    }
}