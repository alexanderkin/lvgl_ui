#include <stdio.h>
#include "./FirstWindow.h"
#include "../manager/WindowsManager.h"

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

void initFirstWindow(lv_obj_t* parent) {
    lv_style_init(&fw.style);
    lv_style_set_bg_color(&fw.style, lv_color_white());
    lv_style_set_border_width(&fw.style, 0);
    lv_style_set_radius(&fw.style, 0);

    fw.controller.getContainer = getContainer;
    fw.controller.getWindowName = getWindowName;

    fw.hasInited = ON;

    fw.name = "FirstWindow";

    fw.container = lv_obj_create(parent);
    lv_obj_set_size(fw.container, 800, 480);
    lv_obj_add_style(fw.container, &fw.style, 0);
    
    fw.label = lv_label_create(fw.container);
    fw.setLabelText = setLabelText;
    setLabelText(fw.name);
    getWindowsManager()->registerWindow(&fw.controller, FirstWindow, true);
}
