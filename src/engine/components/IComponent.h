#pragma once
#ifndef CATALYST_ICOMPONENT_H
#define CATALYST_ICOMPONENT_H

#include "entt/entt.hpp"

namespace Catalyst::engine {
    class IComponent {
    protected:
        entt::entity entity = entt::null;
    public:
        explicit IComponent(entt::entity ent) {
            this->entity = ent;
        }

        entt::entity getEntity() {
            return entity;
        }
    };
}
#endif
