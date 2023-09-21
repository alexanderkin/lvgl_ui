#include <stdio.h>
#include "./ThirdPresenter.h"
#include "../manager/WindowsManager.h"

static third_presenter_t tp;

static void handleKeyEvent(key_event_t* event) {
    printf("third presenter event type = %d, key id = %d\n", event->i_event.type, event->key);
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

third_presenter_t* getThirdPresenter() {
    return &tp;
}

void initThirdPresenter(third_window_t* window) {
    tp.window = window;
    tp.subscribe = subscribe;
}