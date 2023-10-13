#pragma once
#ifndef CATALYST_ENGINE_ICOMPONENT_H
#define CATALYST_ENGINE_ICOMPONENT_H

#include <string>
#include "pugixml.hpp"
#include "../../util/structures/List.h"

namespace Catalyst {
    class Document;

    class IElement {
    private:
        Catalyst::List<IElement> children;
        std::string id;
        Document *document = nullptr;
    public:
        virtual void render();

        virtual void setId(std::string &newId);

        virtual std::string getId();

        virtual Catalyst::List<IElement> *getChildren();

        virtual void collectAttributes(pugi::xml_node node) {}

        virtual IElement *copy() { return nullptr; }

        void renderChildren();

        Document *getDocument();

        void setDocument(Document *document);
    };
}
#endif

