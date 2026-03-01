#include "..\..\elementIds.hpp"

[] spawn {
    waitUntil {!isNull findDisplay FACTIONS_CONFIG_IDD};

    private _spawners = entities "LOGIC" select {_x getVariable ["logicType", ""] == "spawner"};

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


    private _spawnersTree = displayCtrl FACTIONS_CONFIG_SPAWNERPOOLSTREE_IDC;

    Rimsiakas_lastSavedSpawnersData = createHashMap;
    private _collectedSpawners = createHashMap;
    Rimsiakas_lastSavedSpawnersData set ["spawners", _collectedSpawners];



    private _independentRelation = 0;

    if ([independent, west] call BIS_fnc_sideIsFriendly) then {
        _independentRelation = _independentRelation + 1;
    };

    if ([independent, east] call BIS_fnc_sideIsFriendly) then {
        _independentRelation = _independentRelation + 2;
    };

    _greenforAlliesField lbSetCurSel _independentRelation;

    Rimsiakas_lastSavedSpawnersData set ["independentRelation", _independentRelation];



    {
        private _spawner = _x;

        private _spawnerData = createHashMapFromArray [
            ["maxUnitsPerGroup", _spawner getVariable ["maxUnitsPerGroup", 0]],
            ["maxUnits", _spawner getVariable ["maxUnits", 0]],
            ["spawnRate", _spawner getVariable ["spawnRate", 0]],
            ["pools", _spawner getVariable ["pools", []]]
        ];

        _collectedSpawners set [str _spawner, _spawnerData];
    } forEach _spawners;

    Rimsiakas_workingSpawnersData = +Rimsiakas_lastSavedSpawnersData;

    if (isNil "Rimsiakas_initialSpawnersData") then {
        Rimsiakas_initialSpawnersData = +Rimsiakas_lastSavedSpawnersData;

        [] call Rimsiakas_fnc_generateDefaultFactionPreset;
    };



    [] call Rimsiakas_fnc_populateSpawnerTree;
    [] call Rimsiakas_fnc_populateFactionGroupsConfigTree;
};