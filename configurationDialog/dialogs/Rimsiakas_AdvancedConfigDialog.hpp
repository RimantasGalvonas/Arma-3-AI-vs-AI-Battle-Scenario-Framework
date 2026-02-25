#define RIGHT_SIDE_X (31)
#define PATROL_RADIUS_ELEMENTS_Y (2.5)
#define INTEL_RESPONSE_ELEMENTS_Y (6.5)

class Rimsiakas_AdvancedConfigDialog
{
    idd = ADVANCED_CONFIG_DIALOG_IDD;
    movingEnabled = false;
    enableSimulation = true;

    controlsBackground[]=
    {
        Rimsiakas_AdvancedConfigDialog_MainBackground,
        Rimsiakas_AdvancedConfigDialog_Heading,
        Rimsiakas_AdvancedConfigDialog_PatrolRadiusFrame,
        Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceFrame
    };

    controls[]=
    {
        Rimsiakas_AdvancedConfigDialog_BackButton,
        Rimsiakas_AdvancedConfigDialog_Map,
        Rimsiakas_AdvancedConfigDialog_RotateCCW,
        Rimsiakas_AdvancedConfigDialog_RotateCW,
        Rimsiakas_AdvancedConfigDialog_ScaleDown,
        Rimsiakas_AdvancedConfigDialog_ScaleUp,
        Rimsiakas_AdvancedConfigDialog_PatrolRadiusLabel,
        Rimsiakas_AdvancedConfigDialog_PatrolRadiusValue,
        Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceLabel,
        Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceInfantryLabel,
        Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceInfantryValue,
        Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceVehiclesLabel,
        Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceVehiclesValue,
        Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceAirLabel,
        Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceAirValue,
        Rimsiakas_AdvancedConfigDialog_ApplyParamsBtn
    };

    class Rimsiakas_AdvancedConfigDialog_MainBackground: Rimsiakas_MainBackground
    {
         idc = ADVANCED_CONFIG_DIALOG_MAINBACKGROUND_IDC;
    };

    class Rimsiakas_AdvancedConfigDialog_Heading: Rimsiakas_Heading
    {
        idc = ADVANCED_CONFIG_DIALOG_HEADING_IDC;
        text = "Advanced configuration";
    };

    class Rimsiakas_AdvancedConfigDialog_Map: RscMapControl
    {
        idc = ADVANCED_CONFIG_DIALOG_MAP_IDC;
        x = 0.5 * GUI_GRID_W + GUI_GRID_X;
        y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 30 * GUI_GRID_W;
        h = 20 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_PatrolRadiusFrame: RscFrame
    {
        idc =ADVANCED_CONFIG_DIALOG_PATROLRADIUSFRAME_IDC;
        x = RIGHT_SIDE_X * GUI_GRID_W + GUI_GRID_X;
        y = PATROL_RADIUS_ELEMENTS_Y * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 3 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_PatrolRadiusLabel: RscText
    {
        idc = ADVANCED_CONFIG_DIALOG_PATROLRADIUSLABEL_IDC;
        text = "Patrol Radius:";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (0.5 + PATROL_RADIUS_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_PatrolRadiusValue: RscText
    {
        idc = ADVANCED_CONFIG_DIALOG_PATROLRADIUSVALUE_IDC;
        x = (1 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (1.5 + PATROL_RADIUS_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 6.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceFrame: RscFrame
    {
        idc = ADVANCED_CONFIG_DIALOG_INTELRESPONSEDISTANCEFRAME_IDC;
        x = 31 * GUI_GRID_W + GUI_GRID_X;
        y = INTEL_RESPONSE_ELEMENTS_Y * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 16 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceLabel: RscText
    {
        idc = ADVANCED_CONFIG_DIALOG_INTELRESPONSEDISTANCELABEL_IDC;
        text = "Intel Response Dist.";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (0.5 + INTEL_RESPONSE_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceInfantryLabel: RscText
    {
        idc = ADVANCED_CONFIG_DIALOG_INTELRESPONSEDISTANCEINFANTRYLABEL_IDC;
        text = "Infantry";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (2 + INTEL_RESPONSE_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceInfantryValue: RscEdit
    {
        idc = ADVANCED_CONFIG_DIALOG_INTELRESPONSEDISTANCEINFANTRYVALUE_IDC;
        x = (1 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (3 + INTEL_RESPONSE_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 6.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        tooltip = "Maximum distance to target at which infantry groups will respond to intel about the enemy location.";
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceVehiclesLabel: RscText
    {
        idc = ADVANCED_CONFIG_DIALOG_INTELRESPONSEDISTANCEVEHICLESLABEL_IDC;
        text = "Vehicles";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (4.5 + INTEL_RESPONSE_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceVehiclesValue: RscEdit
    {
        idc = ADVANCED_CONFIG_DIALOG_INTELRESPONSEDISTANCEVEHICLESVALUE_IDC;
        x = (1 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (5.5 + INTEL_RESPONSE_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 6.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        tooltip = "Maximum distance to target at which mounted groups will respond to intel about the enemy location.";
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceAirLabel: RscText
    {
        idc = ADVANCED_CONFIG_DIALOG_INTELRESPONSEDISTANCEAIRLABEL_IDC;
        text = "Air";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (7 + INTEL_RESPONSE_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceAirValue: RscEdit
    {
        idc = ADVANCED_CONFIG_DIALOG_INTELRESPONSEDISTANCEAIRVALUE_IDC;
        x = (1 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (8 + INTEL_RESPONSE_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 6.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        tooltip = "Maximum distance to target at which air assets will respond to intel about the enemy location.";
    };

    class Rimsiakas_AdvancedConfigDialog_ApplyParamsBtn: Rimsiakas_Button
    {
        idc = ADVANCED_CONFIG_DIALOG_APPLYPARAMSBTN_IDC;
        action = "call Rimsiakas_fnc_confirmAdvancedParams;";
        text = "Apply";
        x = (1 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (13.5 + INTEL_RESPONSE_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 6.5 * GUI_GRID_W;
        tooltip = "Apply the input field values.";
    };

    class Rimsiakas_AdvancedConfigDialog_BottomButton: Rimsiakas_Button
    {
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
    }

    class Rimsiakas_AdvancedConfigDialog_BackButton: Rimsiakas_AdvancedConfigDialog_BottomButton
    {
        idc = ADVANCED_CONFIG_DIALOG_BACKBUTTON_IDC;
        action = "closeDialog 1;";
        text = "Back";
        x = 0.5 * GUI_GRID_W + GUI_GRID_X;
    };

    class Rimsiakas_AdvancedConfigDialog_RotateCCW: Rimsiakas_AdvancedConfigDialog_BottomButton
    {
        idc = ADVANCED_CONFIG_DIALOG_ROTATECCW_IDC;
        action = "['rotate_ccw'] remoteExecCall ['Rimsiakas_fnc_handleTransformButton', 2];";
        text = "Rotate CCW";
        x = 6.5 * GUI_GRID_W + GUI_GRID_X;
    };

    class Rimsiakas_AdvancedConfigDialog_RotateCW: Rimsiakas_AdvancedConfigDialog_BottomButton
    {
        idc = ADVANCED_CONFIG_DIALOG_ROTATECW_IDC;
        action = "['rotate_cw'] remoteExecCall ['Rimsiakas_fnc_handleTransformButton', 2];";
        text = "Rotate CW";
        x = 12.5 * GUI_GRID_W + GUI_GRID_X;
    };

    class Rimsiakas_AdvancedConfigDialog_ScaleDown: Rimsiakas_AdvancedConfigDialog_BottomButton
    {
        idc = ADVANCED_CONFIG_DIALOG_SCALEDOWN_IDC;
        action = "['scale_down'] remoteExecCall ['Rimsiakas_fnc_handleTransformButton', 2];";
        text = "Scale-";
        x = 18.5 * GUI_GRID_W + GUI_GRID_X;
    };

    class Rimsiakas_AdvancedConfigDialog_ScaleUp: Rimsiakas_AdvancedConfigDialog_BottomButton
    {
        idc = ADVANCED_CONFIG_DIALOG_SCALEUP_IDC;
        action = "['scale_up'] remoteExecCall ['Rimsiakas_fnc_handleTransformButton', 2];";
        text = "Scale+";
        x = 24.5 * GUI_GRID_W + GUI_GRID_X;
    };
}
