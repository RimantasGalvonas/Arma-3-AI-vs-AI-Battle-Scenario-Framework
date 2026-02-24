_getIncompleteParts = {
    private _placers = [];
    private _hasProperlyConfiguredPlacers = false;
    private _incompleteParts = ["Mission Area Setup"];



    if (isNil "patrolCenter" || {isNil {patrolCenter getVariable "patrolRadius"}}) exitWith {
        _incompleteParts;
    };

    _incompleteParts deleteAt 0;



    _incompleteParts;
};


_incompleteParts = call _getIncompleteParts;



_allHints = [];

if ((count _incompleteParts) > 0) then {
    _incompleteSetupLines = [];
    _incompleteSetupLines append [parseText "You have successfully installed the template but the mission setup is incomplete."];
    _incompleteSetupLines append [parseText "Go to <a colorLink='#095EEA' href='https://github.com/RimantasGalvonas/Arma-3-AI-vs-AI-Battle-Scenario-Template#mission-setup'>https://github.com/RimantasGalvonas/Arma-3-AI-vs-AI-Battle-Scenario-Template#mission-setup</a> for instructions."];
    _incompletePartsString = _incompleteParts joinString "<br/>";
    _incompleteSetupLines append [parseText ("These mandatory steps from the instructions still need completing or were done incorrectly:<br/><br/>" + _incompletePartsString)];
    _allHints append [["Mission Setup", _incompleteSetupLines]];
};

_allHints;