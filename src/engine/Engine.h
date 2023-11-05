#ifndef CATALYST_ENGINE_H
#define CATALYST_ENGINE_H

#include "entt/entity/registry.hpp"
#include "world/WorldController.h"
#include "resource/ResourcesController.h"
#include "system/SystemsController.h"

namespace CEngine {
    class IIOController;

    class IFSController;

    class Engine {
    private:
        WorldController world;
        ResourcesController resources;
        SystemsController systems;
        IIOController *io = nullptr;
        IFSController *fs = nullptr;
    public:

        explicit Engine(IIOController *ioController, IFSController *fsController);

        WorldController &getWorld();

        ResourcesController &getResources();

        IIOController *getIo();

        IFSController *getFs();

        void run();
    };
}

#endif
