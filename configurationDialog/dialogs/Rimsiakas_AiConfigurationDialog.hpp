class Rimsiakas_AiConfigurationDialog
{
    idd = AI_CONFIG_DIALOG_IDD;
    movingEnabled = false;
    enableSimulation = true;

    onLoad = "call Rimsiakas_fnc_populateAiConfigFields";

    controlsBackground[]=
    {
        Rimsiakas_AiConfigurationDialog_Background,
        Rimsiakas_AiConfigurationDialog_PatrolFormationLabel,
        Rimsiakas_AiConfigurationDialog_AttackFormationLabel,
        Rimsiakas_AiConfigurationDialog_MovementSpeedModeLabel,
        Rimsiakas_AiConfigurationDialog_AttackSpeedOverrideLabel,
        Rimsiakas_AiConfigurationDialog_AllowGroupJoiningLabel,
        Rimsiakas_AiConfigurationDialog_ForceKeepFormationLabel
    };

    controls[]=
    {
        Rimsiakas_AiConfigurationDialog_PatrolFormation,
        Rimsiakas_AiConfigurationDialog_AttackFormation,
        Rimsiakas_AiConfigurationDialog_MovementSpeedMode,
        Rimsiakas_AiConfigurationDialog_AttackSpeedOverride,
        Rimsiakas_AiConfigurationDialog_AllowGroupJoining,
        Rimsiakas_AiConfigurationDialog_ForceKeepFormation,
        Rimsiakas_AiConfigurationDialog_ConfirmButton
    };

    class Rimsiakas_AiConfigurationDialog_Background: RscText
    {
        idc = AI_CONFIG_DIALOG_BACKGROUND_IDC;
        x = 9.5 * GUI_GRID_W + GUI_GRID_X;
        y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 19.5 * GUI_GRID_W;
        h = 18.5 * GUI_GRID_H;
        colorBackground[] = {0.15,0.15,0.15,0.9};
    };

    class Rimsiakas_AiConfigurationDialog_PatrolFormationLabel: RscText
    {
        idc = AI_CONFIG_DIALOG_PATROLFORMATIONLABEL_IDC;
        text = "Patrol formation:";
        x = 10 * GUI_GRID_W + GUI_GRID_X;
        y = 1 * GUI_GRID_H + GUI_GRID_Y;
        w = 10 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_AiConfigurationDialog_Formation: RscCombo
    {
        w = 18.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;

        class Items
        {
            class Column
            {
                text = "Column";
                data = "COLUMN";
                default = 0;
            };
            class StaggeredColumn
            {
                text = "Staggered Column";
                data = "STAG COLUMN";
                default = 0;
            };
            class Wedge
            {
                text = "Wedge";
                data = "WEDGE";
                default = 1;
            };
            class EchelonLeft
            {
                text = "Echelon Left";
                data = "ECH LEFT";
                default = 0;
            };
            class EchelonRight
            {
                text = "Echelon Right";
                data = "ECH RIGHT";
                default = 0;
            };
            class Vee
            {
                text = "Vee";
                data = "VEE";
                default = 0;
            };
            class Line
            {
                text = "Line";
                data = "LINE";
                default = 0;
            };
            class File
            {
                text = "File";
                data = "FILE";
                default = 0;
            };
            class Diamond
            {
                text = "Diamond";
                data = "DIAMOND";
                default = 0;
            };
        };
    }

    class Rimsiakas_AiConfigurationDialog_PatrolFormation: Rimsiakas_AiConfigurationDialog_Formation
    {
        idc = AI_CONFIG_DIALOG_PATROLFORMATION_IDC;
        x = 10 * GUI_GRID_W + GUI_GRID_X;
        y = 2 * GUI_GRID_H + GUI_GRID_Y;
        tooltip = "Group will use this formation while looking for targets or while moving towards their target";
    };

    class Rimsiakas_AiConfigurationDialog_AttackFormationLabel: RscText
    {
        idc = AI_CONFIG_DIALOG_ATTACKFORMATIONLABEL_IDC;
        text = "Attack formation:";
        x = 10 * GUI_GRID_W + GUI_GRID_X;
        y = 4 * GUI_GRID_H + GUI_GRID_Y;
        w = 10 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_AiConfigurationDialog_AttackFormation: Rimsiakas_AiConfigurationDialog_Formation
    {
        idc = AI_CONFIG_DIALOG_ATTACKFORMATION_IDC;
        x = 10 * GUI_GRID_W + GUI_GRID_X;
        y = 5 * GUI_GRID_H + GUI_GRID_Y;
        tooltip = "Group will switch to this formation when within engagement distance to their target";
    };

    class Rimsiakas_AiConfigurationDialog_MovementSpeedModeLabel: RscText
    {
        idc = AI_CONFIG_DIALOG_MOVEMENTSPEEDMODELABEL_IDC;
        text = "Group movement speed:";
        x = 10 * GUI_GRID_W + GUI_GRID_X;
        y = 7 * GUI_GRID_H + GUI_GRID_Y;
        w = 10 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_AiConfigurationDialog_MovementSpeedMode: RscCombo
    {
        idc = AI_CONFIG_DIALOG_MOVEMENTSPEEDMODE_IDC;
        x = 10 * GUI_GRID_W + GUI_GRID_X;
        y = 8 * GUI_GRID_H + GUI_GRID_Y;
        w = 18.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;

        class Items
        {
            class Normal
            {
                text = "Normal";
                data = "NORMAL";
                default = 1;
            };
            class Smart
            {
                text = "Smart";
                data = "SMART";
                tooltip = "Slow in cover, fast in open areas";
                default = 0;
            };
            class Slow
            {
                text = "Slow";
                data = "SLOW";
                default = 0;
            };
        };
    };

    class Rimsiakas_AiConfigurationDialog_AttackSpeedOverrideLabel: RscText
    {
        idc = AI_CONFIG_DIALOG_ATTACKSPEEDOVERRIDELABEL_IDC;
        text = "Force normal attack speed:";
        x = 10 * GUI_GRID_W + GUI_GRID_X;
        y = 10 * GUI_GRID_H + GUI_GRID_Y;
        w = 10 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_AiConfigurationDialog_AttackSpeedOverride: RscCheckBox
    {
        idc = AI_CONFIG_DIALOG_ATTACKSPEEDOVERRIDE_IDC;
        x = 19.5 * GUI_GRID_W + GUI_GRID_X;
        y = 10 * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        tooltip = "Switch to Normal speed mode as soon as a target is assigned.";
        checked = 0;
    };

    class Rimsiakas_AiConfigurationDialog_AllowGroupJoiningLabel: RscText
    {
        idc = AI_CONFIG_DIALOG_ALLOWGROUPJOININGLABEL_IDC;
        text = "Allow last man to join new group:";
        x = 10 * GUI_GRID_W + GUI_GRID_X;
        y = 12 * GUI_GRID_H + GUI_GRID_Y;
        w = 12 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_AiConfigurationDialog_AllowGroupJoining: RscCheckBox
    {
        idc = AI_CONFIG_DIALOG_ALLOWGROUPJOINING_IDC;
        x = 21.5 * GUI_GRID_W + GUI_GRID_X;
        y = 12 * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        tooltip = "Allow the last surviving AI unit to join a new group, if there is one nearby.";
        checked = 0;
    };

    class Rimsiakas_AiConfigurationDialog_ForceKeepFormationLabel: RscText
    {
        idc = AI_CONFIG_DIALOG_FORCEKEEPFORMATIONLABEL_IDC;
        text = "Force keeping formation:";
        x = 10 * GUI_GRID_W + GUI_GRID_X;
        y = 14 * GUI_GRID_H + GUI_GRID_Y;
        w = 12 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_AiConfigurationDialog_ForceKeepFormation: RscCheckBox
    {
        idc = AI_CONFIG_DIALOG_FORCEKEEPFORMATION_IDC;
        x = 19 * GUI_GRID_W + GUI_GRID_X;
        y = 14 * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        tooltip = "Prevent units from leaving the formation to engage targets.";
        checked = 0;
    };

    class Rimsiakas_AiConfigurationDialog_ConfirmButton: RscButton
    {
        idc = AI_CONFIG_DIALOG_CONFIRMBUTTON_IDC;
        text = "Confirm";
        action = "call Rimsiakas_fnc_confirmAiConfig";

        x = 10.5 * GUI_GRID_W + GUI_GRID_X;
        y = 16.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 5 * GUI_GRID_W;
        h = 1.5 * GUI_GRID_H;
    };
}
