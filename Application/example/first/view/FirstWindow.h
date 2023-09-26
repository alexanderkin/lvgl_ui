#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include "../../../generic/enum.h"
#include "../../../interface/WindowController.h"
#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct FirstWindow {
    window_controller_t controller;
    on_off_t hasInited;
    lv_obj_t* container;
    lv_style_t style;
    lv_obj_t* label;
    lv_obj_t* spinbox;
    void (*spinboxSelectLeft)(lv_obj_t* spinbox);
    void (*spinboxSelectRight)(lv_obj_t* spinbox);
    void (*spinboxSelectUp)(lv_obj_t* spinbox);
    void (*spinboxSelectDown)(lv_obj_t* spinbox);
    char* name;
    void (*setLabelText)(const char* text);
} first_window_t;

void initFirstWindow(lv_obj_t* parent);

#endif // FIRSTWINDOW_H
