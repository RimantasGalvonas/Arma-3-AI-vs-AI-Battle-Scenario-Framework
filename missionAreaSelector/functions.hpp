class missionAreaSelectorGeneral
{
    file = "missionAreaSelector\functions";

    class openMissionAreaSelector {};
    class previewMissionArea {};
    class terminateMissionAreaPreview {};
    class moveMissionArea {};
    class initMissionAreaSelection {};
    class handleMapClick {};
}

class missionAreaSelectorAdvanced
{
    file = "missionAreaSelector\functions\advanced";

    class openAdvancedConfig {};
    class refreshAdvancedConfigInfo {};
    class confirmAdvancedParams{};
    class createMarkersForSyncedObjects {};
    class scaleObjectPlacement {};
    class handleTransformButton {};
}

class missionAreaSelectorEnvironment
{
    file = "missionAreaSelector\functions\environment";

    class populateEnvConfigFields {};
    class confirmEnvConfig {};
}

class missionAreaSelectorAI
{
    file = "missionAreaSelector\functions\ai";

    class populateAiConfigFields {};
    class confirmAiConfig {};
}