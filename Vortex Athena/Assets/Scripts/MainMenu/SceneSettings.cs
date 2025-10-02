using UnityEngine;

public class SceneSettings : MonoBehaviour
{
    public enum OrientationMode { Portrait, Landscape }

    [Header("Ajustes de escena")]
    public OrientationMode orientation = OrientationMode.Portrait;

    void Awake()
    {
        ApplyOrientation();
    }

    void ApplyOrientation()
    {
        if (orientation == OrientationMode.Portrait)
        {
            Screen.orientation = ScreenOrientation.Portrait;
        }
        else if (orientation == OrientationMode.Landscape)
        {
            Screen.orientation = ScreenOrientation.LandscapeLeft;
        }
    }
}

