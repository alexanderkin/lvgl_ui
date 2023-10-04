#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include "../../../generic/enum.h"
#include "../../../interface/IWindowController.h"
#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct ThirdWindow {
    window_controller_i controller;
    lv_obj_t* container;
    lv_style_t style;
    lv_obj_t* label;
    char* name;
    void (*setLabelText)(const char* text);
} third_window_t;

void initThirdWindow(lv_obj_t* parent);

#endif // THIRDWINDOW_H
