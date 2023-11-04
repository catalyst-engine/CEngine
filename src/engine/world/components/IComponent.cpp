
#include "IComponent.h"

namespace CEngine {

    IEntity *CEngine::IComponent::getEntity() {
        return entity;
    }

    IComponent::IComponent(IEntity *ent) {
        this->entity = ent;
    }
}