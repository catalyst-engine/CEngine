#pragma once
#ifndef CATALYST_ENGINE_ICOMPONENT_H
#define CATALYST_ENGINE_ICOMPONENT_H

#include <string>
#include "pugixml.hpp"
#include "../../util/structures/List.h"

namespace Catalyst::ui {
    class IElement {
    private:
        Catalyst::util::List<IElement> children;
        std::string id;
    public:
        virtual void render();

        virtual void setId(std::string &newId);

        virtual std::string getId();

        virtual Catalyst::util::List<IElement> *getChildren();

        virtual void collectAttributes(pugi::xml_node node) {}

        virtual IElement *copy() { return nullptr; }

        void renderChildren();
    };
}
#endif

