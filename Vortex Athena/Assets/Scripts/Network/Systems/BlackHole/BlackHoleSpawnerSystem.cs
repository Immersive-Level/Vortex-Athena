using Unity.Entities;
using Unity.Mathematics;
using Unity.NetCode;
using Unity.Transforms;

[WorldSystemFilter(WorldSystemFilterFlags.ServerSimulation)] // Reemplaza ServerSimulationSystemGroup
public partial class BlackHoleSpawnerSystem : SystemBase
{
    private EntityQuery _playerQuery;

    protected override void OnCreate()
    {
        base.OnCreate();
        _playerQuery = GetEntityQuery(ComponentType.ReadOnly<PlayerComponent>());
        RequireForUpdate<GameplayStateComponent>();
    }

    protected override void OnUpdate()
    {
        // Ejemplo: Spawneamos un agujero negro cada X segundos o basado en eventos del juego
        var gameState = SystemAPI.GetSingleton<GameplayStateComponent>();

        if (gameState.ShouldSpawnBlackHole && !gameState.BlackHoleActive)
        {
            SpawnBlackHole();

            // Actualizar estado del juego
            var gameStateEntity = SystemAPI.GetSingletonEntity<GameplayStateComponent>();
            EntityManager.SetComponentData(gameStateEntity, new GameplayStateComponent
            {
                BlackHoleActive = true,
                ShouldSpawnBlackHole = false,
                BlackHoleSpawnTimer = 0
            });
        }
    }

    private void SpawnBlackHole()
    {
        // Crear la entidad del agujero negro
        var blackHoleEntity = EntityManager.CreateEntity();

        // Añadir componentes necesarios para networking (corregido de NetworkObject a GhostType)
        EntityManager.AddComponent<GhostType>(blackHoleEntity);

        // Reemplazamos GhostOwnerComponent obsoleto por GhostOwner
        EntityManager.AddComponentData(blackHoleEntity, new GhostOwner
        {
            NetworkId = 0
        });

        // Determinar una posición estratégica (por ejemplo, cerca del centro del mapa)
        var position = new float3(0, 0, 0); // Ajustar según necesidades del juego

        EntityManager.AddComponentData(blackHoleEntity, new LocalTransform
        {
            Position = position,
            Rotation = quaternion.identity,
            Scale = 1f
        });

        // Configurar los parámetros del agujero negro
        EntityManager.AddComponentData(blackHoleEntity, new BlackHoleComponent
        {
            Radius = 5f,
            MaxAttractionForce = 20f,
            MaxEffectDistance = 50f,
            AttractionCurve = 2.5f
        });

        // Añadir componente de prefab para visualización
        // Este prefab debe estar configurado en tu GhostAuthoringComponent
        EntityManager.AddComponent<PrefabComponent>(blackHoleEntity);
    }
}