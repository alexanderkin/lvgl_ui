#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "../../../generic/enum.h"
#include "../../../generic/struct.h"
#include "../../../manager/EventsManager.h"
#include "../../../interface/WindowController.h"
#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct KeyBoard {
    on_off_t hasInited;
    lv_obj_t* container;
    lv_obj_t* key_matrix;
    lv_style_t style;
    char* name;
} key_board_t;

void initKeyBoard(lv_obj_t* parent);

#endif // KEYBOARD_H
