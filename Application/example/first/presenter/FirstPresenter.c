﻿#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "./FirstPresenter.h"
#include "../../../generic/enum.h"
#include "../../../generic/struct.h"
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
        fp.windowInterface->selectSpinbox(CH1);
        break;
    case KeySelect2:
        fp.windowInterface->setLabelText("First KeySelect2");
        fp.windowInterface->selectSpinbox(CH2);
        break;
    case KeySelect3:
        fp.windowInterface->setLabelText("First KeySelect3");
        fp.windowInterface->selectSpinbox(CH3);
        break;
    case KeySelect4:
        fp.windowInterface->setLabelText("First KeySelect4");
        fp.windowInterface->selectSpinbox(CH4);
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

static void handleValueChangeEvent(value_change_event_t* event) {
    double v = (double)event->value / pow(10, event->decimals);
    printf("First value = %lld, decimals = %d, result = %f\n", event->value, event->decimals, v);
    fp.modelInterface->setValue((uint64_t)v);
    printf("Model value = %lld\n", fp.modelInterface->getValue());
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

void initFirstPresenter(first_model_i* modelInterface, first_window_i* windowInterface) {
    fp.modelInterface = modelInterface;
    fp.windowInterface = windowInterface;
    fp.controller.handleEvent = handleEvent;
    getEventsManagerInterface()->registerEventHandler(&fp.controller, FirstWindow);
}
