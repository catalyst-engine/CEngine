
#ifndef CATALYST_ENGINE_DOCUMENT_H
#define CATALYST_ENGINE_DOCUMENT_H

#include "components/IComponent.h"
#include "../util/DynamicMap.h"

namespace UI {

    class Document {
    private:
        DynamicMap<std::string, IComponent> elements;
        Util::Basic::DoubleLinkedList<IComponent> roots;
    public:
        void init();

        template<typename T>
        T *addElement(std::string id, IComponent *parent);

        IComponent *getElementById(std::string &id);

        void render();

        DynamicMap<std::string, IComponent> getElements();
    };

} // UI

#endif //CATALYST_ENGINE_DOCUMENT_H
