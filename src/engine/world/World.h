#pragma once
#ifndef CATALYST_WORLD_H
#define CATALYST_WORLD_H

#include "entt/entt.hpp"
#include "WorldRegistry.h"

namespace Catalyst::engine {
    /**
     * For manipulating data
     * */
    class World : public ILoggable {
    private:
        WorldRegistry worldReg;
        size_t entitiesActive = 0;
    public:

        WorldRegistry *getRegistry() {
            return &worldReg;
        }

        entt::entity addEntity();

        void removeEntity(entt::entity ent);

        /**
         * @tparam T extends IComponent
         * @param ent
         * @return component instance
         */
        template<class T>
        void addComponent(entt::entity ent) {
            CONSOLE_LOG("Adding component to entity")
            worldReg.getRegistry()->emplace<T>(ent, ent);
        }

        template<class T>
        void removeComponent(entt::entity ent) {
            CONSOLE_LOG("Removing component from entity")
            worldReg.getRegistry()->erase<T>(ent);
        }
    };
}

#endif
