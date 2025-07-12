using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Video;
using UnityEngine.SceneManagement;

public class SplashController : MonoBehaviour
{
    public VideoPlayer logoPlayer;
    public VideoPlayer cinePlayer;
    public GameObject skipButton;  // Tu bot�n Skip

    void Start()
    {
        // Suscribirse al final de cada video
        logoPlayer.loopPointReached += OnLogoFinished;
        cinePlayer.loopPointReached += OnCineFinished;

        // Empezar por el logo
        logoPlayer.Play();
    }

    void OnLogoFinished(VideoPlayer vp)
    {
        // Al terminar logo, ocultar logo y lanzar cinem�tica
        logoPlayer.gameObject.SetActive(false);
        skipButton.SetActive(true);
        cinePlayer.Play();
    }

    void OnCineFinished(VideoPlayer vp)
    {
        GoToMainMenu();
    }

    // Llamado desde el bot�n Skip
    public void SkipCine()
    {
        cinePlayer.Stop();
        GoToMainMenu();
    }

    void GoToMainMenu()
    {
        // Aseg�rate de que este sea el nombre de tu escena de men�
        SceneManager.LoadScene("MainMenu");
    }
}

