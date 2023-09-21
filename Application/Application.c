#include "Application.h"
#include "./view/KeyBoard.h"
#include "./view/FirstWindow.h"
#include "./presenter/FirstPresenter.h"
#include "./view/SecondWindow.h"
#include "./presenter/SecondPresenter.h"
#include "./view/ThirdWindow.h"
#include "./presenter/ThirdPresenter.h"
#include "./manager/WindowsManager.h"
#include "./manager/EventsManager.h"

void initMainApplication(void) {
    lv_obj_t* screen = lv_scr_act();
    initWindowsManager();
    initEventsManager();
    initFirstWindow(screen);
    initFirstPresenter(getWindowsManager()->getWindow(FirstWindow));
    initSecondWindow(screen);
    initSecondPresenter(getWindowsManager()->getWindow(SecondWindow));
    initThirdWindow(screen);
    initThirdPresenter(getWindowsManager()->getWindow(ThirdWindow));
    initKeyBoard(screen);
}
