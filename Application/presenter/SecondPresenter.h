#ifndef SECONDPRESENTER_H
#define SECONDPRESENTER_H

#include "../interface/struct.h"
#include "../view/SecondWindow.h"

typedef struct SecondPresenter {
    second_window_t* window;
    void (*subscribe)(i_event_type_t* i_event);
} second_presenter_t;

second_presenter_t* getSecondPresenter();
void initSecondPresenter(second_window_t* window);

#endif // SECONDPRESENTER_H
