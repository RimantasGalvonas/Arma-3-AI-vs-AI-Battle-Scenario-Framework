#include "..\elementIds.hpp"

[] spawn {
    waitUntil {!isNull findDisplay FACTIONS_CONFIG_IDD};

    private _spawnerPropertiesControlGroup = displayCtrl FACTIONS_CONFIG_SPAWNERDETAILSCONTROLGROUP_IDC;
    private _poolPropertiesControlGroup = displayCtrl FACTIONS_CONFIG_POOLDETAILSCONTROLGROUP_IDC;
    private _groupsConfigControlGroup = displayCtrl FACTIONS_CONFIG_GROUPSCONFIGCONTROLGROUP_IDC;
    private _addGroupButton = displayCtrl FACTIONS_CONFIG_ADDGROUPBUTTON_IDC;
    private _greenforAlliesField = displayCtrl FACTIONS_CONFIG_GREENFORALLIES_IDC;
    _spawnerPropertiesControlGroup ctrlShow false;
    _poolPropertiesControlGroup ctrlShow false;
    _groupsConfigControlGroup ctrlShow false;
    _addGroupButton ctrlEnable false;



    _map = displayCtrl FACTIONS_CONFIG_MAP_IDC;
    _map ctrlMapAnimAdd [0, 0.5, getMarkerPos "missionAreaMarker"];
    ctrlMapAnimCommit _map;
    [] call Rimsiakas_fnc_createMarkersForSpawners;

    [] spawn {
        waitUntil {isNull findDisplay FACTIONS_CONFIG_IDD};
        {
            deleteMarkerLocal _x
        } forEach Rimsiakas_markersForSpawners;
    };

    [] call Rimsiakas_fnc_collectFactionsData;

    _independentRelation = Rimsiakas_lastSavedFactionsData get "independentRelation";
    _greenforAlliesField lbSetCurSel _independentRelation;



    [] call Rimsiakas_fnc_populateSpawnerTree;
    [] call Rimsiakas_fnc_populateFactionGroupsConfigTree;
};