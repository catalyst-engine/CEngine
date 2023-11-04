#pragma once
#ifndef CATALYST_WORLDCONTROLLER_H
#define CATALYST_WORLDCONTROLLER_H

#include "entt/entt.hpp"

namespace Catalyst::engine {
    /**
     * For manipulating data
     * */
    class WorldController : public ILoggable {
    private:
        entt::registry worldReg;
        size_t entitiesActive = 0;
    public:

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
            worldReg.emplace<T>(ent, ent);
        }

        template<class T>
        void removeComponent(entt::entity ent) {
            CONSOLE_LOG("Removing component from entity")
            worldReg.erase<T>(ent);
        }

        template<class T>
        T *getComponent(entt::entity ent) {
            return worldReg.get<T>(ent);
        }

        template<class T>
        bool hasComponent(entt::entity ent) {
            return worldReg.all_of<T>(ent);
        }

        CMetadata *getEntityMetadata(entt::entity ent);

        entt::registry &getRegistry();
    };
}

#endif
