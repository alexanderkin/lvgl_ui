#ifndef THIRDPRESENTER_H
#define THIRDPRESENTER_H

#include "../interface/IThirdWindow.h"
#include "../../../interface/IEventController.h"

typedef struct ThirdPresenter {
    event_controller_i controller;
    third_window_i* windowInterface;
} third_presenter_t;

void initThirdPresenter(third_window_i* windowInterface);

#endif // THIRDPRESENTER_H
