#include <stdio.h>
#include "./WindowsManager.h"

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

static void* getWindow(windows_t w) {
    return (void*)wm.windows_stack[w];
}

static windows_t getActivedWindow() {
    return wm.activedWindow;
}

static void switchActivedWindow(windows_t w) {
    if (wm.windows_stack[w] == NULL) return;
    hideWindow(wm.activedWindow);
    showWindow(w);
}

static window_controller_t* getWindowController(windows_t w) {
    return wm.windows_stack[w];
}

static void registerWindow(window_controller_t* controller, windows_t w, bool isMainWindow) {
    wm.windows_stack[w] = controller;
    if (isMainWindow) {
        wm.mainWindow = w;
        showWindow(wm.mainWindow);
    } else {
        hideWindow(w);
    }
}

static windows_type_t getActivedWindowsType() {
    return wm.activedWindowsType;
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
}

static void* getPopupWindow(popup_windows_t p) {
    return (void*)wm.popup_stack[p];
}

static popup_windows_t getActivedPopupWindow() {
    return wm.activedPopupWindow;
}

static window_controller_t* getPopupWindowController(popup_windows_t p) {
    return wm.popup_stack[p];
}

static void registerPopupWindow(window_controller_t* controller, popup_windows_t p) {
    wm.popup_stack[p] = controller;
    hidePopupWindow(p);
}

windows_manager_t* getWindowsManager() {
    return &wm;
}

void initWindowsManager() {
    wm.mainWindow = EndWindow;
    wm.activedWindow = EndWindow;
    memset(wm.windows_stack, 0, sizeof(wm.windows_stack));
    wm.getWindow = getWindow;
    wm.getActivedWindow = getActivedWindow;
    wm.switchActivedWindow = switchActivedWindow;
    wm.getWindowController = getWindowController;
    wm.registerWindow = registerWindow;

    wm.activedWindowsType = Window;
    wm.getActivedWindowsType = getActivedWindowsType;

    wm.activedPopupWindow = EndPopupWindow;
    memset(wm.popup_stack, 0, sizeof(wm.popup_stack));
    wm.showPopupWindow = showPopupWindow;
    wm.hidePopupWindow = hidePopupWindow;
    wm.getPopupWindow = getPopupWindow;
    wm.getActivedPopupWindow = getActivedPopupWindow;
    wm.getPopupWindowController = getPopupWindowController;
    wm.registerPopupWindow = registerPopupWindow;
}
