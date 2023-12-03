#ifndef CATALYST_ISYSTEM_H
#define CATALYST_ISYSTEM_H

#include "../../util/debug/ILoggable.h"

namespace CEngine {
    class ResourcesController;

    class WorldController;

    class IIOController;

    class IFSController;

    class ISystem : public ILoggable {
    private:
        bool initialized = false;
    protected:
        ResourcesController *resources = nullptr;
        WorldController *world = nullptr;
        IIOController *io = nullptr;
        IFSController *fs = nullptr;
    public:
        virtual void run();

        virtual bool isEnabled();

        void initialize(ResourcesController *r, WorldController *w, IIOController *ioController, IFSController *fsController);
    };

}

#endif
