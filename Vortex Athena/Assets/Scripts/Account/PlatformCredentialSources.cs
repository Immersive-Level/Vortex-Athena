using System;
using System.Threading.Tasks;
using UnityEngine;

public abstract class GooglePlayGamesCredentialSource : MonoBehaviour
{
    public abstract bool IsAvailable { get; }
    public abstract Task<string> GetServerAuthCodeAsync();
}

public abstract class AppleGameCenterCredentialSource : MonoBehaviour
{
    public abstract bool IsAvailable { get; }
    public abstract Task<AppleGameCenterCredentials> GetCredentialsAsync();
}

[Serializable]
public struct AppleGameCenterCredentials
{
    public string signature;
    public string teamPlayerId;
    public string publicKeyUrl;
    public string salt;
    public ulong timestamp;

    public AppleGameCenterCredentials(string signature, string teamPlayerId, string publicKeyUrl, string salt, ulong timestamp)
    {
        this.signature = signature;
        this.teamPlayerId = teamPlayerId;
        this.publicKeyUrl = publicKeyUrl;
        this.salt = salt;
        this.timestamp = timestamp;
    }
}

public sealed class MissingGooglePlayGamesCredentialSource : GooglePlayGamesCredentialSource
{
    public override bool IsAvailable => false;

    public override Task<string> GetServerAuthCodeAsync()
    {
        throw new InvalidOperationException("Instala Google Play Games plugin for Unity v11.01+ y asigna una fuente de credenciales Android.");
    }
}

public sealed class MissingAppleGameCenterCredentialSource : AppleGameCenterCredentialSource
{
    public override bool IsAvailable => false;

    public override Task<AppleGameCenterCredentials> GetCredentialsAsync()
    {
        throw new InvalidOperationException("Instala el Apple GameKit Unity plugin y asigna una fuente de credenciales iOS.");
    }
}
