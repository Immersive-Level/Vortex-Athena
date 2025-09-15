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

        var objectsToRemove = new List<IGravityAffected>();

        foreach (var obj in affectedObjects)
        {
            if (!obj.IsActive || obj.Rigidbody == null)
            {
                objectsToRemove.Add(obj);
                continue;
            }

            ProcessObjectGravity(obj);
        }

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