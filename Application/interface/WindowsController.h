#ifndef WINDOWSCONTROLLER_H
#define WINDOWSCONTROLLER_H

#include "../LVGL.Simulator/lvgl/lvgl.h"

typedef struct WindowsController {
    lv_obj_t* (*getContainer)();
    const char* (*getWindowName)();
} windows_controller_t;


#endif // WINDOWSCONTROLLER_H