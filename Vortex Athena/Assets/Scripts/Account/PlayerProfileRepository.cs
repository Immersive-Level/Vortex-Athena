using System;
using System.Collections.Generic;
using System.IO;
using System.Threading.Tasks;
using Unity.Services.Authentication;
using Unity.Services.CloudSave;
using UnityEngine;

public enum PlayerProfileLoadSource
{
    None,
    CloudSave,
    LocalCache,
    CreatedDefault
}

public interface IPlayerProfileRepository
{
    string LastWarning { get; }
    PlayerProfileLoadSource LastLoadSource { get; }
    bool LastCloudSaveSucceeded { get; }
    Task<PlayerProfileData> LoadProfileAsync();
    Task<PlayerProfileData> CreateDefaultProfileAsync(string playerId, string accountType, bool linked);
    Task SaveProfileAsync(PlayerProfileData profile);
    Task UpdateSelectedCharacterAsync(PlayerProfileData profile, string characterId);
    Task UpdateUsernameAsync(PlayerProfileData profile, string username);
    Task UpdateStatsAsync(PlayerProfileData profile, int bestScore, int kills, int deaths, int victories, int defeats);
}

public sealed class PlayerProfileRepository : IPlayerProfileRepository
{
    private const string CloudKey = "player_profile_v1";
    private readonly string playerId;
    private readonly bool useCloudSave;

    public string LastWarning { get; private set; }
    public PlayerProfileLoadSource LastLoadSource { get; private set; }
    public bool LastCloudSaveSucceeded { get; private set; }

    public PlayerProfileRepository(string playerId, bool useCloudSave)
    {
        this.playerId = string.IsNullOrWhiteSpace(playerId) ? "unknown" : playerId;
        this.useCloudSave = useCloudSave;
    }

    public async Task<PlayerProfileData> LoadProfileAsync()
    {
        LastWarning = null;
        LastLoadSource = PlayerProfileLoadSource.None;
        if (CanUseCloudSave())
        {
            try
            {
                var result = await CloudSaveService.Instance.Data.Player.LoadAsync(
                    new HashSet<string> { CloudKey },
                    new Unity.Services.CloudSave.Models.Data.Player.LoadOptions());
                if (result.TryGetValue(CloudKey, out var item))
                {
                    PlayerProfileData cloudProfile = item.Value.GetAs<PlayerProfileData>();
                    if (cloudProfile != null)
                    {
                        SaveLocal(cloudProfile);
                        LastLoadSource = PlayerProfileLoadSource.CloudSave;
                        return cloudProfile;
                    }
                }
            }
            catch (Exception exception)
            {
                LastWarning = $"Cloud Save no pudo cargar el perfil; se usara la copia local. {exception.Message}";
                Debug.LogWarning($"[PlayerProfile] {LastWarning}");
            }
        }

        PlayerProfileData localProfile = LoadLocal();
        if (localProfile != null)
            LastLoadSource = PlayerProfileLoadSource.LocalCache;
        return localProfile;
    }

    public async Task<PlayerProfileData> CreateDefaultProfileAsync(string id, string accountType, bool linked)
    {
        PlayerProfileData profile = PlayerProfileData.CreateDefault(id, accountType, linked);
        await SaveProfileAsync(profile);
        LastLoadSource = PlayerProfileLoadSource.CreatedDefault;
        return profile;
    }

    public async Task SaveProfileAsync(PlayerProfileData profile)
    {
        if (profile == null)
            throw new ArgumentNullException(nameof(profile));

        SaveLocal(profile);
        LastCloudSaveSucceeded = false;
        if (!CanUseCloudSave())
            return;

        try
        {
            await CloudSaveService.Instance.Data.Player.SaveAsync(
                new Dictionary<string, object> { { CloudKey, profile } },
                new Unity.Services.CloudSave.Models.Data.Player.SaveOptions());
            LastWarning = null;
            LastCloudSaveSucceeded = true;
        }
        catch (Exception exception)
        {
            LastWarning = $"El perfil se guardo localmente, pero Cloud Save fallo. {exception.Message}";
            Debug.LogWarning($"[PlayerProfile] {LastWarning}");
        }
    }

    public Task UpdateSelectedCharacterAsync(PlayerProfileData profile, string characterId)
    {
        if (string.IsNullOrWhiteSpace(characterId))
            throw new ArgumentException("El personaje seleccionado no puede estar vacio.", nameof(characterId));
        string normalizedId = PlayerProfileData.NormalizeCharacterId(characterId);
        if (!PlayerProfileData.IsKnownCharacterId(normalizedId))
            throw new ArgumentException("El personaje seleccionado no es valido.", nameof(characterId));
        if (profile == null || profile.unlockedCharacters == null || !profile.unlockedCharacters.Contains(normalizedId))
            throw new InvalidOperationException("El personaje seleccionado esta bloqueado.");
        profile.selectedCharacterId = normalizedId;
        return SaveProfileAsync(profile);
    }

    public Task UpdateUsernameAsync(PlayerProfileData profile, string username)
    {
        if (string.IsNullOrWhiteSpace(username))
            throw new ArgumentException("El nombre de usuario no puede estar vacio.", nameof(username));
        profile.username = username.Trim();
        return SaveProfileAsync(profile);
    }

    public Task UpdateStatsAsync(PlayerProfileData profile, int bestScore, int kills, int deaths, int victories, int defeats)
    {
        profile.bestScore = Math.Max(profile.bestScore, bestScore);
        profile.kills = Math.Max(0, kills);
        profile.deaths = Math.Max(0, deaths);
        profile.victories = Math.Max(0, victories);
        profile.defeats = Math.Max(0, defeats);
        return SaveProfileAsync(profile);
    }

    private bool CanUseCloudSave()
    {
        return useCloudSave && AuthenticationService.Instance.IsSignedIn
            && Application.internetReachability != NetworkReachability.NotReachable;
    }

    private PlayerProfileData LoadLocal()
    {
        string path = GetLocalPath();
        if (!File.Exists(path))
            return null;

        try
        {
            string json = File.ReadAllText(path);
            PlayerProfileData profile = JsonUtility.FromJson<PlayerProfileData>(json);
            if (profile == null)
                throw new InvalidDataException("El JSON no contiene un perfil valido.");
            return profile;
        }
        catch (Exception exception)
        {
            LastWarning = $"La cache local estaba corrupta y sera reemplazada. {exception.Message}";
            Debug.LogWarning($"[PlayerProfile] {LastWarning}");
            return null;
        }
    }

    private void SaveLocal(PlayerProfileData profile)
    {
        string path = GetLocalPath();
        string directory = Path.GetDirectoryName(path);
        if (!string.IsNullOrEmpty(directory)) Directory.CreateDirectory(directory);
        string tempPath = path + ".tmp";
        File.WriteAllText(tempPath, JsonUtility.ToJson(profile, true));
        if (File.Exists(path)) File.Delete(path);
        File.Move(tempPath, path);
    }

    private string GetLocalPath()
    {
        string safePlayerId = playerId;
        foreach (char invalid in Path.GetInvalidFileNameChars())
            safePlayerId = safePlayerId.Replace(invalid, '_');
        return Path.Combine(Application.persistentDataPath, $"player-profile-{safePlayerId}.json");
    }
}
