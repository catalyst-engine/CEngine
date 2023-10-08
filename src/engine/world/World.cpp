#include "World.h"
#include "WorldRegistry.h"
#include "../components/CMetadata.h"

namespace Catalyst::engine {
    void World::removeEntity(entt::entity ent) {
        worldReg.getRegistry()->destroy(ent);
    }

    entt::entity World::addEntity() {
        entt::entity ent = worldReg.getRegistry()->create();
        addComponent<CMetadata>(ent);
        return ent;
    }

    /**
     * @tparam T extends IComponent
     * @param ent
     * @return component instance
     */
    template<class T>
    void World::addComponent(entt::entity ent) {
        worldReg.getRegistry()->emplace<T>(ent,  ent);
    }

    template<class T>
    void World::removeComponent(entt::entity ent) {
        worldReg.getRegistry()->erase<T>(ent);
    }

}