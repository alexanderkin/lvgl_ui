#ifndef LINEEDIT_H
#define LINEEDIT_H

#include "../../../generic/enum.h"
#include "../../../interface/IWindowController.h"
#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct LineEdit {
    window_controller_i controller;
    lv_obj_t* container;
    lv_style_t container_style;
    lv_obj_t* area;
    lv_style_t area_style;
    lv_obj_t* title;
    lv_style_t title_style;
    lv_obj_t* line;
    lv_point_t line_points[2];
    lv_style_t line_style;
    lv_obj_t* input_area;
    lv_style_t input_style;
    char* name;
    on_off_t hasDot;
    void (*addChar)(const char c);
    void (*deleteChar)();
    void (*textSelectLeft)();
    void (*textSelectRight)();
    const char* (*getCurrentInput)();
    void (*clearInput)();
} line_edit_t;

void initLineEdit(lv_obj_t* parent);

#endif // LINEEDIT_H