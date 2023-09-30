
#include "Document.h"

namespace Catalyst::ui {
    /**
     * This operation is not cheap, try to cache the entity instead of querying every frame
     * @param id
     * @return nullptr if not found or else AbstractComponent*
     */
    AbstractComponent *Document::getElementById(std::string id) {
        Catalyst::util::ListItem<AbstractComponent> *current = roots.getFirst();
        while (current != nullptr) {
            AbstractComponent *found = searchFor(current, id);
            if (found != nullptr) {
                return found;
            }
            current = current->next;
        }
        return nullptr;
    }

    AbstractComponent *Document::searchFor(Catalyst::util::ListItem<AbstractComponent> *item, const std::string &id) {
        if (item->value->getId() == id) {
            return item->value;
        }

        Catalyst::util::List<AbstractComponent>* children = item->value->getChildren();
        Catalyst::util::ListItem<AbstractComponent> *child = children->getFirst();
        while (child != nullptr) {
            if (child->value->getId() == id) {
                return child->value;
            }
            AbstractComponent *found = searchFor(child, id);
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
            AbstractComponent *next = roots.next();
            next->render();
        }
    }

    void Document::init() {
        // TODO - INITIALIZE STRUCTURE
    }

    Catalyst::util::List<AbstractComponent> Document::getElements() {
        return roots;
    }

    size_t Document::quantityOfElements() {
        return elementsSize;
    }
} // UI