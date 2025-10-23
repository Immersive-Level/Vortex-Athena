using System.Collections;
using UnityEngine;

[RequireComponent(typeof(SpriteRenderer))]
[DefaultExecutionOrder(200)] // corre después de tu script que fuerza la orientación
public class ArenaWallAutoScale : MonoBehaviour
{
    [SerializeField] private Camera targetCamera;     // opcional; si es null usa Camera.main
    [SerializeField] private bool continuous = false; // si true, re-ajusta cuando cambie el aspect
    [SerializeField] private int settleFrames = 2;    // frames consecutivos con mismo aspect para considerarlo “estable”
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
        if (cam == null || !cam.orthographic) yield break;

        // Espera a que la orientación/viewport se estabilice
        int stable = 0;
        int tries = 0;
        while (stable < settleFrames && tries < maxWaitFrames)
        {
            float a = cam.aspect;
            if (Mathf.Approximately(a, lastAspect)) stable++;
            else { stable = 0; lastAspect = a; }

            FitToCamera(cam);
            tries++;
            yield return null; // espera al siguiente frame
        }

        // Opcional: seguir ajustando si cambia el aspect (por split-screen, resize, etc.)
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
        float worldH = cam.orthographicSize * 2f;
        float worldW = worldH * cam.aspect;

        Vector2 spriteSize = sr.sprite.bounds.size;

        Vector3 newScale = transform.localScale;
        newScale.x = worldW / spriteSize.x;
        newScale.y = worldH / spriteSize.y;
        transform.localScale = newScale;
    }
}


