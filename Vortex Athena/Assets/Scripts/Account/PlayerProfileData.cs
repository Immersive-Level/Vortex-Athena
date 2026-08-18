using System;
using System.Collections.Generic;

[Serializable]
public sealed class PlayerProfileData
{
    public const int CurrentSchemaVersion = 2;
    public const string AntaresCharacterId = "antares";
    public const string BellatrixCharacterId = "bellatrix";
    public const string ZetaCharacterId = "zeta";
    public const string ZubenesCharacterId = "zubenes";
    public const string LegacyDefaultCharacterId = "default";

    public int schemaVersion = CurrentSchemaVersion;
    public string playerId;
    public string username;
    public string accountType;
    public bool isLinkedAccount;
    public string selectedCharacterId;
    public List<string> unlockedCharacters = new List<string>();
    public int coins;
    public List<string> claimedRewards = new List<string>();
    public int bestScore;
    public int kills;
    public int deaths;
    public int victories;
    public int defeats;
    public string lastLoginDate;
    public string profileCreatedAt;

    public static PlayerProfileData CreateDefault(string id, string type, bool linked)
    {
        string now = DateTime.UtcNow.ToString("O");
        return new PlayerProfileData
        {
            playerId = id,
            username = linked ? "Nuevo Piloto" : "Piloto Invitado",
            accountType = string.IsNullOrWhiteSpace(type) ? "Guest" : type,
            isLinkedAccount = linked,
            selectedCharacterId = AntaresCharacterId,
            unlockedCharacters = new List<string> { AntaresCharacterId },
            claimedRewards = new List<string>(),
            lastLoginDate = now,
            profileCreatedAt = now
        };
    }

    public void Normalize(string fallbackPlayerId, string fallbackAccountType, bool linked)
    {
        schemaVersion = CurrentSchemaVersion;
        if (string.IsNullOrWhiteSpace(playerId)) playerId = fallbackPlayerId;
        if (string.IsNullOrWhiteSpace(username)) username = linked ? "Nuevo Piloto" : "Piloto Invitado";
        if (!string.IsNullOrWhiteSpace(fallbackAccountType)) accountType = fallbackAccountType;
        isLinkedAccount = linked;
        selectedCharacterId = NormalizeCharacterId(selectedCharacterId);
        unlockedCharacters ??= new List<string>();
        var normalizedUnlocked = new List<string>();
        foreach (string characterId in unlockedCharacters)
        {
            string normalizedId = NormalizeCharacterId(characterId);
            if (IsKnownCharacterId(normalizedId) && !normalizedUnlocked.Contains(normalizedId))
                normalizedUnlocked.Add(normalizedId);
        }
        if (!normalizedUnlocked.Contains(AntaresCharacterId)) normalizedUnlocked.Add(AntaresCharacterId);
        unlockedCharacters = normalizedUnlocked;
        if (!unlockedCharacters.Contains(selectedCharacterId)) selectedCharacterId = AntaresCharacterId;
        claimedRewards ??= new List<string>();
        if (string.IsNullOrWhiteSpace(profileCreatedAt)) profileCreatedAt = DateTime.UtcNow.ToString("O");
        lastLoginDate = DateTime.UtcNow.ToString("O");
    }

    public static bool IsKnownCharacterId(string characterId)
    {
        return string.Equals(characterId, AntaresCharacterId, StringComparison.Ordinal)
            || string.Equals(characterId, BellatrixCharacterId, StringComparison.Ordinal)
            || string.Equals(characterId, ZetaCharacterId, StringComparison.Ordinal)
            || string.Equals(characterId, ZubenesCharacterId, StringComparison.Ordinal);
    }

    public static string NormalizeCharacterId(string characterId)
    {
        if (string.IsNullOrWhiteSpace(characterId) || string.Equals(characterId.Trim(), LegacyDefaultCharacterId, StringComparison.OrdinalIgnoreCase))
            return AntaresCharacterId;
        if (string.Equals(characterId.Trim(), "bellarix", StringComparison.OrdinalIgnoreCase))
            return BellatrixCharacterId;
        string normalized = characterId.Trim().ToLowerInvariant();
        return IsKnownCharacterId(normalized) ? normalized : AntaresCharacterId;
    }
}
