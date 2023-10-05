#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include "../../../generic/enum.h"
#include "../interface/IThirdWindow.h"
#include "../../../interface/IWindowController.h"

typedef struct ThirdWindow {
    lv_obj_t* container;
    lv_style_t style;
    lv_obj_t* label;
    char* name;
    third_window_i twi;
    window_controller_i controller;
} third_window_t;

void initThirdWindow(lv_obj_t* parent);

#endif // THIRDWINDOW_H
