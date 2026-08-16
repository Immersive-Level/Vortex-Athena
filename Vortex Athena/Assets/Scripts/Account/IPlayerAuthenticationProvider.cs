using System;
using System.Threading.Tasks;
using Unity.Services.Authentication;
using Unity.Services.Core;
using UnityEngine;

public readonly struct PlayerAuthSession
{
    public readonly string PlayerId;
    public readonly string AccountType;
    public readonly bool IsLinked;

    public PlayerAuthSession(string playerId, string accountType, bool isLinked)
    {
        PlayerId = playerId;
        AccountType = accountType;
        IsLinked = isLinked;
    }
}

public interface IPlayerAuthenticationProvider
{
    string ProviderName { get; }
    bool IsSimulated { get; }
    bool IsSignedIn { get; }
    Task InitializeAuthAsync();
    Task<PlayerAuthSession> RestoreSessionAsync();
    Task<PlayerAuthSession> SignInAnonymouslyAsync();
    Task<PlayerAuthSession> LinkWithPlatformAsync(IPlatformAccountLinker platformLinker);
    Task SignOutAsync();
}

public interface IPlatformAccountLinker
{
    string PlatformName { get; }
    bool IsAvailable { get; }
    Task LinkCurrentUnityPlayerAsync();
}

public abstract class PlatformAccountLinkerBehaviour : MonoBehaviour, IPlatformAccountLinker
{
    public abstract string PlatformName { get; }
    public abstract bool IsAvailable { get; }
    public abstract Task LinkCurrentUnityPlayerAsync();
}

public sealed class UnityAuthenticationProvider : IPlayerAuthenticationProvider
{
    public string ProviderName => "Unity Authentication";
    public bool IsSimulated => false;
    public bool IsSignedIn => UnityServices.State == ServicesInitializationState.Initialized
        && AuthenticationService.Instance.IsSignedIn;

    public async Task InitializeAuthAsync()
    {
        if (UnityServices.State != ServicesInitializationState.Initialized)
            await UnityServices.InitializeAsync();
    }

    public async Task<PlayerAuthSession> RestoreSessionAsync()
    {
        return IsSignedIn ? await BuildSessionAsync() : default;
    }

    public async Task<PlayerAuthSession> SignInAnonymouslyAsync()
    {
        if (!AuthenticationService.Instance.IsSignedIn)
            await AuthenticationService.Instance.SignInAnonymouslyAsync();
        return await BuildSessionAsync();
    }

    public async Task<PlayerAuthSession> LinkWithPlatformAsync(IPlatformAccountLinker platformLinker)
    {
        if (platformLinker == null || !platformLinker.IsAvailable)
            throw new InvalidOperationException("No hay un adaptador de identidad disponible para esta plataforma.");

        await platformLinker.LinkCurrentUnityPlayerAsync();
        return await BuildSessionAsync();
    }

    public Task SignOutAsync()
    {
        if (AuthenticationService.Instance.IsSignedIn)
            AuthenticationService.Instance.SignOut();
        return Task.CompletedTask;
    }

    private static async Task<PlayerAuthSession> BuildSessionAsync()
    {
        PlayerInfo info = await AuthenticationService.Instance.GetPlayerInfoAsync();
        bool linked = info?.Identities != null && info.Identities.Count > 0;
        string type = linked ? info.Identities[0].TypeId : "Guest";
        return new PlayerAuthSession(AuthenticationService.Instance.PlayerId, type, linked);
    }
}

public sealed class SimulatedAuthenticationProvider : IPlayerAuthenticationProvider
{
    private string playerId;
    private bool linked;

    public string ProviderName => "Editor Mock";
    public bool IsSimulated => true;
    public bool IsSignedIn => !string.IsNullOrWhiteSpace(playerId);

    public SimulatedAuthenticationProvider(string restoredPlayerId = null, bool restoredLinked = false)
    {
        playerId = restoredPlayerId;
        linked = restoredLinked;
    }

    public Task InitializeAuthAsync() => Task.CompletedTask;

    public Task<PlayerAuthSession> RestoreSessionAsync()
    {
        return Task.FromResult(IsSignedIn
            ? new PlayerAuthSession(playerId, linked ? "EditorMock" : "Guest", linked)
            : default);
    }

    public Task<PlayerAuthSession> SignInAnonymouslyAsync()
    {
        playerId ??= $"mock-{Guid.NewGuid():N}";
        linked = false;
        return Task.FromResult(new PlayerAuthSession(playerId, "Guest", false));
    }

    public Task<PlayerAuthSession> LinkWithPlatformAsync(IPlatformAccountLinker platformLinker)
    {
        playerId ??= $"mock-{Guid.NewGuid():N}";
        linked = true;
        return Task.FromResult(new PlayerAuthSession(playerId, "EditorMock", true));
    }

    public Task SignOutAsync()
    {
        playerId = null;
        linked = false;
        return Task.CompletedTask;
    }
}
