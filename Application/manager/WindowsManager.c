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
    wm.windows_stack[w]->visable = inVisable;
    lv_obj_add_flag(wm.windows_stack[w]->getContainer(), LV_OBJ_FLAG_HIDDEN);
}

static void switchActivedWindow(windows_t w) {
    if (wm.windows_stack[w] == NULL) return;
    hideWindow(wm.activedWindow);
    showWindow(w);
}

static void registerWindow(window_controller_t* controller, windows_t w, bool isMainWindow) {
    wm.windows_stack[w] = controller;
    if (isMainWindow) {
        wm.mainWindow = w;
    }
    if (wm.hasShow == OFF) {
        showWindow(w);
        wm.hasShow = ON;
    } else {
        hideWindow(w);
    }
}

static window_controller_t* getWindowController(windows_t w) {
    return wm.windows_stack[w];
}

static windows_t getActivedWindow() {
    return wm.activedWindow; 
}

static void* getWindow(windows_t w) {
    return (void*)wm.windows_stack[w];
}

static void showPopupWindow(popup_windows_t p) {
    if (wm.popup_windows_stack[p] == NULL) return;
    wm.popup_windows_stack[p]->visable = Visable;
    lv_obj_clear_flag(wm.popup_windows_stack[p]->getContainer(), LV_OBJ_FLAG_HIDDEN);
}

static void hidePopupWindow(popup_windows_t p) {
    if (wm.popup_windows_stack[p] == NULL) return;
    wm.popup_windows_stack[p]->visable = inVisable;
    lv_obj_add_flag(wm.popup_windows_stack[p]->getContainer(), LV_OBJ_FLAG_HIDDEN);
}

static visable_t getPopupWindowStatus(popup_windows_t p) {
    return wm.popup_windows_stack[p]->visable;
}

static void registerPopupWindow(window_controller_t* controller, popup_windows_t p) {
    wm.popup_windows_stack[p] = controller;
    hidePopupWindow(p);
}

windows_manager_t* getWindowsManager() {
    return &wm;
}

void initWindowsManager() {
    memset(wm.windows_stack, 0, sizeof(wm.windows_stack));
    wm.hasShow = OFF;
    wm.mainWindow = EndWindow;
    wm.activedWindow = EndWindow;
    wm.getWindow = getWindow;
    wm.registerWindow = registerWindow;
    wm.getActivedWindow = getActivedWindow;
    wm.switchActivedWindow = switchActivedWindow;
    wm.getWindowController = getWindowController;
    
    memset(wm.popup_windows_stack, 0, sizeof(wm.popup_windows_stack));
    wm.showPopupWindow = showPopupWindow;
    wm.hidePopupWindow = hidePopupWindow;
    wm.getPopupWindowStatus = getPopupWindowStatus;
    wm.registerPopupWindow = registerPopupWindow;
}
