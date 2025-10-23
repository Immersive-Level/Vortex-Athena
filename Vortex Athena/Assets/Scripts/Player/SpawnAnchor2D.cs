using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[ExecuteAlways]
[DisallowMultipleComponent]
[DefaultExecutionOrder(300)] // corre después de tu autoscale/orientación
public class SpawnAnchor2D : MonoBehaviour
{
    public enum BoundsSource
    {
        CameraOrthographic,     // usa el rectángulo visible de la cámara
        RectFromColliderOrSprite, // usa AABB de un Collider2D o SpriteRenderer
        IrregularCollider2D     // usa la forma (Edge/Polygon) y clampa adentro
    }

    [Header("Fuente de límites")]
    public BoundsSource boundsSource = BoundsSource.IrregularCollider2D;

    [Tooltip("Si boundsSource=Camera, si es null usa Camera.main")]
    public Camera targetCamera;

    [Tooltip("Para RectFromColliderOrSprite: un Collider2D o un SpriteRenderer (se usa su AABB)")]
    public Collider2D rectCollider;
    public SpriteRenderer rectSprite;

    [Tooltip("Para IrregularCollider2D: usa EdgeCollider2D o PolygonCollider2D que define el BORDE interior")]
    public Collider2D shapeCollider;

    [Header("Anchor dentro del área (0..1)")]
    [Range(0f, 1f)] public float anchorX = 0.5f; // 0 izq … 1 der
    [Range(0f, 1f)] public float anchorY = 0.5f; // 0 abajo … 1 arriba
    public Vector2 worldOffset = Vector2.zero;   // ajuste fino

    [Header("Márgenes (AABB) - solo para ancla inicial")]
    public float marginLeft = 0.5f;
    public float marginRight = 0.5f;
    public float marginTop = 0.5f;
    public float marginBottom = 0.5f;

    [Header("Borde irregular")]
    [Tooltip("Distancia mínima al borde del collider (padding interior)")]
    public float minDistanceToEdge = 0.6f;

    [Header("Actualización")]
    public bool applyOnEnable = true;
    public bool continuous = false; // re-ancle si cambian los límites en runtime
    public int settleFrames = 2;    // frames iguales para considerar estable
    public int maxWaitFrames = 10;

    [Header("Z")]
    public bool lockZ = true;
    public float zOverride = 0f;

    // cache de última caja para evitar trabajo
    Vector3 _lastCenter, _lastSize;

    void OnEnable()
    {
        if (applyOnEnable) StartCoroutine(ApplyAfterSettle());
        else Apply(true);
    }

    void LateUpdate()
    {
        if (continuous) Apply(false);
    }

    IEnumerator ApplyAfterSettle()
    {
        int stable = 0, tries = 0;
        var (c, s) = GetRectBounds();
        while (tries++ < maxWaitFrames)
        {
            var cur = GetRectBounds();
            if (Approximately(cur.center, c) && Approximately(cur.size, s)) stable++;
            else { stable = 0; c = cur.center; s = cur.size; }
            Apply(true);
            if (stable >= settleFrames) break;
            yield return null;
        }
        Apply(true);
    }

    void Apply(bool force)
    {
        // 1) Posición base por AABB (seguro para cualquier modo)
        var (center, size) = GetRectBounds();
        if (!force && Approximately(center, _lastCenter) && Approximately(size, _lastSize)) return;
        _lastCenter = center; _lastSize = size;

        float minX = center.x - size.x * 0.5f + marginLeft;
        float maxX = center.x + size.x * 0.5f - marginRight;
        float minY = center.y - size.y * 0.5f + marginBottom;
        float maxY = center.y + size.y * 0.5f - marginTop;
        if (minX > maxX) { float m = (minX + maxX) * 0.5f; minX = maxX = m; }
        if (minY > maxY) { float m = (minY + maxY) * 0.5f; minY = maxY = m; }

        Vector2 target = new Vector2(
            Mathf.Lerp(minX, maxX, anchorX),
            Mathf.Lerp(minY, maxY, anchorY)
        ) + worldOffset;

        Vector3 p = transform.position;
        p.x = target.x;
        p.y = target.y;

        // 2) Si el borde es irregular, clampa adentro con padding
        if (boundsSource == BoundsSource.IrregularCollider2D && shapeCollider != null)
        {
            if (TryGetPolygon(shapeCollider, out var poly))
            {
                Vector2 adjusted = ClampInsidePolygon(poly, target, minDistanceToEdge);
                p.x = adjusted.x;
                p.y = adjusted.y;
            }
            // Si no logra obtener polígono, se queda con el AABB (mejor que nada)
        }

        if (!lockZ) p.z = zOverride;
        transform.position = p;
    }

    // ---------------------------------------------------------------------
    // BOUNDS
    (Vector3 center, Vector3 size) GetRectBounds()
    {
        switch (boundsSource)
        {
            case BoundsSource.CameraOrthographic:
                {
                    var cam = targetCamera != null ? targetCamera : Camera.main;
                    if (cam != null && cam.orthographic)
                    {
                        float halfH = cam.orthographicSize;
                        float halfW = halfH * cam.aspect;
                        var c = cam.transform.position;
                        return (new Vector3(c.x, c.y, 0f), new Vector3(halfW * 2f, halfH * 2f, 0f));
                    }
                    break;
                }
            case BoundsSource.RectFromColliderOrSprite:
                {
                    if (rectCollider != null)
                    {
                        var b = rectCollider.bounds;
                        return (b.center, new Vector3(b.size.x, b.size.y, 0f));
                    }
                    if (rectSprite != null)
                    {
                        var b = rectSprite.bounds;
                        return (b.center, new Vector3(b.size.x, b.size.y, 0f));
                    }
                    break;
                }
            case BoundsSource.IrregularCollider2D:
            default:
                {
                    // Para el ancla inicial usamos el AABB del shapeCollider (rápido)
                    if (shapeCollider != null)
                    {
                        var b = shapeCollider.bounds;
                        return (b.center, new Vector3(b.size.x, b.size.y, 0f));
                    }
                    break;
                }
        }
        // fallback: posición actual
        return (transform.position, Vector3.one);
    }

    // ---------------------------------------------------------------------
    // POLÍGONOS (Edge/Polygon)
    bool TryGetPolygon(Collider2D col, out List<Vector2> worldPts)
    {
        worldPts = null;

        if (col is EdgeCollider2D edge)
        {
            var pts = edge.points; // en espacio local del collider
            if (pts == null || pts.Length < 2) return false;

            worldPts = new List<Vector2>(pts.Length + 1);
            for (int i = 0; i < pts.Length; i++)
                worldPts.Add(edge.transform.TransformPoint(pts[i]));

            // cerrar si no está cerrado
            if (worldPts[0] != worldPts[worldPts.Count - 1])
                worldPts.Add(worldPts[0]);

            if (PolygonSignedArea(worldPts) == 0f) return false;
            return true;
        }
        else if (col is PolygonCollider2D poly)
        {
            if (poly.pathCount == 0) return false;

            // Usamos el path con mayor área (el contorno exterior)
            float bestArea = 0f;
            int bestIdx = 0;
            for (int p = 0; p < poly.pathCount; p++)
            {
                var arr = poly.GetPath(p);
                float area = Mathf.Abs(PolygonSignedAreaLocal(arr));
                if (area > bestArea) { bestArea = area; bestIdx = p; }
            }

            var path = poly.GetPath(bestIdx);
            worldPts = new List<Vector2>(path.Length + 1);
            for (int i = 0; i < path.Length; i++)
                worldPts.Add(poly.transform.TransformPoint(path[i]));
            if (worldPts[0] != worldPts[worldPts.Count - 1])
                worldPts.Add(worldPts[0]);

            if (PolygonSignedArea(worldPts) == 0f) return false;
            return true;
        }

        return false;
    }

    // Área con signo en world-space (CCW > 0, CW < 0)
    float PolygonSignedArea(List<Vector2> poly)
    {
        double a = 0;
        for (int i = 0; i < poly.Count - 1; i++)
            a += (double)poly[i].x * poly[i + 1].y - (double)poly[i + 1].x * poly[i].y;
        return (float)(a * 0.5);
    }

    // Área con signo en local para PolygonCollider2D.GetPath
    float PolygonSignedAreaLocal(Vector2[] pts)
    {
        double a = 0;
        for (int i = 0; i < pts.Length; i++)
        {
            var p = pts[i];
            var q = pts[(i + 1) % pts.Length];
            a += (double)p.x * q.y - (double)q.x * p.y;
        }
        return (float)(a * 0.5);
    }

    // ---------------------------------------------------------------------
    // CLAMP IRREGULAR
    Vector2 ClampInsidePolygon(List<Vector2> poly, Vector2 p, float padding)
    {
        // 1) orientación (signo) para saber hacia dónde es "adentro"
        float area = PolygonSignedArea(poly);
        int orient = area >= 0f ? +1 : -1; // +1 => CCW

        // 2) punto adentro?
        bool inside = PointInPolygon(poly, p);

        // 3) encontrar borde más cercano y su normal "hacia dentro"
        Vector2 closest, inward;
        float dist = ClosestEdge(poly, p, orient, out closest, out inward);

        // 4) si está fuera, traerlo justo adentro (closest + inward*(padding + dist))
        //    si está dentro pero muy cerca, empujarlo hasta padding
        const float eps = 1e-3f;
        if (!inside)
            return closest + inward * (padding + dist + eps);
        if (dist < padding)
            return closest + inward * (padding + eps);

        return p; // ya adentro con distancia suficiente
    }

    // True si p está dentro (ray casting, funciona para cóncavos)
    bool PointInPolygon(List<Vector2> poly, Vector2 p)
    {
        bool inside = false;
        for (int i = 0, j = poly.Count - 1; i < poly.Count; j = i++)
        {
            Vector2 a = poly[i], b = poly[j];
            bool intersect = ((a.y > p.y) != (b.y > p.y)) &&
                             (p.x < (b.x - a.x) * (p.y - a.y) / ((b.y - a.y) == 0 ? 1e-6f : (b.y - a.y)) + a.x);
            if (intersect) inside = !inside;
        }
        return inside;
    }

    // Devuelve punto más cercano en el contorno y la normal hacia adentro en ese punto
    float ClosestEdge(List<Vector2> poly, Vector2 p, int orientSign, out Vector2 closest, out Vector2 inwardNormal)
    {
        float bestDist = float.PositiveInfinity;
        Vector2 bestPoint = p;
        Vector2 bestNormal = Vector2.up;

        for (int i = 0; i < poly.Count - 1; i++)
        {
            Vector2 a = poly[i];
            Vector2 b = poly[i + 1];
            Vector2 v = b - a;

            // proyección del punto sobre el segmento
            float t = Vector2.Dot(p - a, v) / (v.sqrMagnitude + 1e-8f);
            t = Mathf.Clamp01(t);
            Vector2 q = a + v * t;

            float d = Vector2.Distance(p, q);
            if (d < bestDist)
            {
                bestDist = d;
                bestPoint = q;

                // normal a la izquierda del borde
                Vector2 left = new Vector2(-v.y, v.x);
                if (left.sqrMagnitude < 1e-8f) left = Vector2.up;
                left.Normalize();

                // para CCW, "izquierda" es interior; para CW, invertir
                bestNormal = (orientSign >= 0) ? left : -left;
            }
        }

        closest = bestPoint;
        inwardNormal = bestNormal;
        return bestDist;
    }

    // ---------------------------------------------------------------------
    static bool Approximately(Vector3 a, Vector3 b)
    {
        return Mathf.Approximately(a.x, b.x)
            && Mathf.Approximately(a.y, b.y)
            && Mathf.Approximately(a.z, b.z);
    }
}
