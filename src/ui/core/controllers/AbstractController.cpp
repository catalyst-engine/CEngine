#include "AbstractController.h"
#include "../views/IView.h"

namespace Catalyst::ui {
    void AbstractController::bindView(IView *pView) {
        this->view = pView;
    }

    IView *AbstractController::getBoundView() {
        return view;
    }

    bool AbstractController::isValid() {
        return view != nullptr;
    }
}

