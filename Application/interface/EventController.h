#ifndef EVENTCONTROLLER_H
#define EVENTCONTROLLER_H

#include "../generic/struct.h"

typedef struct EventController {
    void (*handleEvent)(i_event_type_t* i_event);
} event_controller_t;

#endif // EVENTCONTROLLER_H
