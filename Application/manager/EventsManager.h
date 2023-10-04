#ifndef EVENTSMANAGER_H
#define EVENTSMANAGER_H

#include "../interface/IEventsManager.h"
#include "../interface/IEventController.h"
#include "../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct EventsManager {
    event_controller_i* handler_stack[EndWindow];
    events_manager_i emi;
} events_manager_t;

void initEventsManager();
events_manager_i* getEventsManagerInterface();

#endif // EVENTSMANAGER_H
