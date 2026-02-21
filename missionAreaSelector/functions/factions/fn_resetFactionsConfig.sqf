params [["_default", false]];

if (_default) exitWith {
    Rimsiakas_workingSpawnersData = +Rimsiakas_initialSpawnersData;

    [] call Rimsiakas_fnc_confirmFactionsConfig;
};

Rimsiakas_workingSpawnersData = +Rimsiakas_lastSavedSpawnersData;