#include "IElement.h"

namespace Catalyst {
    Catalyst::List<IElement> *IElement::getChildren() {
        return &children;
    }

    std::string IElement::getId() {
        return id;
    }

    void IElement::setId(std::string &newId) {
        id = newId;
    }


    void IElement::renderChildren() {
        children.iterate();
        while (children.hasNext()) {
            IElement *next = children.next();
            next->render();
        }
    }

    void IElement::render() {
        renderChildren();
    }

    Document *IElement::getDocument() {
        return document;
    }

    void IElement::setDocument(Document *doc) {
        if (IElement::document == nullptr) {
            IElement::document = doc;
        }
    }

    IElement *IElement::copy() {
        return nullptr;
    }

    void IElement::collectAttributes(pugi::xml_node node) {

    }
}