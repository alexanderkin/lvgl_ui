#ifndef IFIRSTMODEL_H
#define IFIRSTMODEL_H

#include <stdint.h>
#include "../../../generic/enum.h"
#include "../../../../LVGL.Simulator/lvgl/lvgl.h"

typedef struct IFirstModel {
    void (*reset)();
    void (*setValue)(channel_t channel, uint64_t v);
    uint64_t (*getValue)(channel_t channel);
} first_model_i;

#endif // IFIRSTMODEL_H
