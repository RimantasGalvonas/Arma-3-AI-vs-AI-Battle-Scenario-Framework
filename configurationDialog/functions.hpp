class configurationDialogGeneral
{
    file = "configurationDialog\functions";

    class openMissionConfigurationDialog {};
    class previewMissionArea {};
    class terminateMissionAreaPreview {};
    class initAdminMissionConfiguration {};
    class handleMapClick {};
    class updateMissionAreaSelectionMarker {};
    class confirmMissionAreaSelection {};
}

class configurationDialogAdvanced
{
    file = "configurationDialog\functions\advanced";

    class openAdvancedConfig {};
    class refreshAdvancedConfigInfo {};
    class confirmAdvancedParams{};
    class createMarkersForSyncedObjects {};
    class scaleObjectPlacement {};
    class handleTransformButton {};
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