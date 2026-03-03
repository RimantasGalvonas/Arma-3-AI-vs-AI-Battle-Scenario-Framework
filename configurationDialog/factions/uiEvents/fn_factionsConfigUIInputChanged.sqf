#include "..\..\elementIds.hpp"

params ["_control", "_value"];

_value = parseNumber _value;

private _selected = [] call Rimsiakas_fnc_getSelectedSpawnerAndPool;

private _selectedSpawnerData = (_selected get "spawner") get "data";


if (!isNil {_selected get "pool"}) exitWith {
    private _selectedPoolData = (_selected get "pool") get "data";

    switch (ctrlIDC _control) do
    {
        case FACTIONS_CONFIG_SPAWNERPOOLWEIGHT_IDC: {
            _selectedPoolData set ["weight", _value];
        };
    };
};


switch (ctrlIDC _control) do
{
    case FACTIONS_CONFIG_MAXUNITSPERGROUP_IDC: {
        _selectedSpawnerData set ["maxUnitsPerGroup", _value];
    };
    case FACTIONS_CONFIG_MAXUNITS_IDC: {
        _selectedSpawnerData set ["maxUnits", _value];
    };
    case FACTIONS_CONFIG_SPAWNRATE_IDC: {
        _selectedSpawnerData set ["spawnRate", _value];
    };
};