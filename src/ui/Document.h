
#ifndef CATALYST_ENGINE_DOCUMENT_H
#define CATALYST_ENGINE_DOCUMENT_H

#include "components/IComponent.h"
#include "../util/structures/DynamicMap.h"

namespace Catalyst::ui {
    class Document {
    private:
        util::structs::DynamicMap<std::string, IComponent> elements;
        Catalyst::util::structs::List<IComponent> roots;
    public:
        void init();

        template<typename T>
        T *addElement(std::string id, IComponent *parent);

        IComponent *getElementById(std::string &id);

        void render();

        util::structs::DynamicMap<std::string, IComponent> getElements();
    };

} // UI

#endif //CATALYST_ENGINE_DOCUMENT_H
