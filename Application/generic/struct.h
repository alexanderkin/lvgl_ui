#ifndef STRUCT_H
#define STRUCT_H

#include "./enum.h"

typedef struct EventTypeInterface {
    event_type_t type;
} i_event_type_t;

typedef struct KeyEvent {
    i_event_type_t i_event;
    key_type_t key;
} key_event_t;

#endif // STRUCT_H
