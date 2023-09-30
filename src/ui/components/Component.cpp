
#include "Component.h"
namespace Catalyst::ui {
    void Component::render() {

    }

    void Component::update() {

    }

    void Component::setId(std::string &newId) {
        id = newId;
    }

    std::string Component::getId() {
        return id;
    }

    Catalyst::util::structs::List<AbstractComponent> *Component::getChildren() {
        return children.getList();
    }


    void Component::renderChildren() {
        Catalyst::util::structs::List<AbstractComponent> *list = children.getList();
        list->iterate();
        while (list->hasNext()) {
            AbstractComponent *next = list->next();
            next->render();
        }
    }

    void Component::addChild(AbstractComponent *child) {
        children.set(child->getId(), child);
    }
}