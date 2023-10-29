#include "Engine.h"
#include "world/WorldRegistry.h"
#include "world/World.h"

namespace Catalyst {
    engine::World Engine::world;

    entt::registry * Engine::getRegistry() {
        return world.getRegistry()->getRegistry();
    }

    engine::World *Engine::getWorld() {
        return &world;
    }

    engine::WorldRegistry *Engine::getWorldRegistry() {
        return world.getRegistry();
    }
}