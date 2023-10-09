#include <stdio.h>
#include <string.h>
#include "./WindowsManager.h"
#include "../../LVGL.Simulator/lvgl/lvgl.h"

static windows_manager_t wm;

static void showWindow(windows_t w) {
    if (wm.windows_stack[w] == NULL) return;
    wm.activedWindow = w;
    wm.windows_stack[w]->visable = Visable;
    lv_obj_clear_flag(wm.windows_stack[w]->getContainer(), LV_OBJ_FLAG_HIDDEN);
}

static void hideWindow(windows_t w) {
    if (wm.windows_stack[w] == NULL) return;
    if (wm.activedWindow == w) {
        wm.activedWindow = EndWindow;
    }
    wm.windows_stack[w]->visable = inVisable;
    lv_obj_add_flag(wm.windows_stack[w]->getContainer(), LV_OBJ_FLAG_HIDDEN);
}

static void* getWindowInterface(windows_t w) {
    return wm.windows_stack[w]->getWindowInterface();
}

static windows_t getActivedWindow() {
    return wm.activedWindow;
}

static void switchActivedWindow(windows_t w) {
    if (wm.windows_stack[w] == NULL) return;
    hideWindow(wm.activedWindow);
    showWindow(w);
}

static window_controller_i* getWindowController(windows_t w) {
    return wm.windows_stack[w];
}

static void registerWindow(window_controller_i* controller, windows_t w, bool isMainWindow) {
    wm.windows_stack[w] = controller;
    if (isMainWindow) {
        wm.mainWindow = w;
        showWindow(wm.mainWindow);
    } else {
        hideWindow(w);
    }
}

static windows_type_t getActivedWindowsType() {
    if (wm.activedPopupWindow != EndPopupWindow) {
        return PopupWindow;
    }
    return Window;
}

static void hidePopupWindow(popup_windows_t p) {
    if (wm.popup_stack[p] == NULL) return;
    if (wm.activedPopupWindow == p) {
        wm.activedPopupWindow = EndPopupWindow;
    }
    wm.popup_stack[p]->visable = inVisable;
    lv_obj_add_flag(wm.popup_stack[p]->getContainer(), LV_OBJ_FLAG_HIDDEN);
}

static void showPopupWindow(popup_windows_t p) {
    if (wm.popup_stack[p] == NULL) return;
    if (wm.activedPopupWindow != EndPopupWindow) {
        hidePopupWindow(wm.activedPopupWindow);
    }
    wm.activedPopupWindow = p;
    wm.popup_stack[p]->visable = Visable;
    lv_obj_clear_flag(wm.popup_stack[p]->getContainer(), LV_OBJ_FLAG_HIDDEN);
    if (wm.popup_stack[p]->onShow != NULL) {
        wm.popup_stack[p]->onShow();
    }
}

static void* getPopupWindowInterface(popup_windows_t p) {
    return wm.popup_stack[p]->getWindowInterface();
}

static popup_windows_t getActivedPopupWindow() {
    return wm.activedPopupWindow;
}

static window_controller_i* getPopupWindowController(popup_windows_t p) {
    return wm.popup_stack[p];
}

static void registerPopupWindow(window_controller_i* controller, popup_windows_t p) {
    wm.popup_stack[p] = controller;
    hidePopupWindow(p);
}

windows_manager_i* getWindowsManagerInterface() {
    return &wm.wmi;
}

void initWindowsManager() {
    wm.mainWindow = EndWindow;
    wm.activedWindow = EndWindow;
    memset(wm.windows_stack, 0, sizeof(wm.windows_stack));
    wm.wmi.getActivedWindow = getActivedWindow;
    wm.wmi.getWindowInterface = getWindowInterface;
    wm.wmi.getWindowController = getWindowController;
    wm.wmi.switchActivedWindow = switchActivedWindow;
    wm.wmi.registerWindow = registerWindow;

    wm.wmi.getActivedWindowsType = getActivedWindowsType;

    wm.activedPopupWindow = EndPopupWindow;
    memset(wm.popup_stack, 0, sizeof(wm.popup_stack));
    wm.wmi.getActivedPopupWindow = getActivedPopupWindow;
    wm.wmi.getPopupWindowInterface = getPopupWindowInterface;
    wm.wmi.getPopupWindowController = getPopupWindowController;
    wm.wmi.showPopupWindow = showPopupWindow;
    wm.wmi.hidePopupWindow = hidePopupWindow;
    wm.wmi.registerPopupWindow = registerPopupWindow;
}
