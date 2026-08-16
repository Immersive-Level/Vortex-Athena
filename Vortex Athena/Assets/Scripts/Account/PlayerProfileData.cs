using System;
using System.Collections.Generic;

[Serializable]
public sealed class PlayerProfileData
{
    public const int CurrentSchemaVersion = 1;

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
            selectedCharacterId = "default",
            unlockedCharacters = new List<string> { "default" },
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
        if (string.IsNullOrWhiteSpace(selectedCharacterId)) selectedCharacterId = "default";
        unlockedCharacters ??= new List<string>();
        if (!unlockedCharacters.Contains("default")) unlockedCharacters.Add("default");
        claimedRewards ??= new List<string>();
        if (string.IsNullOrWhiteSpace(profileCreatedAt)) profileCreatedAt = DateTime.UtcNow.ToString("O");
        lastLoginDate = DateTime.UtcNow.ToString("O");
    }
}
