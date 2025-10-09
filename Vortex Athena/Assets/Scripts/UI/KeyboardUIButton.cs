using UnityEngine;
using UnityEngine.UI;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;
using System.Collections;
using UnityEngine.InputSystem.Controls;

public class KeyboardUIButton : MonoBehaviour
{
    [Header("Botones (1,2,3,4 en ese orden)")]
    public Button[] buttons = new Button[4];

    [Header("Opciones")]
    public bool includeNumpad = true;
    [Tooltip("Duración visible del 'Pressed' antes de soltar (segundos).")]
    public float pressFeedbackDuration = 0.07f;

    void Update()
    {
        if (Keyboard.current == null) return;

        if (Pressed(Keyboard.current.digit1Key, Keyboard.current.numpad1Key)) ClickIndex(0);
        if (Pressed(Keyboard.current.digit2Key, Keyboard.current.numpad2Key)) ClickIndex(1);
        if (Pressed(Keyboard.current.digit3Key, Keyboard.current.numpad3Key)) ClickIndex(2);
        if (Pressed(Keyboard.current.digit4Key, Keyboard.current.numpad4Key)) ClickIndex(3);
    }

    bool Pressed(KeyControl main, KeyControl numpad)
    {
        if (main != null && main.wasPressedThisFrame) return true;
        if (includeNumpad && numpad != null && numpad.wasPressedThisFrame) return true;
        return false;
    }

    void ClickIndex(int i)
    {
        if (i < 0 || i >= buttons.Length) return;
        var btn = buttons[i];
        if (btn == null || !btn.interactable || !btn.gameObject.activeInHierarchy) return;
        StartCoroutine(PressButtonRoutine(btn));
    }

    IEnumerator PressButtonRoutine(Button btn)
    {
        // seleccionar para que reciba estilo de "Selected" si tu transición lo usa
        if (EventSystem.current != null)
            EventSystem.current.SetSelectedGameObject(btn.gameObject);

        // simular pointer enter + down (activa estado Pressed en ColorTint/SpriteSwap/Animation)
        var ped = new PointerEventData(EventSystem.current);
        ExecuteEvents.Execute(btn.gameObject, ped, ExecuteEvents.pointerEnterHandler);
        ExecuteEvents.Execute(btn.gameObject, ped, ExecuteEvents.pointerDownHandler);

        // mantener un instante el estado “Pressed” para feedback visual
        if (pressFeedbackDuration > 0f)
            yield return new WaitForSeconds(pressFeedbackDuration);

        // soltar y disparar el click
        ExecuteEvents.Execute(btn.gameObject, ped, ExecuteEvents.pointerUpHandler);
        // submit para Selectables que lo usen
        ExecuteEvents.Execute(btn.gameObject, ped, ExecuteEvents.submitHandler);
        // y el onClick normal del Button
        btn.onClick.Invoke();

        // opcional: salir del hover (si no quieres que quede resaltado)
        ExecuteEvents.Execute(btn.gameObject, ped, ExecuteEvents.pointerExitHandler);
    }
}

