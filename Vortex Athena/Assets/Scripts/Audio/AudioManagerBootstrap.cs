using UnityEngine;
public class AudioManagerBootstrap : MonoBehaviour
{
    static AudioManagerBootstrap _inst;
    void Awake()
    {
        if (_inst != null) { Destroy(gameObject); return; }
        _inst = this;
        DontDestroyOnLoad(gameObject);
    }
}
