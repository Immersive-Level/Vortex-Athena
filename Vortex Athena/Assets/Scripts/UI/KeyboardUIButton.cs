using UnityEngine;
using UnityEngine.UI;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.InputSystem.Controls;

public class KeyboardUIButton : MonoBehaviour
{
    [Header("Botones en orden (1,2,3,4)")]
    public Button[] buttons = new Button[4];

    [Header("Opciones")]
    public bool includeNumpad = true;

    [Tooltip("Duración visible del estado 'Pressed'. Usa tiempo REAL si useUnscaledTime = true.")]
    [Range(0f, 0.25f)] public float pressFeedbackDuration = 0.07f;

    [Tooltip("Usar tiempo NO escalado (recomendado si tu UI pausa con timeScale=0).")]
    public bool useUnscaledTime = true;

    [Tooltip("Si ya hay un 'press' corriendo sobre el mismo botón, forzar release antes de iniciar otro.")]
    public bool ensureReleaseOnNewPress = true;

    // Corrutinas por botón para evitar solapes
    private readonly Dictionary<Button, Coroutine> _running = new Dictionary<Button, Coroutine>();

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

        // Si ya había una corrutina “apretando” este botón, la soltamos primero
        if (ensureReleaseOnNewPress && _running.TryGetValue(btn, out var co) && co != null)
        {
            StopCoroutine(co);
            ForceRelease(btn);
            _running.Remove(btn);
        }

        var c = StartCoroutine(PressButtonRoutine(btn));
        _running[btn] = c;
    }

    IEnumerator PressButtonRoutine(Button btn)
    {
        var es = EventSystem.current;
        if (es != null) es.SetSelectedGameObject(btn.gameObject);

        var ped = new PointerEventData(es);

        // pointer enter + down → activa transición "Pressed"
        ExecuteEvents.Execute(btn.gameObject, ped, ExecuteEvents.pointerEnterHandler);
        ExecuteEvents.Execute(btn.gameObject, ped, ExecuteEvents.pointerDownHandler);

        // Espera visible (realtime si quieres ignorar timeScale)
        if (pressFeedbackDuration > 0f)
        {
            if (useUnscaledTime) yield return new WaitForSecondsRealtime(pressFeedbackDuration);
            else yield return new WaitForSeconds(pressFeedbackDuration);
        }

        // Si durante la espera el botón se desactivó/destruyó, salimos sin colgar estados
        if (btn == null || !btn.gameObject.activeInHierarchy)
        {
            yield break;
        }

        // Soltar y click “real”
        ExecuteEvents.Execute(btn.gameObject, ped, ExecuteEvents.pointerUpHandler);
        ExecuteEvents.Execute(btn.gameObject, ped, ExecuteEvents.submitHandler);
        btn.onClick?.Invoke();
        ExecuteEvents.Execute(btn.gameObject, ped, ExecuteEvents.pointerExitHandler);

        _running.Remove(btn);
    }

    void ForceRelease(Button btn)
    {
        if (btn == null || !btn.gameObject.activeInHierarchy) return;
        var es = EventSystem.current;
        var ped = new PointerEventData(es);
        ExecuteEvents.Execute(btn.gameObject, ped, ExecuteEvents.pointerUpHandler);
        ExecuteEvents.Execute(btn.gameObject, ped, ExecuteEvents.pointerExitHandler);
    }
}

