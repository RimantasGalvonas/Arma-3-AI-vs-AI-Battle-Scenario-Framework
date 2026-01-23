[] spawn {
    waitUntil {!isNull findDisplay 46421};

    private _resolution = patrolCenter getVariable ["intelGridResolution", 1];
    _resolution = floor _resolution;

    if (_resolution <= 1) exitWith {
        ctrlSetText [101003, "Disabled"];
    };

    ctrlSetText [101003, (str _resolution) + " x " + (str _resolution)];
};

