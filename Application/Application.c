#include "Application.h"
#include "./example/lineedit/view/LineEdit.h"
#include "./example/keyboard/view/KeyBoard.h"
#include "./example/first/view/FirstWindow.h"
#include "./example/first/presenter/FirstPresenter.h"
#include "./example/second/view/SecondWindow.h"
#include "./example/second/presenter/SecondPresenter.h"
#include "./example/third/view/ThirdWindow.h"
#include "./example/third/presenter/ThirdPresenter.h"
#include "./manager/WindowsManager.h"
#include "./manager/EventsManager.h"

void initMainApplication(void) {
    lv_obj_t* screen = lv_scr_act();
    initWindowsManager();
    initEventsManager();
    initFirstWindow(screen);
    initFirstPresenter(getWindowsManagerInterface()->getWindow(FirstWindow));
    initSecondWindow(screen);
    initSecondPresenter(getWindowsManagerInterface()->getWindow(SecondWindow));
    initThirdWindow(screen);
    initThirdPresenter(getWindowsManagerInterface()->getWindow(ThirdWindow));
    // initLineEdit(screen);
    initKeyBoard(screen);
}
