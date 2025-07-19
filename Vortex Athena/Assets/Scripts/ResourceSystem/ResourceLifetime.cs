// Assets/Scripts/ResourceLifetime.cs
using UnityEngine;

[RequireComponent(typeof(SpriteRenderer))]
public class ResourceLifetime : MonoBehaviour
{
    [Header("Lifetime")]
    public float totalLifetime = 30f;     // Segundos hasta desaparecer
    public float blinkDuration = 5f;      // Últimos segundos en los que parpadea
    [Header("Blink")]
    public float blinkInterval = .25f;    // Velocidad del parpadeo

    float t;               // tiempo transcurrido
    bool isBlinking;
    SpriteRenderer[] rends;

    void OnEnable()
    {
        t = 0f;
        isBlinking = false;
        rends = GetComponentsInChildren<SpriteRenderer>(true);
        // Garantiza que el sprite empiece visible
        foreach (var r in rends) r.enabled = true;
    }

    void Update()
    {
        t += Time.deltaTime;

        // -- Comenzar parpadeo
        if (!isBlinking && t >= totalLifetime - blinkDuration)
            isBlinking = true;

        // -- Alternar visibilidad
        if (isBlinking)
        {
            bool visible = Mathf.FloorToInt((t - (totalLifetime - blinkDuration)) / blinkInterval) % 2 == 0;
            foreach (var r in rends) r.enabled = visible;
        }

        // -- Fin de vida: volver al pool
        if (t >= totalLifetime)
        {
            ResourceSpawner.Instance?.ReturnToPool(gameObject);
            // Si llegara a no existir spawner, simplemente:
            // gameObject.SetActive(false);
        }
    }
}

