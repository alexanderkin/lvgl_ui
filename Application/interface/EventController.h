#ifndef EVENTCONTROLLER_H
#define EVENTCONTROLLER_H

#include "./struct.h"

typedef struct EventController {
    void (*subscribe)(i_event_type_t* i_event);
} event_controller_t;

#endif // EVENTCONTROLLER_H
