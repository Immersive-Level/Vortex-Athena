using UnityEngine;
using UnityEngine.UI;

namespace GameSystems
{
    public class MultiplayerShipFuelSetup : MonoBehaviour
    {
        public ShipInputController ShipInputController;
        [SerializeField] private ComboSystem ComboSystem;
        [SerializeField] private Button RunButton;

        /// <summary>
        /// Referencias encontradas en Nave A para informar scripts de UI y guardar una copia por si se pierde en transferencia
        /// </summary>
         
        public FuelManager _fuelManager { get; private set; }
        public ShipController _shipController { get; private set; }
        public UnifiedDeathManager _unifiedDeathManager { get; private set; }
        public AbilityManager _abilityManager { get; private set; }

        /// <summary>
        /// Metodo para traer variables de PlayerMain
        /// </summary>

        public void GetPlayerShipScripts(FuelManager fuelManager, ShipController shipController, UnifiedDeathManager unifiedDeathManager, AbilityManager abilityManager)
        {
            _fuelManager = fuelManager;
            _shipController = shipController;
            _unifiedDeathManager = unifiedDeathManager;
            _abilityManager = abilityManager;

            Debug.Log("Stored succesfully ship scripts");

            SetPlayerShipScripts();
        }

        private void SetPlayerShipScripts()
        {
            ComboSystem.SetAbilityManager(_abilityManager);
            ShipInputController.SetScriptReferences(_fuelManager, _shipController, _unifiedDeathManager);
        }

    }
}

