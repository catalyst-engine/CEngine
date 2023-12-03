#include "WorldController.h"
#include "IEntity.h"
#include "../../util/structures/Map.cpp"

namespace CEngine {
    void WorldController::removeEntity(const std::string &uuid) {
        if (!entities.has(uuid))
            return;
        CONSOLE_LOG("Removing entity")
        IEntity *entity = entities.get(uuid);
        worldReg.destroy(entity->getEntity());
        entities.deleteKey(uuid);
        delete entity;
    }

    IEntity *WorldController::addEntity() {
        CONSOLE_LOG("Creating entity")
        return addEntityInternal(UUID::v4(), nullptr);
    }

    IEntity *WorldController::addEntity(std::string name) {
        CONSOLE_LOG("Creating entity {0}", name)
        return addEntityInternal(UUID::v4(), name.c_str());
    }

    entt::entity WorldController::getEntityFromWrapper(IEntity *entity) {
        return entity->getEntity();
    }

    IEntity *WorldController::addEntityInternal(const std::string& uuid, const char *name) {
        auto *pEntity = new IEntity(worldReg.create(), uuid);
        entities.set(uuid, pEntity);
        if(name != nullptr) {
            pEntity->setName(name);
        }
        return pEntity;
    }

    bool WorldController::hasEntity(const std::string &uuid) {
        return entities.has(uuid);
    }

    entt::registry &WorldController::getRegistry() {
        return worldReg;
    }

}