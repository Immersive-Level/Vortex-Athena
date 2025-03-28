using UnityEngine;

public class BlackHole : MonoBehaviour
{
    [Header("Propiedades Físicas")]
    [Tooltip("Radio del agujero negro")]
    public float radius = 5f;

    [Tooltip("Fuerza máxima de atracción")]
    public float maxAttractionForce = 20f;

    [Tooltip("Distancia máxima de efecto")]
    public float maxEffectDistance = 30f;

    [Tooltip("Exponente para la curva de atracción (2 = gravitación normal, mayor = más agresivo)")]
    [Range(1f, 10f)]
    public float attractionCurve = 2f;

    [Header("Configuración")]
    [Tooltip("¿El agujero negro está activo?")]
    public bool isActive = true;

    [Header("Visualización")]
    [Tooltip("Color del núcleo del agujero negro")]
    public Color coreColor = Color.black;

    [Tooltip("Color del halo exterior")]
    public Color outerColor = new Color(0.2f, 0.05f, 0.3f, 0.7f);

    // Referencia al material
    private Material blackHoleMaterial;

    // Referencia a la imagen
    public UnityEngine.UI.Image blackHoleImage;

    [Header("Efectos Visuales")]
    [Range(0.1f, 2.0f)] public float distortionStrength = 0.3f;
    [Range(0.1f, 2.0f)] public float distortionRadius = 0.5f;
    [Range(0.1f, 10.0f)] public float rotationSpeed = 2.0f;
    [Range(1.0f, 20.0f)] public float eventHorizonSharpness = 8.0f;
    public Color eventHorizonColor = new Color(0.1f, 0.4f, 1.0f, 1.0f);

    [Header("Animación")]
    public bool animateProperties = true;
    [Range(0.1f, 5.0f)] public float pulseSpeed = 1.0f;
    [Range(0.0f, 1.0f)] public float pulseStrengthAmount = 0.2f;
    [Range(0.0f, 0.5f)] public float pulseRadiusAmount = 0.1f;
    [Range(0.0f, 5.0f)] public float rotationVariation = 1.0f;
    [Range(0.0f, 5.0f)] public float colorCycleSpeed = 0.5f;
    public bool useRandomSeed = true;
    [Range(1, 5)] public int chaosLevel = 3;
    public bool usePerlinNoise = true;

    // Variables privadas para animación
    private float timeOffset;
    private float noiseOffset1, noiseOffset2, noiseOffset3;
    private float initialDistortionStrength;
    private float initialDistortionRadius;
    private float initialRotationSpeed;
    private Color initialEventHorizonColor;
    private float[] chaosFactors;
    private Vector2[] noiseVectors;

    private void Start()
    {
        // Inicializar efectos visuales
        InitializeVisuals();

        // Guardar valores iniciales para la animación
        initialDistortionStrength = distortionStrength;
        initialDistortionRadius = distortionRadius;
        initialRotationSpeed = rotationSpeed;
        initialEventHorizonColor = eventHorizonColor;

        // Inicializar aleatoriedad para animaciones
        InitializeRandomness();
    }

    private void InitializeVisuals()
    {
        // Verificar que tenemos una imagen asignada
        if (blackHoleImage == null)
        {
            blackHoleImage = GetComponent<UnityEngine.UI.Image>();
            if (blackHoleImage == null)
            {
                Debug.LogError("No se encontró un componente Image en el objeto. Por favor asigne uno.");
                enabled = false;
                return;
            }
        }

        // Cargar y configurar el shader
        Shader blackHoleShader = Shader.Find("Custom/BlackHoleDistortion");
        if (blackHoleShader == null)
        {
            Debug.LogError("No se encontró el shader 'Custom/BlackHoleDistortion'. Asegúrate de que está incluido en el proyecto.");
            enabled = false;
            return;
        }

        blackHoleMaterial = new Material(blackHoleShader);
        blackHoleImage.material = blackHoleMaterial;
    }

    private void InitializeRandomness()
    {
        if (useRandomSeed)
        {
            timeOffset = Random.Range(0f, 1000f);
            noiseOffset1 = Random.Range(0f, 1000f);
            noiseOffset2 = Random.Range(0f, 1000f);
            noiseOffset3 = Random.Range(0f, 1000f);
        }
        else
        {
            timeOffset = 0f;
            noiseOffset1 = 0f;
            noiseOffset2 = 100f;
            noiseOffset3 = 200f;
        }

        // Inicializar factores de caos para comportamiento impredecible
        chaosFactors = new float[10];
        for (int i = 0; i < chaosFactors.Length; i++)
        {
            chaosFactors[i] = Random.Range(0.5f, 1.5f);
        }

        // Vectores para ruido de Perlin
        noiseVectors = new Vector2[5];
        for (int i = 0; i < noiseVectors.Length; i++)
        {
            noiseVectors[i] = new Vector2(
                Random.Range(-1f, 1f),
                Random.Range(-1f, 1f)
            ).normalized;
        }
    }

    private void Update()
    {
        if (!isActive) return;

        // Aplicar animaciones si está habilitado
        if (animateProperties)
        {
            AnimateBlackHole();
        }
        else
        {
            // Actualizar propiedades estáticas
            UpdateShaderProperties(distortionStrength, distortionRadius, rotationSpeed, eventHorizonSharpness, eventHorizonColor);
        }
    }

    private void AnimateBlackHole()
    {
        float time = Time.time + timeOffset;

        float pulsatingStrength, pulsatingRadius, varyingRotation;
        Color cyclicColor;

        if (usePerlinNoise && chaosLevel >= 3)
        {
            // Usar ruido de Perlin para valores más caóticos e impredecibles
            pulsatingStrength = GetChaosValue(initialDistortionStrength, pulseStrengthAmount * 1.5f, time, 0);
            pulsatingRadius = GetChaosValue(initialDistortionRadius, pulseRadiusAmount * 1.5f, time, 1);
            varyingRotation = GetChaosValue(initialRotationSpeed, rotationVariation * 1.5f, time, 2);

            // Color con variación caótica
            float hue = Mathf.PerlinNoise(time * colorCycleSpeed * 0.1f * chaosFactors[3] + noiseOffset1,
                                          time * colorCycleSpeed * 0.05f * chaosFactors[4] + noiseOffset2);
            Color.RGBToHSV(initialEventHorizonColor, out float _, out float s, out float v);
            cyclicColor = Color.HSVToRGB(hue, s, v);
            cyclicColor.a = initialEventHorizonColor.a;
        }
        else
        {
            // Variación más tradicional basada en senos
            float chaosMultiplier = 1f + (chaosLevel * 0.1f);

            // Agregar funciones trigonométricas múltiples para mayor complejidad
            pulsatingStrength = initialDistortionStrength +
                (Mathf.Sin(time * pulseSpeed * chaosFactors[0]) * 0.6f +
                Mathf.Sin(time * pulseSpeed * 1.3f * chaosFactors[1]) * 0.4f) *
                pulseStrengthAmount * chaosMultiplier;

            pulsatingRadius = initialDistortionRadius +
                (Mathf.Sin(time * pulseSpeed * 0.7f * chaosFactors[2]) * 0.65f +
                Mathf.Cos(time * pulseSpeed * 1.1f * chaosFactors[3]) * 0.35f) *
                pulseRadiusAmount * chaosMultiplier;

            varyingRotation = initialRotationSpeed +
                (Mathf.Sin(time * pulseSpeed * 0.5f * chaosFactors[4]) * 0.7f +
                Mathf.Sin(time * pulseSpeed * 1.7f * chaosFactors[5]) * 0.3f) *
                rotationVariation * chaosMultiplier;

            // Color con varias frecuencias
            float hueShift = (Mathf.Sin(time * colorCycleSpeed * 0.1f * chaosFactors[6]) * 0.6f +
                             Mathf.Sin(time * colorCycleSpeed * 0.27f * chaosFactors[7]) * 0.4f) * 0.5f;

            float baseHue;
            Color.RGBToHSV(initialEventHorizonColor, out baseHue, out float s, out float v);
            float newHue = Mathf.Repeat(baseHue + hueShift, 1f);
            cyclicColor = Color.HSVToRGB(newHue, s, v);
            cyclicColor.a = initialEventHorizonColor.a;
        }

        // Añadir pequeños temblores aleatorios en niveles altos de caos
        if (chaosLevel >= 4)
        {
            pulsatingStrength += Random.Range(-0.05f, 0.05f) * chaosLevel * 0.02f;
            pulsatingRadius += Random.Range(-0.02f, 0.02f) * chaosLevel * 0.02f;
            varyingRotation += Random.Range(-0.1f, 0.1f) * chaosLevel * 0.1f;
        }

        // Actualizar propiedades en el shader
        UpdateShaderProperties(pulsatingStrength, pulsatingRadius, varyingRotation, eventHorizonSharpness, cyclicColor);
    }

    private float GetChaosValue(float baseValue, float amplitude, float time, int index)
    {
        if (chaosLevel <= 1)
            return baseValue + Mathf.Sin(time * pulseSpeed * chaosFactors[index]) * amplitude;

        // Usar múltiples capas de ruido de Perlin para crear patrones complejos
        float noise1 = Mathf.PerlinNoise(
            time * pulseSpeed * 0.2f * chaosFactors[index] + noiseOffset1,
            time * pulseSpeed * 0.3f * chaosFactors[index + 1] + noiseOffset2
        ) * 2f - 1f; // Convertir de 0-1 a -1 a 1

        float noise2 = Mathf.PerlinNoise(
            time * pulseSpeed * 0.15f * chaosFactors[index + 2] + noiseOffset2,
            time * pulseSpeed * 0.25f * chaosFactors[index + 3] + noiseOffset3
        ) * 2f - 1f;

        // Añadir un componente direccional al ruido
        float directionalNoise = Vector2.Dot(
            new Vector2(noise1, noise2).normalized,
            noiseVectors[index % noiseVectors.Length]
        ) * 0.5f;

        // Mezclar diferentes tipos de ruido
        float finalNoise = (noise1 * 0.5f + noise2 * 0.3f + directionalNoise * 0.2f) * amplitude;

        // Añadir pequeños saltos aleatorios en niveles altos de caos
        if (chaosLevel >= 4 && Random.value < 0.01f * chaosLevel)
        {
            finalNoise += Random.Range(-0.1f, 0.1f) * chaosLevel * 0.05f;
        }

        return baseValue + finalNoise;
    }

    private void UpdateShaderProperties(float strength, float radius, float rotation, float sharpness, Color color)
    {
        if (blackHoleMaterial != null)
        {
            blackHoleMaterial.SetFloat("_DistortionStrength", strength);
            blackHoleMaterial.SetFloat("_DistortionRadius", radius);
            blackHoleMaterial.SetFloat("_RotationSpeed", rotation);
            blackHoleMaterial.SetFloat("_EventHorizonSharpness", sharpness);
            blackHoleMaterial.SetColor("_EventHorizonColor", color);
        }
    }

    // Calcula la fuerza de atracción basada en la distancia
    public float CalculateAttractionForce(float distance)
    {
        // Si el agujero negro está inactivo, no hay atracción
        if (!isActive) return 0f;

        // Evitar división por cero
        if (distance < 0.0001f)
            return maxAttractionForce;

        // Si está dentro del radio, fuerza máxima
        if (distance <= radius)
            return maxAttractionForce;

        // Calcula caída de fuerza basada en distancia y exponente de curva
        float normalizedDistance = Mathf.Clamp01((maxEffectDistance - distance) /
                                               (maxEffectDistance - radius));

        // Aplica la curva (usa pow para exponente)
        float forceFactor = Mathf.Pow(normalizedDistance, attractionCurve);

        return forceFactor * maxAttractionForce;
    }

    // Para visualizar en el editor
    private void OnDrawGizmos()
    {
        // Dibujar radio del núcleo
        Gizmos.color = coreColor;
        Gizmos.DrawSphere(transform.position, radius);

        // Dibujar radio de efecto máximo
        Gizmos.color = outerColor;
        Gizmos.DrawWireSphere(transform.position, maxEffectDistance);
    }

    private void OnValidate()
    {
        if (Application.isPlaying && blackHoleMaterial != null)
        {
            // Reinicializar randomización al cambiar parámetros en tiempo de ejecución
            InitializeRandomness();
        }
    }
}