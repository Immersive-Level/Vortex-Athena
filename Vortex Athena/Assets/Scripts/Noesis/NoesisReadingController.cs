using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
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

    [Header("Buttons")]
    public Button consultAgainButton;
    public Button backButton;

    [Header("Layout")]
    public float flyAwayDuration = 0.55f;
    public float revealDelay = 0.7f;
    public float fanArcDegrees = 68f;
    public float radiusFactor = 2.6f;
    public float horizontalFactor = 0.55f;

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
    public AudioClip resetSound;
    public AudioClip backSound;

    [Header("Optional Animators")]
    public Animator pickerAnimator;
    public Animator revealAnimator;

    [Header("Navigation")]
    public string menuSceneName = "MainMenu";

    private readonly List<NoesisCardView> activeViews = new List<NoesisCardView>();
    private readonly List<NoesisCardData> currentDeck = new List<NoesisCardData>();
    private NoesisFanLayout fanLayout;
    private bool isSelecting;
    private bool hasRevealed;
    private Vector2 lastFanSize;

    private void Awake()
    {
        if (fanContainer != null)
            fanLayout = fanContainer.GetComponent<NoesisFanLayout>() ?? fanContainer.gameObject.AddComponent<NoesisFanLayout>();

        ValidateEssentialReferences();
    }

    private void OnEnable()
    {
        if (consultAgainButton != null)
            consultAgainButton.onClick.AddListener(ResetReading);
        if (backButton != null)
            backButton.onClick.AddListener(BackToMenu);
    }

    private void Start()
    {
        StartReading();
    }

    private void OnDisable()
    {
        if (consultAgainButton != null)
            consultAgainButton.onClick.RemoveListener(ResetReading);
        if (backButton != null)
            backButton.onClick.RemoveListener(BackToMenu);
    }

    private void Update()
    {
        if (fanContainer == null || hasRevealed || isSelecting) return;

        Vector2 size = fanContainer.rect.size;
        if ((size - lastFanSize).sqrMagnitude > 1f)
        {
            lastFanSize = size;
            ApplyFanLayout();
        }
    }

    public void StartReading()
    {
        StopAllCoroutines();
        isSelecting = false;
        hasRevealed = false;
        ClearCards();
        BuildDeck();

        if (pickerSection != null)
            pickerSection.SetActive(true);
        if (revealSection != null)
            revealSection.SetActive(false);

        if (currentDeck.Count == 0)
        {
            Debug.LogWarning("[NoesisReadingController] No available cards assigned.", this);
            return;
        }

        if (fanContainer == null || cardPrefab == null)
        {
            Debug.LogWarning("[NoesisReadingController] Fan container or card prefab is missing.", this);
            return;
        }

        foreach (NoesisCardData card in currentDeck)
        {
            NoesisCardView view = Instantiate(cardPrefab, fanContainer);
            view.gameObject.SetActive(true);
            view.Initialize(card, defaultBackSprite, HandleCardSelected);
            activeViews.Add(view);
        }

        Canvas.ForceUpdateCanvases();
        ApplyFanLayout();
    }

    public void ResetReading()
    {
        if (audioSource != null && resetSound != null)
            audioSource.PlayOneShot(resetSound);
        StartReading();
    }

    public void BackToMenu()
    {
        if (audioSource != null && backSound != null)
            audioSource.PlayOneShot(backSound);

        if (string.IsNullOrWhiteSpace(menuSceneName))
        {
            Debug.LogWarning("[NoesisReadingController] Menu scene name is empty.", this);
            return;
        }

        SceneManager.LoadScene(menuSceneName);
    }

    private void HandleCardSelected(NoesisCardView selectedView)
    {
        if (isSelecting || hasRevealed || selectedView == null) return;

        isSelecting = true;
        foreach (NoesisCardView view in activeViews)
        {
            if (view != null)
                view.SetInteractable(false);
        }

        if (selectedView.Data != null && audioSource != null && selectedView.Data.revealSound != null)
            audioSource.PlayOneShot(selectedView.Data.revealSound);

        StartCoroutine(SelectionSequence(selectedView));
    }

    private IEnumerator SelectionSequence(NoesisCardView selectedView)
    {
        float verticalDistance = -(fanContainer != null ? Mathf.Max(fanContainer.rect.height, Screen.height) : Screen.height);

        foreach (NoesisCardView view in activeViews)
        {
            if (view == null || view == selectedView) continue;
            StartCoroutine(view.FlyAway(flyAwayDuration, verticalDistance, 20f, 0.3f));
        }

        StartCoroutine(selectedView.PulseSelected(Mathf.Min(0.25f, revealDelay), 1.08f));
        yield return new WaitForSecondsRealtime(Mathf.Max(revealDelay, flyAwayDuration));
        ShowReveal(selectedView.Data);
    }

    private void ShowReveal(NoesisCardData card)
    {
        hasRevealed = true;
        isSelecting = false;

        if (pickerAnimator != null)
            pickerAnimator.SetTrigger("Hide");
        if (revealAnimator != null)
            revealAnimator.SetTrigger("Show");

        if (pickerSection != null)
            pickerSection.SetActive(false);
        if (revealSection != null)
            revealSection.SetActive(true);

        if (revealedCardImage != null)
        {
            Sprite sprite = card != null ? card.frontSprite : null;
            revealedCardImage.sprite = sprite;
            revealedCardImage.color = sprite != null ? Color.white : new Color(0.77f, 0.64f, 0.29f, 1f);
        }

        if (revealedCardNumberText != null)
            revealedCardNumberText.text = card != null ? "CARTA " + card.cardNumber : "CARTA";
        if (revealedCardNameText != null)
            revealedCardNameText.text = card != null ? card.displayName : "Sin carta";
        if (revealedCardMessageText != null)
            revealedCardMessageText.text = card != null ? card.noesisMessage : string.Empty;
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
        if (fanLayout == null) return;
        lastFanSize = fanContainer.rect.size;
        fanLayout.ApplyLayout(activeViews, fanArcDegrees, radiusFactor, horizontalFactor);
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

    private void ValidateEssentialReferences()
    {
        if (fanContainer == null)
            Debug.LogWarning("[NoesisReadingController] fanContainer is not assigned.", this);
        if (cardPrefab == null)
            Debug.LogWarning("[NoesisReadingController] cardPrefab is not assigned.", this);
        if (pickerSection == null)
            Debug.LogWarning("[NoesisReadingController] pickerSection is not assigned.", this);
        if (revealSection == null)
            Debug.LogWarning("[NoesisReadingController] revealSection is not assigned.", this);
        if (consultAgainButton == null)
            Debug.LogWarning("[NoesisReadingController] consultAgainButton is not assigned.", this);
        if (backButton == null)
            Debug.LogWarning("[NoesisReadingController] backButton is not assigned.", this);
    }
}
