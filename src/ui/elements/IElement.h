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
    private:
        bool initialized = false;
        IElement *parent = nullptr;
        Catalyst::List<IElement> children;
    protected:
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

        Catalyst::List<IElement> *getChildren();

        void renderChildren();

        void initialize(Document *document, IElement *parent, const char * pId);

        IElement *getChildElementById(std::string id);

        Document *getDocument();

        std::string getId();

        IElement *getParent();
    };
}
#endif

