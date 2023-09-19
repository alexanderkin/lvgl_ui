#include "./WindowsManager.h"

static windows_manager_t wm;

static void showWindow(windows_t w) {
    if (wm.container_stack[w] == NULL) return;
    lv_obj_clear_flag(wm.container_stack[w], LV_OBJ_FLAG_HIDDEN);
}

static void hideWindow(windows_t w) {
    if (wm.container_stack[w] == NULL) return;
    lv_obj_add_flag(wm.container_stack[w], LV_OBJ_FLAG_HIDDEN);
}

static void registerWindow(void* window, lv_obj_t *container, windows_t w) {
    wm.windows_stack[w] = window;
    wm.container_stack[w] = container;
    if (wm.hasShow == OFF) {
        showWindow(w);
        wm.hasShow = ON;
    } else {
        hideWindow(w);
    }
}

static void* getWindow(windows_t w) {
    return wm.windows_stack[w];
}

windows_manager_t* getWindowsManager() {
    return &wm;
}

void initWindowsManager() {
    memset(wm.windows_stack, 0, sizeof(wm.windows_stack));
    memset(wm.container_stack, 0, sizeof(wm.container_stack));
    wm.hasShow = OFF;
    wm.show = showWindow;
    wm.hide = hideWindow;
    wm.registerWindows = registerWindow;
    wm.getWindow = getWindow;
}
