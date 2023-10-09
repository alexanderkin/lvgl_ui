#include <stdio.h>
#include <stdint.h>
#include "./FirstModel.h"
#include "../../../manager/ModelsManager.h"

first_model_t fm;

static void setValue(channel_t channel, uint64_t v) {
    fm.data[channel].value = v;
}

static uint64_t getValue(channel_t channel) {
    return fm.data[channel].value;
}

static void* getModelInterface() {
    return &fm.fmi;
}

static void reset() {
    for (uint8_t i = 0; i < EndChannel; i++) {
        fm.data[i].value = 0;
    }
}

static void readData(FILE* fp) {
    if (fp != NULL) {
        fread(&fm.data, sizeof(first_model_data_t), EndChannel, fp);
    }
}

static void saveData(FILE* fp) {
    if (fp != NULL) {
        fwrite(&fm.data, sizeof(first_model_data_t), EndChannel, fp);
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
