
#ifndef CATALYST_ENGINE_DOCUMENT_H
#define CATALYST_ENGINE_DOCUMENT_H

#include "components/AbstractComponent.h"
#include "../util/structures/DynamicMap.h"

namespace Catalyst::ui {
    class Document {
    private:
        util::structs::DynamicMap<std::string, AbstractComponent> elements;
        Catalyst::util::structs::List<AbstractComponent> roots;
    public:
        void init();

        AbstractComponent *getElementById(std::string &id);

        void render();

        util::structs::DynamicMap<std::string, AbstractComponent> getElements();

        template<class T>
        T* addElement(std::string id, AbstractComponent *parent) {
            if (elements.has(id)) {
                return nullptr;
            }
            T* component = new T;
            component->setId(id);
            elements.set(id, component);
            if (parent != nullptr) {
                parent->addChild(component);
            } else {
                roots.push(component);
            }
            return component;
        }

    };

} // UI

#endif //CATALYST_ENGINE_DOCUMENT_H
