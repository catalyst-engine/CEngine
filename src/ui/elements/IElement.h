#pragma once
#ifndef CATALYST_ENGINE_ICOMPONENT_H
#define CATALYST_ENGINE_ICOMPONENT_H

#include <string>
#include "pugixml.hpp"
#include "../../util/structures/List.h"
#include "../event/IListener.h"
#include "imgui.h"

namespace Catalyst {
    class Document;

    class IElement : public IListener {
    protected:
        Catalyst::List<IElement> children;
        std::string id;
        Document *document = nullptr;
        bool active = true;

        IElement *getElementById(std::string id);

    public:
        ~IElement();

        virtual void loadFlags();

        virtual void onInitialize();

        bool isActive() const;

        void setActive(bool active);

        virtual void render();

        virtual void collectAttributes(pugi::xml_node node);

        virtual IElement *copy();

        void setId(std::string &newId);

        std::string getId();

        Catalyst::List<IElement> *getChildren();

        void renderChildren();

        Document *getDocument();

        void setDocument(Document *document);

        IElement *getChildElementById(std::string id);
    };
}
#endif

