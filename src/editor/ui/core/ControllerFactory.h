#pragma once
#ifndef CATALYST_CONTROLLERFACTORY_H
#define CATALYST_CONTROLLERFACTORY_H

#include <string>

namespace Catalyst::ui {
    class TextController;
    class AbstractController;
    class ControllerFactory{
    public:
        static AbstractController *getControllerByAttr(const char *controller);
    };
}
#endif
