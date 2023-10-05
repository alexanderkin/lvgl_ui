#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include "../generic/enum.h"
#include "../interface/IModelsManager.h"
#include "../interface/IModelController.h"

typedef struct ModelsManager {
    model_controller_i* model_stack[EndModel];
    models_manager_i mmi;
} models_manager_t;

void initModelsManager();
models_manager_i* getModelsManagerInterface();

#endif // MODELMANAGER_H