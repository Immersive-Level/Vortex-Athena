#if UNITY_EDITOR
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using TMPro;
using UnityEditor;
using UnityEditor.Events;
using UnityEditor.SceneManagement;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public static class NoesisSetupRunner
{
    private const string ScenePath = "Assets/Scenes/NoesisReadingScene.unity";
    private const string CardPrefabPath = "Assets/Noesis/Prefabs/NoesisCardView.prefab";
    private const string MenuScenePath = "Assets/Scenes/MainMenu.unity";

    private struct CardDefinition
    {
        public string Id;
        public string Number;
        public string Name;
        public string Message;

        public CardDefinition(string id, string number, string name, string message)
        {
            Id = id;
            Number = number;
            Name = name;
            Message = message;
        }
    }

    [MenuItem("Tools/Vortex Athena/Setup Noesis Reading")]
    public static void RunFromMenu()
    {
        Debug.Log(Run());
    }

    [MenuItem("Tools/Vortex Athena/Test Noesis Select First Card")]
    public static void TestSelectFirstCard()
    {
        NoesisCardView[] cards = UnityEngine.Object.FindObjectsByType<NoesisCardView>(FindObjectsSortMode.None);
        NoesisCardView card = cards.FirstOrDefault(view => view != null && view.gameObject.activeInHierarchy);
        if (card == null)
        {
            Debug.LogWarning("[NoesisSetup] No active Noesis card found to select.");
            return;
        }

        card.OnPointerClick(null);
        Debug.Log("[NoesisSetup] Selected first active Noesis card for validation.");
    }

    public static string Run()
    {
        Type cardDataType = FindType("NoesisCardData");
        Type cardViewType = FindType("NoesisCardView");
        Type controllerType = FindType("NoesisReadingController");
        Type fanLayoutType = FindType("NoesisFanLayout");
        Type safeAreaType = FindType("SafeAreaHandler");

        if (cardDataType == null || cardViewType == null || controllerType == null || fanLayoutType == null || safeAreaType == null)
        {
            throw new InvalidOperationException(
                "Noesis runtime scripts must compile before running setup. Missing: " +
                $"NoesisCardData={cardDataType == null}, " +
                $"NoesisCardView={cardViewType == null}, " +
                $"NoesisReadingController={controllerType == null}, " +
                $"NoesisFanLayout={fanLayoutType == null}, " +
                $"SafeAreaHandler={safeAreaType == null}");
        }

        string root = EnsureFolder("Assets", "Noesis");
        string cardsFolder = EnsureFolder(root, "Cards");
        string prefabsFolder = EnsureFolder(root, "Prefabs");
        string spritesFolder = EnsureFolder(root, "Sprites");

        Sprite defaultBack = EnsureDefaultBackSprite(spritesFolder);
        List<UnityEngine.Object> cardAssets = CreateCardAssets(cardsFolder, cardDataType);
        UnityEngine.Object cardPrefabComponent = CreateCardPrefab(defaultBack, cardViewType, prefabsFolder);
        CreateNoesisScene(defaultBack, cardAssets, cardPrefabComponent, controllerType, fanLayoutType, safeAreaType);
        AddNoesisSceneToBuildSettings();
        AddButtonToMainMenu();

        AssetDatabase.SaveAssets();
        AssetDatabase.Refresh();

        return $"Noesis setup complete: {ScenePath}, {cardAssets.Count} card assets, {CardPrefabPath}, MainMenu button.";
    }

    private static Type FindType(string typeName)
    {
        Type typeFromMonoScript = FindTypeFromMonoScript(typeName);
        if (typeFromMonoScript != null)
            return typeFromMonoScript;

        Type typeFromCache = TypeCache.GetTypesDerivedFrom<ScriptableObject>().FirstOrDefault(type => type.Name == typeName)
                             ?? TypeCache.GetTypesDerivedFrom<MonoBehaviour>().FirstOrDefault(type => type.Name == typeName);
        if (typeFromCache != null)
            return typeFromCache;

        foreach (var assembly in AppDomain.CurrentDomain.GetAssemblies())
        {
            Type type = assembly.GetType(typeName);
            if (type != null) return type;
        }
        return null;
    }

    private static Type FindTypeFromMonoScript(string typeName)
    {
        string[] guids = AssetDatabase.FindAssets(typeName + " t:MonoScript", new[] { "Assets/Scripts/Noesis" });
        foreach (string guid in guids)
        {
            string path = AssetDatabase.GUIDToAssetPath(guid);
            MonoScript script = AssetDatabase.LoadAssetAtPath<MonoScript>(path);
            Type type = script != null ? script.GetClass() : null;
            if (type != null && type.Name == typeName)
                return type;
        }

        return null;
    }

    private static string EnsureFolder(string parent, string name)
    {
        string path = parent + "/" + name;
        if (!AssetDatabase.IsValidFolder(path))
            AssetDatabase.CreateFolder(parent, name);
        return path;
    }

    private static Sprite EnsureDefaultBackSprite(string spritesFolder)
    {
        string texturePath = spritesFolder + "/Noesis_DefaultBack.png";
        if (!File.Exists(texturePath))
        {
            const int width = 256;
            const int height = 438;
            Texture2D texture = new Texture2D(width, height, TextureFormat.RGBA32, false);
            Color deep = new Color(0.035f, 0.04f, 0.075f, 1f);
            Color gold = new Color(0.77f, 0.64f, 0.29f, 1f);
            Color dim = new Color(0.25f, 0.20f, 0.08f, 1f);

            for (int y = 0; y < height; y++)
            {
                for (int x = 0; x < width; x++)
                {
                    float distance = Vector2.Distance(new Vector2(x / (float)width, y / (float)height), new Vector2(0.5f, 0.5f));
                    float vignette = Mathf.InverseLerp(0.85f, 0.2f, distance);
                    Color color = Color.Lerp(deep * 0.7f, deep, vignette);
                    bool border = x < 7 || x > width - 8 || y < 7 || y > height - 8;
                    bool inner = x > 20 && x < width - 21 && y > 20 && y < height - 21 && (x < 24 || x > width - 25 || y < 24 || y > height - 25);
                    bool star = Mathf.Abs(x - width / 2) + Mathf.Abs(y - height / 2) < 22 ||
                                Mathf.Abs(x - width / 2) < 4 && Mathf.Abs(y - height / 2) < 58 ||
                                Mathf.Abs(y - height / 2) < 4 && Mathf.Abs(x - width / 2) < 58;

                    if (border || star) color = gold;
                    else if (inner) color = dim;

                    texture.SetPixel(x, y, color);
                }
            }

            texture.Apply();
            File.WriteAllBytes(texturePath, texture.EncodeToPNG());
            UnityEngine.Object.DestroyImmediate(texture);
            AssetDatabase.ImportAsset(texturePath);
        }

        TextureImporter importer = AssetImporter.GetAtPath(texturePath) as TextureImporter;
        if (importer != null)
        {
            importer.textureType = TextureImporterType.Sprite;
            importer.spriteImportMode = SpriteImportMode.Single;
            importer.alphaIsTransparency = true;
            importer.SaveAndReimport();
        }

        return AssetDatabase.LoadAssetAtPath<Sprite>(texturePath);
    }

    private static List<UnityEngine.Object> CreateCardAssets(string cardsFolder, Type cardDataType)
    {
        List<UnityEngine.Object> assets = new List<UnityEngine.Object>();
        foreach (CardDefinition card in GetCardDefinitions())
        {
            string assetPath = $"{cardsFolder}/NoesisCard_{card.Number}_{SanitizeFileName(card.Name)}.asset";
            UnityEngine.Object data = AssetDatabase.LoadAssetAtPath(assetPath, cardDataType);
            if (data == null)
            {
                data = ScriptableObject.CreateInstance(cardDataType);
                AssetDatabase.CreateAsset(data, assetPath);
            }

            SerializedObject serialized = new SerializedObject(data);
            serialized.FindProperty("cardId").stringValue = card.Id;
            serialized.FindProperty("cardNumber").stringValue = card.Number;
            serialized.FindProperty("displayName").stringValue = card.Name;
            serialized.FindProperty("noesisMessage").stringValue = card.Message;
            serialized.ApplyModifiedProperties();
            EditorUtility.SetDirty(data);
            assets.Add(data);
        }

        return assets;
    }

    private static UnityEngine.Object CreateCardPrefab(Sprite defaultBack, Type cardViewType, string prefabsFolder)
    {
        GameObject prefabSource = new GameObject("NoesisCardView", typeof(RectTransform), typeof(CanvasRenderer), typeof(Image), typeof(CanvasGroup));
        RectTransform rectTransform = prefabSource.GetComponent<RectTransform>();
        rectTransform.sizeDelta = new Vector2(110f, 188f);

        Image cardImage = prefabSource.GetComponent<Image>();
        cardImage.sprite = defaultBack;
        cardImage.color = Color.white;
        cardImage.preserveAspect = true;

        CanvasGroup canvasGroup = prefabSource.GetComponent<CanvasGroup>();
        Component cardView = prefabSource.AddComponent(cardViewType);

        GameObject highlight = new GameObject("Highlight", typeof(RectTransform), typeof(CanvasRenderer), typeof(Image));
        highlight.transform.SetParent(prefabSource.transform, false);
        RectTransform highlightTransform = highlight.GetComponent<RectTransform>();
        highlightTransform.anchorMin = Vector2.zero;
        highlightTransform.anchorMax = Vector2.one;
        highlightTransform.offsetMin = new Vector2(-5f, -5f);
        highlightTransform.offsetMax = new Vector2(5f, 5f);
        Image highlightImage = highlight.GetComponent<Image>();
        highlightImage.color = new Color(0.88f, 0.74f, 0.36f, 0.22f);
        highlightImage.raycastTarget = false;
        highlightImage.enabled = false;

        SerializedObject serialized = new SerializedObject(cardView);
        serialized.FindProperty("cardImage").objectReferenceValue = cardImage;
        serialized.FindProperty("highlightImage").objectReferenceValue = highlightImage;
        serialized.FindProperty("canvasGroup").objectReferenceValue = canvasGroup;
        serialized.ApplyModifiedProperties();

        PrefabUtility.SaveAsPrefabAsset(prefabSource, CardPrefabPath);
        UnityEngine.Object.DestroyImmediate(prefabSource);

        GameObject prefabAsset = AssetDatabase.LoadAssetAtPath<GameObject>(CardPrefabPath);
        return prefabAsset != null ? prefabAsset.GetComponent<NoesisCardView>() : null;
    }

    private static void CreateNoesisScene(Sprite defaultBack, List<UnityEngine.Object> cardAssets, UnityEngine.Object cardPrefabComponent, Type controllerType, Type fanLayoutType, Type safeAreaType)
    {
        Scene scene = EditorSceneManager.NewScene(NewSceneSetup.EmptyScene, NewSceneMode.Single);
        scene.name = "NoesisReadingScene";

        CreateCamera();
        CreateOrientationSettings();
        CreateEventSystem();

        GameObject canvasObject = new GameObject("Canvas_NoesisReading", typeof(RectTransform), typeof(Canvas), typeof(CanvasScaler), typeof(GraphicRaycaster));
        Canvas canvas = canvasObject.GetComponent<Canvas>();
        canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        CanvasScaler scaler = canvasObject.GetComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1080f, 1920f);
        scaler.matchWidthOrHeight = 0.5f;

        GameObject background = StretchObject(canvasObject, "Background");
        background.transform.SetSiblingIndex(0);
        Image backgroundImage = background.AddComponent<Image>();
        backgroundImage.color = new Color(0.025f, 0.027f, 0.045f, 1f);

        GameObject safeRoot = StretchObject(canvasObject, "SafeAreaRoot");
        safeRoot.AddComponent(safeAreaType);

        GameObject content = StretchObject(safeRoot, "Content");
        RectTransform contentTransform = content.GetComponent<RectTransform>();
        contentTransform.offsetMin = new Vector2(42f, 34f);
        contentTransform.offsetMax = new Vector2(-42f, -34f);

        TMP_FontAsset font = GetDefaultFont();
        TextMeshProUGUI titleText;
        TextMeshProUGUI subtitleText;
        TextMeshProUGUI instructionText;
        CreateHeader(content, font, out titleText, out subtitleText);

        GameObject pickerSection;
        RectTransform fanContainer;
        CreatePickerSection(content, font, fanLayoutType, out pickerSection, out fanContainer, out instructionText);

        GameObject revealSection;
        Image revealedCardImage;
        TMP_Text numberText;
        TMP_Text nameText;
        TMP_Text messageText;
        Button consultAgainButton;
        Button backButton;
        CreateRevealSection(content, font, defaultBack, out revealSection, out revealedCardImage, out numberText, out nameText, out messageText, out consultAgainButton, out backButton);
        NoesisCardView sceneCardTemplate = CreateSceneCardTemplate(content, defaultBack);

        GameObject controllerObject = new GameObject("NoesisReadingController", typeof(AudioSource));
        Component controller = controllerObject.AddComponent(controllerType);
        SerializedObject serialized = new SerializedObject(controller);
        SerializedProperty cards = serialized.FindProperty("availableCards");
        cards.arraySize = cardAssets.Count;
        for (int i = 0; i < cardAssets.Count; i++)
            cards.GetArrayElementAtIndex(i).objectReferenceValue = cardAssets[i];
        serialized.FindProperty("fanContainer").objectReferenceValue = fanContainer;
        serialized.FindProperty("cardPrefab").objectReferenceValue = sceneCardTemplate;
        serialized.FindProperty("defaultBackSprite").objectReferenceValue = defaultBack;
        serialized.FindProperty("pickerSection").objectReferenceValue = pickerSection;
        serialized.FindProperty("revealSection").objectReferenceValue = revealSection;
        serialized.FindProperty("revealedCardImage").objectReferenceValue = revealedCardImage;
        serialized.FindProperty("revealedCardNumberText").objectReferenceValue = numberText;
        serialized.FindProperty("revealedCardNameText").objectReferenceValue = nameText;
        serialized.FindProperty("revealedCardMessageText").objectReferenceValue = messageText;
        serialized.FindProperty("consultAgainButton").objectReferenceValue = consultAgainButton;
        serialized.FindProperty("backButton").objectReferenceValue = backButton;
        serialized.FindProperty("backgroundImage").objectReferenceValue = backgroundImage;
        serialized.FindProperty("titleText").objectReferenceValue = titleText;
        serialized.FindProperty("subtitleText").objectReferenceValue = subtitleText;
        serialized.FindProperty("instructionText").objectReferenceValue = instructionText;
        serialized.FindProperty("consultAgainButtonImage").objectReferenceValue = consultAgainButton.GetComponent<Image>();
        serialized.FindProperty("backButtonImage").objectReferenceValue = backButton.GetComponent<Image>();
        serialized.FindProperty("audioSource").objectReferenceValue = controllerObject.GetComponent<AudioSource>();
        serialized.FindProperty("menuSceneName").stringValue = "MainMenu";
        serialized.ApplyModifiedProperties();
        EditorUtility.SetDirty(controller);

        EditorSceneManager.SaveScene(scene, ScenePath);
    }

    private static NoesisCardView CreateSceneCardTemplate(GameObject parent, Sprite defaultBack)
    {
        GameObject template = new GameObject("NoesisCardTemplate", typeof(RectTransform), typeof(CanvasRenderer), typeof(Image), typeof(CanvasGroup), typeof(NoesisCardView));
        template.transform.SetParent(parent.transform, false);
        RectTransform rectTransform = template.GetComponent<RectTransform>();
        rectTransform.sizeDelta = new Vector2(110f, 188f);

        Image cardImage = template.GetComponent<Image>();
        cardImage.sprite = defaultBack;
        cardImage.color = Color.white;
        cardImage.preserveAspect = true;

        CanvasGroup canvasGroup = template.GetComponent<CanvasGroup>();

        GameObject highlight = new GameObject("Highlight", typeof(RectTransform), typeof(CanvasRenderer), typeof(Image));
        highlight.transform.SetParent(template.transform, false);
        RectTransform highlightTransform = highlight.GetComponent<RectTransform>();
        highlightTransform.anchorMin = Vector2.zero;
        highlightTransform.anchorMax = Vector2.one;
        highlightTransform.offsetMin = new Vector2(-5f, -5f);
        highlightTransform.offsetMax = new Vector2(5f, 5f);
        Image highlightImage = highlight.GetComponent<Image>();
        highlightImage.color = new Color(0.88f, 0.74f, 0.36f, 0.22f);
        highlightImage.raycastTarget = false;
        highlightImage.enabled = false;

        NoesisCardView cardView = template.GetComponent<NoesisCardView>();
        cardView.cardImage = cardImage;
        cardView.highlightImage = highlightImage;
        cardView.canvasGroup = canvasGroup;
        template.SetActive(false);
        return cardView;
    }

    private static void CreateCamera()
    {
        GameObject cameraObject = new GameObject("Main Camera", typeof(Camera), typeof(AudioListener));
        cameraObject.tag = "MainCamera";
        Camera camera = cameraObject.GetComponent<Camera>();
        camera.clearFlags = CameraClearFlags.SolidColor;
        camera.backgroundColor = new Color(0.025f, 0.027f, 0.045f, 1f);
        camera.orthographic = true;
        camera.orthographicSize = 5f;
        cameraObject.transform.position = new Vector3(0f, 0f, -10f);
    }

    private static void CreateOrientationSettings()
    {
        GameObject sceneSettings = new GameObject("SceneSettings", typeof(ForceOrientation));
        ForceOrientation orientation = sceneSettings.GetComponent<ForceOrientation>();
        orientation.orientation = ForceOrientation.Mode.Portrait;
        orientation.lockToThisOrientation = true;
    }

    private static void CreateEventSystem()
    {
        GameObject eventSystem = new GameObject("EventSystem", typeof(EventSystem));
        Type inputModuleType = Type.GetType("UnityEngine.InputSystem.UI.InputSystemUIInputModule, Unity.InputSystem");
        if (inputModuleType != null)
            eventSystem.AddComponent(inputModuleType);
        else
            eventSystem.AddComponent<StandaloneInputModule>();
    }

    private static void CreateHeader(GameObject content, TMP_FontAsset font, out TextMeshProUGUI titleText, out TextMeshProUGUI subtitleText)
    {
        GameObject header = new GameObject("Header", typeof(RectTransform));
        header.transform.SetParent(content.transform, false);
        RectTransform headerTransform = header.GetComponent<RectTransform>();
        headerTransform.anchorMin = new Vector2(0f, 1f);
        headerTransform.anchorMax = new Vector2(1f, 1f);
        headerTransform.pivot = new Vector2(0.5f, 1f);
        headerTransform.anchoredPosition = Vector2.zero;
        headerTransform.sizeDelta = new Vector2(0f, 315f);

        TextMeshProUGUI eyebrow = AddText(header, "EyebrowText", "VORTEX ATHENA · ORACULO DEL UNIVERSO", 30f, new Color(0.42f, 0.33f, 0.12f, 1f), TextAlignmentOptions.Center, font);
        SetTopRect(eyebrow.rectTransform, -18f, 64f);

        titleText = AddText(header, "TitleText", "LECTURA DE NOESIS", 58f, new Color(0.91f, 0.79f, 0.48f, 1f), TextAlignmentOptions.Center, font);
        SetTopRect(titleText.rectTransform, -98f, 96f);

        subtitleText = AddText(header, "SubtitleText", "Las cartas del universo estan revueltas. Una de ellas guarda un mensaje para ti hoy.", 34f, new Color(0.62f, 0.55f, 0.40f, 1f), TextAlignmentOptions.Center, font);
        subtitleText.fontStyle = FontStyles.Italic;
        SetTopRect(subtitleText.rectTransform, -205f, 92f);
    }

    private static void CreatePickerSection(GameObject content, TMP_FontAsset font, Type fanLayoutType, out GameObject pickerSection, out RectTransform fanContainer, out TextMeshProUGUI instructionText)
    {
        pickerSection = new GameObject("PickerSection", typeof(RectTransform));
        pickerSection.transform.SetParent(content.transform, false);
        RectTransform pickerTransform = pickerSection.GetComponent<RectTransform>();
        pickerTransform.anchorMin = new Vector2(0f, 0f);
        pickerTransform.anchorMax = new Vector2(1f, 1f);
        pickerTransform.offsetMin = Vector2.zero;
        pickerTransform.offsetMax = new Vector2(0f, -315f);

        instructionText = AddText(pickerSection, "InstructionText", "ELIGE UNA CARTA", 34f, new Color(0.79f, 0.66f, 0.30f, 1f), TextAlignmentOptions.Center, font);
        SetTopRect(instructionText.rectTransform, -6f, 70f);

        GameObject fan = new GameObject("FanContainer", typeof(RectTransform));
        fan.AddComponent(fanLayoutType);
        fan.transform.SetParent(pickerSection.transform, false);
        fanContainer = fan.GetComponent<RectTransform>();
        fanContainer.anchorMin = new Vector2(0f, 0f);
        fanContainer.anchorMax = new Vector2(1f, 1f);
        fanContainer.offsetMin = Vector2.zero;
        fanContainer.offsetMax = new Vector2(0f, -80f);
    }

    private static void CreateRevealSection(GameObject content, TMP_FontAsset font, Sprite defaultBack, out GameObject revealSection, out Image revealedCardImage, out TMP_Text numberText, out TMP_Text nameText, out TMP_Text messageText, out Button consultAgainButton, out Button backButton)
    {
        revealSection = new GameObject("RevealSection", typeof(RectTransform));
        revealSection.transform.SetParent(content.transform, false);
        RectTransform revealTransform = revealSection.GetComponent<RectTransform>();
        revealTransform.anchorMin = Vector2.zero;
        revealTransform.anchorMax = Vector2.one;
        revealTransform.offsetMin = Vector2.zero;
        revealTransform.offsetMax = new Vector2(0f, -315f);
        revealSection.SetActive(false);

        GameObject revealedCard = new GameObject("RevealedCardImage", typeof(RectTransform), typeof(CanvasRenderer), typeof(Image), typeof(AspectRatioFitter));
        revealedCard.transform.SetParent(revealSection.transform, false);
        RectTransform revealedTransform = revealedCard.GetComponent<RectTransform>();
        revealedTransform.anchorMin = new Vector2(0.5f, 1f);
        revealedTransform.anchorMax = new Vector2(0.5f, 1f);
        revealedTransform.pivot = new Vector2(0.5f, 1f);
        revealedTransform.anchoredPosition = new Vector2(0f, -16f);
        revealedTransform.sizeDelta = new Vector2(440f, 754f);
        revealedCardImage = revealedCard.GetComponent<Image>();
        revealedCardImage.sprite = defaultBack;
        revealedCardImage.color = Color.white;
        AspectRatioFitter fitter = revealedCard.GetComponent<AspectRatioFitter>();
        fitter.aspectMode = AspectRatioFitter.AspectMode.FitInParent;
        fitter.aspectRatio = 414f / 709f;

        TextMeshProUGUI cardNumberText = AddText(revealSection, "RevealedCardNumberText", "CARTA 000", 26f, new Color(0.42f, 0.33f, 0.12f, 1f), TextAlignmentOptions.Center, font);
        SetAnchoredBand(cardNumberText.rectTransform, 0.36f, 54f);
        numberText = cardNumberText;

        TextMeshProUGUI cardNameText = AddText(revealSection, "RevealedCardNameText", "NOESIS", 46f, new Color(0.91f, 0.79f, 0.48f, 1f), TextAlignmentOptions.Center, font);
        SetAnchoredBand(cardNameText.rectTransform, 0.30f, 90f);
        nameText = cardNameText;

        TextMeshProUGUI cardMessageText = AddText(revealSection, "RevealedCardMessageText", string.Empty, 32f, new Color(0.83f, 0.77f, 0.63f, 1f), TextAlignmentOptions.Center, font);
        cardMessageText.fontStyle = FontStyles.Italic;
        RectTransform messageTransform = cardMessageText.rectTransform;
        messageTransform.anchorMin = new Vector2(0f, 0.10f);
        messageTransform.anchorMax = new Vector2(1f, 0.27f);
        messageTransform.offsetMin = new Vector2(28f, 0f);
        messageTransform.offsetMax = new Vector2(-28f, 0f);
        messageText = cardMessageText;

        GameObject buttons = new GameObject("Buttons", typeof(RectTransform), typeof(HorizontalLayoutGroup));
        buttons.transform.SetParent(revealSection.transform, false);
        RectTransform buttonsTransform = buttons.GetComponent<RectTransform>();
        buttonsTransform.anchorMin = new Vector2(0f, 0f);
        buttonsTransform.anchorMax = new Vector2(1f, 0f);
        buttonsTransform.pivot = new Vector2(0.5f, 0f);
        buttonsTransform.anchoredPosition = new Vector2(0f, 10f);
        buttonsTransform.sizeDelta = new Vector2(0f, 110f);
        HorizontalLayoutGroup buttonsLayout = buttons.GetComponent<HorizontalLayoutGroup>();
        buttonsLayout.childAlignment = TextAnchor.MiddleCenter;
        buttonsLayout.spacing = 28f;
        buttonsLayout.childControlWidth = false;
        buttonsLayout.childControlHeight = false;
        buttonsLayout.childForceExpandWidth = false;
        buttonsLayout.childForceExpandHeight = false;

        consultAgainButton = CreateButton(buttons, "ConsultAgainButton", "CONSULTAR DE NUEVO", new Vector2(430f, 82f), font);
        backButton = CreateButton(buttons, "BackButton", "VOLVER", new Vector2(270f, 82f), font);
    }

    private static void AddNoesisSceneToBuildSettings()
    {
        List<EditorBuildSettingsScene> scenes = EditorBuildSettings.scenes.ToList();
        if (!scenes.Any(scene => scene.path == ScenePath))
            scenes.Add(new EditorBuildSettingsScene(ScenePath, true));

        foreach (EditorBuildSettingsScene scene in scenes)
        {
            if (scene.path == ScenePath)
                scene.enabled = true;
        }

        EditorBuildSettings.scenes = scenes.ToArray();
    }

    private static void AddButtonToMainMenu()
    {
        Scene menuScene = EditorSceneManager.OpenScene(MenuScenePath, OpenSceneMode.Single);
        GameObject sceneControllerObject = FindSceneObject("SceneManagerController", menuScene);
        SceneManagerController sceneController = sceneControllerObject != null ? sceneControllerObject.GetComponent<SceneManagerController>() : null;

        GameObject existingButton = FindSceneObject("NoesisReadingBtn", menuScene);
        if (existingButton == null)
        {
            GameObject localButton = FindSceneObject("LocalBtn", menuScene);
            if (localButton == null)
            {
                Debug.LogWarning("[NoesisSetup] Could not find LocalBtn in MainMenu; button not created.");
                EditorSceneManager.SaveScene(menuScene);
                return;
            }

            existingButton = UnityEngine.Object.Instantiate(localButton, localButton.transform.parent);
            existingButton.name = "NoesisReadingBtn";
            RectTransform noesisTransform = existingButton.GetComponent<RectTransform>();
            noesisTransform.sizeDelta = new Vector2(520f, 100f);
            noesisTransform.anchoredPosition = new Vector2(noesisTransform.anchoredPosition.x, noesisTransform.anchoredPosition.y - 130f);
            noesisTransform.SetSiblingIndex(localButton.transform.GetSiblingIndex() + 1);

            TextMeshProUGUI label = existingButton.GetComponentInChildren<TextMeshProUGUI>(true);
            if (label != null)
            {
                label.text = "LECTURA DE NOESIS";
                label.fontSizeMax = 42f;
                label.fontSizeMin = 16f;
                label.textWrappingMode = TextWrappingModes.Normal;
                label.alignment = TextAlignmentOptions.Center;
            }
        }

        Button button = existingButton.GetComponent<Button>();
        if (button != null)
        {
            button.onClick = new Button.ButtonClickedEvent();
            if (sceneController != null)
                UnityEventTools.AddStringPersistentListener(button.onClick, sceneController.ChangeScene, "NoesisReadingScene");
            else
                Debug.LogWarning("[NoesisSetup] SceneManagerController not found; Noesis button has no navigation listener.");
        }

        EditorUtility.SetDirty(existingButton);
        EditorSceneManager.SaveScene(menuScene);
    }

    private static GameObject FindSceneObject(string objectName, Scene scene)
    {
        return Resources.FindObjectsOfTypeAll<GameObject>()
            .FirstOrDefault(gameObject =>
                gameObject.name == objectName &&
                gameObject.scene.IsValid() &&
                gameObject.scene == scene);
    }

    private static GameObject StretchObject(GameObject parent, string name)
    {
        GameObject gameObject = new GameObject(name, typeof(RectTransform));
        gameObject.transform.SetParent(parent.transform, false);
        RectTransform rectTransform = gameObject.GetComponent<RectTransform>();
        rectTransform.anchorMin = Vector2.zero;
        rectTransform.anchorMax = Vector2.one;
        rectTransform.offsetMin = Vector2.zero;
        rectTransform.offsetMax = Vector2.zero;
        return gameObject;
    }

    private static TextMeshProUGUI AddText(GameObject parent, string name, string text, float size, Color color, TextAlignmentOptions alignment, TMP_FontAsset font)
    {
        GameObject gameObject = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(TextMeshProUGUI));
        gameObject.transform.SetParent(parent.transform, false);
        TextMeshProUGUI tmp = gameObject.GetComponent<TextMeshProUGUI>();
        tmp.text = text;
        tmp.fontSize = size;
        tmp.enableAutoSizing = true;
        tmp.fontSizeMin = Mathf.Max(8f, size * 0.45f);
        tmp.fontSizeMax = size;
        tmp.color = color;
        tmp.alignment = alignment;
        tmp.textWrappingMode = TextWrappingModes.Normal;
        if (font != null)
            tmp.font = font;
        return tmp;
    }

    private static Button CreateButton(GameObject parent, string name, string label, Vector2 size, TMP_FontAsset font)
    {
        GameObject gameObject = new GameObject(name, typeof(RectTransform), typeof(CanvasRenderer), typeof(Image), typeof(Button));
        gameObject.transform.SetParent(parent.transform, false);
        RectTransform rectTransform = gameObject.GetComponent<RectTransform>();
        rectTransform.sizeDelta = size;

        Image image = gameObject.GetComponent<Image>();
        image.type = Image.Type.Sliced;
        image.color = new Color(0.12f, 0.10f, 0.16f, 0.92f);

        Button button = gameObject.GetComponent<Button>();
        button.targetGraphic = image;

        TextMeshProUGUI text = AddText(gameObject, "Text (TMP)", label, 32f, new Color(0.88f, 0.74f, 0.36f, 1f), TextAlignmentOptions.Center, font);
        RectTransform textTransform = text.rectTransform;
        textTransform.anchorMin = Vector2.zero;
        textTransform.anchorMax = Vector2.one;
        textTransform.offsetMin = new Vector2(14f, 4f);
        textTransform.offsetMax = new Vector2(-14f, -4f);

        return button;
    }

    private static TMP_FontAsset GetDefaultFont()
    {
        TMP_FontAsset font = AssetDatabase.LoadAssetAtPath<TMP_FontAsset>("Assets/TextMesh Pro/Resources/Fonts & Materials/LiberationSans SDF.asset");
        return font != null ? font : Resources.Load<TMP_FontAsset>("Fonts & Materials/LiberationSans SDF");
    }

    private static void SetTopRect(RectTransform rectTransform, float y, float height)
    {
        rectTransform.anchorMin = new Vector2(0f, 1f);
        rectTransform.anchorMax = new Vector2(1f, 1f);
        rectTransform.pivot = new Vector2(0.5f, 1f);
        rectTransform.anchoredPosition = new Vector2(0f, y);
        rectTransform.sizeDelta = new Vector2(0f, height);
    }

    private static void SetAnchoredBand(RectTransform rectTransform, float yAnchor, float height)
    {
        rectTransform.anchorMin = new Vector2(0f, yAnchor);
        rectTransform.anchorMax = new Vector2(1f, yAnchor);
        rectTransform.sizeDelta = new Vector2(0f, height);
    }

    private static string SanitizeFileName(string value)
    {
        foreach (char invalid in Path.GetInvalidFileNameChars())
            value = value.Replace(invalid, '_');
        return value.Replace(' ', '_');
    }

    private static CardDefinition[] GetCardDefinitions()
    {
        return new[]
        {
            new CardDefinition("1", "001", "Cuarteto de Robert", "Tu vida no necesita ser estable, solo armonica. Escucha las mareas. El verdadero orden no es quietud, sino movimiento sincronizado."),
            new CardDefinition("2", "002", "Constelacion Fenix", "Hay algo en ti que se prepara para reaparecer con fuerza. No temas el olvido, lo esencial renace con mas brillo cuando nadie lo espera."),
            new CardDefinition("3", "003", "Bellatrix", "Traes contigo el liderazgo que nace del dolor transformado. Tu mayor poder proviene de tus heridas bien procesadas. Usa tu historia para dar sentido."),
            new CardDefinition("4", "004", "Antares", "Tu poder es el escudo de los tuyos. Eres mas fuerte de lo que crees, pero cuidado, tu furia puede ser una trampa si olvidas pensar antes de actuar."),
            new CardDefinition("5", "005", "Zeta", "Tu mente como herramienta es sagrada. No permitas que tus miedos bloqueen tu potencial. Eres capaz de grandes logros, pero debes atreverte a confiar."),
            new CardDefinition("6", "006", "Zubenes", "Alguien cuenta contigo aunque no lo diga. Tu fuerza esta en la lealtad. Cuando dudes, apoyate de tus aliados. Y si estas solo, es momento de extender la mano."),
            new CardDefinition("7", "007", "Halora", "El universo tiene patrones; tu mision es reconocerlos antes de moverte. No reacciones por miedo, ordena tus ideas y responde con claridad."),
            new CardDefinition("8", "008", "Dragora", "Actua sin adornos. No expliques tanto. No pidas permiso. La llama en ti no es decorativa, es impulso, es decision. Haz que tus pasos quemen, no que suenen."),
            new CardDefinition("9", "009", "Lucaris", "Lo mas valioso se esconde tras el polvo. No te desesperes buscando respuestas inmediatas. Observa, razona, y confia en que tu mente sera tu faro."),
            new CardDefinition("10", "010", "Ignara", "Estas en medio de una tormenta creativa. No intentes controlarlo todo. Improvisa, adapta, usa lo que tienes. La solucion no sera perfecta, pero sera brillante."),
            new CardDefinition("11", "011", "Auriga", "Es momento de confiar en tu vision. No todo se resuelve con fuerza; a veces la verdadera victoria esta en leer mejor el rumbo antes de dar el siguiente paso."),
            new CardDefinition("12", "012", "Colmillo de Marea", "No retrocedas. Hay batallas que solo se transforman cuando decides entrar con toda tu fuerza y reclamar el espacio que tambien te pertenece."),
            new CardDefinition("13", "013", "Velo de Aletheia", "Observa con mas profundidad. Lo que hoy parece confuso guarda una verdad que solo se revela a quien sabe mirar mas alla de la superficie."),
            new CardDefinition("14", "014", "Chispa", "Muevete. No esperes a que el caos termine para avanzar, porque a veces el impulso correcto nace justo en medio de la incertidumbre."),
            new CardDefinition("15", "015", "Vector de Retorno", "Recuerda que no todo peligro avanza en linea recta. Hay energias que corrigen su camino, te buscan y regresan una y otra vez, hasta tocar aquello que no ha sido resuelto."),
            new CardDefinition("16", "016", "Nexo de Blindaje", "Hay momentos en los que proteger tu energia no es retroceder, sino reconocer que no todo debe tocarte para poder transformarte."),
            new CardDefinition("17", "017", "Aguja del Umbral", "La distancia no siempre te protege. Hay verdades que avanzan en silencio y solo esperan el instante exacto para alcanzarte.")
        };
    }
}
#endif
