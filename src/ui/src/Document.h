
#ifndef CATALYST_ENGINE_DOCUMENT_H
#define CATALYST_ENGINE_DOCUMENT_H

#include "components/AbstractComponent.h"
#include "../../util/structures/DynamicMap.h"

namespace Catalyst::ui {
    class Document {
    private:
        Catalyst::util::List<AbstractComponent> roots;

        static AbstractComponent *searchFor(Catalyst::util::ListItem<AbstractComponent> *item, const std::string &id);

        size_t elementsSize = 0;
    public:

        void init();

        AbstractComponent *getElementById(std::string id);

        void render();

        size_t quantityOfElements();

        Catalyst::util::List<AbstractComponent> getElements();

        template<class T>
        T *addElement(std::string id, AbstractComponent *parent) {
            AbstractComponent *found = getElementById(id);
            if (found != nullptr) {
                return (T *) found;
            }
            T *component = new T;
            component->setId(id);
            if (parent != nullptr) {
                Catalyst::util::List<AbstractComponent> *children = parent->getChildren();
                children->push(component);
            } else {
                roots.push(component);
            }
            elementsSize++;
            return component;
        }
    };

} // UI

#endif //CATALYST_ENGINE_DOCUMENT_H
