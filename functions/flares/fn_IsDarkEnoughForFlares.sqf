if (!isNil "customIsDarkEnoughForFlaresFunction") exitWith {
	[] call customIsDarkEnoughForFlaresFunction; // Option to override this behavior by placing a Game Logic entity with a custom function in the editor.
};

private _lat = -getnumber (configfile >> "cfgworlds" >> worldname >> "latitude");
private _declination = 23.45 * sin (360/365 * (284 + (365 * datetonumber date)));
private _hourAngle = 15 * (dayTime - 12);
private _solarElevation = asin ((sin _lat * sin _declination) + (cos _lat * cos _declination * cos _hourAngle));

private _maximumSolarElevation = [] call Rimsiakas_fnc_getMaximumSolarElevationForFlares;

_solarElevation < _maximumSolarElevation;