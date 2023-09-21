#include <stdio.h>
#include "./SecondPresenter.h"
#include "../manager/WindowsManager.h"

static second_presenter_t sp;

static void handleKeyEvent(key_event_t* event) {
    printf("second presenter event type = %d, key id = %d\n", event->i_event.type, event->key);
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

second_presenter_t* getSecondPresenter() {
    return &sp;
}

void initSecondPresenter(second_window_t* window) {
    sp.window = window;
    sp.subscribe = subscribe;
}