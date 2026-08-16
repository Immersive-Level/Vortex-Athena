using UnityEngine;

[RequireComponent(typeof(RectTransform))]
public class SafeAreaHandler : MonoBehaviour
{
    public bool applyOnEnable = true;
    public bool updateWhenChanged = true;

    private RectTransform rectTransform;
    private Rect lastReportedSafeArea;
    private Vector2Int lastScreenSize;

    private void Awake()
    {
        rectTransform = GetComponent<RectTransform>();
    }

    private void OnEnable()
    {
        if (applyOnEnable)
            ApplySafeArea();
    }

    private void Update()
    {
        if (!updateWhenChanged) return;

        Vector2Int screenSize = new Vector2Int(Screen.width, Screen.height);
        if (lastReportedSafeArea != Screen.safeArea || lastScreenSize != screenSize)
            ApplySafeArea();
    }

    public void ApplySafeArea()
    {
        if (rectTransform == null)
            rectTransform = GetComponent<RectTransform>();

        int screenWidth = Mathf.Max(1, Screen.width);
        int screenHeight = Mathf.Max(1, Screen.height);
        Rect safeArea = Screen.safeArea;
        lastReportedSafeArea = safeArea;
        bool invalidSafeArea = safeArea.width <= 0f
            || safeArea.height <= 0f
            || safeArea.xMin < 0f
            || safeArea.yMin < 0f
            || safeArea.xMax > screenWidth + 0.5f
            || safeArea.yMax > screenHeight + 0.5f;
        if (invalidSafeArea)
        {
            // Some Editor Game View configurations report the monitor safe area
            // instead of the simulated viewport. Never allow anchors outside 0..1.
            safeArea = new Rect(0f, 0f, screenWidth, screenHeight);
        }

        lastScreenSize = new Vector2Int(screenWidth, screenHeight);

        Vector2 anchorMin = safeArea.position;
        Vector2 anchorMax = safeArea.position + safeArea.size;
        anchorMin.x /= screenWidth;
        anchorMin.y /= screenHeight;
        anchorMax.x /= screenWidth;
        anchorMax.y /= screenHeight;

        rectTransform.anchorMin = anchorMin;
        rectTransform.anchorMax = anchorMax;
        rectTransform.offsetMin = Vector2.zero;
        rectTransform.offsetMax = Vector2.zero;
    }
}
