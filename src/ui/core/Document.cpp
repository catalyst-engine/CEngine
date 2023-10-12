#include "Document.h"
#include "../elements/IElement.h"

namespace Catalyst::ui {
    /**
     * This operation is not cheap, try to cache the entity instead of querying every frame
     * @param id
     * @return nullptr if not found or else IElement*
     */
    IElement *Document::getElementById(std::string id) {
        CONSOLE_LOG("GETTING ELEMENT: {0}", id)
        Catalyst::util::ListItem<IElement> *current = views.getFirst();
        while (current != nullptr) {
            IElement *found = searchFor(current, id);
            if (found != nullptr) {
                return found;
            }
            current = current->next;
        }
        return nullptr;
    }

    IElement *Document::searchFor(Catalyst::util::ListItem<IElement> *item, const std::string &id) {
        CONSOLE_LOG("SEARCHING: {0}", id)
        if (item->value->getId() == id) {
            return item->value;
        }

        Catalyst::util::List<IElement> *children = item->value->getChildren();
        Catalyst::util::ListItem<IElement> *child = children->getFirst();
        while (child != nullptr) {
            if (child->value->getId() == id) {
                return child->value;
            }
            IElement *found = searchFor(child, id);
            if (found != nullptr) {
                return found;
            }
            child = child->next;
        }
        return nullptr;
    }

    void Document::render() {
        views.iterate();
        while (views.hasNext()) {
            IElement *next = views.next();
            next->render();
        }
    }

    void Document::update() {
        // TODO
    }

    Catalyst::util::List<IElement> Document::getElements() {
        return views;
    }

    size_t Document::quantityOfElements() const {
        return elementsSize;
    }

    bool Document::addElement(std::string id, IElement *component, IElement *parent) {
        CONSOLE_LOG("ADDING ELEMENT: {0}", id)
        IElement *found = getElementById(id);
        if (found != nullptr) {
            CONSOLE_LOG("ELEMENT FOUND WITH SAME ID: {0}", id)
            return false;
        }
        component->setId(id);
        bindElement(component, parent);
        CONSOLE_LOG("ELEMENT ADDED: {0}", id)
        return true;
    }

    void Document::bindElement(IElement *component, IElement *parent) {
        if (parent != nullptr) {
            CONSOLE_LOG("BINDING {0} TO {1}", component->getId(), parent->getId())
            Catalyst::util::List<IElement> *children = parent->getChildren();
            children->push(component);
        } else {
            CONSOLE_LOG("BINDING {0} TO ROOT", component->getId())
            views.push(component);
        }
        elementsSize++;
    }
} // UI