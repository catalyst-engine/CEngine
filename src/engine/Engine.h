#ifndef CATALYST_ENGINE_H
#define CATALYST_ENGINE_H

#include "entt/entity/registry.hpp"

namespace Catalyst {
    namespace engine {
        class WorldController;

        class WorldRegistry;
    }

    class Engine {
    private:
        static engine::WorldController world;
    public:
        static engine::WorldController *getWorld();

        static entt::basic_registry<> * getRegistry();

        static engine::WorldRegistry *getWorldRegistry();
    };
}

#endif
