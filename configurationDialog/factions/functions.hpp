class configurationDialogFactionConfig
{
    file = "configurationDialog\factions";

    class confirmFactionsConfig {};
    class getSelectedSpawnerAndPool {};
    class openFactionsConfig {};

    class addCustomGroupToPool { file = "configurationDialog\factions\customGroup\fn_addCustomGroupToPool.sqf"; };
    class addVehicleToGroup { file = "configurationDialog\factions\customGroup\fn_addVehicleToGroup.sqf"; };
    class openCustomGroupDialog { file = "configurationDialog\factions\customGroup\fn_openCustomGroupDialog.sqf"; };
    class populateVehiclesConfigTree { file = "configurationDialog\factions\customGroup\fn_populateVehiclesConfigTree.sqf"; };
    class removeVehicleFromGroup { file = "configurationDialog\factions\customGroup\fn_removeVehicleFromGroup.sqf"; };

    class addItemToAllowedItemsTree { file = "configurationDialog\factions\inventory\fn_addItemToAllowedItemsTree.sqf"; };
    class onInventoryAdjustmentItemTreeSelectionChange { file = "configurationDialog\factions\inventory\fn_onInventoryAdjustmentItemTreeSelectionChange.sqf"; };
    class openAllowedInventoryAdjustmentItemsDialog { file = "configurationDialog\factions\inventory\fn_openAllowedInventoryAdjustmentItemsDialog.sqf"; };
    class populateInventoryAdjustmentItemsTree { file = "configurationDialog\factions\inventory\fn_populateInventoryAdjustmentItemsTree.sqf"; };
    class removeItemFromAllowedItemsTree { file = "configurationDialog\factions\inventory\fn_removeItemFromAllowedItemsTree.sqf"; };

    class addGroupToPool { file = "configurationDialog\factions\pools\fn_addGroupToPool.sqf"; };
    class copyPoolGroups { file = "configurationDialog\factions\pools\fn_copyPoolGroups.sqf"; };
    class onGroupConfigTreeSelectionChange { file = "configurationDialog\factions\pools\fn_onGroupConfigTreeSelectionChange.sqf"; };
    class onPoolGroupListSelectionChange { file = "configurationDialog\factions\pools\fn_onPoolGroupListSelectionChange.sqf"; };
    class pasteGroupsIntoPool { file = "configurationDialog\factions\pools\fn_pasteGroupsIntoPool.sqf"; };
    class populateFactionGroupsConfigTree { file = "configurationDialog\factions\pools\fn_populateFactionGroupsConfigTree.sqf"; };
    class populatePoolGroupsList { file = "configurationDialog\factions\pools\fn_populatePoolGroupsList.sqf"; };
    class removeGroupFromPool { file = "configurationDialog\factions\pools\fn_removeGroupFromPool.sqf"; };

    class deleteFactionPreset { file = "configurationDialog\factions\presets\fn_deleteFactionPreset.sqf"; };
    class generateDefaultFactionPreset { file = "configurationDialog\factions\presets\fn_generateDefaultFactionPreset.sqf"; };
    class loadFactionPreset { file = "configurationDialog\factions\presets\fn_loadFactionPreset.sqf"; };
    class onPresetListSelectionChange { file = "configurationDialog\factions\presets\fn_onPresetListSelectionChange.sqf"; };
    class openFactionPresets { file = "configurationDialog\factions\presets\fn_openFactionPresets.sqf"; };
    class saveFactionPreset { file = "configurationDialog\factions\presets\fn_saveFactionPreset.sqf"; };

    class addPoolToSpawner { file = "configurationDialog\factions\spawners\fn_addPoolToSpawner.sqf"; };
    class clearAllPoolsInSpawner { file = "configurationDialog\factions\spawners\fn_clearAllPoolsInSpawner.sqf"; };
    class createMarkersForSpawners { file = "configurationDialog\factions\spawners\fn_createMarkersForSpawners.sqf"; };
    class onSpawnerPoolsTreeSelectionChange { file = "configurationDialog\factions\spawners\fn_onSpawnerPoolsTreeSelectionChange.sqf"; };
    class populateSpawnerTree { file = "configurationDialog\factions\spawners\fn_populateSpawnerTree.sqf"; };
    class removePoolFromSpawner { file = "configurationDialog\factions\spawners\fn_removePoolFromSpawner.sqf"; };

    class onFactionsConfigCheckboxCheck { file = "configurationDialog\factions\uiEvents\fn_onFactionsConfigCheckboxCheck.sqf"; };
    class onFactionsConfigTextInputChange { file = "configurationDialog\factions\uiEvents\fn_onFactionsConfigTextInputChange.sqf"; };
}