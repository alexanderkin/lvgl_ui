#include <stdio.h>
#include "./SecondModel.h"
#include "../../../manager/ModelsManager.h"

second_model_t sm;

static void setValue(uint64_t v) {
    sm.data.value = v;
}

static uint64_t getValue() {
    return sm.data.value;
}

static void* getModelInterface() {
    return &sm.smi;
}

static void reset() {
    sm.data.value = 0.0;
}

static void readData(FILE* fp) {
    if (fp != NULL) {
        fread(&sm.data, 1, sizeof(second_model_data_t), fp);
    }
}

static void saveData(FILE* fp) {
    if (fp != NULL) {
        fwrite(&sm.data, sizeof(second_model_data_t), 1, fp);
    }
}

void initSecondModel() {
    reset();
    sm.smi.reset = reset;
    sm.smi.setValue = setValue;
    sm.smi.getValue = getValue;
    sm.controller.getModelInterface = getModelInterface;
    sm.controller.readData = readData;
    sm.controller.saveData = saveData;

    getModelsManagerInterface()->registerModel(&sm.controller, SecondModel);
}
