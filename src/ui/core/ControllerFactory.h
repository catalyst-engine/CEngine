#pragma once
#ifndef CATALYST_CONTROLLERFACTORY_H
#define CATALYST_CONTROLLERFACTORY_H

#include <string>

namespace Catalyst::util {
    template<typename K, typename V>
    class Map;
}

namespace Catalyst::ui {

    class AbstractController;

    class ControllerFactory {
    private:
        static Catalyst::util::Map<std::string, AbstractController *> registered;
        static void registerControllerInternal(const char *name, AbstractController* controller);
    public:
        template<class T>
        static void registerController(const char *name) {
            registerControllerInternal(name, new T);
        }

        static void init();

        static AbstractController *getControllerByAttr(const char *controller);
    };
}
#endif
