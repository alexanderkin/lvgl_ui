#include "Application.h"
#include "./view/FirstWindow.h"
#include "./view/SecondWindow.h"
#include "./interface/WindowsManager.h"

void initMainApplication(void) {
    lv_obj_t* screen = lv_scr_act();
    initWindowsManager();
    initFirstWindow(screen);
    initSecondWindow(screen);
}
