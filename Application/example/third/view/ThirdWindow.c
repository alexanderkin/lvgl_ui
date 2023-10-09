#include <stdio.h>
#include "./ThirdWindow.h"
#include "../../../generic/macro.h"
#include "../../../manager/WindowsManager.h"

static third_window_t tw;

static void setLabelText(const char* text) {
    lv_label_set_text(tw.label, text);
}

static const char* getWindowName() {
    return tw.name;
}

static lv_obj_t* getContainer() {
    return tw.container;
}

static void* getWindowInterface() {
    return &tw.twi;
}

void initThirdWindow(lv_obj_t* parent) {
    lv_style_init(&tw.style);
    lv_style_set_radius(&tw.style, 0);
    lv_style_set_border_width(&tw.style, 0);
    lv_style_set_bg_color(&tw.style, lv_color_white());

    tw.name = "ThirdWindow";

    tw.container = lv_obj_create(parent);
    lv_obj_remove_style_all(tw.container);
    lv_obj_set_size(tw.container, WINDOWS_WIDTH, WINDOWS_HEIGH);
    lv_obj_set_pos(tw.container, 0, 0);
    lv_obj_add_style(tw.container, &tw.style, 0);

    tw.label = lv_label_create(tw.container);
    setLabelText(tw.name);

    tw.twi.setLabelText = setLabelText;

    tw.controller.visable = inVisable;
    tw.controller.getContainer = getContainer;
    tw.controller.getWindowName = getWindowName;
    tw.controller.getWindowInterface = getWindowInterface;
    
    getWindowsManagerInterface()->registerWindow(&tw.controller, ThirdWindow, false);
}
