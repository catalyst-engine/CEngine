#include "Document.h"
#include "../elements/IView.h"

namespace Catalyst::ui {
    /**
     * This operation is not cheap, try to cache the entity instead of querying every frame
     * @param id
     * @return nullptr if not found or else IView*
     */
    IView *Document::getElementById(std::string id) {
        CONSOLE_LOG("GETTING ELEMENT: {0}", id)
        Catalyst::util::ListItem<IView> *current = views.getFirst();
        while (current != nullptr) {
            IView *found = searchFor(current, id);
            if (found != nullptr) {
                return found;
            }
            current = current->next;
        }
        return nullptr;
    }

    IView *Document::searchFor(Catalyst::util::ListItem<IView> *item, const std::string &id) {
        CONSOLE_LOG("SEARCHING: {0}", id)
        if (item->value->getId() == id) {
            return item->value;
        }

        Catalyst::util::List<IView> *children = item->value->getChildren();
        Catalyst::util::ListItem<IView> *child = children->getFirst();
        while (child != nullptr) {
            if (child->value->getId() == id) {
                return child->value;
            }
            IView *found = searchFor(child, id);
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
            IView *next = views.next();
            next->render();
        }
    }

    void Document::update() {
        // TODO
    }

    Catalyst::util::List<IView> Document::getElements() {
        return views;
    }

    size_t Document::quantityOfElements() const {
        return elementsSize;
    }

    bool Document::addElement(std::string id, IView *component, IView *parent) {
        CONSOLE_LOG("ADDING ELEMENT: {0}", id)
        IView *found = getElementById(id);
        if (found != nullptr) {
            CONSOLE_LOG("ELEMENT FOUND WITH SAME ID: {0}", id)
            return false;
        }
        component->setId(id);
        bindElement(component, parent);
        CONSOLE_LOG("ELEMENT ADDED: {0}", id)
        return true;
    }

    void Document::bindElement(IView *component, IView *parent) {
        if (parent != nullptr) {
            CONSOLE_LOG("BINDING {0} TO {1}", component->getId(), parent->getId())
            Catalyst::util::List<IView> *children = parent->getChildren();
            children->push(component);
        } else {
            CONSOLE_LOG("BINDING {0} TO ROOT", component->getId())
            views.push(component);
        }
        elementsSize++;
    }
} // UI