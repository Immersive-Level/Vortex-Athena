using UnityEngine;

[DisallowMultipleComponent]
public class FuelButtonRespawnFX : MonoBehaviour
{
    [Header("Hijo con la animación/imagen")]
    [SerializeField] private GameObject fxRoot;

    private void Awake()
    {
        if (fxRoot != null) fxRoot.SetActive(false);
    }

    /// Enciende el hijo y dispara la anim.
    public void Show()
    {
        if (fxRoot == null) return;
        if (!fxRoot.activeSelf) fxRoot.SetActive(true);
    }

    /// Llama este método desde el evento del último frame.
    public void FuelButtonRespawnFXHide()
    {
        if (fxRoot == null) return;
        fxRoot.SetActive(false);
        Debug.LogError("Hide ejecutado");
    }
}
