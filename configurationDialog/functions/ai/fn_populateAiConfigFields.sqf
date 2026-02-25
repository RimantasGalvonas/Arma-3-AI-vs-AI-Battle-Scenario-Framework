#include "..\..\elementIds.hpp"

[] spawn {
    waitUntil {!isNull findDisplay AI_CONFIG_DIALOG_IDD};

    private _formationHashMap = createHashMapFromArray [
        ["COLUMN", 0],
        ["STAG COLUMN", 1],
        ["WEDGE", 2],
        ["ECH LEFT", 3],
        ["ECH RIGHT", 4],
        ["VEE", 5],
        ["LINE", 6],
        ["FILE", 7],
        ["DIAMOND", 8]
    ];

    private _patrolFormation = patrolCenter getVariable ["aiConfigPatrolFormation", "WEDGE"];
    lbSetCurSel [AI_CONFIG_DIALOG_PATROLFORMATION_IDC, _formationHashMap get _patrolFormation];

    private _attackFormation = patrolCenter getVariable ["aiConfigAttackFormation", "WEDGE"];
    lbSetCurSel [AI_CONFIG_DIALOG_ATTACKFORMATION_IDC, _formationHashMap get _attackFormation];


    private _speedHashMap = createHashMapFromArray [
        ["NORMAL", 0],
        ["SMART", 1],
        ["SLOW", 2]
    ];

    private _speedMode = patrolCenter getVariable ["aiConfigSpeedMode", "NORMAL"];
    lbSetCurSel [AI_CONFIG_DIALOG_MOVEMENTSPEEDMODE_IDC, _speedHashMap get _speedMode];

    private _attackSpeedOverride = patrolCenter getVariable ["aiConfigAttackSpeedOverride", false];
    (displayCtrl AI_CONFIG_DIALOG_ATTACKSPEEDOVERRIDE_IDC) cbSetChecked _attackSpeedOverride;

    private _allowJoinGroup = patrolCenter getVariable ["aiConfigAllowLastManToJoinNewGroup", false];
    (displayCtrl AI_CONFIG_DIALOG_ALLOWGROUPJOINING_IDC) cbSetChecked _allowJoinGroup;

    private _forceFormation = patrolCenter getVariable ["aiConfigForceFormation", false];
    (displayCtrl AI_CONFIG_DIALOG_FORCEKEEPFORMATION_IDC) cbSetChecked _forceFormation;
};