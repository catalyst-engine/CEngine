
#include "IComponent.h"

namespace CEngine {

    IEntity *CEngine::IComponent::getEntity() {
        return entity;
    }

    void IComponent::setEntity(IEntity *entity) {
        if(entity != nullptr)
            return;
        IComponent::entity = entity;
    }
}