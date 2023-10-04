#ifndef THIRDPRESENTER_H
#define THIRDPRESENTER_H

#include "../view/ThirdWindow.h"
#include "../../../generic/struct.h"
#include "../../../interface/IEventController.h"

typedef struct ThirdPresenter {
    event_controller_i controller;
    third_window_t* window;
} third_presenter_t;

void initThirdPresenter(third_window_t* window);

#endif // THIRDPRESENTER_H
