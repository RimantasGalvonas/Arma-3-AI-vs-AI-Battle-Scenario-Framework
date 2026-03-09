params [["_data", nil]];

if (isNil "_data") then {
    _data = Rimsiakas_workingSpawnersData;
};



if (!isServer) then {
    [_data] remoteExec ["Rimsiakas_fnc_confirmFactionsConfig"];
};



{
    private _spawner = missionNamespace getVariable _x;

    _spawner setVariable ["maxUnitsPerGroup",_y get "maxUnitsPerGroup"];
    _spawner setVariable ["maxUnits", _y get "maxUnits"];
    _spawner setVariable ["spawnRate", _y get "spawnRate"];
    _spawner setVariable ["pools", _y get "pools"];
    _spawner setVariable ["inventoryAdjustments", _y get "inventoryAdjustments"];

    publicVariableServer _x;
} forEach (_data get "spawners");



independent setFriend [blufor, 0];
independent setFriend [opfor, 0];
blufor setFriend [independent, 0];
opfor setFriend [independent, 0];

switch (_data get "independentRelation") do
{
    case 1: {
        independent setFriend [blufor, 1];
        blufor setFriend [independent, 1];
    };
    case 2: {
        independent setFriend [opfor, 1];
        opfor setFriend [independent, 1];
    };
    case 3: {
        independent setFriend [blufor, 1];
        independent setFriend [opfor, 1];
        blufor setFriend [independent, 1];
        opfor setFriend [independent, 1];
    };
};