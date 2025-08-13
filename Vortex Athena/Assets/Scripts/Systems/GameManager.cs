using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public static GameManager Instance { get; private set; }

    //sistemas hijos del GameManager
    public ScoreSystem ScoreSystem;
    public List<GameObject> NavesActivas { get; private set; }

    public GameObject TutorialRoot;


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
    }

    public void Start()
    {
        NavesActivas = new List<GameObject>();

        ToggleTutorial();
    }

    public void RegisterShip(GameObject inShip)
    {
        NavesActivas.Add(inShip);
    }

    public void RemoveRegisterShip(GameObject inShip)
    {
        NavesActivas.Remove(inShip);
    }

    public void ToggleTutorial()
    {
        if (Time.timeScale != 0)
            Time.timeScale = 0;
        else
            Time.timeScale = 1;

        if (!TutorialRoot.activeInHierarchy)
            TutorialRoot.SetActive(true);
        else
            TutorialRoot.SetActive(false);
    }
}
