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

    public bool TryActivate(string morseCode, GameObject invoker)
    {
        if (morseRegistry.TryGetValue(morseCode, out AbilityData ability))
        {
            ability.Activate(invoker);
            return true;
        }
        return false;
    }

}
