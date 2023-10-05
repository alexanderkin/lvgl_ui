#include <stdio.h>
#include <stdint.h>
#include "./FirstModel.h"
#include "../../../manager/ModelsManager.h"

first_model_t fm;

static void setValue(uint64_t v) {
    fm.value = v;
}

static uint64_t getValue() {
    return fm.value;
}

static void* getModelInterface() {
    return &fm.fmi;
}

static void reset() {
    fm.value = 0;
}

void initFirstModel() {
    reset();
    fm.fmi.reset = reset;
    fm.fmi.setValue = setValue;
    fm.fmi.getValue = getValue;
    fm.controller.getModelInterface = getModelInterface;

    getModelsManagerInterface()->registerModel(&fm.controller, FirstModel);
}