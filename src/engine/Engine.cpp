#include "Engine.h"
#include "world/WorldController.h"

namespace CEngine {
    const WorldController &Engine::getWorldController() const {
        return world;
    }

    const ResourcesController &Engine::getResources() const {
        return resources;
    }

    void Engine::update() {
        systems.update();
    }
}