#include "AbstractController.h"
#include "../elements//IElement.h"

namespace Catalyst::ui {
    void AbstractController::bindView(IElement *pView) {
        this->view = pView;
    }

    IElement *AbstractController::getBoundView() {
        return view;
    }

    bool AbstractController::isValid() {
        return view != nullptr;
    }
}

