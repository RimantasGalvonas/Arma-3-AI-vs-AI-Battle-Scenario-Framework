private _tooltip = "How strongly to illuminate the battlefield at night.\nAt current weather and date flares would be shot between:\n%1 and %2";
private _maxSolarElevation = [] call Rimsiakas_fnc_getMaximumSolarElevationForFlares;

private _sunRiseSunSetTimes = date call BIS_fnc_sunriseSunsetTime;

if (_sunRiseSunSetTimes select 0 == -1) then {
    _toolTip = "Polar night. Flares will be shot all night.";
};

if (_sunRiseSunSetTimes select 1 == -1) then {
    _toolTip = "Polar day. Flares will never be shot.";
};

private _lat = -getnumber (configfile >> "cfgworlds" >> worldname >> "latitude");
private _declination = 23.45 * sin (360/365 * (284 + (365 * datetonumber date)));
private _start = 12 + (1 / 15) * acos ((sin _maxSolarElevation - (sin _lat * sin _declination)) / (cos _lat * cos _declination));
private _end = 12 - (1 / 15) * acos ((sin _maxSolarElevation - (sin _lat * sin _declination)) / (cos _lat * cos _declination));


(displayCtrl 101502) ctrlSetTooltip (str parseText (format [_tooltip, [_start, "HH:MM"] call BIS_fnc_timeToString, [_end, "HH:MM"] call BIS_fnc_timeToString]));