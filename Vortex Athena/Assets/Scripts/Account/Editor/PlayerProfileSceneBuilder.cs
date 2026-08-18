#if UNITY_EDITOR
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using TMPro;
using UnityEditor;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public static class PlayerProfileSceneBuilder
{
    private const string ScenePath = "Assets/Scenes/PlayerAccountScene.unity";
    private const string MainMenuPrefabPath = "Assets/Assets/Prefab/UI/Canvas_MainMenu.prefab";
    private const string CharacterSheetPath = "Assets/Assets/Personajes/Personajes_Siluetas.png";
    private const string UiSheetPath = "Assets/Assets/UI/VA_UINuevo_02.png";
    private const string BackgroundPath = "Assets/Assets/Arena/VA_FN_BG.png";
    private const string CharacterAssetFolder = "Assets/ScriptableObjects/PlayerCharacters";

    private static readonly Color Gold = new Color(0.85f, 0.69f, 0.22f, 1f);
    private static readonly Color White = new Color(0.98f, 0.98f, 0.98f, 1f);
    private static readonly Color Muted = new Color(0.78f, 0.76f, 0.68f, 1f);
    private static readonly Color Dark = new Color(0.025f, 0.022f, 0.018f, 0.96f);

    [MenuItem("Tools/Vortex Athena/Test Account/Set Portrait Game View")]
    public static void SetPortraitGameView()
    {
        Assembly editorAssembly = typeof(Editor).Assembly;
        Type sizesType = editorAssembly.GetType("UnityEditor.GameViewSizes");
        Type sizeType = editorAssembly.GetType("UnityEditor.GameViewSize");
        Type sizeModeType = editorAssembly.GetType("UnityEditor.GameViewSizeType");
        Type gameViewType = editorAssembly.GetType("UnityEditor.GameView");
        if (sizesType == null || sizeType == null || sizeModeType == null || gameViewType == null)
        {
            Debug.LogWarning("[PlayerProfileSetup] Unity Game View reflection API is unavailable.");
            return;
        }

        Type singletonType = typeof(ScriptableSingleton<>).MakeGenericType(sizesType);
        object sizes = singletonType.GetProperty("instance", BindingFlags.Public | BindingFlags.Static)?.GetValue(null);
        MethodInfo getGroup = sizesType.GetMethod("GetGroup", BindingFlags.Public | BindingFlags.Instance);
        Type groupEnumType = getGroup?.GetParameters()[0].ParameterType;
        object standalone = groupEnumType != null ? Enum.Parse(groupEnumType, "Standalone") : null;
        object group = sizes != null && standalone != null ? getGroup.Invoke(sizes, new[] { standalone }) : null;
        if (group == null)
        {
            Debug.LogWarning("[PlayerProfileSetup] Standalone Game View size group was not found.");
            return;
        }

        Type groupType = group.GetType();
        MethodInfo totalMethod = groupType.GetMethod("GetTotalCount");
        MethodInfo getSizeMethod = groupType.GetMethod("GetGameViewSize");
        int total = (int)totalMethod.Invoke(group, null);
        int selectedIndex = -1;
        for (int index = 0; index < total; index++)
        {
            object size = getSizeMethod.Invoke(group, new object[] { index });
            int width = (int)sizeType.GetProperty("width").GetValue(size);
            int height = (int)sizeType.GetProperty("height").GetValue(size);
            if (width == 1080 && height == 1920)
            {
                selectedIndex = index;
                break;
            }
        }

        if (selectedIndex < 0)
        {
            object fixedResolution = Enum.Parse(sizeModeType, "FixedResolution");
            ConstructorInfo constructor = sizeType.GetConstructor(new[] { sizeModeType, typeof(int), typeof(int), typeof(string) });
            object customSize = constructor.Invoke(new[] { fixedResolution, (object)1080, 1920, "Vortex Portrait 1080x1920" });
            groupType.GetMethod("AddCustomSize").Invoke(group, new[] { customSize });
            selectedIndex = (int)totalMethod.Invoke(group, null) - 1;
        }

        EditorWindow gameView = EditorWindow.GetWindow(gameViewType);
        PropertyInfo selectedSize = gameViewType.GetProperty("selectedSizeIndex", BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
        selectedSize?.SetValue(gameView, selectedIndex);
        gameView.Repaint();
        Debug.Log("[PlayerProfileSetup] Game View set to 1080x1920.");
    }

    [MenuItem("Tools/Vortex Athena/Test Account/Capture Portrait Profile")]
    public static void CapturePortraitProfile()
    {
        if (!EditorApplication.isPlaying)
        {
            Debug.LogWarning("[PlayerProfileSetup] Enter Play Mode before capturing the profile.");
            return;
        }

        Canvas canvas = UnityEngine.Object.FindObjectsByType<Canvas>(FindObjectsInactive.Include, FindObjectsSortMode.None)
            .FirstOrDefault(candidate => candidate.name == "Canvas_PlayerAccount");
        if (canvas == null)
        {
            Debug.LogWarning("[PlayerProfileSetup] Canvas_PlayerAccount was not found.");
            return;
        }

        RenderMode previousMode = canvas.renderMode;
        Camera previousCamera = canvas.worldCamera;
        float previousPlaneDistance = canvas.planeDistance;
        RectTransform canvasRect = canvas.GetComponent<RectTransform>();
        Vector2 previousCanvasSize = canvasRect.sizeDelta;
        Vector3 previousCanvasPosition = canvasRect.position;
        Quaternion previousCanvasRotation = canvasRect.rotation;
        Vector3 previousCanvasScale = canvasRect.localScale;
        CanvasScaler canvasScaler = canvas.GetComponent<CanvasScaler>();
        bool previousScalerEnabled = canvasScaler != null && canvasScaler.enabled;
        SafeAreaHandler safeAreaHandler = canvas.GetComponentInChildren<SafeAreaHandler>(true);
        bool previousSafeAreaEnabled = safeAreaHandler != null && safeAreaHandler.enabled;
        RectTransform safeAreaRect = safeAreaHandler != null ? safeAreaHandler.GetComponent<RectTransform>() : null;
        Vector2 previousSafeMin = safeAreaRect != null ? safeAreaRect.anchorMin : Vector2.zero;
        Vector2 previousSafeMax = safeAreaRect != null ? safeAreaRect.anchorMax : Vector2.one;
        Vector2 previousSafeOffsetMin = safeAreaRect != null ? safeAreaRect.offsetMin : Vector2.zero;
        Vector2 previousSafeOffsetMax = safeAreaRect != null ? safeAreaRect.offsetMax : Vector2.zero;
        RenderTexture previousActive = RenderTexture.active;
        GameObject cameraObject = new GameObject("ProfileCaptureCamera", typeof(Camera));
        Camera captureCamera = cameraObject.GetComponent<Camera>();
        RenderTexture target = new RenderTexture(1080, 1920, 24, RenderTextureFormat.ARGB32);
        Texture2D image = new Texture2D(1080, 1920, TextureFormat.RGBA32, false);
        try
        {
            captureCamera.clearFlags = CameraClearFlags.SolidColor;
            captureCamera.backgroundColor = Color.black;
            captureCamera.cullingMask = ~0;
            captureCamera.orthographic = true;
            captureCamera.orthographicSize = 960f;
            captureCamera.transform.position = new Vector3(0f, 0f, -10f);
            captureCamera.targetTexture = target;
            if (canvasScaler != null) canvasScaler.enabled = false;
            if (safeAreaHandler != null) safeAreaHandler.enabled = false;
            canvas.renderMode = RenderMode.WorldSpace;
            canvas.worldCamera = captureCamera;
            canvasRect.sizeDelta = new Vector2(1080f, 1920f);
            canvasRect.position = Vector3.zero;
            canvasRect.rotation = Quaternion.identity;
            canvasRect.localScale = Vector3.one;
            if (safeAreaRect != null)
            {
                safeAreaRect.anchorMin = Vector2.zero;
                safeAreaRect.anchorMax = Vector2.one;
                safeAreaRect.offsetMin = Vector2.zero;
                safeAreaRect.offsetMax = Vector2.zero;
            }
            Canvas.ForceUpdateCanvases();
            captureCamera.Render();
            RenderTexture.active = target;
            image.ReadPixels(new Rect(0f, 0f, 1080f, 1920f), 0, 0);
            image.Apply();
            string folder = Path.Combine(Directory.GetParent(Application.dataPath).FullName, "Temp", "CodexProfile");
            Directory.CreateDirectory(folder);
            string path = Path.Combine(folder, "profile-ui-portrait.png");
            File.WriteAllBytes(path, image.EncodeToPNG());
            Debug.Log($"[PlayerProfileSetup] Portrait profile captured at {path}.");
        }
        finally
        {
            canvas.renderMode = previousMode;
            canvas.worldCamera = previousCamera;
            canvas.planeDistance = previousPlaneDistance;
            canvasRect.sizeDelta = previousCanvasSize;
            canvasRect.position = previousCanvasPosition;
            canvasRect.rotation = previousCanvasRotation;
            canvasRect.localScale = previousCanvasScale;
            if (canvasScaler != null) canvasScaler.enabled = previousScalerEnabled;
            if (safeAreaRect != null)
            {
                safeAreaRect.anchorMin = previousSafeMin;
                safeAreaRect.anchorMax = previousSafeMax;
                safeAreaRect.offsetMin = previousSafeOffsetMin;
                safeAreaRect.offsetMax = previousSafeOffsetMax;
            }
            if (safeAreaHandler != null) safeAreaHandler.enabled = previousSafeAreaEnabled;
            RenderTexture.active = previousActive;
            captureCamera.targetTexture = null;
            UnityEngine.Object.DestroyImmediate(image);
            target.Release();
            UnityEngine.Object.DestroyImmediate(target);
            UnityEngine.Object.DestroyImmediate(cameraObject);
        }
    }

    public static void BuildAccountScene()
    {
        PlayerCharacterData[] characters = EnsureCharacterAssets();
        if (characters.Any(character => character == null))
            throw new InvalidOperationException("One or more PlayerCharacterData assets could not be loaded.");
        Dictionary<string, Sprite> uiSprites = LoadNamedSprites(UiSheetPath);

        Scene scene = EditorSceneManager.NewScene(NewSceneSetup.EmptyScene, NewSceneMode.Single);
        CreateSceneSettings();
        CreateCamera();
        CreateEventSystem();
        CreateAccountServices();

        GameObject canvasObject = new GameObject("Canvas_PlayerAccount", typeof(RectTransform), typeof(Canvas), typeof(CanvasScaler), typeof(GraphicRaycaster));
        Canvas canvas = canvasObject.GetComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        CanvasScaler scaler = canvasObject.GetComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1080f, 1920f);
        scaler.screenMatchMode = CanvasScaler.ScreenMatchMode.MatchWidthOrHeight;
        scaler.matchWidthOrHeight = 0.5f;

        Image background = CreateImage(canvasObject, "Background", AssetDatabase.LoadAssetAtPath<Sprite>(BackgroundPath), Color.white);
        Stretch(background.rectTransform);

        GameObject safeArea = new GameObject("SafeArea", typeof(RectTransform), typeof(SafeAreaHandler));
        safeArea.transform.SetParent(canvasObject.transform, false);
        Stretch(safeArea.GetComponent<RectTransform>());

        GameObject templateRoot = AssetDatabase.LoadAssetAtPath<GameObject>(MainMenuPrefabPath);
        Transform templatePanel = templateRoot != null ? FindDeep(templateRoot.transform, "Panel_Perfil") : null;
        if (templatePanel == null)
            throw new InvalidOperationException("Panel_Perfil was not found in Canvas_MainMenu.prefab.");

        GameObject profilePanel = UnityEngine.Object.Instantiate(templatePanel.gameObject, safeArea.transform);
        profilePanel.name = "Panel_Perfil";
        profilePanel.SetActive(true);
        Stretch(profilePanel.GetComponent<RectTransform>());
        Image panelBackground = profilePanel.GetComponent<Image>();
        if (panelBackground != null) panelBackground.color = Color.clear;
        foreach (Button button in profilePanel.GetComponentsInChildren<Button>(true))
            button.onClick = new Button.ButtonClickedEvent();

        TMP_Text usernameText = Require<TMP_Text>(profilePanel, "Encabezado/Texto");
        TMP_FontAsset font = usernameText.font != null ? usernameText.font : TMP_Settings.defaultFontAsset;
        RectTransform header = RequireRect(profilePanel, "Encabezado");
        SetTopCenter(header, new Vector2(730f, 118f), new Vector2(0f, -178f));
        Image empireIcon = Require<Image>(profilePanel, "Encabezado/Imperio");
        SetCentered(empireIcon.rectTransform, new Vector2(-350f, 0f), new Vector2(142f, 142f));
        Stretch(usernameText.rectTransform, 105f, 36f, 12f, 12f);
        usernameText.fontSize = 58f;
        usernameText.enableAutoSizing = true;
        usernameText.fontSizeMin = 34f;
        usernameText.fontSizeMax = 62f;

        Button editUsernameButton = AddOrGetButton(header.gameObject);
        editUsernameButton.name = "EditUsernameButton";

        Button settingsButton = Require<Button>(profilePanel, "Confi");
        settingsButton.name = "SettingsButton";
        SetTopRight(settingsButton.GetComponent<RectTransform>(), new Vector2(86f, 86f), new Vector2(-62f, -62f));
        Button backButton = Require<Button>(profilePanel, "Atras");
        backButton.name = "BackButton";
        SetTopRight(backButton.GetComponent<RectTransform>(), new Vector2(86f, 86f), new Vector2(-62f, -168f));

        TMP_Text accountStatusText = CreateText(profilePanel, "AccountStatus", "INVITADO", 24f, FontStyles.Bold, font, Gold);
        SetTopCenter(accountStatusText.rectTransform, new Vector2(480f, 34f), new Vector2(0f, -126f));

        Image characterImage = Require<Image>(profilePanel, "Personaje");
        SetCentered(characterImage.rectTransform, new Vector2(0f, 175f), new Vector2(640f, 720f));
        characterImage.preserveAspect = true;
        characterImage.raycastTarget = false;
        if (characters.Length > 0) characterImage.sprite = characters[0].SilhouetteSprite;

        Image lockImage = CreateImage(characterImage.gameObject, "CharacterLock", GetSprite(uiSprites, "VA_UINuevo_02_0"), Color.white);
        SetCentered(lockImage.rectTransform, Vector2.zero, new Vector2(112f, 142f));
        lockImage.preserveAspect = true;
        lockImage.raycastTarget = false;
        lockImage.gameObject.SetActive(false);

        RectTransform dataRoot = RequireRect(profilePanel, "Datos");
        Stretch(dataRoot);
        Button previousButton = Require<Button>(profilePanel, "Datos/Flecha");
        previousButton.name = "PreviousCharacterButton";
        previousButton.GetComponent<Image>().sprite = GetSprite(uiSprites, "VA_UINuevo_02_3");
        previousButton.GetComponent<Image>().preserveAspect = true;
        SetCentered(previousButton.GetComponent<RectTransform>(), new Vector2(-315f, -285f), new Vector2(70f, 104f));
        Button nextButton = Require<Button>(profilePanel, "Datos/Flecha (1)");
        nextButton.name = "NextCharacterButton";
        nextButton.GetComponent<Image>().sprite = GetSprite(uiSprites, "VA_UINuevo_02_4");
        nextButton.GetComponent<Image>().preserveAspect = true;
        SetCentered(nextButton.GetComponent<RectTransform>(), new Vector2(315f, -285f), new Vector2(70f, 104f));

        TMP_Text characterNameText = Require<TMP_Text>(profilePanel, "Datos/Nombre");
        SetCentered(characterNameText.rectTransform, new Vector2(0f, -270f), new Vector2(480f, 72f));
        characterNameText.fontSize = 50f;
        characterNameText.enableAutoSizing = true;
        characterNameText.fontSizeMin = 30f;
        characterNameText.fontSizeMax = 52f;
        characterNameText.color = White;
        characterNameText.fontStyle = FontStyles.Bold;
        Button selectCharacterButton = AddOrGetButton(characterNameText.gameObject);
        selectCharacterButton.name = "SelectCharacterButton";
        selectCharacterButton.targetGraphic = null;
        selectCharacterButton.transition = Selectable.Transition.None;
        TMP_Text selectionStateText = CreateText(profilePanel, "CharacterSelectionState", "SELECCIONADO", 22f, FontStyles.Bold, font, Gold);
        SetCentered(selectionStateText.rectTransform, new Vector2(0f, -327f), new Vector2(420f, 38f));

        TMP_Text bestScore = ConfigureStatistic(profilePanel, "Datos/Puntaje", "Mejor puntaje", -420f);
        TMP_Text kills = ConfigureStatistic(profilePanel, "Datos/Kills", "Kills en partida", -492f);
        TMP_Text deaths = ConfigureStatistic(profilePanel, "Datos/Muertes", "Muertes", -564f);
        TMP_Text victories = ConfigureStatistic(profilePanel, "Datos/Victorias", "Victorias", -636f);
        TMP_Text defeats = ConfigureStatistic(profilePanel, "Datos/Derrotas", "Derrotas", -708f);

        TMP_Text feedbackText = CreateText(profilePanel, "ProfileFeedback", string.Empty, 21f, FontStyles.Normal, font, Gold);
        SetCentered(feedbackText.rectTransform, new Vector2(0f, -772f), new Vector2(820f, 54f));

        Image footer = Require<Image>(profilePanel, "Pie de pagina");
        footer.sprite = GetSprite(uiSprites, "VA_UINuevo_02_17") ?? footer.sprite;
        footer.preserveAspect = true;
        SetBottomCenter(footer.rectTransform, new Vector2(776f, 83f), new Vector2(117f, 48f));
        Image footerFrame = CreateImage(profilePanel, "BottomProfileFrame", GetSprite(uiSprites, "VA_UINuevo_02_15"), Color.white);
        footerFrame.preserveAspect = true;
        SetBottomCenter(footerFrame.rectTransform, new Vector2(96f, 83f), new Vector2(-457f, 48f));
        Image footerProfileIcon = CreateImage(profilePanel, "BottomProfileIcon", GetSprite(uiSprites, "VA_UINuevo_02_16"), Color.white);
        footerProfileIcon.preserveAspect = true;
        SetBottomCenter(footerProfileIcon.rectTransform, new Vector2(64f, 63f), new Vector2(-333f, 58f));
        Button profileTab = CreateInvisibleButton(profilePanel, "ProfileTabButton", new Vector2(110f, 100f), new Vector2(-333f, -862f));
        Button shopTab = CreateInvisibleButton(profilePanel, "ShopTabButton", new Vector2(130f, 100f), new Vector2(-203f, -862f));
        SetBottomCenter(profileTab.GetComponent<RectTransform>(), new Vector2(110f, 100f), new Vector2(-333f, 48f));
        SetBottomCenter(shopTab.GetComponent<RectTransform>(), new Vector2(130f, 100f), new Vector2(-203f, 48f));
        shopTab.interactable = false;

        GameObject futureShopSection = CreatePanel(profilePanel, "FutureShopSection", Color.clear);
        futureShopSection.SetActive(false);
        GameObject futureRewardsSection = CreatePanel(profilePanel, "FutureRewardsSection", Color.clear);
        futureRewardsSection.SetActive(false);

        GameObject usernameEditPanel = CreateModal(profilePanel, "UsernameEditPanel", new Vector2(820f, 430f), font, "EDITAR NOMBRE");
        TMP_InputField usernameInput = CreateInput(usernameEditPanel, "UsernameInput", "Nombre de jugador", font);
        SetCentered(usernameInput.GetComponent<RectTransform>(), new Vector2(0f, 55f), new Vector2(650f, 92f));
        Button saveUsernameButton = CreateButton(usernameEditPanel, "SaveUsernameButton", "GUARDAR", new Vector2(300f, 82f), font, Gold, Color.black);
        SetCentered(saveUsernameButton.GetComponent<RectTransform>(), new Vector2(-170f, -85f), new Vector2(300f, 82f));
        Button cancelUsernameButton = CreateButton(usernameEditPanel, "CancelUsernameButton", "CANCELAR", new Vector2(300f, 82f), font, new Color(0.16f, 0.14f, 0.11f, 1f), White);
        SetCentered(cancelUsernameButton.GetComponent<RectTransform>(), new Vector2(170f, -85f), new Vector2(300f, 82f));
        usernameEditPanel.SetActive(false);

        GameObject accountStatePanel = CreateModal(profilePanel, "AccountStatePanel", new Vector2(850f, 610f), font, "ESTADO DE CUENTA");
        TMP_Text accountMessage = CreateText(accountStatePanel, "AccountStateMessage", string.Empty, 29f, FontStyles.Normal, font, White);
        SetCentered(accountMessage.rectTransform, new Vector2(0f, 105f), new Vector2(700f, 210f));
        accountMessage.alignment = TextAlignmentOptions.Center;
        Button linkButton = CreateButton(accountStatePanel, "LinkAccountButton", "VINCULAR PROXIMAMENTE", new Vector2(650f, 86f), font, new Color(0.24f, 0.21f, 0.13f, 1f), Muted);
        SetCentered(linkButton.GetComponent<RectTransform>(), new Vector2(0f, -55f), new Vector2(650f, 86f));
        linkButton.interactable = false;
        Button logoutButton = CreateButton(accountStatePanel, "LogoutButton", "CERRAR SESION", new Vector2(650f, 86f), font, new Color(0.35f, 0.09f, 0.08f, 1f), White);
        SetCentered(logoutButton.GetComponent<RectTransform>(), new Vector2(0f, -160f), new Vector2(650f, 86f));
        Button closeAccountButton = CreateButton(accountStatePanel, "CloseAccountStateButton", "CERRAR", new Vector2(300f, 70f), font, new Color(0.16f, 0.14f, 0.11f, 1f), White);
        SetCentered(closeAccountButton.GetComponent<RectTransform>(), new Vector2(0f, -255f), new Vector2(300f, 70f));
        accountStatePanel.SetActive(false);

        GameObject signedOutPanel = CreatePanel(safeArea, "LoginPanel", new Color(0f, 0f, 0f, 0.46f));
        TMP_Text signedOutTitle = CreateText(signedOutPanel, "Title", "PERFIL DE JUGADOR", 52f, FontStyles.Bold, font, White);
        SetCentered(signedOutTitle.rectTransform, new Vector2(0f, 160f), new Vector2(840f, 90f));
        TMP_Text signedOutMessage = CreateText(signedOutPanel, "ProviderText", "Continua como invitado para cargar tu perfil.", 29f, FontStyles.Normal, font, Muted);
        SetCentered(signedOutMessage.rectTransform, new Vector2(0f, 55f), new Vector2(780f, 100f));
        Button guestButton = CreateButton(signedOutPanel, "SimulatedLoginButton", "CONTINUAR COMO INVITADO", new Vector2(720f, 100f), font, Gold, Color.black);
        SetCentered(guestButton.GetComponent<RectTransform>(), new Vector2(0f, -80f), new Vector2(720f, 100f));
        Button signedOutBack = CreateButton(signedOutPanel, "SignedOutBackButton", "VOLVER AL MENU", new Vector2(620f, 82f), font, new Color(0.16f, 0.14f, 0.11f, 1f), White);
        SetCentered(signedOutBack.GetComponent<RectTransform>(), new Vector2(0f, -205f), new Vector2(620f, 82f));
        signedOutPanel.SetActive(false);

        GameObject busyOverlay = CreatePanel(canvasObject, "BusyOverlay", new Color(0f, 0f, 0f, 0.72f));
        TMP_Text busyText = CreateText(busyOverlay, "BusyText", "SINCRONIZANDO...", 34f, FontStyles.Bold, font, Gold);
        SetCentered(busyText.rectTransform, Vector2.zero, new Vector2(720f, 90f));
        busyOverlay.SetActive(false);

        PlayerProfileViewController profileController = profilePanel.AddComponent<PlayerProfileViewController>();
        profileController.ConfigureCharactersInEditor(characters);
        EditorUtility.SetDirty(profileController);
        SerializedObject profileSerialized = new SerializedObject(profileController);
        Set(profileSerialized, "characterImage", characterImage);
        Set(profileSerialized, "lockImage", lockImage);
        Set(profileSerialized, "empireIconImage", empireIcon);
        Set(profileSerialized, "fallbackEmpireIcon", empireIcon.sprite);
        Set(profileSerialized, "previousCharacterButton", previousButton);
        Set(profileSerialized, "nextCharacterButton", nextButton);
        Set(profileSerialized, "selectCharacterButton", selectCharacterButton);
        Set(profileSerialized, "characterNameText", characterNameText);
        Set(profileSerialized, "characterSelectionStateText", selectionStateText);
        Set(profileSerialized, "usernameText", usernameText);
        Set(profileSerialized, "editUsernameButton", editUsernameButton);
        Set(profileSerialized, "usernameEditPanel", usernameEditPanel);
        Set(profileSerialized, "usernameInput", usernameInput);
        Set(profileSerialized, "saveUsernameButton", saveUsernameButton);
        Set(profileSerialized, "cancelUsernameButton", cancelUsernameButton);
        Set(profileSerialized, "feedbackText", feedbackText);
        Set(profileSerialized, "bestScoreText", bestScore);
        Set(profileSerialized, "killsText", kills);
        Set(profileSerialized, "deathsText", deaths);
        Set(profileSerialized, "victoriesText", victories);
        Set(profileSerialized, "defeatsText", defeats);
        Set(profileSerialized, "accountStatusText", accountStatusText);
        Set(profileSerialized, "accountStatePanel", accountStatePanel);
        Set(profileSerialized, "accountStateMessageText", accountMessage);
        Set(profileSerialized, "settingsButton", settingsButton);
        Set(profileSerialized, "closeAccountStateButton", closeAccountButton);
        Set(profileSerialized, "linkAccountButton", linkButton);
        Set(profileSerialized, "logoutButton", logoutButton);
        Set(profileSerialized, "backButton", backButton);
        Set(profileSerialized, "profileSection", profilePanel);
        Set(profileSerialized, "futureShopSection", futureShopSection);
        Set(profileSerialized, "futureRewardsSection", futureRewardsSection);
        Set(profileSerialized, "profileTabButton", profileTab);
        Set(profileSerialized, "shopTabButton", shopTab);
        profileSerialized.ApplyModifiedPropertiesWithoutUndo();

        GameObject controllerObject = new GameObject("PlayerAccountController", typeof(PlayerAccountController));
        PlayerAccountController accountController = controllerObject.GetComponent<PlayerAccountController>();
        SerializedObject accountSerialized = new SerializedObject(accountController);
        Set(accountSerialized, "loginPanel", signedOutPanel);
        Set(accountSerialized, "profilePanel", profilePanel);
        Set(accountSerialized, "busyOverlay", busyOverlay);
        Set(accountSerialized, "profileViewController", profileController);
        Set(accountSerialized, "simulatedLoginButton", guestButton);
        Set(accountSerialized, "loginProviderText", signedOutMessage);
        Set(accountSerialized, "backButton", backButton);
        Set(accountSerialized, "signedOutBackButton", signedOutBack);
        accountSerialized.ApplyModifiedPropertiesWithoutUndo();

        EditorSceneManager.MarkSceneDirty(scene);
        EditorSceneManager.SaveScene(scene, ScenePath);
        Debug.Log("[PlayerProfileSetup] PlayerAccountScene rebuilt from Panel_Perfil with four character assets.");
    }

    private static PlayerCharacterData[] EnsureCharacterAssets()
    {
        EnsureFolder("Assets/ScriptableObjects");
        EnsureFolder(CharacterAssetFolder);
        Sprite[] silhouettes = AssetDatabase.LoadAllAssetsAtPath(CharacterSheetPath)
            .OfType<Sprite>()
            .OrderBy(sprite => sprite.name, StringComparer.Ordinal)
            .ToArray();
        if (silhouettes.Length < 4)
            Debug.LogWarning($"[PlayerProfileSetup] Expected 4 silhouettes but found {silhouettes.Length} in {CharacterSheetPath}.");

        CharacterDefinition[] definitions =
        {
            new CharacterDefinition("antares", "Antares", false),
            new CharacterDefinition("bellatrix", "Bellatrix", false),
            new CharacterDefinition("zeta", "Zeta", false),
            new CharacterDefinition("zubenes", "Zubenes", false)
        };
        PlayerCharacterData[] assets = new PlayerCharacterData[definitions.Length];
        for (int index = 0; index < definitions.Length; index++)
        {
            CharacterDefinition definition = definitions[index];
            string path = $"{CharacterAssetFolder}/PlayerCharacter_{definition.DisplayName}.asset";
            PlayerCharacterData asset = AssetDatabase.LoadAssetAtPath<PlayerCharacterData>(path);
            if (asset == null)
            {
                asset = ScriptableObject.CreateInstance<PlayerCharacterData>();
                AssetDatabase.CreateAsset(asset, path);
            }
            SerializedObject serialized = new SerializedObject(asset);
            serialized.FindProperty("characterId").stringValue = definition.Id;
            serialized.FindProperty("displayName").stringValue = definition.DisplayName;
            serialized.FindProperty("isUnlockedByDefault").boolValue = definition.Unlocked;
            serialized.FindProperty("silhouetteSprite").objectReferenceValue = index < silhouettes.Length ? silhouettes[index] : null;
            serialized.ApplyModifiedPropertiesWithoutUndo();
            EditorUtility.SetDirty(asset);
            assets[index] = asset;
        }
        AssetDatabase.SaveAssets();
        for (int index = 0; index < assets.Length; index++)
        {
            string path = AssetDatabase.GetAssetPath(assets[index]);
            assets[index] = AssetDatabase.LoadAssetAtPath<PlayerCharacterData>(path);
        }
        return assets;
    }

    private static TMP_Text ConfigureStatistic(GameObject root, string path, string label, float y)
    {
        TMP_Text text = Require<TMP_Text>(root, path);
        text.text = label;
        text.fontSize = 31f;
        text.enableAutoSizing = true;
        text.fontSizeMin = 21f;
        text.fontSizeMax = 34f;
        text.alignment = TextAlignmentOptions.Left;
        SetCentered(text.rectTransform, new Vector2(0f, y), new Vector2(690f, 56f));
        return text;
    }

    private static GameObject CreateModal(GameObject parent, string name, Vector2 size, TMP_FontAsset font, string title)
    {
        GameObject overlay = CreatePanel(parent, name, new Color(0f, 0f, 0f, 0.78f));
        Image surface = CreateImage(overlay, "Surface", null, Dark);
        SetCentered(surface.rectTransform, Vector2.zero, size);
        Outline outline = surface.gameObject.AddComponent<Outline>();
        outline.effectColor = Gold;
        outline.effectDistance = new Vector2(3f, -3f);
        TMP_Text titleText = CreateText(surface.gameObject, "Title", title, 37f, FontStyles.Bold, font, Gold);
        SetTopCenter(titleText.rectTransform, new Vector2(size.x - 80f, 70f), new Vector2(0f, -38f));
        return overlay;
    }

    private static TMP_InputField CreateInput(GameObject parent, string name, string placeholder, TMP_FontAsset font)
    {
        GameObject root = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(Image), typeof(TMP_InputField));
        root.transform.SetParent(parent.transform, false);
        Image image = root.GetComponent<Image>();
        image.color = new Color(0.08f, 0.07f, 0.055f, 1f);
        Outline outline = root.AddComponent<Outline>();
        outline.effectColor = Gold;
        outline.effectDistance = new Vector2(2f, -2f);
        TMP_Text placeholderText = CreateText(root, "Placeholder", placeholder, 28f, FontStyles.Normal, font, Muted);
        Stretch(placeholderText.rectTransform, 24f, 24f, 12f, 12f);
        placeholderText.alignment = TextAlignmentOptions.MidlineLeft;
        TMP_Text valueText = CreateText(root, "Text", string.Empty, 30f, FontStyles.Normal, font, White);
        Stretch(valueText.rectTransform, 24f, 24f, 12f, 12f);
        valueText.alignment = TextAlignmentOptions.MidlineLeft;
        TMP_InputField input = root.GetComponent<TMP_InputField>();
        input.textViewport = root.GetComponent<RectTransform>();
        input.textComponent = valueText;
        input.placeholder = placeholderText;
        input.lineType = TMP_InputField.LineType.SingleLine;
        input.characterLimit = 20;
        return input;
    }

    private static Button CreateButton(GameObject parent, string name, string label, Vector2 size, TMP_FontAsset font, Color background, Color foreground)
    {
        GameObject root = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(Image), typeof(Button));
        root.transform.SetParent(parent.transform, false);
        root.GetComponent<RectTransform>().sizeDelta = size;
        Image image = root.GetComponent<Image>();
        image.color = background;
        Button button = root.GetComponent<Button>();
        button.targetGraphic = image;
        TMP_Text text = CreateText(root, "Label", label, 27f, FontStyles.Bold, font, foreground);
        Stretch(text.rectTransform, 18f, 18f, 8f, 8f);
        return button;
    }

    private static Button CreateInvisibleButton(GameObject parent, string name, Vector2 size, Vector2 position)
    {
        GameObject root = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(Image), typeof(Button));
        root.transform.SetParent(parent.transform, false);
        Image image = root.GetComponent<Image>();
        image.color = new Color(1f, 1f, 1f, 0.001f);
        SetCentered(root.GetComponent<RectTransform>(), position, size);
        return root.GetComponent<Button>();
    }

    private static TMP_Text CreateText(GameObject parent, string name, string value, float size, FontStyles style, TMP_FontAsset font, Color color)
    {
        GameObject root = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(TextMeshProUGUI));
        root.transform.SetParent(parent.transform, false);
        TMP_Text text = root.GetComponent<TMP_Text>();
        text.text = value;
        text.font = font;
        text.fontSize = size;
        text.fontStyle = style;
        text.color = color;
        text.alignment = TextAlignmentOptions.Center;
        text.enableWordWrapping = true;
        return text;
    }

    private static Image CreateImage(GameObject parent, string name, Sprite sprite, Color color)
    {
        GameObject root = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(Image));
        root.transform.SetParent(parent.transform, false);
        Image image = root.GetComponent<Image>();
        image.sprite = sprite;
        image.color = color;
        return image;
    }

    private static GameObject CreatePanel(GameObject parent, string name, Color color)
    {
        Image image = CreateImage(parent, name, null, color);
        Stretch(image.rectTransform);
        return image.gameObject;
    }

    private static Button AddOrGetButton(GameObject target)
    {
        Button button = target.GetComponent<Button>();
        if (button == null) button = target.AddComponent<Button>();
        button.targetGraphic = target.GetComponent<Graphic>();
        button.onClick = new Button.ButtonClickedEvent();
        return button;
    }

    private static T Require<T>(GameObject root, string path) where T : Component
    {
        Transform target = FindPath(root.transform, path);
        T component = target != null ? target.GetComponent<T>() : null;
        if (component == null) throw new InvalidOperationException($"Required component {typeof(T).Name} at '{path}' was not found.");
        return component;
    }

    private static RectTransform RequireRect(GameObject root, string path) => Require<RectTransform>(root, path);

    private static Transform FindPath(Transform root, string path)
    {
        Transform current = root;
        foreach (string part in path.Split('/'))
        {
            current = current.Cast<Transform>().FirstOrDefault(child => child.name == part);
            if (current == null) return null;
        }
        return current;
    }

    private static Transform FindDeep(Transform root, string name)
    {
        if (root.name == name) return root;
        foreach (Transform child in root)
        {
            Transform found = FindDeep(child, name);
            if (found != null) return found;
        }
        return null;
    }

    private static Dictionary<string, Sprite> LoadNamedSprites(string path)
    {
        return AssetDatabase.LoadAllAssetsAtPath(path).OfType<Sprite>()
            .ToDictionary(sprite => sprite.name, sprite => sprite, StringComparer.Ordinal);
    }

    private static Sprite GetSprite(Dictionary<string, Sprite> sprites, string name)
    {
        sprites.TryGetValue(name, out Sprite sprite);
        if (sprite == null) Debug.LogWarning($"[PlayerProfileSetup] Sprite '{name}' was not found.");
        return sprite;
    }

    private static void CreateSceneSettings()
    {
        GameObject settings = new GameObject("SceneSettings");
        settings.AddComponent<ForceOrientation>();
    }

    private static void CreateCamera()
    {
        GameObject root = new GameObject("Main Camera", typeof(Camera), typeof(AudioListener));
        root.tag = "MainCamera";
        Camera camera = root.GetComponent<Camera>();
        camera.clearFlags = CameraClearFlags.SolidColor;
        camera.backgroundColor = Color.black;
        camera.orthographic = true;
        root.transform.position = new Vector3(0f, 0f, -10f);
    }

    private static void CreateEventSystem()
    {
        GameObject eventSystem = new GameObject("EventSystem", typeof(EventSystem));
        Type inputModule = Type.GetType("UnityEngine.InputSystem.UI.InputSystemUIInputModule, Unity.InputSystem");
        if (inputModule != null) eventSystem.AddComponent(inputModule);
        else eventSystem.AddComponent<StandaloneInputModule>();
    }

    private static void CreateAccountServices()
    {
        GameObject services = new GameObject("PlayerAccountServices", typeof(PlayerSessionManager), typeof(MobilePlatformAccountLinker));
        SerializedObject manager = new SerializedObject(services.GetComponent<PlayerSessionManager>());
        Set(manager, "platformLinker", services.GetComponent<MobilePlatformAccountLinker>());
        manager.FindProperty("useMockAuthInEditor").boolValue = false;
        manager.FindProperty("autoSignInAnonymously").boolValue = true;
        manager.FindProperty("useCloudSave").boolValue = true;
        manager.ApplyModifiedPropertiesWithoutUndo();
    }

    private static void EnsureFolder(string path)
    {
        if (AssetDatabase.IsValidFolder(path)) return;
        int slash = path.LastIndexOf('/');
        string parent = path.Substring(0, slash);
        string name = path.Substring(slash + 1);
        EnsureFolder(parent);
        AssetDatabase.CreateFolder(parent, name);
    }

    private static void Set(SerializedObject target, string propertyName, UnityEngine.Object value)
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

    private static void SetTopCenter(RectTransform rect, Vector2 size, Vector2 position)
    {
        rect.anchorMin = rect.anchorMax = rect.pivot = new Vector2(0.5f, 1f);
        rect.anchoredPosition = position;
        rect.sizeDelta = size;
    }

    private static void SetTopRight(RectTransform rect, Vector2 size, Vector2 position)
    {
        rect.anchorMin = rect.anchorMax = rect.pivot = Vector2.one;
        rect.anchoredPosition = position;
        rect.sizeDelta = size;
    }

    private static void SetBottomCenter(RectTransform rect, Vector2 size, Vector2 position)
    {
        rect.anchorMin = rect.anchorMax = rect.pivot = new Vector2(0.5f, 0f);
        rect.anchoredPosition = position;
        rect.sizeDelta = size;
    }

    private static void Stretch(RectTransform rect, float left = 0f, float right = 0f, float top = 0f, float bottom = 0f)
    {
        rect.anchorMin = Vector2.zero;
        rect.anchorMax = Vector2.one;
        rect.offsetMin = new Vector2(left, bottom);
        rect.offsetMax = new Vector2(-right, -top);
    }

    private readonly struct CharacterDefinition
    {
        public readonly string Id;
        public readonly string DisplayName;
        public readonly bool Unlocked;

        public CharacterDefinition(string id, string displayName, bool unlocked)
        {
            Id = id;
            DisplayName = displayName;
            Unlocked = unlocked;
        }
    }
}
#endif
