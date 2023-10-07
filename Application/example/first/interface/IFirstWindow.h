#ifndef IFIRSTWINDOW_H
#define IFIRSTWINDOW_H

#include "../../../generic/enum.h"
#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct IFirstWindow {
    lv_obj_t* (*getSpinbox)();
    void (*spinboxCheckable)(lv_obj_t* spinbox, checkable_t checkable);
    void (*spinboxSelectLeft)(lv_obj_t* spinbox);
    void (*spinboxSelectRight)(lv_obj_t* spinbox);
    void (*spinboxSelectUp)(lv_obj_t* spinbox);
    void (*spinboxSelectDown)(lv_obj_t* spinbox);
    void (*setLabelText)(const char* text);
} first_window_i;

#endif // IFIRSTWINDOW_H
