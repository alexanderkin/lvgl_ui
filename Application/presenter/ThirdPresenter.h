#ifndef THIRDPRESENTER_H
#define THIRDPRESENTER_H

#include "../interface/struct.h"
#include "../view/ThirdWindow.h"

typedef struct ThirdPresenter {
    third_window_t* window;
    void (*subscribe)(i_event_type_t* i_event);
} third_presenter_t;

third_presenter_t* getThirdPresenter();
void initThirdPresenter(third_window_t* window);

#endif // THIRDPRESENTER_H
