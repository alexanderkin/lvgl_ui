#ifndef SECONDPRESENTER_H
#define SECONDPRESENTER_H

#include "../interface/ISecondModel.h"
#include "../interface/ISecondWindow.h"
#include "../../../interface/IEventController.h"

typedef struct SecondPresenter {
    event_controller_i controller;
    second_model_i* modelInterface;
    second_window_i* windowInterface;
} second_presenter_t;

void initSecondPresenter(second_model_i* modelInterface, second_window_i* windowInterface);

#endif // SECONDPRESENTER_H
