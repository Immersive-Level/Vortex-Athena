using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Procesa la física gravitacional - Versión optimizada para producción
/// </summary>
public class BlackHoleGravityProcessor : MonoBehaviour
{
    private BlackHoleCore blackHole;
    private BlackHoleConfiguration config;
    private float lastUpdateTime;

    // Optimización: Reutilizar listas para evitar allocaciones
    private readonly List<IGravityAffected> objectsToRemove = new List<IGravityAffected>(10);

    // Cache para valores frecuentemente calculados
    private float cachedGravityStrength;
    private float lastIntensityUpdate;
    private const float GRAVITY_CACHE_DURATION = 0.1f; // Cache por 100ms

    public void Initialize(BlackHoleCore core, BlackHoleConfiguration configuration)
    {
        blackHole = core;
        config = configuration;
        lastUpdateTime = Time.time;
        lastIntensityUpdate = -1f; // Forzar primer cálculo
    }

    public void ProcessGravity(HashSet<IGravityAffected> affectedObjects)
    {
        // Optimización: Control de frecuencia más preciso
        float currentTime = Time.time;
        if (currentTime - lastUpdateTime < config.UpdateFrequency) return;
        lastUpdateTime = currentTime;

        // Optimización: Early return si no hay objetos
        if (affectedObjects.Count == 0) return;

        // Limpiar lista de objetos a remover
        objectsToRemove.Clear();

        // Actualizar strength de gravedad solo cuando sea necesario
        UpdateGravityStrength();

        // Cache de valores del agujero negro para evitar property calls
        Vector2 blackHolePos = blackHole.Position;
        float eventHorizonRadius = config.EventHorizonRadius;
        float currentInfluenceRadius = blackHole.CurrentInfluenceRadius;
        float invInfluenceRadius = 1f / currentInfluenceRadius; // Pre-calcular división

        // CORRECCIÓN: Crear un array temporal para evitar modificación durante iteración
        var objectsArray = new IGravityAffected[affectedObjects.Count];
        affectedObjects.CopyTo(objectsArray);

        // Procesar objetos usando el array temporal
        foreach (var obj in objectsArray)
        {
            // Verificar que el objeto aún esté en la colección original
            if (!affectedObjects.Contains(obj)) continue;

            if (!obj.IsActive || obj.Rigidbody == null)
            {
                objectsToRemove.Add(obj);
                continue;
            }

            ProcessObjectGravityOptimized(obj, blackHolePos, eventHorizonRadius,
                                        currentInfluenceRadius, invInfluenceRadius);
        }

        // Remover objetos inválidos después de la iteración
        if (objectsToRemove.Count > 0)
        {
            foreach (var obj in objectsToRemove)
            {
                affectedObjects.Remove(obj);
            }
        }
    }

    private void UpdateGravityStrength()
    {
        float currentTime = Time.time;

        // Solo recalcular si ha pasado suficiente tiempo
        if (currentTime - lastIntensityUpdate > GRAVITY_CACHE_DURATION)
        {
            float currentIntensity = blackHole.CurrentIntensity;
            cachedGravityStrength = Mathf.Lerp(config.BaseGravityStrength,
                                             config.MaxGravityStrength,
                                             currentIntensity - 1f);
            lastIntensityUpdate = currentTime;
        }
    }

    private void ProcessObjectGravityOptimized(IGravityAffected obj, Vector2 blackHolePos,
                                             float eventHorizonRadius, float influenceRadius,
                                             float invInfluenceRadius)
    {
        Transform objTransform = obj.Transform;
        Vector2 objPos = objTransform.position;

        // Optimización: Usar squared distance para verificación inicial
        Vector2 direction = blackHolePos - objPos;
        float sqrDistance = direction.sqrMagnitude;

        // Verificar event horizon usando squared distance
        float eventHorizonSqr = eventHorizonRadius * eventHorizonRadius;
        if (sqrDistance <= eventHorizonSqr)
        {
            blackHole.ConsumeObject(obj);
            return;
        }

        // Solo calcular distance real si es necesario
        float distance = Mathf.Sqrt(sqrDistance);

        // Normalizar dirección usando la distancia ya calculada
        direction /= distance;

        // Calcular falloff
        float normalizedDistance = distance * invInfluenceRadius;
        float falloffMultiplier = config.GravityFalloffCurve.Evaluate(1f - normalizedDistance);

        // Aplicar fuerza gravitacional
        Vector2 gravitationalForce = direction * cachedGravityStrength * falloffMultiplier *
                                   obj.GravityMultiplier * Time.fixedDeltaTime;

        obj.Rigidbody.AddForce(gravitationalForce, ForceMode2D.Force);
    }

    private void OnDestroy()
    {
        // Limpiar referencias
        blackHole = null;
        config = null;
        objectsToRemove?.Clear();
    }
}