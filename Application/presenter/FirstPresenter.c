#include <stdio.h>
#include "./FirstPresenter.h"
#include "../manager/WindowsManager.h"

static first_presenter_t fp;

static void handleKeyEvent(key_event_t* event) {
    printf("first presenter event type = %d, key id = %d\n", event->i_event.type, event->key);
    switch (event->key)
    {
    case KeyFirst:
        getWindowsManager()->switchActivedWindow(FirstWindow);
        break;
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

first_presenter_t* getFirstPresenter() {
    return &fp;
}

void initFirstPresenter(first_window_t* window) {
    fp.window = window;
    fp.subscribe = subscribe;
}