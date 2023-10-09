#ifndef ILINEEDIT_H
#define ILINEEDIT_H

#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct ILineEdit {
    void (*addChar)(const char c);
    void (*deleteChar)();
    void (*selectLeft)();
    void (*selectRight)();
    const char* (*getCurrentInput)();
    void (*clearCurrentInput)();
    void (*resetTimer)();
} line_edit_i;

#endif // ILINEEDIT_H
