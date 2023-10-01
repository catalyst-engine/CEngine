
#include "Document.h"
#include "views/IView.h"

namespace Catalyst::ui {
    /**
     * This operation is not cheap, try to cache the entity instead of querying every frame
     * @param id
     * @return nullptr if not found or else IView*
     */
    IView *Document::getElementById(std::string id) {
        Catalyst::util::ListItem<IView> *current = roots.getFirst();
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
        roots.iterate();
        while (roots.hasNext()) {
            IView *next = roots.next();
            next->render();
        }
    }

    void Document::init() {
        // TODO - INITIALIZE STRUCTURE
    }

    Catalyst::util::List<IView> Document::getElements() {
        return roots;
    }

    size_t Document::quantityOfElements() {
        return elementsSize;
    }

    bool Document::addElement(std::string id, IView *component, IView *parent) {
        IView *found = getElementById(id);
        if (found != nullptr) {
            return false;
        }
        component->setId(id);
        bindElement(component, parent);
        return true;
    }

    void Document::bindElement(IView *component, IView *parent) {
        if (parent != nullptr) {
            Catalyst::util::List<IView> *children = parent->getChildren();
            children->push(component);
        } else {
            roots.push(component);
        }
        elementsSize++;
    }
} // UI