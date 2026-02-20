params [["_units", nil]];

if (isNil "_units") then {
    _units = allUnits;
};

{
    private _unit = _x;

    {
        _unit forgetTarget _x; // Reset target knowledge acquired before mission start when on multiplyer
    } forEach (_unit targets [false, 0, [blufor, opfor, independent]]);

    _unit enableAI "all"; // Re-enable AI disabled by disableAIWhileLoading function
} forEach _units;