#ifndef CATALYST_ENGINE_H
#define CATALYST_ENGINE_H

#include "entt/entity/registry.hpp"

namespace Catalyst {
    namespace engine {
        class World;

        class WorldRegistry;
    }

    class Engine {
    private:
        static engine::World world;
    public:
        static engine::World *getWorld();

        static entt::basic_registry<> * getRegistry();

        static engine::WorldRegistry *getWorldRegistry();
    };
}

#endif
