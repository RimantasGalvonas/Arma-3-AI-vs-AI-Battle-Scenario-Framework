#include "..\..\elementIds.hpp"

params ["_control", "_path"];

if (count _path == 0) exitWith {};

private _secondColumnFrame = displayCtrl FACTIONS_CONFIG_SECONDCOLUMNFRAME_IDC;
private _spawnerPropertiesControlGroup = displayCtrl FACTIONS_CONFIG_SPAWNERDETAILSCONTROLGROUP_IDC;
private _poolPropertiesControlGroup = displayCtrl FACTIONS_CONFIG_POOLDETAILSCONTROLGROUP_IDC;
private _groupsConfigControlGroup = displayCtrl FACTIONS_CONFIG_GROUPSCONFIGCONTROLGROUP_IDC;

private _selected = [] call Rimsiakas_fnc_getSelectedSpawnerAndPoolFactionsConfig;

if (isNil {_selected get "pool"}) then {
    private _spawnerData = (_selected get "spawner") get "data";
    private _maxUnitsPerGroupField = displayCtrl FACTIONS_CONFIG_MAXUNITSPERGROUP_IDC;
    private _maxUnitsField = displayCtrl FACTIONS_CONFIG_MAXUNITS_IDC;
    private _spawnRateField = displayCtrl FACTIONS_CONFIG_SPAWNRATE_IDC;

    private _maxUnitsPerGroup = _spawnerData getOrDefault ["maxUnitsPerGroup", []];
    private _maxUnits = _spawnerData getOrDefault ["maxUnits", []];
    private _spawnRate = _spawnerData getOrDefault ["spawnRate", []];

    _maxUnitsPerGroupField ctrlSetText (str _maxUnitsPerGroup);
    _maxUnitsField ctrlSetText (str _maxUnits);
    _spawnRateField ctrlSetText (str _spawnRate);

    _secondColumnFrame ctrlSetText "Spawner properties";
    _spawnerPropertiesControlGroup ctrlShow true;
    _poolPropertiesControlGroup ctrlShow false;
    _groupsConfigControlGroup ctrlShow false;
} else {
    private _poolWeightField = displayCtrl FACTIONS_CONFIG_SPAWNERPOOLWEIGHT_IDC;

    private _poolData = (_selected get "pool") get "data";

    [_poolData] call Rimsiakas_fnc_populatePoolGroupsFactionsConfig;

    private _weight = _poolData getOrdEfault ["weight", 0];
    _poolWeightField ctrlSetText (str _weight);

    _secondColumnFrame ctrlSetText "Groups pool properties";
    _poolPropertiesControlGroup ctrlShow true;
    _spawnerPropertiesControlGroup ctrlShow false;
    _groupsConfigControlGroup ctrlShow true;
};



{
    _x setMarkerColorLocal "colorRed"
} forEach Rimsiakas_markersForSpawners;

_markerName = "spawnerMarker" + ((_selected get "spawner") get "name");
_markerName setMarkerColorLocal "colorBlue";

_map = displayCtrl FACTIONS_CONFIG_MAP_IDC;
_map ctrlMapAnimAdd [1, 0.5, getMarkerPos _markerName];

ctrlMapAnimCommit _map;
