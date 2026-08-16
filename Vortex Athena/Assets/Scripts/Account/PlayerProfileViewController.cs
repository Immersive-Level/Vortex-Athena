using System;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

public sealed class PlayerProfileViewController : MonoBehaviour
{
    private const int UsernameMaxLength = 20;

    [Header("Characters")]
    [SerializeField] private List<PlayerCharacterData> characters = new List<PlayerCharacterData>();
    [SerializeField] private Image characterImage;
    [SerializeField] private Image lockImage;
    [SerializeField] private Image empireIconImage;
    [SerializeField] private Sprite fallbackEmpireIcon;
    [SerializeField] private Button previousCharacterButton;
    [SerializeField] private Button nextCharacterButton;
    [SerializeField] private Button selectCharacterButton;
    [SerializeField] private TMP_Text characterNameText;
    [SerializeField] private TMP_Text characterSelectionStateText;

    [Header("Username")]
    [SerializeField] private TMP_Text usernameText;
    [SerializeField] private Button editUsernameButton;
    [SerializeField] private GameObject usernameEditPanel;
    [SerializeField] private TMP_InputField usernameInput;
    [SerializeField] private Button saveUsernameButton;
    [SerializeField] private Button cancelUsernameButton;
    [SerializeField] private TMP_Text feedbackText;

    [Header("Statistics")]
    [SerializeField] private TMP_Text bestScoreText;
    [SerializeField] private TMP_Text killsText;
    [SerializeField] private TMP_Text deathsText;
    [SerializeField] private TMP_Text victoriesText;
    [SerializeField] private TMP_Text defeatsText;

    [Header("Account")]
    [SerializeField] private TMP_Text accountStatusText;
    [SerializeField] private GameObject accountStatePanel;
    [SerializeField] private TMP_Text accountStateMessageText;
    [SerializeField] private Button settingsButton;
    [SerializeField] private Button closeAccountStateButton;
    [SerializeField] private Button linkAccountButton;
    [SerializeField] private Button logoutButton;
    [SerializeField] private Button backButton;

    [Header("Future Modules")]
    [SerializeField] private GameObject profileSection;
    [SerializeField] private GameObject futureShopSection;
    [SerializeField] private GameObject futureRewardsSection;
    [SerializeField] private Button profileTabButton;
    [SerializeField] private Button shopTabButton;
    [SerializeField] private Button rewardsTabButton;

    [Header("Presentation")]
    [SerializeField] private Color unlockedColor = Color.white;
    [SerializeField] private Color lockedColor = new Color(0.72f, 0.72f, 0.72f, 0.78f);
    [SerializeField] private bool showAccountStatus = true;
    [SerializeField] private bool showGuestLinkPrompt = true;
    [SerializeField] private bool showDebugPlayerId;

    public bool IsSaving { get; private set; }
    public int PreviewCharacterIndex => previewCharacterIndex;
    public string PreviewCharacterId => CurrentCharacter != null ? CurrentCharacter.CharacterId : string.Empty;
    public bool IsPreviewCharacterUnlocked => IsUnlocked(CurrentCharacter, session?.Profile);

    private PlayerSessionManager session;
    private int previewCharacterIndex;
    private bool previewInitialized;

    private PlayerCharacterData CurrentCharacter => characters != null
        && previewCharacterIndex >= 0
        && previewCharacterIndex < characters.Count
            ? characters[previewCharacterIndex]
            : null;

    private void Awake()
    {
        session = PlayerSessionManager.EnsureInstance();
        if (usernameInput != null)
            usernameInput.characterLimit = UsernameMaxLength;
        BindButtons();
        ValidateReferences();
    }

    private void OnEnable()
    {
        session ??= PlayerSessionManager.EnsureInstance();
        session.SessionStateChanged += HandleSessionStateChanged;
        session.ProfileChanged += HandleProfileChanged;
        Refresh(session.Profile);
    }

    private void OnDisable()
    {
        if (session == null) return;
        session.SessionStateChanged -= HandleSessionStateChanged;
        session.ProfileChanged -= HandleProfileChanged;
    }

    public void ShowPreviousCharacter() => ChangePreview(-1);
    public void ShowNextCharacter() => ChangePreview(1);

    public async void SelectPreviewCharacter()
    {
        PlayerCharacterData character = CurrentCharacter;
        PlayerProfileData profile = session?.Profile;
        if (IsSaving || session == null || session.IsBusy || profile == null || character == null)
            return;

        if (!IsUnlocked(character, profile))
        {
            SetFeedback("Este personaje aun esta bloqueado.", true);
            RefreshCharacter(profile);
            return;
        }

        IsSaving = true;
        SetInteractable(false);
        await session.UpdateSelectedCharacterAsync(character.CharacterId);
        IsSaving = false;
        SetFeedback(BuildPersistenceMessage("Personaje guardado."), false);
        Refresh(session.Profile);
    }

    public void OpenUsernameEditor()
    {
        if (IsSaving || session == null || session.IsBusy || session.Profile == null)
            return;
        if (usernameInput != null)
        {
            usernameInput.text = session.Profile.username ?? string.Empty;
            usernameInput.ActivateInputField();
        }
        if (usernameEditPanel != null) usernameEditPanel.SetActive(true);
        SetFeedback(string.Empty, false);
    }

    public void CloseUsernameEditor()
    {
        if (IsSaving) return;
        if (usernameEditPanel != null) usernameEditPanel.SetActive(false);
    }

    public async void SaveUsername()
    {
        if (IsSaving || session == null || session.IsBusy || session.Profile == null)
            return;

        string username = usernameInput != null ? usernameInput.text.Trim() : string.Empty;
        if (string.IsNullOrWhiteSpace(username))
        {
            SetFeedback("El nombre no puede estar vacio.", true);
            return;
        }

        if (username.Length > UsernameMaxLength)
            username = username.Substring(0, UsernameMaxLength);

        IsSaving = true;
        SetInteractable(false);
        await session.UpdateUsernameAsync(username);
        IsSaving = false;
        if (usernameEditPanel != null) usernameEditPanel.SetActive(false);
        SetFeedback(BuildPersistenceMessage("Nombre guardado."), false);
        Refresh(session.Profile);
    }

    public void ToggleAccountStatePanel()
    {
        if (accountStatePanel != null && !IsSaving)
            accountStatePanel.SetActive(!accountStatePanel.activeSelf);
    }

    public void CloseAccountStatePanel()
    {
        if (accountStatePanel != null && !IsSaving)
            accountStatePanel.SetActive(false);
    }

    public async void Logout()
    {
        if (IsSaving || session == null || session.IsBusy)
            return;
        IsSaving = true;
        SetInteractable(false);
        await session.SignOutAsync();
        IsSaving = false;
    }

    private void ChangePreview(int direction)
    {
        if (characters == null || characters.Count == 0 || IsSaving || session == null || session.IsBusy)
            return;
        previewCharacterIndex = (previewCharacterIndex + direction + characters.Count) % characters.Count;
        RefreshCharacter(session.Profile);
        SetFeedback(string.Empty, false);
    }

    private void Refresh(PlayerProfileData profile)
    {
        if (profile == null)
        {
            SetInteractable(false);
            return;
        }

        if (!previewInitialized)
        {
            previewCharacterIndex = FindCharacterIndex(profile.selectedCharacterId);
            if (previewCharacterIndex < 0)
            {
                previewCharacterIndex = FindFirstUnlockedIndex(profile);
                Debug.LogWarning($"[PlayerProfileUI] selectedCharacterId '{profile.selectedCharacterId}' no existe en la lista; se muestra el primer personaje disponible.", this);
            }
            previewInitialized = true;
        }

        if (usernameText != null) usernameText.text = profile.username;
        SetStatistic(bestScoreText, "Mejor puntaje", profile.bestScore);
        SetStatistic(killsText, "Kills en partida", profile.kills);
        SetStatistic(deathsText, "Muertes", profile.deaths);
        SetStatistic(victoriesText, "Victorias", profile.victories);
        SetStatistic(defeatsText, "Derrotas", profile.defeats);
        RefreshAccountState(profile);
        RefreshCharacter(profile);
        SetInteractable(!IsSaving && !session.IsBusy);
    }

    private void RefreshCharacter(PlayerProfileData profile)
    {
        PlayerCharacterData character = CurrentCharacter;
        if (character == null)
        {
            if (characterImage != null) characterImage.enabled = false;
            if (lockImage != null) lockImage.gameObject.SetActive(false);
            if (characterNameText != null) characterNameText.text = "SIN PERSONAJES";
            if (characterSelectionStateText != null) characterSelectionStateText.text = string.Empty;
            return;
        }

        bool unlocked = IsUnlocked(character, profile);
        bool selected = profile != null && string.Equals(profile.selectedCharacterId, character.CharacterId, StringComparison.Ordinal);
        if (characterImage != null)
        {
            characterImage.sprite = character.SilhouetteSprite;
            characterImage.enabled = character.SilhouetteSprite != null;
            characterImage.preserveAspect = true;
            characterImage.color = unlocked ? unlockedColor : lockedColor;
        }
        if (lockImage != null) lockImage.gameObject.SetActive(!unlocked);
        if (empireIconImage != null)
        {
            empireIconImage.sprite = character.EmpireIcon != null ? character.EmpireIcon : fallbackEmpireIcon;
            empireIconImage.enabled = empireIconImage.sprite != null;
            empireIconImage.preserveAspect = true;
        }
        if (characterNameText != null) characterNameText.text = character.DisplayName;
        if (characterSelectionStateText != null)
            characterSelectionStateText.text = !unlocked ? "BLOQUEADO" : selected ? "SELECCIONADO" : "SELECCIONAR";
        if (selectCharacterButton != null)
            selectCharacterButton.interactable = unlocked && !selected && !IsSaving && session != null && !session.IsBusy;
    }

    private void RefreshAccountState(PlayerProfileData profile)
    {
        bool guest = session != null && session.IsGuest;
        if (accountStatusText != null)
        {
            accountStatusText.gameObject.SetActive(showAccountStatus);
            string status = guest ? "INVITADO" : "CUENTA VINCULADA";
            if (showDebugPlayerId && !string.IsNullOrWhiteSpace(profile.playerId))
                status += $"  |  {ShortPlayerId(profile.playerId)}";
            accountStatusText.text = status;
        }

        if (accountStateMessageText != null)
        {
            accountStateMessageText.text = guest && showGuestLinkPrompt
                ? "Tu progreso esta guardado. La vinculacion con Google Play Games y Apple estara disponible mas adelante."
                : "Tu cuenta esta vinculada y el progreso se sincroniza con Unity Cloud Save.";
        }
        if (linkAccountButton != null)
        {
            linkAccountButton.gameObject.SetActive(guest && showGuestLinkPrompt);
            linkAccountButton.interactable = false;
        }
    }

    private bool IsUnlocked(PlayerCharacterData character, PlayerProfileData profile)
    {
        if (character == null) return false;
        if (character.IsUnlockedByDefault) return true;
        return profile?.unlockedCharacters != null && profile.unlockedCharacters.Contains(character.CharacterId);
    }

    private int FindCharacterIndex(string characterId)
    {
        if (characters == null) return -1;
        return characters.FindIndex(character => character != null
            && string.Equals(character.CharacterId, characterId, StringComparison.Ordinal));
    }

    private int FindFirstUnlockedIndex(PlayerProfileData profile)
    {
        if (characters == null || characters.Count == 0) return 0;
        int index = characters.FindIndex(character => IsUnlocked(character, profile));
        return index >= 0 ? index : 0;
    }

    private string BuildPersistenceMessage(string success)
    {
        if (session == null) return success;
        if (!string.IsNullOrWhiteSpace(session.LastPersistenceWarning))
            return success + " Se usara la copia local hasta recuperar conexion.";
        return success;
    }

    private void SetFeedback(string message, bool isError)
    {
        if (feedbackText == null) return;
        feedbackText.text = message;
        feedbackText.color = isError ? new Color(1f, 0.48f, 0.42f, 1f) : new Color(1f, 0.82f, 0.25f, 1f);
    }

    private void SetInteractable(bool interactable)
    {
        bool canNavigate = interactable && characters != null && characters.Count > 1;
        if (previousCharacterButton != null) previousCharacterButton.interactable = canNavigate;
        if (nextCharacterButton != null) nextCharacterButton.interactable = canNavigate;
        if (editUsernameButton != null) editUsernameButton.interactable = interactable;
        if (saveUsernameButton != null) saveUsernameButton.interactable = interactable;
        if (cancelUsernameButton != null) cancelUsernameButton.interactable = interactable;
        if (settingsButton != null) settingsButton.interactable = interactable;
        if (closeAccountStateButton != null) closeAccountStateButton.interactable = interactable;
        if (logoutButton != null) logoutButton.interactable = interactable;
        if (backButton != null) backButton.interactable = interactable;
        if (profileTabButton != null) profileTabButton.interactable = false;
        if (shopTabButton != null) shopTabButton.interactable = false;
        if (rewardsTabButton != null) rewardsTabButton.interactable = false;
        RefreshCharacter(session?.Profile);
    }

    private void BindButtons()
    {
        Bind(previousCharacterButton, ShowPreviousCharacter);
        Bind(nextCharacterButton, ShowNextCharacter);
        Bind(selectCharacterButton, SelectPreviewCharacter);
        Bind(editUsernameButton, OpenUsernameEditor);
        Bind(saveUsernameButton, SaveUsername);
        Bind(cancelUsernameButton, CloseUsernameEditor);
        Bind(settingsButton, ToggleAccountStatePanel);
        Bind(closeAccountStateButton, CloseAccountStatePanel);
        Bind(logoutButton, Logout);
    }

    private static void Bind(Button button, UnityEngine.Events.UnityAction action)
    {
        if (button == null) return;
        button.onClick.RemoveListener(action);
        button.onClick.AddListener(action);
    }

    private void HandleSessionStateChanged(PlayerSessionState _) => Refresh(session?.Profile);
    private void HandleProfileChanged(PlayerProfileData profile) => Refresh(profile);

    private static void SetStatistic(TMP_Text target, string label, int value)
    {
        if (target != null) target.text = $"{label}  <color=#D8AF37>..........</color>  {Mathf.Max(0, value)}";
    }

    private static string ShortPlayerId(string playerId)
    {
        return playerId.Length <= 8 ? playerId : playerId.Substring(0, 4) + "..." + playerId.Substring(playerId.Length - 4);
    }

    private void ValidateReferences()
    {
        if (characters == null || characters.Count == 0)
            Debug.LogWarning("[PlayerProfileUI] No hay personajes configurados.", this);
        if (characterImage == null)
            Debug.LogWarning("[PlayerProfileUI] Falta la imagen principal del personaje.", this);
        if (usernameText == null)
            Debug.LogWarning("[PlayerProfileUI] Falta el texto de username.", this);
        if (previousCharacterButton == null || nextCharacterButton == null)
            Debug.LogWarning("[PlayerProfileUI] Faltan una o ambas flechas de personaje.", this);
        if (lockImage == null)
            Debug.LogWarning("[PlayerProfileUI] Falta la imagen de candado; los bloqueos seguiran siendo funcionales.", this);
        foreach (PlayerCharacterData character in characters)
        {
            if (character == null || character.SilhouetteSprite == null)
                Debug.LogWarning("[PlayerProfileUI] Hay un personaje sin datos o sin silueta asignada.", this);
        }
    }

#if UNITY_EDITOR
    public void ConfigureCharactersInEditor(IEnumerable<PlayerCharacterData> configuredCharacters)
    {
        characters = configuredCharacters != null
            ? new List<PlayerCharacterData>(configuredCharacters)
            : new List<PlayerCharacterData>();
    }
#endif
}
