#include "World.h"
#include "WorldRegistry.h"
#include "../components/CMetadata.h"

namespace Catalyst::engine {
    void World::removeEntity(entt::entity ent) {
        CONSOLE_LOG("Removing entity")
        worldReg.getRegistry()->destroy(ent);
        entitiesActive--;
    }

    entt::entity World::addEntity() {
        CONSOLE_LOG("Creating entity")
        entitiesActive++;
        entt::entity ent = worldReg.getRegistry()->create();
        addComponent<CMetadata>(ent);
        auto &component = getRegistry()->getRegistry()->get<engine::CMetadata>(ent);
        component.setName(component.getName() + " ("+std::to_string(entitiesActive) + ")");
        return ent;
    }

}