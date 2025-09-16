using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Procesa la física gravitacional para todos los objetos afectados
/// </summary>
public class BlackHoleGravityProcessor : MonoBehaviour
{
    private BlackHoleCore blackHole;
    private BlackHoleConfiguration config;
    private float lastUpdateTime;

    public void Initialize(BlackHoleCore core, BlackHoleConfiguration configuration)
    {
        blackHole = core;
        config = configuration;
    }

    public void ProcessGravity(HashSet<IGravityAffected> affectedObjects)
    {
        if (Time.time - lastUpdateTime < config.UpdateFrequency) return;
        lastUpdateTime = Time.time;

        // Crear una lista temporal para evitar modificar la colección durante la iteración
        var objectsToProcess = new List<IGravityAffected>(affectedObjects);
        var objectsToRemove = new List<IGravityAffected>();

        // Procesar objetos usando la lista temporal
        foreach (var obj in objectsToProcess)
        {
            // Verificar que el objeto aún esté en la colección original
            if (!affectedObjects.Contains(obj))
                continue;

            if (!obj.IsActive || obj.Rigidbody == null)
            {
                objectsToRemove.Add(obj);
                continue;
            }

            ProcessObjectGravity(obj);
        }

        // Remover objetos inválidos después de la iteración
        foreach (var obj in objectsToRemove)
        {
            affectedObjects.Remove(obj);
        }
    }

    private void ProcessObjectGravity(IGravityAffected obj)
    {
        Vector2 direction = (blackHole.Position - (Vector2)obj.Transform.position);
        float distance = direction.magnitude;

        if (distance <= blackHole.EventHorizonRadius)
        {
            blackHole.ConsumeObject(obj);
            return;
        }

        direction.Normalize();

        float normalizedDistance = distance / blackHole.CurrentInfluenceRadius;
        float falloffMultiplier = config.GravityFalloffCurve.Evaluate(1f - normalizedDistance);

        float gravityStrength = Mathf.Lerp(config.BaseGravityStrength, config.MaxGravityStrength,
                                          blackHole.CurrentIntensity - 1f);

        Vector2 gravitationalForce = direction * gravityStrength * falloffMultiplier *
                                   obj.GravityMultiplier * Time.fixedDeltaTime;

        obj.Rigidbody.AddForce(gravitationalForce, ForceMode2D.Force);
    }
}