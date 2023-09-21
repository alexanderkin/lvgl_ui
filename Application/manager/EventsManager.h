#ifndef EVENTSMANAGER_H
#define EVENTSMANAGER_H

#include "../interface/enum.h"
#include "../interface/struct.h"
#include "../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct EventsManager {
    void (*postEvent)(i_event_type_t* i_event);
} events_manager_t;

void initEventsManager();
events_manager_t* getEventsManager();

#endif // EVENTSMANAGER_H
