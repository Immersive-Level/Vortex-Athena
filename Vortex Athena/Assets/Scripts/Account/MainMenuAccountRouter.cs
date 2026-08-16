using TMPro;
using UnityEngine;
using UnityEngine.Events;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public sealed class MainMenuAccountRouter : MonoBehaviour
{
    [Header("Menu Buttons")]
    [SerializeField] private Button profileButton;
    [SerializeField] private Button onlineButton;
    [SerializeField] private Graphic onlineButtonGraphic;

    [Header("Login Required Dialog")]
    [SerializeField] private GameObject loginRequiredDialog;
    [SerializeField] private TMP_Text loginRequiredText;
    [SerializeField] private Button goToAccountButton;
    [SerializeField] private Button dismissButton;

    [Header("Navigation")]
    [SerializeField] private string accountSceneName = "PlayerAccountScene";
    [Tooltip("Optional. Leave empty until the real online entry flow is ready.")]
    [SerializeField] private string onlineSceneName;
    [SerializeField] private UnityEvent authenticatedOnlineAction;

    [Header("Visual State")]
    [SerializeField, Range(0.1f, 1f)] private float lockedAlpha = 0.55f;

    public bool IsOnlineLocked => session == null || !session.IsLinkedAccount;
    public bool IsLoginRequiredDialogVisible => loginRequiredDialog != null && loginRequiredDialog.activeSelf;
    public PlayerSessionState SessionState => session != null ? session.State : PlayerSessionState.NotInitialized;
    public string PlayerId => session?.GetPlayerId() ?? string.Empty;
    public string AuthenticationProvider => session?.ProviderName ?? string.Empty;
    public bool IsUsingMockAuthentication => session?.IsUsingSimulatedProvider ?? true;
    public string ProfileUsername => session?.Profile?.username ?? string.Empty;
    public string ProfileLoadSource => session?.LastProfileLoadSource.ToString() ?? PlayerProfileLoadSource.None.ToString();
    public bool CloudSaveSucceeded => session?.LastCloudSaveSucceeded ?? false;
    public string AccountError => session?.LastError ?? string.Empty;
    public string PersistenceWarning => session?.LastPersistenceWarning ?? string.Empty;

    private PlayerSessionManager session;
    private Color onlineBaseColor = Color.white;

    private void Awake()
    {
        session = PlayerSessionManager.EnsureInstance();
        if (onlineButtonGraphic != null)
            onlineBaseColor = onlineButtonGraphic.color;

        BindButtons();
        if (loginRequiredDialog != null)
            loginRequiredDialog.SetActive(false);
    }

    private void OnEnable()
    {
        session ??= PlayerSessionManager.EnsureInstance();
        session.SessionStateChanged += HandleSessionStateChanged;
        RefreshOnlineState();
    }

    private void OnDisable()
    {
        if (session != null)
            session.SessionStateChanged -= HandleSessionStateChanged;
    }

    public void OpenAccount()
    {
        LoadSceneIfAvailable(accountSceneName);
    }

    public void TryOpenOnline()
    {
        if (IsOnlineLocked)
        {
            if (loginRequiredText != null)
                loginRequiredText.text = "Vincula una cuenta para acceder al multijugador online.";
            if (loginRequiredDialog != null)
                loginRequiredDialog.SetActive(true);
            return;
        }

        if (!string.IsNullOrWhiteSpace(onlineSceneName))
        {
            LoadSceneIfAvailable(onlineSceneName);
            return;
        }

        authenticatedOnlineAction?.Invoke();
        Debug.Log("[AccountGate] Linked-account online access granted; no online destination is configured yet.", this);
    }

    public void DismissLoginRequired()
    {
        if (loginRequiredDialog != null)
            loginRequiredDialog.SetActive(false);
    }

    private void BindButtons()
    {
        Bind(profileButton, OpenAccount);
        Bind(onlineButton, TryOpenOnline);
        Bind(goToAccountButton, OpenAccount);
        Bind(dismissButton, DismissLoginRequired);
    }

    private static void Bind(Button button, UnityAction action)
    {
        if (button == null)
            return;

        button.onClick.RemoveListener(action);
        button.onClick.AddListener(action);
    }

    private void HandleSessionStateChanged(PlayerSessionState _)
    {
        RefreshOnlineState();
    }

    private void RefreshOnlineState()
    {
        if (onlineButton != null)
            onlineButton.interactable = true;

        if (onlineButtonGraphic != null)
        {
            Color color = onlineBaseColor;
            color.a = IsOnlineLocked ? lockedAlpha : onlineBaseColor.a;
            onlineButtonGraphic.color = color;
        }

        if (!IsOnlineLocked)
            DismissLoginRequired();
    }

    private void LoadSceneIfAvailable(string sceneName)
    {
        if (string.IsNullOrWhiteSpace(sceneName) || !Application.CanStreamedLevelBeLoaded(sceneName))
        {
            Debug.LogWarning($"[AccountGate] Scene '{sceneName}' is not available in Build Settings.", this);
            return;
        }

        SceneManager.LoadScene(sceneName);
    }
}
