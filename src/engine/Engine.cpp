#include "Engine.h"
#include "world/WorldController.h"
#include "system/systems/InputSystem.h"
#include "external/IIOController.h"
#include "external/IFSController.h"

namespace CEngine {
    Engine::Engine(IIOController *ioController, IFSController *fsController) {
        io = ioController;
        fs = fsController;
        systems.setEngine(this);
        systems.createSystem<InputSystem>();
    }

    WorldController &Engine::getWorld() {
        return world;
    }

    ResourcesController &Engine::getResources() {
        return resources;
    }

    void Engine::run() {
        systems.run();
    }

    IIOController *Engine::getIo() {
        return io;
    }

    IFSController *Engine::getFs() {
        return fs;
    }
}