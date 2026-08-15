using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(RectTransform))]
public class NoesisFanLayout : MonoBehaviour
{
    public float cardAspectRatio = 414f / 709f;
    public float maxCardHeight = 400f;
    public float minCardHeight = 90f;
    public float widthPadding = 12f;
    public float heightUsage = 0.92f;
    public float verticalArcFactor = 0.18f;

    private RectTransform rectTransform;

    public RectTransform RectTransform => rectTransform != null ? rectTransform : rectTransform = GetComponent<RectTransform>();

    public void ApplyLayout(IReadOnlyList<NoesisCardView> cards, float fanArcDegrees, float radiusFactor, float horizontalFactor, float scaleFactor)
    {
        if (cards == null || cards.Count == 0) return;

        Rect rect = RectTransform.rect;
        float containerWidth = Mathf.Max(rect.width, 1f);
        float containerHeight = Mathf.Max(rect.height, 1f);
        float usableWidth = Mathf.Max(containerWidth - widthPadding * 2f, 1f);
        float usableHeight = Mathf.Max(containerHeight * Mathf.Clamp01(heightUsage), 1f);
        float arc = Mathf.Clamp(fanArcDegrees, 0f, 160f);
        float safeRadiusFactor = Mathf.Max(0.1f, radiusFactor);
        float safeHorizontalFactor = Mathf.Max(0f, horizontalFactor);
        float maxAngleRad = arc * 0.5f * Mathf.Deg2Rad;
        float edgeHalfWidthFactor = (Mathf.Cos(maxAngleRad) * cardAspectRatio + Mathf.Sin(maxAngleRad)) * 0.5f;
        float fanWidthFactor = 2f * (Mathf.Sin(maxAngleRad) * safeRadiusFactor * safeHorizontalFactor + edgeHalfWidthFactor);
        float cardHeightByWidth = usableWidth / Mathf.Max(fanWidthFactor, cardAspectRatio);
        float edgeHalfHeightFactor = (Mathf.Sin(maxAngleRad) * cardAspectRatio + Mathf.Cos(maxAngleRad)) * 0.5f;
        float edgeVerticalOffsetFactor = safeRadiusFactor * verticalArcFactor * (1f - Mathf.Cos(maxAngleRad));
        float cardHeightByGeometry = containerHeight * 0.5f / Mathf.Max(0.5f, edgeHalfHeightFactor + edgeVerticalOffsetFactor);
        float minHeightThatFits = Mathf.Min(minCardHeight, cardHeightByWidth, cardHeightByGeometry);
        float responsiveScale = Mathf.Clamp(scaleFactor, 0.5f, 1.5f);
        float baseCardHeight = Mathf.Min(usableHeight, cardHeightByWidth, cardHeightByGeometry, maxCardHeight / responsiveScale);
        float cardHeight = Mathf.Clamp(
            Mathf.Min(baseCardHeight * responsiveScale, usableHeight, cardHeightByGeometry, maxCardHeight),
            minHeightThatFits,
            maxCardHeight);
        float cardWidth = cardHeight * cardAspectRatio;
        float radius = cardHeight * safeRadiusFactor;

        float edgeHalfWidth = edgeHalfWidthFactor * cardHeight;
        float availableTravel = Mathf.Max(0f, containerWidth * 0.5f - widthPadding - edgeHalfWidth);
        float projectedTravel = Mathf.Sin(maxAngleRad) * radius;
        float effectiveHorizontalFactor = projectedTravel > 0.001f
            ? Mathf.Min(safeHorizontalFactor, availableTravel / projectedTravel)
            : 0f;

        float startAngle = cards.Count > 1 ? -arc * 0.5f : 0f;
        float step = cards.Count > 1 ? arc / (cards.Count - 1) : 0f;
        Vector2 pivot = new Vector2(containerWidth * 0.5f, containerHeight * 0.5f);

        for (int i = 0; i < cards.Count; i++)
        {
            NoesisCardView card = cards[i];
            if (card == null) continue;

            float angle = startAngle + step * i;
            float rad = angle * Mathf.Deg2Rad;
            float centerX = pivot.x + Mathf.Sin(rad) * radius * effectiveHorizontalFactor;
            float centerY = pivot.y - radius * verticalArcFactor + Mathf.Cos(rad) * radius * verticalArcFactor;
            float halfExtentX = (Mathf.Abs(Mathf.Cos(rad)) * cardWidth + Mathf.Abs(Mathf.Sin(rad)) * cardHeight) * 0.5f;
            float halfExtentY = (Mathf.Abs(Mathf.Sin(rad)) * cardWidth + Mathf.Abs(Mathf.Cos(rad)) * cardHeight) * 0.5f;
            centerX = Mathf.Clamp(centerX, widthPadding + halfExtentX, containerWidth - widthPadding - halfExtentX);
            centerY = Mathf.Clamp(centerY, halfExtentY, containerHeight - halfExtentY);

            card.SetLayoutPose(
                new Vector2(centerX, centerY),
                Quaternion.Euler(0f, 0f, -angle),
                new Vector2(cardWidth, cardHeight),
                i);
        }
    }
}
