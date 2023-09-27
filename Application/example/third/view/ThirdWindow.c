#include <stdio.h>
#include "./ThirdWindow.h"
#include "../../../manager/WindowsManager.h"

static third_window_t tw;

static void setLabelText(const char* text) {
    if (tw.hasInited == ON) {
        lv_label_set_text(tw.label, text);
    }
}

static const char* getWindowName() {
    if (tw.hasInited == ON) {
        return tw.name;
    }
    return NULL;
}

static lv_obj_t* getContainer() {
    if (tw.hasInited == ON) {
        return tw.container;
    }
    return NULL;
}

void initThirdWindow(lv_obj_t* parent) {
    lv_style_init(&tw.style);
    lv_style_set_bg_color(&tw.style, lv_color_white());
    lv_style_set_border_width(&tw.style, 0);
    lv_style_set_radius(&tw.style, 0);

    tw.name = "ThirdWindow";

    tw.container = lv_obj_create(parent);
    lv_obj_set_size(tw.container, 800, 480);
    lv_obj_add_style(tw.container, &tw.style, 0);

    tw.label = lv_label_create(tw.container);
    tw.setLabelText = setLabelText;
    setLabelText(tw.name);

    tw.controller.visable = inVisable;
    tw.controller.getContainer = getContainer;
    tw.controller.getWindowName = getWindowName;

    tw.hasInited = ON;
    
    getWindowsManager()->registerWindow(&tw.controller, ThirdWindow, false);
}
