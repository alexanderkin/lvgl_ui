#include <stdio.h>
#include "./LineEditPresenter.h"
#include "../../../generic/enum.h"
#include "../../../generic/struct.h"
#include "../../../manager/EventsManager.h"
#include "../../../manager/WindowsManager.h"

static line_edit_presenter_t lep;

static void handleKeyEvent(key_event_t* event) {
    switch (event->key_id)
    {
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
        printf("line edit key value = %d\n", event->key_id - KeyNum0);
        break;
    case KeyDot:
        printf("line edit key value = .\n");
        break;
    case KeyBackspace:
        printf("line edit key value = <-\n");
        break;
    case KeyEnter:
        getWindowsManagerInterface()->hidePopupWindow(LineEditWindow);
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

void initLineEditPresenter(line_edit_t* popup) {
    lep.popup = popup;
    lep.controller.handleEvent = handleEvent;
    getEventsManagerInterface()->registerPopupEventHandler(&lep.controller, LineEditWindow);
}