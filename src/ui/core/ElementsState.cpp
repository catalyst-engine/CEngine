#include "ElementsState.h"
#include "../elements/IElement.h"

namespace Catalyst {
    Catalyst::List<IElement> *ElementsState::getElements() {
        return &elements;
    }

    /**
   * This operation is not cheap, try to cache the entity instead of querying every frame
   * @param id
   * @return nullptr if not found or else IElement*
   */
    IElement *ElementsState::getElementById(std::string id) {
        CONSOLE_LOG("GETTING ELEMENT: {0}", id)
        Catalyst::ListItem<IElement> *current = elements.getFirst();
        while (current != nullptr) {
            IElement *found = searchFor(current, id);
            if (found != nullptr) {
                return found;
            }
            current = current->next;
        }
        return nullptr;
    }

    IElement *ElementsState::searchFor(Catalyst::ListItem<IElement> *item, const std::string &id) {
        CONSOLE_LOG("SEARCHING: {0}", id)
        if (item->value->getId() == id) {
            return item->value;
        }

        Catalyst::List<IElement> *children = item->value->getChildren();
        Catalyst::ListItem<IElement> *child = children->getFirst();
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


    void ElementsState::bindElement(IElement *component, IElement *parent) {
        if (parent != nullptr) {
            CONSOLE_LOG("BINDING {0} TO {1}", component->getId(), parent->getId())
            Catalyst::List<IElement> *children = parent->getChildren();
            children->push(component);
        } else {
            CONSOLE_LOG("BINDING {0} TO ROOT", component->getId())
            elements.push(component);
        }
    }

    IElement *ElementsState::add(IElement *element, IElement *parent) {
        if (element == nullptr) {
            return nullptr;
        }
        bindElement(element, parent);
        return element;
    }


}