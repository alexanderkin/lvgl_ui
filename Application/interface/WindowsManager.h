#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include "../enum/enum.h"
#include "./WindowsController.h"
#include "../LVGL.Simulator/lvgl/lvgl.h"

typedef struct WindowsManager {
    on_off_t hasShow;
    void (*show)(windows_t w);
    void (*hide)(windows_t w);
    void (*registerWindows)(windows_controller_t* window, windows_t w);
    windows_controller_t* (*getWindowsController)(windows_t w);
    void* (*getWindow)(windows_t w);
    windows_controller_t* windows_stack[EndWindow];
} windows_manager_t;

void initWindowsManager();
windows_manager_t* getWindowsManager();

#endif // WINDOWSMANAGER_H
