#ifndef IWINDOWCONTROLLER_H
#define IWINDOWCONTROLLER_H

#include "../generic/enum.h"
#include "../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct IWindowController {
    visable_t visable;
    lv_obj_t* (*getContainer)();
    void (*onShow)();
    const char* (*getWindowName)();
    void* (*getWindowInterface)();
} window_controller_i;

#endif // WINDOWCONTROLLER_H
