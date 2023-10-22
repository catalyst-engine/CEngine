#include "IElement.h"

#include <utility>
#include "../document/Document.h"

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
            if (next->isActive()) {
                next->render();
            }
        }
    }

    void IElement::render() {
        renderChildren();
    }

    Document *IElement::getDocument() {
        return document;
    }

    void IElement::setDocument(Document *doc) {
        if (document == nullptr) {
            document = doc;
        }
    }

    IElement *IElement::copy() {
        CONSOLE_ERROR("No implementation for method 'copy' found")
        return nullptr;
    }

    void IElement::collectAttributes(pugi::xml_node node) {

    }

    IElement *IElement::getElementById(std::string id) {
        return document->getElementById(std::move(id), this);
    }

    bool IElement::isActive() const {
        return active;
    }

    void IElement::setActive(bool a) {
        IElement::active = a;
    }

    void IElement::onInitialize() {

    }

    IElement::~IElement() {
        children.clear();
    }
}