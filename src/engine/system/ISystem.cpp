
#include "ISystem.h"
#include "../resource/ResourcesController.h"
#include "../world/WorldController.h"

namespace CEngine {
    void ISystem::setResources(const ResourcesController &controller) {
        resources = controller;
    }

    void ISystem::setWorld(const WorldController &controller) {
        world = controller;
    }

    void ISystem::update() {

    }

    bool ISystem::isEnabled() {
        return false;
    }
}