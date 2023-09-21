#include "Application.h"
#include "./view/KeyBoard.h"
#include "./view/FirstWindow.h"
#include "./view/SecondWindow.h"
#include "./manager/WindowsManager.h"
#include "./manager/EventsManager.h"

void initMainApplication(void) {
    lv_obj_t* screen = lv_scr_act();
    initWindowsManager();
    initEventsManager();
    initFirstWindow(screen);
    initSecondWindow(screen);
    initKeyBoard(screen);
}
