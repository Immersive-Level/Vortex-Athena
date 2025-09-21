using System.Collections.Generic;
using UnityEngine;
using GameSystems;            // Para verificar muerte con UnifiedDeathManager
using UnityEngine.Events;    // Para exponer eventos en el Inspector

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

/// <summary>
/// Entrada de SFX por habilidad: se sincroniza con abilityBindings.
/// Arrastra aquí tu objeto SFX (instancia en escena) y elige Play/Trigger/PlayRandom.
/// </summary>
[System.Serializable]
public class AbilitySfxEntry
{
    public MorseLetter letter;
    [Tooltip("Se invoca cuando ESTA habilidad se activa correctamente.")]
    public UnityEvent onActivatedSfx;
}

public class AbilityManager : MonoBehaviour
{
    [Header("Bindings (letra → Ability)")]
    [SerializeField] public List<LetterAbility> abilityBindings;

    // Registro morse → Ability y morse → letra para lookup rápido
    private readonly Dictionary<string, AbilityData> morseToAbility = new();
    private readonly Dictionary<string, MorseLetter> morseToLetter = new();

    private PlayerMain _playerMain;
    private UnifiedDeathManager _deathManager;

    [Header("Audio")]
    [Tooltip("Se invoca SIEMPRE que cualquier habilidad se activa con éxito (además del SFX por-habilidad).")]
    public UnityEvent onSfxAbilityActivatedGlobal;

    [Tooltip("Lista auto-sincronizada con abilityBindings. Aquí asignas el sonido específico por habilidad.")]
    public List<AbilitySfxEntry> perAbilitySfx = new();

    [Tooltip("Mantener sincronizada perAbilitySfx con abilityBindings automáticamente.")]
    [SerializeField] private bool autoSyncSfxList = true;

    void Awake()
    {
        // Construir registros morse → ability y morse → letra
        morseToAbility.Clear();
        morseToLetter.Clear();

        foreach (var item in abilityBindings)
        {
            string letterStr = item.letter.ToString();
            if (MorseDictionary.AlphabetToMorse.TryGetValue(letterStr, out string morseCode))
            {
                morseToAbility[morseCode] = item.ability;
                morseToLetter[morseCode] = item.letter;
            }
            else
            {
                Debug.LogWarning($"[AbilityManager] Letra inválida en bindings: {letterStr}");
            }
        }

        if (autoSyncSfxList)
            SyncPerAbilitySfxWithBindings();
    }

    private void Start()
    {
        _playerMain = transform.parent.GetComponent<PlayerMain>();
        if (_playerMain == null)
            Debug.LogError("[AbilityManager] PlayerMain is Null at " + transform.parent.name);

        // Buscar UnifiedDeathManager para bloquear activación si el jugador está muerto
        _deathManager = _playerMain?.UnifiedDeathManager;
        if (_deathManager == null)
        {
            _deathManager = GetComponent<UnifiedDeathManager>()
                         ?? GetComponentInParent<UnifiedDeathManager>()
                         ?? GetComponentInChildren<UnifiedDeathManager>();
        }
        if (_deathManager == null)
            Debug.LogWarning("[AbilityManager] UnifiedDeathManager no encontrado; no se verificará estado de muerte.");
    }

    /// <summary>
    /// Intenta activar una habilidad a partir del código morse.
    /// Dispara SFX global y SFX específico por habilidad si procede.
    /// </summary>
    public bool TryActivate(string morseCode)
    {
        // Gate global: habilidades activadas en GameManager
        if (!GameManager.Instance.UseAbilities) return false;  // no suena nada

        // Gate por estado de muerte
        if (_deathManager != null && _deathManager.IsDead)
        {
            // jugador muerto: no activar ni sonar
            return false;
        }

        if (morseToAbility.TryGetValue(morseCode, out AbilityData ability))
        {
            ability.Activate(gameObject);

            // SFX global (uno para todas)
            onSfxAbilityActivatedGlobal?.Invoke();

            // SFX por-habilidad (según la letra asociada a este código)
            if (morseToLetter.TryGetValue(morseCode, out MorseLetter letter))
                InvokePerAbilitySfx(letter);

            return true;
        }

        // Código inválido: no activar ni sonar (como pediste, solo AbilityActivated)
        return false;
    }

    /// <summary> Útil para otras partes del juego. </summary>
    public bool IsPlayerAlive()
    {
        if (_deathManager != null) return !_deathManager.IsDead;
        return true;
    }

    /// <summary> Obtiene una habilidad por su código morse. </summary>
    public AbilityData GetAbilityByMorse(string morseCode)
    {
        if (morseToAbility.TryGetValue(morseCode, out AbilityData ability))
            return ability;
        return null;
    }

    /// <summary> Obtiene una habilidad por su letra. </summary>
    public AbilityData GetAbilityByLetter(MorseLetter letter)
    {
        string letterStr = letter.ToString();
        if (MorseDictionary.AlphabetToMorse.TryGetValue(letterStr, out string morseCode))
            return GetAbilityByMorse(morseCode);
        return null;
    }

    // ---------- Audio por-habilidad ----------

    /// <summary>
    /// Sincroniza la lista de SFX por-habilidad con abilityBindings:
    /// crea entradas faltantes, conserva las existentes y elimina las que ya no estén.
    /// </summary>
    private void SyncPerAbilitySfxWithBindings()
    {
        // Construir set de letras presentes en abilityBindings
        var wanted = new HashSet<MorseLetter>();
        foreach (var bind in abilityBindings)
            wanted.Add(bind.letter);

        // Eliminar entradas de perAbilitySfx que ya no existan en bindings
        perAbilitySfx.RemoveAll(e => !wanted.Contains(e.letter));

        // Añadir entradas faltantes
        foreach (var letter in wanted)
        {
            if (!perAbilitySfx.Exists(e => e.letter == letter))
                perAbilitySfx.Add(new AbilitySfxEntry { letter = letter });
        }

        // Ordenar por letra para que se vea bonito en el Inspector
        perAbilitySfx.Sort((a, b) => a.letter.CompareTo(b.letter));
    }

#if UNITY_EDITOR
    private void OnValidate()
    {
        if (autoSyncSfxList)
            SyncPerAbilitySfxWithBindings();
    }
#endif

    private void InvokePerAbilitySfx(MorseLetter letter)
    {
        // Busca la entrada coincidente y dispara su evento
        var entry = perAbilitySfx.Find(e => e.letter == letter);
        entry?.onActivatedSfx?.Invoke();
    }
}
