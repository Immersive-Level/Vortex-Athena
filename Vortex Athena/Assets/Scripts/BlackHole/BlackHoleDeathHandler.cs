﻿using UnityEngine;
using TMPro;
using System.Collections;

public class BlackHoleDeathHandler : MonoBehaviour
{
    private CombatSystem _combatSystem;

    [Header("Referencias")]
    [SerializeField] private Transform respawnPoint;
    [SerializeField] private Transform blackHoleCenter; // Para calcular distancia
    [SerializeField] private Collider2D blackHoleAttractionZone;
    [SerializeField] private Collider2D blackHoleDeathZone;
    [SerializeField] private GameObject countdownUI;
    [SerializeField] public TextMeshProUGUI countdownText;
    [SerializeField] private GameObject shipVisual;

    private ShipInvulnerability shipInvulnerability; // <<--- Referencia automática

    [Header("Configuración")]
    [SerializeField] private float maxDistanceForScaling = 5f;
    [SerializeField] private float minScale = 0.2f;
    [SerializeField] private float scaleSmooth = 5f;
    [SerializeField] private float respawnDelay = 3f;

    private Vector3 originalScale;
    private bool isDead = false;
    private bool inAttractionZone = false;

    private void Start()
    {
        originalScale = transform.localScale;
        countdownUI.SetActive(false);

        _combatSystem = GetComponent<CombatSystem>();
        // 🔥 Buscamos automáticamente el componente ShipInvulnerability en el mismo GameObject
        shipInvulnerability = GetComponent<ShipInvulnerability>();
        if (shipInvulnerability == null)
        {
            Debug.LogWarning("No se encontró el componente ShipInvulnerability en el mismo GameObject.");
        }
    }

    private void Update()
    {
        if (inAttractionZone && !isDead)
        {
            float distance = Vector2.Distance(transform.position, blackHoleCenter.position);
            float t = Mathf.Clamp01(distance / maxDistanceForScaling);
            float targetScale = Mathf.Lerp(minScale, originalScale.x, t);
            Vector3 newScale = Vector3.one * targetScale;
            transform.localScale = Vector3.Lerp(transform.localScale, newScale, Time.deltaTime * scaleSmooth);
        }
        else if (!isDead)
        {
            transform.localScale = Vector3.Lerp(transform.localScale, originalScale, Time.deltaTime * scaleSmooth);
        }
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision == blackHoleAttractionZone)
        {
            inAttractionZone = true;
        }

        if (collision == blackHoleDeathZone && !isDead)
        {
            StartCoroutine(HandleDeathAndRespawn());
        }
    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision == blackHoleAttractionZone)
        {
            inAttractionZone = false;
        }
    }

    public void Death()
    {
        StartCoroutine(HandleDeathAndRespawn());
    }

    private IEnumerator HandleDeathAndRespawn()
    {
        isDead = true;

        OcultarVisual();

        countdownUI.SetActive(true);

        float timeLeft = respawnDelay;
        while (timeLeft > 0)
        {
            countdownText.text = Mathf.Ceil(timeLeft).ToString() + "...";
            yield return new WaitForSeconds(1f);
            timeLeft--;
        }

        countdownUI.SetActive(false);

        // Respawn
        transform.position = respawnPoint.position;
        transform.localScale = originalScale;

        MostrarVisual();

        // 🚀 Activamos la invulnerabilidad después del respawn
        if (shipInvulnerability != null)
        {
            shipInvulnerability.ActivarInvulnerabilidad();
        }

        isDead = false;
    }

    public void OcultarVisual()
    {
        if (shipVisual != null)
        {
            shipVisual.SetActive(false);
        }
    }

    public void MostrarVisual()
    {
        if (shipVisual != null)
        {
            shipVisual.SetActive(true);
        }
    }

    private void OnDestroy()
    {
        StopAllCoroutines();
    }
}
