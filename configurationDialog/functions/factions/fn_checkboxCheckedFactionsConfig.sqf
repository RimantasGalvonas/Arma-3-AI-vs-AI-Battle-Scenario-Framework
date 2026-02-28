#include "..\..\elementIds.hpp"

params ["_control", "_checked"];

_checked = _checked == 1;


private _selected = [] call Rimsiakas_fnc_getSelectedSpawnerAndPoolFactionsConfig;

private _selectedSpawnerData = (_selected get "spawner") get "data";


if (!isNil {_selected get "pool"}) exitWith {
    private _selectedPoolData = (_selected get "pool") get "data";

    switch (ctrlIDC _control) do
    {
        case FACTIONS_CONFIG_POOLVEHICLECREWGROUPING_IDC: {
            _selectedPoolData set ["vehicleCrewGrouping", _checked];
        };
    };
};


switch (ctrlIDC _control) do
{
};