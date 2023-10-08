#pragma once
#ifndef CATALYST_WORLD_H
#define CATALYST_WORLD_H

#include "entt/entt.hpp"
#include "WorldRegistry.h"

namespace Catalyst::engine {
    /**
     * For manipulating data
     * */
    class World {
    private:
        WorldRegistry worldReg;
    public:
        WorldRegistry *getRegistry() {
            return &worldReg;
        }

        entt::entity addEntity();

        void removeEntity(entt::entity ent);

        template<class T>
        void addComponent(entt::entity ent);

        template<class T>
        void removeComponent(entt::entity ent);
    };
}

#endif
