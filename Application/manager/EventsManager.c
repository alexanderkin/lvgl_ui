#include <stdio.h>
#include "./EventsManager.h"
#include "./WindowsManager.h"

static events_manager_t em;

static void postEvent(i_event_type_t* i_event) {
    if (i_event->destination != EndWindow) {
        if (em.handler_stack[i_event->destination] == NULL) return;
        em.handler_stack[i_event->destination]->handleEvent(i_event);
        return;
    }
    if (getWindowsManagerInterface()->getActivedWindowsType() == PopupWindow) {
        popup_windows_t p = getWindowsManagerInterface()->getActivedPopupWindow();
        if (em.popup_handler_stack[p] == NULL) return;
        em.popup_handler_stack[p]->handleEvent(i_event);
        return;
    }
    windows_t w = getWindowsManagerInterface()->getActivedWindow();
    if (em.handler_stack[w] == NULL) return;
    em.handler_stack[w]->handleEvent(i_event);
}

static void registerEventHandler(event_controller_i* controller, windows_t w) {
    em.handler_stack[w] = controller;
}

static void registerPopupEventHandler(event_controller_i* controller, popup_windows_t p) {
    em.popup_handler_stack[p] = controller;
}

events_manager_i* getEventsManagerInterface() {
    return &em.emi;
}

void initEventsManager() {
    memset(em.handler_stack, 0, sizeof(em.handler_stack));
    memset(em.popup_handler_stack, 0, sizeof(em.popup_handler_stack));
    em.emi.postEvent = postEvent;
    em.emi.registerEventHandler = registerEventHandler;
    em.emi.registerPopupEventHandler = registerPopupEventHandler;
}
