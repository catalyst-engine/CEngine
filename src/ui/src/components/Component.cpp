
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

    Catalyst::util::List<AbstractComponent> *Component::getChildren() {
        return &children;
    }

    void Component::renderChildren() {
        children.iterate();
        while (children.hasNext()) {
            AbstractComponent *next = children.next();
            next->render();
        }
    }
}