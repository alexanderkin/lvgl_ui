#include <stdio.h>
#include "./FirstWindow.h"
#include "../../../manager/WindowsManager.h"

static first_window_t fw;

static void setLabelText(const char* text) {
    if (fw.hasInited == ON) {
        lv_label_set_text(fw.label, text);
    }
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

void initFirstWindow(lv_obj_t* parent) {
    lv_style_init(&fw.style);
    lv_style_set_bg_color(&fw.style, lv_color_white());
    lv_style_set_border_width(&fw.style, 0);
    lv_style_set_radius(&fw.style, 0);

    fw.name = "FirstWindow";

    fw.container = lv_obj_create(parent);
    lv_obj_set_size(fw.container, 800, 480);
    lv_obj_add_style(fw.container, &fw.style, 0);
    
    fw.label = lv_label_create(fw.container);
    lv_obj_set_size(fw.label, 750, 100);
    lv_obj_set_pos(fw.label, 0, 0);
    fw.setLabelText = setLabelText;
    setLabelText(fw.name);

    fw.spinbox = lv_spinbox_create(fw.container);
    lv_spinbox_set_range(fw.spinbox, -1000, 25000);
    lv_spinbox_set_digit_format(fw.spinbox, 5, 2);
    lv_obj_set_width(fw.spinbox, 100);
    lv_obj_set_size(fw.spinbox, 750, 100);
    lv_obj_set_pos(fw.spinbox, 0, 100);

    fw.controller.visable = OFF;
    fw.controller.getContainer = getContainer;
    fw.controller.getWindowName = getWindowName;

    fw.spinboxSelectLeft = spinboxSelectLeft;
    fw.spinboxSelectRight = spinboxSelectRight;
    fw.spinboxSelectUp = spinboxSelectUp;
    fw.spinboxSelectDown = spinboxSelectDown;

    fw.hasInited = ON;

    getWindowsManager()->registerWindow(&fw.controller, FirstWindow, true);
}
