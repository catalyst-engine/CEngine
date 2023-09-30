
#include "Document.h"

namespace Catalyst::ui {
    AbstractComponent *Document::getElementById(std::string &id) {
        return elements.get(id);
    }

    void Document::render() {
        roots.iterate();
        while (roots.hasNext()) {
            AbstractComponent *next = roots.next();
            next->render();
        }
    }

    void Document::init() {

    }

    util::structs::DynamicMap<std::string, AbstractComponent> Document::getElements() {
        return elements;
    }
} // UI