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
        fp.window->setLabelText("First KeySelect");
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
        getEventsManagerInterface()->postEvent(&(event->i_event));
        break;
    case KeyLeft:
        fp.window->spinboxSelectLeft(fp.window->spinbox);
        break;
    case KeyRight:
        fp.window->spinboxSelectRight(fp.window->spinbox);
        break;
    case KeyUp:
        fp.window->spinboxSelectUp(fp.window->spinbox);
        break;
    case KeyDown:
        fp.window->spinboxSelectDown(fp.window->spinbox);
        break;
    default:
        break;
    }
}

static void handleEvent(i_event_type_t* i_event) {
    switch (i_event->event_type)
    {
    case KeyEvent:
        handleKeyEvent((key_event_t*)i_event);
        break;
    default:
        break;
    }
}

void initFirstPresenter(first_window_t* window) {
    fp.window = window;
    fp.controller.handleEvent = handleEvent;
    getEventsManagerInterface()->registerEventHandler(&fp.controller, FirstWindow);
}