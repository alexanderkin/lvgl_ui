#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include "../enum/enum.h"
#include "../LVGL.Simulator/lvgl/lvgl.h"
#include "../interface/WindowsController.h"

typedef struct SecondWindow {
    windows_controller_t controller;
    on_off_t hasInited;
    lv_obj_t* container;
    lv_style_t style;
    lv_obj_t* label;
    char* name;
    void (*setLabelText)(const char* text);
} second_window_t;

void initSecondWindow(lv_obj_t* parent);

#endif // SECONDWINDOW_H