#pragma once
#ifndef CATALYST_ENGINE_ICOMPONENT_H
#define CATALYST_ENGINE_ICOMPONENT_H

#include <string>
#include "pugixml.hpp"
#include "imgui.h"
#include "../../../util/structures/List.h"
#include "../../../engine/event/IListener.h"

namespace CEngine {
    class Document;

    class Engine;

    class IElement : public IListener {
    private:
        bool initialized = false;
        IElement *parent = nullptr;
        CEngine::List<IElement> children;
        Engine *engine;
    protected:
        std::string id;
    public:
        void setId(const std::string &id);

    protected:
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

        CEngine::List<IElement> *getChildren();

        void renderChildren();

        void initialize(Document *document, Engine *engine, IElement *parent, const char *pId);

        IElement *getChildElementById(std::string id);

        Document *getDocument();

        Engine *getEngine();

        std::string getId();

        IElement *getParent();
    };
}
#endif

