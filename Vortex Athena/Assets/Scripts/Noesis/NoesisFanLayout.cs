using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(RectTransform))]
public class NoesisFanLayout : MonoBehaviour
{
    public float cardAspectRatio = 414f / 709f;
    public float baseCardHeight = 380f;
    public float maxCardHeight = 500f;
    public float minCardHeight = 90f;
    public float widthPadding = 18f;
    public float heightPadding = 18f;

    private RectTransform rectTransform;

    public RectTransform RectTransform => rectTransform != null ? rectTransform : rectTransform = GetComponent<RectTransform>();
    public Vector2 LastStackPosition { get; private set; }
    public Vector2 LastRadialCenter { get; private set; }
    public float LastAppliedScale { get; private set; } = 1f;

    public void ApplyLayout(
        IReadOnlyList<NoesisCardView> cards,
        float fanRadius,
        float totalAngle,
        float cardScale,
        float angleStep,
        Vector2 fanCenterOffset)
    {
        if (cards == null || cards.Count == 0) return;

        Rect rect = RectTransform.rect;
        float containerWidth = Mathf.Max(rect.width, 1f);
        float containerHeight = Mathf.Max(rect.height, 1f);
        float usableWidth = Mathf.Max(containerWidth - widthPadding * 2f, 1f);
        float usableHeight = Mathf.Max(containerHeight - heightPadding * 2f, 1f);
        float requestedArc = Mathf.Clamp(totalAngle, 0f, 350f);
        float step = cards.Count > 1
            ? (angleStep > 0f ? Mathf.Min(angleStep, requestedArc / (cards.Count - 1)) : requestedArc / (cards.Count - 1))
            : 0f;
        float arc = step * Mathf.Max(0, cards.Count - 1);
        float startAngle = -arc * 0.5f;
        float requestedCardHeight = Mathf.Clamp(baseCardHeight * Mathf.Clamp(cardScale, 0.5f, 1.75f), minCardHeight, maxCardHeight);
        float requestedRadius = Mathf.Max(0f, fanRadius);

        Bounds2D requestedBounds = CalculateBounds(cards.Count, startAngle, step, requestedCardHeight, requestedRadius);
        float fitScale = Mathf.Min(
            1f,
            usableWidth / Mathf.Max(requestedBounds.Width, 1f),
            usableHeight / Mathf.Max(requestedBounds.Height, 1f));
        float cardHeight = Mathf.Max(1f, requestedCardHeight * fitScale);
        float cardWidth = cardHeight * cardAspectRatio;
        float radius = requestedRadius * fitScale;
        LastAppliedScale = fitScale;

        Bounds2D bounds = CalculateBounds(cards.Count, startAngle, step, cardHeight, radius);
        Vector2 requestedCenter = new Vector2(containerWidth * 0.5f, containerHeight * 0.5f) + fanCenterOffset;
        Vector2 translation = requestedCenter - bounds.Center;
        translation.x = Mathf.Clamp(
            translation.x,
            widthPadding - bounds.MinX,
            containerWidth - widthPadding - bounds.MaxX);
        translation.y = Mathf.Clamp(
            translation.y,
            heightPadding - bounds.MinY,
            containerHeight - heightPadding - bounds.MaxY);
        LastRadialCenter = translation;
        LastStackPosition = translation + Vector2.up * radius;

        for (int i = 0; i < cards.Count; i++)
        {
            NoesisCardView card = cards[i];
            if (card == null) continue;

            float angle = startAngle + step * i;
            float rad = angle * Mathf.Deg2Rad;
            Vector2 center = translation + new Vector2(Mathf.Sin(rad) * radius, Mathf.Cos(rad) * radius);

            card.SetLayoutPose(
                center,
                Quaternion.Euler(0f, 0f, -angle),
                new Vector2(cardWidth, cardHeight),
                i);
        }
    }

    private Bounds2D CalculateBounds(int cardCount, float startAngle, float step, float cardHeight, float radius)
    {
        float cardWidth = cardHeight * cardAspectRatio;
        Bounds2D bounds = Bounds2D.Empty;
        for (int i = 0; i < cardCount; i++)
        {
            float angle = startAngle + step * i;
            float rad = angle * Mathf.Deg2Rad;
            Vector2 center = new Vector2(Mathf.Sin(rad) * radius, Mathf.Cos(rad) * radius);
            float halfWidth = (Mathf.Abs(Mathf.Cos(rad)) * cardWidth + Mathf.Abs(Mathf.Sin(rad)) * cardHeight) * 0.5f;
            float halfHeight = (Mathf.Abs(Mathf.Sin(rad)) * cardWidth + Mathf.Abs(Mathf.Cos(rad)) * cardHeight) * 0.5f;
            bounds.Encapsulate(center, halfWidth, halfHeight);
        }
        return bounds;
    }

    private struct Bounds2D
    {
        public float MinX;
        public float MaxX;
        public float MinY;
        public float MaxY;
        private bool initialized;

        public static Bounds2D Empty => new Bounds2D();
        public float Width => MaxX - MinX;
        public float Height => MaxY - MinY;
        public Vector2 Center => new Vector2((MinX + MaxX) * 0.5f, (MinY + MaxY) * 0.5f);

        public void Encapsulate(Vector2 center, float halfWidth, float halfHeight)
        {
            float minX = center.x - halfWidth;
            float maxX = center.x + halfWidth;
            float minY = center.y - halfHeight;
            float maxY = center.y + halfHeight;
            if (!initialized)
            {
                MinX = minX;
                MaxX = maxX;
                MinY = minY;
                MaxY = maxY;
                initialized = true;
                return;
            }

            MinX = Mathf.Min(MinX, minX);
            MaxX = Mathf.Max(MaxX, maxX);
            MinY = Mathf.Min(MinY, minY);
            MaxY = Mathf.Max(MaxY, maxY);
        }
    }
}
