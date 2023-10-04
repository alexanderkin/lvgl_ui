#include <stdio.h>
#include "./EventsManager.h"
#include "./WindowsManager.h"

static events_manager_t em;

static void postEvent(i_event_type_t* i_event) {
    windows_t w = getWindowsManagerInterface()->getActivedWindow();
    if (i_event->destination != EndWindow) {
        w = i_event->destination;
    }
    if (em.handler_stack[w] == NULL) return;
    em.handler_stack[w]->handleEvent(i_event);
}

static void registerEventHandler(event_controller_i* controller, windows_t w) {
    em.handler_stack[w] = controller;
}

events_manager_i* getEventsManagerInterface() {
    return &em.emi;
}

void initEventsManager() {
    memset(em.handler_stack, 0, sizeof(em.handler_stack));
    em.emi.postEvent = postEvent;
    em.emi.registerEventHandler = registerEventHandler;
}
