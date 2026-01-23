params ["_action"];

private _resolution = patrolCenter getVariable ["intelGridResolution", 1];
_resolution = floor _resolution;

switch (_action) do
{
    case "down": {
        patrolCenter setVariable ["intelGridResolution", (_resolution - 1) max 1, true];
    };
    case "up": {
        patrolCenter setVariable ["intelGridResolution", (_resolution + 1) max 1, true];
    };
    default {};
};

call Rimsiakas_fnc_refreshIntelGridValue;