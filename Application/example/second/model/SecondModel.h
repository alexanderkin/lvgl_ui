#ifndef SECONDMODEL_H
#define SECONDMODEL_H

#include "../interface/ISecondModel.h"
#include "../../../interface/IModelController.h"

typedef struct SecondModelData {
    float value;
} second_model_data_t;

typedef struct SecondModel {
    second_model_data_t data;
    second_model_i smi;
    model_controller_i controller;
} second_model_t;

void initSecondModel();

#endif // SECONDMODEL_H
