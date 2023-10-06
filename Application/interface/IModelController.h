#ifndef IMODELCONTROLLER_H
#define IMODELCONTROLLER_H

#include <stdio.h>
#include "../generic/struct.h"

typedef struct IModelController {
    void* (*getModelInterface)();
    void (*readData)(FILE* fp);
    void (*saveData)(FILE* fp);
} model_controller_i;

#endif // IMODELCONTROLLER_H
