#include <stdio.h>
#include "./FirstPresenter.h"
#include "../../../generic/enum.h"
#include "../../../manager/EventsManager.h"
#include "../../../manager/WindowsManager.h"

static first_presenter_t fp;

static void handleKeyEvent(key_event_t* event) {
    switch (event->key_id)
    {
    case KeySecond:
        getWindowsManagerInterface()->switchActivedWindow(SecondWindow);
        break;
    case KeyThird:
        getWindowsManagerInterface()->switchActivedWindow(ThirdWindow);
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
        printf("key value = %d\n", event->key_id - KeyNum0);
        break;
    case KeyDot:
        printf("key value = .\n");
        break;
    case KeyBackspace:
        printf("key value = <-\n");
        break;
    case KeyEnter:
        printf("key value = Enter\n");
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
    getEventsManager()->registerEventHandler(&fp.controller, FirstWindow);
}