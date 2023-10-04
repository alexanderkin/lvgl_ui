#ifndef IEVENTCONTROLLER_H
#define IEVENTCONTROLLER_H

#include "../generic/struct.h"

typedef struct IEventController {
    void (*handleEvent)(i_event_type_t* i_event);
} event_controller_i;

#endif // IEVENTCONTROLLER_H
