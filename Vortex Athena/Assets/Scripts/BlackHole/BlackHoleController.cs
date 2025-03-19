using UnityEngine;

public class BlackHoleController : MonoBehaviour
{
    public SpriteRenderer blackHoleRenderer;
    public float distortionStrength = 0.3f;
    public float distortionRadius = 0.5f;
    public float rotationSpeed = 2.0f;
    public float eventHorizonSharpness = 8.0f;
    public Color eventHorizonColor = new Color(0.1f, 0.4f, 1.0f, 1.0f);

    private Material blackHoleMaterial;

    void Start()
    {
        // Cargar el shader y aplicarlo al renderer
        Shader blackHoleShader = Shader.Find("Custom/BlackHoleDistortion");
        blackHoleMaterial = new Material(blackHoleShader);
        blackHoleRenderer.material = blackHoleMaterial;
    }

    void Update()
    {
        // Actualizar propiedades dinámicamente
        blackHoleMaterial.SetFloat("_DistortionStrength", distortionStrength);
        blackHoleMaterial.SetFloat("_DistortionRadius", distortionRadius);
        blackHoleMaterial.SetFloat("_RotationSpeed", rotationSpeed);
        blackHoleMaterial.SetFloat("_EventHorizonSharpness", eventHorizonSharpness);
        blackHoleMaterial.SetColor("_EventHorizonColor", eventHorizonColor);
    }
}