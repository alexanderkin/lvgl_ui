#include <stdio.h>
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
    case KeySelect:
        sp.window->setLabelText("Second KeySelect");
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

void initSecondPresenter(second_window_t* window) {
    sp.window = window;
    sp.controller.handleEvent = handleEvent;
    getEventsManagerInterface()->registerEventHandler(&sp.controller, SecondWindow);
}