using Unity.Entities;
using Unity.Mathematics;
using UnityEngine;

// Authoring para configurar el agujero negro desde el editor
public class BlackHoleAuthoring : MonoBehaviour
{
    [Header("Propiedades F�sicas")]
    [Tooltip("Radio del agujero negro")]
    public float radius = 5f;

    [Tooltip("Fuerza m�xima de atracci�n")]
    public float maxAttractionForce = 20f;

    [Tooltip("Distancia m�xima de efecto")]
    public float maxEffectDistance = 30f;

    [Tooltip("Exponente para la curva de atracci�n (2 = gravitaci�n normal, mayor = m�s agresivo)")]
    [Range(1f, 10f)]
    public float attractionCurve = 2f;

    [Header("Configuraci�n")]
    [Tooltip("�El agujero negro est� activo al inicio de la partida?")]
    public bool activeAtStart = true;

    [Header("Visualizaci�n")]
    [Tooltip("Color del n�cleo del agujero negro")]
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

            // A�ade componentes al singleton
            AddComponent(entity, new BlackHoleComponent
            {
                Radius = authoring.radius,
                MaxAttractionForce = authoring.maxAttractionForce,
                MaxEffectDistance = authoring.maxEffectDistance,
                AttractionCurve = authoring.attractionCurve,
                IsActive = authoring.activeAtStart,
                GameSessionId = 0 // Se actualizar� en tiempo de ejecuci�n
            });

            // A�ade componente para la transformaci�n
            AddComponent(entity, new BlackHoleTransform
            {
                Position = authoring.transform.position
            });
        }
    }
}