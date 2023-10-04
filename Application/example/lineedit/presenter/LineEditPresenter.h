#ifndef LINEEDITPRESENTER_H
#define LINEEDITPRESENTER_H

#include "../view/LineEdit.h"
#include "../../../interface/IEventController.h"

typedef struct LineEditPresenter {
    event_controller_i controller;
    line_edit_t* popup;
} line_edit_presenter_t;

void initLineEditPresenter(line_edit_t* popup);

#endif // LINEEDITPRESENTER_H