#include "ElementsState.h"
#include "../elements/IElement.h"

namespace Catalyst {
    Catalyst::List<IElement> *ElementsState::getElements() {
        return &elements;
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


    IElement *ElementsState::add(IElement *element, IElement *parent) {
        if (element == nullptr) {
            return nullptr;
        }
        if (parent != nullptr) {
            CONSOLE_LOG("BINDING [{0}] ({1}) TO [{2}] ({3})", typeid(*element).name(), element->getId(), typeid(*parent).name(),
                        parent->getId())
            Catalyst::List<IElement> *children = parent->getChildren();
            children->push(element);
        } else {

            CONSOLE_LOG("BINDING [{0}] ({1}) TO ROOT", typeid(*element).name(), element->getId())
            elements.push(element);
        }
        return element;
    }


    /**
   * This operation is not cheap, try to cache the entity instead of querying every frame
   * @param id
   * @return nullptr if not found or else IElement*
   */
    IElement *ElementsState::getElementById(std::string id) {
        return getElementByIdInternal(id, elements.getFirst());
    }

    IElement *ElementsState::getElementById(std::string id, IElement *root) {
        return getElementByIdInternal(id, root->getChildren()->getFirst());
    }

    IElement *ElementsState::getElementByIdInternal(std::string &id, ListItem<IElement> *root) {
        CONSOLE_LOG("GETTING ELEMENT: {0}", id)
        Catalyst::ListItem<IElement> *current = root;
        while (current != nullptr) {
            IElement *found = searchFor(current, id);
            if (found != nullptr) {
                return found;
            }
            current = current->next;
        }
        return nullptr;
    }


}