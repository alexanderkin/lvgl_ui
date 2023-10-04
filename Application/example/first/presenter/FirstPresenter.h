#ifndef FIRSTPRESENTER_H
#define FIRSTPRESENTER_H

#include "../view/FirstWindow.h"
#include "../../../interface/IEventController.h"

typedef struct FirstPresenter {
    event_controller_i controller;
    first_window_t* window;
} first_presenter_t;

void initFirstPresenter(first_window_t* window);

#endif // FIRSTPRESENTER_H
