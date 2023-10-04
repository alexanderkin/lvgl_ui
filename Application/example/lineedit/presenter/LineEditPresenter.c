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
        lep.popup->addChar(event->key_id - KeyNum0 + 48);
        break;
    case KeyDot:
        lep.popup->addChar('.');
        break;
    case KeyBackspace:
        lep.popup->deleteChar();
        break;
    case KeyEnter:
        const char* text = lep.popup->getCurrentInput();
        getWindowsManagerInterface()->hidePopupWindow(LineEditWindow);
        printf("Current input = %s\n", text);
        //字符串指针，用完之后在clear
        lep.popup->clearInput();
        break;
    case KeyLeft:
        lep.popup->textSelectLeft();
        break;
    case KeyRight:
        lep.popup->textSelectRight();
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