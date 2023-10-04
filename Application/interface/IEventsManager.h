#ifndef IEVENTSMANAGER_H
#define IEVENTSMANAGER_H

#include "../generic/enum.h"
#include "../generic/struct.h"
#include "../interface/IEventController.h"

typedef struct IEventsManager {
    void (*postEvent)(i_event_type_t* i_event);
    void (*registerEventHandler)(event_controller_i* controller, windows_t w);
} events_manager_i;

#endif // IEVENTSMANAGER_H