if (!isNil "customIsDarkEnoughForFlaresFunction") exitWith {
    call customIsDarkEnoughForFlaresFunction; // Option to override this behavior by placing a Game Logic entity with a custom function in the editor.
};

private _lightLevel = getLighting select 1;

private _maxLight = 75;
private _minLight = 25;

switch (toLower worldName) do
{
    case "vn_khe_sanh";
    case "altis";
    case "stratis";
    case "malden";
    case "gm_weferlingen_summer";
    case "sefrouramal";
    case "tanoa": {
        _maxLight = 20;
        _minLight = 10;
    };
    case "cam_lao_nam";
    case "vn_the_bra";
    case "spe_normandy";
    case "spe_mortain";
    case "enoch";
    case "stozec": {
        _maxLight = 75;
        _minLight = 35;
    };
};

if (_lightLevel > _maxLight) exitWith {
    false;
};

private _chanceToEnableFlares = linearConversion [_maxLight, _minLight, _lightLevel, 0, 100, true];
_chanceToEnableFlares >= random 100;