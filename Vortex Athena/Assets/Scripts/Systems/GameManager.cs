using UnityEngine;

public class GameManager : MonoBehaviour
{
    public static GameManager Instance { get; private set; }

    //sistemas hijos del GameManager
    public ScoreSystem ScoreSystem;

    //Objetos tutorial
    public GameObject _tutorialRoot;     //tutorialRoot debe estar desactivado al inicio

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
        }
        else
        {
            Instance = this;
        }

        Debug.Log("Toggling tutorial");
        ToggleTutorial();
    }

    public void Start()
    {
        
    }

    //Logica que inica flujo de Tutorial
    public void ToggleTutorial()
    {
        if (Time.timeScale != 0f)
            Time.timeScale = 0f;
        else
            Time.timeScale = 1f;
        Debug.Log("Current time scale is: " + Time.timeScale);

        if (!_tutorialRoot.activeInHierarchy)
            _tutorialRoot.SetActive(true);
        else
            _tutorialRoot.SetActive(false);
    }

}
