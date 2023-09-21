#ifndef STRUCT_H
#define STRUCT_H

#include "./enum.h"

typedef struct EventData {
    event_type_t type;
} event_data_t;

typedef struct KeyEvent {
    event_data_t data;
    key_type_t type;
} key_event_t;

#endif // STRUCT_H
