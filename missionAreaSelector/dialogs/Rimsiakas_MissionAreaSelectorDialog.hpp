#define RIGHT_SIDE_X	(31)
#define FLARE_ELEMENTS_Y	(7)
#define ENVIRONMENT_ELEMENTS_Y	(11.5)

class Rimsiakas_MissionAreaSelectorDialog
{
    idd = 46421;
    movingEnabled = false;
    enableSimulation = true;
    onLoad = "call Rimsiakas_fnc_populateEnvConfigFields; call Rimsiakas_fnc_refreshIntelGridValue";

    controlsBackground[]=
    {
        Rimsiakas_MissionAreaSelectorDialog_MainBackground,
        Rimsiakas_MissionAreaSelectorDialog_Heading,
        Rimsiakas_MissionAreaSelectorDialog_IntelGridFrame,
        Rimsiakas_MissionAreaSelectorDialog_IntelGridLabel,
        Rimsiakas_MissionAreaSelectorDialog_IntelGridValue,
        Rimsiakas_MissionAreaSelectorDialog_FlareFrame,
        Rimsiakas_MissionAreaSelectorDialog_FlareLabel,
        Rimsiakas_MissionAreaSelectorDialog_EnvironmentFrame,
        Rimsiakas_EnvironmentConfigurationDialog_DateLabel,
        Rimsiakas_EnvironmentConfigurationDialog_DateSeparator1,
        Rimsiakas_EnvironmentConfigurationDialog_DateSeparator2,
        Rimsiakas_EnvironmentConfigurationDialog_TimeLabel,
        Rimsiakas_EnvironmentConfigurationDialog_TimeSeparator,
        Rimsiakas_EnvironmentConfigurationDialog_OvercastLabel,
        Rimsiakas_EnvironmentConfigurationDialog_FogLabel
    };
    controls[]=
    {
        Rimsiakas_MissionAreaSelectorDialog_ConfirmButton,
        Rimsiakas_MissionAreaSelectorDialog_Map,
        Rimsiakas_MissionAreaSelectorDialog_IntelGridDecrease,
        Rimsiakas_MissionAreaSelectorDialog_IntelGridIncrease,
        Rimsiakas_MissionAreaSelectorDialog_FlareField,
        Rimsiakas_EnvironmentConfigurationDialog_YearField,
        Rimsiakas_EnvironmentConfigurationDialog_MonthField,
        Rimsiakas_EnvironmentConfigurationDialog_DayField,
        Rimsiakas_EnvironmentConfigurationDialog_HourField,
        Rimsiakas_EnvironmentConfigurationDialog_MinuteField,
        Rimsiakas_EnvironmentConfigurationDialog_OvercastField,
        Rimsiakas_EnvironmentConfigurationDialog_FogField,
        Rimsiakas_EnvironmentConfigurationDialog_ConfirmButton,
        Rimsiakas_MissionAreaSelectorDialog_PreviewButton,
        Rimsiakas_MissionAreaSelectorDialog_AdvancedConfigButton,
        Rimsiakas_MissionAreaSelectorDialog_AiConfigButton
    };

    class Rimsiakas_MissionAreaSelectorDialog_MainBackground: Rimsiakas_MainBackground
    {
         idc = 100000;
    };

    class Rimsiakas_MissionAreaSelectorDialog_Heading: Rimsiakas_Heading
    {
        idc = 100001;
        text = "Click on the map to select the mission area";
    };

    class Rimsiakas_MissionAreaSelectorDialog_Map: RscMapControl
    {
        idc = 9999;
        x = 0.5 * GUI_GRID_W + GUI_GRID_X;
        y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 30 * GUI_GRID_W;
        h = 20 * GUI_GRID_H;
    };

    class Rimsiakas_MissionAreaSelectorDialog_IntelGridFrame: RscFrame
    {
        idc = 101000;
        x = RIGHT_SIDE_X * GUI_GRID_W + GUI_GRID_X;
        y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 3.5 * GUI_GRID_H;
    };

    class Rimsiakas_MissionAreaSelectorDialog_IntelGridLabel: RscText
    {
        idc = 101001;
        text = "Intel Grid:";
        tooltip = "The resolution of colored squares on the map hinting the enemy locations.";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = 3 * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_MissionAreaSelectorDialog_IntelGridDecrease: Rimsiakas_Button
    {
        idc = 101002;
        text = "-";
        action = "['down'] call Rimsiakas_fnc_handleIntelGridButton;";
        x = (1 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = 4 * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    }

    class Rimsiakas_MissionAreaSelectorDialog_IntelGridValue: RscText
    {
        idc = 101003;
        text = "";
        tooltip = "The size of colored squares on the map hinting the enemy locations.";
        x = (2 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = 4.2 * GUI_GRID_H + GUI_GRID_Y;
        w = 4 * GUI_GRID_H + GUI_GRID_Y;
        h = 1 * GUI_GRID_W;
    }

    class Rimsiakas_MissionAreaSelectorDialog_IntelGridIncrease: Rimsiakas_Button
    {
        idc = 101004;
        text = "+";
        action = "['up'] call Rimsiakas_fnc_handleIntelGridButton;";
        x = (6.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = 4 * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    }

    class Rimsiakas_MissionAreaSelectorDialog_FlareFrame: RscFrame
    {
        idc = 101500;
        x = RIGHT_SIDE_X * GUI_GRID_W + GUI_GRID_X;
        y = (FLARE_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 3.5 * GUI_GRID_H;
    };

    class Rimsiakas_MissionAreaSelectorDialog_FlareLabel: RscText
    {
        idc = 101501;
        text = "Flare Illumination:";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (0.5 + FLARE_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_MissionAreaSelectorDialog_FlareField: RscCombo
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

    class Rimsiakas_MissionAreaSelectorDialog_EnvironmentFrame: RscFrame
    {
        idc = 102000;
        x = RIGHT_SIDE_X * GUI_GRID_W + GUI_GRID_X;
        y = (ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 11 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_DateLabel: RscText
    {
        idc = 102001;
        text = "Date:";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (0.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 3.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_YearField: RscEdit
    {
        idc = 102002;
        x = (1 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (1.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 2.3 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 4;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_DateSeparator1: RscText
    {
        idc = 102003;
        text = "-";
        x = (3.1 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (1.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_MonthField: RscEdit
    {
        idc = 102004;
        x = (3.9 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (1.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 2;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_DateSeparator2: RscText
    {
        idc = 102005;
        text = "-";
        x = (5.2 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (1.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_DayField: RscEdit
    {
        idc = 102006;
        x = (6 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (1.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 2;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_TimeLabel: RscText
    {
        idc = 102007;
        text = "Time:";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (3 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 3.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_HourField: RscEdit
    {
        idc = 102008;
        x = (3.9 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (3 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 2;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_TimeSeparator: RscText
    {
        idc = 102009;
        text = ":";
        x = (5.2 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (3 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_MinuteField: RscEdit
    {
        idc = 102010;
        x = (6 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (3 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 1.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 2;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_OvercastLabel: RscText
    {
        idc = 102011;
        text = "Overcast %:";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (4.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_OvercastField: RscEdit
    {
        idc = 102012;
        x = (5.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (4.5 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 2 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_FogLabel: RscText
    {
        idc = 102013;
        text = "Fog %:";
        x = (0.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (6 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 4 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_FogField: RscEdit
    {
        idc = 102014;
        x = (5.5 + RIGHT_SIDE_X) * GUI_GRID_W + GUI_GRID_X;
        y = (6 + ENVIRONMENT_ELEMENTS_Y) * GUI_GRID_H + GUI_GRID_Y;
        w = 2 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_ConfirmButton: Rimsiakas_Button
    {
        idc = 102099;
        text = "Apply";
        action = "call Rimsiakas_fnc_confirmEnvConfig";
        x = 32 * GUI_GRID_W + GUI_GRID_X;
        y = 20 * GUI_GRID_H + GUI_GRID_Y;
        w = 6.5 * GUI_GRID_W;
    };

    class Rimsiakas_MissionAreaSelectorDialog_ConfirmButton: Rimsiakas_Button
    {
        idc = 109000;
        action = "call Rimsiakas_fnc_confirmMissionAreaSelection";
        text = "Confirm";
        x = 0.5 * GUI_GRID_W + GUI_GRID_X;
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
        w = 5.5 * GUI_GRID_W;
    };

    class Rimsiakas_MissionAreaSelectorDialog_PreviewButton: Rimsiakas_Button
    {
        idc = 209001;
        action = "[] call Rimsiakas_fnc_previewMissionArea";
        text = "Preview";
        x = 6.5 * GUI_GRID_W + GUI_GRID_X;
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
        w = 5.5 * GUI_GRID_W;
    };

    class Rimsiakas_MissionAreaSelectorDialog_AdvancedConfigButton: Rimsiakas_Button
    {
        idc = 209003;
        action = "[] spawn {call Rimsiakas_fnc_openAdvancedConfig;};";
        text = "Advanced Config";
        x = 12.5 * GUI_GRID_W + GUI_GRID_X;
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
    };

    class Rimsiakas_MissionAreaSelectorDialog_AiConfigButton: Rimsiakas_Button
    {
        idc = 209004;
        action = "[] spawn {createDialog 'Rimsiakas_AiConfigurationDialog';};"
        text = "AI Config";
        x = 20.5 * GUI_GRID_W + GUI_GRID_X;
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
        w = 5.5 * GUI_GRID_W;
    };
}