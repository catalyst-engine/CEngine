#pragma once
#ifndef CATALYST_ENGINE_ICOMPONENT_H
#define CATALYST_ENGINE_ICOMPONENT_H

#include <string>
#include "pugixml.hpp"
#include "../../util/structures/List.h"

namespace Catalyst::ui {
    class IView {
    private:
        Catalyst::util::List<IView> children;
        std::string id;
    public:
        virtual void render();

        virtual void setId(std::string &newId);

        virtual std::string getId();

        virtual Catalyst::util::List<IView> *getChildren();

        virtual void collectAttributes(pugi::xml_node node) {}

        virtual IView *copy() { return nullptr; }

        void renderChildren();
    };
}
#endif

