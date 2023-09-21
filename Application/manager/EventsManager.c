#include <stdio.h>
#include "./EventsManager.h"

static events_manager_t em;

static void postEvent(event_data_t* data) {
    if (data->type == KeyEvent) {
        key_event_t* e = (key_event_t*)data;
        printf("data = %d, keyid = %d\n", e->data.type, e->type);
    }
}

events_manager_t* getEventsManager() {
    return &em;
}

void initEventsManager() {
    em.postEvent = postEvent;
}
