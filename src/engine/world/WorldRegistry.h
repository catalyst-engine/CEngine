#ifndef CATALYST_WORLDREGISTRY_H
#define CATALYST_WORLDREGISTRY_H

#include "entt/entt.hpp"

namespace Catalyst::engine {
    class CMetadata;

    /**
     * For querying data and storing registry
     * */
    class WorldRegistry {
    private:
        entt::registry worldReg;
    public:
        entt::registry *getRegistry();

        template<class T>
        T *getComponent(entt::entity ent);

        template<class T>
        bool hasComponent(entt::entity ent);

        CMetadata *getEntityMetadata(entt::entity ent);
    };

}

#endif
