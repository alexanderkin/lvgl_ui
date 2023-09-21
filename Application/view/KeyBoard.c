#include <stdio.h>
#include "./KeyBoard.h"
#include "../manager/WindowsManager.h"

#define KeyBoardWidth 800
#define KeyBoardHeight 100

key_board_t kb;
static const char* key_map[] = {
    "First", "Second", "Third", ""
};

static void event_handler(lv_event_t * e) {
    lv_obj_t* obj = lv_event_get_target(e);
    if (e->code == LV_EVENT_CLICKED) {
        key_event_t event = {
            .data = { KeyEvent },
            .type = lv_btnmatrix_get_selected_btn(obj),
        };
        getEventsManager()->postEvent(&event.data);
    }
}

void initKeyBoard(lv_obj_t* parent) {
    lv_style_init(&kb.style);
    lv_style_set_bg_color(&kb.style, lv_color_white());
    lv_style_set_border_width(&kb.style, 0);
    lv_style_set_radius(&kb.style, 0);

    kb.hasInited = ON;

    kb.name = "KeyBoard";

    kb.container = lv_obj_create(parent);
    lv_obj_add_style(kb.container, &kb.style, 0);
    lv_obj_set_size(kb.container, KeyBoardWidth, KeyBoardHeight);
    lv_obj_set_pos(kb.container, 0, 480);
    static lv_coord_t column_dsc[] = {KeyBoardWidth, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t row_dsc[] = {KeyBoardHeight, LV_GRID_TEMPLATE_LAST};
    lv_obj_set_style_grid_column_dsc_array(kb.container, column_dsc, 0);
    lv_obj_set_style_grid_row_dsc_array(kb.container, row_dsc, 0);
    lv_obj_set_style_pad_all(kb.container, 0, 0);
    lv_obj_set_layout(kb.container, LV_LAYOUT_GRID);

    kb.key_matrix = lv_btnmatrix_create(kb.container);
    lv_obj_add_style(kb.key_matrix, &kb.style, 0);
    lv_obj_set_size(kb.key_matrix, KeyBoardWidth, KeyBoardHeight);
    lv_btnmatrix_set_map(kb.key_matrix, key_map);
    lv_btnmatrix_set_one_checked(kb.key_matrix, true);
    lv_obj_set_grid_cell(kb.key_matrix, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_add_event_cb(kb.key_matrix, event_handler, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_flag(kb.container, LV_OBJ_FLAG_HIDDEN);
}
