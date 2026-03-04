class configurationDialogFactionConfig
{
    file = "configurationDialog\factions";

    class openFactionsConfig {};
    class confirmFactionsConfig {};
    class getSelectedSpawnerAndPool {};

    class factionsConfigUICheckboxChecked { file = "configurationDialog\factions\uiEvents\fn_factionsConfigUICheckboxChecked.sqf"; };
    class factionsConfigUIInputChanged { file = "configurationDialog\factions\uiEvents\fn_factionsConfigUIInputChanged.sqf"; };

    class populateSpawnerTree { file = "configurationDialog\factions\spawners\fn_populateSpawnerTree.sqf"; };
    class clearAllPoolsInSpawner { file = "configurationDialog\factions\spawners\fn_clearAllPoolsInSpawner.sqf"; };
    class addPoolToSpawner { file = "configurationDialog\factions\spawners\fn_addPoolToSpawner.sqf"; };
    class createMarkersForSpawners { file = "configurationDialog\factions\spawners\fn_createMarkersForSpawners.sqf"; };
    class removePoolFromSpawner { file = "configurationDialog\factions\spawners\fn_removePoolFromSpawner.sqf"; };
    class spawnerSelected { file = "configurationDialog\factions\spawners\fn_spawnerSelected.sqf"; };

    class addGroupToPool { file = "configurationDialog\factions\pools\fn_addGroupToPool.sqf"; };
    class copyPoolGroups { file = "configurationDialog\factions\pools\fn_copyPoolGroups.sqf"; };
    class groupConfigSelected { file = "configurationDialog\factions\pools\fn_groupConfigSelected.sqf"; };
    class pasteGroupsIntoPool { file = "configurationDialog\factions\pools\fn_pasteGroupsIntoPool.sqf"; };
    class poolGroupSelected { file = "configurationDialog\factions\pools\fn_poolGroupSelected.sqf"; };
    class populateFactionGroupsConfigTree { file = "configurationDialog\factions\pools\fn_populateFactionGroupsConfigTree.sqf"; };
    class populatePoolGroupsList { file = "configurationDialog\factions\pools\fn_populatePoolGroupsList.sqf"; };
    class removeGroupFromPool { file = "configurationDialog\factions\pools\fn_removeGroupFromPool.sqf"; };

    class openFactionPresets { file = "configurationDialog\factions\presets\fn_openFactionPresets.sqf"; };
    class loadFactionPreset { file = "configurationDialog\factions\presets\fn_loadFactionPreset.sqf"; };
    class deleteFactionPreset { file = "configurationDialog\factions\presets\fn_deleteFactionPreset.sqf"; };
    class saveFactionPreset { file = "configurationDialog\factions\presets\fn_saveFactionPreset.sqf"; };
    class factionPresetSelected { file = "configurationDialog\factions\presets\fn_factionPresetSelected.sqf"; };
    class generateDefaultFactionPreset { file = "configurationDialog\factions\presets\fn_generateDefaultFactionPreset.sqf"; };

    class addCustomGroupToPool { file = "configurationDialog\factions\customGroup\fn_addCustomGroupToPool.sqf"; };
    class openCustomGroupDialog { file = "configurationDialog\factions\customGroup\fn_openCustomGroupDialog.sqf"; };
    class populateVehiclesConfigTree { file = "configurationDialog\factions\customGroup\fn_populateVehiclesConfigTree.sqf"; };
    class addVehicleToGroup { file = "configurationDialog\factions\customGroup\fn_addVehicleToGroup.sqf"; };
    class removeVehicleFromGroup { file = "configurationDialog\factions\customGroup\fn_removeVehicleFromGroup.sqf"; };
}