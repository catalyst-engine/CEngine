#include "IResource.h"

namespace CEngine {
    IResource::IResource(ResourceType type) {
        IResource::type = type;
    }

    ResourceType IResource::getType() const {
        return type;
    }

    void IResource::setResourceSystem(ResourcesSystem *system) {
        if (this->resourcesSystem != nullptr) {
            return;
        }
        this->resourcesSystem = system;
    }

    IResource::~IResource() = default;
}
