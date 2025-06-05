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

    private void FixedUpdate()
    {
        // Procesar la atracci�n hacia todos los objetos afectables
        ProcessAttraction();
    }

    // M�todo para encontrar todos los agujeros negros en la escena
    public void FindAllBlackHoles()
    {
        blackHoles.Clear();
        BlackHole[] foundBlackHoles = FindObjectsOfType<BlackHole>();
        blackHoles.AddRange(foundBlackHoles);

        Debug.Log($"BlackHoleAttractionManager: Se encontraron {blackHoles.Count} agujeros negros.");
    }

    public void FindAllAffectableObjects()
    {
        // No volvemos a agregar objetos que ya est�n en la lista
        HashSet<AffectedByBlackHole> existingObjects = new HashSet<AffectedByBlackHole>(affectableObjects);

        // Buscar todos los objetos afectables activos
        AffectedByBlackHole[] foundObjects = FindObjectsOfType<AffectedByBlackHole>();

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

                // Obtener Rigidbody2D
                Rigidbody2D rb = affectable.GetComponent<Rigidbody2D>();
                if (rb == null) continue;

                Vector2 objectPosition = affectable.transform.position;
                Vector2 directionToBlackHole = blackHolePosition - objectPosition;
                float distanceSq = directionToBlackHole.sqrMagnitude;

                // Solo afecta objetos dentro del radio m�ximo de efecto
                if (distanceSq < maxDistanceSq && distanceSq > 0.0001f)
                {
                    // Normaliza direcci�n
                    float distance = Mathf.Sqrt(distanceSq);
                    Vector2 direction = directionToBlackHole / distance;

                    // F�SICA ORBITAL SIMPLE
                    // 1. Fuerza hacia el centro (gravedad)
                    float forceMagnitude = blackHole.CalculateAttractionForce(distance);
                    Vector2 gravityForce = direction * forceMagnitude;

                    // 2. Si el objeto no tiene suficiente velocidad tangencial, darle un empuj�n
                    Vector2 tangent = new Vector2(-direction.y, direction.x); // Perpendicular
                    float tangentialSpeed = Vector2.Dot(rb.linearVelocity, tangent);

                    // Si la velocidad tangencial es muy baja, a�adir fuerza tangencial
                    if (Mathf.Abs(tangentialSpeed) < 2f)
                    {
                        Vector2 tangentialForce = tangent * 50f;
                        rb.AddForce(tangentialForce, ForceMode2D.Force);
                    }

                    // 3. Aplicar la gravedad
                    rb.AddForce(gravityForce, ForceMode2D.Force);

                    // 4. Limitar velocidad m�xima
                    if (rb.linearVelocity.magnitude > 5f)
                    {
                        rb.linearVelocity = rb.linearVelocity.normalized * 5f;
                    }

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