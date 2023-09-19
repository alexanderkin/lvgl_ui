#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include "../enum/enum.h"
#include "../LVGL.Simulator/lvgl/lvgl.h"

typedef struct FirstWindow {
    on_off_t hasInited;
    lv_obj_t* container;
    lv_label_t* label;
    void (*setLabelText)(const char* text);
} first_window_t;

void initFirstWindow(lv_obj_t* parent);

#endif // FIRSTWINDOW_H