#include <stdio.h>
#include "./LineEdit.h"
#include "../../../manager/WindowsManager.h"

static line_edit_t le;

static const char* getWindowName() {
    if (le.hasInited == ON) {
        return le.name;
    }
    return NULL;
}

static lv_obj_t* getContainer() {
    if (le.hasInited == ON) {
        return le.container;
    }
    return NULL;
}

void initLineEdit(lv_obj_t* parent) {
    lv_style_init(&le.style);
    lv_style_set_bg_color(&le.style, lv_color_make(49, 154, 222));
    lv_style_set_border_width(&le.style, 0);
    lv_style_set_radius(&le.style, 0);

    le.name = "LineEdit";

    le.container = lv_obj_create(parent);
    lv_obj_set_size(le.container, 300, 100);
    lv_obj_set_pos(le.container, 250, 190);
    lv_obj_add_style(le.container, &le.style, 0);

    le.controller.visable = inVisable;
    le.controller.getContainer = getContainer;
    le.controller.getWindowName = getWindowName;

    le.hasInited = ON;
    
    getWindowsManagerInterface()->registerPopupWindow(&le.controller, LineEditWindow);
}