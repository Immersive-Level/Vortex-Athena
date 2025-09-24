using UnityEngine;

public class BlackHoleDebugger : MonoBehaviour
{
    [Header("Debug Settings")]
    [SerializeField] private bool showGravityVectors = true;
    [SerializeField] private bool showZoneInfo = true;
    [SerializeField] private Color gravityVectorColor = Color.red;
    [SerializeField] private float vectorScale = 0.1f;

    private BlackHoleCore blackHole;

    private void Awake()
    {
        blackHole = GetComponent<BlackHoleCore>();
    }

    private void OnDrawGizmos()
    {
        if (!Application.isPlaying || blackHole == null) return;

        if (showZoneInfo)
        {
            DrawZoneInfo();
        }

        if (showGravityVectors)
        {
            DrawGravityVectors();
        }
    }

    private void DrawZoneInfo()
    {
        Vector3 pos = transform.position;

        // Información del agujero negro
        Gizmos.color = Color.white;
        Gizmos.DrawWireCube(pos + Vector3.up * 3, Vector3.one * 0.5f);

#if UNITY_EDITOR
        UnityEditor.Handles.Label(pos + Vector3.up * 3.5f,
            $"Intensity: {blackHole.CurrentIntensity:F2}\n" +
            $"Radius: {blackHole.CurrentInfluenceRadius:F1}\n" +
            $"Objects: {blackHole.AffectedObjectsCount}");
#endif
    }

    private void DrawGravityVectors()
    {
        var affectedObjects = FindObjectsOfType<GravityAffectedBase>();

        Gizmos.color = gravityVectorColor;

        foreach (var obj in affectedObjects)
        {
            if (!obj.IsInGravityField) continue;

            Vector3 objPos = obj.transform.position;
            Vector3 direction = (transform.position - objPos).normalized;
            float intensity = obj.CurrentGravityIntensity;

            Gizmos.DrawRay(objPos, direction * intensity * vectorScale);
        }
    }
}