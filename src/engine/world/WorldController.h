#pragma once
#ifndef CATALYST_WORLDCONTROLLER_H
#define CATALYST_WORLDCONTROLLER_H

#include "entt/entt.hpp"
#include "debug/ILoggable.h"
#include "structures/Map.h"

namespace CEngine {
    /**
     * For manipulating data
     * */

    class IEntity;

    class WorldController : public ILoggable {
    private:
        entt::registry worldReg;
        Map<std::string, IEntity *> entities;

        IEntity *addEntityInternal(std::string uuid, const char *name);

        entt::entity getEntityFromWrapper(IEntity *entity);

    public:

        IEntity *addEntity();

        void removeEntity(const std::string &uuid);

        template<class T>
        void addComponent(IEntity *ent) {
            CONSOLE_LOG("Adding component to entity")
            entt::entity entity = getEntityFromWrapper(ent);
            worldReg.emplace<T>(entity, entity);
        }

        template<class T>
        void removeComponent(IEntity *ent) {
            CONSOLE_LOG("Removing component from entity")
            entt::entity entity = getEntityFromWrapper(ent);
            worldReg.erase<T>(entity);
        }

        template<class T>
        T *getComponent(IEntity *ent) {
            entt::entity entity = getEntityFromWrapper(ent);
            return worldReg.get<T>(entity);
        }

        template<class T>
        bool hasComponent(IEntity *ent) {
            entt::entity entity = getEntityFromWrapper(ent);
            return worldReg.all_of<T>(entity);
        }
    };
}

#endif
