#include "AbstractView.h"
#include "../controllers/AbstractController.h"

namespace Catalyst::ui {
    void AbstractView::render() {

    }

    void AbstractView::update() {
        if (controller != nullptr) {
            controller->update();
        }
    }

    void AbstractView::setId(std::string &newId) {
        id = newId;
    }

    std::string AbstractView::getId() {
        return id;
    }

    Catalyst::util::List<IView> *AbstractView::getChildren() {
        return &children;
    }

    void AbstractView::renderChildren() {
        children.iterate();
        while (children.hasNext()) {
            IView *next = children.next();
            next->render();
        }
    }
}