
#include "ISystem.h"
#include "../resource/ResourcesController.h"
#include "../world/WorldController.h"

namespace CEngine {

    void ISystem::run() {

    }

    bool ISystem::isEnabled() {
        return false;
    }

    void ISystem::setWorld(WorldController *controller) {
        world = controller;
    }

    void ISystem::setResources(ResourcesController *controller) {
        resources = controller;
    }
}