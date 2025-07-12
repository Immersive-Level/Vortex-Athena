using System.Collections.Generic;
using UnityEditor;
using UnityEditor.UIElements;
using UnityEngine;
using UnityEngine.UIElements;

[CustomPropertyDrawer(typeof(LetterAbility))]
public class LetterAbilityDrawer : PropertyDrawer
{
    private static readonly Dictionary<string, string> morseMap = new()
    {
        { "A", ".-" }, { "B", "-..." }, { "C", "-.-." }, { "D", "-.." },
        { "E", "." }, { "F", "..-." }, { "G", "--." }, { "H", "...." },
        { "I", ".." }, { "J", ".---" }, { "K", "-.-" }, { "L", ".-.." },
        { "M", "--" }, { "N", "-." }, { "O", "---" }, { "P", ".--." },
        { "Q", "--.-" }, { "R", ".-." }, { "S", "..." }, { "T", "-" },
        { "U", "..-" }, { "V", "...-" }, { "W", ".--" }, { "X", "-..-" },
        { "Y", "-.--" }, { "Z", "--.." }
    };

    public override void OnGUI(Rect position, SerializedProperty property, GUIContent label)
    {
        EditorGUI.BeginProperty(position, label, property);

        var letterProp = property.FindPropertyRelative("letter");
        var abilityProp = property.FindPropertyRelative("ability");

        // Layout
        var labelRect = new Rect(position.x, position.y, 80, position.height);
        var letterRect = new Rect(position.x + 85, position.y, 40, position.height);
        var morseRect = new Rect(position.x + 130, position.y, 80, position.height);
        var abilityRect = new Rect(position.x + 215, position.y, position.width - 215, position.height);

        // Campos
        EditorGUI.LabelField(labelRect, "Letra");
        EditorGUI.PropertyField(letterRect, letterProp, GUIContent.none);

        string selectedLetter = letterProp.enumDisplayNames[letterProp.enumValueIndex];
        string morseCode = morseMap.ContainsKey(selectedLetter) ? morseMap[selectedLetter] : "???";
        EditorGUI.LabelField(morseRect, morseCode);

        EditorGUI.PropertyField(abilityRect, abilityProp, GUIContent.none);

        EditorGUI.EndProperty();
    }
}
