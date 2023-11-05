#ifndef CATALYST_SYSTEMSCONTROLLER_H
#define CATALYST_SYSTEMSCONTROLLER_H

#include <vector>
#include "ISystem.h"
#include "../util/structures/List.h"

namespace CEngine {
    class Engine;

    class SystemsController {
    private:
        Engine *engine = nullptr;
        std::vector<ISystem *> systems;

        void registerSystem(ISystem *system);

    public:

        void setEngine(Engine *engine);

        template<class T>
        void createSystem() {
            auto *pSystem = (ISystem *) new T;
            registerSystem(pSystem);
        }

        void update();
    };

}

#endif
