#ifndef FIRSTPRESENTER_H
#define FIRSTPRESENTER_H

#include "../interface/IFirstModel.h"
#include "../interface/IFirstWindow.h"
#include "../../../interface/IEventController.h"

typedef struct FirstPresenter {
    
    event_controller_i controller;
    first_model_i* modelInterface;
    first_window_i* windowInterface;
} first_presenter_t;

void initFirstPresenter(first_model_i* modelInterface, first_window_i* windowInterface);

#endif // FIRSTPRESENTER_H
