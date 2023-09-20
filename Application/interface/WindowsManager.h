﻿#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include "../enum/enum.h"
#include "./WindowController.h"
#include "../LVGL.Simulator/lvgl/lvgl.h"

typedef struct WindowsManager {
    on_off_t hasShow;
    windows_t activedWindow;
    void (*show)(windows_t w);
    void (*hide)(windows_t w);
    void (*registerWindow)(window_controller_t* window, windows_t w);
    window_controller_t* (*getWindowController)(windows_t w);
    void* (*getWindow)(windows_t w);
    void* (*getActivedWindow)();
    window_controller_t* windows_stack[EndWindow];
} windows_manager_t;

void initWindowsManager();
windows_manager_t* getWindowsManager();

#endif // WINDOWSMANAGER_H
