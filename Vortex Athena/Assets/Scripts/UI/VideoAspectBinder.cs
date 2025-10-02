using UnityEngine;
using UnityEngine.UI;
using UnityEngine.Video;

[RequireComponent(typeof(AspectRatioFitter))]
public class VideoAspectBinder : MonoBehaviour
{
    [Header("Referencias")]
    public VideoPlayer videoPlayer;   // Asigna aquí tu VideoPlayer
    private AspectRatioFitter fitter;

    void Awake()
    {
        fitter = GetComponent<AspectRatioFitter>();
    }

    void OnEnable()
    {
        if (videoPlayer != null)
        {
            // Cuando el video ya está listo, obtenemos su tamaño real
            videoPlayer.prepareCompleted += OnVideoPrepared;
            if (videoPlayer.isPrepared)
                OnVideoPrepared(videoPlayer);
        }
    }

    void OnDisable()
    {
        if (videoPlayer != null)
            videoPlayer.prepareCompleted -= OnVideoPrepared;
    }

    private void OnVideoPrepared(VideoPlayer vp)
    {
        if (vp.width > 0 && vp.height > 0)
        {
            float aspect = (float)vp.width / vp.height;
            fitter.aspectRatio = aspect;
        }
    }
}
