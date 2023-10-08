#include "World.h"
#include "WorldRegistry.h"
#include "../components/CMetadata.h"

namespace Catalyst::engine {
    void World::removeEntity(entt::entity ent) {
        CONSOLE_LOG("Removing entity")
        worldReg.getRegistry()->destroy(ent);
    }

    entt::entity World::addEntity() {
        CONSOLE_LOG("Creating entity")
        entt::entity ent = worldReg.getRegistry()->create();
        addComponent<CMetadata>(ent);
        return ent;
    }

}