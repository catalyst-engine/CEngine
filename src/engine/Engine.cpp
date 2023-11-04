#include "Engine.h"
#include "world/WorldController.h"

namespace CEngine {
    WorldController &Engine::getWorldController() {
        return world;
    }
}