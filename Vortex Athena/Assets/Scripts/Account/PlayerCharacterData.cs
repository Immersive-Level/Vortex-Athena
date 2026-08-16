using UnityEngine;

[CreateAssetMenu(fileName = "PlayerCharacter", menuName = "Vortex Athena/Player Character")]
public sealed class PlayerCharacterData : ScriptableObject
{
    [SerializeField] private string characterId;
    [SerializeField] private string displayName;
    [SerializeField] private Sprite silhouetteSprite;
    [SerializeField] private bool isUnlockedByDefault;
    [SerializeField] private Sprite empireIcon;
    [TextArea(2, 4)]
    [SerializeField] private string statsPreview;

    public string CharacterId => characterId;
    public string DisplayName => string.IsNullOrWhiteSpace(displayName) ? characterId : displayName;
    public Sprite SilhouetteSprite => silhouetteSprite;
    public bool IsUnlockedByDefault => isUnlockedByDefault;
    public Sprite EmpireIcon => empireIcon;
    public string StatsPreview => statsPreview;
}
