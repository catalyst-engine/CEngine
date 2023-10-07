#include "IView.h"
#include "../controllers/AbstractController.h"

namespace Catalyst::ui {
    void IView::setController(AbstractController *ctr) {
        controller = ctr;
    }

    AbstractController *IView::getController() {
        return controller;
    }
}