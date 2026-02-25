#define RIGHT_SIDE_X (31)
#define INTEL_GRID_ELEMENTS_Y (2.5)
#define FLARE_ELEMENTS_Y (7)
#define ENVIRONMENT_ELEMENTS_Y (11.5)

class Rimsiakas_MainConfigDialog
{
    idd = 46421;
    movingEnabled = false;
    enableSimulation = true;
    onLoad = "call Rimsiakas_fnc_populateEnvConfigFields; call Rimsiakas_fnc_refreshIntelGridValue";

    controlsBackground[]=
    {
        Rimsiakas_MainConfigDialog_MainBackground,
        Rimsiakas_MainConfigDialog_Heading,
        Rimsiakas_MainConfigDialog_Intel_GridFrame,
        Rimsiakas_MainConfigDialog_Intel_GridLabel,
        Rimsiakas_MainConfigDialog_Intel_GridValue,
        Rimsiakas_MainConfigDialog_Flare_Frame,
        Rimsiakas_MainConfigDialog_Flare_Label,
        Rimsiakas_MainConfigDialog_Env_Frame,
        Rimsiakas_MainConfigDialog_Env_DateLabel,
        Rimsiakas_MainConfigDialog_Env_DateSeparator1,
        Rimsiakas_MainConfigDialog_Env_DateSeparator2,
        Rimsiakas_MainConfigDialog_Env_TimeLabel,
        Rimsiakas_MainConfigDialog_Env_TimeSeparator,
        Rimsiakas_MainConfigDialog_Env_OvercastLabel,
        Rimsiakas_MainConfigDialog_Env_FogLabel
    };
    controls[]=
    {
        Rimsiakas_MainConfigDialog_ConfirmButton,
        Rimsiakas_MainConfigDialog_Map,
        Rimsiakas_MainConfigDialog_Intel_GridDecrease,
        Rimsiakas_MainConfigDialog_Intel_GridIncrease,
        Rimsiakas_MainConfigDialog_Flare_Field,
        Rimsiakas_MainConfigDialog_Env_YearField,
        Rimsiakas_MainConfigDialog_Env_MonthField,
        Rimsiakas_MainConfigDialog_Env_DayField,
        Rimsiakas_MainConfigDialog_Env_HourField,
        Rimsiakas_MainConfigDialog_Env_MinuteField,
        Rimsiakas_MainConfigDialog_Env_OvercastField,
        Rimsiakas_MainConfigDialog_Env_FogField,
        Rimsiakas_MainConfigDialog_Env_ConfirmButton,
        Rimsiakas_MainConfigDialog_PreviewButton,
        Rimsiakas_MainConfigDialog_AdvancedConfigButton,
        Rimsiakas_MainConfigDialog_AiConfigButton,
        Rimsiakas_MainConfigDialog_FactionConfigButton,
    };

    class Rimsiakas_MainConfigDialog_MainBackground: Rimsiakas_MainBackground
    {
         idc = 100000;
    };

    class Rimsiakas_MainConfigDialog_Heading: Rimsiakas_Heading
    {
        idc = 100001;
        text = "Click on the map to select the mission area";
    };

    class Rimsiakas_MainConfigDialog_Map: RscMapControl
    {
        idc = 9999;
        x = 0.5 * GUI_GRID_W + GUI_GRID_X;
        y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 30 * GUI_GRID_W;
        h = 20 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Intel_GridFrame: RscFrame
    {
        idc = 101000;
        x = RIGHT_SIDE_X * GUI_GRID_W + GUI_GRID_X;
        y = INTEL_GRID_ELEMENTS_Y * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 3.5 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Intel_GridLabel: RscText
    {
        idc = 101001;
        text = "Intel Grid:";
        tooltip = "The resolution of colored squares on the map hinting the enemy locations.";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (0.5 + INTEL_GRID_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Intel_GridDecrease: Rimsiakas_Button
    {
        idc = 101002;
        text = "-";
        action = "['down'] call Rimsiakas_fnc_handleIntelGridButton;";
        x = (1 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (1.5 + INTEL_GRID_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    }

    class Rimsiakas_MainConfigDialog_Intel_GridValue: RscText
    {
        idc = 101003;
        text = "";
        tooltip = "The size of colored squares on the map hinting the enemy locations.";
        style = ST_CENTER;
        x = (2 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (1.7 + INTEL_GRID_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 2.7 * GUI_GRID_H + GUI_GRID_Y;
        h = 1 * GUI_GRID_W;
    }

    class Rimsiakas_MainConfigDialog_Intel_GridIncrease: Rimsiakas_Button
    {
        idc = 101004;
        text = "+";
        action = "['up'] call Rimsiakas_fnc_handleIntelGridButton;";
        x = (6.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (1.5 + INTEL_GRID_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    }

    class Rimsiakas_MainConfigDialog_Flare_Frame: RscFrame
    {
        idc = 101500;
        x = RIGHT_SIDE_X * GUI_GRID_W + GUI_GRID_X;
        y = (FLARE_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 3.5 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Flare_Label: RscText
    {
        idc = 101501;
        text = "Flare Illumination:";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (0.5 + FLARE_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Flare_Field: RscCombo
    {
        idc = 101502;
        tooltip = "How strongly to illuminate the battlefield at night.";
        class Items
        {
            class Disabled
            {
                text = "Disabled";
                data = 0;
                default = 1;
            };
            class Low
            {
                text = "Low";
                data = 1;
            };
            class Medium
            {
                text = "Medium";
                data = 2;
            };
            class High
            {
                text = "High";
                data = 3;
            };

        };
        y = (1.5 + FLARE_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        w = 7.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Env_Frame: RscFrame
    {
        idc = 102000;
        x = RIGHT_SIDE_X * GUI_GRID_W + GUI_GRID_X;
        y = (ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 11 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Env_DateLabel: RscText
    {
        idc = 102001;
        text = "Date:";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (0.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 3.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Env_YearField: RscEdit
    {
        idc = 102002;
        x = (1 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (1.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 2.3 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 4;
    };

    class Rimsiakas_MainConfigDialog_Env_DateSeparator1: RscText
    {
        idc = 102003;
        text = "-";
        x = (3.1 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (1.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Env_MonthField: RscEdit
    {
        idc = 102004;
        x = (3.9 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (1.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 2;
    };

    class Rimsiakas_MainConfigDialog_Env_DateSeparator2: RscText
    {
        idc = 102005;
        text = "-";
        x = (5.2 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (1.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Env_DayField: RscEdit
    {
        idc = 102006;
        x = (6 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (1.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 2;
    };

    class Rimsiakas_MainConfigDialog_Env_TimeLabel: RscText
    {
        idc = 102007;
        text = "Time:";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (3 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 3.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Env_HourField: RscEdit
    {
        idc = 102008;
        x = (3.9 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (3 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 2;
    };

    class Rimsiakas_MainConfigDialog_Env_TimeSeparator: RscText
    {
        idc = 102009;
        text = ":";
        x = (5.2 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (3 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Env_MinuteField: RscEdit
    {
        idc = 102010;
        x = (6 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (3 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 2;
    };

    class Rimsiakas_MainConfigDialog_Env_OvercastLabel: RscText
    {
        idc = 102011;
        text = "Overcast %:";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (4.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Env_OvercastField: RscEdit
    {
        idc = 102012;
        x = (5.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (4.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 2 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Env_FogLabel: RscText
    {
        idc = 102013;
        text = "Fog %:";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (6 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 4 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Env_FogField: RscEdit
    {
        idc = 102014;
        x = (5.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (6 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 2 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_MainConfigDialog_Env_ConfirmButton: Rimsiakas_Button
    {
        idc = 102099;
        text = "Apply";
        action = "call Rimsiakas_fnc_confirmEnvConfig";
        x = 32 * GUI_GRID_W + GUI_GRID_X;
        y = 20 * GUI_GRID_H + GUI_GRID_Y;
        w = 6.5 * GUI_GRID_W;
    };

    class Rimsiakas_MainConfigDialog_ConfirmButton: Rimsiakas_Button
    {
        idc = 109000;
        action = "call Rimsiakas_fnc_confirmMissionAreaSelection";
        text = "Confirm";
        x = 0.5 * GUI_GRID_W + GUI_GRID_X;
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
    };

    class Rimsiakas_MainConfigDialog_PreviewButton: Rimsiakas_Button
    {
        idc = 209001;
        action = "[] call Rimsiakas_fnc_previewMissionArea";
        text = "Preview";
        x = 6.5 * GUI_GRID_W + GUI_GRID_X;
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
    };

    class Rimsiakas_MainConfigDialog_AdvancedConfigButton: Rimsiakas_Button
    {
        idc = 209003;
        action = "[] spawn {call Rimsiakas_fnc_openAdvancedConfig;};";
        text = "Advanced Config";
        x = 12.5 * GUI_GRID_W + GUI_GRID_X;
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
    };

    class Rimsiakas_MainConfigDialog_AiConfigButton: Rimsiakas_Button
    {
        idc = 209004;
        action = "[] spawn {createDialog 'Rimsiakas_AiConfigurationDialog';};"
        text = "AI Config";
        x = 20.5 * GUI_GRID_W + GUI_GRID_X;
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
    };

    class Rimsiakas_MainConfigDialog_FactionConfigButton: Rimsiakas_Button
    {
        idc = 209004;
        action = "[] spawn {createDialog 'Rimsiakas_FactionsConfigDialog';};"
        text = "Faction Config";
        x = 26.5 * GUI_GRID_W + GUI_GRID_X;
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
        w = 6.5 * GUI_GRID_W;
    };
}