#include "Engine.h"
#include "world/WorldController.h"
#include "system/systems/InputSystem.h"

namespace CEngine {
    const WorldController &Engine::getWorld() const {
        return world;
    }

    const ResourcesController &Engine::getResources() const {
        return resources;
    }

    void Engine::update() {
        systems.update();
    }

    Engine::Engine() {
        systems.setEngine(this);

        systems.createSystem<InputSystem>();
    }
}