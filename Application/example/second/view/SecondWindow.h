#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include "../../../generic/enum.h"
#include "../../../interface/IWindowController.h"
#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct SecondWindow {
    window_controller_i controller;
    on_off_t hasInited;
    lv_obj_t* container;
    lv_style_t style;
    lv_obj_t* label;
    char* name;
    void (*setLabelText)(const char* text);
} second_window_t;

void initSecondWindow(lv_obj_t* parent);

#endif // SECONDWINDOW_H
