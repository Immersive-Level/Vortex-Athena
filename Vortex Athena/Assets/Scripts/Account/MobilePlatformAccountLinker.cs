using System;
using System.Threading.Tasks;
using UnityEngine;

public sealed class MobilePlatformAccountLinker : PlatformAccountLinkerBehaviour
{
    [Header("Provider Adapters")]
    [SerializeField] private PlatformAccountLinkerBehaviour googlePlayGamesLinker;
    [SerializeField] private PlatformAccountLinkerBehaviour appleOrGameCenterLinker;

    private IPlatformAccountLinker ActiveLinker
    {
        get
        {
#if UNITY_ANDROID
            return googlePlayGamesLinker;
#elif UNITY_IOS
            return appleOrGameCenterLinker;
#else
            return null;
#endif
        }
    }

    public override string PlatformName
    {
        get
        {
#if UNITY_ANDROID
            return "Google Play Games";
#elif UNITY_IOS
            return "Apple / Game Center";
#else
            return "Unsupported platform";
#endif
        }
    }

    public override bool IsAvailable => ActiveLinker != null && ActiveLinker.IsAvailable;

    public override Task LinkCurrentUnityPlayerAsync()
    {
        if (!IsAvailable)
            throw new InvalidOperationException($"El adaptador de {PlatformName} aun no esta configurado.");
        return ActiveLinker.LinkCurrentUnityPlayerAsync();
    }
}
