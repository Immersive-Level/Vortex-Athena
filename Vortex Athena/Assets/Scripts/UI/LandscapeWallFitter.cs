using System.Collections;
using UnityEngine;

[RequireComponent(typeof(SpriteRenderer))]
[DefaultExecutionOrder(200)] // corre tras tu script global de orientación
public class LandscapeWallFitter : MonoBehaviour
{
    [Header("Camera")]
    [SerializeField] private Camera targetCamera;         // si es null usa Camera.main

    [Header("Flow")]
    [SerializeField] private bool forceLandscapeOnAwake = true;
    [SerializeField] private int settleFrames = 2;        // frames iguales para considerar estable
    [SerializeField] private int maxWaitFrames = 15;      // tope de espera inicial
    [SerializeField] private bool continuous = true;      // re-ajuste si cambia el aspect en runtime

    private SpriteRenderer sr;
    private float lastAspect = -1f;

    void Awake()
    {
        sr = GetComponent<SpriteRenderer>();
        if (forceLandscapeOnAwake) ForceLandscape();
    }

    void OnEnable()
    {
        StartCoroutine(WaitAndFit());
    }

    IEnumerator WaitAndFit()
    {
        Camera cam = targetCamera != null ? targetCamera : Camera.main;
        if (cam == null || !cam.orthographic || sr == null || sr.sprite == null) yield break;

        // Espera a que el teléfono aplique landscape y el aspect se estabilice
        int stable = 0, tries = 0;
        lastAspect = -1f;

        while (stable < settleFrames && tries < maxWaitFrames)
        {
            float a = cam.aspect;
            if (Mathf.Approximately(a, lastAspect)) stable++;
            else { stable = 0; lastAspect = a; }

            FitToCamera(cam);
            tries++;
            yield return null;
        }

        // Reajuste continuo (por cambios de barra de navegación/notch, multitarea, etc.)
        if (continuous)
        {
            while (enabled)
            {
                cam = targetCamera != null ? targetCamera : Camera.main;
                if (cam != null && cam.orthographic)
                {
                    if (!Mathf.Approximately(cam.aspect, lastAspect))
                    {
                        lastAspect = cam.aspect;
                        FitToCamera(cam);
                    }
                }
                yield return null;
            }
        }
    }

    void FitToCamera(Camera cam)
    {
        // Escala “stretch” para cubrir exactamente el viewport (como tu script original)
        float worldHeight = cam.orthographicSize * 2f;
        float worldWidth = worldHeight * cam.aspect;

        Vector2 spriteSize = sr.sprite.bounds.size;
        Vector3 s = transform.localScale;
        s.x = worldWidth / spriteSize.x;
        s.y = worldHeight / spriteSize.y;
        transform.localScale = s;
    }

    void ForceLandscape()
    {
#if UNITY_ANDROID && !UNITY_EDITOR
        // Permitir sólo landscape en runtime (evita parpadeos al entrar a la escena)
        Screen.autorotateToLandscapeLeft  = true;
        Screen.autorotateToLandscapeRight = true;
        Screen.autorotateToPortrait       = false;
        Screen.autorotateToPortraitUpsideDown = false;
        Screen.orientation = ScreenOrientation.AutoRotation;
#endif
    }
}

