#include <stdio.h>
#include <string.h>
#include "./EventsManager.h"
#include "./WindowsManager.h"

static events_manager_t em;

static void postEvent(event_type_i* ievent) {
    if (ievent->destination != EndWindow) {
        if (em.handler_stack[ievent->destination] == NULL) 
            return;
        em.handler_stack[ievent->destination]->handleEvent(ievent);
        return;
    }
    if (getWindowsManagerInterface()->getActivedWindowsType() == PopupWindow) {
        popup_windows_t p = getWindowsManagerInterface()->getActivedPopupWindow();
        if (em.popup_handler_stack[p] == NULL) 
            return;
        em.popup_handler_stack[p]->handleEvent(ievent);
        return;
    }
    windows_t w = getWindowsManagerInterface()->getActivedWindow();
    if (em.handler_stack[w] == NULL) 
        return;
    em.handler_stack[w]->handleEvent(ievent);
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
