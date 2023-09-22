#include <stdio.h>
#include "./FirstPresenter.h"
#include "../interface/enum.h"
#include "../manager/EventsManager.h"
#include "../manager/WindowsManager.h"

static first_presenter_t fp;

static void handleKeyEvent(key_event_t* event) {
    switch (event->key)
    {
    case KeySecond:
        getWindowsManager()->switchActivedWindow(SecondWindow);
        break;
    case KeyThird:
        getWindowsManager()->switchActivedWindow(ThirdWindow);
        break;
    default:
        break;
    }
}

static void handleEvent(i_event_type_t* i_event) {
    switch (i_event->type)
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
    getEventsManager()->registerEventHandler(&fp.controller, FirstWindow);
}