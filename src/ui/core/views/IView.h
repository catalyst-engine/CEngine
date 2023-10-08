#pragma once
#ifndef CATALYST_ENGINE_ICOMPONENT_H
#define CATALYST_ENGINE_ICOMPONENT_H

#include <string>
#include "pugixml.hpp"
#include "../../../util/structures/List.h"

namespace Catalyst::ui {
    class AbstractController;

    class IView {
    protected:
        AbstractController *controller = nullptr;
    public:
        /**
         * Updates component state
         */
        virtual void update() {}

        /**
         * Renders component with state
         */
        virtual void render() {}

        virtual void setId(std::string &newId) {}

        virtual std::string getId() {
            return "";
        }

        virtual Catalyst::util::List<IView> *getChildren() {
            return nullptr;
        }

        virtual void load(pugi::xml_node node) {}

        void setController(AbstractController *ctr);

        AbstractController *getController();

        virtual IView *copy() { return nullptr; }
    };
}
#endif

