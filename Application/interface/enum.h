#ifndef ENUM_H
#define ENUM_H

typedef enum ON_OFF {
    ON,
    OFF,
} on_off_t;

typedef enum KeyTypeEnum {
    KeyFirst,
    KeySecond,
    KeyThird,
    KeyEnd,
} key_type_t;

typedef enum EventTypeEnum {
    KeyEvent,
} event_type_t;

typedef enum Windows {
    FirstWindow,
    SecondWindow,
    ThirdWindow,
    EndWindow,
} windows_t;

#endif // ENUM_H
