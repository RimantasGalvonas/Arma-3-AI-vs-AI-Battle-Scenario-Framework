class configurationDialogMain
{
    file = "configurationDialog\main";

    class centerMapOnPatrolCenter {};
    class confirmMissionAreaSelection {};
    class initAdminMissionConfiguration {};
    class openMissionConfigurationDialog {};

    class populateEnvConfigFields { file = "configurationDialog\main\environment\fn_populateEnvConfigFields.sqf"; };
    class confirmEnvConfig { file = "configurationDialog\main\environment\fn_confirmEnvConfig.sqf"; };

    class onFlaresLevelChange { file = "configurationDialog\main\flares\fn_onFlaresLevelChange.sqf"; };
    class refreshFlaresLevelValue { file = "configurationDialog\main\flares\fn_refreshFlaresLevelValue.sqf"; };

    class handleIntelGridButton { file = "configurationDialog\main\intelGrid\fn_handleIntelGridButton.sqf"; };
    class refreshIntelGridValue { file = "configurationDialog\main\intelGrid\fn_refreshIntelGridValue.sqf"; };

    class createMarkersForSyncedObjects { file = "configurationDialog\main\missionAreaTransform\fn_createMarkersForSyncedObjects.sqf"; };
    class deleteMarkersForSyncedObjects { file = "configurationDialog\main\missionAreaTransform\fn_deleteMarkersForSyncedObjects.sqf"; };
    class handleMapClickOnServer { file = "configurationDialog\main\missionAreaTransform\fn_handleMapClickOnServer.sqf"; };
    class handleTransformButtonOnServer { file = "configurationDialog\main\missionAreaTransform\fn_handleTransformButtonOnServer.sqf"; };
    class refreshMissionAreaSizeValue { file = "configurationDialog\main\missionAreaTransform\fn_refreshMissionAreaSizeValue.sqf"; };
    class scaleObjectPlacement { file = "configurationDialog\main\missionAreaTransform\fn_scaleObjectPlacement.sqf"; };
    class updateMissionAreaSelectionMarkerFromServer { file = "configurationDialog\main\missionAreaTransform\fn_updateMissionAreaSelectionMarkerFromServer.sqf"; };
    class toggleMapEntities { file = "configurationDialog\main\missionAreaTransform\fn_toggleMapEntities.sqf"; };
}