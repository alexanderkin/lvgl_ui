#ifndef ENUM_H
#define ENUM_H

typedef enum ON_OFF {
    ON,
    OFF,
} on_off_t;

typedef enum VisableEnum {
    Visable,
    inVisable,
} visable_t;

typedef enum KeyTypeEnum {
    KeyFirst,
    KeySecond,
    KeyThird,
    KeySelect,
    KeyNum0,
    KeyNum1,
    KeyNum2,
    KeyNum3,
    KeyNum4,
    KeyNum5,
    KeyNum6,
    KeyNum7,
    KeyNum8,
    KeyNum9,
    KeyDot,
    KeyBackspace,
    KeyEnter,
    KeyLeft,
    KeyRight,
    KeyUp,
    KeyDown,
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

typedef enum PopupWindows {
    LineEditWindow,
    WarningWindow,
    EndPopupWindow,
} popup_windows_t;

#endif // ENUM_H
