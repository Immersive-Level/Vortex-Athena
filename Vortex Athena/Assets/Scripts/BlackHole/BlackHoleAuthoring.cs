using Unity.Entities;
using Unity.Mathematics;
using UnityEngine;

// Authoring para configurar el agujero negro desde el editor
public class BlackHoleAuthoring : MonoBehaviour
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
    [Tooltip("¿El agujero negro está activo al inicio de la partida?")]
    public bool activeAtStart = true;

    [Header("Visualización")]
    [Tooltip("Color del núcleo del agujero negro")]
    public Color coreColor = Color.black;

    [Tooltip("Color del halo exterior")]
    public Color outerColor = new Color(0.2f, 0.05f, 0.3f, 0.7f);

    // Visual guide in editor
    private void OnDrawGizmos()
    {
        // Draw core radius
        Gizmos.color = coreColor;
        Gizmos.DrawSphere(transform.position, radius);

        // Draw effect radius
        Gizmos.color = outerColor;
        Gizmos.DrawWireSphere(transform.position, maxEffectDistance);
    }

    // Baker para convertir el GameObject en Entity
    class BlackHoleBaker : Baker<BlackHoleAuthoring>
    {
        public override void Bake(BlackHoleAuthoring authoring)
        {
            // Crea entidad para el agujero negro
            var entity = GetEntity(TransformUsageFlags.Dynamic);

            // Añade componentes al singleton
            AddComponent(entity, new BlackHoleComponent
            {
                Radius = authoring.radius,
                MaxAttractionForce = authoring.maxAttractionForce,
                MaxEffectDistance = authoring.maxEffectDistance,
                AttractionCurve = authoring.attractionCurve,
                IsActive = authoring.activeAtStart,
                GameSessionId = 0 // Se actualizará en tiempo de ejecución
            });

            // Añade componente para la transformación
            AddComponent(entity, new BlackHoleTransform
            {
                Position = authoring.transform.position
            });
        }
    }
}