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

    public void ChangeScene(string sceneName)
    {
        if (string.IsNullOrWhiteSpace(sceneName))
        {
            Debug.LogWarning("[SceneManagerController] Scene name is empty.", this);
            return;
        }

        SceneManager.LoadScene(sceneName);
    }
}

