#include <stdio.h>
#include "./FirstWindow.h"
#include "../../../fonts/fonts.h"
#include "../../../generic/macro.h"
#include "../../../manager/WindowsManager.h"

static first_window_t fw;

static void setLabelText(const char* text) {
    lv_label_set_text(fw.label, text);
}

static const char* getWindowName() {
    return fw.name;
}

static lv_obj_t* getContainer() {
    return fw.container;
}

static void spinboxSelectLeft(lv_obj_t* spinbox) {
    lv_spinbox_step_prev(spinbox);
}

static void spinboxSelectRight(lv_obj_t* spinbox) {
    lv_spinbox_step_next(spinbox);
}

static void spinboxSelectUp(lv_obj_t* spinbox) {
    lv_spinbox_increment(spinbox);
}

static void spinboxSelectDown(lv_obj_t* spinbox) {
    lv_spinbox_decrement(spinbox);
}

static void spinboxCheckable(lv_obj_t* spinbox, checkable_t checkable) {
    switch (checkable)
    {
    case Checked:
        lv_obj_set_style_opa(spinbox, LV_OPA_COVER, LV_PART_CURSOR);
        break;
    case UnCheck:
        lv_obj_set_style_opa(spinbox, LV_OPA_TRANSP, LV_PART_CURSOR);
        lv_spinbox_set_cursor_pos(spinbox, 0);
        break;
    default:
        lv_obj_set_style_opa(spinbox, LV_OPA_TRANSP, LV_PART_CURSOR);
        lv_spinbox_set_cursor_pos(spinbox, 0);
        break;
    }
}

static lv_obj_t* getSpinbox() {
    return fw.spinbox;
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
    lv_obj_set_size(fw.container, WINDOWS_WIDTH, WINDOWS_HEIGH);
    lv_obj_set_pos(fw.container, 0, 0);
    lv_obj_add_style(fw.container, &fw.style, 0);
    
    fw.label = lv_label_create(fw.container);
    lv_obj_set_size(fw.label, 750, 100);
    lv_obj_set_pos(fw.label, 0, 0);
    lv_obj_set_style_text_font(fw.label, &SourceHanSansCN_Bold_20, 0);

    fw.spinbox = lv_spinbox_create(fw.container);
    lv_spinbox_set_range(fw.spinbox, -1000, 25000);
    lv_spinbox_set_digit_format(fw.spinbox, 5, 2);
    lv_obj_set_width(fw.spinbox, 100);
    lv_obj_set_size(fw.spinbox, 750, 100);
    lv_obj_set_pos(fw.spinbox, 0, 100);
    lv_spinbox_set_range(fw.spinbox, 0, 100000);
    lv_spinbox_set_digit_format(fw.spinbox, 5, 2);
    lv_obj_set_style_anim_time(fw.spinbox, 500, LV_PART_CURSOR);
    lv_obj_set_style_text_font(fw.spinbox, &SourceHanSansAscii_Bold_30, 0);

    setLabelText(fw.name);

    fw.fwi.getSpinbox = getSpinbox;
    fw.fwi.spinboxCheckable = spinboxCheckable;
    fw.fwi.spinboxSelectLeft = spinboxSelectLeft;
    fw.fwi.spinboxSelectRight = spinboxSelectRight;
    fw.fwi.spinboxSelectUp = spinboxSelectUp;
    fw.fwi.spinboxSelectDown = spinboxSelectDown;
    fw.fwi.setLabelText = setLabelText;

    fw.controller.visable = inVisable;
    fw.controller.getContainer = getContainer;
    fw.controller.getWindowName = getWindowName;
    fw.controller.getWindowInterface = getWindowInterface;

    getWindowsManagerInterface()->registerWindow(&fw.controller, FirstWindow, true);
}
