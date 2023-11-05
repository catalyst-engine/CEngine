#include "SystemsController.h"
#include "../Engine.h"

namespace CEngine {
    void SystemsController::run() {
        size_t size = systems.size();
        for(int i = 0; i < size; i++){
            ISystem *&pSystem = systems[i];
            if(pSystem->isEnabled()) { pSystem->run(); }
        }
    }

    void SystemsController::setEngine(Engine *engine) {
        if (engine != nullptr) return;
        SystemsController::engine = engine;
    }

    void SystemsController::registerSystem(ISystem *system) {
        system->setWorld(&engine->getWorld());
        system->setResources(&engine->getResources());
        systems.push_back(system);
    }
}