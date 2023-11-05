#include "IResource.h"

namespace CEngine {
    IResource::IResource(ResourceType type) {
        IResource::type = type;
    }

    ResourceType IResource::getType() const {
        return type;
    }


}
