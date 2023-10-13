#include "Document.h"
#include "../elements/IElement.h"

namespace Catalyst {
    /**
     * This operation is not cheap, try to cache the entity instead of querying every frame
     * @param id
     * @return nullptr if not found or else IElement*
     */
    IElement *Document::getElementById(std::string id) {
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

    IElement *Document::searchFor(Catalyst::ListItem<IElement> *item, const std::string &id) {
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

    Catalyst::List<IElement> *Document::getElements() {
        return &elements;
    }

    size_t Document::quantityOfElements() const {
        return elementsSize;
    }

    void Document::bindElement(IElement *component, IElement *parent) {
        if (parent != nullptr) {
            CONSOLE_LOG("BINDING {0} TO {1}", component->getId(), parent->getId())
            Catalyst::List<IElement> *children = parent->getChildren();
            children->push(component);
        } else {
            CONSOLE_LOG("BINDING {0} TO ROOT", component->getId())
            elements.push(component);
        }
        elementsSize++;
    }

    IElement *Document::addElementInternal(const char *tag, IElement *parent) {
        IElement *element = createElement(tag);
        bindElement(element, parent);
        element->setDocument(this);
        return element;
    }

    IElement *Document::addElement(const char *tag) {
        return addElementInternal(tag, nullptr);
    }

    IElement *Document::addElement(const char *tag, std::string id, IElement *parent) {
        IElement *pElement = addElementInternal(tag, parent);
        pElement->setId(id);
        return pElement;
    }

    IElement *Document::addElement(const char *tag, IElement *parent) {
        return addElementInternal(tag, parent);
    }
}