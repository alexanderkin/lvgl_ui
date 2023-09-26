#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include "../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct WindowController {
    on_off_t visable;
    lv_obj_t* (*getContainer)();
    const char* (*getWindowName)();
} window_controller_t;


#endif // WINDOWCONTROLLER_H
