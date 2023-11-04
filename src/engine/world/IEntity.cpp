#include "IEntity.h"

#include <utility>

namespace CEngine {
    const char *IEntity::getName() const {
        return name;
    }

    void IEntity::setName(const char *name) {
        IEntity::name = name;
    }

    const std::string &IEntity::getUUID() const {
        return uuid;
    }

    entt::entity IEntity::getEntity() {
        return entity;
    }

    IEntity::IEntity(entt::entity entity, std::string uuid) {
        this->uuid = std::move(uuid);
        this->entity = entity;
    }
}