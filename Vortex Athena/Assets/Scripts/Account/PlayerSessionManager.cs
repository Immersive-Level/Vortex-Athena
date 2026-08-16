using System;
using System.Threading.Tasks;
using UnityEngine;

public enum PlayerSessionState
{
    NotInitialized,
    Guest,
    Linked,
    SignedOut,
    Error
}

[DefaultExecutionOrder(-900)]
public sealed class PlayerSessionManager : MonoBehaviour
{
    public static PlayerSessionManager Instance { get; private set; }

    public event Action<PlayerSessionState> SessionStateChanged;
    public event Action<PlayerProfileData> ProfileChanged;

    [Header("Authentication")]
    [SerializeField] private bool useMockAuthInEditor;
    [SerializeField] private bool autoSignInAnonymously = true;
    [Tooltip("Assign an Android Google Play Games or iOS Apple/Game Center adapter when installed.")]
    [SerializeField] private PlatformAccountLinkerBehaviour platformLinker;

    [Header("Persistence")]
    [SerializeField] private bool useCloudSave = true;

    public PlayerSessionState State { get; private set; } = PlayerSessionState.NotInitialized;
    public PlayerProfileData Profile { get; private set; }
    public string LastError { get; private set; }
    public string LastErrorDetails { get; private set; }
    public string LastPersistenceWarning => repository?.LastWarning;
    public PlayerProfileLoadSource LastProfileLoadSource => repository?.LastLoadSource ?? PlayerProfileLoadSource.None;
    public bool LastCloudSaveSucceeded => repository?.LastCloudSaveSucceeded ?? false;
    public bool IsBusy { get; private set; }
    public bool IsSignedIn => State == PlayerSessionState.Guest || State == PlayerSessionState.Linked;
    public bool IsAuthenticated => IsSignedIn;
    public bool IsGuest => State == PlayerSessionState.Guest;
    public bool IsLinkedAccount => State == PlayerSessionState.Linked;
    public string ProviderName => provider?.ProviderName ?? string.Empty;
    public bool IsUsingSimulatedProvider => provider?.IsSimulated ?? ShouldUseMockProvider();

    private IPlayerAuthenticationProvider provider;
    private IPlayerProfileRepository repository;
    private Task initializationTask;

    public static PlayerSessionManager EnsureInstance()
    {
        if (Instance != null)
            return Instance;

        PlayerSessionManager existing = FindFirstObjectByType<PlayerSessionManager>();
        if (existing != null)
            return existing;

        return new GameObject("PlayerSessionManager").AddComponent<PlayerSessionManager>();
    }

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;
        DontDestroyOnLoad(gameObject);
        CreateProvider();
    }

    private void Start()
    {
        initializationTask = InitializeAuthAsync();
    }

    public async Task InitializeAuthAsync()
    {
        if (IsBusy || State != PlayerSessionState.NotInitialized)
            return;

        IsBusy = true;
        NotifyState();
        try
        {
            EnsureProvider();
            await provider.InitializeAuthAsync();
            PlayerAuthSession restored = await provider.RestoreSessionAsync();
            if (!string.IsNullOrWhiteSpace(restored.PlayerId))
                await ApplySessionAsync(restored);
            else if (autoSignInAnonymously)
                await SignInAnonymouslyInternalAsync();
            else
                SetState(PlayerSessionState.SignedOut);
        }
        catch (Exception exception)
        {
            Fail("No se pudo inicializar Unity Authentication.", exception);
        }
        finally
        {
            IsBusy = false;
            NotifyState();
        }
    }

    public async Task<bool> SignInAnonymouslyAsync()
    {
        await WaitForInitializationAsync();
        if (IsBusy || IsSignedIn)
            return IsSignedIn;

        IsBusy = true;
        LastError = null;
        NotifyState();
        try
        {
            await SignInAnonymouslyInternalAsync();
            return true;
        }
        catch (Exception exception)
        {
            Fail("No se pudo iniciar la sesion de invitado.", exception);
            return false;
        }
        finally
        {
            IsBusy = false;
            NotifyState();
        }
    }

    public async Task<bool> LinkWithPlatformAsync()
    {
        await WaitForInitializationAsync();
        if (IsBusy || IsLinkedAccount)
            return IsLinkedAccount;

        if (!IsGuest && !await SignInAnonymouslyAsync())
            return false;

        IsBusy = true;
        LastError = null;
        NotifyState();
        try
        {
            EnsureProvider();
            PlayerAuthSession linkedSession = await provider.LinkWithPlatformAsync(platformLinker);
            await ApplySessionAsync(linkedSession);
            return IsLinkedAccount;
        }
        catch (Exception exception)
        {
            LastErrorDetails = exception.ToString();
            LastError = $"No se pudo vincular la cuenta. {exception.Message}";
            Debug.LogWarning($"[PlayerSession] {LastError}", this);
            SetState(PlayerSessionState.Guest);
            return false;
        }
        finally
        {
            IsBusy = false;
            NotifyState();
        }
    }

    public async Task SignOutAsync()
    {
        await WaitForInitializationAsync();
        if (IsBusy || State == PlayerSessionState.SignedOut)
            return;

        IsBusy = true;
        NotifyState();
        try
        {
            EnsureProvider();
            await provider.SignOutAsync();
            Profile = null;
            repository = null;
            LastError = null;
            LastErrorDetails = null;
            SetState(PlayerSessionState.SignedOut);
            ProfileChanged?.Invoke(null);
        }
        catch (Exception exception)
        {
            Fail("No se pudo cerrar la sesion.", exception);
        }
        finally
        {
            IsBusy = false;
            NotifyState();
        }
    }

    public string GetPlayerId() => Profile?.playerId ?? string.Empty;

    public Task UpdateUsernameAsync(string username)
    {
        return UpdateProfileAsync(() => repository.UpdateUsernameAsync(Profile, username));
    }

    public Task UpdateSelectedCharacterAsync(string characterId)
    {
        return UpdateProfileAsync(() => repository.UpdateSelectedCharacterAsync(Profile, characterId));
    }

    public Task UpdateStatsAsync(int bestScore, int kills, int deaths, int victories, int defeats)
    {
        return UpdateProfileAsync(() => repository.UpdateStatsAsync(Profile, bestScore, kills, deaths, victories, defeats));
    }

    public async Task ReloadProfileAsync()
    {
        if (!IsSignedIn || repository == null || IsBusy)
            return;

        IsBusy = true;
        NotifyState();
        try
        {
            PlayerProfileData loaded = await repository.LoadProfileAsync();
            if (loaded != null)
            {
                loaded.Normalize(GetPlayerId(), Profile.accountType, IsLinkedAccount);
                Profile = loaded;
                ProfileChanged?.Invoke(Profile);
            }
        }
        catch (Exception exception)
        {
            LastError = $"No se pudo recargar el perfil. {exception.Message}";
            Debug.LogWarning($"[PlayerSession] {LastError}", this);
        }
        finally
        {
            IsBusy = false;
            NotifyState();
        }
    }

    public void SetProviderForTests(IPlayerAuthenticationProvider authenticationProvider)
    {
        if (authenticationProvider == null) throw new ArgumentNullException(nameof(authenticationProvider));
        if (IsBusy) throw new InvalidOperationException("No se puede cambiar el proveedor durante una operacion.");
        provider = authenticationProvider;
        repository = null;
        Profile = null;
        SetState(PlayerSessionState.NotInitialized);
        initializationTask = InitializeAuthAsync();
    }

    private async Task SignInAnonymouslyInternalAsync()
    {
        EnsureProvider();
        PlayerAuthSession guestSession = await provider.SignInAnonymouslyAsync();
        await ApplySessionAsync(guestSession);
    }

    private async Task ApplySessionAsync(PlayerAuthSession authSession)
    {
        if (string.IsNullOrWhiteSpace(authSession.PlayerId))
            throw new InvalidOperationException("El proveedor devolvio un Player ID vacio.");

        EnsureProvider();
        repository = new PlayerProfileRepository(authSession.PlayerId, useCloudSave && !provider.IsSimulated);
        PlayerProfileData profile = await repository.LoadProfileAsync();
        profile ??= await repository.CreateDefaultProfileAsync(authSession.PlayerId, authSession.AccountType, authSession.IsLinked);
        profile.Normalize(authSession.PlayerId, authSession.AccountType, authSession.IsLinked);
        Profile = profile;
        await repository.SaveProfileAsync(Profile);
        LastError = null;
        LastErrorDetails = null;
        SetState(authSession.IsLinked ? PlayerSessionState.Linked : PlayerSessionState.Guest);
        ProfileChanged?.Invoke(Profile);
    }

    private async Task UpdateProfileAsync(Func<Task> update)
    {
        await WaitForInitializationAsync();
        if (!IsSignedIn || Profile == null || repository == null || IsBusy)
            return;

        IsBusy = true;
        LastError = null;
        NotifyState();
        try
        {
            await update();
            ProfileChanged?.Invoke(Profile);
        }
        catch (Exception exception)
        {
            LastError = $"No se pudo guardar el perfil. {exception.Message}";
            Debug.LogWarning($"[PlayerSession] {LastError}", this);
        }
        finally
        {
            IsBusy = false;
            NotifyState();
        }
    }

    private async Task WaitForInitializationAsync()
    {
        if (initializationTask != null && !initializationTask.IsCompleted)
            await initializationTask;
    }

    private void CreateProvider()
    {
        provider = ShouldUseMockProvider()
            ? new SimulatedAuthenticationProvider(Profile?.playerId, State == PlayerSessionState.Linked)
            : new UnityAuthenticationProvider();
    }

    private void EnsureProvider()
    {
        if (provider == null)
            CreateProvider();
    }

    private bool ShouldUseMockProvider()
    {
#if UNITY_EDITOR
        return useMockAuthInEditor;
#else
        return false;
#endif
    }

    private void Fail(string context, Exception exception)
    {
        LastError = $"{context} {exception.Message}";
        LastErrorDetails = exception.ToString();
        Debug.LogWarning($"[PlayerSession] {LastError}", this);
        SetState(PlayerSessionState.Error);
    }

    private void SetState(PlayerSessionState nextState)
    {
        State = nextState;
        NotifyState();
    }

    private void NotifyState()
    {
        SessionStateChanged?.Invoke(State);
    }
}
