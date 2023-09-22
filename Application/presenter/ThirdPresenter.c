#include <stdio.h>
#include "./ThirdPresenter.h"
#include "../interface/enum.h"
#include "../manager/EventsManager.h"
#include "../manager/WindowsManager.h"

static third_presenter_t tp;

static void handleKeyEvent(key_event_t* event) {
    switch (event->key)
    {
    case KeyFirst:
    case KeyThird:
        getWindowsManager()->switchActivedWindow(FirstWindow);
        break;
    case KeySecond:
        getWindowsManager()->switchActivedWindow(SecondWindow);
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

void initThirdPresenter(third_window_t* window) {
    tp.window = window;
    tp.controller.handleEvent = handleEvent;
    getEventsManager()->registerEventHandler(&tp.controller, ThirdWindow);
}