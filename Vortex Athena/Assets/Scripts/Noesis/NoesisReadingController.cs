using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.Serialization;
using UnityEngine.UI;

public class NoesisReadingController : MonoBehaviour
{
    [Header("Cards")]
    public List<NoesisCardData> availableCards = new List<NoesisCardData>();
    public RectTransform fanContainer;
    public NoesisCardView cardPrefab;
    public Sprite defaultBackSprite;

    [Header("Sections")]
    public GameObject pickerSection;
    public GameObject revealSection;
    public Image revealedCardImage;
    public TMP_Text revealedCardNumberText;
    public TMP_Text revealedCardNameText;
    public TMP_Text revealedCardMessageText;
    public GameObject headerRoot;

    [Header("Buttons")]
    public Button pickerBackButton;
    public Button revealBackButton;
    public Image pickerBackButtonImage;
    public Image revealBackButtonImage;
    [Tooltip("Legacy hidden button retained for scene compatibility.")]
    public Button consultAgainButton;
    [Tooltip("Legacy hidden button retained for scene compatibility.")]
    public Button backButton;

    [Header("Radial Fan Layout")]
    [Min(0f)] public float fanRadius = 240f;
    [FormerlySerializedAs("fanArcDegrees"), Range(0f, 350f)] public float totalAngle = 320f;
    [FormerlySerializedAs("fanScaleFactor"), Range(0.5f, 1.75f)] public float cardScale = 1.25f;
    [Min(0f), Tooltip("Zero distributes cards evenly across Total Angle.")]
    public float angleStep = 20f;
    public Vector2 fanCenterOffset = new Vector2(0f, -10f);
    public float cardHoverLift = 24f;
    [Min(1f)] public float cardHoverScale = 1.06f;

    [Header("Animation")]
    [FormerlySerializedAs("fanIntroDuration"), Min(0f)] public float openAnimationDuration = 0.72f;
    [Min(0f)] public float staggerDelay = 0.025f;
    public Vector2 stackedStartOffset = new Vector2(0f, -36f);
    public AnimationCurve openAnimationCurve = AnimationCurve.EaseInOut(0f, 0f, 1f, 1f);
    [Min(0f)] public float selectedCardMoveDuration = 0.38f;
    [Min(0f)] public float cardFlipDuration = 0.46f;
    [Min(0f)] public float flyAwayDuration = 0.55f;
    [Min(0f)] public float revealFadeDuration = 0.28f;
    public AnimationCurve movementCurve = AnimationCurve.EaseInOut(0f, 0f, 1f, 1f);
    public AnimationCurve flipCurve = AnimationCurve.EaseInOut(0f, 0f, 1f, 1f);

    [Header("Editable Visuals")]
    public Image backgroundImage;
    public Image[] decorativeOverlays;
    public TMP_Text titleText;
    public TMP_Text subtitleText;
    public TMP_Text instructionText;
    public Image consultAgainButtonImage;
    public Image backButtonImage;
    public Image backButtonIcon;

    [Header("Optional Audio")]
    public AudioSource audioSource;
    public AudioClip selectionSound;
    public AudioClip revealSound;
    public AudioClip resetSound;
    public AudioClip backSound;

    [Header("Optional Animators")]
    public Animator pickerAnimator;
    public Animator revealAnimator;

    [Header("Navigation")]
    public string menuSceneName = "MainMenu";

    private enum ReadingState
    {
        Initializing,
        Introducing,
        Ready,
        Selecting,
        Revealed,
        Resetting
    }

    private readonly List<NoesisCardView> activeViews = new List<NoesisCardView>();
    private readonly List<NoesisCardData> currentDeck = new List<NoesisCardData>();
    private NoesisFanLayout fanLayout;
    private CanvasGroup revealCanvasGroup;
    private ReadingState state = ReadingState.Initializing;
    private Vector2 lastFanSize;

    private bool IsTransitioning => state == ReadingState.Initializing
        || state == ReadingState.Introducing
        || state == ReadingState.Selecting
        || state == ReadingState.Resetting;

    private void Awake()
    {
        if (fanContainer != null)
            fanLayout = fanContainer.GetComponent<NoesisFanLayout>() ?? fanContainer.gameObject.AddComponent<NoesisFanLayout>();

        if (revealSection != null)
            revealCanvasGroup = revealSection.GetComponent<CanvasGroup>() ?? revealSection.AddComponent<CanvasGroup>();

        ValidateEssentialReferences();
    }

    private void OnEnable()
    {
        if (pickerBackButton != null)
            pickerBackButton.onClick.AddListener(BackToMenu);
        if (revealBackButton != null)
            revealBackButton.onClick.AddListener(ReturnToPicker);
    }

    private void Start()
    {
        StartCoroutine(BuildReadingSequence());
    }

    private void OnDisable()
    {
        if (pickerBackButton != null)
            pickerBackButton.onClick.RemoveListener(BackToMenu);
        if (revealBackButton != null)
            revealBackButton.onClick.RemoveListener(ReturnToPicker);
    }

    private void Update()
    {
        if (fanContainer == null || state != ReadingState.Ready) return;

        Vector2 size = fanContainer.rect.size;
        if ((size - lastFanSize).sqrMagnitude > 1f)
            ApplyFanLayout();
    }

    public void StartReading()
    {
        if (IsTransitioning)
        {
            Debug.LogWarning("[NoesisReadingController] A reading transition is already in progress.", this);
            return;
        }

        state = ReadingState.Resetting;
        StartCoroutine(RestartSequence(false));
    }

    public void ResetReading()
    {
        if (IsTransitioning)
        {
            Debug.LogWarning("[NoesisReadingController] CONSULTAR DE NUEVO ignored while an animation is running.", this);
            return;
        }

        state = ReadingState.Resetting;
        SetNavigationInteractable(false);
        PlaySound(resetSound);
        StartCoroutine(RestartSequence(true));
    }

    public void BackToMenu()
    {
        if (IsTransitioning)
        {
            Debug.LogWarning("[NoesisReadingController] VOLVER ignored while an animation is running.", this);
            return;
        }

        if (string.IsNullOrWhiteSpace(menuSceneName))
        {
            Debug.LogWarning("[NoesisReadingController] Menu scene name is empty.", this);
            return;
        }

        state = ReadingState.Resetting;
        SetNavigationInteractable(false);
        PlaySound(backSound);
        SceneManager.LoadScene(menuSceneName);
    }

    public void ReturnToPicker()
    {
        if (state != ReadingState.Revealed)
        {
            Debug.LogWarning("[NoesisReadingController] Reveal back ignored outside the revealed state.", this);
            return;
        }

        state = ReadingState.Resetting;
        SetNavigationInteractable(false);
        PlaySound(backSound);
        StartCoroutine(RestartSequence(true));
    }

    private IEnumerator RestartSequence(bool fadeCurrentReveal)
    {
        if (fadeCurrentReveal && revealSection != null && revealSection.activeSelf)
            yield return FadeCanvasGroup(revealCanvasGroup, 1f, 0f, revealFadeDuration);

        yield return BuildReadingSequence();
    }

    private IEnumerator BuildReadingSequence()
    {
        state = ReadingState.Initializing;
        SetNavigationInteractable(false);
        ClearCards();
        yield return null;
        BuildDeck();

        if (pickerSection != null)
            pickerSection.SetActive(true);
        if (revealSection != null)
            revealSection.SetActive(false);
        if (headerRoot != null)
            headerRoot.SetActive(true);
        if (pickerBackButton != null)
            pickerBackButton.gameObject.SetActive(true);
        if (revealBackButton != null)
            revealBackButton.gameObject.SetActive(false);

        if (currentDeck.Count == 0)
        {
            Debug.LogWarning("[NoesisReadingController] No available cards assigned.", this);
            state = ReadingState.Ready;
            SetNavigationInteractable(true);
            yield break;
        }

        if (fanContainer == null || cardPrefab == null)
        {
            Debug.LogWarning("[NoesisReadingController] Fan container or card prefab is missing.", this);
            state = ReadingState.Ready;
            SetNavigationInteractable(true);
            yield break;
        }

        foreach (NoesisCardData card in currentDeck)
        {
            NoesisCardView view = Instantiate(cardPrefab, fanContainer);
            view.gameObject.SetActive(true);
            view.Initialize(card, defaultBackSprite, HandleCardSelected, cardHoverLift, cardHoverScale, movementCurve, flipCurve);
            activeViews.Add(view);
        }

        Canvas.ForceUpdateCanvases();
        ApplyFanLayout();
        state = ReadingState.Introducing;
        TrySetTrigger(pickerAnimator, "Show");

        for (int i = 0; i < activeViews.Count; i++)
        {
            StartCoroutine(activeViews[i].PlayFanOpen(
                i * staggerDelay,
                openAnimationDuration,
                fanLayout.LastStackPosition,
                stackedStartOffset,
                openAnimationCurve));
        }

        bool introStillRunning;
        do
        {
            introStillRunning = false;
            foreach (NoesisCardView view in activeViews)
            {
                if (view != null && view.IsTransitioning)
                {
                    introStillRunning = true;
                    break;
                }
            }
            if (introStillRunning)
                yield return null;
        }
        while (introStillRunning);

        foreach (NoesisCardView view in activeViews)
        {
            if (view != null)
                view.SetInteractable(true);
        }

        state = ReadingState.Ready;
        SetNavigationInteractable(true);
    }

    private void HandleCardSelected(NoesisCardView selectedView)
    {
        if (state != ReadingState.Ready || selectedView == null) return;

        state = ReadingState.Selecting;
        SetNavigationInteractable(false);
        foreach (NoesisCardView view in activeViews)
        {
            if (view != null)
                view.SetInteractable(false);
        }

        PlaySound(selectionSound);
        StartCoroutine(SelectionSequence(selectedView));
    }

    private IEnumerator SelectionSequence(NoesisCardView selectedView)
    {
        Rect fanRect = fanContainer.rect;
        Vector2 fanCenter = new Vector2(fanRect.width * 0.5f, fanRect.height * 0.52f);
        float travelX = Mathf.Max(fanRect.width, Screen.width) * 0.85f;
        float travelY = -Mathf.Max(fanRect.height, Screen.height) * 0.7f;

        for (int i = 0; i < activeViews.Count; i++)
        {
            NoesisCardView view = activeViews[i];
            if (view == null || view == selectedView) continue;

            float direction = view.RectTransform.anchoredPosition.x < fanCenter.x ? -1f : 1f;
            if (Mathf.Abs(view.RectTransform.anchoredPosition.x - fanCenter.x) < 1f)
                direction = i % 2 == 0 ? -1f : 1f;

            Vector2 offset = new Vector2(direction * travelX, travelY);
            StartCoroutine(view.FlyAway(flyAwayDuration, offset, direction * 24f, 0.72f));
        }

        yield return selectedView.MoveSelected(fanCenter, selectedCardMoveDuration, 1.08f);
        yield return selectedView.FlipToFront(cardFlipDuration);
        PlaySound(selectedView.Data != null && selectedView.Data.revealSound != null
            ? selectedView.Data.revealSound
            : revealSound);

        float remainingExitTime = flyAwayDuration - selectedCardMoveDuration - cardFlipDuration;
        if (remainingExitTime > 0f)
            yield return WaitRealtime(remainingExitTime);

        ShowRevealData(selectedView.Data);
        TrySetTrigger(pickerAnimator, "Hide");
        TrySetTrigger(revealAnimator, "Show");

        if (revealSection != null)
        {
            revealSection.SetActive(true);
            if (revealCanvasGroup != null)
                revealCanvasGroup.alpha = 0f;
        }
        if (pickerSection != null)
            pickerSection.SetActive(false);
        if (headerRoot != null)
            headerRoot.SetActive(false);
        if (pickerBackButton != null)
            pickerBackButton.gameObject.SetActive(false);
        if (revealBackButton != null)
            revealBackButton.gameObject.SetActive(true);

        yield return FadeCanvasGroup(revealCanvasGroup, 0f, 1f, revealFadeDuration);
        state = ReadingState.Revealed;
        SetNavigationInteractable(true);
    }

    private void ShowRevealData(NoesisCardData card)
    {
        if (revealedCardImage != null)
        {
            Sprite sprite = card != null ? card.frontSprite : null;
            revealedCardImage.sprite = sprite;
            revealedCardImage.color = sprite != null ? Color.white : new Color(0.77f, 0.64f, 0.29f, 1f);
            revealedCardImage.preserveAspect = true;
        }

        if (revealedCardNumberText != null)
        {
            revealedCardNumberText.text = string.Empty;
            revealedCardNumberText.gameObject.SetActive(false);
        }
        if (revealedCardNameText != null)
        {
            revealedCardNameText.text = string.Empty;
            revealedCardNameText.gameObject.SetActive(false);
        }
        if (revealedCardMessageText != null)
        {
            revealedCardMessageText.text = string.Empty;
            revealedCardMessageText.gameObject.SetActive(false);
        }
    }

    private void BuildDeck()
    {
        currentDeck.Clear();
        foreach (NoesisCardData card in availableCards)
        {
            if (card != null)
                currentDeck.Add(card);
        }

        for (int i = currentDeck.Count - 1; i > 0; i--)
        {
            int j = Random.Range(0, i + 1);
            NoesisCardData temp = currentDeck[i];
            currentDeck[i] = currentDeck[j];
            currentDeck[j] = temp;
        }
    }

    private void ApplyFanLayout()
    {
        if (fanLayout == null || fanContainer == null) return;
        lastFanSize = fanContainer.rect.size;
        fanLayout.ApplyLayout(activeViews, fanRadius, totalAngle, cardScale, angleStep, fanCenterOffset);
    }

    private void ClearCards()
    {
        foreach (NoesisCardView view in activeViews)
        {
            if (view != null)
                Destroy(view.gameObject);
        }
        activeViews.Clear();
    }

    private IEnumerator FadeCanvasGroup(CanvasGroup group, float from, float to, float duration)
    {
        if (group == null) yield break;
        group.alpha = from;

        float elapsed = 0f;
        while (elapsed < duration)
        {
            elapsed += Time.unscaledDeltaTime;
            float t = Evaluate(movementCurve, elapsed / Mathf.Max(duration, 0.0001f));
            group.alpha = Mathf.LerpUnclamped(from, to, t);
            yield return null;
        }
        group.alpha = to;
    }

    private void SetNavigationInteractable(bool value)
    {
        if (pickerBackButton != null)
            pickerBackButton.interactable = value && state == ReadingState.Ready;
        if (revealBackButton != null)
            revealBackButton.interactable = value && state == ReadingState.Revealed;
        if (consultAgainButton != null)
            consultAgainButton.interactable = false;
        if (backButton != null)
            backButton.interactable = false;
    }

    private void PlaySound(AudioClip clip)
    {
        if (audioSource != null && clip != null)
            audioSource.PlayOneShot(clip);
    }

    private static void TrySetTrigger(Animator animator, string triggerName)
    {
        if (animator == null || animator.runtimeAnimatorController == null) return;
        foreach (AnimatorControllerParameter parameter in animator.parameters)
        {
            if (parameter.type == AnimatorControllerParameterType.Trigger && parameter.name == triggerName)
            {
                animator.SetTrigger(triggerName);
                return;
            }
        }
    }

    private void ValidateEssentialReferences()
    {
        if (fanContainer == null) Debug.LogWarning("[NoesisReadingController] fanContainer is not assigned.", this);
        if (cardPrefab == null) Debug.LogWarning("[NoesisReadingController] cardPrefab is not assigned.", this);
        if (defaultBackSprite == null) Debug.LogWarning("[NoesisReadingController] defaultBackSprite is not assigned.", this);
        if (pickerSection == null) Debug.LogWarning("[NoesisReadingController] pickerSection is not assigned.", this);
        if (revealSection == null) Debug.LogWarning("[NoesisReadingController] revealSection is not assigned.", this);
        if (revealedCardImage == null) Debug.LogWarning("[NoesisReadingController] revealedCardImage is not assigned.", this);
        if (headerRoot == null) Debug.LogWarning("[NoesisReadingController] headerRoot is not assigned.", this);
        if (pickerBackButton == null) Debug.LogWarning("[NoesisReadingController] pickerBackButton is not assigned.", this);
        if (revealBackButton == null) Debug.LogWarning("[NoesisReadingController] revealBackButton is not assigned.", this);
        if (availableCards == null || availableCards.Count < 17)
            Debug.LogWarning($"[NoesisReadingController] Expected 17 cards, but {availableCards?.Count ?? 0} are assigned.", this);

        if (availableCards == null) return;
        HashSet<string> seenCardIds = new HashSet<string>();
        for (int i = 0; i < availableCards.Count; i++)
        {
            NoesisCardData card = availableCards[i];
            if (card == null)
            {
                Debug.LogWarning($"[NoesisReadingController] Card slot {i} is empty.", this);
                continue;
            }
            if (card.frontSprite == null)
                Debug.LogWarning($"[NoesisReadingController] Card {card.cardNumber} ({card.displayName}) has no front sprite.", card);
            if (string.IsNullOrWhiteSpace(card.cardId) || string.IsNullOrWhiteSpace(card.cardNumber) || string.IsNullOrWhiteSpace(card.displayName))
                Debug.LogWarning($"[NoesisReadingController] Card slot {i} has an empty id, number, or display name.", card);
            if (string.IsNullOrWhiteSpace(card.noesisMessage))
                Debug.LogWarning($"[NoesisReadingController] Card {card.cardNumber} has no Noesis message.", card);
            if (!string.IsNullOrWhiteSpace(card.cardId) && !seenCardIds.Add(card.cardId))
                Debug.LogWarning($"[NoesisReadingController] Duplicate card id '{card.cardId}'.", card);
        }
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
