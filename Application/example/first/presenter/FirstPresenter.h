#ifndef FIRSTPRESENTER_H
#define FIRSTPRESENTER_H

#include "../interface/IFirstWindow.h"
#include "../../../interface/IEventController.h"

typedef struct FirstPresenter {
    event_controller_i controller;
    first_window_i* windowInterface;
} first_presenter_t;

void initFirstPresenter(first_window_i* windowInterface);

#endif // FIRSTPRESENTER_H
