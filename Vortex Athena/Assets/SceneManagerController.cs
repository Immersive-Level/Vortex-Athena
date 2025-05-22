using UnityEngine;
using UnityEngine.SceneManagement;
using System.Collections;

public class SceneManagerController : MonoBehaviour
{
    public string targetScene;

    public void ChangeScene()
    {
        SceneManager.LoadScene(targetScene);
    }
}

