#include <stdio.h>
#include "./WindowsManager.h"

static windows_manager_t wm;

static void showWindow(windows_t w) {
    if (wm.windows_stack[w] == NULL) return;
    wm.activedWindow = w;
    wm.windows_stack[w]->visable = ON;
    lv_obj_clear_flag(wm.windows_stack[w]->getContainer(), LV_OBJ_FLAG_HIDDEN);
}

static void hideWindow(windows_t w) {
    if (wm.windows_stack[w] == NULL) return;
    wm.windows_stack[w]->visable = OFF;
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
}
