#ifndef CATALYST_ENGINE_H
#define CATALYST_ENGINE_H

namespace Catalyst {
    namespace engine {
        class World;

        class WorldRegistry;
    }

    class Engine {
    private:
        static engine::World world;
    public:
        static engine::World *getWorld();

        static engine::WorldRegistry *getRegistry();
    };
}

#endif
