#ifndef EVENTSMANAGER_H
#define EVENTSMANAGER_H

#include "../generic/enum.h"
#include "../generic/struct.h"
#include "../interface/EventController.h"
#include "../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct EventsManager {
    event_controller_t* handler_stack[EndWindow];
    void (*postEvent)(i_event_type_t* i_event);
    void (*registerEventHandler)(event_controller_t* controller, windows_t w);

    event_controller_t* popup_handler_stack[EndPopupWindow];
    void (*eventTransferToPopup)(i_event_type_t* i_event, popup_windows_t p);
    void (*registerPopupEventHandler)(event_controller_t* controller, popup_windows_t p);
} events_manager_t;

void initEventsManager();
events_manager_t* getEventsManager();

#endif // EVENTSMANAGER_H
