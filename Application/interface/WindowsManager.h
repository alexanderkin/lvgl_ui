#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include "../enum/enum.h"
#include "../LVGL.Simulator/lvgl/lvgl.h"

typedef struct WindowsManager {
    on_off_t hasShow;
    void (*show)(windows_t w);
    void (*hide)(windows_t w);
    void (*registerWindows)(void* window, lv_obj_t *container, windows_t w);
    void* (*getWindow)(windows_t w);
    void* windows_stack[EndWindow];
    lv_obj_t* container_stack[EndWindow];
} windows_manager_t;

void initWindowsManager();
windows_manager_t* getWindowsManager();

#endif // WINDOWSMANAGER_H
