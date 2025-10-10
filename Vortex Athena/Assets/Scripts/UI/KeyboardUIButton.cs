using UnityEngine;
using UnityEngine.UI;
using UnityEngine.InputSystem;
using UnityEngine.EventSystems;
using System.Collections;
using System.Collections.Generic;

public class KeyboardUIButton : MonoBehaviour
{
    [Header("Botones en orden")]
    [Tooltip("Orden: [0]=→  [1]=↑  [2]=↓  [3]=←")]
    public Button[] buttons = new Button[4];

    [Header("Opciones")]
    public bool useUnscaledTime = true;
    public bool ensureReleaseOnNewPress = true;
    [Range(0f, 0.25f)] public float pressFeedbackDuration = 0.07f;

    // Corrutinas por botón para evitar solapes
    private readonly Dictionary<Button, Coroutine> _running = new Dictionary<Button, Coroutine>();

    void Update()
    {
        if (Keyboard.current == null) return;

        // Asignaciones de teclas
        if (Keyboard.current.rightArrowKey.wasPressedThisFrame) ClickIndex(0); // →
        if (Keyboard.current.upArrowKey.wasPressedThisFrame) ClickIndex(1);    // ↑
        if (Keyboard.current.downArrowKey.wasPressedThisFrame) ClickIndex(2);  // ↓
        if (Keyboard.current.leftArrowKey.wasPressedThisFrame) ClickIndex(3);  // ←
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


