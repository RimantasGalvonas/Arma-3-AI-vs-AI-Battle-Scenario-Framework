#define COLUMN_WIDTH (12.666666)
#define MARGIN (0.5)

class Rimsiakas_FactionConfigDialog
{
    idd = 46423;
    movingEnabled = false;
    enableSimulation = true;
    onLoad = "call Rimsiakas_fnc_openFactionConfig";

    controlsBackground[]=
    {
        Rimsiakas_FactionConfigDialog_MainBackground,
        Rimsiakas_FactionConfigDialog_Heading,
        Rimsiakas_FactionConfigDialog_FirstColumnFrame, // Frames are in here rather than in control groupss because otherwise the appearance gets messed up somehow
        Rimsiakas_FactionConfigDialog_SecondColumnFrame,
        Rimsiakas_FactionConfigDialog_ThirdColumnFrame
    };
    controls[]=
    {
        Rimsiakas_FactionConfigDialog_SpawnerPoolsControlGroup,
        Rimsiakas_FactionConfigDialog_SpawnerDetailsControlGroup,
        Rimsiakas_FactionConfigDialog_PoolDetailsControlGroup,
        Rimsiakas_FactionConfigDialog_Map
    };

    class Rimsiakas_FactionConfigDialog_TextInput: RscEdit
    {
        sizeEx = 0.03;
        colorBackground[] = {0,0,0,0.3};
        x = (COLUMN_WIDTH - MARGIN - 2) * GUI_GRID_W;
        w = 2 * GUI_GRID_W;
        h = 1 * GUI_GRID_H;
        onEditChanged = "[_this select 0, _this select 1] call Rimsiakas_fnc_inputChanged;"
    };

    class Rimsiakas_FactionConfigDialog_MainBackground: Rimsiakas_MainBackground
    {
         idc = 400000;
    };

    class Rimsiakas_FactionConfigDialog_Heading: Rimsiakas_Heading
    {
        idc = 400001;
        text = "Faction config";
    };

    class Rimsiakas_FactionConfigDialog_FirstColumnFrame: RscFrame
    {
        idc = 401000;
        x = MARGIN * GUI_GRID_W;
        y = 2.5 * GUI_GRID_H;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 20 * GUI_GRID_H;
        sizeEx = 0.03;
    };

    class Rimsiakas_FactionConfigDialog_Map: RscMapControl // Can't be put in the controlsGroup according to the docs
    {
        idc = 409999; // Different ID than the other ones because this map is not responsible for moving things around
        x = 1 * GUI_GRID_W + GUI_GRID_X;
        y = 15 * GUI_GRID_H + GUI_GRID_Y;
        w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
        h = 7 * GUI_GRID_H;
    };

    class Rimsiakas_FactionConfigDialog_SpawnerPoolsControlGroup: RscControlsGroup
    {
        idc = 401001;
        x = MARGIN * GUI_GRID_W + GUI_GRID_X;
        y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 20 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionConfigDialog_SpawnerPoolsTree: RscTreeSearch
            {
                idc = 401002;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                h = 11.5 * GUI_GRID_H;
                onTreeSelChanged = "[_this] call Rimsiakas_fnc_spawnerSelected;";
            };
        };
    }

    class Rimsiakas_FactionConfigDialog_SecondColumnFrame: RscFrame
    {
        idc = 402000;
        x = (MARGIN * 2 + COLUMN_WIDTH) * GUI_GRID_W;
        y = 2.15 * GUI_GRID_H;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 20.35 * GUI_GRID_H;
        sizeEx = 0.03;
        text = "Properties";
    };

    class Rimsiakas_FactionConfigDialog_SpawnerDetailsControlGroup: RscControlsGroup
    {
        idc = 402001;
        x = (MARGIN * 2 + COLUMN_WIDTH) * GUI_GRID_W;
        y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 20 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionConfigDialog_MaxUnitsPerGroupLabel: RscText
            {
                idc = 402002;
                text = "Max units per group:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionConfigDialog_MaxUnitsPerGroup: Rimsiakas_FactionConfigDialog_TextInput
            {
                idc = 402003;
                tooltip = "If you set this variable, groups with the amount of soldiers exceeding this number are trimmed down to the desired size.";
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionConfigDialog_MaxUnitsLabel: RscText
            {
                idc = 402004;
                text = "Max units:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionConfigDialog_MaxUnits: Rimsiakas_FactionConfigDialog_TextInput
            {
                idc = 402005;
                tooltip = "Spawner will pause when it has this number of alive spawned units.";
                y = 1.5 * GUI_GRID_H + GUI_GRID_Y;
            };

            class Rimsiakas_FactionConfigDialog_SpawnRateLabel: RscText
            {
                idc = 402006;
                text = "Spawn Rate:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionConfigDialog_SpawnRate: Rimsiakas_FactionConfigDialog_TextInput
            {
                idc = 402007;
                tooltip = "Time delay (seconds) between spawns.";
                y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
            };
        };
    };

    class Rimsiakas_FactionConfigDialog_PoolDetailsControlGroup: RscControlsGroup
    {
        idc = 403001;
        x = (MARGIN * 2 + COLUMN_WIDTH) * GUI_GRID_W;
        y = 2.5 * GUI_GRID_H + GUI_GRID_Y;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 20 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_FactionConfigDialog_PoolDetailsLabel: RscText
            {
                idc = 403002;
                sizeEx = 0.035;
                text = "Groups in pool:";
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 11 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionConfigDialog_SpawnerPoolGroups: RscListBox
            {
                idc = 403003;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 2 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                h = 10 * GUI_GRID_H;
            };

            class Rimsiakas_FactionConfigDialog_SpawnerPoolWeightLabel: RscText
            {
                idc = 403004;
                text = "Pool selection weight:";
                sizeEx = 0.035;
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = COLUMN_WIDTH * GUI_GRID_H + GUI_GRID_Y;
                w = 8 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_FactionConfigDialog_SpawnerPoolWeight: Rimsiakas_FactionConfigDialog_TextInput
            {
                idc = 403005;
                tooltip = "Relative likelihood of spawning a group from this pool. A higher value means the spawner will pick groups to spawn from this pool more frequently.";
                y = COLUMN_WIDTH * GUI_GRID_H + GUI_GRID_Y;
            };
        };
    };

    class Rimsiakas_FactionConfigDialog_ThirdColumnFrame: RscFrame
    {
        idc = 403000;
        x = (MARGIN * 3 + COLUMN_WIDTH * 2) * GUI_GRID_W;
        y = 2.5 * GUI_GRID_H;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 20 * GUI_GRID_H;
    };
}