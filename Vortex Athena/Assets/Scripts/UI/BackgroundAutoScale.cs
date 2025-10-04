using UnityEngine;
using UnityEngine.UI;

[RequireComponent(typeof(RectTransform))]
public class BackgroundAutoScale : MonoBehaviour
{
    public bool fillScreen = true; // true = recorta, false = barras

    void Update()
    {
        RectTransform rt = GetComponent<RectTransform>();
        float screenAspect = (float)Screen.width / Screen.height;

        // Asumimos que el sprite/textura tiene proporción 9:16
        float targetAspect = 9f / 16f;

        if (fillScreen)
        {
            if (screenAspect > targetAspect)
                rt.sizeDelta = new Vector2(Screen.width, Screen.width / targetAspect);
            else
                rt.sizeDelta = new Vector2(Screen.height * targetAspect, Screen.height);
        }
        else
        {
            if (screenAspect > targetAspect)
                rt.sizeDelta = new Vector2(Screen.height * targetAspect, Screen.height);
            else
                rt.sizeDelta = new Vector2(Screen.width, Screen.width / targetAspect);
        }
    }
}

