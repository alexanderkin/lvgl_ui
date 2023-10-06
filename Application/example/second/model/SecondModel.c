#include <stdio.h>
#include "./SecondModel.h"
#include "../../../manager/ModelsManager.h"

second_model_t sm;

static void setValue(float v) {
    sm.data.value = v;
}

static float getValue() {
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
    printf("Second Model read value = %f\n", sm.data.value);
}

static void saveData(FILE* fp) {
    printf("Second Model save value = %f\n", sm.data.value);
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
