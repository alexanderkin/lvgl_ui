#ifndef WINDOWSMANAGER_H
#define WINDOWSMANAGER_H

#include "../generic/enum.h"
#include "../interface/IWindowsManager.h"
#include "../interface/IWindowController.h"

typedef struct WindowsManager {
    //通用窗口
    windows_t mainWindow;
    windows_t activedWindow;
    window_controller_i* windows_stack[EndWindow];
    //弹窗
    popup_windows_t activedPopupWindow;
    window_controller_i* popup_stack[EndPopupWindow];
    //对外开放接口
    windows_manager_i wmi;
} windows_manager_t;

void initWindowsManager();
windows_manager_i* getWindowsManagerInterface();

#endif // WINDOWSMANAGER_H
