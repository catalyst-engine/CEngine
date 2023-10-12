#pragma once

#ifndef CATALYST_VIEWFACTORY_H
#define CATALYST_VIEWFACTORY_H

#include <string>
namespace Catalyst::util {
    template<typename K, typename V>
    class Map;
}

namespace Catalyst::ui {
    class IElement;

    class EText;

    class ESection;

    class ViewFactory {
    private:
        static Catalyst::util::Map<std::string, IElement*> registered;
        static void registerViewInternal(const char *name, IElement* view);
    public:
        template<class T>
        static void registerView(const char *name) {
            registerViewInternal(name, new T);
        }

        static void init();

        static IElement *getViewByTag(const char *tag);
    };
}
#endif
