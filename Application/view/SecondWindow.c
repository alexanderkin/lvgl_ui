#include <stdio.h>
#include "./SecondWindow.h"
#include "../interface/WindowsManager.h"

static second_window_t sw;

static void setLabelText(const char* text) {
    if (sw.hasInited == ON) {
        lv_label_set_text(sw.label, text);
    }
}

static const char* getWindowName() {
    return sw.name;
}

static lv_obj_t* getContainer() {
    return sw.container;
}

void initSecondWindow(lv_obj_t* parent) {
    lv_style_init(&sw.style);
    lv_style_set_bg_color(&sw.style, lv_color_white());

    sw.controller.getContainer = getContainer;
    sw.controller.getWindowName = getWindowName;

    sw.hasInited = ON;

    sw.name = "SecondWindow";

    sw.container = lv_obj_create(parent);
    lv_obj_set_size(sw.container, 800, 480);
    lv_obj_add_style(sw.container, &sw.style, 0);

    sw.label = lv_label_create(sw.container);
    sw.setLabelText = setLabelText;
    setLabelText("SecondWindow");
    getWindowsManager()->registerWindows(&sw.controller, SecondWindow);
}
