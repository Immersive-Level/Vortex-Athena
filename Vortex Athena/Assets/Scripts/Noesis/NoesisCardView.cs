using System;
using System.Collections;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

[RequireComponent(typeof(RectTransform))]
public class NoesisCardView : MonoBehaviour, IPointerClickHandler, IPointerEnterHandler, IPointerExitHandler
{
    [Header("References")]
    public Image cardImage;
    public Image highlightImage;
    public CanvasGroup canvasGroup;
    public Animator optionalAnimator;

    [Header("Fallback")]
    public Color fallbackBackColor = new Color(0.07f, 0.08f, 0.14f, 1f);
    public Color fallbackFrontColor = new Color(0.77f, 0.64f, 0.29f, 1f);

    private RectTransform rectTransform;
    private NoesisCardData data;
    private Sprite defaultBackSprite;
    private bool interactable;
    private bool faceUp;
    private Action<NoesisCardView> selectedCallback;
    private Vector2 baseAnchoredPosition;
    private Quaternion baseRotation;

    public NoesisCardData Data => data;
    public RectTransform RectTransform => rectTransform;

    private void Awake()
    {
        rectTransform = GetComponent<RectTransform>();
        if (cardImage == null)
            cardImage = GetComponent<Image>();
        if (canvasGroup == null)
            canvasGroup = GetComponent<CanvasGroup>() ?? gameObject.AddComponent<CanvasGroup>();
    }

    public void Initialize(NoesisCardData cardData, Sprite sharedBackSprite, Action<NoesisCardView> onSelected)
    {
        data = cardData;
        defaultBackSprite = sharedBackSprite;
        selectedCallback = onSelected;
        faceUp = false;
        SetInteractable(true);
        SetVisible(true);
        SetHighlight(false);
        RefreshImage();
    }

    public void StoreBaseTransform()
    {
        baseAnchoredPosition = rectTransform.anchoredPosition;
        baseRotation = rectTransform.localRotation;
    }

    public void SetInteractable(bool value)
    {
        interactable = value;
        if (canvasGroup != null)
        {
            canvasGroup.blocksRaycasts = value;
            canvasGroup.interactable = value;
        }
    }

    public void SetFaceUp(bool value)
    {
        faceUp = value;
        RefreshImage();

        if (optionalAnimator != null)
        {
            optionalAnimator.SetBool("FaceUp", faceUp);
            optionalAnimator.SetTrigger("Reveal");
        }
    }

    public void SetVisible(bool value)
    {
        if (canvasGroup == null) return;
        canvasGroup.alpha = value ? 1f : 0f;
        canvasGroup.blocksRaycasts = value && interactable;
    }

    public void OnPointerClick(PointerEventData eventData)
    {
        if (!interactable) return;
        selectedCallback?.Invoke(this);
    }

    public void OnPointerEnter(PointerEventData eventData)
    {
        if (!interactable) return;
        SetHighlight(true);
    }

    public void OnPointerExit(PointerEventData eventData)
    {
        SetHighlight(false);
    }

    public IEnumerator FlyAway(float duration, float verticalDistance, float rotationOffset, float targetScale)
    {
        SetInteractable(false);
        SetHighlight(false);

        Vector2 startPosition = rectTransform.anchoredPosition;
        Quaternion startRotation = rectTransform.localRotation;
        Vector3 startScale = rectTransform.localScale;
        Vector2 endPosition = startPosition + new Vector2(0f, verticalDistance);
        Quaternion endRotation = Quaternion.Euler(0f, 0f, rectTransform.localEulerAngles.z + rotationOffset);
        Vector3 endScale = Vector3.one * targetScale;
        float startAlpha = canvasGroup != null ? canvasGroup.alpha : 1f;

        if (duration <= 0f)
        {
            rectTransform.anchoredPosition = endPosition;
            rectTransform.localRotation = endRotation;
            rectTransform.localScale = endScale;
            if (canvasGroup != null) canvasGroup.alpha = 0f;
            yield break;
        }

        float elapsed = 0f;
        while (elapsed < duration)
        {
            elapsed += Time.unscaledDeltaTime;
            float t = Mathf.Clamp01(elapsed / duration);
            float eased = t * t * (3f - 2f * t);
            rectTransform.anchoredPosition = Vector2.LerpUnclamped(startPosition, endPosition, eased);
            rectTransform.localRotation = Quaternion.Slerp(startRotation, endRotation, eased);
            rectTransform.localScale = Vector3.Lerp(startScale, endScale, eased);
            if (canvasGroup != null) canvasGroup.alpha = Mathf.Lerp(startAlpha, 0f, eased);
            yield return null;
        }
    }

    public IEnumerator PulseSelected(float duration, float scale)
    {
        SetInteractable(false);
        SetHighlight(true);
        SetFaceUp(true);

        Vector3 startScale = rectTransform.localScale;
        Vector3 endScale = Vector3.one * scale;

        if (duration <= 0f)
        {
            rectTransform.localScale = endScale;
            yield break;
        }

        float elapsed = 0f;
        while (elapsed < duration)
        {
            elapsed += Time.unscaledDeltaTime;
            float t = Mathf.Clamp01(elapsed / duration);
            rectTransform.localScale = Vector3.Lerp(startScale, endScale, t);
            yield return null;
        }
    }

    public void ResetToBase()
    {
        rectTransform.anchoredPosition = baseAnchoredPosition;
        rectTransform.localRotation = baseRotation;
        rectTransform.localScale = Vector3.one;
        SetHighlight(false);
        SetVisible(true);
        SetInteractable(true);
        SetFaceUp(false);
    }

    private void RefreshImage()
    {
        if (cardImage == null) return;

        Sprite sprite = null;
        if (faceUp)
            sprite = data != null ? data.frontSprite : null;
        else
            sprite = data != null && data.customBackSprite != null ? data.customBackSprite : defaultBackSprite;

        cardImage.sprite = sprite;
        cardImage.color = sprite != null ? Color.white : (faceUp ? fallbackFrontColor : fallbackBackColor);
    }

    private void SetHighlight(bool value)
    {
        if (highlightImage != null)
            highlightImage.enabled = value;
    }
}
