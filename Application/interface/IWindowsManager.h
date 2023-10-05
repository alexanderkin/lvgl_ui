#ifndef IWINDOWSMANAGER_H
#define IWINDOWSMANAGER_H

#include "../generic/enum.h"
#include "../interface/IWindowController.h"

typedef struct IWindowsManager {
    //通用窗口
    windows_t (*getActivedWindow)();
    void* (*getWindowInterface)(windows_t w);
    window_controller_i* (*getWindowController)(windows_t w);
    void (*switchActivedWindow)(windows_t w);
    void (*registerWindow)(window_controller_i* controller, windows_t w, bool isMainWindow);
    //窗口类型
    windows_type_t (*getActivedWindowsType)();
    //弹窗
    popup_windows_t (*getActivedPopupWindow)();
    void* (*getPopupWindowInterface)(popup_windows_t p);
    window_controller_i* (*getPopupWindowController)(popup_windows_t p);
    void (*showPopupWindow)(popup_windows_t p);
    void (*hidePopupWindow)(popup_windows_t p);
    void (*registerPopupWindow)(window_controller_i* controller, popup_windows_t p);
} windows_manager_i;

#endif // IWINDOWSMANAGER_H
