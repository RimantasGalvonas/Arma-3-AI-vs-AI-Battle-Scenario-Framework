params ["_group", ["_combatModeTime", 15]];

private _originalBehaviour = behaviour (leader _group);

if (leader _group == player || {_group getVariable ["hasTemporaryCombatMode", false] || {_originalBehaviour in ["COMBAT", "STEALTH"]}}) exitWith {};

[_group, _originalBehaviour, _combatModeTime] spawn {
    params ["_group", "_originalBehaviour", "_combatModeTime"];

    _group setVariable ["hasTemporaryCombatMode", true];

    _group setBehaviour "COMBAT";

    private _lastKnownTargetPos = _group getVariable ["lastReportedTargetPosition", nil];
    if (!isNil "_lastKnownTargetPos") then {
        _group setFormDir ((leader _group) getDir _lastKnownTargetPos);
    };

    sleep _combatModeTime;

    _group setBehaviour _originalBehaviour;
    _group setVariable ["hasTemporaryCombatMode", false];
};