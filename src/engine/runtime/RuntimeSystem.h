#ifndef CATALYST_RUNTIMESYSTEM_H
#define CATALYST_RUNTIMESYSTEM_H

#include <vector>
#include "systems/ISystem.h"
#include "../../core/structures/List.h"

namespace CEngine {
    class Engine;

    class RuntimeSystem {
    private:
        Engine *engine = nullptr;
        std::vector<ISystem *> systems;

        void registerSystem(ISystem *system);

    public:

        void setEngine(Engine *eg);

        template<class T>
        void createSystem() {
            auto *pSystem = (ISystem *) new T;
            registerSystem(pSystem);
        }

        void run();
    };

}

#endif
