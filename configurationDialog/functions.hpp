class configurationDialogGeneral
{
    file = "configurationDialog\functions";

    class openMissionConfigurationDialog {};
    class previewMissionArea {};
    class terminateMissionAreaPreview {};
    class initAdminMissionConfiguration {};
    class confirmMissionAreaSelection {};
}

class configurationDialogMissionAreaTransform
{
    file = "configurationDialog\functions\missionAreaTransform";

    class afterMissionAreaTransform {};
    class createMarkersForSyncedObjects {};
    class deleteMarkersForSyncedObjects {};
    class handleMapClick {};
    class handleTransformButton {};
    class scaleObjectPlacement {};
    class updateMissionAreaSelectionMarker {};
    class toggleMapEntities {};
}

class configurationDialogEnvironment
{
    file = "configurationDialog\functions\environment";

    class populateEnvConfigFields {};
    class confirmEnvConfig {};
}

class configurationDialogAI
{
    file = "configurationDialog\functions\ai";

    class populateAiConfigFields {};
    class confirmAiConfig {};
}

class intelGrid
{
    file = "configurationDialog\functions\intelGrid";

    class handleIntelGridButton {};
    class refreshIntelGridValue {};
}

class configurationDialogFactionConfig
{
    file = "configurationDialog\functions\factions";

    class openFactionsConfig {};
    class populateSpawnerTreeFactionsConfig {};
    class spawnerSelectedFactionsConfig {};
    class inputChangedFactionsConfig {};
    class addGroupFactionsConfig {};
    class removeGroupFactionsConfig {};
    class populatePoolGroupsFactionsConfig {};
    class populateGroupsConfigTreeGroupsFactionsConfig {};
    class confirmFactionsConfig {};
    class getSelectedSpawnerAndPoolFactionsConfig {};
    class clearAllPoolsFactionsConfig {};
    class addPoolFactionsConfig {};
    class createMarkersForSpawners {};
    class groupConfigSelectedFactionsConfig {};
    class addCustomGroupFactionsConfig {};
    class removePoolFactionsConfig {};
    class checkboxCheckedFactionsConfig {};
}

class configurationDialogFactionPresets
{
    file = "configurationDialog\functions\factionPresets";

    class openFactionPresets {};
    class loadFactionPreset {};
    class deleteFactionPreset {};
    class saveFactionPreset {};
    class factionPresetSelected {};
    class generateDefaultPreset {};
}