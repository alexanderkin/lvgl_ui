#ifndef FIRSTMODEL_H
#define FIRSTMODEL_H

#include <stdint.h>
#include "../interface/IFirstModel.h"
#include "../../../interface/IModelController.h"

typedef struct FirstModelData {
    uint64_t value;
} first_model_data_t;

typedef struct FirstModel {
    first_model_data_t data[EndChannel];
    first_model_i fmi;
    model_controller_i controller;
} first_model_t;

void initFirstModel();

#endif // FIRSTMODEL_H
