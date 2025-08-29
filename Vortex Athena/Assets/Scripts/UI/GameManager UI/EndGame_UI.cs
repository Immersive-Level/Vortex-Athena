using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class EndGame_UI : MonoBehaviour
{
    public Button RestartButton;
    public Button QuitButton;

    private void Start()
    {
        if (RestartButton != null)
        {
            RestartButton.onClick.AddListener(OnRestartPressed);
        }

        if (QuitButton != null)
        {
            QuitButton.onClick.AddListener(OnQuitPressed);
        }
    }

    public void OnRestartPressed()
    {
        var sceneIndex = SceneManager.GetActiveScene().buildIndex;
        SceneManager.LoadScene(sceneIndex);
    }

    public void OnQuitPressed()
    {
        SceneManager.LoadScene("Main Menu");
    }

}
