#include "Application.h"
#include "./example/lineedit/presenter/LineEditPresenter.h"
#include "./example/lineedit/view/LineEdit.h"
#include "./example/keyboard/view/KeyBoard.h"
#include "./example/first/model/FirstModel.h"
#include "./example/first/view/FirstWindow.h"
#include "./example/first/presenter/FirstPresenter.h"
#include "./example/second/view/SecondWindow.h"
#include "./example/second/presenter/SecondPresenter.h"
#include "./example/third/view/ThirdWindow.h"
#include "./example/third/presenter/ThirdPresenter.h"
#include "./manager/ModelsManager.h"
#include "./manager/EventsManager.h"
#include "./manager/WindowsManager.h"

void initMainApplication(void) {
    lv_obj_t* screen = lv_scr_act();
    initModelsManager();
    initEventsManager();
    initWindowsManager();
    initFirstModel();
    initFirstWindow(screen);
    initFirstPresenter(
        getModelsManagerInterface()->getModelInterface(FirstModel), 
        getWindowsManagerInterface()->getWindowInterface(FirstWindow)
    );
    initSecondWindow(screen);
    initSecondPresenter(getWindowsManagerInterface()->getWindowInterface(SecondWindow));
    initThirdWindow(screen);
    initThirdPresenter(getWindowsManagerInterface()->getWindowInterface(ThirdWindow));
    initLineEdit(screen);
    initLineEditPresenter(getWindowsManagerInterface()->getPopupWindowInterface(LineEditWindow));
    initKeyBoard(screen);
    getModelsManagerInterface()->readTable();
}

void saveTables() {
    getModelsManagerInterface()->saveTable();
}
