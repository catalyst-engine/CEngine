
#include "Document.h"

namespace Catalyst::ui {
    template<typename T>
    T *Document::addElement(std::string id, IComponent *parent) {
        if (elements.has(id)) {
            return nullptr;
        }
        IComponent *newInstance = new T();
        newInstance->setId(id);
        elements.set(id, newInstance);
        if (parent != nullptr) {
            parent->addChild(newInstance);
        } else {
            roots.push(newInstance);
        }
        return (T *) newInstance;
    }

    IComponent *Document::getElementById(std::string &id) {
        return elements.get(id);
    }

    void Document::render() {
        roots.iterate();
        while (roots.hasNext()) {
            IComponent *next = roots.next();
            next->render();
        }
    }

    void Document::init() {

    }

    util::structs::DynamicMap<std::string, IComponent> Document::getElements() {
        return elements;
    }
} // UI