params ["_vehicle"];

private _originalSpawnVelocity = _vehicle getVariable "Rimsiakas_originalSpawnVelocity";
private _originalSpawnHeight = _vehicle getVariable "Rimsiakas_originalSpawnHeight";

if (!isNil "_originalSpawnHeight") then {
    private _pos = getPos _vehicle;
    _pos set [2, _originalSpawnHeight];
    _vehicle setPos _pos;
};

sleep 0.1;

if (!isNil "_originalSpawnVelocity") then {
    _vehicle setVelocityModelSpace _originalSpawnVelocity;
};