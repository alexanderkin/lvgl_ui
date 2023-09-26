#include <stdio.h>
#include "./SecondPresenter.h"
#include "../../../generic/enum.h"
#include "../../../manager/EventsManager.h"
#include "../../../manager/WindowsManager.h"

static second_presenter_t sp;

static void handleKeyEvent(key_event_t* event) {
    switch (event->key)
    {
    case KeyFirst:
    case KeySecond:
        getWindowsManager()->switchActivedWindow(FirstWindow);
        break;
    case KeyThird:
        getWindowsManager()->switchActivedWindow(ThirdWindow);
        break;
    case KeySelect1:
        sp.window->setLabelText("Second KeySelect1");
        break;
    case KeyLeft:
        sp.window->setLabelText("Second KeyLeft");
        break;
    case KeyRight:
        sp.window->setLabelText("Second KeyRight");
        break;
    case KeyUp:
        sp.window->setLabelText("Second KeyUp");
        break;
    case KeyDown:
        sp.window->setLabelText("Second KeyDown");
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

void initSecondPresenter(second_window_t* window) {
    sp.window = window;
    sp.controller.handleEvent = handleEvent;
    getEventsManager()->registerEventHandler(&sp.controller, SecondWindow);
}