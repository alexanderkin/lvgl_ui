#ifndef IWINDOWSMANAGER_H
#define IWINDOWSMANAGER_H

#include "../generic/enum.h"
#include "../interface/IWindowController.h"

typedef struct IWindowsManager {
    //通用窗口
    void* (*getWindow)(windows_t w);
    windows_t (*getActivedWindow)();
    void (*switchActivedWindow)(windows_t w);
    window_controller_i* (*getWindowController)(windows_t w);
    void (*registerWindow)(window_controller_i* controller, windows_t w, bool isMainWindow);
    //窗口类型
    windows_type_t (*getActivedWindowsType)();
    //弹窗
    void (*showPopupWindow)(popup_windows_t p);
    void (*hidePopupWindow)(popup_windows_t p);
    void* (*getPopupWindow)(popup_windows_t p);
    popup_windows_t (*getActivedPopupWindow)();
    window_controller_i* (*getPopupWindowController)(popup_windows_t p);
    void (*registerPopupWindow)(window_controller_i* controller, popup_windows_t p);
} windows_manager_i;

#endif // IWINDOWSMANAGER_H