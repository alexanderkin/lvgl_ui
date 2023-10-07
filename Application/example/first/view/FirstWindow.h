#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include "../../../generic/enum.h"
#include "../interface/IFirstWindow.h"
#include "../../../interface/IWindowController.h"

typedef struct FirstWindow {
    lv_obj_t* container;
    lv_style_t style;
    lv_obj_t* label;
    lv_obj_t* spinbox;
        char* name;
    first_window_i fwi;
    window_controller_i controller;
} first_window_t;

void initFirstWindow(lv_obj_t* parent);

#endif // FIRSTWINDOW_H
