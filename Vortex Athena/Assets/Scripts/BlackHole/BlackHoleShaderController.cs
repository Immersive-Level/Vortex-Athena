using Unity.Entities;
using UnityEngine;

public class BlackHoleShaderController : MonoBehaviour
{
    private Material material;

    [Header("Distortion Settings")]
    [Range(0, 1)]
    public float distortionStrength = 0.3f;
    [Range(0, 1)]
    public float distortionRadius = 0.5f;
    [Range(0, 10)]
    public float rotationSpeed = 2.0f;

    [Header("Event Horizon Settings")]
    [Range(1, 20)]
    public float eventHorizonSharpness = 8.0f;
    public Color eventHorizonColor = new Color(0.1f, 0.4f, 1.0f, 1.0f);

    [Header("Dynamic Effects")]
    public bool pulsateEffect = true;
    [Range(0, 1)]
    public float pulsateStrength = 0.1f;
    [Range(0, 5)]
    public float pulsateSpeed = 1.0f;

    public bool reactToGravity = true;

    // Referencia al componente BlackHole para sincronizar con la física
    private Entity blackHoleEntity;
    private EntityManager entityManager;

    void Start()
    {
        material = GetComponent<SpriteRenderer>().material;

        // Inicializar los parámetros
        UpdateShaderParameters();
    }

    void Update()
    {
        // Efecto de pulsación
        if (pulsateEffect)
        {
            float pulse = Mathf.Sin(Time.time * pulsateSpeed) * pulsateStrength;
            material.SetFloat("_DistortionStrength", distortionStrength + pulse);

            // También podemos hacer pulsar el color
            Color pulseColor = eventHorizonColor;
            pulseColor.r += pulse * 0.2f;
            pulseColor.g += pulse * 0.2f;
            pulseColor.b += pulse * 0.2f;
            material.SetColor("_EventHorizonColor", pulseColor);
        }
        else
        {
            UpdateShaderParameters();
        }
    }

    // Para actualizar todos los parámetros del shader
    public void UpdateShaderParameters()
    {
        if (material != null)
        {
            material.SetFloat("_DistortionStrength", distortionStrength);
            material.SetFloat("_DistortionRadius", distortionRadius);
            material.SetFloat("_RotationSpeed", rotationSpeed);
            material.SetFloat("_EventHorizonSharpness", eventHorizonSharpness);
            material.SetColor("_EventHorizonColor", eventHorizonColor);
        }
    }

    // Método para reaccionar a la fuerza gravitacional
    public void ReactToGravityStrength(float strength)
    {
        if (reactToGravity && material != null)
        {
            // Aumentar distorsión y rotación cuando la gravedad aumenta
            material.SetFloat("_DistortionStrength", distortionStrength * (1 + strength));
            material.SetFloat("_RotationSpeed", rotationSpeed * (1 + strength * 0.5f));
        }
    }
}