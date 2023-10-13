#include "IElement.h"

namespace Catalyst {
    Catalyst::List<IElement> *IElement::getChildren() {
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

    Document *IElement::getDocument() {
        return document;
    }

    void IElement::setDocument(Document *doc) {
        if (IElement::document == nullptr) {
            IElement::document = doc;
        }
    }
}