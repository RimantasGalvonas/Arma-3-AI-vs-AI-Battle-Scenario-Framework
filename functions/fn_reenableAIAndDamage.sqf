params [["_units", nil]];

if (isNil "_units") then {
    _units = allUnits;
};

{
    private _unit = _x;

    {
        _unit forgetTarget _x; // Reset target knowledge acquired before mission start when on multiplyer
    } forEach (_unit targets [false, 0, [blufor, opfor, independent]]);

    _unit enableAI "all";
} forEach _units;

[_units] spawn {
    params ["_units"];

    sleep 5; // Gotta give them time to survive whatever physics insanity they're stuck in after spawnning


    {
        _x allowDamage true;
        (vehicle _x) allowDamage true;
    } forEach _units;
};