#include <stdio.h>
#include "./FirstPresenter.h"
#include "../../../generic/enum.h"
#include "../../../generic/struct.h"
#include "../../../manager/EventsManager.h"
#include "../../../manager/WindowsManager.h"

static first_presenter_t fp;

static void handleKeyEvent(key_event_t* event) {
    switch (event->key_id)
    {
    case KeyFirst:
        if (getWindowsManagerInterface()->getActivedWindow() != FirstWindow) {
            getWindowsManagerInterface()->switchActivedWindow(FirstWindow);
        }
        break;
    case KeySelect:
        fp.windowInterface->setLabelText("First KeySelect");
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
        fp.windowInterface->spinboxSelectLeft(fp.windowInterface->getSpinbox());
        break;
    case KeyRight:
        fp.windowInterface->spinboxSelectRight(fp.windowInterface->getSpinbox());
        break;
    case KeyUp:
        fp.windowInterface->spinboxSelectUp(fp.windowInterface->getSpinbox());
        break;
    case KeyDown:
        fp.windowInterface->spinboxSelectDown(fp.windowInterface->getSpinbox());
        break;
    default:
        break;
    }
}

static void handleEvent(event_type_i* ievent) {
    switch (ievent->event_type)
    {
    case KeyEvent:
        handleKeyEvent((key_event_t*)ievent);
        break;
    default:
        break;
    }
}

void initFirstPresenter(first_window_i* windowInterface) {
    fp.windowInterface = windowInterface;
    fp.controller.handleEvent = handleEvent;
    getEventsManagerInterface()->registerEventHandler(&fp.controller, FirstWindow);
}
