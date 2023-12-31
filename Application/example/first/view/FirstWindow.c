#include <stdio.h>
#include <stdbool.h>
#include "./FirstWindow.h"
#include "../../../fonts/fonts.h"
#include "../../../generic/macro.h"
#include "../../../manager/WindowsManager.h"

static first_window_t fw;

static const char* getWindowName() {
    return fw.name;
}

static lv_obj_t* getContainer() {
    return fw.container;
}

static void spinboxCheckable(checkable_t checkable) {
    if (fw.activedSpinbox == NULL) return;
    switch (checkable)
    {
    case Checked:
        lv_obj_set_style_opa(fw.activedSpinbox, LV_OPA_COVER, LV_PART_CURSOR);
        break;
    case UnCheck:
        lv_obj_set_style_opa(fw.activedSpinbox, LV_OPA_TRANSP, LV_PART_CURSOR);
        lv_spinbox_set_cursor_pos(fw.activedSpinbox, 0);
        fw.activedSpinbox = NULL;
        break;
    default:
        lv_obj_set_style_opa(fw.activedSpinbox, LV_OPA_TRANSP, LV_PART_CURSOR);
        lv_spinbox_set_cursor_pos(fw.activedSpinbox, 0);
        fw.activedSpinbox = NULL;
        break;
    }
}

static void selectSpinbox(channel_t channel, bool view) {
    if (!view) {
        fw.activedSpinbox = fw.spinbox[channel];
        return;
    }
    if (fw.activedSpinbox != NULL) {
        spinboxCheckable(UnCheck);
    }
    fw.activedSpinbox = fw.spinbox[channel];
    spinboxCheckable(Checked);
}

static void spinboxSelectLeft() {
    if (fw.activedSpinbox == NULL) return;
    lv_spinbox_step_prev(fw.activedSpinbox);
}

static void spinboxSelectRight() {
    if (fw.activedSpinbox == NULL) return;
    lv_spinbox_step_next(fw.activedSpinbox);
}

static void spinboxSelectUp() {
    if (fw.activedSpinbox == NULL) return;
    lv_spinbox_increment(fw.activedSpinbox);
}

static void spinboxSelectDown() {
    if (fw.activedSpinbox == NULL) return;
    lv_spinbox_decrement(fw.activedSpinbox);
}

static void spinboxSetValue(uint64_t value) {
    if (fw.activedSpinbox == NULL) return;
    lv_spinbox_set_value(fw.activedSpinbox, value);
}

static bool allowKeyBoardInput() {
    return fw.activedSpinbox != NULL;
}

static void setLabelText(const char* text) {
    lv_label_set_text(fw.label, text);
}

static void* getWindowInterface() {
    return &fw.fwi;
}

void initFirstWindow(lv_obj_t* parent) {
    lv_style_init(&fw.style);
    lv_style_set_radius(&fw.style, 0);
    lv_style_set_border_width(&fw.style, 0);
    lv_style_set_bg_color(&fw.style, lv_color_white());

    fw.name = "FirstWindow";

    fw.container = lv_obj_create(parent);
    lv_obj_remove_style_all(fw.container);
    lv_obj_set_size(fw.container, WINDOWS_WIDTH, WINDOWS_HEIGH);
    lv_obj_set_pos(fw.container, 0, 0);
    lv_obj_add_style(fw.container, &fw.style, 0);
    
    fw.label = lv_label_create(fw.container);
    lv_obj_remove_style_all(fw.label);
    lv_obj_set_size(fw.label, 450, 30);
    lv_obj_set_pos(fw.label, 0, 0);

    for (int i = 0; i < EndChannel; i++) {
        fw.spinbox[i] = lv_spinbox_create(fw.container);
        lv_obj_set_width(fw.spinbox[i], 100);
        lv_obj_set_size(fw.spinbox[i], 450, 50);
        lv_obj_set_pos(fw.spinbox[i], 0, i * 60 + 40);
        lv_spinbox_set_range(fw.spinbox[i], 0, 100000);
        lv_spinbox_set_digit_format(fw.spinbox[i], 5, 2);
        lv_obj_set_style_border_width(fw.spinbox[i], 0, 0);
        lv_obj_set_style_outline_width(fw.spinbox[i], 0, 0);
        lv_obj_set_style_anim_time(fw.spinbox[i], 500, LV_PART_CURSOR);
        lv_obj_set_style_opa(fw.spinbox[i], LV_OPA_TRANSP, LV_PART_CURSOR);
        lv_obj_set_style_text_font(fw.spinbox[i], &SourceHanSansAscii_Bold_24, 0);
    }

    setLabelText(fw.name);

    fw.fwi.selectSpinbox = selectSpinbox;
    fw.fwi.spinboxCheckable = spinboxCheckable;
    fw.fwi.spinboxSelectLeft = spinboxSelectLeft;
    fw.fwi.spinboxSelectRight = spinboxSelectRight;
    fw.fwi.spinboxSelectUp = spinboxSelectUp;
    fw.fwi.spinboxSelectDown = spinboxSelectDown;
    fw.fwi.spinboxSetValue = spinboxSetValue;
    fw.fwi.allowKeyBoardInput = allowKeyBoardInput;
    fw.fwi.setLabelText = setLabelText;

    fw.controller.visable = inVisable;
    fw.controller.getContainer = getContainer;
    fw.controller.getWindowName = getWindowName;
    fw.controller.getWindowInterface = getWindowInterface;

    getWindowsManagerInterface()->registerWindow(&fw.controller, FirstWindow, true);
}
