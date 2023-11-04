#ifndef CATALYST_ENGINE_H
#define CATALYST_ENGINE_H

#include "entt/entity/registry.hpp"
#include "world/WorldController.h"

namespace CEngine {

    class Engine {
    private:
        WorldController world;
    public:
        WorldController &getWorldController();
    };
}

#endif
