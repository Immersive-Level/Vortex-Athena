using UnityEngine;

[RequireComponent(typeof(SpriteRenderer))]
public class ArenaWallAutoScale : MonoBehaviour
{
    void Start()
    {
        var cam = Camera.main;
        if (cam == null || !cam.orthographic) return;

        float worldH = cam.orthographicSize * 2f;
        float worldW = worldH * cam.aspect;

        SpriteRenderer sr = GetComponent<SpriteRenderer>();
        Vector2 spriteSize = sr.sprite.bounds.size;

        Vector3 newScale = transform.localScale;
        newScale.x = worldW / spriteSize.x;
        newScale.y = worldH / spriteSize.y;
        transform.localScale = newScale;
    }
}

