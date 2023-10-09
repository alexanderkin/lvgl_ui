#ifndef IFIRSTWINDOW_H
#define IFIRSTWINDOW_H

#include <stdint.h>
#include "../../../generic/enum.h"
#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct IFirstWindow {
    void (*selectSpinbox)(channel_t channel);
    void (*spinboxCheckable)(checkable_t checkable);
    void (*spinboxSelectLeft)();
    void (*spinboxSelectRight)();
    void (*spinboxSelectUp)();
    void (*spinboxSelectDown)();
    void (*spinboxSetValue)(uint64_t value);
    boolean_t (*allowKeyBoardInput)();
    void (*setLabelText)(const char* text);
} first_window_i;

#endif // IFIRSTWINDOW_H
