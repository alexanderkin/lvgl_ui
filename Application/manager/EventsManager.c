#include <stdio.h>
#include "./EventsManager.h"
#include "./WindowsManager.h"
#include "../presenter/FirstPresenter.h"
#include "../presenter/SecondPresenter.h"
#include "../presenter/ThirdPresenter.h"

static events_manager_t em;

static void postEvent(i_event_type_t* i_event) {
    switch (getWindowsManager()->getActivedWindow())
    {
    case FirstWindow:
        getFirstPresenter()->subscribe(i_event);
        break;
    case SecondWindow:
        getSecondPresenter()->subscribe(i_event);
        break;
    case ThirdWindow:
        getThirdPresenter()->subscribe(i_event);
        break;
    default:
        break;
    }
}

events_manager_t* getEventsManager() {
    return &em;
}

void initEventsManager() {
    em.postEvent = postEvent;
}
