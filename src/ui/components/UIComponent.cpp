
#include "UIComponent.h"

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

Util::Basic::DoubleLinkedList<IComponent> *UIComponent::getChildren() {
    return children.getList();
}


void UIComponent::renderChildren() {
    Util::Basic::DoubleLinkedList<IComponent> *list = children.getList();
    list->iterate();
    while (list->hasNext()) {
        IComponent *next = list->next();
        next->render();
    }
}

void UIComponent::addChild(IComponent *child) {
    children.set(child->getId(), child);
}

