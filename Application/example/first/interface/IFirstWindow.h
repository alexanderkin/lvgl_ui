#ifndef IFIRSTWINDOW_H
#define IFIRSTWINDOW_H

#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct IFirstWindow {
    void (*spinboxSelectLeft)(lv_obj_t* spinbox);
    void (*spinboxSelectRight)(lv_obj_t* spinbox);
    void (*spinboxSelectUp)(lv_obj_t* spinbox);
    void (*spinboxSelectDown)(lv_obj_t* spinbox);
    void (*setLabelText)(const char* text);
    lv_obj_t* (*getSpinbox)();
} first_window_i;

#endif // IFIRSTWINDOW_H
