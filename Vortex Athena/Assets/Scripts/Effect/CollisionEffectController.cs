using UnityEngine;

[RequireComponent(typeof(Animator))]
public class CollisionEffectController : MonoBehaviour
{
    void Start()
    {
        // Obtenemos el Animator y su primer clip
        Animator anim = GetComponent<Animator>();
        if (anim.runtimeAnimatorController != null &&
            anim.runtimeAnimatorController.animationClips.Length > 0)
        {
            // Tomamos la duración del primer clip
            float clipLength = anim.runtimeAnimatorController
                                   .animationClips[0].length;
            // Destruir este GameObject cuando el clip termine
            Destroy(gameObject, clipLength);
        }
        else
        {
            // Por si acaso: auto-destruir en 1 segundo
            Destroy(gameObject, 1f);
        }
    }
}

