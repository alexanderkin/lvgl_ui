#ifndef ISECONDMODEL_H
#define ISECONDMODEL_H

#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct ISecondModel {
    void (*reset)();
    void (*setValue)(float v);
    float (*getValue)();
} second_model_i;

#endif // ISECONDMODEL_H
