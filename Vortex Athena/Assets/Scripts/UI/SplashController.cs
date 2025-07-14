using UnityEngine;
using UnityEngine.Video;
using UnityEngine.SceneManagement;

public class SplashController : MonoBehaviour
{
    public VideoPlayer logoPlayer;
    public VideoPlayer cinePlayer;
    public GameObject skipButton;

    void Start()
    {
        // Asegurarnos de que no salte frames por rendimiento
        logoPlayer.skipOnDrop = false;
        cinePlayer.skipOnDrop = false;

        // Preparamos ambos clips
        logoPlayer.Prepare();
        cinePlayer.Prepare();

        // Cuando el logo est� listo, forzamos tiempo 0 y lo reproducimos
        logoPlayer.prepareCompleted += vp =>
        {
            vp.time = 0;          // aseg�rate de apuntar al segundo 0
            vp.Play();
        };

        // Al llegar al final, pasamos al v�deo de cinem�tica
        logoPlayer.loopPointReached += OnLogoFinished;
        cinePlayer.loopPointReached += OnCineFinished;
    }

    void OnLogoFinished(VideoPlayer vp)
    {
        logoPlayer.gameObject.SetActive(false);
        skipButton.SetActive(true);
        // Igual aqu� nos aseguramos de partir desde 0
        cinePlayer.time = 0;
        cinePlayer.Play();
    }

    public void SkipCine()
    {
        cinePlayer.Stop();
        LoadMainMenu();
    }

    void OnCineFinished(VideoPlayer vp)
    {
        LoadMainMenu();
    }

    void LoadMainMenu()
    {
        SceneManager.LoadScene("MainMenu");
    }
}
