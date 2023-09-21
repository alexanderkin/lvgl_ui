#include <stdio.h>
#include "./SecondPresenter.h"
#include "../interface/enum.h"
#include "../manager/EventsManager.h"
#include "../manager/WindowsManager.h"

static second_presenter_t sp;

static void handleKeyEvent(key_event_t* event) {
    switch (event->key)
    {
    case KeyFirst:
        getWindowsManager()->switchActivedWindow(FirstWindow);
        break;
    case KeySecond:
        printf("already in second window\n");
        break;
    case KeyThird:
        getWindowsManager()->switchActivedWindow(ThirdWindow);
        break;
    default:
        break;
    }
}

static void subscribe(i_event_type_t* i_event) {
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
    sp.controller.subscribe = subscribe;
    getEventsManager()->registerEvent(&sp.controller, SecondWindow);
}