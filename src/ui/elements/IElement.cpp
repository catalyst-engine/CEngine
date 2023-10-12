#include "IElement.h"
#include "../controllers/AbstractController.h"

namespace Catalyst::ui {
    Catalyst::util::List<IElement> *IElement::getChildren() {
        return &children;
    }

    std::string IElement::getId() {
        return "";
    }

    void IElement::setId(std::string &newId) {

    }

    void IElement::render() {

    }

    void IElement::renderChildren() {
        children.iterate();
        while (children.hasNext()) {
            IElement *next = children.next();
            next->render();
        }
    }
}