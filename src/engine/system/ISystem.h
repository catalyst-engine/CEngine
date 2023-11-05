#ifndef CATALYST_ISYSTEM_H
#define CATALYST_ISYSTEM_H

namespace CEngine {
    class ResourcesController;

    class WorldController;

    class ISystem {
    protected:
        ResourcesController &resources;
        WorldController &world;
    public:
        void setResources(const ResourcesController &controller);

        void setWorld(const WorldController &controller);

        virtual void update();

        virtual bool isEnabled();
    };

}

#endif
