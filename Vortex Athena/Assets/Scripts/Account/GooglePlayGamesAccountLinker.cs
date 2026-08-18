using System;
using System.Threading.Tasks;
using Unity.Services.Authentication;
using UnityEngine;

public sealed class GooglePlayGamesAccountLinker : PlatformAccountLinkerBehaviour
{
    [Tooltip("Bridge implemented with Google Play Games plugin v11.01+.")]
    [SerializeField] private GooglePlayGamesCredentialSource credentialSource;

    public override string PlatformName => "Google Play Games";

    public override bool IsAvailable
    {
        get
        {
#if UNITY_ANDROID && !UNITY_EDITOR
            return credentialSource != null && credentialSource.IsAvailable;
#else
            return false;
#endif
        }
    }

    public override async Task LinkCurrentUnityPlayerAsync()
    {
#if UNITY_ANDROID && !UNITY_EDITOR
        if (!IsAvailable)
            throw new InvalidOperationException("Google Play Games no esta instalado o no tiene una fuente de credenciales asignada.");

        string authCode = await credentialSource.GetServerAuthCodeAsync();
        if (string.IsNullOrWhiteSpace(authCode))
            throw new InvalidOperationException("Google Play Games devolvio un server auth code vacio.");

        await AuthenticationService.Instance.LinkWithGooglePlayGamesAsync(authCode);
#else
        throw new InvalidOperationException("Google Play Games solo puede vincularse en Android.");
#endif
    }
}
