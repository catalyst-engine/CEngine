
#include "ISystem.h"
#include "../resource/ResourcesController.h"
#include "../world/WorldController.h"

namespace CEngine {

    void ISystem::run() {

    }

    bool ISystem::isEnabled() {
        return false;
    }

    void ISystem::initialize(ResourcesController *r, WorldController *w, IIOController *ioController,
                             IFSController *fsController) {
        if (initialized) {
            return;
        }
        initialized = true;
        fs = fsController;
        io = ioController;
        world = w;
        resources = r;
    }
}