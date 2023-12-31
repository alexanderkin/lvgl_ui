#include <stdio.h>
#include "./KeyBoard.h"
#include "../../../fonts/fonts.h"
#include "../../../generic/macro.h"
#include "../../../manager/EventsManager.h"
#include "../../../manager/WindowsManager.h"

#define KeyBoardWidth WINDOWS_WIDTH
#define KeyBoardHeight 200

key_board_t kb;

static const char* special_key_map[] = {
    "First",   "Second",  "Third",   "\n", 
    "Select1", "Select2", "Select3", "Select4", ""
};

static const int special_key_id[] = {
    KeyFirst,   KeySecond,  KeyThird,
    KeySelect1, KeySelect2, KeySelect3, KeySelect4,
};

static const char* generic_key_map[] = {
    "7", "8", "9",  "Left",  "\n",
    "4", "5", "6",  "Right", "\n",
    "1", "2", "3",  "Up",    "\n",
    "0", ".", "<-", "Down",  "\n",
    "Enter", ""
};

static const int generic_key_id[] = {
    KeyNum7, KeyNum8, KeyNum9,      KeyLeft,
    KeyNum4, KeyNum5, KeyNum6,      KeyRight,
    KeyNum1, KeyNum2, KeyNum3,      KeyUp,
    KeyNum0, KeyDot,  KeyBackspace, KeyDown,
    KeyEnter
};

static void special_event_handler(lv_event_t * e) {
    windows_t w = EndWindow;
    lv_obj_t* obj = lv_event_get_target(e);
    key_type_t id = special_key_id[lv_btnmatrix_get_selected_btn(obj)];
    if (e->code == LV_EVENT_CLICKED) {
        switch (id)
        {
        case KeyFirst:
            w = FirstWindow;
            break;
        case KeySecond:
            w = SecondWindow;
            break;
        case KeyThird:
            w = ThirdWindow;
            break;
        default:
            w = EndWindow;
            break;
        }
        key_event_t event = {
            .ievent = {
                .event_type = KeyEvent,
                .destination = w,
            },
            .key_id = id,
        };
        getEventsManagerInterface()->postEvent(&event.ievent);
    }
}

static void generic_event_handler(lv_event_t * e) {
    lv_obj_t* obj = lv_event_get_target(e);
    if (e->code == LV_EVENT_CLICKED) {
        key_event_t event = {
            .ievent = {
                .event_type = KeyEvent,
                .destination = EndWindow,
            },
            .key_id = generic_key_id[lv_btnmatrix_get_selected_btn(obj)],
        };
        getEventsManagerInterface()->postEvent(&event.ievent);
    }
}

void initKeyBoard(lv_obj_t* parent) {
    lv_style_init(&kb.style);
    lv_style_set_radius(&kb.style, 0);
    lv_style_set_pad_all(&kb.style, 0);
    lv_style_set_border_width(&kb.style, 0);
    lv_style_set_bg_color(&kb.style, lv_color_make(224, 224, 224));

    kb.name = "KeyBoard";

    kb.container = lv_obj_create(parent);
    lv_obj_remove_style_all(kb.container);
    lv_obj_add_style(kb.container, &kb.style, 0);
    lv_obj_set_size(kb.container, KeyBoardWidth, KeyBoardHeight);
    lv_obj_set_pos(kb.container, 0, 272);

    kb.special_key_matrix = lv_btnmatrix_create(kb.container);
    lv_obj_set_size(kb.special_key_matrix, 288, KeyBoardHeight - 1);
    lv_obj_set_pos(kb.special_key_matrix, 0, 1);
    lv_obj_set_style_pad_all(kb.special_key_matrix, 2, 0);
    lv_obj_set_style_pad_top(kb.special_key_matrix, 5, 0);
    lv_obj_set_style_pad_left(kb.special_key_matrix, 6, 0);
    lv_obj_set_style_pad_row(kb.special_key_matrix, 5, 0);
    lv_obj_set_style_pad_column(kb.special_key_matrix, 2, 0);
    lv_btnmatrix_set_map(kb.special_key_matrix, special_key_map);
    lv_btnmatrix_set_one_checked(kb.special_key_matrix, true);
    lv_obj_add_event_cb(kb.special_key_matrix, special_event_handler, LV_EVENT_CLICKED, NULL);

    kb.generic_key_matrix = lv_btnmatrix_create(kb.container);
    lv_obj_set_size(kb.generic_key_matrix, 192, KeyBoardHeight - 1);
    lv_obj_set_pos(kb.generic_key_matrix, 288, 1);
    lv_obj_set_style_pad_all(kb.generic_key_matrix, 2, 0);
    lv_obj_set_style_pad_top(kb.generic_key_matrix, 5, 0);
    lv_obj_set_style_pad_left(kb.generic_key_matrix, 6, 0);
    lv_obj_set_style_pad_row(kb.generic_key_matrix, 5, 0);
    lv_obj_set_style_pad_column(kb.generic_key_matrix, 2, 0);
    lv_btnmatrix_set_map(kb.generic_key_matrix, generic_key_map);
    lv_btnmatrix_set_one_checked(kb.generic_key_matrix, true);
    lv_obj_add_event_cb(kb.generic_key_matrix, generic_event_handler, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_flag(kb.container, LV_OBJ_FLAG_HIDDEN);
}
