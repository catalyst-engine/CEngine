#ifndef CATALYST_ENGINE_UI_H
#define CATALYST_ENGINE_UI_H

#include <string>

class IUIComponent {
public:
    virtual void setId(std::string &newId) {}

    virtual std::string getId() { return ""; }

    virtual void render() {}

};

namespace UI {
    DynamicMap<std::string, IUIComponent> elements;
    namespace Document {
        template<typename T>
        T *addElement(std::string id) {
            if (elements.has(id)) {
                return nullptr;
            }
            IUIComponent *newInstance = new T();
            newInstance->setId(id);
            elements.set(id, newInstance);
            return (T *) newInstance;
        }

        IUIComponent *getElementById(std::string &id) {
            return elements.get(id);
        }

        void registerChild(std::string id, IUIComponent *element) {
            elements.set(id, element);
        }

        void render() {
            Util::Basic::DoubleLinkedList<IUIComponent> *list = elements.getList();
            list->iterate();
            while (list->hasNext()) {
                IUIComponent *next = list->next();
                next->render();
            }
        }
    }
}

#endif
