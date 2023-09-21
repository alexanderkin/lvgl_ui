#include <stdio.h>
#include "./WindowsManager.h"

static windows_manager_t wm;

static void showWindow(windows_t w) {
    if (wm.windows_stack[w] == NULL) return;
    wm.activedWindow = w;
    lv_obj_clear_flag(wm.windows_stack[w]->getContainer(), LV_OBJ_FLAG_HIDDEN);
}

static void hideWindow(windows_t w) {
    if (wm.windows_stack[w] == NULL) return;
    lv_obj_add_flag(wm.windows_stack[w]->getContainer(), LV_OBJ_FLAG_HIDDEN);
}

static void switchActivedWindow(windows_t w) {
    if (wm.windows_stack[w] == NULL) return;
    printf("switch from %d to %d\n", wm.activedWindow, w);
    hideWindow(wm.activedWindow);
    showWindow(w);
}

static void registerWindow(window_controller_t* window, windows_t w) {
    wm.windows_stack[w] = window;
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
    wm.activedWindow = EndWindow;
    wm.hasShow = OFF;
    wm.registerWindow = registerWindow;
    wm.switchActivedWindow = switchActivedWindow;
    wm.getWindowController = getWindowController;
    wm.getWindow = getWindow;
    wm.getActivedWindow = getActivedWindow;
}
