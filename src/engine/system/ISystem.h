#ifndef CATALYST_ISYSTEM_H
#define CATALYST_ISYSTEM_H

#include "../util/debug/ILoggable.h"

namespace CEngine {
    class ResourcesController;

    class WorldController;

    class ISystem : public ILoggable {
    protected:
        ResourcesController *resources = nullptr;
        WorldController *world = nullptr;
    public:
        virtual void run();

        virtual bool isEnabled();

        void setWorld(WorldController *controller);

        void setResources(ResourcesController *controller);
    };

}

#endif
