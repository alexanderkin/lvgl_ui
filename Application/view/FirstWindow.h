#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include "../interface/enum.h"
#include "../interface/WindowController.h"
#include "../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct FirstWindow {
    window_controller_t controller;
    on_off_t hasInited;
    lv_obj_t* container;
    lv_style_t style;
    lv_obj_t* label;
    char* name;
    void (*setLabelText)(const char* text);
} first_window_t;

void initFirstWindow(lv_obj_t* parent);

#endif // FIRSTWINDOW_H
