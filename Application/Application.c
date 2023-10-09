#include "Application.h"
#include "./example/lineedit/presenter/LineEditPresenter.h"
#include "./example/lineedit/view/LineEdit.h"
#include "./example/keyboard/view/KeyBoard.h"
#include "./example/first/model/FirstModel.h"
#include "./example/first/view/FirstWindow.h"
#include "./example/first/presenter/FirstPresenter.h"
#include "./example/second/model/SecondModel.h"
#include "./example/second/view/SecondWindow.h"
#include "./example/second/presenter/SecondPresenter.h"
#include "./example/third/view/ThirdWindow.h"
#include "./example/third/presenter/ThirdPresenter.h"
#include "./manager/ModelsManager.h"
#include "./manager/EventsManager.h"
#include "./manager/WindowsManager.h"

/*******************************
* 初始化Application顺序：
* 1、获取全局窗口
* 2、初始化各个管理器
* 3、初始化各个Model
* 4、读Table
* 5、初始化各个View
* 6、初始化各个Presenter
********************************/
void initMainApplication(void) {
    lv_obj_t* screen = lv_scr_act();

    initModelsManager();
    initEventsManager();
    initWindowsManager();

    initFirstModel();
    initSecondModel();

    getModelsManagerInterface()->readTable();

    initFirstWindow(screen);
    initSecondWindow(screen);
    initThirdWindow(screen);
    initLineEdit(screen);
    initKeyBoard(screen);

    initFirstPresenter(
        getModelsManagerInterface()->getModelInterface(FirstModel), 
        getWindowsManagerInterface()->getWindowInterface(FirstWindow)
    );
    initSecondPresenter(
        getModelsManagerInterface()->getModelInterface(SecondModel),
        getWindowsManagerInterface()->getWindowInterface(SecondWindow)
    );
    initThirdPresenter(getWindowsManagerInterface()->getWindowInterface(ThirdWindow));

    initLineEditPresenter(getWindowsManagerInterface()->getPopupWindowInterface(LineEditWindow));
    
}

void saveTables() {
    getModelsManagerInterface()->saveTable();
}
