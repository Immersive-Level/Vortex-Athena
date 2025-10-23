using System.Collections;
using UnityEngine;

[RequireComponent(typeof(SpriteRenderer))]
[DefaultExecutionOrder(200)] // corre tras tu forzado de orientación de la escena
public class ArenaAutoScale : MonoBehaviour
{
    [SerializeField] private Camera targetCamera;     // si es null usa Camera.main
    [SerializeField] private bool continuous = false; // re-ajustar si cambia el aspect en runtime
    [SerializeField] private int settleFrames = 2;    // frames consecutivos con el mismo aspect
    [SerializeField] private int maxWaitFrames = 10;  // tope de espera tras cargar la escena

    private SpriteRenderer sr;
    private float lastAspect = -1f;

    void Awake()
    {
        sr = GetComponent<SpriteRenderer>();
    }

    void OnEnable()
    {
        StartCoroutine(WaitAndFit());
    }

    IEnumerator WaitAndFit()
    {
        Camera cam = targetCamera != null ? targetCamera : Camera.main;
        if (cam == null || !cam.orthographic || sr == null || sr.sprite == null) yield break;

        // Espera a que la orientación/viewport se estabilice al entrar a la escena
        int stable = 0;
        int tries = 0;
        while (stable < settleFrames && tries < maxWaitFrames)
        {
            float a = cam.aspect;
            if (Mathf.Approximately(a, lastAspect)) stable++;
            else { stable = 0; lastAspect = a; }

            FitToCamera(cam);
            tries++;
            yield return null; // siguiente frame
        }

        // Opcional: seguir ajustando si el aspect cambia (p. ej., cambio de ventana)
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
        float worldHeight = cam.orthographicSize * 2f;
        float worldWidth = worldHeight * cam.aspect;

        Vector2 size = sr.sprite.bounds.size;

        Vector3 newScale = transform.localScale;
        newScale.x = worldWidth / size.x;
        newScale.y = worldHeight / size.y;
        transform.localScale = newScale;
    }
}


