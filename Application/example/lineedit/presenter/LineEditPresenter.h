#ifndef LINEEDITPRESENTER_H
#define LINEEDITPRESENTER_H

#include "../interface/ILineEdit.h"
#include "../../../interface/IEventController.h"

typedef struct LineEditPresenter {
    event_controller_i controller;
    line_edit_i* popupInterface;
} line_edit_presenter_t;

void initLineEditPresenter(line_edit_i* popupInterface);

#endif // LINEEDITPRESENTER_H
