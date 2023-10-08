#include "WorldRegistry.h"
#include "../components/CMetadata.h"

namespace Catalyst::engine {
    entt::registry *WorldRegistry::getRegistry() {
        return &worldReg;
    }

    CMetadata *WorldRegistry::getEntityMetadata(entt::entity ent) {
        return &worldReg.get<CMetadata>(ent);
    }
}