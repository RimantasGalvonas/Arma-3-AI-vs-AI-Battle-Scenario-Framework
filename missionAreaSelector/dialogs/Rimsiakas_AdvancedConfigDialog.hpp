class Rimsiakas_AdvancedConfigDialog
{
    idd = 46424;
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
         idc = 200000;
    };

    class Rimsiakas_AdvancedConfigDialog_Heading: Rimsiakas_Heading
    {
        idc = 200001;
        text = "Advanced configuration";
    };

    class Rimsiakas_AdvancedConfigDialog_Map: RscMapControl
    {
        idc = 9999;
        x = 0.5 * GUI_GRID_W + GUI_GRID_X;
        y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 30 * GUI_GRID_W;
        h = 20 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_PatrolRadiusFrame: RscFrame
    {
        idc = 201000;
        x = 31 * GUI_GRID_W + GUI_GRID_X;
        y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 3 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_PatrolRadiusLabel: RscText
    {
        idc = 201001;
        text = "Patrol Radius:";
        x = 31.5 * GUI_GRID_W + GUI_GRID_X;
        y = 3 * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_PatrolRadiusValue: RscText
    {
        idc = 201002;
        x = 32 * GUI_GRID_W + GUI_GRID_X;
        y = 4 * GUI_GRID_H + GUI_GRID_Y;
        w = 6.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceFrame: RscFrame
    {
        idc = 202000;
        x = 31 * GUI_GRID_W + GUI_GRID_X;
        y = 6.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 16 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceLabel: RscText
    {
        idc = 202001;
        text = "Intel Response Dist.";
        x = 31.5 * GUI_GRID_W + GUI_GRID_X;
        y = 7 * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceInfantryLabel: RscText
    {
        idc = 202002;
        text = "Infantry";
        x = 31.5 * GUI_GRID_W + GUI_GRID_X;
        y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceInfantryValue: RscEdit
    {
        idc = 202003;
        x = 32 * GUI_GRID_W + GUI_GRID_X;
        y = 9.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 6.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        tooltip = "Maximum distance to target at which infantry groups will respond to intel about the enemy location.";
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceVehiclesLabel: RscText
    {
        idc = 202004;
        text = "Vehicles";
        x = 31.5 * GUI_GRID_W + GUI_GRID_X;
        y = 11 * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceVehiclesValue: RscEdit
    {
        idc = 202005;
        x = 32 * GUI_GRID_W + GUI_GRID_X;
        y = 12 * GUI_GRID_H + GUI_GRID_Y;
        w = 6.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        tooltip = "Maximum distance to target at which mounted groups will respond to intel about the enemy location.";
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceAirLabel: RscText
    {
        idc = 202006;
        text = "Air";
        x = 31.5 * GUI_GRID_W + GUI_GRID_X;
        y = 13.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_AdvancedConfigDialog_IntelResponseDistanceAirValue: RscEdit
    {
        idc = 202007;
        x = 32 * GUI_GRID_W + GUI_GRID_X;
        y = 14.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 6.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        tooltip = "Maximum distance to target at which air assets will respond to intel about the enemy location.";
    };

    class Rimsiakas_AdvancedConfigDialog_ApplyParamsBtn: Rimsiakas_Button
    {
        idc = 202099;
        action = "call Rimsiakas_fnc_confirmAdvancedParams;";
        text = "Apply";
        x = 32 * GUI_GRID_W + GUI_GRID_X;
        y = 20 * GUI_GRID_H + GUI_GRID_Y;
        w = 6.5 * GUI_GRID_W;
        tooltip = "Apply the input field values.";
    };

    class Rimsiakas_AdvancedConfigDialog_BottomButton: Rimsiakas_Button
    {
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
        w = 5.5 * GUI_GRID_W;
    }

    class Rimsiakas_AdvancedConfigDialog_BackButton: Rimsiakas_AdvancedConfigDialog_BottomButton
    {
        idc = 209000;
        action = "closeDialog 1;";
        text = "Back";
        x = 0.5 * GUI_GRID_W + GUI_GRID_X;
    };

    class Rimsiakas_AdvancedConfigDialog_RotateCCW: Rimsiakas_AdvancedConfigDialog_BottomButton
    {
        idc = 209001;
        action = "['rotate_ccw'] remoteExecCall ['Rimsiakas_fnc_handleTransformButton', 2];";
        text = "Rotate CCW";
        x = 6.5 * GUI_GRID_W + GUI_GRID_X;
    };

    class Rimsiakas_AdvancedConfigDialog_RotateCW: Rimsiakas_AdvancedConfigDialog_BottomButton
    {
        idc = 209002;
        action = "['rotate_cw'] remoteExecCall ['Rimsiakas_fnc_handleTransformButton', 2];";
        text = "Rotate CW";
        x = 12.5 * GUI_GRID_W + GUI_GRID_X;
    };

    class Rimsiakas_AdvancedConfigDialog_ScaleDown: Rimsiakas_AdvancedConfigDialog_BottomButton
    {
        idc = 209003;
        action = "['scale_down'] remoteExecCall ['Rimsiakas_fnc_handleTransformButton', 2];";
        text = "Scale-";
        x = 18.5 * GUI_GRID_W + GUI_GRID_X;
    };

    class Rimsiakas_AdvancedConfigDialog_ScaleUp: Rimsiakas_AdvancedConfigDialog_BottomButton
    {
        idc = 209004;
        action = "['scale_up'] remoteExecCall ['Rimsiakas_fnc_handleTransformButton', 2];";
        text = "Scale+";
        x = 24.5 * GUI_GRID_W + GUI_GRID_X;
    };
}
