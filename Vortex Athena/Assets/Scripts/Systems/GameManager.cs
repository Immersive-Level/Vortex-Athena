using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public static GameManager Instance { get; private set; }

    //sistemas hijos del GameManager
    public ScoreSystem ScoreSystem;
    public List<GameObject> NavesActivas { get; private set; }


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
    }

    public void RegisterShip(GameObject inShip)
    {
        NavesActivas.Add(inShip);
    }

    public void RemoveRegisterShip(GameObject inShip)
    {
        NavesActivas.Remove(inShip);
    }

}
