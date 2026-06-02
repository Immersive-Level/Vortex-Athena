using UnityEngine;

[CreateAssetMenu(fileName = "NoesisCardData", menuName = "Vortex Athena/Noesis/Card Data")]
public class NoesisCardData : ScriptableObject
{
    public string cardId;
    public string cardNumber;
    public string displayName;
    [TextArea(3, 8)] public string noesisMessage;
    public Sprite frontSprite;
    public Sprite customBackSprite;
    public AudioClip revealSound;
}
