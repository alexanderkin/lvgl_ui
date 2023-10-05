#ifndef IMODELSMANAGER_H
#define IMODELSMANAGER_H

#include "../generic/struct.h"
#include "../interface/IModelController.h"

typedef struct IModelsManager {
    void* (*getModelInterface)(models_t m);
    void (*registerModel)(model_controller_i* controller, models_t m);
} models_manager_i;

#endif // IMODELMANAGER_H
