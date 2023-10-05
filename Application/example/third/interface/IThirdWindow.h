#ifndef ITHIRDWINDOW_H
#define ITHIRDWINDOW_H

#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct IThirdWindow {
    void (*setLabelText)(const char* text);
} third_window_i;

#endif // ITHIRDWINDOW_H
