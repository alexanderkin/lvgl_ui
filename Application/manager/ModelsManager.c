#include <stdio.h>
#include <string.h>
#include "./ModelsManager.h"

static models_manager_t mmt;

static void* getModelInterface(models_t m) {
    return (void*)mmt.model_stack[m]->getModelInterface();
}

static void registerModel(model_controller_i* controller, models_t m) {
    mmt.model_stack[m] = controller;
}

models_manager_i* getModelsManagerInterface() {
    return &mmt.mmi;
}

void initModelsManager() {
    memset(mmt.model_stack, 0, sizeof(mmt.model_stack));
    mmt.mmi.getModelInterface = getModelInterface;
    mmt.mmi.registerModel = registerModel;
}