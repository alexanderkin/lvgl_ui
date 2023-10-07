#include <stdio.h>
#include <math.h>
#include "./SecondPresenter.h"
#include "../../../generic/enum.h"
#include "../../../generic/struct.h"
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

static void handleValueChangeEvent(value_change_event_t* event) {
    float v = (float)(event->value / pow(10, event->decimals));
    printf("First value = %lld, decimals = %d, result = %f\n", event->value, event->decimals, v);
    sp.modelInterface->setValue(v);
    printf("Model value = %f\n", sp.modelInterface->getValue());
}

static void handleEvent(event_type_i* ievent) {
    switch (ievent->event_type)
    {
    case KeyEvent:
        handleKeyEvent((key_event_t*)ievent);
        break;
    case ValueChangeEvent:
        handleValueChangeEvent((value_change_event_t*)ievent);
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
