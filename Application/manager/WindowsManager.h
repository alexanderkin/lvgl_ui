#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include "../interface/enum.h"
#include "../interface/WindowController.h"
#include "../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct WindowsManager {
    on_off_t hasShow;
    windows_t activedWindow;
    window_controller_t* windows_stack[EndWindow];
    void (*switchActivedWindow)(windows_t w);
    void (*registerWindow)(window_controller_t* controller, windows_t w);
    window_controller_t* (*getWindowController)(windows_t w);
    void* (*getWindow)(windows_t w);
    windows_t (*getActivedWindow)();
} windows_manager_t;

void initWindowsManager();
windows_manager_t* getWindowsManager();

#endif // WINDOWSMANAGER_H
