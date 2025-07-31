using UnityEngine;

[RequireComponent(typeof(SpriteRenderer))]
public class ArenaAutoScale : MonoBehaviour
{
    void Start()
    {
        var cam = Camera.main;
        if (cam == null || !cam.orthographic) return;

        // Tamaño del viewport en unidades de mundo
        float worldHeight = cam.orthographicSize * 2f;
        float worldWidth = worldHeight * cam.aspect;

        // Tamaño original del sprite
        SpriteRenderer sr = GetComponent<SpriteRenderer>();
        Vector2 size = sr.sprite.bounds.size;

        // Nueva escala necesaria para cubrir toda el área
        Vector3 newScale = transform.localScale;
        newScale.x = worldWidth / size.x;
        newScale.y = worldHeight / size.y;
        transform.localScale = newScale;
    }
}

