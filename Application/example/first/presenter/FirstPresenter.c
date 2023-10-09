#include <stdio.h>
#include <stdbool.h>
#include "./FirstPresenter.h"
#include "../../../generic/enum.h"
#include "../../../generic/struct.h"
#include "../../../tools/StringTools.h"
#include "../../../manager/EventsManager.h"
#include "../../../manager/WindowsManager.h"

static first_presenter_t fp;

static void handleKeyChangeFocus(key_type_t id) {
    switch (id)
    {
    case KeySelect1:
    case KeySelect2:
    case KeySelect3:
    case KeySelect4:
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
    case KeyDot:
    case KeyBackspace:
    case KeyLeft:
    case KeyRight:
    case KeyUp:
    case KeyDown:
        fp.windowInterface->spinboxCheckable(Checked);
        break;
    default:
        fp.windowInterface->spinboxCheckable(UnCheck);
        break;
    }
}

static void handleKeyEvent(key_event_t* event) {
    handleKeyChangeFocus(event->key_id);
    switch (event->key_id)
    {
    case KeyFirst:
        if (getWindowsManagerInterface()->getActivedWindow() != FirstWindow) {
            getWindowsManagerInterface()->switchActivedWindow(FirstWindow);
        }
        break;
    case KeySelect1:
        fp.windowInterface->setLabelText("First KeySelect1");
        fp.windowInterface->selectSpinbox(CH1, true);
        fp.ch = CH1;
        break;
    case KeySelect2:
        fp.windowInterface->setLabelText("First KeySelect2");
        fp.windowInterface->selectSpinbox(CH2, true);
        fp.ch = CH2;
        break;
    case KeySelect3:
        fp.windowInterface->setLabelText("First KeySelect3");
        fp.windowInterface->selectSpinbox(CH3, true);
        fp.ch = CH3;
        break;
    case KeySelect4:
        fp.windowInterface->setLabelText("First KeySelect4");
        fp.windowInterface->selectSpinbox(CH4, true);
        fp.ch = CH4;
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
        if (!fp.windowInterface->allowKeyBoardInput()) return;
        getWindowsManagerInterface()->showPopupWindow(LineEditWindow);
        getEventsManagerInterface()->postEvent(&(event->ievent));
        break;
    case KeyLeft:
        fp.windowInterface->spinboxSelectLeft();
        break;
    case KeyRight:
        fp.windowInterface->spinboxSelectRight();
        break;
    case KeyUp:
        fp.windowInterface->spinboxSelectUp();
        break;
    case KeyDown:
        fp.windowInterface->spinboxSelectDown();
        break;
    default:
        break;
    }
}

static void handleLineEditChangeEvent(line_edit_change_event_t* event) {
    fp.modelInterface->setValue(fp.ch, getValueFromLineEditString(event->value));
    fp.windowInterface->spinboxSetValue(fp.modelInterface->getValue(fp.ch));
}

static void handleEvent(event_type_i* ievent) {
    switch (ievent->event_type)
    {
    case KeyEvent:
        handleKeyEvent((key_event_t*)ievent);
        break;
    case ValueChangeEvent:
        handleLineEditChangeEvent((line_edit_change_event_t*)ievent);
        fp.windowInterface->spinboxCheckable(UnCheck);
        break;
    default:
        break;
    }
}

static void initValueFromModel() {
    for (uint8_t i = 0; i < EndChannel; i++) {
        fp.windowInterface->selectSpinbox(i, false);
        fp.windowInterface->spinboxSetValue(fp.modelInterface->getValue(i));
        fp.windowInterface->spinboxCheckable(UnCheck);
    }
}

void initFirstPresenter(first_model_i* modelInterface, first_window_i* windowInterface) {
    fp.modelInterface = modelInterface;
    fp.windowInterface = windowInterface;
    fp.controller.handleEvent = handleEvent;
    initValueFromModel();
    getEventsManagerInterface()->registerEventHandler(&fp.controller, FirstWindow);
}
