#include "Engine.h"
#include "world/WorldController.h"
#include "system/systems/InputSystem.h"

namespace CEngine {
    WorldController &Engine::getWorld() {
        return world;
    }

    ResourcesController &Engine::getResources() {
        return resources;
    }

    void Engine::run() {
        systems.run();
    }

    Engine::Engine() {
        systems.setEngine(this);
        systems.createSystem<InputSystem>();
    }
}