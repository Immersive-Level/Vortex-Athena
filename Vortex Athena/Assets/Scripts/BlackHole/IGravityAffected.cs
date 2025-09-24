using UnityEngine;

/// <summary>
/// Interfaz para objetos que pueden ser afectados por gravedad del agujero negro
/// </summary>
public interface IGravityAffected
{
    Transform Transform { get; }
    Rigidbody2D Rigidbody { get; }
    float GravityMultiplier { get; }
    bool IsActive { get; }

    void OnEnterGravityField(BlackHoleCore blackHole);
    void OnExitGravityField(BlackHoleCore blackHole);
    void OnReachEventHorizon(BlackHoleCore blackHole);
}