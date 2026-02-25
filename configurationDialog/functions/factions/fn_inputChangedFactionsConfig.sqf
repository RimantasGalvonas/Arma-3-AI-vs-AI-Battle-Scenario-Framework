params ["_control", "_value"];

_value = parseNumber _value;

private _selected = [] call Rimsiakas_fnc_getSelectedSpawnerAndPoolFactionsConfig;

private _selectedSpawnerData = (_selected get "spawner") get "data";


if (!isNil {_selected get "pool"}) exitWith {
    private _selectedPoolData = (_selected get "pool") get "data";

    switch (ctrlClassName _control) do
    {
        case "Rimsiakas_FactionsConfigDialog_SpawnerPoolWeight": {
            _selectedPoolData set ["weight", _value];
        };
    };
};


switch (ctrlClassName _control) do
{
    case "Rimsiakas_FactionsConfigDialog_MaxUnitsPerGroup": {
        _selectedSpawnerData set ["maxUnitsPerGroup", _value];
    };
    case "Rimsiakas_FactionsConfigDialog_MaxUnits": {
        _selectedSpawnerData set ["maxUnits", _value];
    };
    case "Rimsiakas_FactionsConfigDialog_SpawnRate": {
        _selectedSpawnerData set ["spawnRate", _value];
    };
};