#include <stdio.h>
#include <string.h>
#include "./LineEditPresenter.h"
#include "../../../generic/enum.h"
#include "../../../generic/struct.h"
#include "../../../manager/EventsManager.h"
#include "../../../manager/WindowsManager.h"

static line_edit_presenter_t lep;

static void handleTimerStatus(key_event_t* event) {
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
    case KeyLeft:
    case KeyRight:
    case KeyDot:
    case KeyBackspace:
        lep.popupInterface->resetTimer();
        break;
    default:
        break;
    }
}

static void handleKeyEvent(key_event_t* event) {
    handleTimerStatus(event);
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
        lep.popupInterface->addChar(event->key_id - KeyNum0 + 48);
        break;
    case KeyDot:
        lep.popupInterface->addChar('.');
        break;
    case KeyBackspace:
        lep.popupInterface->deleteChar();
        break;
    case KeyEnter: {
        getWindowsManagerInterface()->hidePopupWindow(LineEditWindow);
        const char* value = lep.popupInterface->getCurrentInput();
        if (strlen(value) == 0) {
            getEventsManagerInterface()->postEvent(&event->ievent);
            //字符串指针，用完之后在clear
            lep.popupInterface->clearCurrentInput();
            return;
        }
        line_edit_change_event_t lece = {
            .ievent = {
                .event_type = ValueChangeEvent,
                .destination = EndWindow,
            },
            .value = value,
        };
        getEventsManagerInterface()->postEvent(&lece.ievent);
        //字符串指针，用完之后在clear
        lep.popupInterface->clearCurrentInput();
        break;
    }
    case KeyLeft:
        lep.popupInterface->selectLeft();
        break;
    case KeyRight:
        lep.popupInterface->selectRight();
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

void initLineEditPresenter(line_edit_i* popupInterface) {
    lep.popupInterface = popupInterface;
    lep.controller.handleEvent = handleEvent;
    getEventsManagerInterface()->registerPopupEventHandler(&lep.controller, LineEditWindow);
}
