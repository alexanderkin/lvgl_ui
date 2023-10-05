#ifndef IMODELCONTROLLER_H
#define IMODELCONTROLLER_H

#include "../generic/struct.h"

typedef struct IModelController {
    void* (*getModelInterface)();
} model_controller_i;

#endif // IMODELCONTROLLER_H
