#include <stdio.h>
#include "./EventsManager.h"
#include "./WindowsManager.h"

static events_manager_t em;

static void postEvent(i_event_type_t* i_event) {
    windows_t w = getWindowsManager()->getActivedWindow();
    if (em.event_stack[w] == NULL) return;
    em.event_stack[w]->subscribe(i_event);
}

static void registerEvent(event_controller_t* controller, windows_t w) {
    em.event_stack[w] = controller;
}

events_manager_t* getEventsManager() {
    return &em;
}

void initEventsManager() {
    em.postEvent = postEvent;
    em.registerEvent = registerEvent;
}
