#include "WorldRegistry.h"
#include "../components/CMetadata.h"

namespace Catalyst::engine {
    entt::registry *WorldRegistry::getRegistry() {
        return &worldReg;
    }

    CMetadata *WorldRegistry::getEntityMetadata(entt::entity ent) {
        return &worldReg.get<CMetadata>(ent);
    }

    template<class T>
    T *WorldRegistry::getComponent(entt::entity ent) {
        return worldReg.get<T>(ent);
    }

    template<class T>
    bool WorldRegistry::hasComponent(entt::entity ent) {
        return worldReg.all_of<T>(ent);
    }
}