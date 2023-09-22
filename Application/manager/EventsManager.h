#ifndef EVENTSMANAGER_H
#define EVENTSMANAGER_H

#include "../interface/enum.h"
#include "../interface/struct.h"
#include "../interface/EventController.h"
#include "../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct EventsManager {
    event_controller_t* handler_stack[EndWindow];
    void (*postEvent)(i_event_type_t* i_event);
    void (*registerEventHandler)(event_controller_t* controller, windows_t w);
} events_manager_t;

void initEventsManager();
events_manager_t* getEventsManager();

#endif // EVENTSMANAGER_H
