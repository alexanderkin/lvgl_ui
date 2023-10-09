#ifndef IFIRSTWINDOW_H
#define IFIRSTWINDOW_H

#include <stdint.h>
#include <stdbool.h>
#include "../../../generic/enum.h"
#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct IFirstWindow {
    void (*selectSpinbox)(channel_t channel, bool view);
    void (*spinboxCheckable)(checkable_t checkable);
    void (*spinboxSelectLeft)();
    void (*spinboxSelectRight)();
    void (*spinboxSelectUp)();
    void (*spinboxSelectDown)();
    void (*spinboxSetValue)(uint64_t value);
    bool (*allowKeyBoardInput)();
    void (*setLabelText)(const char* text);
} first_window_i;

#endif // IFIRSTWINDOW_H
