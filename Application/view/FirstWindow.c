#include "./FirstWindow.h"
#include "../interface/WindowsManager.h"

static lv_style_t firstStyle;
static first_window_t fw;

static void setLabelText(const char* text) {
    if (fw.hasInited == ON) {
        lv_label_set_text(fw.label, text);
    }
}

void initFirstWindow(lv_obj_t* parent) {
    lv_style_init(&firstStyle);
    lv_style_set_bg_color(&firstStyle, lv_color_white());

    fw.hasInited = ON;
    fw.container = lv_obj_create(parent);
    lv_obj_set_size(fw.container, 800, 480);
    lv_obj_add_style(fw.container, &firstStyle, 0);
    
    fw.label = lv_label_create(fw.container);
    fw.setLabelText = setLabelText;
    setLabelText("FirstWindow");
    getWindowsManager()->registerWindows(&fw, fw.container, FirstWindow);
}
