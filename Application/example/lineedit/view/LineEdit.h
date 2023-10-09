#ifndef LINEEDIT_H
#define LINEEDIT_H

#include "../../../generic/enum.h"
#include "../interface/ILineEdit.h"
#include "../../../interface/IWindowController.h"

typedef struct LineEdit {
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
    lv_timer_t* timer;
    char* name;
    on_off_t hasDot;
    line_edit_i lei;
    window_controller_i controller;
} line_edit_t;

void initLineEdit(lv_obj_t* parent);

#endif // LINEEDIT_H
