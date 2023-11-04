#include "IStaticResource.h"

namespace CEngine {
    IStaticResource::IStaticResource(StaticResource resourceID) {
        id = std::to_string(resourceID);
    }

    std::string IStaticResource::getId() {
        return id;
    }
}