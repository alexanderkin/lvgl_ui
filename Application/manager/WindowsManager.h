#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include "../generic/enum.h"
#include "../interface/WindowController.h"
#include "../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct WindowsManager {
    //通用窗口
    windows_t mainWindow;
    windows_t activedWindow;
    window_controller_t* windows_stack[EndWindow];
    void* (*getWindow)(windows_t w);
    windows_t (*getActivedWindow)();
    void (*switchActivedWindow)(windows_t w);
    window_controller_t* (*getWindowController)(windows_t w);
    void (*registerWindow)(window_controller_t* controller, windows_t w, bool isMainWindow);
    //窗口类型
    windows_type_t activedWindowsType;
    windows_type_t (*getActivedWindowsType)();
    //弹窗
    popup_windows_t activedPopupWindow;
    window_controller_t* popup_stack[EndPopupWindow];
    void (*showPopupWindow)(popup_windows_t p);
    void (*hidePopupWindow)(popup_windows_t p);
    void* (*getPopupWindow)(popup_windows_t p);
    popup_windows_t (*getActivedPopupWindow)();
    window_controller_t* (*getPopupWindowController)(popup_windows_t p);
    void (*registerPopupWindow)(window_controller_t* controller, popup_windows_t p);
} windows_manager_t;

windows_manager_t* getWindowsManager();
void initWindowsManager();

#endif // WINDOWSMANAGER_H
