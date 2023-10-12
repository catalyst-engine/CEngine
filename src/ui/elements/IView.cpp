#include "IView.h"
#include "../controllers/AbstractController.h"

namespace Catalyst::ui {
    Catalyst::util::List<IView> *IView::getChildren() {
        return &children;
    }

    std::string IView::getId() {
        return "";
    }

    void IView::setId(std::string &newId) {

    }

    void IView::render() {

    }

    void IView::renderChildren() {
        children.iterate();
        while (children.hasNext()) {
            IView *next = children.next();
            next->render();
        }
    }
}