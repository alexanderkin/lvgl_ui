#ifndef IEVENTCONTROLLER_H
#define IEVENTCONTROLLER_H

#include "../generic/struct.h"

typedef struct IEventController {
    void (*handleEvent)(event_type_i* ievent);
} event_controller_i;

#endif // IEVENTCONTROLLER_H
