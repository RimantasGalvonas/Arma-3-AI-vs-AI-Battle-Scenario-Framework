#define COLUMN_WIDTH (14)
#define MARGIN (0.5)

class Rimsiakas_AllowedInventoryAdjustmentItemsDialog
{
    idd = INVENTORY_ADJUSTMENT_ITEMS_IDD;
    movingEnabled = false;
    enableSimulation = true;
    onLoad = "[] spawn Rimsiakas_fnc_openAllowedInventoryAdjustmentItemsDialog;";

    controlsBackground[]=
    {
        Rimsiakas_AllowedInventoryAdjustmentItemsDialog_MainBackground,
        Rimsiakas_AllowedInventoryAdjustmentItemsDialog_Heading,
        Rimsiakas_AllowedInventoryAdjustmentItemsDialog_LeftColumnFrame,
        Rimsiakas_AllowedInventoryAdjustmentItemsDialog_RightColumnFrame
    };
    controls[]=
    {
        Rimsiakas_AllowedInventoryAdjustmentItemsDialog_AllowedItemsTree,
        Rimsiakas_AllowedInventoryAdjustmentItemsDialog_ActionButtonsControlGroup,
        Rimsiakas_AllowedInventoryAdjustmentItemsDialog_AvailableItemsTree,
        Rimsiakas_AllowedInventoryAdjustmentItemsDialog_Buttons_ControlGroup
    };

    class Rimsiakas_AllowedInventoryAdjustmentItemsDialog_MainBackground: Rimsiakas_MainBackground
    {
         idc = INVENTORY_ADJUSTMENT_MAINBACKGROUND_IDC;
    };

    class Rimsiakas_AllowedInventoryAdjustmentItemsDialog_Heading: Rimsiakas_Heading
    {
        idc = INVENTORY_ADJUSTMENT_HEADING_IDC;
        text = "Specify items allowed to be added to spawned units";
    };

    class Rimsiakas_AllowedInventoryAdjustmentItemsDialog_LeftColumnFrame: RscFrame
    {
        idc = INVENTORY_ADJUSTMENT_ITEMS_LEFTCOLUMNFRAME_IDC;
        x = MARGIN * GUI_GRID_W;
        y = 2.5 * GUI_GRID_H;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 20 * GUI_GRID_H;
        sizeEx = 0.03;
    };

    class Rimsiakas_AllowedInventoryAdjustmentItemsDialog_AllowedItemsTree: RscTreeSearch
    {
        idc = INVENTORY_ADJUSTMENT_ITEMS_ALLOWEDITEMSTREE_IDC;
        sizeEx = 0.03;
        colorBackground[] = {0,0,0,0.3};
        x = MARGIN * 2 * GUI_GRID_W + GUI_GRID_X;
        y = (2.5 + MARGIN) * GUI_GRID_H + GUI_GRID_Y;
        w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
        h = 19 * GUI_GRID_H;
        multiselectEnabled = 1;
        onTreeSelChanged = "_this call Rimsiakas_fnc_onInventoryAdjustmentItemTreeSelectionChange;";
        onLBDblClick = "[] call Rimsiakas_fnc_removeItemFromAllowedItemsTree";
    };

    class Rimsiakas_AllowedInventoryAdjustmentItemsDialog_ActionButtonsControlGroup: RscControlsGroup
    {
        idc = INVENTORY_ADJUSTMENT_ITEMS_ACTIONS_BUTTONS_CONTROLGROUP_IDC;
        x = (COLUMN_WIDTH + MARGIN * 2) * GUI_GRID_W;
        y = 2.5 * GUI_GRID_H;
        colorBackground[] = {0,0,0,0.3};
        w = (40 - COLUMN_WIDTH * 2 - 4 * MARGIN) * GUI_GRID_W;
        h = 20 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_AllowedInventoryAdjustmentItemsDialog_ActionButtonsAdd: Rimsiakas_Button
            {
                idc = INVENTORY_ADJUSTMENT_ITEMS_ACTIONS_BUTTONS_ADD_IDC;
                text = "<-";
                action = "[] call Rimsiakas_fnc_addItemToAllowedItemsTree";

                x = 0 * GUI_GRID_W + GUI_GRID_X;
                y = 2.5 * GUI_GRID_H;
                w = 2 * GUI_GRID_W;
            };

            class Rimsiakas_AllowedInventoryAdjustmentItemsDialog_ActionButtonsAddRemove: Rimsiakas_Button
            {
                idc = INVENTORY_ADJUSTMENT_ITEMS_ACTIONS_BUTTONS_REMOVE_IDC;
                text = "->";
                action = "[] call Rimsiakas_fnc_removeItemFromAllowedItemsTree";

                x = (38 - COLUMN_WIDTH * 2 - 4 * MARGIN) * GUI_GRID_W + GUI_GRID_X;
                y = 2.5 * GUI_GRID_H;
                w = 2 * GUI_GRID_W;
            };

            class Rimsiakas_AllowedInventoryAdjustmentItemsDialog_SelectedItemPicture: RscPictureKeepAspect
            {
                idc = INVENTORY_ADJUSTMENT_ITEMS_ACTIONS_BUTTONS_SELECTEDITEMPICTURE_IDC;
                x = 0 * GUI_GRID_W + GUI_GRID_X;
                y = 5.5 * GUI_GRID_H + GUI_GRID_Y;
                w = (40 - COLUMN_WIDTH * 2 - 4 * MARGIN) * GUI_GRID_W;
                h = (40 - COLUMN_WIDTH * 2 - 4 * MARGIN) * GUI_GRID_H;
            };
        };
    };

    class Rimsiakas_AllowedInventoryAdjustmentItemsDialog_RightColumnFrame: RscFrame
    {
        idc = INVENTORY_ADJUSTMENT_ITEMS_RIGHTCOLUMNFRAME_IDC;
        x = (40 - MARGIN - COLUMN_WIDTH) * GUI_GRID_W;
        y = 2.5 * GUI_GRID_H;
        w = COLUMN_WIDTH * GUI_GRID_W;
        h = 20 * GUI_GRID_H;
    };

    class Rimsiakas_AllowedInventoryAdjustmentItemsDialog_AvailableItemsTree: RscTreeSearch
    {
        idc = INVENTORY_ADJUSTMENT_ITEMS_AVAILABLEITEMSTREE_IDC;
        sizeEx = 0.03;
        colorBackground[] = {0,0,0,0.3};
        x = (40 - COLUMN_WIDTH) * GUI_GRID_W;
        y = (2.5 + MARGIN) * GUI_GRID_H;
        w = (COLUMN_WIDTH - MARGIN * 2) * GUI_GRID_W;
        h = 19 * GUI_GRID_H;
        multiselectEnabled = 1;
        onTreeSelChanged = "_this call Rimsiakas_fnc_onInventoryAdjustmentItemTreeSelectionChange;";
        onTreeDblClick = "[] call Rimsiakas_fnc_addItemToAllowedItemsTree";
    };

    class Rimsiakas_AllowedInventoryAdjustmentItemsDialog_Buttons_ControlGroup: RscControlsGroup
    {
        idc = INVENTORY_ADJUSTMENT_ITEMS_BUTTONS_CONTROLGROUP_IDC;
        x = 0.5 * GUI_GRID_W;
        y = 23 * GUI_GRID_H + GUI_GRID_Y;
        w = 40 * COLUMN_WIDTH * GUI_GRID_W;
        h = 2 * GUI_GRID_H;

        class Controls
        {
            class Rimsiakas_AllowedInventoryAdjustmentItemsDialog_ConfirmButton: Rimsiakas_Button
            {
                idc = INVENTORY_ADJUSTMENT_ITEMS_BUTTONS_CONFIRM_IDC;
                text = "Confirm";
                action = "[] call Rimsiakas_fnc_addCustomGroupToPool;";

                x = 0 * GUI_GRID_W + GUI_GRID_X;
            };

            class Rimsiakas_AllowedInventoryAdjustmentItemsDialog_CancelButton: Rimsiakas_Button
            {
                idc = INVENTORY_ADJUSTMENT_ITEMS_BUTTONS_CANCEL_IDC;
                text = "Cancel";
                action = "closeDialog 2;";

                x = 6 * GUI_GRID_W + GUI_GRID_X;
            };
        };
    }
}