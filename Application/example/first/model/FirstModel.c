#include <stdio.h>
#include <stdint.h>
#include "./FirstModel.h"
#include "../../../manager/ModelsManager.h"

first_model_t fm;

static void setValue(uint64_t v) {
    fm.data.value = v;
}

static uint64_t getValue() {
    return fm.data.value;
}

static void* getModelInterface() {
    return &fm.fmi;
}

static void reset() {
    fm.data.value = 0;
}

static void readData(FILE* fp) {
    if (fp != NULL) {
        fread(&fm.data, 1, sizeof(first_model_data_t), fp);
    }
}

static void saveData(FILE* fp) {
    if (fp != NULL) {
        fwrite(&fm.data, sizeof(first_model_data_t), 1, fp);
    }
}

void initFirstModel() {
    reset();
    fm.fmi.reset = reset;
    fm.fmi.setValue = setValue;
    fm.fmi.getValue = getValue;
    fm.controller.getModelInterface = getModelInterface;
    fm.controller.readData = readData;
    fm.controller.saveData = saveData;

    getModelsManagerInterface()->registerModel(&fm.controller, FirstModel);
}
