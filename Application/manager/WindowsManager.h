#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include "../generic/enum.h"
#include "../interface/WindowController.h"
#include "../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct WindowsManager {
    on_off_t hasShow;
    windows_t mainWindow;
    windows_t activedWindow;
    window_controller_t* windows_stack[EndWindow];
    void* (*getWindow)(windows_t w);
    void (*switchActivedWindow)(windows_t w);
    window_controller_t* (*getWindowController)(windows_t w);
    void (*registerWindow)(window_controller_t* controller, windows_t w, bool isMainWindow);
    windows_t (*getActivedWindow)();
} windows_manager_t;

windows_manager_t* getWindowsManager();
void initWindowsManager();

#endif // WINDOWSMANAGER_H
