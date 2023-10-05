#ifndef IFIRSTMODEL_H
#define IFIRSTMODEL_H

#include <stdint.h>
#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct IFirstModel {
    void (*reset)();
    void (*setValue)(uint64_t v);
    uint64_t (*getValue)();
} first_model_i;

#endif // IFIRSTMODEL_H
