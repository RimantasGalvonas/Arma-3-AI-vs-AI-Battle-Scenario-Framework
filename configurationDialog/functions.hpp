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
    class factionsConfigUISpawnerSelected { file = "configurationDialog\functions\factions\uiEvents\fn_factionsConfigUISpawnerSelected.sqf" };
    class factionsConfigUIInputChanged { file = "configurationDialog\functions\factions\uiEvents\fn_factionsConfigUIInputChanged.sqf" };
    class factionsConfigUIGroupConfigSelected { file = "configurationDialog\functions\factions\uiEvents\fn_factionsConfigUIGroupConfigSelected.sqf" };
    class factionsConfigUICheckboxChecked { file = "configurationDialog\functions\factions\uiEvents\fn_factionsConfigUICheckboxChecked.sqf" };
    class populateSpawnerTree {};
    class addGroupToPool {};
    class removeGroupFromPool {};
    class populatePoolGroupsList {};
    class populateFactionGroupsConfigTree {};
    class confirmFactionsConfig {};
    class getSelectedSpawnerAndPool {};
    class clearAllPoolsInSpawner {};
    class addPoolToSpawner {};
    class createMarkersForSpawners {};
    class addCustomGroupToPool {};
    class removePoolFromSpawner {};
}

class configurationDialogFactionPresets
{
    file = "configurationDialog\functions\factionPresets";

    class openFactionPresets {};
    class loadFactionPreset {};
    class deleteFactionPreset {};
    class saveFactionPreset {};
    class factionPresetSelected {};
    class generateDefaultFactionPreset {};
}