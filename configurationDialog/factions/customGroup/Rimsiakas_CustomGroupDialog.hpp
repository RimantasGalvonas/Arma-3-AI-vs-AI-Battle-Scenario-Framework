#define COLUMN_WIDTH (18)
#define MARGIN (0.5)

class Rimsiakas_CustomGroupDialog
{
    idd = CUSTOM_GROUP_IDD;
    movingEnabled = false;
    enableSimulation = true;
    onLoad = "[] spawn Rimsiakas_fnc_openCustomGroupDialog;";

    controlsBackground[]=
    {
        Rimsiakas_CustomGroupDialog_MainBackground,
        Rimsiakas_CustomGroupDialog_Heading,
        Rimsiakas_CustomGroupDialog_LeftColumnFrame,
        Rimsiakas_CustomGroupDialog_RightColumnFrame
    };
    controls[]=
    {
        Rimsiakas_CustomGroupDialog_GroupUnitsList,
        Rimsiakas_CustomGroupDialog_ActionButtonsControlGroup,
        Rimsiakas_CustomGroupDialog_VehicleConfigTreeControlGroup,
        Rimsiakas_CustomGroupDialog_Buttons_ControlGroup
    };

    class Rimsiakas_CustomGroupDialog_MainBackground: Rimsiakas_MainBackground
    {
         idc = FACTIONS_CONFIG_MAINBACKGROUND_IDC;
    };

    class Rimsiakas_CustomGroupDialog_Heading: Rimsiakas_Heading
    {
        idc = FACTIONS_CONFIG_HEADING_IDC;
        text = "Custom group config";
    };

    class Rimsiakas_CustomGroupDialog_LeftColumnFrame: RscFrame
    {
        idc = CUSTOM_GROUP_LEFTCOLUMNFRAME_IDC;
        x = MARGIN * GUI_GRID_W;
        y = 2.5 * GUI_GRID_H;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 20 * GUI_GRID_H;
        sizeEx = 0.03;
    };

    class Rimsiakas_CustomGroupDialog_GroupUnitsList: RscListBox
    {
        idc = CUSTOM_GROUP_GROUPUNITSLIST_IDC;
        sizeEx = 0.03;
        colorBackground[] = {0,0,0,0.3};
        x = MARGIN * 2 * GUI_GRID_W + GUI_GRID_X;
        y = (2.5 + MARGIN) * GUI_GRID_H + GUI_GRID_Y;
        w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
        h = 19 * GUI_GRID_H;
        onLBDblClick = "[] call Rimsiakas_fnc_removeVehicleFromGroup";
    };

    class Rimsiakas_CustomGroupDialog_ActionButtonsControlGroup: RscControlsGroup
    {
        idc = CUSTOM_GROUP_ACTIONS_BUTTONS_CONTROLGROUP_IDC;
        x = (COLUMN_WIDTH + MARGIN * 2) * GUI_GRID_W;
        y = 5 * GUI_GRID_H;
        w = 2 * GUI_GRID_W;
        h = 3.5 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_CustomGroupDialog_ActionButtonsAdd: Rimsiakas_Button
            {
                idc = CUSTOM_GROUP_ACTIONS_BUTTONS_ADD_IDC;
                text = "<-";
                action = "[] call Rimsiakas_fnc_addVehicleToGroup;";

                x = 0 * GUI_GRID_W + GUI_GRID_X;
                y = 0 * GUI_GRID_H;
                w = 2 * GUI_GRID_W;
            };

            class Rimsiakas_CustomGroupDialog_ActionButtonsAddRemove: Rimsiakas_Button
            {
                idc = CUSTOM_GROUP_ACTIONS_BUTTONS_REMOVE_IDC;
                text = "->";
                action = "[] call Rimsiakas_fnc_removeVehicleFromGroup;";

                x = 0 * GUI_GRID_W + GUI_GRID_X;
                y = 2 * GUI_GRID_H;
                w = 2 * GUI_GRID_W;
            };
        };
    };

    class Rimsiakas_CustomGroupDialog_RightColumnFrame: RscFrame
    {
        idc = CUSTOM_GROUP_RIGHTCOLUMNFRAME_IDC;
        x = (40 - MARGIN - COLUMN_WIDTH) * GUI_GRID_W;
        y = 2.5 * GUI_GRID_H;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 20 * GUI_GRID_H;
    };

    class Rimsiakas_CustomGroupDialog_VehicleConfigTreeControlGroup: RscControlsGroup
    {
        idc = CUSTOM_GROUP_VEHICLECONFIGTREECONTROLGROUP_IDC;
        x = (40 - MARGIN - COLUMN_WIDTH) * GUI_GRID_W;
        y = 2.5 * GUI_GRID_H;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 20 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_CustomGroupDialog_VehicleConfigSearch: RscEdit
            {
                idc = CUSTOM_GROUP_VEHICLECONFIGSEARCH_IDC;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - 2 - MARGIN * 1) * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
            };

            class Rimsiakas_CustomGroupDialog_VehicleConfigSearchIcon: RscPictureKeepAspect
            {
                idc = CUSTOM_GROUP_VEHICLECONFIGSEARCHICON_IDC;
                x = (COLUMN_WIDTH - MARGIN - 1) * GUI_GRID_W;
                y = 0.5 * GUI_GRID_H + GUI_GRID_Y;
                w = 1 * GUI_GRID_W;
                h = 1 * GUI_GRID_H;
                text = "\A3\ui_f\data\gui\rsccommon\rscbuttonsearch\search_start_ca.paa";
            };

            class Rimsiakas_CustomGroupDialog_VehicleConfigTree: RscTreeSearch
            {
                idc = CUSTOM_GROUP_VEHICLECONFIGTREE_IDC;
                sizeEx = 0.03;
                colorBackground[] = {0,0,0,0.3};
                x = MARGIN * GUI_GRID_W + GUI_GRID_X;
                y = 2 * GUI_GRID_H + GUI_GRID_Y;
                w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
                h = 17.5 * GUI_GRID_H;
                multiselectEnabled = 1;
                onTreeDblClick = "[] call Rimsiakas_fnc_addVehicleToGroup;";
                idcSearch = CUSTOM_GROUP_VEHICLECONFIGSEARCH_IDC;
            };
        };
    };

    class Rimsiakas_CustomGroupDialog_Buttons_ControlGroup: RscControlsGroup
    {
        idc = CUSTOM_GROUP_BUTTONS_CONTROLGROUP_IDC;
        x = 0.5 * GUI_GRID_W;
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
        w = 40 * COLUMN_WIDTH * GUI_GRID_W;
        h = 2 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_CustomGroupDialog_ConfirmButton: Rimsiakas_Button
            {
                idc = CUSTOM_GROUP_BUTTONS_CONFIRM_IDC;
                text = "Confirm";
                action = "[] call Rimsiakas_fnc_addCustomGroupToPool;";

                x = 0 * GUI_GRID_W + GUI_GRID_X;
            };

            class Rimsiakas_CustomGroupDialog_CancelButton: Rimsiakas_Button
            {
                idc = CUSTOM_GROUP_BUTTONS_CANCEL_IDC;
                text = "Cancel";
                action = "closeDialog 2;";

                x = 6 * GUI_GRID_W + GUI_GRID_X;
            };
        };
    }
}