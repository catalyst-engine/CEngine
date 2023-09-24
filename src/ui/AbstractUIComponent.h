#ifndef CATALYST_ENGINE_ABSTRACT_UI_H
#define CATALYST_ENGINE_ABSTRACT_UI_H
#pragma once

#include "../util/DoubleLinkedList.h"
#include "../util/DynamicMap.h"
#include "UI.h"

class AbstractUIComponent : public IUIComponent {
private:
    DynamicMap<std::string, AbstractUIComponent> children;
    std::string id;
protected:
    void renderChildren() {
        Util::Basic::DoubleLinkedList<AbstractUIComponent> *list = children.getList();
        list->iterate();
        while (list->hasNext()) {
            AbstractUIComponent *next = list->next();
            next->render();
        }
    }

public:
    void setId(std::string &newId) override {
        id = newId;
    }

    std::string getId() override {
        return id;
    }

    Util::Basic::DoubleLinkedList<AbstractUIComponent> *getChildren() {
        return children.getList();
    }

    template<typename T>
    T *addChild(std::string newId) {
        if (children.has(newId)) {
            return nullptr;
        }
        AbstractUIComponent *newInstance = new T();
        newInstance->setId(newId);
        children.set(newId, newInstance);

        UI::Document::registerChild(newId, newInstance);
        return (T *) newInstance;
    }

    void removeChild(AbstractUIComponent *child) {
        children.deleteKey(child->getId());
    }
};

#endif