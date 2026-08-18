using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public sealed class PlayerAccountController : MonoBehaviour
{
    [Header("Views")]
    [SerializeField] private GameObject loginPanel;
    [SerializeField] private GameObject registerPanel;
    [SerializeField] private GameObject profilePanel;
    [SerializeField] private GameObject busyOverlay;
    [SerializeField] private PlayerProfileViewController profileViewController;

    [Header("Guest / Link")]
    [SerializeField] private Button simulatedLoginButton;
    [SerializeField] private Button showRegisterButton;
    [SerializeField] private TMP_Text loginProviderText;

    [Header("Account Options")]
    [SerializeField] private Button simulatedRegisterButton;
    [SerializeField] private Button registerBackButton;

    [Header("Profile")]
    [SerializeField] private TMP_Text displayNameText;
    [SerializeField] private TMP_Text playerIdText;
    [SerializeField] private TMP_Text selectedCharacterText;
    [SerializeField] private TMP_Text statsText;
    [SerializeField] private Button logoutButton;

    [Header("Navigation")]
    [SerializeField] private Button backButton;
    [SerializeField] private Button signedOutBackButton;
    [SerializeField] private string mainMenuSceneName = "MainMenu";

    public bool IsShowingLogin => loginPanel != null && loginPanel.activeSelf;
    public bool IsShowingProfile => profilePanel != null && profilePanel.activeSelf;
    public bool IsShowingGuest => IsShowingProfile && session != null && session.IsGuest;
    public PlayerSessionState SessionState => session != null ? session.State : PlayerSessionState.NotInitialized;
    public string ProfileUsername => session?.Profile?.username ?? string.Empty;
    public string SelectedCharacterId => session?.Profile?.selectedCharacterId ?? string.Empty;
    public string UnlockedCharacterIds => session?.Profile?.unlockedCharacters == null
        ? string.Empty
        : string.Join(",", session.Profile.unlockedCharacters);
    public int ProfileSchemaVersion => session?.Profile?.schemaVersion ?? 0;
    public string LastErrorDetails => session?.LastErrorDetails ?? string.Empty;
    public string PlayerId => session?.GetPlayerId() ?? string.Empty;
    public string AuthenticationProvider => session?.ProviderName ?? string.Empty;
    public bool IsUsingMockAuthentication => session?.IsUsingSimulatedProvider ?? true;
    public string ProfileLoadSource => session?.LastProfileLoadSource.ToString() ?? PlayerProfileLoadSource.None.ToString();
    public bool CloudSaveSucceeded => session?.LastCloudSaveSucceeded ?? false;
    public string PersistenceWarning => session?.LastPersistenceWarning ?? string.Empty;

    private PlayerSessionManager session;

    private void Awake()
    {
        session = PlayerSessionManager.EnsureInstance();
        BindButtons();
    }

    private async void OnEnable()
    {
        session ??= PlayerSessionManager.EnsureInstance();
        session.SessionStateChanged += HandleSessionStateChanged;
        session.ProfileChanged += HandleProfileChanged;
        Refresh();
        if (session.IsSignedIn)
            await session.ReloadProfileAsync();
    }

    private void OnDisable()
    {
        if (session == null) return;
        session.SessionStateChanged -= HandleSessionStateChanged;
        session.ProfileChanged -= HandleProfileChanged;
    }

    public void ShowRegister()
    {
        if (!session.IsBusy && !session.IsLinkedAccount)
            SetView(login: false, register: true, profile: false);
    }

    public void ShowLogin()
    {
        if (!session.IsBusy && !session.IsLinkedAccount)
            SetView(login: true, register: false, profile: false);
    }

    public async void SimulateLogin()
    {
        SetButtonsInteractable(false);
        if (session.IsGuest)
            await session.LinkWithPlatformAsync();
        else
            await session.SignInAnonymouslyAsync();
    }

    public async void SimulateRegister()
    {
        SetButtonsInteractable(false);
        await session.LinkWithPlatformAsync();
    }

    public async void ContinueAsGuest()
    {
        SetButtonsInteractable(false);
        await session.SignInAnonymouslyAsync();
    }

    public async void Logout()
    {
        SetButtonsInteractable(false);
        await session.SignOutAsync();
    }

#if UNITY_EDITOR
    public async void SimulateProfileUpdateAndReload()
    {
        if (session == null || !session.IsSignedIn || session.IsBusy)
            return;
        await session.UpdateUsernameAsync("UGS Cloud Test");
        await session.UpdateSelectedCharacterAsync(PlayerProfileData.AntaresCharacterId);
        await session.ReloadProfileAsync();
    }
#endif

    public void ReturnToMainMenu()
    {
        if ((session != null && session.IsBusy) || (profileViewController != null && profileViewController.IsSaving))
            return;
        if (!Application.CanStreamedLevelBeLoaded(mainMenuSceneName))
        {
            Debug.LogWarning($"[PlayerAccount] Scene '{mainMenuSceneName}' is not available in Build Settings.", this);
            return;
        }
        SceneManager.LoadScene(mainMenuSceneName);
    }

    private void BindButtons()
    {
        Bind(simulatedLoginButton, SimulateLogin);
        Bind(showRegisterButton, ShowRegister);
        Bind(simulatedRegisterButton, SimulateRegister);
        Bind(registerBackButton, ShowLogin);
        Bind(logoutButton, Logout);
        Bind(backButton, ReturnToMainMenu);
        Bind(signedOutBackButton, ReturnToMainMenu);
    }

    private static void Bind(Button button, UnityEngine.Events.UnityAction action)
    {
        if (button == null) return;
        button.onClick.RemoveListener(action);
        button.onClick.AddListener(action);
    }

    private void HandleSessionStateChanged(PlayerSessionState _) => Refresh();
    private void HandleProfileChanged(PlayerProfileData _) => Refresh();

    private void Refresh()
    {
        if (session == null) return;

        bool busy = session.IsBusy;
        if (busyOverlay != null) busyOverlay.SetActive(busy);

        if (session.IsSignedIn)
        {
            SetView(login: false, register: false, profile: true);
            PopulateProfile(session.Profile);
        }
        else if (!busy && (registerPanel == null || !registerPanel.activeSelf))
        {
            SetView(login: true, register: false, profile: false);
        }

        if (loginProviderText != null)
        {
            if (!string.IsNullOrWhiteSpace(session.LastError))
                loginProviderText.text = session.LastError;
            else if (session.IsGuest)
                loginProviderText.text = "Sesion invitada activa";
            else if (session.State == PlayerSessionState.SignedOut)
                loginProviderText.text = "Continua como invitado para cargar tu perfil.";
            else
                loginProviderText.text = $"Proveedor: {session.ProviderName}";
        }

        SetButtonsInteractable(!busy);
    }

    private void SetView(bool login, bool register, bool profile)
    {
        if (loginPanel != null) loginPanel.SetActive(login);
        if (registerPanel != null) registerPanel.SetActive(register);
        if (profilePanel != null) profilePanel.SetActive(profile);
        if (login)
        {
            Bind(simulatedLoginButton, SimulateLogin);
            Bind(showRegisterButton, ShowRegister);
        }
        if (register)
        {
            Bind(simulatedRegisterButton, SimulateRegister);
            Bind(registerBackButton, ShowLogin);
        }
        if (profile) Bind(logoutButton, Logout);
    }

    private void PopulateProfile(PlayerProfileData profile)
    {
        if (profile == null) return;
        if (displayNameText != null) displayNameText.text = profile.username;
        if (playerIdText != null) playerIdText.text = $"ID: {profile.playerId}";
        if (selectedCharacterText != null) selectedCharacterText.text = $"Personaje: {profile.selectedCharacterId}";
        if (statsText != null)
        {
            statsText.text = $"Monedas {profile.coins}   Mejor puntaje {profile.bestScore}\n" +
                             $"Victorias {profile.victories}   Derrotas {profile.defeats}\n" +
                             $"Kills {profile.kills}   Muertes {profile.deaths}";
        }
    }

    private void SetButtonsInteractable(bool interactable)
    {
        if (simulatedLoginButton != null) simulatedLoginButton.interactable = interactable;
        if (showRegisterButton != null) showRegisterButton.interactable = interactable;
        if (simulatedRegisterButton != null) simulatedRegisterButton.interactable = interactable;
        if (registerBackButton != null) registerBackButton.interactable = interactable;
        if (logoutButton != null) logoutButton.interactable = interactable;
        if (backButton != null) backButton.interactable = interactable;
        if (signedOutBackButton != null) signedOutBackButton.interactable = interactable;
    }
}
