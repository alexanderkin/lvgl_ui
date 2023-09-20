#include "./WindowsManager.h"

static windows_manager_t wm;

static void showWindow(windows_t w) {
    if (wm.windows_stack[w] == NULL) return;
    lv_obj_clear_flag(wm.windows_stack[w]->getContainer(), LV_OBJ_FLAG_HIDDEN);
}

static void hideWindow(windows_t w) {
    if (wm.windows_stack[w] == NULL) return;
    lv_obj_add_flag(wm.windows_stack[w]->getContainer(), LV_OBJ_FLAG_HIDDEN);
}

static void registerWindow(windows_controller_t* window, windows_t w) {
    wm.windows_stack[w] = window;
    if (wm.hasShow == OFF) {
        showWindow(w);
        wm.hasShow = ON;
    } else {
        hideWindow(w);
    }
}

static windows_controller_t* getWindowsController(windows_t w) {
    return wm.windows_stack[w];
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
    wm.show = showWindow;
    wm.hide = hideWindow;
    wm.registerWindows = registerWindow;
    wm.getWindowsController = getWindowsController;
    wm.getWindow = getWindow;
}
