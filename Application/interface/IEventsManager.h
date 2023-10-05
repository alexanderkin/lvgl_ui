#ifndef IEVENTSMANAGER_H
#define IEVENTSMANAGER_H

#include "../generic/enum.h"
#include "../generic/struct.h"
#include "../interface/IEventController.h"

typedef struct IEventsManager {
    void (*postEvent)(event_type_i* ievent);
    void (*registerEventHandler)(event_controller_i* controller, windows_t w);
    void (*registerPopupEventHandler)(event_controller_i* controller, popup_windows_t p);
} events_manager_i;

#endif // IEVENTSMANAGER_H