#ifndef LINEEDIT_H
#define LINEEDIT_H

#include "../../../generic/enum.h"
#include "../../../interface/IWindowController.h"
#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct LineEdit {
    window_controller_i controller;
    on_off_t hasInited;
    lv_obj_t* container;
    lv_style_t style;
    char* name;
} line_edit_t;

void initLineEdit(lv_obj_t* parent);

#endif // LINEEDIT_H