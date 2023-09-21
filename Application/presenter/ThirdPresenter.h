#ifndef THIRDPRESENTER_H
#define THIRDPRESENTER_H

#include "../interface/struct.h"
#include "../view/ThirdWindow.h"
#include "../interface/EventController.h"

typedef struct ThirdPresenter {
    event_controller_t controller;
    third_window_t* window;
} third_presenter_t;

void initThirdPresenter(third_window_t* window);

#endif // THIRDPRESENTER_H
