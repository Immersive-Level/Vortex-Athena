using System.Collections.Generic;
using UnityEngine;

[RequireComponent(typeof(RectTransform))]
public class NoesisFanLayout : MonoBehaviour
{
    public float cardAspectRatio = 414f / 709f;
    public float maxCardHeight = 320f;
    public float minCardHeight = 90f;
    public float widthPadding = 12f;
    public float heightUsage = 0.92f;
    public float verticalArcFactor = 0.18f;

    private RectTransform rectTransform;

    public RectTransform RectTransform
    {
        get
        {
            if (rectTransform == null)
                rectTransform = GetComponent<RectTransform>();
            return rectTransform;
        }
    }

    public void ApplyLayout(IReadOnlyList<NoesisCardView> cards, float fanArcDegrees, float radiusFactor, float horizontalFactor)
    {
        if (cards == null || cards.Count == 0) return;

        Rect rect = RectTransform.rect;
        float containerWidth = Mathf.Max(rect.width, 1f);
        float containerHeight = Mathf.Max(rect.height, 1f);
        float arc = Mathf.Max(0f, fanArcDegrees);
        float startAngle = cards.Count > 1 ? -arc * 0.5f : 0f;
        float step = cards.Count > 1 ? arc / (cards.Count - 1) : 0f;
        float maxAngleRad = arc * 0.5f * Mathf.Deg2Rad;
        float fanWidthFactor = 2f * Mathf.Sin(maxAngleRad) * radiusFactor * horizontalFactor + cardAspectRatio;
        float cardHeightByWidth = (containerWidth - widthPadding) / Mathf.Max(fanWidthFactor, cardAspectRatio);
        float cardHeight = Mathf.Clamp(Mathf.Min(containerHeight * heightUsage, cardHeightByWidth, maxCardHeight), minCardHeight, maxCardHeight);
        float cardWidth = cardHeight * cardAspectRatio;
        float radius = cardHeight * radiusFactor;
        Vector2 pivot = new Vector2(containerWidth * 0.5f, containerHeight * 0.5f);

        for (int i = 0; i < cards.Count; i++)
        {
            NoesisCardView card = cards[i];
            if (card == null) continue;

            float angle = startAngle + step * i;
            float rad = angle * Mathf.Deg2Rad;
            float centerX = pivot.x + Mathf.Sin(rad) * radius * horizontalFactor;
            float centerY = pivot.y + radius * verticalArcFactor - Mathf.Cos(rad) * radius * verticalArcFactor;
            RectTransform cardRect = card.RectTransform;

            cardRect.anchorMin = new Vector2(0f, 0f);
            cardRect.anchorMax = new Vector2(0f, 0f);
            cardRect.pivot = new Vector2(0.5f, 0.5f);
            cardRect.sizeDelta = new Vector2(cardWidth, cardHeight);
            cardRect.anchoredPosition = new Vector2(centerX, centerY);
            cardRect.localRotation = Quaternion.Euler(0f, 0f, angle);
            cardRect.localScale = Vector3.one;
            cardRect.SetSiblingIndex(i);
            card.StoreBaseTransform();
        }
    }
}
