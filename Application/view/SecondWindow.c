#include "./SecondWindow.h"
#include "../interface/WindowsManager.h"

static lv_style_t secondStyle;
static second_window_t sw;

static void setLabelText(const char* text) {
    if (sw.hasInited == ON) {
        lv_label_set_text(sw.label, text);
    }
}

void initSecondWindow(lv_obj_t* parent) {
    printf("World\n");
    lv_style_init(&secondStyle);
    lv_style_set_bg_color(&secondStyle, lv_color_white());

    sw.hasInited = ON;
    sw.container = lv_obj_create(parent);
    lv_obj_set_size(sw.container, 800, 480);
    lv_obj_add_style(sw.container, &secondStyle, 0);

    sw.label = lv_label_create(sw.container);
    sw.setLabelText = setLabelText;
    setLabelText("SecondWindow");
    getWindowsManager()->registerWindows(&sw, sw.container, SecondWindow);
}
