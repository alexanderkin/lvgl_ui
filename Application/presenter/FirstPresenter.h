#ifndef FIRSTPRESENTER_H
#define FIRSTPRESENTER_H

#include "../interface/struct.h"
#include "../view/FirstWindow.h"

typedef struct FirstPresenter {
    first_window_t* window;
    void (*subscribe)(i_event_type_t* i_event);
} first_presenter_t;

first_presenter_t* getFirstPresenter();
void initFirstPresenter(first_window_t* window);

#endif // FIRSTPRESENTER_H
