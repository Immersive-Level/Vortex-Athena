using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.TestTools;
using UnityEngine.UI;

public class NoesisReadingPlayModeTests
{
    [UnityTest]
    public IEnumerator CompleteReadingFlow_FromMenuAndBack()
    {
        SceneManager.LoadScene("MainMenu");
        yield return WaitForScene("MainMenu");

        GameObject menuButtonObject = GameObject.Find("NoesisReadingBtn");
        Assert.IsNotNull(menuButtonObject, "MainMenu must contain NoesisReadingBtn.");
        Assert.IsTrue(menuButtonObject.activeInHierarchy, "NoesisReadingBtn must be reachable from the active menu.");
        Button menuButton = menuButtonObject.GetComponent<Button>();
        Assert.IsNotNull(menuButton, "NoesisReadingBtn must have a Button component.");
        menuButton.onClick.Invoke();
        yield return WaitForScene("NoesisReadingScene");

        Type controllerType = FindProjectType("NoesisReadingController");
        Type cardViewType = FindProjectType("NoesisCardView");
        Assert.IsNotNull(controllerType);
        Assert.IsNotNull(cardViewType);

        Component controller = FindSceneComponent(controllerType);
        Assert.IsNotNull(controller, "NoesisReadingController was not found in the scene.");

        RectTransform fanContainer = (RectTransform)GetField(controller, "fanContainer");
        Assert.Greater(fanContainer.rect.width, 0f, "FanContainer must have usable width.");
        Assert.Greater(fanContainer.rect.height, 0f, "FanContainer must have usable height at the current resolution.");

        IList availableCards = (IList)GetField(controller, "availableCards");
        Assert.AreEqual(17, availableCards.Count);
        foreach (UnityEngine.Object card in availableCards)
        {
            Assert.IsNotNull(card);
            Assert.IsNotNull(GetField(card, "frontSprite"));
        }
        Assert.IsNotNull(GetField(controller, "defaultBackSprite"));

        float openDuration = GetFloat(controller, "openAnimationDuration");
        float staggerDelay = GetFloat(controller, "staggerDelay");
        float totalOpenDuration = openDuration + staggerDelay * 16f;
        yield return WaitForCardCount(cardViewType, 17);

        List<Component> views = FindActiveSceneComponents(cardViewType);
        Assert.AreEqual(17, views.Count, "The fan must instantiate all 17 cards.");
        float stackedMinX = views.Min(view => view.GetComponent<RectTransform>().anchoredPosition.x);
        float stackedMaxX = views.Max(view => view.GetComponent<RectTransform>().anchoredPosition.x);
        Assert.Less(stackedMaxX - stackedMinX, 20f, "Cards must begin as a compact stacked deck.");

        yield return new WaitForSecondsRealtime(totalOpenDuration + 0.2f);
        foreach (Component view in views)
        {
            CanvasGroup group = view.GetComponent<CanvasGroup>();
            Assert.IsNotNull(group);
            Assert.That(group.alpha, Is.EqualTo(1f).Within(0.02f));
            Assert.IsTrue(group.interactable, "Every card must become interactable after the fan intro.");
            Assert.IsTrue(group.blocksRaycasts, "Every card must receive pointer input after the fan intro.");
            Assert.IsNotNull(view.GetComponent<Image>().sprite);
        }

        Type fanLayoutType = FindProjectType("NoesisFanLayout");
        Component fanLayout = fanContainer.GetComponent(fanLayoutType);
        Vector2 radialCenter = (Vector2)GetProperty(fanLayout, "LastRadialCenter");
        List<float> radialAngles = new List<float>();
        RectTransform representativeCard = views[0].GetComponent<RectTransform>();
        foreach (Component view in views)
        {
            RectTransform cardTransform = view.GetComponent<RectTransform>();
            Vector2 fromCenter = cardTransform.anchoredPosition - radialCenter;
            float radialAngle = Mathf.Atan2(fromCenter.x, fromCenter.y) * Mathf.Rad2Deg;
            radialAngles.Add(radialAngle);
            Assert.That(
                Mathf.Abs(Mathf.DeltaAngle(0f, cardTransform.localEulerAngles.z) + radialAngle),
                Is.LessThan(1f),
                "Each card must face away from the radial center.");
        }

        Assert.Greater(radialAngles.Max() - radialAngles.Min(), 280f, "Cards must cover a near-complete circle.");
        Assert.IsTrue(views.Any(view => view.GetComponent<RectTransform>().anchoredPosition.y > radialCenter.y));
        Assert.IsTrue(views.Any(view => view.GetComponent<RectTransform>().anchoredPosition.y < radialCenter.y));
        Assert.IsTrue(views.Any(view => view.GetComponent<RectTransform>().anchoredPosition.x > radialCenter.x));
        Assert.IsTrue(views.Any(view => view.GetComponent<RectTransform>().anchoredPosition.x < radialCenter.x));
        Assert.Less(Mathf.Abs(radialCenter.x - fanContainer.rect.width * 0.5f), fanContainer.rect.width * 0.2f);
        Assert.Less(Mathf.Abs(radialCenter.y - fanContainer.rect.height * 0.5f), fanContainer.rect.height * 0.25f);
        Assert.Greater(views.Max(view => view.GetComponent<RectTransform>().anchoredPosition.x)
            - views.Min(view => view.GetComponent<RectTransform>().anchoredPosition.x), representativeCard.rect.width);
        Assert.That(GetFloat(controller, "cardScale"), Is.EqualTo(1.25f).Within(0.01f));
        Assert.That(GetFloat(controller, "fanRadius"), Is.GreaterThan(0f));
        Assert.That(GetFloat(controller, "totalAngle"), Is.GreaterThan(280f));

        Vector2 averagePivot = Vector2.zero;
        List<Vector2> bottomPivots = new List<Vector2>();
        foreach (Component view in views)
        {
            RectTransform cardTransform = view.GetComponent<RectTransform>();
            Vector2 bottomPivot = cardTransform.anchoredPosition
                + (Vector2)(cardTransform.localRotation * new Vector3(0f, -cardTransform.rect.height * 0.5f, 0f));
            bottomPivots.Add(bottomPivot);
            averagePivot += bottomPivot;
        }
        averagePivot /= bottomPivots.Count;
        float pivotSpread = bottomPivots.Max(point => Vector2.Distance(point, averagePivot));
        Assert.Less(pivotSpread, representativeCard.rect.width * 0.2f, "Cards must share a compact radial pivot.");

        GameObject headerRoot = (GameObject)GetField(controller, "headerRoot");
        Assert.IsTrue(headerRoot.activeInHierarchy, "Title and subtitle must remain visible above the radial fan.");
        TMP_Text titleText = (TMP_Text)GetField(controller, "titleText");
        TMP_Text subtitleText = (TMP_Text)GetField(controller, "subtitleText");
        Assert.IsTrue(titleText.gameObject.activeInHierarchy);
        Assert.IsTrue(subtitleText.gameObject.activeInHierarchy);
        float titleWorldY = titleText.rectTransform.TransformPoint(titleText.rectTransform.rect.center).y;
        float subtitleWorldY = subtitleText.rectTransform.TransformPoint(subtitleText.rectTransform.rect.center).y;
        float fanWorldY = views.Average(view => view.GetComponent<RectTransform>().TransformPoint(view.GetComponent<RectTransform>().rect.center).y);
        Assert.Greater(titleWorldY, fanWorldY, "The title must remain above the radial fan.");
        Assert.Greater(subtitleWorldY, fanWorldY, "The subtitle must remain above the radial fan.");

        Button pickerBackButton = (Button)GetField(controller, "pickerBackButton");
        Assert.IsTrue(pickerBackButton.gameObject.activeInHierarchy);
        Assert.AreEqual("VA_UINuevo_01_2", pickerBackButton.GetComponent<Image>().sprite.name);
        pickerBackButton.onClick.Invoke();
        yield return WaitForScene("MainMenu");

        GameObject.Find("NoesisReadingBtn").GetComponent<Button>().onClick.Invoke();
        yield return WaitForScene("NoesisReadingScene");
        controller = FindSceneComponent(controllerType);
        yield return new WaitForSecondsRealtime(
            GetFloat(controller, "openAnimationDuration")
            + GetFloat(controller, "staggerDelay") * 16f
            + 0.2f);
        views = FindActiveSceneComponents(cardViewType);

        Component selectedView = views[0];
        UnityEngine.Object selectedData = (UnityEngine.Object)GetProperty(selectedView, "Data");
        Invoke(selectedView, "OnPointerClick", new object[] { null });

        foreach (Component view in views)
        {
            CanvasGroup group = view.GetComponent<CanvasGroup>();
            Assert.IsFalse(group.interactable, "All card input must lock immediately after selection.");
            Assert.IsFalse(group.blocksRaycasts);
        }

        float selectionDuration = Mathf.Max(
            GetFloat(controller, "flyAwayDuration"),
            GetFloat(controller, "selectedCardMoveDuration") + GetFloat(controller, "cardFlipDuration"));
        yield return new WaitForSecondsRealtime(selectionDuration + GetFloat(controller, "revealFadeDuration") + 0.3f);

        GameObject pickerSection = (GameObject)GetField(controller, "pickerSection");
        GameObject revealSection = (GameObject)GetField(controller, "revealSection");
        Assert.IsFalse(pickerSection.activeSelf);
        Assert.IsTrue(revealSection.activeSelf, "RevealSection must be active after selecting a card.");

        Image revealedImage = (Image)GetField(controller, "revealedCardImage");
        Sprite expectedFront = (Sprite)GetField(selectedData, "frontSprite");
        Assert.AreSame(expectedFront, revealedImage.sprite);
        Assert.IsTrue(revealedImage.preserveAspect, "The revealed card image must preserve its aspect ratio.");
        RectTransform revealedTransform = revealedImage.rectTransform;
        Assert.That(revealedTransform.anchoredPosition.sqrMagnitude, Is.LessThan(1f), "The revealed card must be centered.");
        Rect parentRect = ((RectTransform)revealedTransform.parent).rect;
        float widthUsage = revealedTransform.rect.width / Mathf.Max(1f, parentRect.width);
        float heightUsage = revealedTransform.rect.height / Mathf.Max(1f, parentRect.height);
        Assert.Greater(Mathf.Max(widthUsage, heightUsage), 0.85f, "The revealed card must use most of its available area.");

        headerRoot = (GameObject)GetField(controller, "headerRoot");
        Assert.IsFalse(headerRoot.activeSelf, "The header must be hidden in reveal view.");
        Assert.AreEqual(0, revealSection.GetComponentsInChildren<TMP_Text>(false).Length, "Reveal view must contain no visible text.");
        Button consultAgainButton = (Button)GetField(controller, "consultAgainButton");
        Assert.IsFalse(consultAgainButton.gameObject.activeInHierarchy, "The legacy CONSULTAR DE NUEVO button must remain hidden.");

        Button revealBackButton = (Button)GetField(controller, "revealBackButton");
        Assert.IsTrue(revealBackButton.gameObject.activeInHierarchy);
        Assert.AreEqual("VA_UINuevo_01_2", revealBackButton.GetComponent<Image>().sprite.name);
        revealBackButton.onClick.Invoke();
        yield return new WaitForSecondsRealtime(GetFloat(controller, "revealFadeDuration") + totalOpenDuration + 0.4f);

        Assert.AreEqual("NoesisReadingScene", SceneManager.GetActiveScene().name);
        Assert.IsTrue(pickerSection.activeSelf, "PickerSection must return from the revealed card.");
        Assert.IsFalse(revealSection.activeSelf);
        Assert.IsTrue(headerRoot.activeSelf);
        Assert.AreEqual(17, FindActiveSceneComponents(cardViewType).Count);

        ((Button)GetField(controller, "pickerBackButton")).onClick.Invoke();
        yield return WaitForScene("MainMenu");
        Assert.IsNotNull(GameObject.Find("NoesisReadingBtn"));
    }

    private static IEnumerator WaitForScene(string sceneName)
    {
        float timeout = Time.realtimeSinceStartup + 10f;
        while (SceneManager.GetActiveScene().name != sceneName && Time.realtimeSinceStartup < timeout)
            yield return null;
        Assert.AreEqual(sceneName, SceneManager.GetActiveScene().name);
        yield return null;
    }

    private static IEnumerator WaitForCardCount(Type cardViewType, int expectedCount)
    {
        float timeout = Time.realtimeSinceStartup + 5f;
        while (FindActiveSceneComponents(cardViewType).Count < expectedCount && Time.realtimeSinceStartup < timeout)
            yield return null;
        Assert.AreEqual(expectedCount, FindActiveSceneComponents(cardViewType).Count);
    }

    private static Type FindProjectType(string name)
    {
        foreach (Assembly assembly in AppDomain.CurrentDomain.GetAssemblies())
        {
            Type type = assembly.GetType(name);
            if (type != null) return type;
        }
        return null;
    }

    private static Component FindSceneComponent(Type type)
    {
        List<Component> components = FindActiveSceneComponents(type);
        return components.Count > 0 ? components[0] : null;
    }

    private static List<Component> FindActiveSceneComponents(Type type)
    {
        List<Component> result = new List<Component>();
        foreach (UnityEngine.Object item in Resources.FindObjectsOfTypeAll(type))
        {
            Component component = item as Component;
            if (component != null && component.gameObject.scene.isLoaded && component.gameObject.activeInHierarchy)
                result.Add(component);
        }
        return result;
    }

    private static object GetField(object target, string name)
    {
        FieldInfo field = target.GetType().GetField(name, BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
        Assert.IsNotNull(field, "Field not found: " + name);
        return field.GetValue(target);
    }

    private static float GetFloat(object target, string name)
    {
        return Convert.ToSingle(GetField(target, name));
    }

    private static object GetProperty(object target, string name)
    {
        PropertyInfo property = target.GetType().GetProperty(name, BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
        Assert.IsNotNull(property, "Property not found: " + name);
        return property.GetValue(target, null);
    }

    private static object Invoke(object target, string methodName, params object[] arguments)
    {
        MethodInfo method = target.GetType().GetMethod(methodName, BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
        Assert.IsNotNull(method, "Method not found: " + methodName);
        return method.Invoke(target, arguments);
    }
}
