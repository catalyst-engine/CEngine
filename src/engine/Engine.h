#ifndef CATALYST_ENGINE_H
#define CATALYST_ENGINE_H

#include "entt/entity/registry.hpp"
#include "world/WorldController.h"
#include "resource/ResourcesController.h"
#include "system/SystemsController.h"

namespace CEngine {

    class Engine {
    private:
        WorldController world;
        ResourcesController resources;
        SystemsController systems;
    public:
        const WorldController &getWorldController() const;

        const ResourcesController &getResources() const;

        void update();
    };
}

#endif
