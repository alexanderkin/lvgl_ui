#include <stdio.h>
#include "./ThirdPresenter.h"
#include "../../../generic/enum.h"
#include "../../../generic/struct.h"
#include "../../../manager/EventsManager.h"
#include "../../../manager/WindowsManager.h"

static third_presenter_t tp;

static void handleKeyEvent(key_event_t* event) {
    switch (event->key_id)
    {
    case KeyThird:
        if (getWindowsManagerInterface()->getActivedWindow() != ThirdWindow) {
            getWindowsManagerInterface()->switchActivedWindow(ThirdWindow);
        } else {
            getWindowsManagerInterface()->switchActivedWindow(FirstWindow);
        }
        break;
    case KeySelect:
        tp.windowInterface->setLabelText("Third KeySelect");
        break;
    case KeyLeft:
        tp.windowInterface->setLabelText("Third KeyLeft");
        break;
    case KeyRight:
        tp.windowInterface->setLabelText("Third KeyRight");
        break;
    case KeyUp:
        tp.windowInterface->setLabelText("Third KeyUp");
        break;
    case KeyDown:
        tp.windowInterface->setLabelText("Third KeyDown");
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

void initThirdPresenter(third_window_i* windowInterface) {
    tp.windowInterface = windowInterface;
    tp.controller.handleEvent = handleEvent;
    getEventsManagerInterface()->registerEventHandler(&tp.controller, ThirdWindow);
}
