#ifndef CATALYST_IENTITY_H
#define CATALYST_IENTITY_H

#include <string>
#include "entt/entity/entity.hpp"
#include "../util/UUID.h"

namespace CEngine {
    class IEntity {
    private:
        const char *name = nullptr;
        std::string uuid;
        entt::entity entity;
    public:
        explicit IEntity(entt::entity entity, std::string uuid);

        const char *getName() const;

        void setName(const char *name);

        const std::string &getUUID() const;

        entt::entity getEntity();
    };
}

#endif
