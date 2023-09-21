#ifndef SECONDPRESENTER_H
#define SECONDPRESENTER_H

#include "../interface/struct.h"
#include "../view/SecondWindow.h"
#include "../interface/EventController.h"

typedef struct SecondPresenter {
    event_controller_t controller;
    second_window_t* window;
} second_presenter_t;

void initSecondPresenter(second_window_t* window);

#endif // SECONDPRESENTER_H
