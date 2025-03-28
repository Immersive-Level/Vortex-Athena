using System.Collections.Generic;
using UnityEngine;

public class BlackHoleAttractionManager : MonoBehaviour
{
    // Singleton para fácil acceso
    public static BlackHoleAttractionManager Instance { get; private set; }

    // Lista de agujeros negros en la escena
    private List<BlackHole> blackHoles = new List<BlackHole>();

    // Lista de objetos afectables
    private List<AffectedByBlackHole> affectableObjects = new List<AffectedByBlackHole>();

    private void Awake()
    {
        // Configurar singleton
        if (Instance == null)
        {
            Instance = this;
        }
        else if (Instance != this)
        {
            Destroy(gameObject);
            return;
        }
    }

    private void Start()
    {
        // Buscar todos los agujeros negros y objetos afectables al inicio
        FindAllBlackHoles();
        FindAllAffectableObjects();
    }

    private void Update()
    {
        // Procesar la atracción hacia todos los objetos afectables
        ProcessAttraction();
    }

    // Método para encontrar todos los agujeros negros en la escena
    public void FindAllBlackHoles()
    {
        blackHoles.Clear();
        BlackHole[] foundBlackHoles = FindObjectsOfType<BlackHole>();
        blackHoles.AddRange(foundBlackHoles);

        Debug.Log($"BlackHoleAttractionManager: Se encontraron {blackHoles.Count} agujeros negros.");
    }

    // Método para encontrar todos los objetos afectables en la escena
    public void FindAllAffectableObjects()
    {
        affectableObjects.Clear();
        AffectedByBlackHole[] foundObjects = FindObjectsOfType<AffectedByBlackHole>();
        affectableObjects.AddRange(foundObjects);

        Debug.Log($"BlackHoleAttractionManager: Se encontraron {affectableObjects.Count} objetos afectables.");
    }

    // Registrar un nuevo agujero negro
    public void RegisterBlackHole(BlackHole blackHole)
    {
        if (!blackHoles.Contains(blackHole))
        {
            blackHoles.Add(blackHole);
        }
    }

    // Desregistrar un agujero negro
    public void UnregisterBlackHole(BlackHole blackHole)
    {
        blackHoles.Remove(blackHole);
    }

    // Registrar un objeto afectable
    public void RegisterAffectableObject(AffectedByBlackHole obj)
    {
        if (!affectableObjects.Contains(obj))
        {
            affectableObjects.Add(obj);
        }
    }

    // Desregistrar un objeto afectable
    public void UnregisterAffectableObject(AffectedByBlackHole obj)
    {
        affectableObjects.Remove(obj);
    }

    // Procesar la atracción de todos los agujeros negros sobre todos los objetos afectables
    private void ProcessAttraction()
    {
        foreach (var blackHole in blackHoles)
        {
            // Solo procesar agujeros negros activos
            if (!blackHole.isActive) continue;

            Vector2 blackHolePosition = blackHole.transform.position;
            float maxDistanceSq = blackHole.maxEffectDistance * blackHole.maxEffectDistance;

            foreach (var affectable in affectableObjects)
            {
                // Solo procesar objetos que pueden ser afectados
                if (!affectable.canBeAffected) continue;

                Vector2 objectPosition = affectable.transform.position;
                Vector2 directionToBlackHole = blackHolePosition - objectPosition;
                float distanceSq = directionToBlackHole.sqrMagnitude;

                // Solo afecta objetos dentro del radio máximo de efecto
                if (distanceSq < maxDistanceSq && distanceSq > 0.0001f)
                {
                    // Normaliza dirección
                    float distance = Mathf.Sqrt(distanceSq);
                    Vector2 direction = directionToBlackHole / distance;

                    // Calcula fuerza basada en la distancia
                    float forceMagnitude = blackHole.CalculateAttractionForce(distance);

                    // Aplica fuerza al objeto
                    Vector2 force = direction * forceMagnitude * Time.deltaTime;
                    affectable.ApplyAttractionForce(force);

                    // Verificar si está dentro del horizonte de eventos
                    if (distance <= blackHole.radius * 1.5f)
                    {
                        affectable.EnterEventHorizon();
                    }
                    else
                    {
                        affectable.ExitEventHorizon();
                    }
                }
                else if (affectable.isWithinEventHorizon)
                {
                    // Si está fuera del rango pero sigue marcado como dentro del horizonte, actualizarlo
                    affectable.ExitEventHorizon();
                }
            }
        }
    }
}
