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
        x = 31 * GUI_GRID_W + GUI_GRID_X;
        y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 3.5 * GUI_GRID_H;
    };

    class Rimsiakas_MissionAreaSelectorDialog_IntelGridLabel: RscText
    {
        idc = 101001;
        text = "Intel Grid Size:";
        tooltip = "The size of colored squares on the map hinting the enemy locations.";
        x = 31.5 * GUI_GRID_W + GUI_GRID_X;
        y = 3 * GUI_GRID_H + GUI_GRID_Y;
        w = 7.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_MissionAreaSelectorDialog_IntelGridDecrease: Rimsiakas_Button
    {
        idc = 101002;
        text = "-";
        action = "['down'] call Rimsiakas_fnc_handleIntelGridButton;";
        x = 32 * GUI_GRID_W + GUI_GRID_X;
        y = 4 * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    }

    class Rimsiakas_MissionAreaSelectorDialog_IntelGridValue: RscText
    {
        idc = 101003;
        text = "";
        tooltip = "The size of colored squares on the map hinting the enemy locations.";
        x = 33 * GUI_GRID_W + GUI_GRID_X;
        y = 4.2 * GUI_GRID_H + GUI_GRID_Y;
        w = 4 * GUI_GRID_H + GUI_GRID_Y;
        h = 1 * GUI_GRID_W;
    }

    class Rimsiakas_MissionAreaSelectorDialog_IntelGridIncrease: Rimsiakas_Button
    {
        idc = 101004;
        text = "+";
        action = "['up'] call Rimsiakas_fnc_handleIntelGridButton;";
        x = 37.5 * GUI_GRID_W + GUI_GRID_X;
        y = 4 * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    }

    class Rimsiakas_MissionAreaSelectorDialog_EnvironmentFrame: RscFrame
    {
        idc = 102000;
        x = 31 * GUI_GRID_W + GUI_GRID_X;
        y = 7 * GUI_GRID_H + GUI_GRID_Y;
        w = 8.5 * GUI_GRID_W;
        h = 15.5 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_DateLabel: RscText
    {
        idc = 102001;
        text = "Date:";
        x = 31.5 * GUI_GRID_W + GUI_GRID_X;
        y = 7.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 3.5 * GUI_GRID_W;
        h = 0.5 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_YearField: RscEdit
    {
        idc = 102002;
        x = 32 * GUI_GRID_W + GUI_GRID_X;
        y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 2.3 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 4;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_DateSeparator1: RscText
    {
        idc = 102003;
        text = "-";
        x = 34.1 * GUI_GRID_W + GUI_GRID_X;
        y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_MonthField: RscEdit
    {
        idc = 102004;
        x = 34.9 * GUI_GRID_W + GUI_GRID_X;
        y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 1.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 2;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_DateSeparator2: RscText
    {
        idc = 102005;
        text = "-";
        x = 36.2 * GUI_GRID_W + GUI_GRID_X;
        y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_DayField: RscEdit
    {
        idc = 102006;
        x = 37 * GUI_GRID_W + GUI_GRID_X;
        y = 8.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 1.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 2;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_TimeLabel: RscText
    {
        idc = 102007;
        text = "Time:";
        x = 31.5 * GUI_GRID_W + GUI_GRID_X;
        y = 10 * GUI_GRID_H + GUI_GRID_Y;
        w = 3.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_HourField: RscEdit
    {
        idc = 102008;
        x = 34.9 * GUI_GRID_W + GUI_GRID_X;
        y = 10 * GUI_GRID_H + GUI_GRID_Y;
        w = 1.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 2;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_TimeSeparator: RscText
    {
        idc = 102009;
        text = ":";
        x = 36.2 * GUI_GRID_W + GUI_GRID_X;
        y = 10 * GUI_GRID_H + GUI_GRID_Y;
        w = 1 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_MinuteField: RscEdit
    {
        idc = 102010;
        x = 37 * GUI_GRID_W + GUI_GRID_X;
        y = 10 * GUI_GRID_H + GUI_GRID_Y;
        w = 1.5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        maxChars = 2;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_OvercastLabel: RscText
    {
        idc = 102011;
        text = "Overcast %:";
        x = 31.5 * GUI_GRID_W + GUI_GRID_X;
        y = 11.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 5 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_OvercastField: RscEdit
    {
        idc = 102012;
        x = 36.5 * GUI_GRID_W + GUI_GRID_X;
        y = 11.5 * GUI_GRID_H + GUI_GRID_Y;
        w = 2 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_FogLabel: RscText
    {
        idc = 102013;
        text = "Fog %:";
        x = 31.5 * GUI_GRID_W + GUI_GRID_X;
        y = 13 * GUI_GRID_H + GUI_GRID_Y;
        w = 4 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
    };

    class Rimsiakas_EnvironmentConfigurationDialog_FogField: RscEdit
    {
        idc = 102014;
        x = 36.5 * GUI_GRID_W + GUI_GRID_X;
        y = 13 * GUI_GRID_H + GUI_GRID_Y;
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
        action = "closeDialog 1; deleteMarkerLocal 'missionAreaMarker'; Rimsiakas_missionAreaSelected = true;";
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