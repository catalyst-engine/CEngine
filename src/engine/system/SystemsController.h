#ifndef CATALYST_SYSTEMSCONTROLLER_H
#define CATALYST_SYSTEMSCONTROLLER_H

#include <vector>
#include "ISystem.h"
#include "structures/List.h"

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
            registerSystem((ISystem *) new T);
        }

        void update();
    };

}

#endif
