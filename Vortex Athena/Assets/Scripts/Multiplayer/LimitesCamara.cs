using UnityEngine;

[RequireComponent(typeof(Camera))]
public class LimitesCamara : MonoBehaviour
{
    [Header("Fuente de límites (elige uno)")]
    public Collider2D boundsCollider;      // p.ej. tu EdgeCollider2D "Bordes"
    public SpriteRenderer boundsSprite;    // o el SpriteRenderer del fondo/muros

    [Header("Ajustes")]
    public Vector2 padding = Vector2.zero; // margen interno opcional
    public bool clampX = true;
    public bool clampY = true;

    Camera cam;

    void Awake()
    {
        cam = GetComponent<Camera>();
        if (!cam.orthographic) cam.orthographic = true;
    }

    void LateUpdate()
    {
        // Recortar posición final de la cámara (después del follow)
        ClampToBounds();
    }

    void ClampToBounds()
    {
        Bounds b = GetWorldBounds();
        if (b.size == Vector3.zero) return;

        float halfH = cam.orthographicSize;
        float halfW = halfH * cam.aspect;

        Vector3 p = transform.position;

        float minX = b.min.x + halfW + padding.x;
        float maxX = b.max.x - halfW - padding.x;
        float minY = b.min.y + halfH + padding.y;
        float maxY = b.max.y - halfH - padding.y;

        // Si el viewport es más grande que la arena en algún eje, centramos en ese eje
        if (clampX)
            p.x = (minX > maxX) ? b.center.x : Mathf.Clamp(p.x, minX, maxX);
        if (clampY)
            p.y = (minY > maxY) ? b.center.y : Mathf.Clamp(p.y, minY, maxY);

        transform.position = p;
    }

    Bounds GetWorldBounds()
    {
        if (boundsCollider != null) return boundsCollider.bounds;
        if (boundsSprite != null) return boundsSprite.bounds;
        return new Bounds(Vector3.zero, Vector3.zero); // sin límites (no hace nada)
    }

#if UNITY_EDITOR
    // Gizmos para depurar
    void OnDrawGizmosSelected()
    {
        var b = GetWorldBounds();
        if (b.size == Vector3.zero || cam == null) return;

        Gizmos.color = Color.yellow;
        Gizmos.DrawWireCube(b.center, b.size);
    }
#endif
}
