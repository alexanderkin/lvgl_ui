#ifndef FIRSTPRESENTER_H
#define FIRSTPRESENTER_H

#include "../interface/struct.h"
#include "../view/FirstWindow.h"
#include "../interface/EventController.h"

typedef struct FirstPresenter {
    event_controller_t controller;
    first_window_t* window;
} first_presenter_t;

void initFirstPresenter(first_window_t* window);

#endif // FIRSTPRESENTER_H
