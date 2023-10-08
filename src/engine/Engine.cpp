#include "Engine.h"
#include "world/WorldRegistry.h"
#include "world/World.h"

namespace Catalyst {
    engine::World Engine::world;

    engine::WorldRegistry *Engine::getRegistry() {
        return world.getRegistry();
    }

    engine::World *Engine::getWorld() {
        return &world;
    }
}