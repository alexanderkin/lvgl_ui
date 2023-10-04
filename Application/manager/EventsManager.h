#ifndef EVENTSMANAGER_H
#define EVENTSMANAGER_H

#include "../generic/enum.h"
#include "../generic/struct.h"
#include "../interface/IEventController.h"
#include "../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct EventsManager {
    event_controller_i* handler_stack[EndWindow];
    void (*postEvent)(i_event_type_t* i_event);
    void (*registerEventHandler)(event_controller_i* controller, windows_t w);
} events_manager_t;

void initEventsManager();
events_manager_t* getEventsManager();

#endif // EVENTSMANAGER_H
