private _patrolCenterData = createHashMap;

_patrolCenterData set ["pos", getPos patrolCenter];

private _variables = createHashMap;

{
    _variables set [_x, patrolCenter getVariable _x];
} forEach (allVariables patrolCenter);

_patrolCenterData set ["variables", _variables];

_patrolCenterData;