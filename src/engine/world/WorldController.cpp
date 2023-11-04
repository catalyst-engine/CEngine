#include "WorldController.h"
#include "IEntity.h"
#include "../util/structures/Map.cpp"

namespace CEngine {
    void WorldController::removeEntity(const std::string &uuid) {
        if (!entities.has(uuid))
            return;
        CONSOLE_LOG("Removing entity")
        IEntity *entity = entities.get(uuid);
        worldReg.destroy(entity->getEntity());
        delete entity;
    }

    IEntity *WorldController::addEntity() {
        CONSOLE_LOG("Creating entity")
        return addEntityInternal(UUID::v4(), nullptr);
    }

    entt::entity WorldController::getEntityFromWrapper(IEntity *entity) {
        return entity->getEntity();
    }

    IEntity *WorldController::addEntityInternal(std::string uuid, const char *name) {
        auto *pEntity = new IEntity(worldReg.create(), uuid);
        entities.set(uuid, pEntity);
        pEntity->setName(name);
        return pEntity;
    }

}