#include <stdio.h>
#include <string.h>
#include "./ModelsManager.h"

static models_manager_t mmt;

static void readTable() {
    FILE* fp = fopen("table.bin", "rb");
    if (fp == NULL)
        return;
    for (int i = 0; i < EndModel; i++) {
        if (mmt.model_stack[i] != NULL) {
            mmt.model_stack[i]->readData(fp);
        }
    }
    fclose(fp);
}

static void saveTable() {
    FILE* fp = fopen("table.bin", "w+");
    for (int i = 0; i < EndModel; i++) {
        if (mmt.model_stack[i] != NULL) {
            mmt.model_stack[i]->saveData(fp);
        }
    }
    fclose(fp);
}

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
    mmt.mmi.readTable = readTable;
    mmt.mmi.saveTable = saveTable;
    mmt.mmi.getModelInterface = getModelInterface;
    mmt.mmi.registerModel = registerModel;
}
