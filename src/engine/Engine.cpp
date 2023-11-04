#include "Engine.h"
#include "world/WorldController.h"

namespace Catalyst {
    engine::WorldController Engine::world;

    entt::registry * Engine::getRegistry() {
        return world.getRegistry();
    }

    engine::WorldController *Engine::getWorld() {
        return &world;
    }
}