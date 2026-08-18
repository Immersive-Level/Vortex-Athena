using System;
using System.Threading.Tasks;
using Unity.Services.Authentication;
using UnityEngine;

public sealed class AppleGameCenterAccountLinker : PlatformAccountLinkerBehaviour
{
    [Tooltip("Bridge implemented with Apple GameKit Unity plugin.")]
    [SerializeField] private AppleGameCenterCredentialSource credentialSource;

    public override string PlatformName => "Apple Game Center";

    public override bool IsAvailable
    {
        get
        {
#if UNITY_IOS && !UNITY_EDITOR
            return credentialSource != null && credentialSource.IsAvailable;
#else
            return false;
#endif
        }
    }

    public override async Task LinkCurrentUnityPlayerAsync()
    {
#if UNITY_IOS && !UNITY_EDITOR
        if (!IsAvailable)
            throw new InvalidOperationException("Apple Game Center no esta instalado o no tiene una fuente de credenciales asignada.");

        AppleGameCenterCredentials credentials = await credentialSource.GetCredentialsAsync();
        if (string.IsNullOrWhiteSpace(credentials.signature) || string.IsNullOrWhiteSpace(credentials.teamPlayerId)
            || string.IsNullOrWhiteSpace(credentials.publicKeyUrl) || string.IsNullOrWhiteSpace(credentials.salt))
            throw new InvalidOperationException("Apple Game Center devolvio credenciales incompletas.");

        await AuthenticationService.Instance.LinkWithAppleGameCenterAsync(
            credentials.signature,
            credentials.teamPlayerId,
            credentials.publicKeyUrl,
            credentials.salt,
            credentials.timestamp);
#else
        throw new InvalidOperationException("Apple Game Center solo puede vincularse en iOS.");
#endif
    }
}
