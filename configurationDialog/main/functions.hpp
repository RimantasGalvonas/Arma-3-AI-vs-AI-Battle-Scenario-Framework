class configurationDialogMain
{
    file = "configurationDialog\main";

    class confirmMissionAreaSelection {};
    class initAdminMissionConfiguration {};
    class openMissionConfigurationDialog {};

    class populateEnvConfigFields { file = "configurationDialog\main\environment\fn_populateEnvConfigFields.sqf"; };
    class confirmEnvConfig { file = "configurationDialog\main\environment\fn_confirmEnvConfig.sqf"; };

    class handleIntelGridButton { file = "configurationDialog\main\intelGrid\fn_handleIntelGridButton.sqf"; };
    class refreshIntelGridValue { file = "configurationDialog\main\intelGrid\fn_refreshIntelGridValue.sqf"; };

    class afterMissionAreaTransform { file = "configurationDialog\main\missionAreaTransform\fn_afterMissionAreaTransform.sqf"; };
    class createMarkersForSyncedObjects { file = "configurationDialog\main\missionAreaTransform\fn_createMarkersForSyncedObjects.sqf"; };
    class deleteMarkersForSyncedObjects { file = "configurationDialog\main\missionAreaTransform\fn_deleteMarkersForSyncedObjects.sqf"; };
    class handleMapClick { file = "configurationDialog\main\missionAreaTransform\fn_handleMapClick.sqf"; };
    class handleTransformButton { file = "configurationDialog\main\missionAreaTransform\fn_handleTransformButton.sqf"; };
    class scaleObjectPlacement { file = "configurationDialog\main\missionAreaTransform\fn_scaleObjectPlacement.sqf"; };
    class updateMissionAreaSelectionMarker { file = "configurationDialog\main\missionAreaTransform\fn_updateMissionAreaSelectionMarker.sqf"; };
    class toggleMapEntities { file = "configurationDialog\main\missionAreaTransform\fn_toggleMapEntities.sqf"; };
}