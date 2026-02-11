params ["_targetPos"];

private _maxFlankingDistance = 400;
private _minFlankingDistance = 200;

switch (toLower worldName) do
{
    case "altis";
    case "stratis";
    case "malden";
    case "gm_weferlingen_summer";
    case "sefrouramal": {
        _maxFlankingDistance = 500;
        _minFlankingDistance = 250;
    };
    case "vn_khe_sanh";
    case "cam_lao_nam";
    case "vn_the_bra";
    case "spe_normandy";
    case "spe_mortain";
    case "tanoa";
    case "enoch";
    case "stozec": {
        _maxFlankingDistance = 375;
        _minFlankingDistance = 175;
    };
};

if ([_targetPos] call Rimsiakas_fnc_isPositionInForest || {[_targetPos] call Rimsiakas_fnc_isPositionAmongBuildings}) then {
    _maxFlankingDistance = 250;
    _minFlankingDistance = 100;
};

[_minFlankingDistance, _maxFlankingDistance];