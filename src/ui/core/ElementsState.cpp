#include "ElementsState.h"
#include "../../util/structures/Map.cpp"
#include "../elements/IElement.h"
#include "../elements/ETree.h"
#include "../elements/EButton.h"
#include "../elements/EMenu.h"
#include "../elements/EMenuBar.h"
#include "../elements/EMenuItem.h"
#include "../elements/EText.h"
#include "../elements/ESection.h"

namespace Catalyst {
    Catalyst::Map<std::string, IElement *> ElementsState::registeredElements;

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
        if (element != nullptr) {
            if (parent != nullptr) {
                CONSOLE_LOG("{0} -> {1}", typeid(*element).name(), typeid(*parent).name())
                Catalyst::List<IElement> *children = parent->getChildren();
                children->push(element);
            } else {
                CONSOLE_LOG("{0} -> ROOT", typeid(*element).name())
                elements.push(element);
            }
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

    IElement *ElementsState::createElement(const char *tag) {
        if (!ElementsState::registeredElements.has(tag)) {
            CONSOLE_ERROR("element with tag {0} was not found", tag)
            return nullptr;
        }
        IElement *element = ElementsState::registeredElements.get(tag);
        if(element == nullptr){
            CONSOLE_ERROR("element {0} doesn't implement method 'copy'", tag)
            return nullptr;
        }
        return element->copy();
    }

    ElementsState::ElementsState() {
        ElementsState::registeredElements.set("EText", new EText);
        ElementsState::registeredElements.set("ESection", new ESection);
        ElementsState::registeredElements.set("ETree", new ETree);
        ElementsState::registeredElements.set("EButton", new EButton);
        ElementsState::registeredElements.set("EMenu", new EMenu);
        ElementsState::registeredElements.set("EMenuBar", new EMenuBar);
        ElementsState::registeredElements.set("EMenuItem", new EMenuItem);
    }


    IElement *ElementsState::addElementInternal(IElement *element, IElement *parent) {
        auto pElement = add(element, parent);
        if (pElement == nullptr) {
            return nullptr;
        }
        return pElement;
    }

    IElement *ElementsState::addElement(const char *tag) {
        return addElementInternal(createElement(tag), nullptr);
    }

    IElement *ElementsState::addElement(const char *tag, std::string id, IElement *parent) {
        IElement *pElement = addElementInternal(createElement(tag), parent);
        if (pElement != nullptr) {
            pElement->setId(id);
        }
        return pElement;
    }

    IElement *ElementsState::addElement(IElement *element, IElement *parent) {
        return addElementInternal(element, parent);
    }

    IElement *ElementsState::addElement(const char *tag, IElement *parent) {
        return addElementInternal(createElement(tag), parent);
    }
}