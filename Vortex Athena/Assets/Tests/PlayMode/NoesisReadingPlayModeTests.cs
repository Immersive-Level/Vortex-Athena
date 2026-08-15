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

        float introDuration = GetFloat(controller, "fanIntroDuration");
        yield return new WaitForSecondsRealtime(introDuration + 0.2f);

        List<Component> views = FindActiveSceneComponents(cardViewType);
        Assert.AreEqual(17, views.Count, "The fan must instantiate all 17 cards.");
        foreach (Component view in views)
        {
            CanvasGroup group = view.GetComponent<CanvasGroup>();
            Assert.IsNotNull(group);
            Assert.That(group.alpha, Is.EqualTo(1f).Within(0.02f));
            Assert.IsTrue(group.interactable, "Every card must become interactable after the fan intro.");
            Assert.IsTrue(group.blocksRaycasts, "Every card must receive pointer input after the fan intro.");
            Assert.IsNotNull(view.GetComponent<Image>().sprite);
        }

        views = views.OrderBy(view => view.GetComponent<RectTransform>().anchoredPosition.x).ToList();
        RectTransform leftCard = views[0].GetComponent<RectTransform>();
        RectTransform centerCard = views[views.Count / 2].GetComponent<RectTransform>();
        RectTransform rightCard = views[views.Count - 1].GetComponent<RectTransform>();
        Assert.Greater(centerCard.anchoredPosition.y, leftCard.anchoredPosition.y, "The fan center must sit above the left edge.");
        Assert.Greater(centerCard.anchoredPosition.y, rightCard.anchoredPosition.y, "The fan center must sit above the right edge.");
        Assert.Greater(Mathf.DeltaAngle(0f, leftCard.localEulerAngles.z), 0f, "Left cards must open outward.");
        Assert.Less(Mathf.DeltaAngle(0f, rightCard.localEulerAngles.z), 0f, "Right cards must open outward.");
        Assert.That(GetFloat(controller, "fanScaleFactor"), Is.EqualTo(1.25f).Within(0.01f));

        Button pickerBackButton = (Button)GetField(controller, "pickerBackButton");
        Assert.IsTrue(pickerBackButton.gameObject.activeInHierarchy);
        Assert.AreEqual("VA_UINuevo_01_2", pickerBackButton.GetComponent<Image>().sprite.name);
        pickerBackButton.onClick.Invoke();
        yield return WaitForScene("MainMenu");

        GameObject.Find("NoesisReadingBtn").GetComponent<Button>().onClick.Invoke();
        yield return WaitForScene("NoesisReadingScene");
        controller = FindSceneComponent(controllerType);
        yield return new WaitForSecondsRealtime(GetFloat(controller, "fanIntroDuration") + 0.2f);
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

        GameObject headerRoot = (GameObject)GetField(controller, "headerRoot");
        Assert.IsFalse(headerRoot.activeSelf, "The header must be hidden in reveal view.");
        Assert.AreEqual(0, revealSection.GetComponentsInChildren<TMP_Text>(false).Length, "Reveal view must contain no visible text.");
        Button consultAgainButton = (Button)GetField(controller, "consultAgainButton");
        Assert.IsFalse(consultAgainButton.gameObject.activeInHierarchy, "The legacy CONSULTAR DE NUEVO button must remain hidden.");

        Button revealBackButton = (Button)GetField(controller, "revealBackButton");
        Assert.IsTrue(revealBackButton.gameObject.activeInHierarchy);
        Assert.AreEqual("VA_UINuevo_01_2", revealBackButton.GetComponent<Image>().sprite.name);
        revealBackButton.onClick.Invoke();
        yield return new WaitForSecondsRealtime(GetFloat(controller, "revealFadeDuration") + introDuration + 0.4f);

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
