#include <stdio.h>
#include "./SecondWindow.h"
#include "../../../generic/macro.h"
#include "../../../manager/WindowsManager.h"

static second_window_t sw;

static void setLabelText(const char* text) {
    lv_label_set_text(sw.label, text);
}

static const char* getWindowName() {
    return sw.name;
}

static lv_obj_t* getContainer() {
    return sw.container;
}

void initSecondWindow(lv_obj_t* parent) {
    lv_style_init(&sw.style);
    lv_style_set_radius(&sw.style, 0);
    lv_style_set_border_width(&sw.style, 0);
    lv_style_set_bg_color(&sw.style, lv_color_white());

    sw.name = "SecondWindow";

    sw.container = lv_obj_create(parent);
    lv_obj_set_size(sw.container, WINDOWS_WIDTH, WINDOWS_HEIGH);
    lv_obj_set_pos(sw.container, 0, 0);
    lv_obj_add_style(sw.container, &sw.style, 0);

    sw.label = lv_label_create(sw.container);
    sw.setLabelText = setLabelText;
    setLabelText(sw.name);

    sw.controller.visable = inVisable;
    sw.controller.getContainer = getContainer;
    sw.controller.getWindowName = getWindowName;
    
    getWindowsManagerInterface()->registerWindow(&sw.controller, SecondWindow, false);
}
