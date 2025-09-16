// Assets/ArcadeSystem/Scripts/ArcadeInput.cs
// --------------------------------------------------------
// Enlaza el Input System (teclas 1,2,3,4) con ArcadeEvents.
// No toca tu gameplay directamente para que tu rama sea estable.

using UnityEngine;
using UnityEngine.InputSystem;

public class ArcadeInput : MonoBehaviour
{
    // Si tu clase generada se llama ArcadeControls, cámbialo aquí.
    private Controls controls;

    private void Awake()
    {
        controls = new Controls();

        // Suscribe a performed (flanco de activación)
        controls.Arcade.P1_Press.performed += _ => OnPress(1);
        controls.Arcade.P2_Press.performed += _ => OnPress(2);
        controls.Arcade.P3_Press.performed += _ => OnPress(3);
        controls.Arcade.P4_Press.performed += _ => OnPress(4);
    }

    private void OnEnable() => controls.Enable();
    private void OnDisable() => controls.Disable();

    private void OnPress(int player)
    {
        // Lanza evento hacia tu core
        ArcadeEvents.RaisePress(player);

        // OJO: El LED "vivo" lo maneja localmente el Leonardo mientras se presiona.
        // Si tu lógica declara muerte/vida, usa SerialBridge.SetAlive(player, bool)
        // desde tus sistemas de juego (ver abajo).
        Debug.Log($"Jugador {player} presionó su botón");
        ArcadeEvents.RaisePress(player);
    }
}

