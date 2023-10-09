#include <stdio.h>
#include "./SecondPresenter.h"
#include "../../../generic/enum.h"
#include "../../../generic/struct.h"
#include "../../../tools/StringTools.h"
#include "../../../manager/EventsManager.h"
#include "../../../manager/WindowsManager.h"

static second_presenter_t sp;

static void handleKeyEvent(key_event_t* event) {
    switch (event->key_id)
    {
    case KeySecond:
        if (getWindowsManagerInterface()->getActivedWindow() != SecondWindow) {
            getWindowsManagerInterface()->switchActivedWindow(SecondWindow);
        } else {
            getWindowsManagerInterface()->switchActivedWindow(FirstWindow);
        }
        break;
    case KeySelect1:
        sp.windowInterface->setLabelText("Second KeySelect1");
        break;
    case KeyNum0:
    case KeyNum1:
    case KeyNum2:
    case KeyNum3:
    case KeyNum4:
    case KeyNum5:
    case KeyNum6:
    case KeyNum7:
    case KeyNum8:
    case KeyNum9:
        getWindowsManagerInterface()->showPopupWindow(LineEditWindow);
        getEventsManagerInterface()->postEvent(&(event->ievent));
        break;
    case KeyLeft:
        sp.windowInterface->setLabelText("Second KeyLeft");
        break;
    case KeyRight:
        sp.windowInterface->setLabelText("Second KeyRight");
        break;
    case KeyUp:
        sp.windowInterface->setLabelText("Second KeyUp");
        break;
    case KeyDown:
        sp.windowInterface->setLabelText("Second KeyDown");
        break;
    default:
        break;
    }
}

static void handleLineEditChangeEvent(line_edit_change_event_t* event) {
    sp.modelInterface->setValue(getValueFromLineEditString(event->value));
}

static void handleEvent(event_type_i* ievent) {
    switch (ievent->event_type)
    {
    case KeyEvent:
        handleKeyEvent((key_event_t*)ievent);
        break;
    case ValueChangeEvent:
        handleLineEditChangeEvent((line_edit_change_event_t*)ievent);
        break;
    default:
        break;
    }
}

void initSecondPresenter(second_model_i* modelInterface, second_window_i* windowInterface) {
    sp.modelInterface = modelInterface;
    sp.windowInterface = windowInterface;
    sp.controller.handleEvent = handleEvent;
    getEventsManagerInterface()->registerEventHandler(&sp.controller, SecondWindow);
}
