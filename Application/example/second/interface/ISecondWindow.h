#ifndef ISECONDWINDOW_H
#define ISECONDWINDOW_H

#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct ISecondWindow {
    void (*setLabelText)(const char* text);
} second_window_i;

#endif // ISECONDWINDOW_H
