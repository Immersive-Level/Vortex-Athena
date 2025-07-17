using System.Collections.Generic;
using UnityEngine;

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
            Debug.LogError("[HabilityManager] PlayerMain is Null at " + transform.parent.name);
        }
    }

    public bool TryActivate(string morseCode)
    {
        if (_playerMain.BlackHoleDeathHandler.GetIsDead)
        {
            return false;
        }

        if (morseRegistry.TryGetValue(morseCode, out AbilityData ability))
        {
            Debug.Log($"Activating {ability.abilityName}");
            ability.Activate(gameObject);
            return true;
        }
        return false;
    }

}
