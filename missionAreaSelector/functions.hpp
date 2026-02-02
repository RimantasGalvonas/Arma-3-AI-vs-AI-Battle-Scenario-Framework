class missionAreaSelectorGeneral
{
    file = "missionAreaSelector\functions";

    class openMissionAreaSelector {};
    class previewMissionArea {};
    class terminateMissionAreaPreview {};
    class initMissionAreaSelection {};
    class handleMapClick {};
    class updateMissionAreaSelectionMarker {};
    class confirmMissionAreaSelection {};
    class updateFlareTooltips {};
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

class intelGrid
{
    file = "missionAreaSelector\functions\intelGrid";

    class handleIntelGridButton {};
    class refreshIntelGridValue {};
}