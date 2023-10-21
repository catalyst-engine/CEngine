#include "ElementController.h"
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
    Catalyst::Map<std::string, IElement *> ElementController::registeredElements;

    Catalyst::List<IElement> *ElementController::getElements() {
        return &elements;
    }

    IElement *ElementController::searchFor(Catalyst::ListItem<IElement> *item, const std::string &id) {
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


    IElement *ElementController::add(IElement *element, IElement *parent) {
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
    IElement *ElementController::getElementById(std::string id) {
        return getElementByIdInternal(id, elements.getFirst());
    }

    IElement *ElementController::getElementById(std::string id, IElement *root) {
        return getElementByIdInternal(id, root->getChildren()->getFirst());
    }

    IElement *ElementController::getElementByIdInternal(std::string &id, ListItem<IElement> *root) {
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

    IElement *ElementController::createElement(const char *tag) {
        if (!ElementController::registeredElements.has(tag)) {
            CONSOLE_ERROR("element with tag {0} was not found", tag)
            return nullptr;
        }
        IElement *element = ElementController::registeredElements.get(tag);
        if(element == nullptr){
            CONSOLE_ERROR("element {0} doesn't implement method 'copy'", tag)
            return nullptr;
        }
        return element->copy();
    }

    ElementController::ElementController() {
        ElementController::registeredElements.set("EText", new EText);
        ElementController::registeredElements.set("ESection", new ESection);
        ElementController::registeredElements.set("ETree", new ETree);
        ElementController::registeredElements.set("EButton", new EButton);
        ElementController::registeredElements.set("EMenu", new EMenu);
        ElementController::registeredElements.set("EMenuBar", new EMenuBar);
        ElementController::registeredElements.set("EMenuItem", new EMenuItem);
    }


    IElement *ElementController::addElementInternal(IElement *element, IElement *parent) {
        auto pElement = add(element, parent);
        if (pElement == nullptr) {
            return nullptr;
        }
        return pElement;
    }

    IElement *ElementController::addElement(const char *tag) {
        return addElementInternal(createElement(tag), nullptr);
    }

    IElement *ElementController::addElement(const char *tag, std::string id, IElement *parent) {
        IElement *pElement = addElementInternal(createElement(tag), parent);
        if (pElement != nullptr) {
            pElement->setId(id);
        }
        return pElement;
    }

    IElement *ElementController::addElement(IElement *element, IElement *parent) {
        return addElementInternal(element, parent);
    }

    IElement *ElementController::addElement(const char *tag, IElement *parent) {
        return addElementInternal(createElement(tag), parent);
    }
}