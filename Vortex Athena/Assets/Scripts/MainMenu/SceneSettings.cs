using UnityEngine;

[DefaultExecutionOrder(-1000)] // se ejecuta antes que la mayoría, útil para el UI
public class ForceOrientation : MonoBehaviour
{
    public enum Mode
    {
        Portrait,
        Landscape,        // acepta cualquiera de las dos (Left/Right)
        LandscapeLeft,
        LandscapeRight
    }

    [Header("Orientation for THIS scene")]
    public Mode orientation = Mode.Portrait;

    [Tooltip("Si está activo, deshabilita autorrotación hacia otras orientaciones mientras esta escena esté activa.")]
    public bool lockToThisOrientation = true;

    void Awake()
    {
        Apply();
    }

    void OnEnable()
    {
        // Por si algún objeto cambia orientación en Awake, aplicamos otra vez
        Apply();
    }

#if UNITY_ANDROID || UNITY_IOS
    void Apply()
    {
        // Configura qué autorrotaciones están permitidas mientras está esta escena
        Screen.autorotateToPortrait = (orientation == Mode.Portrait);
        Screen.autorotateToPortraitUpsideDown = false; // suele deshabilitarse en juegos
        Screen.autorotateToLandscapeLeft = (orientation == Mode.Landscape || orientation == Mode.LandscapeLeft);
        Screen.autorotateToLandscapeRight = (orientation == Mode.Landscape || orientation == Mode.LandscapeRight);

        if (lockToThisOrientation)
        {
            // “Fuerza” la orientación elegida
            switch (orientation)
            {
                case Mode.Portrait:
                    Screen.orientation = ScreenOrientation.Portrait;
                    break;
                case Mode.LandscapeLeft:
                    Screen.orientation = ScreenOrientation.LandscapeLeft;
                    break;
                case Mode.LandscapeRight:
                case Mode.Landscape:
                    Screen.orientation = ScreenOrientation.LandscapeRight;
                    break;
            }
        }
        else
        {
            // Dejar en autorrotación limitada a las opciones marcadas arriba
            Screen.orientation = ScreenOrientation.AutoRotation;
        }
    }
#else
    void Apply() { /* En Editor/PC esto no tiene efecto en pantalla física */ }
#endif
}

