#include <stdio.h>
#include <string.h>
#include "./LineEdit.h"
#include "../../../generic/macro.h"
#include "../../../manager/EventsManager.h"
#include "../../../manager/WindowsManager.h"

#define LineEditWidth 240
#define LineEditHeigh 80

static line_edit_t le;

static const char* getWindowName() {
    return le.name;
}

static lv_obj_t* getContainer() {
    return le.container;
}

static void onShow() {
    lv_obj_add_state(le.input_area, LV_STATE_FOCUSED);
    lv_timer_reset(le.timer);
    lv_timer_resume(le.timer);
}

static void addChar(const char c) {
    if (c == '.') {
        if (le.hasDot == ON) {
            return;
        }
        le.hasDot = ON;
        if (strlen(lv_textarea_get_text(le.input_area)) == 0) {
            lv_textarea_add_char(le.input_area, '0');
        }
    }
    lv_textarea_add_char(le.input_area, c);
}

static void deleteChar() {
    uint32_t pos = lv_textarea_get_cursor_pos(le.input_area);
    const char *text = lv_textarea_get_text(le.input_area);
    if (pos > 0 && text[pos - 1] == '.') {
        le.hasDot = OFF;
    }
    lv_textarea_del_char(le.input_area);
}

static void selectLeft() {
    lv_textarea_cursor_left(le.input_area);
    printf("anim time = %d\n", lv_obj_get_style_anim_time(le.input_area, LV_PART_CURSOR));
}

static void selectRight() {
    lv_textarea_cursor_right(le.input_area);
}

static const char* getCurrentInput() {
    return lv_textarea_get_text(le.input_area);
}

static void clearCurrentInput() {
    le.hasDot = OFF;
    lv_textarea_set_text(le.input_area, "");
}

static void* getWindowInterface() {
    return &le.lei;
}

static void resetTimer() {
    lv_timer_reset(le.timer);
}

static void timerHandler(lv_timer_t* timer) {
    getWindowsManagerInterface()->hidePopupWindow(LineEditWindow);
    lv_timer_pause(le.timer);
    clearCurrentInput();
    key_event_t event = {
        .ievent = {
            .event_type = KeyEvent,
            .destination = EndWindow,
        },
        .key_id = KeyEnter,
    };
    getEventsManagerInterface()->postEvent(&event.ievent);
}

void initLineEdit(lv_obj_t* parent) {
    lv_style_init(&le.container_style);
    lv_style_set_radius(&le.container_style, 0);
    lv_style_set_border_width(&le.container_style, 0);
    lv_style_set_bg_opa(&le.container_style, LV_OPA_50);
    lv_style_set_bg_color(&le.container_style, lv_color_black());

    lv_style_init(&le.area_style);
    lv_style_set_radius(&le.area_style, 4);
    lv_style_set_border_width(&le.area_style, 1);
    lv_style_set_border_color(&le.area_style, lv_color_white());
    lv_style_set_bg_opa(&le.area_style, LV_OPA_COVER);
    lv_style_set_bg_color(&le.area_style, lv_color_make(56, 76, 96));

    lv_style_init(&le.title_style);
    lv_style_set_radius(&le.title_style, 0);
    lv_style_set_border_width(&le.title_style, 0);
    lv_style_set_bg_opa(&le.title_style, LV_OPA_TRANSP);
    lv_style_set_text_color(&le.title_style, lv_color_white());

    lv_style_init(&le.line_style);
    lv_style_set_line_width(&le.line_style, 1);
    lv_style_set_line_color(&le.line_style, lv_color_white());

    lv_style_init(&le.input_style);
    lv_style_set_radius(&le.input_style, 0);
    lv_style_set_border_width(&le.input_style, 0);
    lv_style_set_bg_opa(&le.input_style, LV_OPA_TRANSP);
    lv_style_set_text_color(&le.input_style, lv_color_white());

    le.name = "LineEdit";
    le.hasDot = OFF;

    le.container = lv_obj_create(parent);
    lv_obj_remove_style_all(le.container);
    lv_obj_set_size(le.container, WINDOWS_WIDTH, WINDOWS_HEIGH);
    lv_obj_set_pos(le.container, 0, 0);
    lv_obj_add_style(le.container, &le.container_style, 0);

    le.area = lv_obj_create(le.container);
    lv_obj_remove_style_all(le.area);
    lv_obj_set_size(le.area, LineEditWidth, LineEditHeigh);
    lv_obj_set_pos(le.area, (WINDOWS_WIDTH - LineEditWidth) / 2, (WINDOWS_HEIGH - LineEditHeigh) / 2);
    lv_obj_add_style(le.area, &le.area_style, 0);

    static lv_coord_t col_dsc[] = {LineEditWidth, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t row_dsc[] = {LineEditHeigh / 2, LineEditHeigh / 2, LV_GRID_TEMPLATE_LAST};
    lv_obj_set_style_grid_column_dsc_array(le.area, col_dsc, 0);
    lv_obj_set_style_grid_row_dsc_array(le.area, row_dsc, 0);
    lv_obj_set_style_pad_all(le.area, 0, 0);
    lv_obj_set_style_pad_row(le.area, 0, 0);
    lv_obj_set_layout(le.area, LV_LAYOUT_GRID);

    le.title = lv_label_create(le.area);
    lv_label_set_text(le.title, "Set Value:");
    lv_obj_set_size(le.title, LineEditWidth, 40);
    lv_obj_add_style(le.title, &le.title_style, 0);
    lv_obj_set_style_text_font(le.title, &SourceHanSansCN_Bold_20, 0);
    lv_obj_set_style_pad_top(le.title, 8, 0);
    lv_obj_set_style_pad_left(le.title, 8, 0);
    lv_obj_set_grid_cell(le.title, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);

    le.line_points[0].x = 4;
    le.line_points[0].y = LineEditHeigh / 2;
    le.line_points[1].x = LineEditWidth - 4;
    le.line_points[1].y = LineEditHeigh / 2;
    le.line = lv_line_create(le.area);
    lv_line_set_points(le.line, le.line_points, 2);
    lv_obj_add_style(le.line, &le.line_style, 0);

    le.input_area = lv_textarea_create(le.area);
    lv_obj_set_size(le.input_area, LineEditWidth, 40);
    lv_obj_add_style(le.input_area, &le.input_style, 0);
    lv_textarea_set_one_line(le.input_area, true);
    lv_textarea_set_max_length(le.input_area, 12);
    lv_textarea_set_text_selection(le.input_area, false);
    lv_textarea_set_cursor_click_pos(le.input_area, false);
    lv_textarea_set_align(le.input_area, LV_TEXT_ALIGN_RIGHT);
    lv_textarea_set_accepted_chars(le.input_area, "0123456789.");
    lv_obj_set_style_text_font(le.input_area, &SourceHanSansCN_Bold_20, 0);
    lv_obj_set_style_anim_time(le.input_area, 500, LV_TEXTAREA_PART_CURSOR);
    lv_obj_set_style_border_color(le.input_area, lv_color_white(), LV_TEXTAREA_PART_CURSOR);
    lv_obj_set_grid_cell(le.input_area, LV_GRID_ALIGN_START, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);

    le.timer = lv_timer_create(timerHandler, 5000, NULL);
    lv_timer_pause(le.timer);

    le.lei.addChar = addChar;
    le.lei.deleteChar = deleteChar;
    le.lei.selectLeft = selectLeft;
    le.lei.selectRight = selectRight;
    le.lei.getCurrentInput = getCurrentInput;
    le.lei.clearCurrentInput = clearCurrentInput;
    le.lei.resetTimer = resetTimer;

    le.controller.visable = inVisable;
    le.controller.getContainer = getContainer;
    le.controller.onShow = onShow;
    le.controller.getWindowName = getWindowName;
    le.controller.getWindowInterface = getWindowInterface;
    
    getWindowsManagerInterface()->registerPopupWindow(&le.controller, LineEditWindow);
}
