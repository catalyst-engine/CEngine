#include "WorldController.h"
#include "components/CMetadata.h"

namespace Catalyst::engine {
    void WorldController::removeEntity(entt::entity ent) {
        CONSOLE_LOG("Removing entity")
        worldReg.destroy(ent);
        entitiesActive--;
    }

    entt::entity WorldController::addEntity() {
        CONSOLE_LOG("Creating entity")
        entitiesActive++;
        entt::entity ent = worldReg.create();
        addComponent<CMetadata>(ent);
        CMetadata *pMetadata = getComponent<CMetadata>(ent);
        component.setName(component.getName() + " (" + std::to_string(entitiesActive) + ")");
        return ent;
    }

    entt::registry &WorldController::getRegistry() {
        return worldReg;
    }

    CMetadata *WorldController::getEntityMetadata(entt::entity ent) {
        return nullptr;
    }
}