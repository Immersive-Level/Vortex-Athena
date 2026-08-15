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
    private Action<NoesisCardView> selectedCallback;
    private Coroutine hoverRoutine;
    private Vector2 baseAnchoredPosition;
    private Quaternion baseRotation;
    private float hoverLift;
    private float hoverScale = 1.05f;
    private AnimationCurve movementCurve;
    private AnimationCurve flipCurve;
    private bool interactable;
    private bool faceUp;
    private bool transitionLocked;

    public NoesisCardData Data => data;
    public RectTransform RectTransform => rectTransform;
    public bool IsTransitioning => transitionLocked;

    private void Awake()
    {
        rectTransform = GetComponent<RectTransform>();
        if (cardImage == null)
            cardImage = GetComponent<Image>();
        if (canvasGroup == null)
            canvasGroup = GetComponent<CanvasGroup>() ?? gameObject.AddComponent<CanvasGroup>();
    }

    public void Initialize(
        NoesisCardData cardData,
        Sprite sharedBackSprite,
        Action<NoesisCardView> onSelected,
        float cardHoverLift,
        float cardHoverScale,
        AnimationCurve cardMovementCurve,
        AnimationCurve cardFlipCurve)
    {
        data = cardData;
        defaultBackSprite = sharedBackSprite;
        selectedCallback = onSelected;
        hoverLift = Mathf.Max(0f, cardHoverLift);
        hoverScale = Mathf.Max(1f, cardHoverScale);
        movementCurve = cardMovementCurve;
        flipCurve = cardFlipCurve;
        faceUp = false;
        transitionLocked = false;
        SetInteractable(false);
        SetVisible(true);
        SetHighlight(false);
        RefreshImage();
    }

    public void SetLayoutPose(Vector2 position, Quaternion rotation, Vector2 size, int siblingIndex)
    {
        if (rectTransform == null)
            rectTransform = GetComponent<RectTransform>();

        rectTransform.anchorMin = Vector2.zero;
        rectTransform.anchorMax = Vector2.zero;
        rectTransform.pivot = new Vector2(0.5f, 0.5f);
        rectTransform.sizeDelta = size;
        rectTransform.anchoredPosition = position;
        rectTransform.localRotation = rotation;
        rectTransform.localScale = Vector3.one;
        rectTransform.SetSiblingIndex(siblingIndex);
        baseAnchoredPosition = position;
        baseRotation = rotation;
    }

    public void SetInteractable(bool value)
    {
        interactable = value && !transitionLocked;
        if (canvasGroup != null)
        {
            canvasGroup.blocksRaycasts = interactable;
            canvasGroup.interactable = interactable;
        }
    }

    public void SetVisible(bool value)
    {
        if (canvasGroup == null) return;
        canvasGroup.alpha = value ? 1f : 0f;
        canvasGroup.blocksRaycasts = value && interactable;
    }

    public IEnumerator PlayIntro(float delay, float duration)
    {
        transitionLocked = true;
        SetInteractable(false);
        Vector2 endPosition = baseAnchoredPosition;
        Vector2 startPosition = endPosition - Vector2.up * Mathf.Min(rectTransform.rect.height * 0.2f, 55f);
        Quaternion endRotation = baseRotation;
        float signedEndAngle = Mathf.DeltaAngle(0f, endRotation.eulerAngles.z);
        Quaternion startRotation = Quaternion.Euler(0f, 0f, signedEndAngle * 0.65f);
        Vector3 startScale = Vector3.one * 0.86f;

        rectTransform.anchoredPosition = startPosition;
        rectTransform.localRotation = startRotation;
        rectTransform.localScale = startScale;
        if (canvasGroup != null) canvasGroup.alpha = 0f;

        yield return WaitRealtime(delay);

        float elapsed = 0f;
        while (elapsed < duration)
        {
            elapsed += Time.unscaledDeltaTime;
            float t = Evaluate(movementCurve, elapsed / Mathf.Max(duration, 0.0001f));
            rectTransform.anchoredPosition = Vector2.LerpUnclamped(startPosition, endPosition, t);
            rectTransform.localRotation = Quaternion.SlerpUnclamped(startRotation, endRotation, t);
            rectTransform.localScale = Vector3.LerpUnclamped(startScale, Vector3.one, t);
            if (canvasGroup != null) canvasGroup.alpha = Mathf.Clamp01(t);
            yield return null;
        }

        rectTransform.anchoredPosition = endPosition;
        rectTransform.localRotation = endRotation;
        rectTransform.localScale = Vector3.one;
        if (canvasGroup != null) canvasGroup.alpha = 1f;
        transitionLocked = false;
    }

    public IEnumerator FlyAway(float duration, Vector2 offset, float rotationOffset, float targetScale)
    {
        BeginTransition();
        Vector2 startPosition = rectTransform.anchoredPosition;
        Quaternion startRotation = rectTransform.localRotation;
        Vector3 startScale = rectTransform.localScale;
        Vector2 endPosition = startPosition + offset;
        Quaternion endRotation = Quaternion.Euler(0f, 0f, startRotation.eulerAngles.z + rotationOffset);
        Vector3 endScale = Vector3.one * targetScale;
        float startAlpha = canvasGroup != null ? canvasGroup.alpha : 1f;

        float elapsed = 0f;
        while (elapsed < duration)
        {
            elapsed += Time.unscaledDeltaTime;
            float t = Evaluate(movementCurve, elapsed / Mathf.Max(duration, 0.0001f));
            rectTransform.anchoredPosition = Vector2.LerpUnclamped(startPosition, endPosition, t);
            rectTransform.localRotation = Quaternion.SlerpUnclamped(startRotation, endRotation, t);
            rectTransform.localScale = Vector3.LerpUnclamped(startScale, endScale, t);
            if (canvasGroup != null) canvasGroup.alpha = Mathf.Lerp(startAlpha, 0f, Mathf.Clamp01(t));
            yield return null;
        }

        rectTransform.anchoredPosition = endPosition;
        rectTransform.localRotation = endRotation;
        rectTransform.localScale = endScale;
        if (canvasGroup != null) canvasGroup.alpha = 0f;
    }

    public IEnumerator MoveSelected(Vector2 targetPosition, float duration, float targetScale)
    {
        BeginTransition();
        SetHighlight(true);
        transform.SetAsLastSibling();

        Vector2 startPosition = rectTransform.anchoredPosition;
        Quaternion startRotation = rectTransform.localRotation;
        Vector3 startScale = rectTransform.localScale;
        Vector3 endScale = Vector3.one * targetScale;
        float elapsed = 0f;

        while (elapsed < duration)
        {
            elapsed += Time.unscaledDeltaTime;
            float t = Evaluate(movementCurve, elapsed / Mathf.Max(duration, 0.0001f));
            rectTransform.anchoredPosition = Vector2.LerpUnclamped(startPosition, targetPosition, t);
            rectTransform.localRotation = Quaternion.SlerpUnclamped(startRotation, Quaternion.identity, t);
            rectTransform.localScale = Vector3.LerpUnclamped(startScale, endScale, t);
            yield return null;
        }

        rectTransform.anchoredPosition = targetPosition;
        rectTransform.localRotation = Quaternion.identity;
        rectTransform.localScale = endScale;
    }

    public IEnumerator FlipToFront(float duration)
    {
        BeginTransition();
        Vector3 stableScale = rectTransform.localScale;
        float halfDuration = Mathf.Max(duration * 0.5f, 0.0001f);

        yield return ScaleFlipHalf(stableScale, 1f, 0f, halfDuration);
        SetFaceUp(true);
        yield return ScaleFlipHalf(stableScale, 0f, 1f, halfDuration);

        rectTransform.localScale = stableScale;
        if (optionalAnimator != null)
        {
            optionalAnimator.SetBool("FaceUp", true);
            optionalAnimator.SetTrigger("Reveal");
        }
    }

    public void OnPointerClick(PointerEventData eventData)
    {
        if (!interactable || transitionLocked) return;
        selectedCallback?.Invoke(this);
    }

    public void OnPointerEnter(PointerEventData eventData)
    {
        if (!interactable || transitionLocked) return;
        SetHighlight(true);
        StartHover(true);
    }

    public void OnPointerExit(PointerEventData eventData)
    {
        if (transitionLocked) return;
        SetHighlight(false);
        StartHover(false);
    }

    private IEnumerator AnimateHover(bool raised)
    {
        Vector2 startPosition = rectTransform.anchoredPosition;
        Vector3 startScale = rectTransform.localScale;
        Vector2 liftDirection = baseRotation * Vector3.up;
        Vector2 endPosition = baseAnchoredPosition + (raised ? liftDirection * hoverLift : Vector2.zero);
        Vector3 endScale = Vector3.one * (raised ? hoverScale : 1f);
        const float duration = 0.14f;
        float elapsed = 0f;

        while (elapsed < duration)
        {
            elapsed += Time.unscaledDeltaTime;
            float t = Evaluate(movementCurve, elapsed / duration);
            rectTransform.anchoredPosition = Vector2.LerpUnclamped(startPosition, endPosition, t);
            rectTransform.localScale = Vector3.LerpUnclamped(startScale, endScale, t);
            yield return null;
        }

        rectTransform.anchoredPosition = endPosition;
        rectTransform.localScale = endScale;
    }

    private IEnumerator ScaleFlipHalf(Vector3 stableScale, float from, float to, float duration)
    {
        float elapsed = 0f;
        while (elapsed < duration)
        {
            elapsed += Time.unscaledDeltaTime;
            float t = Evaluate(flipCurve, elapsed / duration);
            float xFactor = Mathf.LerpUnclamped(from, to, t);
            rectTransform.localScale = new Vector3(stableScale.x * xFactor, stableScale.y, stableScale.z);
            yield return null;
        }
    }

    private void BeginTransition()
    {
        transitionLocked = true;
        interactable = false;
        if (hoverRoutine != null)
        {
            StopCoroutine(hoverRoutine);
            hoverRoutine = null;
        }
        SetHighlight(false);
        if (canvasGroup != null)
        {
            canvasGroup.blocksRaycasts = false;
            canvasGroup.interactable = false;
        }
    }

    private void StartHover(bool raised)
    {
        if (hoverRoutine != null)
            StopCoroutine(hoverRoutine);
        hoverRoutine = StartCoroutine(AnimateHover(raised));
    }

    private void SetFaceUp(bool value)
    {
        faceUp = value;
        RefreshImage();
    }

    private void RefreshImage()
    {
        if (cardImage == null) return;

        Sprite sprite = faceUp
            ? data != null ? data.frontSprite : null
            : data != null && data.customBackSprite != null ? data.customBackSprite : defaultBackSprite;

        cardImage.sprite = sprite;
        cardImage.color = sprite != null ? Color.white : (faceUp ? fallbackFrontColor : fallbackBackColor);
        cardImage.preserveAspect = true;
    }

    private void SetHighlight(bool value)
    {
        if (highlightImage != null)
            highlightImage.enabled = value;
    }

    private static float Evaluate(AnimationCurve curve, float t)
    {
        t = Mathf.Clamp01(t);
        return curve != null && curve.length > 0 ? curve.Evaluate(t) : t * t * (3f - 2f * t);
    }

    private static IEnumerator WaitRealtime(float duration)
    {
        float elapsed = 0f;
        while (elapsed < duration)
        {
            elapsed += Time.unscaledDeltaTime;
            yield return null;
        }
    }
}
