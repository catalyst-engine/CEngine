
#include "UIComponent.h"

namespace Catalyst::ui {
    void UIComponent::render() {

    }

    void UIComponent::update() {

    }

    void UIComponent::setId(std::string &newId) {
        id = newId;
    }

    std::string UIComponent::getId() {
        return id;
    }

    Catalyst::util::structs::List<IComponent> *UIComponent::getChildren() {
        return children.getList();
    }


    void UIComponent::renderChildren() {
        Catalyst::util::structs::List<IComponent> *list = children.getList();
        list->iterate();
        while (list->hasNext()) {
            IComponent *next = list->next();
            next->render();
        }
    }

    void UIComponent::addChild(IComponent *child) {
        children.set(child->getId(), child);
    }
}