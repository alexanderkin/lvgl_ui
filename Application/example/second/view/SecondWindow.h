#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include "../../../generic/enum.h"
#include "../interface/ISecondWindow.h"
#include "../../../interface/IWindowController.h"

typedef struct SecondWindow {
    lv_obj_t* container;
    lv_style_t style;
    lv_obj_t* label;
    char* name;
    second_window_i swi;
    window_controller_i controller;
} second_window_t;

void initSecondWindow(lv_obj_t* parent);

#endif // SECONDWINDOW_H
