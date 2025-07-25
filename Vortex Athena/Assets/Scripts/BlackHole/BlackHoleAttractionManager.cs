using System.Collections.Generic;
using UnityEngine;

public class BlackHoleAttractionManager : MonoBehaviour
{
    // Singleton para f�cil acceso
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
        // Procesar la atracci�n hacia todos los objetos afectables
        ProcessAttraction();
    }

    // M�todo para encontrar todos los agujeros negros en la escena
    public void FindAllBlackHoles()
    {
        blackHoles.Clear();
        BlackHole[] foundBlackHoles = FindObjectsByType<BlackHole>(FindObjectsSortMode.None);
        blackHoles.AddRange(foundBlackHoles);

        Debug.Log($"BlackHoleAttractionManager: Se encontraron {blackHoles.Count} agujeros negros.");
    }

    public void FindAllAffectableObjects()
    {
        // No volvemos a agregar objetos que ya est�n en la lista
        HashSet<AffectedByBlackHole> existingObjects = new HashSet<AffectedByBlackHole>(affectableObjects);

        // Buscar todos los objetos afectables activos
        AffectedByBlackHole[] foundObjects = FindObjectsByType<AffectedByBlackHole>(FindObjectsSortMode.None);

        int newObjectsCount = 0;
        foreach (var obj in foundObjects)
        {
            // Verificar si ya est� en la lista
            if (!existingObjects.Contains(obj))
            {
                // Si no hay filtro de capa, agregar todos
                affectableObjects.Add(obj);
                newObjectsCount++;
            }
        }

        if (newObjectsCount > 0)
        {
            Debug.Log($"BlackHoleAttractionManager: Se encontraron {newObjectsCount} nuevos objetos afectables.");
        }
    }

    // Registrar un objeto afectable (llamado desde ResourceSpawner cuando activa un recurso)
    public void RegisterAffectableObject(AffectedByBlackHole obj)
    {
        if (obj != null && !affectableObjects.Contains(obj))
        {
            affectableObjects.Add(obj);
        }
    }

    // Desregistrar un objeto afectable (llamado cuando se desactiva un recurso)
    public void UnregisterAffectableObject(AffectedByBlackHole obj)
    {
        affectableObjects.Remove(obj);
    }

    // Procesar la atracci�n de todos los agujeros negros sobre todos los objetos afectables
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

                // Solo afecta objetos dentro del radio m�ximo de efecto
                if (distanceSq < maxDistanceSq && distanceSq > 0.0001f)
                {
                    // Normaliza direcci�n
                    float distance = Mathf.Sqrt(distanceSq);
                    Vector2 direction = directionToBlackHole / distance;

                    // Calcula fuerza basada en la distancia
                    float forceMagnitude = blackHole.CalculateAttractionForce(distance);

                    // Aplica fuerza al objeto
                    Vector2 force = direction * forceMagnitude * Time.deltaTime;
                    affectable.ApplyAttractionForce(force);

                    // Verificar si est� dentro del horizonte de eventos
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
                    // Si est� fuera del rango pero sigue marcado como dentro del horizonte, actualizarlo
                    affectable.ExitEventHorizon();
                }
            }
        }
    }
}
