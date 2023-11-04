#pragma once
#ifndef CATALYST_ICOMPONENT_H
#define CATALYST_ICOMPONENT_H

#include "entt/entt.hpp"
#include "../IEntity.h"

namespace CEngine {
    class IComponent {
    protected:
        IEntity *entity = nullptr;
    public:
        explicit IComponent(IEntity *ent);

        IEntity *getEntity();
    };
}
#endif
