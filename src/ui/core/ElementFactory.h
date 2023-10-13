#pragma once

#ifndef CATALYST_ELEMENTFACTORY_H
#define CATALYST_ELEMENTFACTORY_H

#include <string>
#include "pugixml.hpp"
#include "../../util/debug/ILoggable.h"

namespace Catalyst {
    template<typename K, typename V>
    class Map;
}

namespace Catalyst {
    class IElement;

    class EText;

    class ESection;

    class ElementFactory : public ILoggable {
    private:
        static bool isReady;

        static Catalyst::Map<std::string, IElement *> registered;

        void load(pugi::xml_node root, IElement *parent);

        void prepare(pugi::xml_node node, IElement *parent);

        static void init();

    public:

        void create(const char *src);

        static IElement *createElement(const char *tag);

        virtual IElement *addElement(const char *tag, std::string id, IElement *parent);

        virtual IElement *addElement(const char *tag, IElement *parent);
    };
}
#endif
