using System.Collections;
using UnityEngine;

[RequireComponent(typeof(SpriteRenderer))]
[DefaultExecutionOrder(200)]  // Se ejecuta después de los controladores de orientación
public class ArenaWallAutoScale : MonoBehaviour
{
    [Header("Cámara objetivo (opcional)")]
    [SerializeField] private Camera targetCamera;

    [Header("Ajuste automático")]
    [SerializeField] private bool continuousAdjust = true; // reajustar si cambia aspect
    [SerializeField] private int settleChecks = 3;          // cuántos frames iguales para estabilizar
    [SerializeField] private int maxStartupFrames = 12;     // máximo tiempo de ajuste al inicio

    private SpriteRenderer sr;
    private float lastAspect = -1f;

    private void Awake()
    {
        sr = GetComponent<SpriteRenderer>();
    }

    private void OnEnable()
    {
        StartCoroutine(AutoFitRoutine());
    }

    private IEnumerator AutoFitRoutine()
    {
        Camera cam = targetCamera != null ? targetCamera : Camera.main;
        if (cam == null || !cam.orthographic) yield break;

        int stable = 0;
        int attempts = 0;

        // --- 🟦 AJUSTE INICIAL — HASTA QUE LA ORIENTACIÓN ESTÉ ESTABLE ---
        while (stable < settleChecks && attempts < maxStartupFrames)
        {
            float aspect = cam.aspect;

            if (Mathf.Approximately(aspect, lastAspect))
                stable++;
            else
            {
                stable = 0;
                lastAspect = aspect;
            }

            ApplyScale(cam);

            attempts++;
            yield return null;
        }

        // --- 🟩 AJUSTE CONTINUO (opcional) ---
        if (continuousAdjust)
        {
            while (true)
            {
                float aspect = cam.aspect;

                if (!Mathf.Approximately(aspect, lastAspect))
                {
                    lastAspect = aspect;
                    ApplyScale(cam);
                }

                yield return null;
            }
        }
    }

    private void ApplyScale(Camera cam)
    {
        // 📌 Tamaño del mundo visible
        float worldHeight = cam.orthographicSize * 2f;
        float worldWidth = worldHeight * cam.aspect;

        // 📌 Tamaño real del sprite (en unidades del mundo)
        Vector2 spriteSize = sr.sprite.bounds.size;

        // 📌 Escalado horizontal forzado (Landscape)
        Vector3 newScale = transform.localScale;
        newScale.x = worldWidth / spriteSize.x;

        // Sólo escalamos Y cuando sea necesario (útil si tu sprite ya está rotado a landscape)
        newScale.y = worldHeight / spriteSize.y;

        transform.localScale = newScale;
    }
}


