#if UNITY_EDITOR
using System.Collections.Generic;
using System.Linq;
using TMPro;
using UnityEditor;
using UnityEditor.Events;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public static class PlayerAccountSetupRunner
{
    private const string AccountScenePath = "Assets/Scenes/PlayerAccountScene.unity";
    private const string MainMenuScenePath = "Assets/Scenes/MainMenu.unity";

    private static readonly Color Background = new Color(0.025f, 0.035f, 0.045f, 1f);
    private static readonly Color Surface = new Color(0.075f, 0.10f, 0.115f, 0.98f);
    private static readonly Color Accent = new Color(0.16f, 0.72f, 0.62f, 1f);
    private static readonly Color Secondary = new Color(0.17f, 0.21f, 0.23f, 1f);
    private static readonly Color TextPrimary = new Color(0.95f, 0.97f, 0.96f, 1f);
    private static readonly Color TextMuted = new Color(0.66f, 0.72f, 0.72f, 1f);

    [MenuItem("Tools/Vortex Athena/Setup Player Account Base")]
    public static void RunFromMenu()
    {
        PlayerProfileSceneBuilder.BuildAccountScene();
        AddSceneToBuildSettings();
        WireMainMenu();
        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();
        Debug.Log("[PlayerAccountSetup] Account scene and MainMenu gate configured.");
    }

    [MenuItem("Tools/Vortex Athena/Test Account/Simulate Login")]
    public static void SimulateLoginInPlayMode()
    {
        if (!EditorApplication.isPlaying)
        {
            Debug.LogWarning("[PlayerAccountSetup] Enter Play Mode before simulating login.");
            return;
        }

        PlayerAccountController controller = Object.FindFirstObjectByType<PlayerAccountController>();
        if (controller == null)
        {
            Debug.LogWarning("[PlayerAccountSetup] PlayerAccountController was not found.");
            return;
        }

        controller.SimulateLogin();
    }

    [MenuItem("Tools/Vortex Athena/Test Account/Simulate Logout")]
    public static void SimulateLogoutInPlayMode()
    {
        if (!EditorApplication.isPlaying)
        {
            Debug.LogWarning("[PlayerAccountSetup] Enter Play Mode before simulating logout.");
            return;
        }

        PlayerAccountController controller = Object.FindFirstObjectByType<PlayerAccountController>();
        if (controller != null)
            controller.Logout();
    }

    [MenuItem("Tools/Vortex Athena/Test Account/Click MainMenu Profile")]
    public static void ClickMainMenuProfile()
    {
        ClickRuntimeButton("Perfil");
    }

    [MenuItem("Tools/Vortex Athena/Test Account/Click MainMenu Online")]
    public static void ClickMainMenuOnline()
    {
        ClickRuntimeButton("PlayEnLinea");
    }

    [MenuItem("Tools/Vortex Athena/Test Account/Click Go To Account")]
    public static void ClickGoToAccount()
    {
        ClickRuntimeButton("GoToAccountButton");
    }

    [MenuItem("Tools/Vortex Athena/Test Account/Click Login")]
    public static void ClickLogin()
    {
        ClickRuntimeButton("SimulatedLoginButton");
    }

    [MenuItem("Tools/Vortex Athena/Test Account/Click Logout")]
    public static void ClickLogout()
    {
        ClickRuntimeButton("LogoutButton");
    }

    [MenuItem("Tools/Vortex Athena/Test Account/Click Back")]
    public static void ClickBack()
    {
        ClickRuntimeButton("BackButton");
    }

    [MenuItem("Tools/Vortex Athena/Test Account/Profile/Previous Character")]
    public static void ClickPreviousCharacter() => ClickRuntimeButton("PreviousCharacterButton");

    [MenuItem("Tools/Vortex Athena/Test Account/Profile/Next Character")]
    public static void ClickNextCharacter() => ClickRuntimeButton("NextCharacterButton");

    [MenuItem("Tools/Vortex Athena/Test Account/Profile/Select Character")]
    public static void ClickSelectCharacter() => ClickRuntimeButton("SelectCharacterButton");

    [MenuItem("Tools/Vortex Athena/Test Account/Profile/Open Username Editor")]
    public static void OpenUsernameEditor() => ClickRuntimeButton("EditUsernameButton");

    [MenuItem("Tools/Vortex Athena/Test Account/Profile/Set Test Username And Save")]
    public static void SetTestUsernameAndSave()
    {
        if (!EditorApplication.isPlaying) return;
        TMP_InputField input = Resources.FindObjectsOfTypeAll<TMP_InputField>()
            .FirstOrDefault(candidate => candidate.name == "UsernameInput" && candidate.gameObject.activeInHierarchy);
        if (input == null)
        {
            Debug.LogWarning("[PlayerAccountTest] Active UsernameInput was not found.");
            return;
        }
        input.text = "Perfil MCP";
        ClickRuntimeButton("SaveUsernameButton");
    }

    [MenuItem("Tools/Vortex Athena/Test Account/Report State")]
    public static void ReportRuntimeState()
    {
        if (!EditorApplication.isPlaying)
        {
            Debug.LogWarning("[PlayerAccountTest] Enter Play Mode before reporting state.");
            return;
        }

        PlayerSessionManager session = Object.FindFirstObjectByType<PlayerSessionManager>();
        MainMenuAccountRouter router = Object.FindFirstObjectByType<MainMenuAccountRouter>();
        PlayerAccountController account = Object.FindFirstObjectByType<PlayerAccountController>();
        string sessionState = session == null ? "missing" : session.State.ToString();
        string routerState = router == null ? "n/a" : $"onlineLocked={router.IsOnlineLocked}, dialog={router.IsLoginRequiredDialogVisible}";
        string accountState = account == null ? "n/a" : $"guestView={account.IsShowingGuest}, login={account.IsShowingLogin}, profile={account.IsShowingProfile}";
        Debug.Log($"[PlayerAccountTest] scene={SceneManager.GetActiveScene().name}; session={sessionState}; {routerState}; {accountState}");
    }

    [MenuItem("Tools/Vortex Athena/Test Account/Update And Reload Profile")]
    public static async void UpdateAndReloadProfile()
    {
        if (!EditorApplication.isPlaying)
        {
            Debug.LogWarning("[PlayerAccountTest] Enter Play Mode before testing profile persistence.");
            return;
        }

        PlayerAccountController controller = Object.FindFirstObjectByType<PlayerAccountController>();
        if (controller == null || (controller.SessionState != PlayerSessionState.Guest
            && controller.SessionState != PlayerSessionState.Linked))
        {
            Debug.LogWarning("[PlayerAccountTest] An authenticated Guest or Linked session is required.");
            return;
        }

        controller.SimulateProfileUpdateAndReload();
        await System.Threading.Tasks.Task.Delay(500);
        Debug.Log($"[PlayerAccountTest] profileRoundTrip username={controller.ProfileUsername}; character={controller.SelectedCharacterId}");
    }

    private static void ClickRuntimeButton(string buttonName)
    {
        if (!EditorApplication.isPlaying)
        {
            Debug.LogWarning("[PlayerAccountTest] Enter Play Mode before clicking runtime UI.");
            return;
        }

        Button[] buttons = Resources.FindObjectsOfTypeAll<Button>();
        Scene activeScene = SceneManager.GetActiveScene();
        Button button = buttons.FirstOrDefault(candidate => candidate.name == buttonName
            && candidate.gameObject.scene == activeScene
            && candidate.gameObject.activeInHierarchy);
        if (button == null)
        {
            Debug.LogWarning($"[PlayerAccountTest] Active button '{buttonName}' was not found.");
            return;
        }

        button.onClick.Invoke();
        Debug.Log($"[PlayerAccountTest] Clicked '{buttonName}'.");
    }

    private static void CreateAccountScene()
    {
        Scene scene = EditorSceneManager.NewScene(NewSceneSetup.EmptyScene, NewSceneMode.Single);

        GameObject settings = new GameObject("SceneSettings");
        settings.AddComponent<ForceOrientation>();
        CreateAccountServices();

        GameObject cameraObject = new GameObject("Main Camera", typeof(Camera), typeof(AudioListener));
        cameraObject.tag = "MainCamera";
        Camera camera = cameraObject.GetComponent<Camera>();
        camera.clearFlags = CameraClearFlags.SolidColor;
        camera.backgroundColor = Background;
        camera.orthographic = true;
        cameraObject.transform.position = new Vector3(0f, 0f, -10f);

        CreateEventSystem();

        GameObject canvasObject = new GameObject("Canvas_PlayerAccount", typeof(RectTransform), typeof(Canvas), typeof(CanvasScaler), typeof(GraphicRaycaster));
        Canvas canvas = canvasObject.GetComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        CanvasScaler scaler = canvasObject.GetComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1080f, 1920f);
        scaler.screenMatchMode = CanvasScaler.ScreenMatchMode.MatchWidthOrHeight;
        scaler.matchWidthOrHeight = 0.5f;

        Image background = CreateImage(canvasObject, "Background", Background);
        Stretch(background.rectTransform);

        GameObject safeArea = new GameObject("SafeArea", typeof(RectTransform), typeof(SafeAreaHandler));
        safeArea.transform.SetParent(canvasObject.transform, false);
        Stretch(safeArea.GetComponent<RectTransform>());

        TMP_FontAsset font = TMP_Settings.defaultFontAsset;
        GameObject header = CreateRect(safeArea, "Header", new Vector2(0f, 180f));
        SetTopStretch(header.GetComponent<RectTransform>(), 180f, 0f);
        Image headerRule = CreateImage(header, "HeaderRule", new Color(Accent.r, Accent.g, Accent.b, 0.7f));
        RectTransform headerRuleRect = headerRule.rectTransform;
        headerRuleRect.anchorMin = new Vector2(0f, 0f);
        headerRuleRect.anchorMax = new Vector2(1f, 0f);
        headerRuleRect.pivot = new Vector2(0.5f, 0f);
        headerRuleRect.sizeDelta = new Vector2(0f, 3f);

        Button backButton = CreateButton(header, "BackButton", "VOLVER", new Vector2(230f, 82f), font, Secondary);
        RectTransform backRect = backButton.GetComponent<RectTransform>();
        backRect.anchorMin = backRect.anchorMax = new Vector2(0f, 0.5f);
        backRect.pivot = new Vector2(0f, 0.5f);
        backRect.anchoredPosition = new Vector2(48f, 0f);

        TMP_Text headerTitle = CreateText(header, "HeaderTitle", "CUENTA", 44f, FontStyles.Bold, font, TextPrimary);
        Stretch(headerTitle.rectTransform, 300f, 30f, 30f, 30f);
        headerTitle.alignment = TextAlignmentOptions.Center;

        GameObject content = CreateRect(safeArea, "Content", Vector2.zero);
        Stretch(content.GetComponent<RectTransform>(), 54f, 54f, 210f, 60f);

        GameObject loginPanel = CreatePanel(content, "LoginPanel");
        TMP_Text loginTitle = CreateText(loginPanel, "Title", "CUENTA DE JUGADOR", 54f, FontStyles.Bold, font, TextPrimary);
        SetCentered(loginTitle.rectTransform, new Vector2(0f, 310f), new Vector2(900f, 100f));
        TMP_Text loginCopy = CreateText(loginPanel, "Description", "Estas jugando como invitado. Vincula una cuenta para proteger tu progreso y acceder a funciones online.", 32f, FontStyles.Normal, font, TextMuted);
        SetCentered(loginCopy.rectTransform, new Vector2(0f, 165f), new Vector2(860f, 170f));
        loginCopy.alignment = TextAlignmentOptions.Center;

        Button loginButton = CreateButton(loginPanel, "SimulatedLoginButton", "VINCULAR CUENTA", new Vector2(760f, 106f), font, Accent);
        SetCentered(loginButton.GetComponent<RectTransform>(), new Vector2(0f, -25f), new Vector2(760f, 106f));
        Button showRegisterButton = CreateButton(loginPanel, "ShowRegisterButton", "VER OPCIONES DE CUENTA", new Vector2(760f, 96f), font, Secondary);
        SetCentered(showRegisterButton.GetComponent<RectTransform>(), new Vector2(0f, -155f), new Vector2(760f, 96f));
        TMP_Text providerText = CreateText(loginPanel, "ProviderText", "Inicializando sesion...", 25f, FontStyles.Normal, font, TextMuted);
        SetCentered(providerText.rectTransform, new Vector2(0f, -275f), new Vector2(800f, 60f));
        providerText.alignment = TextAlignmentOptions.Center;

        GameObject registerPanel = CreatePanel(content, "RegisterPanel");
        registerPanel.SetActive(false);
        TMP_Text registerTitle = CreateText(registerPanel, "Title", "CREAR CUENTA", 54f, FontStyles.Bold, font, TextPrimary);
        SetCentered(registerTitle.rectTransform, new Vector2(0f, 285f), new Vector2(900f, 100f));
        TMP_Text registerCopy = CreateText(registerPanel, "Description", "Android usara Google Play Games e iOS usara Apple o Game Center mediante un adaptador de plataforma.", 31f, FontStyles.Normal, font, TextMuted);
        SetCentered(registerCopy.rectTransform, new Vector2(0f, 115f), new Vector2(850f, 220f));
        registerCopy.alignment = TextAlignmentOptions.Center;
        Button registerButton = CreateButton(registerPanel, "SimulatedRegisterButton", "VINCULAR CUENTA", new Vector2(760f, 106f), font, Accent);
        SetCentered(registerButton.GetComponent<RectTransform>(), new Vector2(0f, -95f), new Vector2(760f, 106f));
        Button registerBackButton = CreateButton(registerPanel, "RegisterBackButton", "REGRESAR", new Vector2(760f, 96f), font, Secondary);
        SetCentered(registerBackButton.GetComponent<RectTransform>(), new Vector2(0f, -225f), new Vector2(760f, 96f));

        GameObject profilePanel = CreatePanel(content, "ProfilePanel");
        profilePanel.SetActive(false);
        TMP_Text displayName = CreateText(profilePanel, "DisplayName", "Piloto", 58f, FontStyles.Bold, font, TextPrimary);
        SetCentered(displayName.rectTransform, new Vector2(0f, 410f), new Vector2(900f, 90f));
        TMP_Text playerId = CreateText(profilePanel, "PlayerId", "ID: --", 23f, FontStyles.Normal, font, TextMuted);
        SetCentered(playerId.rectTransform, new Vector2(0f, 345f), new Vector2(900f, 50f));
        TMP_Text character = CreateText(profilePanel, "SelectedCharacter", "Personaje: default", 34f, FontStyles.Bold, font, TextPrimary);
        SetCentered(character.rectTransform, new Vector2(0f, 230f), new Vector2(900f, 70f));
        TMP_Text stats = CreateText(profilePanel, "Stats", "Victorias 0   Derrotas 0\nKills 0   Muertes 0", 30f, FontStyles.Normal, font, TextMuted);
        SetCentered(stats.rectTransform, new Vector2(0f, 105f), new Vector2(900f, 120f));

        Button characterModule = CreateButton(profilePanel, "CharacterModuleButton", "PERSONAJE - PROXIMAMENTE", new Vector2(820f, 88f), font, Secondary);
        SetCentered(characterModule.GetComponent<RectTransform>(), new Vector2(0f, -60f), new Vector2(820f, 88f));
        characterModule.interactable = false;
        Button rewardsModule = CreateButton(profilePanel, "RewardsModuleButton", "RECOMPENSAS - PROXIMAMENTE", new Vector2(820f, 88f), font, Secondary);
        SetCentered(rewardsModule.GetComponent<RectTransform>(), new Vector2(0f, -170f), new Vector2(820f, 88f));
        rewardsModule.interactable = false;
        Button shopModule = CreateButton(profilePanel, "ShopModuleButton", "TIENDA - PROXIMAMENTE", new Vector2(820f, 88f), font, Secondary);
        SetCentered(shopModule.GetComponent<RectTransform>(), new Vector2(0f, -280f), new Vector2(820f, 88f));
        shopModule.interactable = false;
        Button logoutButton = CreateButton(profilePanel, "LogoutButton", "CERRAR SESION", new Vector2(620f, 96f), font, new Color(0.42f, 0.16f, 0.18f, 1f));
        SetCentered(logoutButton.GetComponent<RectTransform>(), new Vector2(0f, -425f), new Vector2(620f, 96f));

        GameObject busyOverlay = CreatePanel(canvasObject, "BusyOverlay");
        busyOverlay.GetComponent<Image>().color = new Color(0f, 0f, 0f, 0.7f);
        TMP_Text busyText = CreateText(busyOverlay, "BusyText", "PROCESANDO...", 38f, FontStyles.Bold, font, TextPrimary);
        SetCentered(busyText.rectTransform, Vector2.zero, new Vector2(700f, 100f));
        busyOverlay.SetActive(false);

        GameObject controllerObject = new GameObject("PlayerAccountController", typeof(PlayerAccountController));
        PlayerAccountController controller = controllerObject.GetComponent<PlayerAccountController>();
        SerializedObject serializedController = new SerializedObject(controller);
        Set(serializedController, "loginPanel", loginPanel);
        Set(serializedController, "registerPanel", registerPanel);
        Set(serializedController, "profilePanel", profilePanel);
        Set(serializedController, "busyOverlay", busyOverlay);
        Set(serializedController, "simulatedLoginButton", loginButton);
        Set(serializedController, "showRegisterButton", showRegisterButton);
        Set(serializedController, "loginProviderText", providerText);
        Set(serializedController, "simulatedRegisterButton", registerButton);
        Set(serializedController, "registerBackButton", registerBackButton);
        Set(serializedController, "displayNameText", displayName);
        Set(serializedController, "playerIdText", playerId);
        Set(serializedController, "selectedCharacterText", character);
        Set(serializedController, "statsText", stats);
        Set(serializedController, "logoutButton", logoutButton);
        Set(serializedController, "backButton", backButton);
        serializedController.ApplyModifiedPropertiesWithoutUndo();

        EditorSceneManager.SaveScene(scene, AccountScenePath);
    }

    private static void WireMainMenu()
    {
        Scene scene = EditorSceneManager.OpenScene(MainMenuScenePath, OpenSceneMode.Single);
        GameObject canvas = FindSceneObject(scene, "Canvas_MainMenu");
        Button profileButton = FindButton(scene, "Perfil");
        Button onlineButton = FindButton(scene, "PlayEnLinea");
        if (canvas == null || profileButton == null || onlineButton == null)
        {
            Debug.LogWarning("[PlayerAccountSetup] Canvas_MainMenu, Perfil or PlayEnLinea was not found.");
            return;
        }

        GameObject oldRouting = FindSceneObject(scene, "AccountRouting");
        if (oldRouting != null)
            Object.DestroyImmediate(oldRouting);
        GameObject oldServices;
        while ((oldServices = FindSceneObject(scene, "PlayerAccountServices")) != null)
            Object.DestroyImmediate(oldServices);
        Transform oldDialog = canvas.transform.Find("LoginRequiredDialog");
        if (oldDialog != null)
            Object.DestroyImmediate(oldDialog.gameObject);

        ClearPersistentCalls(profileButton);
        ClearPersistentCalls(onlineButton);
        onlineButton.enabled = true;

        TMP_FontAsset font = TMP_Settings.defaultFontAsset;
        GameObject dialog = CreatePanel(canvas, "LoginRequiredDialog");
        dialog.GetComponent<Image>().color = new Color(0f, 0f, 0f, 0.78f);
        dialog.transform.SetAsLastSibling();

        Image dialogSurface = CreateImage(dialog, "DialogSurface", Surface);
        SetCentered(dialogSurface.rectTransform, Vector2.zero, new Vector2(760f, 500f));
        TMP_Text title = CreateText(dialogSurface.gameObject, "Title", "ACCESO ONLINE", 43f, FontStyles.Bold, font, TextPrimary);
        SetCentered(title.rectTransform, new Vector2(0f, 155f), new Vector2(650f, 70f));
        TMP_Text message = CreateText(dialogSurface.gameObject, "Message", "Vincula una cuenta para acceder al multijugador online.", 29f, FontStyles.Normal, font, TextMuted);
        SetCentered(message.rectTransform, new Vector2(0f, 55f), new Vector2(640f, 120f));
        message.alignment = TextAlignmentOptions.Center;
        Button accountButton = CreateButton(dialogSurface.gameObject, "GoToAccountButton", "IR A CUENTA", new Vector2(600f, 92f), font, Accent);
        SetCentered(accountButton.GetComponent<RectTransform>(), new Vector2(0f, -70f), new Vector2(600f, 92f));
        Button dismissButton = CreateButton(dialogSurface.gameObject, "DismissButton", "AHORA NO", new Vector2(600f, 82f), font, Secondary);
        SetCentered(dismissButton.GetComponent<RectTransform>(), new Vector2(0f, -175f), new Vector2(600f, 82f));
        dialog.SetActive(false);

        GameObject routing = new GameObject("AccountRouting", typeof(MainMenuAccountRouter));
        CreateAccountServices();
        MainMenuAccountRouter router = routing.GetComponent<MainMenuAccountRouter>();
        SerializedObject serializedRouter = new SerializedObject(router);
        Set(serializedRouter, "profileButton", profileButton);
        Set(serializedRouter, "onlineButton", onlineButton);
        Set(serializedRouter, "onlineButtonGraphic", onlineButton.targetGraphic);
        Set(serializedRouter, "loginRequiredDialog", dialog);
        Set(serializedRouter, "loginRequiredText", message);
        Set(serializedRouter, "goToAccountButton", accountButton);
        Set(serializedRouter, "dismissButton", dismissButton);
        serializedRouter.ApplyModifiedPropertiesWithoutUndo();

        EditorSceneManager.MarkSceneDirty(scene);
        EditorSceneManager.SaveScene(scene);
    }

    private static void AddSceneToBuildSettings()
    {
        List<EditorBuildSettingsScene> scenes = EditorBuildSettings.scenes.ToList();
        if (scenes.All(scene => scene.path != AccountScenePath))
            scenes.Add(new EditorBuildSettingsScene(AccountScenePath, true));
        else
        {
            foreach (EditorBuildSettingsScene scene in scenes)
                if (scene.path == AccountScenePath) scene.enabled = true;
        }
        EditorBuildSettings.scenes = scenes.ToArray();
    }

    private static void CreateEventSystem()
    {
        GameObject eventSystem = new GameObject("EventSystem", typeof(EventSystem));
        System.Type inputModuleType = System.Type.GetType("UnityEngine.InputSystem.UI.InputSystemUIInputModule, Unity.InputSystem");
        if (inputModuleType != null)
            eventSystem.AddComponent(inputModuleType);
        else
            eventSystem.AddComponent<StandaloneInputModule>();
    }

    private static void CreateAccountServices()
    {
        GameObject services = new GameObject("PlayerAccountServices", typeof(PlayerSessionManager), typeof(MobilePlatformAccountLinker));
        SerializedObject serializedManager = new SerializedObject(services.GetComponent<PlayerSessionManager>());
        Set(serializedManager, "platformLinker", services.GetComponent<MobilePlatformAccountLinker>());
        serializedManager.ApplyModifiedPropertiesWithoutUndo();
    }

    private static GameObject CreatePanel(GameObject parent, string name)
    {
        Image image = CreateImage(parent, name, Color.clear);
        Stretch(image.rectTransform);
        return image.gameObject;
    }

    private static GameObject CreateRect(GameObject parent, string name, Vector2 size)
    {
        GameObject gameObject = new GameObject(name, typeof(RectTransform));
        gameObject.transform.SetParent(parent.transform, false);
        gameObject.GetComponent<RectTransform>().sizeDelta = size;
        return gameObject;
    }

    private static Image CreateImage(GameObject parent, string name, Color color)
    {
        GameObject gameObject = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(Image));
        gameObject.transform.SetParent(parent.transform, false);
        Image image = gameObject.GetComponent<Image>();
        image.color = color;
        return image;
    }

    private static TMP_Text CreateText(GameObject parent, string name, string value, float fontSize, FontStyles style, TMP_FontAsset font, Color color)
    {
        GameObject gameObject = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(TextMeshProUGUI));
        gameObject.transform.SetParent(parent.transform, false);
        TMP_Text text = gameObject.GetComponent<TMP_Text>();
        text.text = value;
        text.font = font;
        text.fontSize = fontSize;
        text.fontStyle = style;
        text.color = color;
        text.alignment = TextAlignmentOptions.Center;
        text.enableWordWrapping = true;
        return text;
    }

    private static Button CreateButton(GameObject parent, string name, string label, Vector2 size, TMP_FontAsset font, Color color)
    {
        GameObject gameObject = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(Image), typeof(Button));
        gameObject.transform.SetParent(parent.transform, false);
        RectTransform rect = gameObject.GetComponent<RectTransform>();
        rect.sizeDelta = size;
        Image image = gameObject.GetComponent<Image>();
        image.color = color;
        Button button = gameObject.GetComponent<Button>();
        button.targetGraphic = image;

        TMP_Text text = CreateText(gameObject, "Label", label, 29f, FontStyles.Bold, font, TextPrimary);
        Stretch(text.rectTransform, 22f, 22f, 8f, 8f);
        return button;
    }

    private static void ClearPersistentCalls(Button button)
    {
        for (int index = button.onClick.GetPersistentEventCount() - 1; index >= 0; index--)
            UnityEventTools.RemovePersistentListener(button.onClick, index);
    }

    private static Button FindButton(Scene scene, string name)
    {
        foreach (GameObject root in scene.GetRootGameObjects())
        {
            Button[] buttons = root.GetComponentsInChildren<Button>(true);
            Button active = buttons.FirstOrDefault(button => button.name == name && button.gameObject.activeSelf);
            if (active != null) return active;
            Button any = buttons.FirstOrDefault(button => button.name == name);
            if (any != null) return any;
        }
        return null;
    }

    private static GameObject FindSceneObject(Scene scene, string name)
    {
        foreach (GameObject root in scene.GetRootGameObjects())
        {
            if (root.name == name) return root;
            Transform[] transforms = root.GetComponentsInChildren<Transform>(true);
            Transform match = transforms.FirstOrDefault(item => item.name == name);
            if (match != null) return match.gameObject;
        }
        return null;
    }

    private static void Set(SerializedObject target, string propertyName, Object value)
    {
        SerializedProperty property = target.FindProperty(propertyName);
        if (property != null) property.objectReferenceValue = value;
    }

    private static void SetCentered(RectTransform rect, Vector2 position, Vector2 size)
    {
        rect.anchorMin = rect.anchorMax = rect.pivot = new Vector2(0.5f, 0.5f);
        rect.anchoredPosition = position;
        rect.sizeDelta = size;
    }

    private static void SetTopStretch(RectTransform rect, float height, float top)
    {
        rect.anchorMin = new Vector2(0f, 1f);
        rect.anchorMax = new Vector2(1f, 1f);
        rect.pivot = new Vector2(0.5f, 1f);
        rect.anchoredPosition = new Vector2(0f, -top);
        rect.sizeDelta = new Vector2(0f, height);
    }

    private static void Stretch(RectTransform rect, float left = 0f, float right = 0f, float top = 0f, float bottom = 0f)
    {
        rect.anchorMin = Vector2.zero;
        rect.anchorMax = Vector2.one;
        rect.offsetMin = new Vector2(left, bottom);
        rect.offsetMax = new Vector2(-right, -top);
    }
}
#endif
