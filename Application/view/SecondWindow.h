#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include "../enum/enum.h"
#include "../LVGL.Simulator/lvgl/lvgl.h"

typedef struct SecondWindow {
    on_off_t hasInited;
    lv_obj_t* container;
    lv_label_t* label;
    void (*setLabelText)(const char* text);
} second_window_t;

void initSecondWindow(lv_obj_t* parent);

#endif // SECONDWINDOW_H